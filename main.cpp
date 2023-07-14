#include <iostream>
#include "gsql_gsm/gsm_db_indices.h"
#include <gsql_gsm/gsql_operators.h>
#include <gsql_gsm/igc_operators.h>

#include <string>
#include <gsql_gsm/dump_to_xml.h>

#include <vector>
#include <fstream>
#include "submodules/yaucl/submodules/rapidcsv/src/rapidcsv.h"
#include <nlohmann/json.hpp>
#include <filesystem>
#include <curl/curl.h>

#include <chrono>
#include "sys/types.h"
#include "sys/sysinfo.h"

using json = nlohmann::json;


void PutInDb(gsm_inmemory_db_view &db,
             std::vector<gsm_object_xi_content>&tablePhi,
             std::vector<double> &scores,
             std::string ell,
             std::string xi,
             double score = 1.0)
{
    createFast(db, ++db.db->max_id, {ell}, {xi});
    tablePhi.emplace_back(db.db->max_id, score);
    scores.emplace_back(score);
}

static inline
void JsonRecursion(json data,
                   std::vector<gsm_object_xi_content> &tablePhi,
                   std::vector<double> &scores,
                   gsm_inmemory_db_view &db,
                   std::string previousKey = "")
{
    for(auto &it : data.items())
    {
        if(it.value().is_object() || it.value().is_array())
        {
            std::vector<gsm_object_xi_content> tablePhiObject = {};
            std::vector<double> scoresObject = {};
            JsonRecursion(it.value(), tablePhiObject, scoresObject, db, it.key());
            std::string phiString = (data.is_array() ? previousKey + it.key() : it.key());
            createFast(db, ++db.db->max_id, {"json_object"}, {}, {scoresObject}, {{phiString, {tablePhiObject}}});
        }
        else
        {
            std::string ell = (data.is_array() ? previousKey : it.key());
            createFast(db, ++db.db->max_id, {ell}, {to_string(it.value())});
        }
        tablePhi.emplace_back(db.db->max_id);
        scores.emplace_back(1.0);
    }
}


static inline
void LoadCsvFile(gsm_inmemory_db_view &db,
                 const std::string& csvFileDir,
                 bool graph = false)
{

    char separator = (graph ? ';' : ','); // ; or ,

    rapidcsv::Document doc(csvFileDir, rapidcsv::LabelParams(0, -1), rapidcsv::SeparatorParams(separator));

    std::vector<std::string> colHeaders = doc.GetColumnNames();
    std::vector<gsm_object_xi_content> tablePhiCsv = {}; // phi table for csv file
    std::vector<double> scoresCsv = {}; // score table for csv file
    std::vector<gsm_object_xi_content> tablePhi = {}; // phi table for rows
    std::vector<double> scores = {}; // score table for rows

    for(int i = 0; i < doc.GetRowCount(); i++)
    {
        std::vector<std::string> row = doc.GetRow<std::string>(i);
        tablePhi = {};
        scores = {};

        for(int j = 0; j < row.size(); j++)
        {
            if(graph && (row.at(j).at(0) == '{' || row.at(j).at(0) == '['))
            {
                json data = json::parse(row.at(j));
                JsonRecursion(data, tablePhi, scores, db, colHeaders.at(j));
            }
            else
            {
                std::string x = colHeaders.at(j);
                PutInDb(db, tablePhi, scores, colHeaders.at(j), row.at(j), 1.0);
            }
        }

        createFast(db, ++db.db->max_id, {"row"}, {row.at(0)}, {scores}, {{"data", {tablePhi}}});
        tablePhiCsv.emplace_back(db.db->max_id, 1.0);
        scoresCsv.emplace_back(1.0);
    }
    createFast(db, ++db.db->max_id, {"csv_file"}, {csvFileDir}, {scoresCsv}, {{"row", {tablePhiCsv}}});
}

