//
// Created by giacomo on 23/12/24.
//

#ifndef GSM2_RANDOMACCESSGSMREADER_H
#define GSM2_RANDOMACCESSGSMREADER_H

#include <string>
#include <parser/writers/PrimaryMemoryLoader.h>
#include <parser/RandomAccessReader.h>
#include <filesystem>

struct RandomAccessGSMReader : public RandomAccessReader {

    size_t count_databases() override;
    ssize_t database_size(size_t graph_id) override;
    std::optional <gsm_object> retrieve(size_t graph_id, size_t id) override;
    DataWriter* getWriter() {
        return &db;
    }
private:
    PrimaryMemoryLoader db;
};

#endif //GSM2_RANDOMACCESSGSMREADER_H
