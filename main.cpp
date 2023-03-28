#include <iostream>
#include "gsql_gsm/gsm_db_indices.h"
#include <gsql_gsm/gsql_operators.h>

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


void JsonRecursion(json data, int &iterator, std::vector<gsm_object_xi_content> &tablePhi, std::vector<double> &scores, gsm_inmemory_db &db, std::string previousKey = "")
{
    for(auto &it : data.items())
    {
        if(it.value().is_object() || it.value().is_array())
        {
            std::vector<gsm_object_xi_content> tablePhiObject = {};
            std::vector<double> scoresObject = {};
            JsonRecursion(it.value(), iterator, tablePhiObject, scoresObject, db, it.key());
            std::string phiString = (data.is_array() ? previousKey + it.key() : it.key());
            createFast(db, ++iterator, {"json_object"}, {}, {scoresObject}, {{phiString, {tablePhiObject}}});
        }
        else
        {
            std::string ell = (data.is_array() ? previousKey : it.key());
            createFast(db, ++iterator, {ell}, {to_string(it.value())});
        }
        tablePhi.emplace_back(iterator);
        scores.emplace_back(1.0);
    }
}


void LoadCsvFile(gsm_inmemory_db &db, std::string csvFileDir,  int &iterator, bool graph = false)
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
                JsonRecursion(data, iterator, tablePhi, scores, db, colHeaders.at(j));
            }
            else
            {
                std::string x = colHeaders.at(j);
                createFast(db, ++iterator, {colHeaders.at(j)}, {row.at(j)});
                tablePhi.emplace_back(iterator, 1.0);
                scores.emplace_back(1.0);
            }
        }

        createFast(db, ++iterator, {"row"}, {row.at(0)}, {scores}, {{"data", {tablePhi}}});
        tablePhiCsv.emplace_back(iterator, 1.0);
        scoresCsv.emplace_back(1.0);
    }
    createFast(db, ++iterator, {"csv_file"}, {csvFileDir}, {scoresCsv}, {{"row", {tablePhiCsv}}});
}

void LoadCsvDb(gsm_inmemory_db &db, std::string pathToDb, int &iterator)
{
    std::vector<gsm_object_xi_content> tablePhiDb = {}; // Phi table for csv db
    std::vector<double> scoresCsvDb = {}; // Scores table for csv db
    for(const auto & entry : std::filesystem::directory_iterator(pathToDb))
    {
        std::cout << entry.path() << std::endl;
        LoadCsvFile(db, entry.path(), iterator);
        tablePhiDb.emplace_back(iterator, 1.0);
        scoresCsvDb.emplace_back(1.0);
    }
    create(db, ++iterator, {"csv_db"}, {pathToDb}, {scoresCsvDb}, {{"csv_file", {tablePhiDb}}});
}




void LoadJson(gsm_inmemory_db &db, std::string pathToFile, int &iterator, std::string xi = "")
{
    json data;
    if(xi == "")
    {
        std::ifstream f(pathToFile);
        xi = pathToFile;
        data = json::parse(f);
    }
    else
    {
        data = json::parse(pathToFile);
    }

    std::vector<gsm_object_xi_content> tablePhiJson = {};
    std::vector<double> scoresJson = {};
    JsonRecursion(data, iterator, tablePhiJson, scoresJson, db);
    createFast(db, ++iterator, {"json_file"}, {xi}, {scoresJson}, {{"json_file", {tablePhiJson}}});
}

std::string downloadedResponse;

std::size_t writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
{
    if(buffer_in != NULL)
    {
        downloadedResponse.assign(data);
        return size*nmemb;
    }
    return 0;
}

