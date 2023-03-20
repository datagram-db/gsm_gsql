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
#include <chrono>
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




void LoadJsonFile(gsm_inmemory_db &db, std::string pathToFile, int &iterator)
{
    std::ifstream f(pathToFile);
    json data = json::parse(f);
    std::vector<gsm_object_xi_content> tablePhiJson = {};
    std::vector<double> scoresJson = {};
    JsonRecursion(data, iterator, tablePhiJson, scoresJson, db);
    createFast(db, ++iterator, {"json_file"}, {pathToFile}, {scoresJson}, {{"json_file", {tablePhiJson}}});
}

void LoadIgcFile(gsm_inmemory_db &db, std::string pathToFile, int &iterator)
{
    std::ifstream stream(pathToFile);
    std::string line;

    std::vector<gsm_object_xi_content> tablePhiIgc = {};
    std::vector<double> scoresIgc = {};

    //get pilot and date
    for(std::string line; std::getline(stream, line);)
    {
        if(line.substr(0,5) == "HFDTE")
        {
            createFast(db, ++iterator, {"date"}, {line.substr(5, 6)});
            break;
        }
    }
    tablePhiIgc.emplace_back(iterator);
    scoresIgc.emplace_back(1.0);

    std::vector<gsm_object_xi_content> tablePhiNodes = {};
    std::vector<double> scoresNodes = {};

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

void BenchmarkJsonLoading()
{
    std::chrono::time_point<std::chrono::system_clock> startLoad, endLoad, startIndex, endIndex;
    std::chrono::duration<double> loadTime;
    std::chrono::duration<double> indexTime;
    std::fstream fileOut("/home/neo/gsm_gsql/bench_files/json_bench.csv", std::fstream::out);
    fileOut << "overall,loadtime,indextime\n";
    for(const auto & entry : std::filesystem::directory_iterator("/home/neo/gsm_gsql/generate_json/"))
    {
        gsm_inmemory_db db;
        int iterator = 0;

        startLoad = std::chrono::system_clock::now();
        LoadJsonFile(db, entry.path(), iterator);
        endLoad = std::chrono::system_clock::now();


        gsm_db_indices idx;
        startIndex = std::chrono::system_clock::now();
        idx.init(db);
        idx.valid_data();
        endIndex = std::chrono::system_clock::now();

        loadTime = endLoad - startLoad;
        indexTime = endIndex - startIndex;
        std::cout << entry << '\n';
        std::cout << "loadTime:" << loadTime.count() << " indexTime:" << indexTime.count() << '\n';


        std::string pathString{entry.path().string()};
        pathString = pathString.substr(42,pathString.length()-46);
        std::string delimiter = "_";
        size_t last = 0;
        size_t next = 0;

        while((next = pathString.find(delimiter, last)) != std::string::npos)
        {
            std::string x = pathString.substr(last, next-last);
            last = next + 1;
        }
        std::string x = pathString.substr(last);
        fileOut << x.substr(0, x.length()-1) << ',';
        fileOut << loadTime.count() << ',' << indexTime.count() << '\n';
    }
}

void BenchmarkCsvLoading()
{
    std::chrono::time_point<std::chrono::system_clock> startLoad, endLoad, startIndex, endIndex;
    std::chrono::duration<double> loadTime;
    std::chrono::duration<double> indexTime;
    std::fstream fileOut("/home/neo/gsm_gsql/bench_files/csv_bench.csv", std::fstream::out);
    fileOut << "columns,rows,overall,loadtime,indextime\n";
    for(const auto & entry : std::filesystem::directory_iterator("/home/neo/gsm_gsql/generate_csv/"))
    {
        gsm_inmemory_db db;
        int iterator = 0;

        startLoad = std::chrono::system_clock::now();
        LoadCsvFile(db, entry.path(), iterator);
        endLoad = std::chrono::system_clock::now();


        gsm_db_indices idx;
        startIndex = std::chrono::system_clock::now();
        idx.init(db);
        idx.valid_data();
        endIndex = std::chrono::system_clock::now();

        loadTime = endLoad - startLoad;
        indexTime = endIndex - startIndex;
        std::cout << entry << '\n';
        std::cout << "loadTime:" << loadTime.count() << " indexTime:" << indexTime.count() << '\n';


        std::string pathString{entry.path().string()};
        pathString = pathString.substr(42,pathString.length()-46);
        std::string delimiter = "_";
        size_t last = 0;
        size_t next = 0;

        while((next = pathString.find(delimiter, last)) != std::string::npos)
        {
            std::string x = pathString.substr(last, next-last);
            fileOut << x.substr(3, x.length()) << ',';
            last = next + 1;
        }
        std::string x = pathString.substr(last);
        fileOut << x.substr(3, x.length()) << ',';

        fileOut << loadTime.count() << ',' << indexTime.count() << '\n';
    }
}

std::string FindPath(std::vector<std::string> &paths, std::string findWhat)
{
    for(std::string s : paths)
    {
        std::string delimiter = "/";
        size_t last = 0;
        size_t next = 0;
        while((next = s.find(delimiter, last)) != std::string::npos)
        {
            last = next + 1;
        }

        std::string x = s.substr(last);
        if(x.substr(0, findWhat.length()) == findWhat)
        {
            return s;
        }
    }
}


void BenchmarkGraphLoading()
{
    std::chrono::time_point<std::chrono::system_clock> startLoad, endLoad, startIndex, endIndex;

    std::chrono::duration<double> loadTime;
    std::chrono::duration<double> indexTime;

    std::vector<std::string> paths;

    std::fstream fileOut("/home/neo/gsm_gsql/bench_files/graph_bench.csv", std::fstream::out);
    fileOut << "id,edge,graphhead,vertex,loadtime,indextime\n";
    int fileIterator = 0;
    for(const auto & entry : std::filesystem::directory_iterator("/home/neo/gsm_gsql/generate_graph/"))
    {
        fileIterator++;
        paths.push_back(entry.path().string());
    }
    fileIterator /= 3;

    for(int i = 1; i <= fileIterator; i++)
    {
        gsm_inmemory_db db;
        int iterator = 0;

        std::vector<std::string> path =
        {
                FindPath(paths, std::to_string(i) +"_generated_edge"),
                FindPath(paths, std::to_string(i) + "_generated_graphhead"),
                FindPath(paths, std::to_string(i) + "_generated_vertex")
        };
        //1_generated_edge
        //1_generated_graphhead
        //1_generated_vertex

        startLoad = std::chrono::system_clock::now();
        LoadGraph(db, iterator, path);
        endLoad = std::chrono::system_clock::now();


        gsm_db_indices idx;
        startIndex = std::chrono::system_clock::now();
        idx.init(db);
        idx.valid_data();
        endIndex = std::chrono::system_clock::now();


        std::string delimiter = "_";
        size_t last = 0;
        size_t next = 0;
        while((next = path[0].find(delimiter, last)) != std::string::npos)
        {
            last = next + 1;
        }
        std::string xEdge = path[0].substr(last);

        next = 0;
        last = 0;
        while((next = path[1].find(delimiter, last)) != std::string::npos)
        {
            last = next + 1;
        }
        std::string xHead = path[1].substr(last);

        next = 0;
        last = 0;
        while((next = path[2].find(delimiter, last)) != std::string::npos)
        {
            last = next + 1;
        }
        std::string xVertex = path[2].substr(last);

        loadTime = endLoad - startLoad;
        indexTime = endIndex - startIndex;
        fileOut << i << "," << xEdge << "," << xHead << "," << xVertex << "," << loadTime.count() << ',' << indexTime.count() << '\n';
        return;
    }
}

int main() {
    //BenchmarkCsvLoading();
    //BenchmarkJsonLoading();
    BenchmarkGraphLoading();
    // Database initialisation, with an empty root
    gsm_inmemory_db db;
    // global iterator keeping track of gsm ids
    int iterator = 0;

    std::string csvPath = "/home/neo/gsm_gsql/csv_files/";
    std::string jsonPath = "/home/neo/gsm_gsql/json_files/generated.json";
    std::string igcPath = "/home/neo/gsm_gsql/igc_files/example2.igc";

    //LoadIgcFile(db, igcPath, iterator);
    //LoadCsvDb(db, csvPath, iterator);
    //LoadJsonFile(db, jsonPath, iterator);
    //LoadCsvFile(db, csvPath + "customers-1.csv", iterator);
    //LoadGraph(db, iterator);

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