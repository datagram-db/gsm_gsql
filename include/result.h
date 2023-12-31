/*
 * result.h
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
// Created by giacomo on 12/08/23.
//

#ifndef GSM2_RESULT_H
#define GSM2_RESULT_H

#include <vector>
#include <ostream>

/**
 * This data structure only relates to the results given from directly querying the database, and not from
 * the intermediate results, where we might add, remove, and define novel datasets
 */
struct result {
    size_t graphid;
    size_t eventid;
    size_t globalEdgeId;
//    double score;

    result(size_t g, size_t e, size_t globalEdgeId) : graphid{g}, eventid{e}, globalEdgeId{globalEdgeId}/*, score{d}*/{};
//    result(size_t g, size_t e, size_t globalEdgeId) : graphid{g}, eventid{e}, globalEdgeId{globalEdgeId}, score{1.0} {}
    result(const result&) = default;
    result(result&& ) = default;
    result& operator=(const result&) = default;
    result& operator=(result&& ) = default;
    bool operator==(const result &rhs) const;
    bool operator!=(const result &rhs) const;
    bool operator<(const result &rhs) const;
    bool operator>(const result &rhs) const;
    bool operator<=(const result &rhs) const;
    bool operator>=(const result &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const result &result);
};

#include <functional>

static
inline void result_union(const std::vector<result>& lhs,
                          const std::vector<result>& rhs,
                          std::vector<result>& out/*,
                          const std::function<double(double,double)>& combination*/) {
    auto first1 = lhs.begin(), first2 = rhs.begin(),
            last1 = lhs.end(), last2 = rhs.end();

    while (first1 != last1) {
        if (first2 == last2) {
            std::copy(first1, last1, std::back_inserter(out));
            return;
        }
        if (first1 > first2) {
            out.emplace_back(*first2++);
        } else if (first1 < first2) {
            out.emplace_back(*first1++);
        } else {
            out.emplace_back(first1->graphid, first1->eventid, first1->globalEdgeId);//, combination(first1->score, first2->score));
            first1++;
            first2++;
        }
    }
    std::copy(first2, last2, std::back_inserter(out));
}


#include "simple_pair_hash.h"

static inline void
map_union(const std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& lhs,
          const std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& rhs,
          std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& out/*,
          const std::function<double(double,double)>& combination*/) {
    std::unordered_set<std::pair<size_t, size_t>> K;
    for (const auto& [k,v] : lhs) K.insert(k);
    for (const auto& [k,v] : rhs) K.insert(k);
    for (const auto& k : K) {
        auto it = lhs.find(k);
        if (it == lhs.end()) {
            out[k] = rhs.at(k);
        } else {
            auto it2 = rhs.find(k);
            if (it2 == rhs.end()) {
                out[k] = it->second;
            } else {
                result_union(it->second, it2->second, out[k]/*, combination*/);
            }
        }
    }
}

static inline void multi_union(const std::vector<std::vector<result>>& q,
                               std::vector<result>& last_union/*,
                               const std::function<double(double,double)>& combination*/) {
    size_t N = q.size();
    if (N == 0) {
        last_union.clear();
        return;
    } else if (N == 1) {
        last_union = q.at(0);
    } else if (N == 2) {
        const auto &arg1 = q.at(0);
        const auto &arg2 = q.at(1);
        last_union.clear();
        result_union(q.at(0), q.at(1), last_union/*, combination*/);
    } else {
        auto it = q.begin();
        last_union = (*it);
        std::vector<result> curr_union;
        for (std::size_t i = 1; i < N; ++i) {
            it++;
            auto& ref = (*it);
            result_union(last_union, ref, curr_union/*, combination*/);
            std::swap(last_union, curr_union);
            curr_union.clear();
        }
    }
}

