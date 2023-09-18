/*
 * gsm_indices.h
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


#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include "yaucl/graphs/NodeLabelBijectionGraph.h"
#include "gsm_inmemory_db.h"

struct gsm_db_indices {
    // Mapping each type label to an id associated to those
    std::unordered_map<std::string, std::unordered_set<size_t>> ell_types;
    // This is the relationship beween sibling elements, thus allowing efficient traversals
    NodeLabelBijectionGraph<size_t, std::string>   siblinghood;
    // Associating each item to its container
    NodeLabelBijectionGraph<size_t, std::string> containedBy, containerOf;
    std::unordered_map<size_t, std::vector<size_t>> containement_order, container_order, traversal_order;


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
