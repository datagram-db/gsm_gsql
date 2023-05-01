#include <iostream>
#include "gsql_gsm/gsm_db_indices.h"
#include <gsql_gsm/gsql_operators.h>
#include <gsql_gsm/igc_operators.h>
#include <gsql_gsm/json_operators.h>

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


void put_db(gsm_inmemory_db &db, int &iterator, std::vector<gsm_object_xi_content>&tablePhi,
            std::vector<double> &scores, std::string ell, std::string xi, double score = 1.0)
{
    create_fast(db, ++iterator, {ell}, {xi});
    tablePhi.emplace_back(iterator, score);
    scores.emplace_back(score);
}

void load_csvfile(gsm_inmemory_db &db, std::string csvFileDir, int &iterator, bool graph = false)
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
                json_recursion(data, iterator, tablePhi, scores, db, colHeaders.at(j));
            }
            else
            {
                std::string x = colHeaders.at(j);
                put_db(db, iterator, tablePhi, scores, colHeaders.at(j), row.at(j));
            }
        }

        create_fast(db, ++iterator, {"row"}, {row.at(0)}, {scores}, {{"data", {tablePhi}}});
        tablePhiCsv.emplace_back(iterator, 1.0);
        scoresCsv.emplace_back(1.0);
    }
    create_fast(db, ++iterator, {"csv_file"}, {csvFileDir}, {scoresCsv}, {{"row", {tablePhiCsv}}});
}

void load_csvdb(gsm_inmemory_db &db, std::string pathToDb, int &iterator)
{
    std::vector<gsm_object_xi_content> tablePhiDb = {}; // Phi table for csv db
    std::vector<double> scoresCsvDb = {}; // Scores table for csv db
    for(const auto & entry : std::filesystem::directory_iterator(pathToDb))
    {
        std::cout << entry.path() << std::endl;
        load_csvfile(db, entry.path(), iterator);
        tablePhiDb.emplace_back(iterator, 1.0);
        scoresCsvDb.emplace_back(1.0);
    }
    create(db, ++iterator, {"csv_db"}, {pathToDb}, {scoresCsvDb}, {{"csv_file", {tablePhiDb}}});
}

