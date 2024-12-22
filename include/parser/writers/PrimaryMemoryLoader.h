//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_SECONDARYMEMORYLOADER_H
#define GSM2_SECONDARYMEMORYLOADER_H

#include <parser/writer.h>
#include <fstream>
#include <database/LinearGSM.h>

struct PrimaryMemoryLoader : public DataWriter {

    void writeToPath(const std::string& path) override;
    void initDatabase() override;
    void writeObject(const gsm_object& object, const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& propertyname_to_type) override;
    void close() override;
    DataReader* asReader(DataWriter*) override;

    bool start=true;
    gsm2::tables::LinearGSM forloading;
    size_t noLabel;
    std::pair<size_t,size_t> graphId_eventId{0,0};
};

#endif //GSM2_PRIMARYMEMORYLOADER_H
