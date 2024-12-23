//
// Created by giacomo on 22/12/24.
//

#ifndef GSM2_PRIMARYMEMORYREADER_H
#define GSM2_PRIMARYMEMORYREADER_H

#include <parser/parser.h>
#include <database/LinearGSM.h>

struct PrimaryMemoryReader : public DataReader {
    gsm2::tables::LinearGSM& memory;
    PrimaryMemoryReader(gsm2::tables::LinearGSM& memory) : memory{memory} {}
    virtual ~PrimaryMemoryReader() {}
    bool readFromPath(const std::string& path) override ;
};

#endif //GSM2_PRIMARYMEMORYREADER_H
