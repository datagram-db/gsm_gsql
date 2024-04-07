//
// Created by giacomo on 16/01/24.
//

#include "database/SchemaIndexer.h"

DPtr<script::structures::ScriptAST> SchemaIndexer::get(const std::string& key) {
    if (key == "*.V")
        std::cout << "CC" << std::endl;
    if (!row)
        return script::structures::ScriptAST::null_();
    auto itChar = key.find('.');
    if (itChar == std::string::npos) {
        auto it = field_to_schema.find(key);
        if (it == field_to_schema.end() || (isNull.contains(it->second)))
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
    } else {
        auto nested = key.substr(0, itChar);
        auto var = key.substr(itChar+1);
        auto it2 = nested_schema.find(nested);
        if ((it2 == nested_schema.end()) || it2->second.find(var) == it2->second.end())
            return script::structures::ScriptAST::null_();
        else {
            std::vector<DPtr<script::structures::ScriptAST>> nested_values;
            const auto nestedColCellIdx = it2->second.find(var)->second;
            if (var == "NN")
                std::cout << "NN" << std::endl;
            auto it = field_to_schema.find(nested);
            DEBUG_ASSERT(it != field_to_schema.end());
            for (const auto& RW : row->at(it->second).table.datum) {
                const auto& cell = RW.at(nestedColCellIdx);
                if (std::holds_alternative<size_t>(cell.val)) {
                    nested_values.emplace_back(script::structures::ScriptAST::integer_(std::get<size_t>(cell.val)));
                } else if (std::holds_alternative<std::string>(cell.val)) {
                    nested_values.emplace_back(script::structures::ScriptAST::string_(std::get<std::string>(cell.val)));
                } else {
                    if (nested_strings[nested].contains(var))
                        nested_values.emplace_back(script::structures::ScriptAST::string_(""));
                    else
                        nested_values.emplace_back(script::structures::ScriptAST::integer_(-1));
                }
            }
            return script::structures::ScriptAST::array_(std::move(nested_values));
        }
    }


}