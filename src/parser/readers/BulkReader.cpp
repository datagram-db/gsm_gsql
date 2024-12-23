//
// Created by giacomo on 22/12/24.
//

#include <parser/readers/BulkReader.h>
#include <database/ndp/ndp_batch.h>
#include <parser/writer.h>
#include <filesystem>


//std::optional<gsm_object> BulkReader::resolve(const std::string& path, size_t graph_id, size_t object_id) const {
//    std::filesystem::path p = path;
//    if (is_directory(p)) {
//        auto f = p / std::to_string(graph_id);
//        auto str = f.string();
//        if (is_regular_file(p)) {
//            std::filesystem::path has_map{str+ "_map.tab"};
//            if (is_regular_file(has_map)) {
//                // Check if this is not a map object, and if this is associated with a map object
//                candidate_paths.emplace_back(std::stoull(str));
//            }
//        }
//    }
//    return {};
//}

bool BulkReader::readFromPath(const std::string& path) {
    std::filesystem::path p = path;
    if (is_directory(p)) {
        std::vector<size_t> candidate_paths;
        for (const auto& f : std::filesystem::directory_iterator(p)) {
            auto str = f.path().string();
            if (f.is_regular_file() && (!str.ends_with("_map.tab")) && std::all_of(str.begin(), str.end(),::isdigit)) {
                std::filesystem::path has_map{str+ "_map.tab"};
                if (is_regular_file(has_map)) {
                    // Check if this is not a map object, and if this is associated with a map object
                    candidate_paths.emplace_back(std::stoull(str));
                }
            }
        }
        std::sort(candidate_paths.begin(), candidate_paths.end());
        for (const auto& id : candidate_paths) {
            this->writer->initDatabase();
            mapping reader(std::to_string(id));
            for (size_t i = 0, N = reader.getGreatestObjectId(); i<=N; i++) {
                this->writer->writeObject(reader.retrieve(i), {});
            }
        }
        this->writer->close();
    } else if (is_regular_file(p)) {
        mapping reader(path);
        this->writer->initDatabase();
        for (size_t i = 0, N = reader.getGreatestObjectId(); i<=N; i++) {
            this->writer->writeObject(reader.retrieve(i), {});
        }
        this->writer->close();
        return true;
    } else {
        this->writer->close();
        return false;
    }
    return false;
}