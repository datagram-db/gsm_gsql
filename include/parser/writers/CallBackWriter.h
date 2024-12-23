//
// Created by giacomo on 22/12/24.
//

#ifndef GSM2_CALLBACKWRITER_H
#define GSM2_CALLBACKWRITER_H

#include <parser/writer.h>

struct CallBackWriter : public DataWriter {
    std::function<void(const gsm_object&)>& callback;

    CallBackWriter(std::function<void(const gsm_object&)>& callback) : callback{callback} {}
    void writeObject(const gsm_object& object,  const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& propertyname_to_type) override;

    void writeToPath(const std::string& path) override {};
    void initDatabase() override {};
    void close() override {};
    virtual DataReader* asReader(DataWriter*) override { return nullptr; };
};

#endif //GSM2_CALLBACKWRITER_H
