/*
 * delta_updates.cpp
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

#include "database/delta_updates.h"

void delta_updates::clear_insertions() {
    newly_inserted_vertices.clear();
    newIterationInsertedObjects.clear();
}

const std::vector<size_t> &delta_updates::getNewlyInsertedVertices(const std::string &x) const {
    auto it = newly_inserted_vertices.find(x);
    if (it == newly_inserted_vertices.end())
        return no_inserted_node;
    else
        return it->second;
}

delta_updates::delta_updates(size_t max_id) {
    delta_plus_db.max_id = max_id;
}

void delta_updates::set_removed(size_t default_val) {
    size_t toRemove = getOrDefault(replacement_map, default_val, default_val);
    if (!newIterationInsertedObjects.contains(toRemove))
        removed_objects.insert(toRemove);
    else
        removed_objects.insert(default_val);
}

void delta_updates::replaceWith(size_t orig, size_t dest) {
    DEBUG_ASSERT(!replacement_map.contains(orig));
    replacement_map[orig] = dest;
}

void delta_updates::associateNewToVar(const std::string &name, size_t id) {
    newly_inserted_vertices[name].emplace_back(id);
    newIterationInsertedObjects.add(id);
}

gsm_object &delta_updates::getNewObject() {
    delta_plus_db.max_id++;
    auto& obj = delta_plus_db.O[delta_plus_db.max_id];
    obj.id = delta_plus_db.max_id;
    return obj;
}

bool delta_updates::hasXBeenRemoved(size_t obj) const {
    return removed_objects.contains(obj);
}
