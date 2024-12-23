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
//#include "RandomAccessReader.h"

#include <parser/ra_readers/RandomAccessBulkReader.h>
#include <parser/ra_readers/RandomAccessGSMReader.h>

struct DataReader;

struct DataFormatHandler {

    /**
     * Converts different GSM representations
     * @param inPath    Input path
     * @param input     Input format
     * @param outPath       Output path
     * @param output    Output format
     * @return  True if there were no issues, false otherwise
     */
    bool data_converter(const std::string& inPath,
                        DataFormat input,
                        const std::string& outPath,
                        DataFormat output);

    /**
     * Provides a data reader from a bulk insertion directory containing multiple databases
     * @param path Directory path
     * @return      A pointer to the bulk insertion reader on disk
     */
    std::shared_ptr<RandomAccessBulkReader> read_from_bulk_data(const std::string& path);

    /**
     * Provides a data reader from a primary-memory loaded instance of the directory
     * @param inPath path
     * @param input  conversion format for loading the path
     * @return       The pointer to the primary-loaded database
     */
    std::shared_ptr<RandomAccessGSMReader> load_to_primary_memory(const std::string& inPath,
                                                               DataFormat input);

    /**
     * Reads the input data using a callback function
     * @param inPath    Input path
     * @param input     Input format
     * @param callback  Callback function returning the objects being visited from the input file
     * @return  True if there were no issues, false otherwise
     */
    bool callback_reader(const std::string& inPath,
                         DataFormat input,
                         std::function<void(const gsm_object&)> callback);

    // Writer Operations

    /**
     * Starts to write data into a specific format
     * @param outPath       Destination path
     * @param output        Destination format
     * @return  True if all was OK, false otherwise
     */
    bool open_data_writer(const std::string& outPath,
                          DataFormat output);

    /**
     * Starts handing a new database
     */
    inline bool newDB() {
        if (writer) {
            writer->initDatabase();
            return true;
        } else
            return false;
    }
    /**
     * Writes a new object within the current database
     * @param object    Object to write
     * @return
     */
    inline bool writeObject(const gsm_object& object) {
        if (writer) {
            writer->writeObject(object, {});
            return true;
        } else
            return false;
    }

    /**
     * Closes the writing operations
     * @return
     */
    inline bool close_writer() {
        if (writer) {
            writer = nullptr;
            return true;
        } else
            return false;
    }

private:
    DataWriter* writer{nullptr};
};

#endif //GSM2_COMMONS_H