static inline
void LoadCsvDb(gsm_inmemory_db_view &db, const std::string& pathToDb)
{
    std::vector<gsm_object_xi_content> tablePhiDb = {}; // Phi table for csv db
    std::vector<double> scoresCsvDb = {}; // Scores table for csv db
    for(const auto & entry : std::filesystem::directory_iterator(pathToDb))
    {
        std::cout << entry.path() << std::endl;
        LoadCsvFile(db, entry.path(), db.db->max_id);
        tablePhiDb.emplace_back(db.db->max_id, 1.0);
        scoresCsvDb.emplace_back(1.0);
    }
    createFast(db, ++db.db->max_id, {"csv_db"}, {pathToDb}, {scoresCsvDb}, {{"csv_file", {tablePhiDb}}});
}


void LoadJson(gsm_inmemory_db_view &db,
              const std::string& pathToFile,
              std::string xi = "")
{
    json data;
    if(xi.empty()) {
        std::ifstream f(pathToFile);
        xi = pathToFile;
        data = json::parse(f);
    } else {
        data = json::parse(pathToFile);
    }

    std::vector<gsm_object_xi_content> tablePhiJson = {};
    std::vector<double> scoresJson = {};
    JsonRecursion(data, tablePhiJson, scoresJson, db);
    createFast(db, ++db.db->max_id, {"json_file"}, {xi}, {scoresJson}, {{"json_file", {tablePhiJson}}});
}

std::string downloadedResponse;

std::size_t writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
{
    if(buffer_in != NULL)
    {
        downloadedResponse.append(data);
        return size*nmemb;
    }
    return 0;
}

std::string DownloadWeather(std::string URL)
{
    downloadedResponse = "";
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    std::ostringstream oss;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charset: utf-8");
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        res = curl_easy_perform(curl);

        if(CURLE_OK == res)
        {
            char *ct;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            if((CURLE_OK == res) && ct)
                return downloadedResponse;
        }
    }
    curl_slist_free_all(headers);
}


void LoadWeather(gsm_inmemory_db_view &db, double lat, double lon, std::time_t start)
{
    std::ifstream file("/home/neo/gsm_gsql/api_keys/openweather.txt");
    std::string openWeatherApiKey;
    file >> openWeatherApiKey;

    std::ifstream fileAnother("/home/neo/gsm_gsql/api_keys/visualcrossing.txt");
    std::string visualCrossingApiKey;
    fileAnother >> visualCrossingApiKey;

    std::stringstream vc;
    vc << "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/"
    << lat << ',' << lon
    << '/' << start
    << "?key=" << visualCrossingApiKey;

    std::stringstream ow;
    ow << "https://history.openweathermap.org/data/2.5/history/city?"
    << "lat=" << lat
    << "&lon=" << lon
    << "&type=hour&start=" << start
    << "&cnt=" << 1
    << "&appid=" << openWeatherApiKey;

    std::string url = ow.str();
    std::cout << "URL:" << url << std::endl;
    std::string weatherString = DownloadWeather(url);
    std::cout << weatherString << std::endl;
    LoadJson(db, weatherString, "weather_ow");

    url = vc.str();
    std::cout << "URL:" << url << std::endl;
    weatherString = DownloadWeather(url);
    std::cout << weatherString << std::endl;
    LoadJson(db, weatherString, "weather_vc");
}

