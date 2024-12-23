//
// Created by giacomo on 22/12/24.
//

#include <parser/writers/CallBackWriter.h>

void CallBackWriter::writeObject(const gsm_object& object,  const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& propertyname_to_type) {
    callback(object);
}
