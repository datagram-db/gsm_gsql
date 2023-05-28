//
// Created by giacomo on 28/05/23.
//

#include "../include/PhiTable.h"

namespace gsm2 {
    namespace tables {
        PhiTable::record::record(size_t l0Id, size_t nodeId, double wContained, size_t idContained) : l0_id(l0Id), node_id(nodeId),
                                                                                                      w_contained(wContained),
                                                                                                      id_contained(idContained) {}

        bool PhiTable::record::operator<(const PhiTable::record &rhs) const {
            if (l0_id < rhs.l0_id)
                return true;
            if (rhs.l0_id < l0_id)
                return false;
            if (node_id < rhs.node_id)
                return true;
            if (rhs.node_id < node_id)
                return false;
            if (w_contained < rhs.w_contained)
                return true;
            if (rhs.w_contained < w_contained)
                return false;
            return id_contained < rhs.id_contained;
        }

        bool PhiTable::record::operator>(const PhiTable::record &rhs) const {
            return rhs < *this;
        }

        bool PhiTable::record::operator<=(const PhiTable::record &rhs) const {
            return !(rhs < *this);
        }

        bool PhiTable::record::operator>=(const PhiTable::record &rhs) const {
            return !(*this < rhs);
        }

        PhiTable::primary_index::primary_index(size_t l0Id, const PhiTable::record *begin,
                                               const PhiTable::record *anEnd) : l0_id(l0Id), begin(begin), end(anEnd) {}

        void PhiTable::add(size_t l0Id, size_t nodeId, double wContained, size_t idContained) {
            table.emplace_back(l0Id, nodeId, wContained, idContained);
        }

        void PhiTable::index() {
            std::sort(table.begin(), table.end());
            size_t lIdPrev = 0;
            const struct record *begin;
            size_t N = table.size();
            for (size_t i = 0; i<N; i++ ) {
                const auto& ref = table[i];
                if (i == 0) {
                    lIdPrev = ref.l0_id;
                    begin = &ref;
                } else if (ref.l0_id != lIdPrev) {
                    primary_index.emplace_back(lIdPrev, begin, (&ref)-1);
                    begin = &ref;
                    lIdPrev = ref.l0_id;
                }
            }
            primary_index.emplace_back(lIdPrev, begin, (&table[N-1]));
        }
    } // gsm2
} // tables