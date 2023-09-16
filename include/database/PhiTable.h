//
// Created by giacomo on 28/05/23.
//

#ifndef GSM2_PHITABLE_H
#define GSM2_PHITABLE_H

#include <vector>
#include <algorithm>

namespace gsm2 {
    namespace tables {
        struct PhiTable {
            struct record {
                size_t l0_id;
                size_t graph_id;
                size_t object_id;
                double w_contained; // Weight
                size_t id_contained;

                record(const record&) = default;
                record(record&&) = default;
                record& operator=(const record&) = default;
                record& operator=(record&&) = default;
                record(size_t l0Id = 0, const std::pair<size_t,size_t>& nodeId = {0,0}, double wContained = 1.0, size_t idContained = 1);

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

            void add(size_t l0Id = 0, const std::pair<size_t,size_t>& nodeId = {0,0}, double wContained = 1.0, size_t idContained = 1);

            void index();
        };
    } // gsm2
} // tables

#endif //GSM2_PHITABLE_H
