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

int LoadCsvFile(gsm_inmemory_db &db, std::string csvFileDir,  int &iterator)
{
    rapidcsv::Document doc(csvFileDir);


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
            db = create(db, ++iterator, {colHeaders.at(j)}, {row.at(j)});
            tablePhi.emplace_back(iterator, 1.0);
            scores.emplace_back(1.0);
        }
        db = create(db, ++iterator, {"row"}, {row.at(0)}, {scores}, {{"data", {tablePhi}}});
        tablePhiCsv.emplace_back(iterator, 1.0);
        scoresCsv.emplace_back(1.0);
    }
    db = create(db, ++iterator, {"csv_file"}, {csvFileDir}, {scoresCsv}, {{"row", {tablePhiCsv}}});
    return iterator;
}

void LoadCsvDb(gsm_inmemory_db &db, std::string pathToDb, int &iterator)
{
    std::vector<gsm_object_xi_content> tablePhiDb = {}; // Phi table for csv db
    std::vector<double> scoresCsvDb = {}; // Scores table for csv db
    for(const auto & entry : std::filesystem::directory_iterator(pathToDb))
    {
        std::cout << entry.path() << std::endl;
        int x = LoadCsvFile(db, entry.path(), iterator);
        tablePhiDb.emplace_back(x, 1.0);
        scoresCsvDb.emplace_back(1.0);
    }
    db = create(db, ++iterator, {"csv_db"}, {pathToDb}, {scoresCsvDb}, {{"csv_file", {tablePhiDb}}});
}


void recursion(json data, int &iterator, std::vector<gsm_object_xi_content> &tablePhi, std::vector<double> &scores, gsm_inmemory_db &db, std::string previousKey = "")
{
    for(auto &it : data.items())
    {
        std::string xi;
        if(it.value().is_object() || it.value().is_array())
        {
            std::vector<gsm_object_xi_content> tablePhiObject = {};
            std::vector<double> scoresObject = {};
            recursion(it.value(), iterator, tablePhiObject, scoresObject, db, it.key());
            xi = (data.is_array() ? previousKey + it.key() : it.key());
            db = create(db, ++iterator, {"json_object"}, {xi}, {scoresObject}, {{"json_object", {tablePhiObject}}});
        }
        else
        {
            xi = (data.is_array() ? previousKey : it.key());
            db = create(db, ++iterator, {xi}, {to_string(it.value())});
        }
        tablePhi.emplace_back(iterator);
        scores.emplace_back(1.0);
    }
}


int main() {
    // Database initialisation, with an empty root
    gsm_inmemory_db db;

    // global iterator keeping track of gsm ids
    int iterator = 0;

    std::string csvPath = "/home/neo/gsm_gsql/csv_files/";
    std::string jsonPath = "/home/neo/gsm_gsql/json_files/example2.json";

    std::ifstream f(jsonPath);
    json data = json::parse(f);


    std::vector<gsm_object_xi_content> tablePhiJson = {};
    std::vector<double> scoresJson = {};
    recursion(data, iterator, tablePhiJson, scoresJson, db);
    db = create(db, ++iterator, {"json_file"}, {jsonPath}, {scoresJson}, {{"json_file", {tablePhiJson}}});


    //LoadCsvDb(db, csvPath, iterator);
    //LoadCsvFile(db, csvPath + "customers-1.csv", iterator);

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