void LoadIgcFile(gsm_inmemory_db_view &db,
                 std::string pathToFile,
                 bool weather)
{
    std::ifstream stream(pathToFile);
    std::string line;

    std::vector<gsm_object_xi_content> tablePhiIgc = {};
    std::vector<double> scoresIgc = {};
    std::string date;
    //get pilot and date
    for(std::string line; std::getline(stream, line);)
    {
        if(line.substr(0,5) == "HFDTE")
        {
            date = line.substr(5, 4) + "20" + line.substr(9,2);
            PutInDb(db, tablePhiIgc, scoresIgc, "date", {line.substr(5, 6)}, 1.0);
            break;
        }
    }

    size_t bFixesIterator;
    std::vector<gsm_object_xi_content> tablePhiNodes = {};
    std::vector<double> scoresNodes = {};
    std::time_t previousTimeStamp = 0;
    int nodeNumber = 0;
    //get flight nodes
    for(std::string line; std::getline(stream, line);)
    {
        if(line.at(0) == 'B')
        {
            std::vector<gsm_object_xi_content> tablePhiNode = {};
            std::vector<double> scoresNode = {};
            std::string time = line.substr(1,6);
            PutInDb(db, tablePhiNode, scoresNode, "time", time);

            std::string latitude = line.substr(7,8);
            PutInDb(db, tablePhiNode, scoresNode, "latitude", latitude);

            std::string longitude = line.substr(15,9);
            PutInDb(db, tablePhiNode, scoresNode, "longitude", longitude);

            std::string fixValidity = line.substr(24,1);
            PutInDb(db, tablePhiNode, scoresNode, "fixValidity", fixValidity);

            std::string pressureAltitude = line.substr(25, 5);
            PutInDb(db, tablePhiNode, scoresNode, "pressure_altitude", pressureAltitude);

            std::string gnssAltitude = line.substr(30, 5);
            PutInDb(db, tablePhiNode, scoresNode, "gnss_altitude", gnssAltitude);

            std::tm t{};
            std::istringstream ss(date + time);
            //DDMMYYYY HHMMSS
            ss >> std::get_time(&t, "%d%m%Y%H%M%S");
            if (ss.fail())
            {
                throw std::runtime_error{"fail to parse fullDate"};
            }
            std::time_t timeStamp = mktime(&t);
            PutInDb(db, tablePhiNode, scoresNode, "unix_time", std::to_string(timeStamp));

            double latDegrees = (double) stoi(latitude.substr(0, 2));
            double latMinutes = (double) stoi(latitude.substr(2, 5));
            latMinutes = latMinutes / 100000;
            latMinutes = (latMinutes*10)/6;
            int latSign = (latitude.at(7) == 'N' ? 1 : -1);
            double latitudeDouble = (latDegrees + latMinutes) * latSign;
            PutInDb(db, tablePhiNode, scoresNode, "latitude_double", std::to_string(latitudeDouble));

            double longDegrees = (double) stoi(longitude.substr(0, 3));
            double longMinutes = (double) stoi(longitude.substr(3, 5));
            longMinutes = longMinutes / 100000;
            longMinutes = (longMinutes*10)/6;
            int longSign = (longitude.at(8) == 'E' ? 1 : -1);
            double longitudeDouble = (longDegrees + longMinutes) * longSign;
            PutInDb(db, tablePhiNode, scoresNode, "longitude_double", std::to_string(longitudeDouble));

            createFast(db, ++db.db->max_id, {"b_fix"}, {std::to_string(nodeNumber)}, {scoresNode}, {{{"data"}, {tablePhiNode}}});
            tablePhiNodes.emplace_back(db.db->max_id);
            scoresNodes.emplace_back(1.0);
            nodeNumber++;
            if (timeStamp - previousTimeStamp >= 3600 && weather)
            {
                previousTimeStamp = timeStamp;
                LoadWeather(db, latitudeDouble, longitudeDouble, timeStamp);
                std::cout << downloadedResponse << std::endl;
            }
        }
    }
    createFast(db, ++db.db->max_id, {"b_fixes"}, {}, {scoresNodes}, {{"b_fix", {tablePhiNodes}}});
    bFixesIterator = db.db->max_id;
    tablePhiIgc.emplace_back(db.db->max_id);
    tablePhiIgc.emplace_back(1.0);
    createFast(db, ++db.db->max_id, {"igc_file"}, {pathToFile}, {scoresIgc}, {{"fixes", {tablePhiIgc}}});
    //calculate_lift(db, nodesIterator);
    calculate_bearing_change(db, bFixesIterator);
}

void LoadGraph(gsm_inmemory_db_view &db,
               std::vector<std::string> &graphPaths){
    std::vector<gsm_object_xi_content> tablePhiGraph = {};
    std::vector<double> scoresGraph = {};
    for(auto &file : graphPaths) {
        LoadCsvFile(db, file, true);
        tablePhiGraph.emplace_back(db.o);
        scoresGraph.emplace_back(db.o);
    }
}

