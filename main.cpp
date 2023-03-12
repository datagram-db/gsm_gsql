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
            db = create(db, ++iterator, {"json_object"}, {}, {scoresObject}, {{phiString, {tablePhiObject}}});
        }
        else
        {
            std::string ell = (data.is_array() ? previousKey : it.key());
            db = create(db, ++iterator, {ell}, {to_string(it.value())});
        }
        tablePhi.emplace_back(iterator);
        scores.emplace_back(1.0);
    }
}

void LoadCsvFile(gsm_inmemory_db &db, std::string csvFileDir,  int &iterator, bool graph = false)
{
    char separator = (graph ? ';' : (char)39); // ; or '
    rapidcsv::Document doc(csvFileDir, rapidcsv::LabelParams(0, -1), rapidcsv::SeparatorParams(separator));


    std::vector<std::string> colHeaders = doc.GetColumnNames();
    std::vector<gsm_object_xi_content> tablePhiCsv = {}; // phi table for csv file
    std::vector<double> scoresCsv = {}; // score table for csv file

    for(int i = 0; i < doc.GetRowCount(); i++)
    {
        std::vector<std::string> row = doc.GetRow<std::string>(i);
        std::vector<gsm_object_xi_content> tablePhi = {}; // phi table for rows
        std::vector<double> scores = {}; // score table for rows
        for(int j = 0; j < row.size(); j++)
        {
            if(graph && (row.at(j).at(0) == '{' || row.at(j).at(0) == '['))
            {
                std::cout <<  "JSONcolHeaders:" << colHeaders.at(j) << " row:"  << row.at(j) << std::endl;
                json data = json::parse(row.at(j));
                JsonRecursion(data, iterator, tablePhi, scores, db, colHeaders.at(j));
            }
            else
            {
                std::cout << "colHeaders: " << colHeaders.at(j) << " row: "  << row.at(j) << std::endl;
                db = create(db, ++iterator, {colHeaders.at(j)}, {row.at(j)});
                tablePhi.emplace_back(iterator, 1.0);
                scores.emplace_back(1.0);
            }
        }
        db = create(db, ++iterator, {"row"}, {row.at(0)}, {scores}, {{"data", {tablePhi}}});
        tablePhiCsv.emplace_back(iterator, 1.0);
        scoresCsv.emplace_back(1.0);
    }
    db = create(db, ++iterator, {"csv_file"}, {csvFileDir}, {scoresCsv}, {{"row", {tablePhiCsv}}});
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
    db = create(db, ++iterator, {"csv_db"}, {pathToDb}, {scoresCsvDb}, {{"csv_file", {tablePhiDb}}});
}




void LoadJsonFile(gsm_inmemory_db &db, std::string pathToFile, int &iterator)
{
    std::ifstream f(pathToFile);
    json data = json::parse(f);
    std::vector<gsm_object_xi_content> tablePhiJson = {};
    std::vector<double> scoresJson = {};
    JsonRecursion(data, iterator, tablePhiJson, scoresJson, db);
    db = create(db, ++iterator, {"json_file"}, {pathToFile}, {scoresJson}, {{"json_file", {tablePhiJson}}});
}

void LoadIgcFile(gsm_inmemory_db &db, std::string pathToFile, int &iterator)
{
    std::ifstream stream(pathToFile);
    std::string line;

    std::vector<gsm_object_xi_content> tablePhiIgc = {};
    std::vector<double> scoresIgc = {};
    std::string date;

    //get pilot and date
    for(std::string line; std::getline(stream, line);)
    {
        if(date != "")
            break;
        if(line.length() < 5)
            continue;
        if(line.substr(0,5) == "HFDTE")
        {
            date = line.substr(5, 6);
            db = create(db, ++iterator, {"date"}, {date});
        }
    }
    tablePhiIgc.emplace_back(iterator);
    scoresIgc.emplace_back(1.0);

    std::vector<gsm_object_xi_content> tablePhiNodes = {};
    std::vector<double> scoresNodes = {};

    //get flight nodes
    for(std::string line; std::getline(stream, line);)
    {
        std::string a = "";
        if(line.at(0) == 'B')
        {
            std::string time = line.substr(1,6);
            std::string latitude = line.substr(7,8);
            std::string longitude = line.substr(15,9);
            std::string fixValidity = line.substr(24,1);
            std::string pressureAltitude = line.substr(25, 5);
            std::string gnssAltitude = line.substr(30, 5);
        }
    }

    //db = create(db, ++iterator, {"igc_file"}, {pathToFile}, {scoresIgc}, {{"igc_file", {tablePhiIgc}}});
}

void LoadGraph(gsm_inmemory_db &db, int &iterator)
{
    std::vector<std::string> graphPaths = {
            "/home/neo/gsm_gsql/graph_files/graphhead.csv",
            "/home/neo/gsm_gsql/graph_files/vertex.csv",
            "/home/neo/gsm_gsql/graph_files/edge.csv"
    };
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
    std::string jsonPath = "/home/neo/gsm_gsql/json_files/example2.json";
    std::string igcPath = "/home/neo/gsm_gsql/igc_files/example2.igc";

    //LoadIgcFile(db, igcPath, iterator);
    //LoadJsonFile(db, jsonPath, iterator);
    //LoadCsvDb(db, csvPath, iterator);
    //LoadCsvFile(db, csvPath + "customers-1.csv", iterator);
    LoadGraph(db, iterator);

    // Setting that the root now shall contain the other elements, while updating 0 to a new object
    db = map(db, [](const gsm_object& ref) { return ref.ell; },
             [](const gsm_object& ref) { return ref.xi;  },
             [](const gsm_object& ref) {return ref.phi;});

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