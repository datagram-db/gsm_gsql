//
// Created by giacomo on 21/12/24.
//

#include <parser/writers/PrimaryMemoryLoader.h>

    void PrimaryMemoryLoader::writeToPath(const std::string& path) {
        start = true;
        graphId_eventId = {0,0};

} ;
    void PrimaryMemoryLoader::initDatabase() {
        noLabel = initLoading(forloading);
        graphId_eventId.second = 0;
        if (forloading.nodesInGraph.size() == graphId_eventId.first) {
            forloading.nodesInGraph.emplace_back(graphId_eventId.second);
        }
        if (start)
            start = false;
        else {
            forloading.nodesInGraph.emplace_back(0);
            graphId_eventId.first++;
        }
    };
    void PrimaryMemoryLoader::writeObject(const gsm_object& object, const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& map_for_types) {
        graphId_eventId.second = object.id;
        forloading.nodesInGraph[graphId_eventId.first] = std::max(forloading.nodesInGraph[graphId_eventId.first],object.id);
        size_t act_id = loadObjectEll2(forloading, object.ell, noLabel, graphId_eventId);
        registerObjectByFirstLabel(forloading, act_id, graphId_eventId);
        loadObjectXi2(forloading, object.xi, graphId_eventId);
        for (const auto& [k, v] : object.content) {
//            if (k == "length")
//                std::cerr << "HIS IS IT" << std::endl;
            if (std::holds_alternative<std::string>(v))
                loadObjectProperty(forloading, map_for_types, act_id, graphId_eventId, k, std::get<std::string>(v));
            else
                loadObjectProperty(forloading, map_for_types, act_id, graphId_eventId, k, std::get<double>(v));

        }
        for (const auto& [tmp, vaks] : object.phi) {
            for (const auto& val : vaks) {
                forloading.containment_tables[tmp].add(act_id, graphId_eventId, val.score, val.id);
                forloading.containment_relationships.emplace(tmp);
            }
        }
        forloading.objectScoresLoading[graphId_eventId].emplace_back(1.0);
    }
    void PrimaryMemoryLoader::close() {
        forloading.nGraphs = graphId_eventId.first+1;
        forloading.index();
    };


#include <parser/readers/PrimaryMemoryReader.h>

DataReader*  PrimaryMemoryLoader::asReader(DataWriter* ptr)  {
    auto* r = new PrimaryMemoryReader(this->forloading);
    r->setWriter(ptr);
    return r;
}