#include <iostream>
#include "gsql_gsm/gsm_db_indices.h"

#include <gsql_gsm/gsql_operators.h>

#include <string>
#include <gsql_gsm/dump_to_xml.h>

#include <vector>
#include "rapidcsv.h"


int main() {
    // Database initialisation, with an empty root'
    gsm_inmemory_db db;

    std::string whatFile = "customers-1.csv";
    rapidcsv::Document doc("/home/neo/Desktop/gsm_gsql/csv_files/" + whatFile);

    int fileNumber = 1;

    std::vector<std::string> colHeaders = doc.GetColumnNames();
    std::vector<gsm_object_xi_content> tablePhiCsv = {};
    std::vector<double> scoresCsv = {};

    for(int i = 0; i < doc.GetRowCount(); i++)
    {
        std::vector<std::string> row = doc.GetRow<std::string>(i);
        std::vector<gsm_object_xi_content> tablePhi = {};
        std::vector<double> scores = {};
        for(int j = 0; j < row.size(); j++)
        {
            int whatRowId = fileNumber + (j+1)+(row.size() * i+1);
            db = create(db, whatRowId, {colHeaders.at(j)}, {row.at(j)});
            tablePhi.emplace_back(whatRowId, 1.0);
            scores.emplace_back(1.0);
        }
        int forWhichRow = fileNumber + (i+1);
        db = create(db, forWhichRow, {"row"}, {row.at(0)}, {scores}, {{"data", {tablePhi}}});
        tablePhiCsv.emplace_back(forWhichRow, 1.0);
        scoresCsv.emplace_back(1.0);
    }
    db = create(db, fileNumber, {"csv_file"}, {whatFile}, {scoresCsv}, {{"row", {tablePhiCsv}}});

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