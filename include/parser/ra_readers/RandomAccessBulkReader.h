//
// Created by giacomo on 23/12/24.
//

#ifndef GSM2_RANDOMACCESSBULKREADER_H
#define GSM2_RANDOMACCESSBULKREADER_H

#include <string>
#include <parser/RandomAccessReader.h>
#include <filesystem>
#include <iostream>
#include <database/ndp/ndp_batch.h>

struct RandomAccessBulkReader  {
    RandomAccessBulkReader(const RandomAccessBulkReader&) = default;
    RandomAccessBulkReader& operator=(const RandomAccessBulkReader&) = default;
    RandomAccessBulkReader(RandomAccessBulkReader&&) = delete;
    RandomAccessBulkReader& operator=(RandomAccessBulkReader&&) = delete;
    explicit RandomAccessBulkReader(const std::string& path) : p{path}, p2{path} {
//    std::cout << path << std::endl;
//     std::cout << p << std::endl;
        auto end = std::chrono::system_clock::now();
        time = std::chrono::system_clock::to_time_t(end);
    }
    size_t count_databases() ;
    ssize_t database_size(size_t graph_id) ;
    std::optional<gsm_object> retrieve(size_t graph_id, size_t id)  ;
    ~RandomAccessBulkReader() {
        for (auto& ref : reader_cache) {
            delete ref.second.second;
        }
    }
    std::string get_path() const {
//    	std::cout << p2 << std::endl;
    	return p2;
    }
private:
    std::filesystem::path p;
    std::string p2;
    std::time_t time;
    std::unordered_map<size_t, std::pair<double,mapping*>> reader_cache;

    inline mapping* open_graph(size_t id) {
        auto f = p / std::to_string(id);
        auto str = f.string();
        auto map = str + "_map.tab";
        if (std::filesystem::is_regular_file(f) && std::filesystem::is_regular_file(map)) {
            auto fileTime = std::filesystem::last_write_time(f);
            auto cftime = std::chrono::system_clock::to_time_t(std::chrono::file_clock::to_sys(fileTime));
            auto delta = std::difftime(cftime, time);
            if (!reader_cache.contains(id)) {
                auto& ref = reader_cache[id];
                ref.first = delta;
                ref.second = new mapping(str);
            } else {
                auto& ref = reader_cache[id];
                if (ref.first < delta) {
                    ref.second->close();
                    fileTime = std::filesystem::last_write_time(f);
                    cftime = std::chrono::system_clock::to_time_t(std::chrono::file_clock::to_sys(fileTime));
                    delta = std::difftime(cftime, time);
                    ref.first = delta;
                    delete ref.second;
                    ref.second = nullptr;
                    ref.second = new mapping(str);
                }
            }
            auto& ref = reader_cache[id];
            return ref.second;
        } else
            return nullptr;
    }
};

#endif //GSM2_RANDOMACCESSBULKREADER_H
