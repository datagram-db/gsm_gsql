//
// Created by giacomo on 16/01/24.
//

#include "database/SchemaIndexer.h"

DPtr<script::structures::ScriptAST> SchemaIndexer::get(const std::string& key) {
    auto it = field_to_schema.find(key);
    if ((!row) || it == field_to_schema.end() || (isNull.contains(it->second)))
        return script::structures::ScriptAST::null_();
    else {
        if (!cow.contains(it->second)) {
            auto& ref = values[it->second];
            if (strings.contains(it->second)) {
                ref->type = script::structures::t::String ;
                ref->string = std::get<std::string>(row->at(it->second).val) ;
            } else {
                ref->type = script::structures::t::Integer ;
                ref->integer = std::get<size_t>(row->at(it->second).val) ;
            }
            cow.insert(it->second);
        }
        return values.at(it->second);
    }
}