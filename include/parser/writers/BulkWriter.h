//
// Created by giacomo on 22/12/24.
//

#ifndef GSM2_BULKWRITER_H
#define GSM2_BULKWRITER_H

#include <parser/writer.h>
#include <database/ndp/ndp_batch.h>
#include <filesystem>

struct BulkWriter : public DataWriter {

    void writeToPath(const std::string& path) override;
    void initDatabase() override;
    void writeObject(const gsm_object& object,  const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& propertyname_to_type) override;
    void close() override;

    std::filesystem::path path;
    size_t dbCounter;
    mapping* writer{nullptr};
};


#endif //GSM2_BULKWRITER_H
