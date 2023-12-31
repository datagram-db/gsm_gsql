/*
 * gsm_object.cpp
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

#include <database/gsm_object.h>

gsm_object::gsm_object(uint_fast32_t id, const std::vector<std::string> &ell, const std::vector<std::string> &xi,
                       const std::vector<double> &scores,
                       const std::unordered_map<std::string, std::vector<gsm_object_xi_content>> &phi)
        : id(id), ell(ell), xi(xi), scores(scores), phi(phi) {}

void gsm_object::updateWith(const gsm_object& old) {
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
        phi[oldKey].insert(phi[oldKey].begin(), oldValue.begin(), oldValue.end());
//        remove_duplicates(phi.emplace(oldKey, oldValue).first->second); // Inserting the old content only if something new is not available
    }
}

bool gsm_object::operator==(const gsm_object &rhs) const {
    return id == rhs.id &&
           ell == rhs.ell &&
           xi == rhs.xi &&
           scores == rhs.scores &&
           phi == rhs.phi;
}

bool gsm_object::operator!=(const gsm_object &rhs) const {
    return !(rhs == *this);
}


#include "queries/delta_updates.h"

void gsm_object::out_json(std::ostream &os, bool inserted) const {
    // TODO:Score/Provenance

    os << "{\"id\":" << id << ", \"ell\":[";
    for (size_t i = 0, N = ell.size(); i<N; i++) {
        os << std::quoted(ell.at(i));
        if (i != (N-1)) os << ",";
    }
    os << "], \"xi\":[";
    for (size_t i = 0, N = xi.size(); i<N; i++) {
        os << std::quoted(xi.at(i));
        if (i != (N-1)) os << ",";
    }
    os << "], \"properties\":{";
    for (auto it = content.begin(), en = content.end(); it != en; ) {
        os << std::quoted(it->first) << ":";
        if (std::holds_alternative<std::string>(it->second)) {
            os << std::quoted(std::get<std::string>(it->second));
        } else {
            os << std::quoted(std::to_string(std::get<double>(it->second)));
        }
        it++;
        if (it != en) {
            os << ", ";
        }
    }
    os << "}, \"phi\":[";
    std::map<std::string, std::map<size_t, std::vector<gsm_object_xi_content>>> P;
    for (const auto& [k,v] : phi) {
        for (const auto& x : v) {
            P[k][x.id].emplace_back(x);
        }
    }
    for (auto it1 = P.begin(), en1 = P.end(); it1 != en1; ) {
        size_t i = 0;
        for (auto it2 = it1->second.begin(), en2 = it1->second.end(); it2 != en2; ) {
            for (auto it3 = it2->second.begin(), en3 = it2->second.end(); it3 != en3; ) {
                os << "{\"containment\":" << std::quoted(it1->first)
                   << ", \"content\":" << it2->first
                   << ", \"properties\":{";
                for (auto it = it3->property_values.begin(), en = it3->property_values.end(); it != en; ) {
                    os << std::quoted(it->first) << ":";
                    if (std::holds_alternative<std::string>(it->second)) {
                        os << std::quoted(std::get<std::string>(it->second));
                    } else {
                        os << std::quoted(std::to_string(std::get<double>(it->second)));
                    }
                    it++;
                    if (it != en) {
                        os << ", ";
                    }
                }

                // TODO!
                os << R"(}, "score":{"type": "ProvPhi", "parent":)"
                   << id << ",\"label\":"<< std::quoted(it1->first)
                   << ",\"child\":" << it2->first << ",\"id\":" << (i++)
                   << "}}"
                        ;
                it3++;
                if (it3 != en3) {
                    os << ",";
                }
            }
            i++;
            it2++;
            if (it2 != en2) {
                os << ",";
            }
        }
        it1++;
        if (it1 != en1) {
            os << ",";
        }
    }
    os << "], \"scores\":{\"type\": \"ProvObject\",\"object\":"<<id<<"}";
    os << "}";
}
