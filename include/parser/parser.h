//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_PARSER_H
#define GSM2_PARSER_H

#include <parser/commons.h>
#include <database/AttributeTable.h>

struct DataWriter;

struct DataReader {
    std::unordered_map<std::string, gsm2::tables::AttributeTableType> propertyname_to_type;
    DataWriter* writer;
    virtual ~DataReader() {}
    virtual void setWriter(DataWriter* data) {
        this->writer = data ? data : nullptr;
    };
    virtual bool readFromPath(const std::string& path) = 0;

};

#endif //GSM2_PARSER_H
