/*
 * PhiTable.h
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
// Created by giacomo on 28/05/23.
//

#ifndef GSM2_PHITABLE_H
#define GSM2_PHITABLE_H

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <yaucl/hashing/pair_hash.h>

namespace gsm2 {
    namespace tables {
        struct PhiTable {
            struct record {
                size_t l0_id;
                size_t graph_id;
                size_t object_id;
                double w_contained; // Weight
                size_t id_contained;
                size_t instance_id;
                size_t record_id;

                record(const record&) = default;
                record(record&&) = default;
                record& operator=(const record&) = default;
                record& operator=(record&&) = default;
                record(size_t l0Id = 0, const std::pair<size_t,size_t>& nodeId = {0,0}, double wContained = 1.0, size_t idContained = 1, size_t instance_id = 0);

                bool operator<(const record &rhs) const;
                bool operator>(const record &rhs) const;
                bool operator<=(const record &rhs) const;
                bool operator>=(const record &rhs) const;
            };

//            struct primary_index {
//                size_t l0_id;
//                const struct record* begin;
//                const struct record* end;
//
//                primary_index(const primary_index&) = default;
//                primary_index(primary_index&&) = default;
//                primary_index& operator=(const primary_index&) = default;
//                primary_index& operator=(primary_index&&) = default;
//                primary_index(size_t l0Id = 0, const record *begin = nullptr, const record *anEnd = nullptr);
//            };

            std::vector<struct record> table;
            std::unordered_map<size_t, std::pair<const struct record*,const struct record*>> primary_index;
            std::unordered_map<size_t, std::unordered_map<size_t, std::vector<const struct record*>>> secondary_index;

            void add(size_t l0Id = 0, const std::pair<size_t,size_t>& nodeId = {0,0}, double wContained = 1.0, size_t idContained = 1, size_t instance_id = 0);

            size_t index(size_t first_record_id);
        };
    } // gsm2
} // tables

#endif //GSM2_PHITABLE_H
