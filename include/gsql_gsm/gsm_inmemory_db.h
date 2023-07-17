/*
 * gsm_inmemory_db.h
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

#ifndef GSM_GSQL_GSM_INMEMORY_DB_H
#define GSM_GSQL_GSM_INMEMORY_DB_H

#include <gsql_gsm/gsm_object.h>

struct gsm_inmemory_db {
    // All objects of the database
    std::unordered_map<size_t, gsm_object> O;
    uint_fast32_t max_id = 0;
    // maximum Id available
//    size_t max_id;

    gsm_inmemory_db(uint_fast32_t id = 0, const std::string &ell = {}, const std::vector<std::string> &xi = {},
                    const std::vector<double> &scores = {}, const std::unordered_map<std::string, std::vector<gsm_object_xi_content>> &phi = {});
    gsm_inmemory_db(const gsm_inmemory_db& ) = default;
    gsm_inmemory_db(gsm_inmemory_db&& ) = default;
    gsm_inmemory_db& operator=(const gsm_inmemory_db& ) = default;
    gsm_inmemory_db& operator=(gsm_inmemory_db&& ) = default;
    inline const std::string& ell(size_t i) const { return O.at(i).ell; }
    inline const std::vector<std::string>& xi(size_t i ) const { return O.at(i).xi; }
    inline const std::vector<double>& err(size_t i) const { return O.at(i).scores; }
    inline const std::unordered_map<std::string, std::vector<gsm_object_xi_content>>& phi(size_t i) const {return O.at(i).phi; }

    /**
     * Runtime calculation of varphi (as further operations might update it)
     * TODO: run-time updates!
     *
     * @param i     Id for which obtain all of its contents
     * @return
     */
    inline std::unordered_set<size_t> varphi(size_t i) const {
        auto result = varphi_plus(i);
        result.erase(i);
        return result;
    }

    /**
     * Getting all of the nodes that
     * @param i
     * @return
     */
    inline std::unordered_set<size_t> varphi_plus(size_t i) const {
        std::unordered_set<size_t> nav;
        expand_varphi_plus(i, nav);
        return nav;
    }
private:
    void expand_varphi_plus(size_t id, std::unordered_set<size_t>& result) const {
        if (result.contains(id)) return;
        result.insert(id);
        for (const auto& [k,v] : O.at(id).phi) {
            for (const auto& cont : v) {
                expand_varphi_plus(cont.id, result);
            }
        }
    }
};

#include <memory>

struct gsm_inmemory_db_view {
    // Root object
    size_t                                 o;
    std::shared_ptr<gsm_inmemory_db>      db;
    gsm_inmemory_db_view() : o{0}, db{nullptr} {}
    gsm_inmemory_db_view(size_t o, std::shared_ptr<gsm_inmemory_db> db);
    gsm_inmemory_db_view(const gsm_inmemory_db_view& ) = default;
    gsm_inmemory_db_view(gsm_inmemory_db_view&& x) : o{x.o} {
        db = std::move(x.db);
    }
    gsm_inmemory_db_view& operator=(const gsm_inmemory_db_view& ) = default;
    gsm_inmemory_db_view& operator=(gsm_inmemory_db_view&& x) {
        o = x.o;
        db = std::move(x.db);
        return *this;
    }
};


#endif //GSM_GSQL_GSM_INMEMORY_DB_H
