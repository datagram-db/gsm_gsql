/*
 * utility.h
 * This file is part of gsm_gsql
 *
 * Copyright (C) 2023 - Giacomo Bergami
 *
 * gsm_gsql is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gsm_gsql is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gsm_gsql. If not, see <http://www.gnu.org/licenses/>.
 */


//
// Created by giacomo on 17/09/23.
//

#ifndef GSM2_UTILITY_H
#define GSM2_UTILITY_H

#define IS_OUTGOING     (true)
#define IS_INGOING      (false)

//template <typename D>
//struct SimpleType : public EinsteinOnTheBeach<D> {
//
//
//    SimpleType(D x) : val{x} {
//        EinsteinOnTheBeach<D>::isNested = false;
//    }
//
//    bool operator!=(const SimpleType<D> &rhs) const {
//        return !(rhs == *this);
//    }
//};
//
//template <typename D>
//struct NestedType : public EinsteinOnTheBeach<D> {
//
//
//    NestedType() {
//        EinsteinOnTheBeach<D>::isNested = true;
//    }
//    bool operator==(const NestedType<D> &rhs) const {
//        return static_cast<const EinsteinOnTheBeach<D> &>(*this).isNested == static_cast<const EinsteinOnTheBeach<D> &>(rhs).isNested &&
//                table == rhs.table;
//    }
//    bool operator!=(const NestedType<D> &rhs) const {
//        return !(rhs == *this);
//    }
//};
//
//template <typename D>
//struct EinsteinOnTheBeach {
//    D val;
//    SimpleTable<D> table;
//};
#include "GraphEdgeMatchTable.h"
#include "SimpleTable.h"
using value = NestedValue<abstract_value>;
using nested_table = SimpleTable<value>;

template<typename K, typename V>
static inline V getOrDefault(const std::unordered_map<K, V>& map, const K& key, const V& default_value) {
    auto it = map.find(key);
    if (it != map.end())
        return it->second;
    else
        return default_value;
}

//struct results_to_preserve {
//    std::string grammar_rule_name;
//    std::string entrypoint_node_var_name;
//    std::string exitpoint_node_var_name;
//
//
//};

#include "tabulate/table.hpp"
static inline
tabulate::Table print_table(const nested_table& table) {
    tabulate::Table t;
    tabulate::Table::Row_t r;
    for (const auto& e : table.Schema) {
        r.emplace_back(e);
    }
    t.add_row(r);
    r.clear();
    for (size_t i = 0, N = table.datum.size(); i<N; i++) {
        auto ptr = table.datum.at(i);
        for (size_t j = 0, M = table.Schema.size(); j<M; j++) {
            auto cell = ptr.at(j);
            if (!cell.isNested) {
                if (std::holds_alternative<bool>(cell.val)) {
                    r.emplace_back("NULL");
                } else if (std::holds_alternative<double>(cell.val)) {
                    r.emplace_back(std::to_string(std::get<double>(cell.val)));
                } else if (std::holds_alternative<std::string>(cell.val)) {
                    r.emplace_back(std::get<std::string>(cell.val));
                } else if (std::holds_alternative<size_t>(cell.val)) {
                    r.emplace_back(std::to_string(std::get<size_t>(cell.val)));
                }
            } else {
                r.emplace_back(print_table(cell.table));
            }
        }
        t.add_row(r);
        r.clear();
    }
    return t;
}

#include <iomanip>

static inline
void serialised_nested_table(std::ostream& oss, const std::string& relation_name, const nested_table& table, const std::unordered_set<std::string>& edges, size_t tab = 1) {
    std::string tabs(tab, '\t');
    oss << relation_name << "(";
    for (size_t i = 0, N = table.Schema.size(); i<N; i++) {
        oss << std::quoted(table.Schema.at(i));
        if (i != (N-1))
            oss << ", ";
    }
    oss << ") {" << std::endl << tabs;
    for (size_t i = 0, N = table.datum.size(); i<N; i++) {
        oss << "[";
        auto ptr = table.datum.at(i);
        for (size_t j = 0, M = table.Schema.size(); j<M; j++) {
            auto cell = ptr.at(j);
            if (!cell.isNested) {
                if (edges.contains(table.Schema.at(j)))
                    oss << "\"↑";
                if (std::holds_alternative<bool>(cell.val)) {
                    oss << "NULL";
                } else if (std::holds_alternative<double>(cell.val)) {
                    oss << std::to_string(std::get<double>(cell.val));
                } else if (std::holds_alternative<std::string>(cell.val)) {
                    oss << std::quoted(std::get<std::string>(cell.val));
                } else if (std::holds_alternative<size_t>(cell.val)) {
                    oss << std::to_string(std::get<size_t>(cell.val));
                }
                if (edges.contains(table.Schema.at(j)))
                    oss << "\"";
            } else {
                oss << "@";
                serialised_nested_table(oss, table.Schema.at(j), cell.table, edges, tab+1);
            }
            if (j != (M-1))
                oss << ", ";
        }
        oss << "]" << std::endl;
        if (i < (N-1)) oss << std::string(tab, '\t');;
    }
    oss << "}";
}

#define PRINT_TABLE(t, os) os << t << std::endl

static inline
void fillFrom(nested_table& table, const RawThreewayTable& orig) {
    table.Schema ={orig.graph, orig.src, orig.edgeLabel, orig.edge, orig.dst/*, orig.score*/};
    for (const auto& ROW : orig.table) {
        auto& tmp = table.datum.emplace_back();
        tmp.emplace_back(std::get<0>(ROW));
        tmp.emplace_back(std::get<1>(ROW));
        tmp.emplace_back(std::get<2>(ROW));
        tmp.emplace_back(std::get<3>(ROW));
        tmp.emplace_back(std::get<4>(ROW));
    }
}