std::string DownloadWeather(std::string URL)
{
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


void LoadWeather(gsm_inmemory_db &db, int &iterator, double lat, double lon, std::time_t start)
{
    std::ifstream file("/home/neo/gsm_gsql/api_keys/openweather.txt");
    std::string apiKey;
    file >> apiKey;
    std::stringstream ss;
    ss << "https://history.openweathermap.org/data/2.5/history/city?"
    << "lat=" << lat
    << "&lon=" << lon
    << "&type=hour&start=" << start
    << "&cnt=" << 1
    << "&appid=" << apiKey;

    std::string url = ss.str();
    std::cout << "URL:" << url << std::endl;
    std::string someWeather = DownloadWeather(url);
    LoadJson(db, someWeather, iterator, "weather_1");
}

void LoadIgcFile(gsm_inmemory_db &db, std::string pathToFile, int &iterator, bool weather)
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
            createFast(db, ++iterator, {"date"}, {line.substr(5, 6)});
            break;
        }
    }
    tablePhiIgc.emplace_back(iterator);
    scoresIgc.emplace_back(1.0);

    std::vector<gsm_object_xi_content> tablePhiNodes = {};
    std::vector<double> scoresNodes = {};
    std::time_t previousTimeStamp = 0;
    //get flight nodes
    for(std::string line; std::getline(stream, line);)
    {
        if(line.at(0) == 'B')
        {
            std::string time = line.substr(1,6);
            createFast(db, ++iterator, {"time"}, {time});
            tablePhiNodes.emplace_back(iterator);
            scoresNodes.emplace_back(1.0);

            std::string latitude = line.substr(7,8);
            createFast(db, ++iterator, {"latitude"}, {latitude});
            tablePhiNodes.emplace_back(iterator);
            scoresNodes.emplace_back(1.0);

            std::string longitude = line.substr(15,9);
            createFast(db, ++iterator, {"longitude"}, {longitude});
            tablePhiNodes.emplace_back(iterator);
            scoresNodes.emplace_back(1.0);

            std::string fixValidity = line.substr(24,1);
            createFast(db, ++iterator, {"fixValidity"}, {fixValidity});
            tablePhiNodes.emplace_back(iterator);
            scoresNodes.emplace_back(1.0);

            std::string pressureAltitude = line.substr(25, 5);
            createFast(db, ++iterator, {"pressureAltitude"}, {pressureAltitude});
            tablePhiNodes.emplace_back(iterator);
            scoresNodes.emplace_back(1.0);

            std::string gnssAltitude = line.substr(30, 5);
            createFast(db, ++iterator, {"gnssAltitude"}, {gnssAltitude});
            tablePhiNodes.emplace_back(iterator);
            scoresNodes.emplace_back(1.0);

            if(weather) {
                std::tm t{};
                std::istringstream ss(date + time);
                //DDMMYYYY HHMMSS
                ss >> std::get_time(&t, "%d%m%Y%H%M%S");
                if (ss.fail()) {
                    throw std::runtime_error{"fail to parse fullDate"};
                }
                std::time_t timeStamp = mktime(&t);
                if (timeStamp - previousTimeStamp <= 3600)
                    continue;

                double latDegrees = (double) stoi(latitude.substr(0, 2));
                double latMinutes = (double) stoi(latitude.substr(2, 5));

                latMinutes = latMinutes / 100000;
                latMinutes = (latMinutes * 10) / 6;
                int latSign = (latitude.at(7) == 'N' ? 1 : -1);
                double latitudeDouble = (latDegrees + latMinutes) * latSign;

                double longDegrees = (double) stoi(longitude.substr(0, 3));
                double longMinutes = (double) stoi(longitude.substr(3, 5));
                longMinutes = longMinutes / 100000;
                longMinutes = (longMinutes * 10) / 6;
                int longSign = (longitude.at(8) == 'E' ? 1 : -1);
                double longitudeDouble = (longDegrees + longMinutes) * longSign;

                if (timeStamp - previousTimeStamp >= 3600) {
                    previousTimeStamp = timeStamp;
                    LoadWeather(db, iterator, latitudeDouble, longitudeDouble, timeStamp);
                    std::cout << downloadedResponse << std::endl;
                }
            }
        }
    }
    createFast(db, ++iterator, {"nodes"}, {}, {scoresNodes}, {{"nodes", {tablePhiNodes}}});
    tablePhiIgc.emplace_back(iterator);
    tablePhiIgc.emplace_back(1.0);
    createFast(db, ++iterator, {"igc_file"}, {pathToFile}, {scoresIgc}, {{"igc_file", {tablePhiIgc}}});
}

void LoadGraph(gsm_inmemory_db &db, int &iterator, std::vector<std::string> &graphPaths)
{
    std::vector<gsm_object_xi_content> tablePhiGraph = {};
    std::vector<double> scoresGraph = {};
    for(auto &file : graphPaths)
    {
        LoadCsvFile(db, file, iterator, true);
        tablePhiGraph.emplace_back(iterator);
        scoresGraph.emplace_back(iterator);
    }

}










int main() {

    // Database initialisation, with an empty root
    gsm_inmemory_db db;
    // global iterator keeping track of gsm ids
    int iterator = 0;

    std::string csvPath = "/home/neo/gsm_gsql/csv_files/";
    std::string jsonPath = "/home/neo/gsm_gsql/json_files/generated.json";
    std::string igcPath = "/home/neo/gsm_gsql/igc_files/example2.igc";

    LoadIgcFile(db, igcPath, iterator, false);
    //LoadCsvDb(db, csvPath, iterator);
    //LoadJsonFile(db, jsonPath, iterator);
    //LoadCsvFile(db, csvPath + "customers-1.csv", iterator);
    //LoadGraph(db, iterator);
    //LoadWeather(db, iterator);
    // Setting that the root now shall contain the other elements, while updating 0 to a new object

    /*
    db = map(db, [](const gsm_object& ref) { return ref.ell; },
             [](const gsm_object& ref) { return ref.xi;  },
             [](const gsm_object& ref) {return ref.phi;});
    */

    // Assuming that all of the operations are done:
    // Therefore, I can also set up the indices

    gsm_db_indices idx;
    idx.init(db);
    idx.valid_data();

    // Dumping the db into a XML format
    dump_to_xml(db, idx, "/home/neo/gsm_gsql/test.xml");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}