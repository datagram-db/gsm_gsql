//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_WRITER_H
#define GSM2_WRITER_H

#include <string>
#include <database/gsm_object.h>
#include <database/AttributeTable.h>
struct DataReader;

struct DataWriter {

    virtual ~DataWriter() {}
    virtual void writeToPath(const std::string& path) = 0;
    virtual void initDatabase() = 0;
    virtual void writeObject(const gsm_object& object, const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& propertyname_to_type) = 0;
    virtual void close() = 0;
    virtual DataReader* asReader() = 0;

};


#endif //GSM2_WRITER_H