static inline void multi_map_union(const std::vector<std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>>& q,
                                   std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& last_union/*,
                               const std::function<double(double,double)>& combination*/) {
    size_t N = q.size();
    if (N == 0) {
        last_union.clear();
        return;
    } else if (N == 1) {
        last_union = q.at(0);
    } else if (N == 2) {
        const auto &arg1 = q.at(0);
        const auto &arg2 = q.at(1);
        last_union.clear();
        map_union(q.at(0), q.at(1), last_union/*, combination*/);
    } else {
        auto it = q.begin();
        last_union = (*it);
        std::unordered_map<std::pair<size_t, size_t>, std::vector<result>> curr_union;
        for (std::size_t i = 1; i < N; ++i) {
            it++;
            auto& ref = (*it);
            map_union(last_union, ref, curr_union/*, combination*/);
            std::swap(last_union, curr_union);
            curr_union.clear();
        }
    }
}


static
inline void result_intersection(const std::vector<result>& lhs,
                         const std::vector<result>& rhs,
                         std::vector<result>& out/*,
                         const std::function<double(double,double)>& combination*/) {
    auto first1 = lhs.begin(), first2 = rhs.begin(),
            last1 = lhs.end(), last2 = rhs.end();

    while (first1 != last1) {
        if (first2 == last2) {
            std::copy(first1, last1, std::back_inserter(out));
            return;
        }
        if (first1 > first2) {
            first2++;
        } else if (first1 < first2) {
            first1++;
        } else {
            out.emplace_back(first1->graphid, first1->eventid, first1->globalEdgeId); // combination(first1->score, first2->score));
            first1++;
            first2++;
        }
    }
    std::copy(first2, last2, std::back_inserter(out));
}

static inline void
map_intersection(const std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& lhs,
          const std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& rhs,
          std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& out/*,
          const std::function<double(double,double)>& combination*/) {
    std::unordered_set<std::pair<size_t, size_t>> K;
    if (lhs.size() < rhs.size()) {
        for (const auto& [k,v] : lhs) {
            auto it = rhs.find(k);
            if (it != rhs.end()) {
                result_intersection(v, it->second, out[k]/*, combination*/);
            }
        }
    } else {
        for (const auto& [k,v] : rhs) {
            auto it = lhs.find(k);
            if (it != lhs.end()) {
                result_intersection(it->second, v, out[k]/*, combination*/);
            }
        }
    }
}

static inline void multi_intersection(const std::vector<std::vector<result>>& q,
                               std::vector<result>& last_union/*,
                               const std::function<double(double,double)>& combination*/) {
    size_t N = q.size();
    if (N == 0) {
        last_union.clear();
        return;
    } else if (N == 1) {
        last_union = q.at(0);
    } else if (N == 2) {
        const auto &arg1 = q.at(0);
        const auto &arg2 = q.at(1);
        last_union.clear();
        result_intersection(q.at(0), q.at(1), last_union/*, combination*/);
    } else {
        auto it = q.begin();
        last_union = (*it);
        std::vector<result> curr_union;
        for (std::size_t i = 1; i < N; ++i) {
            it++;
            auto& ref = (*it);
            result_intersection(last_union, ref, curr_union/*, combination*/);
            std::swap(last_union, curr_union);
            curr_union.clear();
        }
    }
}

static inline void multi_map_intersection(const std::vector<std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>>& q,
                                   std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& last_union/*,
                                   const std::function<double(double,double)>& combination*/) {
    size_t N = q.size();
    if (N == 0) {
        last_union.clear();
        return;
    } else if (N == 1) {
        last_union = q.at(0);
    } else if (N == 2) {
        const auto &arg1 = q.at(0);
        const auto &arg2 = q.at(1);
        last_union.clear();
        map_intersection(q.at(0), q.at(1), last_union/*, combination*/);
    } else {
        auto it = q.begin();
        last_union = (*it);
        std::unordered_map<std::pair<size_t, size_t>, std::vector<result>> curr_union;
        for (std::size_t i = 1; i < N; ++i) {
            it++;
            auto& ref = (*it);
            map_intersection(last_union, ref, curr_union/*, combination*/);
            std::swap(last_union, curr_union);
            curr_union.clear();
        }
    }
}

#endif //GSM2_RESULT_H