static inline
void fillFrom(nested_table& table, const RawTwowayTable& orig) {
    table.Schema ={orig.graph, orig.src, orig.dst/*, orig.score*/};
    for (const auto& ROW : orig.table) {
        auto& tmp = table.datum.emplace_back();
        tmp.emplace_back(std::get<0>(ROW));
        tmp.emplace_back(std::get<1>(ROW));
        tmp.emplace_back(std::get<2>(ROW));
//        tmp.emplace_back(std::get<3>(ROW));
    }
}


struct IndexedSchemaCoordinates {
    const nested_table* table;

    IndexedSchemaCoordinates(const nested_table* ptr) : table{ptr}, isIndexed{false} {}
    DEFAULT_COPY_ASSGN(IndexedSchemaCoordinates);

     void index() {
        if (isIndexed || (!table) || (table->datum.empty())) return;
        isNested.resize(table->Schema.size(), false);
        const auto& disSchema = table->Schema;
        countNested = 0;
        for (size_t i = 0, N = disSchema.size(); i<N; i++) {
            const auto& mother = disSchema.at(i);
            const auto& cellAt0 = table->datum.at(0).at(i);
            colToIdx.emplace(mother, i);
            if (cellAt0.isNested || (!cellAt0.table.Schema.empty())) {
                isNested[i] = true;
                countNested++;
                const auto& nestSchema = cellAt0.table.Schema;
                for (size_t j = 0, M = nestSchema.size(); j<M; j++) {
                    const auto& pepper = nestSchema.at(j);
                    auto it = nestedToMother.emplace(pepper, mother);
                    if (!it.second)
                        throw std::runtime_error("ERROR: field " + it.first->first +" was already associated to "+it.first->second);
                    nestedToOffsetInMother.emplace(pepper, j);
                    sitterToPeppers[mother].emplace_back(pepper);
                }
            }
        }
        isIndexed= true;
    }



     bool isNestedIdx(size_t idx) const {
        return isNested.at(idx);
    }

     bool isNestedCol(const std::string& colName) const {
        auto it = colToIdx.find(colName);
        return (it != colToIdx.end()) && (isNestedIdx(it->second));
    }

    const std::vector<std::string> getNestedSchemaAssociatedToCol(const std::string& key) const {
         auto it = sitterToPeppers.find(key);
         if (it == sitterToPeppers.end())
             return empty_vector;
         else return it->second;
     }

     ssize_t mainHeaderKeyOffset(const std::string& colName) const {
        auto it = colToIdx.find(colName);
        return it == colToIdx.end() ? -1 : it->second;
    }

     bool hasMainHeaderKey(const std::string& colName) const {
        return colToIdx.find(colName) == colToIdx.end();
    }

     bool hasNestedKey(const std::string& colName) const {
        return nestedToOffsetInMother.find(colName) == nestedToOffsetInMother.end();
    }

     ssize_t nestedKeyOffset(const std::string& colName) const {
        auto it = nestedToOffsetInMother.find(colName);
        return it == nestedToOffsetInMother.end() ? -1 : it->second;
    }

     bool hasKeyAnywhere(const std::string& colName) const {
        return (colToIdx.find(colName) != colToIdx.end()) ||
                ( nestedToOffsetInMother.find(colName) != nestedToOffsetInMother.end());
    }

    inline  void fillNotNested(std::vector<std::string>& v) const {
        v.reserve(isNested.size());
        for (size_t i = 0; i<isNested.size(); i++) {
            if (!isNested.at(i))
                v.emplace_back(table->Schema.at(i));
        }
    }

    inline void fillNested(std::vector<std::string>& v) const {
        v.reserve(isNested.size());
        for (size_t i = 0; i<isNested.size(); i++) {
            if (isNested.at(i))
                v.emplace_back(table->Schema.at(i));
        }
    }

    inline void fillBothNested(std::vector<std::string>& y, std::vector<std::string>& n) const {
        y.reserve(countNested);
        n.reserve(table->Schema.size()-countNested);
        for (size_t i = 0; i<isNested.size(); i++) {
            if (!isNested.at(i)) {
                n.emplace_back(table->Schema.at(i));
            } else {
                auto it = sitterToPeppers.find(table->Schema.at(i));
                DEBUG_ASSERT(it !=sitterToPeppers.end() );
                y.insert(y.end(), it->second.begin(), it->second.end());
            }
        }
    }

    inline void getAllParents(const std::string& pepper, std::unordered_set<std::string>& parents) const {
        auto it = nestedToMother.find(pepper);
        if (it != nestedToMother.end()) {
            parents.insert(it->second);
        }
    }

    inline bool hasNestedColumns() const {
        return !nestedToOffsetInMother.empty();
    }

    inline std::vector<std::string> getNestedSchemaFromOffset(const std::string& i) const {
        auto it = sitterToPeppers.find(i);
        if (it != sitterToPeppers.end())
            return it->second;
        return {};
    }

private:
    std::vector<std::string> empty_vector;
    bool isIndexed;
    size_t countNested;
    std::vector<bool> isNested;
    std::unordered_map<std::string, size_t> colToIdx;
    std::unordered_map<std::string, size_t> nestedToOffsetInMother;
    std::unordered_map<std::string, std::string> nestedToMother;
    std::unordered_map<std::string, std::vector<std::string>> sitterToPeppers;
};




#endif //GSM2_UTILITY_H
