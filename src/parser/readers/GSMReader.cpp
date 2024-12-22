//
// Created by giacomo on 21/12/24.
//

#include <parser/readers/GSMReader.h>
#include <fstream>
#include <parsing.h>
#include <parser/writer.h>
#include "yaucl/data/json.h"
#include <filesystem>

bool GSMReader::readFromPath(const std::string& path)  {
    if (!this->writer)
        return false;
    std::filesystem::path path2{path};
    auto schema = path2.parent_path() / "schema.txt";
    if (std::filesystem::exists(schema)) {
        std::ifstream file{schema};
        parse_schema_map(file, propertyname_to_type);
    }
    std::string buffer;
    std::ifstream f(path);
    f.seekg(0, std::ios::end);
    size_t len = f.tellg();
    buffer.resize(f.tellg());
    f.seekg(0);
    f.read(buffer.data(), buffer.size());
    char* string = (char*)buffer.c_str();
    string = skipSpaces(string, &len);
//    size_t graphId = 0;
//    std::vector<std::string> ell, xi;
    double weight; size_t content;
    size_t act_id;
//    size_t noLabel = initLoading(forloading);
    int scanSkip = 0;
    constexpr char const * ID = "id:";
    constexpr char const  DOT = '.';
    constexpr char const * ELL = "ell:";
    constexpr char const * XI = "xi:";
    constexpr char const * PROP = "properties:";
    constexpr char const * PHI = "phi:";
    bool isDbEmpty = true;
    gsm_object current;
//    size_t id;
//    std::pair<size_t,size_t> graphId_eventId{0,0};

    // Defining a simple format to scan, so to avoid using a parser for this.
    while (string && *string) {
        // Reading a new object from the database for value querying
        if (isDbEmpty) {
            this->writer->initDatabase();
            isDbEmpty = false;
        }
//        auto& current = db.back().emplace_back();

        current.id = 0;
//        if (forloading.nodesInGraph.size() == graphId_eventId.first) {
//            forloading.nodesInGraph.emplace_back(graphId_eventId.second);
//        }
//        ell.clear();
        if (!(string = haspos(string, (char*)ID, 0, &len)))  return false;
        current.scores.clear();
        current.ell.clear();
        current.xi.clear();
        current.content.clear();
        current.phi.clear();
        if (sscanf(string, "%lu%n", &current.id, &scanSkip)==EOF)  return false;
//        forloading.nodesInGraph[graphId_eventId.first] = std::max(forloading.nodesInGraph[graphId_eventId.first],graphId_eventId.second);
        len-=scanSkip;
        string+=scanSkip;
        if (!(string = skipSpaces(string, &len)))  return false;
        if (!(string = haspos(string,  (char*)ELL, 0, &len)))  return false;
//        act_id = noLabel;

        if (!(string = atreturn(string, &len)))  return false;
        if (!(string = skipSpaces(string, &len)))  return false;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            current.ell.emplace_back(string, beforeReturn-1);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len)))  return false;
        }


//        act_id = loadObjectEll(forloading, ell, noLabel, graphId_eventId);//// HOC!

        string++; len--;
        if (!(string = skipSpaces(string, &len)))  return false;
        if (!(string = haspos(string,  (char*)XI, 0, &len)))  return false;
//        registerObjectByFirstLabel(forloading, act_id, graphId_eventId); //// HOC!

//        xi.clear();
        if (!(string = atreturn(string, &len)))  return false;
        if (!(string = skipSpaces(string, &len)))  return false;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            current.xi.emplace_back(string, beforeReturn-1);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len)))  return false;
        }
//        loadObjectXi(forloading, xi, graphId_eventId);//// HOC!

        string++; len--;
        if (!(string = skipSpaces(string, &len)))  return false;
        if (!(string = haspos(string,  (char*)PROP, 0, &len)))  return false;

        if (!(string = atreturn(string, &len)))  return false;
        if (!(string = skipSpaces(string, &len)))  return false;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            std::string tmp{string, beforeReturn-1};
            size_t idx = tmp.find("\t");
            if (idx == std::string::npos)  return false;
            std::string key = UNESCAPE(tmp.substr(0, idx));
            std::string val = UNESCAPE(tmp.substr(idx+1));

            current.content[key] = val;
            // Setting up the properties associated to the node
//            loadObjectProperty(forloading, map_for_types, act_id, graphId_eventId, key, val);

            string = beforeReturn;
            if (!(string = skipSpaces(string, &len)))  return false;
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len)))  return false;
        if (!(string = haspos(string,  (char*)PHI, 0, &len)))  return false;

        if (!(string = atreturn(string, &len)))  return false;
        if (!(string = skipSpaces(string, &len)))  return false;

//        forloading.objectScoresLoading[graphId_eventId].emplace_back(1.0);
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            std::string tmp{string, beforeReturn-1};
            tmp = UNESCAPE(tmp);
            string =beforeReturn;
            if (!(string = skipSpaces(string, &len)))  return false;
            while (*string != ';') {
                if (sscanf(string, "%lf\t%lu%n", &weight, &content,&scanSkip)==EOF)  return false;
                len-=scanSkip;
                string+=scanSkip;
                // Setting up the containment associated to the node
                current.phi[tmp].emplace_back(content, weight);
//                forloading.containment_tables[tmp].add(act_id, graphId_eventId, weight, content);
//                forloading.containment_relationships.emplace(tmp);
                if (!(string = skipSpaces(string, &len)))  return false;
            }
            string++;
            len--;
            if (!(string = skipSpaces(string, &len)))  return false;
        }
        this->writer->writeObject(current, propertyname_to_type);
        string++;
        len--;
        if (!(string = skipSpaces(string, &len)))  return false;


        if (strncmp(string,"~~",2)==0) {
            // Finding a new graph
            this->writer->initDatabase();
//            db.emplace_back();
            string+=2; len-=2;
            if (!(string = skipSpaces(string, &len)))  return false;
        }
    }
    return true;
//    maxGraphId = graphId_eventId.first;
}