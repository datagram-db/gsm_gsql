//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_ENTITY_H
#define GSM2_ENTITY_H

#include <string>
#include <vector>
#include <unordered_map>
#include <optional>
#include <unordered_set>
#include <parser/schema/Field.h>

enum FileType {
    JSON,
    LJSON,
    CSV,
    XML
};

struct Entity {
    std::string name;
    std::string namespace_;
    std::vector<std::string> fields_order;
    std::unordered_map<std::string, Field> fields;
    std::unordered_map<std::string, std::string> mapped_field_resolution;
    std::optional<std::string> id;
    std::unordered_set<std::string> attributes;
    std::string loading_filename;
    FileType type;
    bool has_csv_header;
    std::string sep;

    const std::optional<const Field*> find(const std::string& field_name_to_resolve) const {
        const auto& it1 = mapped_field_resolution.find(field_name_to_resolve);
        if (it1 != mapped_field_resolution.end()) {
            auto it2 =  fields.find(it1->second);
            if (it2 != fields.end())
                return {&it2->second};
        } else {
            auto it2 = fields.find(field_name_to_resolve);
            if (it2 != fields.end())
                return {&it2->second};
        }
        return {};
    }

    Entity() = default;
    Entity(const Entity&) = default;
    Entity(Entity&&) = default;
    Entity& operator=(const Entity&) = default;
    Entity& operator=(Entity&&) = default;
};

#endif //GSM2_ENTITY_H