void old_main() {

    // Database initialisation, with an empty root
    auto actual = std::make_shared<gsm_inmemory_db>();
    gsm_inmemory_db_view db(0, actual);
    // global iterator keeping track of gsm ids
//    int iterator = 0;

    std::string csvPath = "data/csv_files/";
    std::string jsonPath = "data/json_files/generated.json";
    std::string igcPath = "data/igc_files/example2.igc";

    //LoadIgcFile(db, igcPath, iterator, false);
    //LoadCsvDb(db, csvPath, iterator);
    //LoadJsonFile(db, jsonPath, iterator);
    //LoadCsvFile(db, csvPath + "customers-1.csv", iterator);
    //LoadGraph(db, iterator);
    LoadWeather(db, 52.598447, 0.923155, 1654352543);
    // Setting that the root now shall contain the other elements, while updating 0 to a new object

    /*
    db = map(db, [](const gsm_object& ref) { return ref.ell; },
             [](const gsm_object& ref) { return ref.xi;  },
             [](const gsm_object& ref) {return ref.phi;});
    */

    // Assuming that all of the operations are done:
    // Therefore, I can also set up the indices

    gsm_db_indices idx;
    idx.init(*db.db);
    idx.valid_data();

    // Dumping the db into a XML format
    dump_to_xml(*db.db, idx, "test.xml");
    std::cout << "Hello, World!" << std::endl;
//    return 0;
}

#include <gsql_gsm/script_1/ScriptVisitor.h>
#include <gsql_gsm/script_1/ScriptAST.h>
#include <fstream>
#include <filesystem>
#include <gtest/gtest.h>

void other_scenario() {
    std::filesystem::path scripts_folder = std::filesystem::current_path().parent_path() / "data" / "script";
    auto database = std::make_shared<gsm_inmemory_db>();
    gsm_inmemory_db_view view{0, database};
    createFast(view, 1, "int", {"38"}, {1.0});
    createFast(view, 2, "label \"timon\"", {}, {1.0}, {{"age", {{1,1.0}}}});
    createFast(view, 3, "label \"timon\"", {"< \"ciao\" >> \"bene\" ; \"tutta\" >> 2 ; \"dritta\" >> \"premiata\" >"}, {1.0});
    script::compiler::ScriptVisitor::bindGSM(database.get());
    std::ifstream file{"/home/giacomo/CLionProjects/gsm_gsql/data/script/script_10.txt"};
    std::cout << script::compiler::ScriptVisitor::eval(file)->toString() << std::endl;

}

void graph_scenario() {
    std::filesystem::path scripts_folder = std::filesystem::current_path() / "data" / "script";
    auto database = std::make_shared<gsm_inmemory_db>();
    gsm_inmemory_db_view view{0, database};
    database->O[0].ell = "label \"graph\"";
    createFast(view, 1, "label \"user\"", {"< \"name\" >> \"Alex\">"}, {1.0});
    createFast(view, 2, "label \"user\"", {"< \"name\" >> \"Aries\">"}, {1.0});
    createFast(view, 3, "label \"follows\"", {"< \"date\" >> \"2018-06-03 15:27\">"}, {1.0});
    database->O[0].ell = "label \"graph\"";
    database->O[3].phi["src"].emplace_back(1);
    database->O[3].phi["dst"].emplace_back(2);
    database->O[0].phi["nodes"].emplace_back(0);
    database->O[0].phi["nodes"].emplace_back(1);
    database->O[0].phi["edges"].emplace_back(3);
    script::compiler::ScriptVisitor::bindGSM(database.get());
    std::ifstream file{scripts_folder / "script_09.txt"};
    std::cout << script::compiler::ScriptVisitor::eval(file)->toString() << std::endl;

}

int main() {
     other_scenario();
//    graph_scenario();
    return 0;
}


