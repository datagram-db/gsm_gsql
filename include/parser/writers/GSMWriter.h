//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_GSMWRITER_H
#define GSM2_GSMWRITER_H

#include <fstream>
#include <fstream>
#include <parser/writer.h>

struct GSMWriter : public DataWriter {

    void writeToPath(const std::string& path) override;
    void initDatabase() override;
    void writeObject(const gsm_object& object,  const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& propertyname_to_type) override;
    void close() override;
    DataReader* asReader(DataWriter*) override;

    std::ofstream b;
    std::string path;
    bool start=true;
};

#endif //GSM2_GSMWRITER_H
