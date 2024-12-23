//
// Created by giacomo on 23/12/24.
//

#include <parser/ra_readers/RandomAccessBulkReader.h>

std::optional<gsm_object> RandomAccessBulkReader::retrieve(size_t graph_id, size_t id) {
    auto map = open_graph(graph_id);
    if (map) {
        return {map->retrieve(id)};
    }
    return {};
}

ssize_t RandomAccessBulkReader::database_size(size_t graph_id) {
    auto map = open_graph(graph_id);
    if (map) {
        return map->getGreatestObjectId()+1;
    }
    return -1;
}

size_t RandomAccessBulkReader::count_databases()  {
    size_t result = 0;
    if (is_directory(p)) {
        for (const auto &f: std::filesystem::directory_iterator(p)) {
            auto str = f.path().string();
            if (f.is_regular_file() && (!str.ends_with("_map.tab")) &&
                std::all_of(str.begin(), str.end(), ::isdigit)) {
                std::filesystem::path has_map{str + "_map.tab"};
                if (is_regular_file(has_map)) {
// Check if this is not a map object, and if this is associated with a map object
                    result++;
                }
            }
        }
    }
    return result;
}