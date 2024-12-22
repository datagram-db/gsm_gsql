//
// Created by giacomo on 07/12/24.
//

#ifndef GSM2_NDP_BATCH_H
#define GSM2_NDP_BATCH_H

#include <database/gsm_object.h>
#include "schema.propo.h"

size_t serialize(int fd, const gsm_object& object);
void readEntry(int fd,  gsm_object& result);

extern "C" {
#include <unistd.h>
#include <fcntl.h>
}

#include <unordered_map>
#include <filesystem>
#include "lrucache.hpp"

#include <mutex>
#include <fstream>

struct mapping {
    mapping(const std::string& filename, size_t cache_size = 1024);
    std::pair<bool,size_t> serialize(const gsm_object& object);

    inline ssize_t getGreatestObjectId() const {
        return greatestObjectId;
    }

    gsm_object retrieve(size_t id);
    void close();
    virtual ~mapping() {
        close();
    }

private:
    std::ofstream mapping_file;
    std::mutex g_pages_mutex;
    bool moved_for_read;
    gsm_object empty_object;
    cache::lru_cache<size_t, gsm_object> cache;
    std::unordered_map<size_t, size_t> metObjectIds;
    int fd;
//    size_t file_size_count;
    std::string filename;
    ssize_t greatestObjectId = -1;
};


#endif //GSM2_NDP_BATCH_H
