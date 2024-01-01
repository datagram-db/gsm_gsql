/*
 * GraphEdgeMatchTable.h
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
// Created by giacomo on 15/09/23.
//

#ifndef GSM2_GRAPHEDGEMATCHTABLE_H
#define GSM2_GRAPHEDGEMATCHTABLE_H

#include <yaucl/structures/RelationalTables.h>
#include <variant>

using abstract_value = std::variant<double,size_t,std::string,bool>;

/**
 * Raw matching table when we also have the edge variable information
 */
struct RawThreewayTable {
    std::string graph{"graph"};
    std::string src;
    std::string edgeLabel;
    std::string edge;
    std::string dst;
//    std::string score{"score"};

    using record = std::tuple<size_t,size_t,std::string,size_t,size_t> ;
    std::vector<record> table;
};

/**
 * Raw matching table when we do not have the edge variable information
 */
struct RawTwowayTable {
    std::string graph{"graph"};
    std::string src;
    std::string dst;
//    std::string score{"score"};

    using record = std::array<size_t, 3/*, double*/> ;
    std::vector<record> table;
};

#if 0
struct MatchTable;

struct MatchRow : public AbstractEquiJoinRow<std::string, abstract_value> {
    MatchTable* parent;
    size_t rowId, nCell;
    MatchRow(MatchTable *parent = nullptr, size_t rowId = -1, size_t ncells = 0) : parent(parent), rowId(rowId), nCell(ncells) {}

    inline size_t nCells() const override { return nCell; }
    const abstract_value &getCell(size_t i) const override;
};

/**
 * Representing a table by row
 * @tparam S    Schema type
 * @tparam D    Data type
 */
struct MatchTable : public AbstractEquiJoinTable<std::string,abstract_value> {
    std::vector<std::string> schema;
    std::vector<std::vector<abstract_value>> data;
    MatchRow row;

    ~MatchTable() override = default;
    MatchTable() {
        row.parent = this;
    }

    /**
 * Copying the abstract table into a concrete one
 * @param table:     the original table
 */
    inline void fromTable(AbstractEquiJoinTable<std::string,abstract_value>* table) {
        schema.clear();
        data.clear();
        row.nCell = 0;
        if (!table) return;
        schema = table->getSchema();
        row.nCell = schema.size();
        std::vector<abstract_value> tmp;
        for (size_t i = 0, N = table->size(); i<N; i++) {
            tmp.clear();
            tmp.reserve(row.nCell);
            const auto& ROW = table->getRow(i);
            for (size_t j = 0; j<row.nCell; j++) {
                tmp.emplace_back(ROW->getCell(j));
            }
            data.emplace_back(tmp);
        }
    }
    inline void fromTable(const RawThreewayTable& table) {
        schema.clear();
        data.clear();
        row.nCell = 0;
        schema = {table.graph, table.src, table.edge, table.dst, table.score};
        row.nCell = schema.size();
        std::vector<abstract_value> tmp;
        for (size_t i = 0, N = table.table.size(); i<N; i++) {
            tmp.clear();
            tmp.reserve(row.nCell);
            auto& ROW = table.table.at(i);
            tmp.emplace_back(std::get<0>(ROW));
            tmp.emplace_back(std::get<1>(ROW));
            tmp.emplace_back(std::get<2>(ROW));
            tmp.emplace_back(std::get<3>(ROW));
            tmp.emplace_back(std::get<4>(ROW));
            data.emplace_back(tmp);
        }
    }
    inline void fromTable(const RawTwowayTable& table) {
        schema.clear();
        data.clear();
        row.nCell = 0;
        schema = {table.graph, table.src, table.dst, table.score};
        row.nCell = schema.size();
        std::vector<abstract_value> tmp;
        for (size_t i = 0, N = table.table.size(); i<N; i++) {
            tmp.clear();
            tmp.reserve(row.nCell);
            auto& ROW = table.table.at(i);
            tmp.emplace_back(std::get<0>(ROW));
            tmp.emplace_back(std::get<1>(ROW));
            tmp.emplace_back(std::get<2>(ROW));
            tmp.emplace_back(std::get<3>(ROW));
            data.emplace_back(tmp);
        }
    }

    MatchTable(AbstractEquiJoinTable<std::string,abstract_value>* table) {
        fromTable(table);
    }
    MatchTable& operator=(AbstractEquiJoinTable<std::string,abstract_value>* table) {
        fromTable(table);
        return *this;
    }

    inline size_t size() const override { return data.size(); }
    inline const std::vector<std::string>& getSchema() const override { return schema; }
    inline AbstractEquiJoinRow<std::string, abstract_value> *getRow(size_t i) override {
        row.rowId = i;
        return &row;
    }

    inline std::vector<abstract_value> asConcreteRow(size_t i) override {
        return data.at(i);
    }

    inline void setDisposability(bool dispose) override { this->dispose = dispose; }
    inline bool isDisposable() const override { return dispose; }

private:
    bool dispose;
    int concrete;
};
#endif

#endif //GSM2_GRAPHEDGEMATCHTABLE_H
