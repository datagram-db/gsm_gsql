/*
 * gsm_object.h
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

#ifndef GSM_GSQL_GSM_OBJECT_H
#define GSM_GSQL_GSM_OBJECT_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "yaucl/structures/setoids/basics.h"

#include <database/gsm_object_xi_content.h>


struct gsm_object  {
    // Object's id
    size_t                                                id=-1;
    // Object's labels/types
    std::vector<std::string>                              ell;
    // Object's values
    std::vector<std::string>          xi;
    // Object's uncertainty scores
    std::vector<double>                                   scores;
    // Object's containment
    std::unordered_map<std::string, std::vector<gsm_object_xi_content>> phi;
    std::unordered_map<std::string, std::string> content;

    void updateWith(const gsm_object& old) {
        if ((old.id != id) && (id == -1)) {
            id = old.id;
        }
        if (ell.empty())
            ell = old.ell;
        if (xi.empty())
            xi = old.xi;
        if (scores.empty())
            scores = old.scores;
        for (const auto& [oldKey, oldValue] : old.content) {
            content.emplace(oldKey, oldValue); // Inserting the old content only if something new is not available
        }
        for (const auto& [oldKey, oldValue] : old.phi) {
            remove_duplicates(phi.emplace(oldKey, oldValue).first->second); // Inserting the old content only if something new is not available
        }
    }

    gsm_object(uint_fast32_t id = 0, const std::vector<std::string> &ell = {}, const std::vector<std::string> &xi = {},
               const std::vector<double> &scores = {}, const std::unordered_map<std::string, std::vector<gsm_object_xi_content>> &phi = {});
    gsm_object(const gsm_object&) = default;
    gsm_object(gsm_object&&) = default;
    gsm_object& operator=(const gsm_object&) = default;
    gsm_object& operator=(gsm_object&&) = default;
    bool operator==(const gsm_object &rhs) const;
    bool operator!=(const gsm_object &rhs) const;
};


#endif //GSM_GSQL_GSM_OBJECT_H
