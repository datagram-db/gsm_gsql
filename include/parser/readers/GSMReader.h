//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_GSMREADER_H
#define GSM2_GSMREADER_H

#include <parser/parser.h>

struct GSMReader : public DataReader {
    virtual ~GSMReader() {}
    virtual bool readFromPath(const std::string& path) override;

};

#endif //GSM2_GSMREADER_H
