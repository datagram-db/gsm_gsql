//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_FIELD_H
#define GSM2_FIELD_H

#include <string>
#include <vector>

enum NativeTypes {
    String,
    UInt,
    Int,
    Double,
    Skip
};

enum FieldCases {
    native_field,
    external_reference,
    local_nested_entity_list,
    local_nested_entity,
    multi_nested_entity
};

struct Entity;

struct Field {
    bool is_id;
    bool xml_tag{false};
    bool xml_property{false};
    bool collective{false};
    bool multi{false};
    bool score{false};
    std::string namespace_;
    std::string entity;
    std::string field_name;
    std::string map_to_actual_field_or_attribute;
    size_t declaration_offset;

    FieldCases type;
    NativeTypes native_field_type;
    std::vector<Entity> nested_decl;

    std::string ext_namespace;
    std::string ext_entity;
    std::string ext_field;

    Field() = default;
    Field(const Field&) = default;
    Field(Field&&) = default;
    Field& operator=(const Field&) = default;
    Field& operator=(Field&&) = default;
};

#endif //GSM2_FIELD_H
