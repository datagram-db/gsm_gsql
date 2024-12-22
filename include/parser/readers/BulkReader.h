//
// Created by giacomo on 22/12/24.
//

#ifndef GSM2_BULKREADER_H
#define GSM2_BULKREADER_H

#include <parser/parser.h>

struct BulkReader : public DataReader {
    virtual ~BulkReader() {}
    virtual bool readFromPath(const std::string& path) override;

};

#endif //GSM2_BULKREADER_H
