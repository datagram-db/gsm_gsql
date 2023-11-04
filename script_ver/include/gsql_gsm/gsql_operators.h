/*
 * gsql_operators.h
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

#ifndef GSM_GSQL_GSQL_OPERATORS_H
#define GSM_GSQL_GSQL_OPERATORS_H

#include <gsql_gsm/gsm_inmemory_db.h>
#include <functional>

using ellT = std::function<std::string(const gsm_object&)>;
using xiT = std::function<std::vector<std::string>(const gsm_object&)>;
using phiT = std::function<std::unordered_map<std::string, std::vector<gsm_object_xi_content>>(const gsm_object&)>;

// Definition 39 (Object Creation), p. 158

//static inline
//struct gsm_inmemory_db create(const struct gsm_inmemory_db& db,
//                              uint_fast32_t id = 0,
//                              const std::vector<std::string> &ell = {},
//                              const std::vector<std::string> &xi = {},
//                              const std::vector<double> &scores = {},
//                              const std::unordered_map<std::string, std::vector<gsm_object_xi_content>> &phi = {}) {
//    if (db.O.contains(id)) {
//        return db;
//    }
//    gsm_inmemory_db result = db;
//    result.O[id] = {id, ell, xi, scores, phi};
//    if (id > result.max_id)
//        result.max_id = id;
//    return result;
//}

static inline
gsm_inmemory_db_view createFast(struct gsm_inmemory_db_view& db,
                uint_fast32_t id = 0,
                const std::string &ell = {},
                const std::vector<std::string> &xi = {},
                const std::vector<double> &scores = {},
                const std::unordered_map<std::string, std::vector<gsm_object_xi_content>> &phi = {}) {
    if(db.db->O.contains(id))
        return db;
    db.db->O[id] = {id, ell, xi, scores, phi};
    if (id > db.db->max_id)
        db.db->max_id = id;
    return db;
}


// Definition 41 (Elect), p. 160
static inline
gsm_inmemory_db_view  elect(struct gsm_inmemory_db_view& db,
                             size_t id) {
    if (db.db->O.contains(id)) {
        return {id, db.db};
    }
    return db;
}


// Definition 40 (Elect), p. 159
static inline
struct gsm_inmemory_db_view map(struct gsm_inmemory_db_view& db,
                           const ellT& lT,
                           const xiT& xT,
                           const phiT& pT) {
    std::unordered_map<size_t, size_t> conversion_map;
//    gsm_inmemory_db result = db;
    for (const auto& obj : db.db->O) {
        gsm_object obj2(obj.first, lT(obj.second), xT(obj.second), obj.second.scores, pT(obj.second));
        if (obj2 != obj.second) {
            uint32_t high = (obj.first & 0xFFFFFFFF00000000ULL) >> 32;
            high++;
            uint32_t low = obj.first & 0xFFFFFFFF;
            obj2.id = ((uint64_t)high << 32) | low;
            conversion_map[obj.first] = obj2.id;
            db.db->max_id = std::max(db.db->max_id, obj2.id);
            db.db->O[obj2.id] = obj2;
        }
    }
    for (const auto& [id,idx] : conversion_map) {
        for (auto& [k,vl] : db.db->O[idx].phi) {
            for (auto& [nid,val] : vl) {
                auto it = conversion_map.find(nid);
                if (it != conversion_map.end()) nid = it->second;
            }
        }
    }
    auto it = conversion_map.find(db.o);
    if (it != conversion_map.end())
        return {it->second, db.db};
    return db;
}

// Definition 42 (n-ary Disjoint Union), p. 160
static inline
struct gsm_inmemory_db_view disjoint(const std::vector<struct gsm_inmemory_db_view>& args) {
    // TODO: double check
    auto db = std::make_shared<gsm_inmemory_db>();
    gsm_inmemory_db_view result{0, std::move(db)};
    if (args.empty()) return result;
    else if (args.size() == 1) return args.at(0);
    else {
        gsm_object resultObj;
        uint32_t curr_high, curr_low;
        for (size_t i = 0, N = args.size(); i<N; i++) {
            std::string idi = std::to_string(i)+"_";
            auto& ref = args.at(i);
            result.db->O.insert(ref.db->O.begin(), ref.db->O.end());
            uint32_t high = (ref.db->max_id & 0xFFFFFFFF00000000ULL) >> 32;
            uint32_t low = ref.db->max_id & 0xFFFFFFFF;
            result.db->max_id = std::max(result.db->max_id, ref.db->max_id);
            if (i == 0) {
                curr_high= high;
                curr_low = low;
                resultObj.ell = ref.db->O.at(ref.o).ell;
                resultObj.xi = ref.db->O.at(ref.o).xi;
                for (const auto& [k,v] : ref.db->O.at(ref.o).phi) {
                    resultObj.phi[idi] = v;
                }
            } else {
                curr_high = std::max(curr_high, high);
                curr_low = std::max(curr_low, low);
                resultObj.ell.insert(resultObj.ell.end(), ref.db->O.at(ref.o).ell.begin(), ref.db->O.at(ref.o).ell.end());
                resultObj.xi.insert(resultObj.xi.end(), ref.db->O.at(ref.o).xi.begin(), ref.db->O.at(ref.o).xi.end());
                for (const auto& [k,v] : ref.db->O.at(ref.o).phi) {
                    resultObj.phi[idi] = v;
                }
            }
        }
        curr_high++;
        curr_low++;
        resultObj.id = ((uint64_t)curr_high << 32) | curr_low;
        result.o = resultObj.id;
        result.db->O[resultObj.id] = resultObj;
        return result;
    }

}

// Definition 43 (High Order Fold Operator), p. 161
template <typename T, typename IteratorT, typename Alpha>
static inline Alpha fold(IteratorT begin,
                         IteratorT end,
                         Alpha a,
                         std::function<Alpha(const T&, const Alpha&)> f)  {
    while (begin != end) {
        a = f(*begin, a);
        begin++;
    }
    return a;
}

#endif //GSM_GSQL_GSQL_OPERATORS_H
