#include <iostream>
#include "gsql_gsm/gsm_db_indices.h"

#include <gsql_gsm/gsql_operators.h>

#include <string>
#include <gsql_gsm/dump_to_xml.h>

#include <vector>
#include "rapidcsv.h"
#include <filesystem>

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



int main() {
    // Database initialisation, with an empty root
    gsm_inmemory_db db;

    // global iterator keeping track of gsm ids
    int iterator = 1;

    std::string path = "/home/neo/Desktop/gsm_gsql/csv_files/";

    LoadCsvDb(db, path, iterator);

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
    dump_to_xml(db, idx, "/home/neo/Desktop/gsm_gsql/test.xml");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}