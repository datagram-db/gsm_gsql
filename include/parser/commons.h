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
struct DataReader;

struct DataFormatHandler {

    DataReader* current_reader;
    DataFormatHandler() : current_reader{nullptr} {}


};

#endif //GSM2_COMMONS_H
