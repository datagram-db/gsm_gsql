//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_GSMWRITER_H
#define GSM2_GSMWRITER_H

#include <parser/writer.h>
#include <fstream>

struct GSMWriter : public DataWriter {

    void writeToPath(const std::string& path) override;
    void initDatabase() override;
    void writeObject(const gsm_object& object,  const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& propertyname_to_type) override;
    void close() override;

    std::ofstream b;
    bool start=true;
};

#endif //GSM2_GSMWRITER_H
