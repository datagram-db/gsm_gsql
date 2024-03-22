//
// Created by giacomo on 16/01/24.
//

#ifndef GSM2_SCHEMAINDEXER_H
#define GSM2_SCHEMAINDEXER_H

#include <unordered_map>
#include <set>
#include <string>
#include <vector>

#include "utility.h"
#include "scriptv2/java_types.h"
#include "scriptv2/ScriptAST.h"

/**
 * This class indices the schema for the programming language evaluation (script3)
 * For the schema indexing for the join operations, please refer ot
 */
struct SchemaIndexer {
    std::unordered_map<std::string, size_t>     field_to_schema;
    std::unordered_map<std::string, std::unordered_map<std::string, size_t>> nested_schema;
    std::unordered_map<std::string, std::unordered_set<std::string>> nested_strings;
    std::set<size_t>                           isNull, cow;
    std::vector<DPtr<script::structures::ScriptAST>> values;
    std::set<size_t> strings;
    const std::vector<value>* row;
    const std::vector<std::string>* schema;

    SchemaIndexer(size_t n) :  values(n, std::make_shared<script::structures::ScriptAST>()){
        fullyIndexed = false;
        row = nullptr;
    }
    void setUp(const std::vector<std::string>* schema)   {
        this->schema = {schema};
        for (size_t i = 0, N = schema->size(); i<N; i++) {
            field_to_schema.emplace(schema->at(i), i);
        }
    }

    void initialize(const  std::vector<value>* nestedRow) {
        if (row == nestedRow) return;
        row = nestedRow;
        isNull.clear();
        cow.clear();
        nested_schema.clear();
        for (size_t i = 0, N = std::min(nestedRow->size(), field_to_schema.size()); i<N; i++) {
            const auto& cell = nestedRow->at(i);
            if (!cell.isNested) {
                if (std::holds_alternative<bool>(cell.val))
                    isNull.insert(i);
                else if (!std::holds_alternative<size_t>(cell.val)) {
                    strings.emplace(i);
                }
            } else {
                if (!fullyIndexed) {
                    for (size_t j = 0, M = cell.table.Schema.size(); j<M; j++) {
                        nested_schema[schema->at(i)].emplace(cell.table.Schema.at(j), j);
                        if (cell.table.Schema.at(j).ends_with("_label"))
                            nested_strings[schema->at(i)].insert(cell.table.Schema.at(j));
                    }
                }
                // TODO: efficient nested values on demand (COW)
            }
        }
        fullyIndexed = true;
    }

    bool hasKey(const std::string& key) const {
        auto it = key.find('.');
        if (it == std::string::npos) {
            return field_to_schema.contains(key);
        } else {
            auto nested = key.substr(0, it);
            auto var = key.substr(it+1);
            auto it2 = nested_schema.find(nested);
            if (it2 == nested_schema.end())
                return false;
            else
                return it2->second.find(var) != it2->second.end();
        }
    }

    size_t getNativeInt(const std::string& key) const {
        auto it = field_to_schema.find(key);
        if ((!row) || it == field_to_schema.end() || (isNull.contains(it->second)))
            return -1;
        else
            return std::get<size_t>(row->at(it->second).val);
    }

    DPtr<script::structures::ScriptAST> get(const std::string& key);

private:
    bool fullyIndexed;
};

struct TemplateIndexer {
    std::unordered_map<size_t, SchemaIndexer> map;
    size_t current_template;

    bool contains(const std::string& key) const {
        auto it = map.find(current_template);
        return it != map.end() && (it->second.hasKey(key));
    }

    DPtr<script::structures::ScriptAST> get(const std::string&key) {
        auto it = map.find(current_template);
        if (it == map.end() )
            return script::structures::ScriptAST::null_();
        return it->second.get(key);
    }

    size_t getNativeInt(const std::string&key) const {
        auto it = map.find(current_template);
        if (it == map.end() )
            return -1;
        return it->second.getNativeInt(key);
    }

    SchemaIndexer& attemptInitialise(size_t i, const std::vector<std::string> *vector) {
        if (!map.contains(i)) {
            auto& ref = map.emplace(i, vector->size()).first->second;
            ref.setUp(vector);
            return ref;
        } else {
            return map.at(i);
        }
    }
};


#endif //GSM2_SCHEMAINDEXER_H
