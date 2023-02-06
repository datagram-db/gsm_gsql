/*
 * gsm_db_indices.h
 * This file is part of gsm_gsql
 *
 * Copyright (C) 2018-2023 - Giacomo Bergami
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
// Created by giacomo on 05/02/23.
//

#ifndef GSM_GSQL_GSM_DB_INDICES_H
#define GSM_GSQL_GSM_DB_INDICES_H

#include <yaucl/graphs/NodeLabelBijectionGraph.h>
#include <gsql_gsm/gsm_inmemory_db.h>
#include <streambuf>
#include "yaucl/graphs/algorithms/all_cycles.h"


struct gsm_db_indices {
    // Mapping each type label to an id associated to those
    std::unordered_map<std::string, roaring::Roaring64Map> ell_types;
    // This is the relationship beween sibling elements, thus allowing efficient traversals
    NodeLabelBijectionGraph<size_t, std::string>   siblinghood;
    // Associating each item to its container
    NodeLabelBijectionGraph<size_t, std::string> containedBy, containerOf;
    std::unordered_map<size_t, std::vector<size_t>> containement_order, container_order, traversal_order;

    /**
     * Initialisation of the indexing structures
     * @param db    GSM database
     */
    void init(const gsm_inmemory_db& db) {
        for (const auto& [id, obj] : db.O) {
            auto cDst = containedBy.addUniqueStateOrGetExisting(id);
            auto oDst = containerOf.addUniqueStateOrGetExisting(id);
            for (const auto& type : obj.ell) ell_types[type].add(id);
            for (const auto& [k1, vl1]: obj.phi) {
                for (const auto& id_score_1 : vl1) {
                    auto src = siblinghood.addUniqueStateOrGetExisting(id_score_1.id);
                    auto cSrc = containedBy.addUniqueStateOrGetExisting(id_score_1.id);
                    auto oSrc = containerOf.addUniqueStateOrGetExisting(id_score_1.id);
                    containedBy.addNewEdgeFromId(cSrc, cDst, "phi-1");
                    containerOf.addNewEdgeFromId(oDst, oSrc,  "phi");
                    for (const auto& [k2,vl2] : obj.phi) {
                        if (k1 == k2) continue; // Avoiding loops
                        for (const auto& id_score_2 : vl2) {
                            auto dst = siblinghood.addUniqueStateOrGetExisting(id_score_2.id);
                            siblinghood.addNewEdgeFromId(src, dst, k2);
                        }
                    }
                }
            }
        }
        containement_order = containedBy.g.topological_sort(-1);
        container_order = containerOf.g.topological_sort(containerOf.getId(db.o));
        traversal_order = siblinghood.g.topological_sort(-1);
    }

    /**
     * Sanity check for the data being loaded
     * @return  Returns true only if the validity check is passed
     */
    bool valid_data() const {
        std::unordered_set<size_t> visited, rec_stack;
        for(size_t id = 0, N =  containedBy.maximumNodeId(); id<N; id++)
            if ( (!visited.contains(id)) && isCyclicUtil(id, visited, rec_stack))
                throw std::runtime_error("ERROR: DATA CONTAINS A CONTAINMENT LOOP!");
        return true;
    }
private:
    bool isCyclicUtil(size_t v, std::unordered_set<size_t>& visited, std::unordered_set<size_t>&recStack) const
    {
        if(!visited.contains(v)){
            // Mark the current node as visited and part of recursion stack
            visited.insert(v);
            recStack.insert(v);

            {
                for (const auto& dst : containedBy.outgoingEdgesById2((size_t)v)) {
                        if (((!visited.contains(dst.second)) && isCyclicUtil(dst.second, visited, recStack)) || (recStack.contains(dst.second)))
                            return true;
                }
            }
            recStack.erase(v);
        }
        return false;
    }
};


#endif //GSM_GSQL_GSM_DB_INDICES_H
