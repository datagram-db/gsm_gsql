/*
 * DataQuery.h
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
// Created by giacomo on 20/01/2022.
//
// Imported from KnoBAB

#ifndef KNOBAB_DATAQUERY_H
#define KNOBAB_DATAQUERY_H

#include <string>
#include <variant>
#include "yaucl/hashing/hashing.h"
#include "yaucl/hashing/hash_combine.h"
#include "yaucl/structures/default_constructors.h"


//enum DataQueryType {
////    ExistsQuery,
////    AbsenceQuery,
//    RangeQuery,
////    InitQuery,
////    EndsQuery,
////    AtomQuery,
////    FirstQuery,
////    LastQuery
//};


struct DataQuery {
    std::string label;
    std::string var;
    std::variant<std::string, double> lower_bound, upper_bound;
    double score;

    static DataQuery
    RangeQuery(const std::string &atom,
               const std::string &var,
               const std::variant<std::string, double> &lb,
               const std::variant<std::string, double> &ub,
               double score = 1.0);

    DEFAULT_CONSTRUCTORS(DataQuery);

    bool operator==(const DataQuery &rhs) const;
    bool operator!=(const DataQuery &rhs) const;
    bool operator<(const DataQuery &rhs) const;
    bool operator>(const DataQuery &rhs) const;
    bool operator<=(const DataQuery &rhs) const;
    bool operator>=(const DataQuery &rhs) const;
};

namespace std {
    template<>
    struct hash<struct DataQuery> {
        std::size_t operator()(const struct DataQuery &k) const {
            return yaucl::hashing::hash_combine(yaucl::hashing::hash_combine(yaucl::hashing::hash_combine(
                                                                                     yaucl::hashing::hash_combine(31,  k.label), k.var),
                                                                             k.lower_bound), k.upper_bound);
        }
    };

}


#endif //KNOBAB_DATAQUERY_H
