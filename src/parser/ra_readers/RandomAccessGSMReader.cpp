//
// Created by giacomo on 23/12/24.
//

#include <parser/ra_readers/RandomAccessGSMReader.h>

size_t RandomAccessGSMReader::count_databases() {
    return db.forloading.nGraphs;
};
ssize_t RandomAccessGSMReader::database_size(size_t graph_id) {
    if (db.forloading.nodesInGraph.size() >= graph_id)
        return -1;
    return db.forloading.nodesInGraph[graph_id];
}
std::optional <gsm_object> RandomAccessGSMReader::retrieve(size_t graph_id, size_t id) {
    return db.forloading.resolve_object(graph_id, id);
};