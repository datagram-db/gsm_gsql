//
// Created by giacomo on 23/12/24.
//

#ifndef GSM2_RANDOMACCESSREADER_H
#define GSM2_RANDOMACCESSREADER_H

#include <optional>
#include <database/gsm_object.h>

struct RandomAccessReader {
    virtual size_t count_databases() {
        return 0;
    }
    virtual ssize_t database_size(size_t graph_id) {
        return -1;
    }
    virtual std::optional<gsm_object> retrieve(size_t graph_id, size_t id)  = 0;
};

#endif //GSM2_RANDOMACCESSREADER_H
