//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_COMMONS_H
#define GSM2_COMMONS_H

enum DataFormat {
    // TODO: SecondaryMemoryDBm (folder of databases)
    NoDataFormat,
    PrimaryMemoryDB,
    Schema, // TODO: only loading, not serialization (for the moment)
    GSM,
    BulkFolder
};

#include <string>

#include <database/gsm_object.h>
#include <stack>
#include "writer.h"

struct DataReader;

struct DataFormatHandler {



    bool data_to_format(const std::string& inPath,
                        DataFormat input,
                        const std::string& outPath,
                        DataFormat output);
    bool write_from_reader(const std::string& outPath,
                           DataFormat output);

    ~DataFormatHandler() {
        while (!memory.empty()) {
            auto& ptr = memory.top();
            delete ptr.first;
            delete ptr.second;
            memory.pop();
        }
    }
private:

    std::stack<std::pair<DataReader*,DataWriter*>> memory;
};

#endif //GSM2_COMMONS_H