int load_igcfile(gsm_inmemory_db &db, std::string pathToFile, int &iterator)
{
    std::ifstream stream(pathToFile);
    std::vector<gsm_object_xi_content> tablePhiIgc = {};
    std::vector<double> scoresIgc = {};
    std::string date;
    //get pilot and date
    for(std::string line; std::getline(stream, line);)
    {
        if(line.substr(0,5) == "HFDTE")
        {
            date = line.substr(line.length()-7, 4) + "20" + line.substr(line.length()-3, 2);
            put_db(db, iterator, tablePhiIgc, scoresIgc, "date", {line.substr(5, 6)});
            break;
        }
    }

    std::vector<gsm_object_xi_content> tablePhiBfixes = {};
    std::vector<double> scoresBfixes = {};
    //get flight nodes
    for(std::string line; std::getline(stream, line);)
    {
        if(line.at(0) == 'B')
        {
            create_fast(db, ++iterator, {"b_fix"}, {""});
            std::vector<gsm_object_xi_content> tablePhiBfix = {};
            std::vector<double> scoresBfix = {};

            std::string time = line.substr(1,6);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "time", time);
            //db.O[iterator].ell.push_back("time");
            //db.O[iterator].xi.push_back(time);

            std::string latitude = line.substr(7,8);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "latitude", latitude);
            //db.O[iterator].ell.push_back("latitude");
            //db.O[iterator].xi.push_back(latitude);

            std::string longitude = line.substr(15,9);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "longitude", longitude);
            //db.O[iterator].ell.push_back("longitude");
            //db.O[iterator].xi.push_back(longitude);

            std::string fixValidity = line.substr(24,1);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "fixValidity", fixValidity);
            //db.O[iterator].ell.push_back("fixValidity");
            //db.O[iterator].xi.push_back(fixValidity);

            std::string pressureAltitude = line.substr(25, 5);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "pressure_altitude", pressureAltitude);
            db.O[iterator].ell.push_back("pressure_altitude");
            db.O[iterator].xi.push_back(pressureAltitude);

            std::string gnssAltitude = line.substr(30, 5);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "gnss_altitude", gnssAltitude);
            //db.O[iterator].ell.push_back("gnss_altitude");
            //db.O[iterator].xi.push_back(gnssAltitude);

            std::tm t{};
            std::istringstream ss(date + time);
            //DDMMYYYY HHMMSS
            ss >> std::get_time(&t, "%d%m%Y%H%M%S");
            if (ss.fail())
            {
                throw std::runtime_error{"fail to parse fullDate"};
            }
            std::time_t timeStamp = mktime(&t);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "unix_time", std::to_string(timeStamp));
            db.O[iterator].ell.push_back("unix_time");
            db.O[iterator].xi.push_back(std::to_string(timeStamp));

            double latDegrees = (double) stoi(latitude.substr(0, 2));
            double latMinutes = (double) stoi(latitude.substr(2, 5));
            latMinutes = latMinutes / 100000;
            latMinutes = (latMinutes*10)/6;
            int latSign = (latitude.at(7) == 'N' ? 1 : -1);
            double latitudeDouble = (latDegrees + latMinutes) * latSign;
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "latitude_double", std::to_string(latitudeDouble));
            db.O[iterator].ell.push_back("latitude_double");
            db.O[iterator].xi.push_back(std::to_string(latitudeDouble));

            double longDegrees = (double) stoi(longitude.substr(0, 3));
            double longMinutes = (double) stoi(longitude.substr(3, 5));
            longMinutes = longMinutes / 100000;
            longMinutes = (longMinutes*10)/6;
            int longSign = (longitude.at(8) == 'E' ? 1 : -1);
            double longitudeDouble = (longDegrees + longMinutes) * longSign;
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "longitude_double", std::to_string(longitudeDouble));
            db.O[iterator].ell.push_back("longitude_double");
            db.O[iterator].xi.push_back(std::to_string(longitudeDouble));

            //create_fast(db, ++iterator, {"b_fix"}, {std::to_string(nodeNumber)}, {scoresBfix},
            //            {{{"data"}, {tablePhiBfix}}});
            tablePhiBfixes.emplace_back(iterator);
            scoresBfixes.emplace_back(1.0);
        }
    }
    create_fast(db, ++iterator, {"b_fixes"}, {}, {scoresBfixes}, {{"b_fix", {tablePhiBfixes}}});
    int bFixesIterator = iterator;

    tablePhiIgc.emplace_back(iterator);
    tablePhiIgc.emplace_back(1.0);
    create_fast(db, ++iterator, {"igc_file"}, {pathToFile}, {scoresIgc}, {{"fixes", {tablePhiIgc}}});
    return bFixesIterator;
}

void LoadGraph(gsm_inmemory_db &db, int &iterator, std::vector<std::string> &graphPaths)
{
    std::vector<gsm_object_xi_content> tablePhiGraph = {};
    std::vector<double> scoresGraph = {};
    for(auto &file : graphPaths)
    {
        load_csvfile(db, file, iterator, true);
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
    std::string jsonPath = "/home/neo/gsm_gsql/json_files/vc_6dk65ff_1673719200.json";
    std::string igcPath = "/home/neo/gsm_gsql/igc_files/example1.igc";

    //load_jsonEllXiFile(db, jsonPath, iterator, {"currentConditions"}, "weather");


    int nwm = load_igcfile(db, igcPath, iterator);
    calculate_lift(db, nwm, iterator);
    int geoHashesIterator = generate_weatherbucket(db, nwm, iterator);
    export_csv(db, iterator, geoHashesIterator);

    //load_csvdb(db, csvPath, iterator);
    //load_jsonfile(db, jsonPath, iterator);
    //load_csvfile(db, csvPath + "customers-1.csv", iterator);
    //LoadGraph(db, iterator);
    //LoadWeather(db, iterator, 52.598447, 0.923155, 1654352543);
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
    std::cout << sizeof(db) << '\n';
    std::cout << "Hello, World!" << std::endl;
    return 0;
}