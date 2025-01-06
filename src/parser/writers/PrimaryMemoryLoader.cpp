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
//        if (graphId_eventId.first > 0)
//            std::cerr << "WARNING: this is something should not happen when loading Schema" << std::endl;
        if (graphId_eventId.second != object.id) {
            queued_objects[object.id] = object;
        } else {
            actual_writeObject(object, map_for_types);
            for (auto it = queued_objects.begin(); it != queued_objects.end(); ) {
                if (it->first == graphId_eventId.second) {
                    actual_writeObject(it->second, map_for_types);
                    it = queued_objects.erase(it);
                } else
                    break;
            }
        }
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