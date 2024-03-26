/*
 * SimpleTable.h
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
// Created by giacomo on 15/09/23.
//

#ifndef GSM2_SIMPLETABLE_H
#define GSM2_SIMPLETABLE_H
#include <string>
#include <vector>
#include <set>
#include "yaucl/structures/default_constructors.h"
#include <iostream>
template <typename D>
struct SimpleTable {
    std::vector<std::string> Schema;
    std::vector<std::vector<D>> datum;

    DEFAULT_CONSTRUCTORS(SimpleTable);
    bool operator==(const SimpleTable<D> &rhs) const {
        return Schema == rhs.Schema &&
               datum == rhs.datum;
    }
    bool operator!=(const SimpleTable<D> &rhs) const {
        return !(rhs == *this);
    }
    bool operator<(const SimpleTable<D>& rhs) const {
        return (Schema == rhs.Schema) && (datum<rhs.datum);
    }

    bool checkSchemaSizeCompliance() const {
        if (datum.empty())
            return true;
        for (size_t i = 0, N = datum.size(); i<N; i++) {
            if (datum.at(i).size() != Schema.size()) {
                std::cerr << "ERROR: Size of record #" <<i << " (" <<   datum.at(i).size()<< ") does not match with the schema size, " << Schema.size() << std::endl;
                return false;
            }
        }
        return true;
    }

};



#include"yaucl/structures/set_operations.h"

template <typename D>
SimpleTable<D> crossProduct(const SimpleTable<D>& lhs, const SimpleTable<D>& rhs) {
    SimpleTable<D> result;
    result.Schema = lhs.Schema;
    result.Schema.insert(result.Schema.end(), rhs.Schema.begin(), rhs.Schema.end());
    for (const auto& recordL : lhs.datum) {
        for (const auto& recordR : rhs.datum) {
            auto v = recordL;
            v.insert(v.end(), recordR.begin(), recordR.end());
            result.datum.emplace_back(v);
        }
    }
    DEBUG_ASSERT(result.checkSchemaSizeCompliance());
    return result;
}

template <typename D>
SimpleTable<D> natural_equijoin(const SimpleTable<D>& lhs, const SimpleTable<D>& rhs) {
    std::set<std::string> i;
    {
        std::set<std::string> L{lhs.Schema.begin(), lhs.Schema.end()}, R{rhs.Schema.begin(), rhs.Schema.end()};
        i = ordered_intersection(L,R);
    }

    if (i.empty()) {
        return crossProduct(lhs, rhs);
    }
    std::vector<size_t> iposL, iposR;
    std::vector<size_t> remainingL, remainingR;
    bool firstStr = true;
    for (const auto& str : i) {
        for (size_t j = 0, N = lhs.Schema.size(); j<N; j++) {
            if (firstStr)
                remainingL.emplace_back(j);
            if (str == (lhs.Schema.at(j))) {
                iposL.emplace_back(j);
                if (!firstStr) break;
            }
        }
        for (size_t j = 0, N = rhs.Schema.size(); j<N; j++) {
            if (firstStr)
                remainingR.emplace_back(j);
            if (str == (rhs.Schema.at(j))) {
                iposR.emplace_back(j);
                if (!firstStr) break;
            }
        }
        firstStr = false;
    }
    std::vector<std::string> L = lhs.Schema, R = rhs.Schema;
    std::set<size_t> IL{iposL.begin(), iposL.end()}, IR{iposR.begin(), iposR.end()};
    {
        std::vector<size_t> tmpL{IL.begin(), IL.end()}, tmpR{IR.begin(), IR.end()};
        remove_index(L, tmpL);
        remove_index(remainingL, tmpL);
        remove_index(R, tmpR);
        remove_index(remainingR, tmpR);
    }

    std::map<std::vector<D>, std::vector<std::vector<D>>> rM, lM;
    for (const auto& record : lhs.datum) {
        std::vector<D> proj, remain;
        for (size_t j = 0, N = record.size(); j<N; j++) {
            if (!IL.contains(j))
                remain.emplace_back(record.at(j));
        }
        for (size_t j : iposL)
            proj.emplace_back(record.at(j));
        lM[proj].emplace_back(remain);
    }
    for (const auto& record : rhs.datum) {
        std::vector<D> proj, remain;
        for (size_t j = 0, N = record.size(); j<N; j++) {
            if (!IR.contains(j))
                remain.emplace_back(record.at(j));
        }
        for (size_t j : iposR)
            proj.emplace_back(record.at(j));
        rM[proj].emplace_back(remain);
    }
    SimpleTable<D> result;
    result.Schema.insert(result.Schema.end(), i.begin(), i.end());
    result.Schema.insert(result.Schema.end(), L.begin(), L.end());
    result.Schema.insert(result.Schema.end(), R.begin(), R.end());
    auto it = lM.begin(), en = lM.end();
    auto it2 = rM.begin(), en2 = rM.end();
    while (it != en && it2 != en2) {
        if (it->first < it2->first) {
            it++;
        } else if (it2->first < it->first) {
            it2++;
        } else {
            for (const auto& lR : it->second) {
                for (const auto& rR : it2->second) {
                    auto v = it->first;
                    v.insert(v.end(), lR.begin(), lR.end());
                    v.insert(v.end(), rR.begin(), rR.end());
                    auto& ref = result.datum.emplace_back(v);
                    for (auto& x : ref) {
                        if (!x.table.Schema.empty())
                            x.isNested = true;
                    }
                }
            }
            it++;
            it2++;
        }
    }
    DEBUG_ASSERT(result.checkSchemaSizeCompliance());
    return result;
}

template <typename D> struct GetSchemaResultingFromJoin {
    bool considerNestedDatum = true;
    const std::vector<D>* rowWithNesting = nullptr;
            size_t hasOneNested = -1;
            size_t forindex = -1;
            size_t iposLIndex = -1;
    bool hasiPosLOneNested;
    std::set<size_t> IL, IR;
    std::vector<size_t> remainingL, remainingR;
    std::vector<size_t> iposL, iposR;

    GetSchemaResultingFromJoin(bool considerNestedDatum, const std::vector<D> *rowWithNesting) : considerNestedDatum(
            considerNestedDatum), rowWithNesting(rowWithNesting) {}

    inline bool compute(const std::vector<std::string>& lhsSchema,
                                                  const std::vector<std::string>& rhsSchema,
                                                  std::vector<std::string>& schemaResult) {
        considerNestedDatum = considerNestedDatum && (rowWithNesting != nullptr);
        std::set<std::string> i;
        {
            std::set<std::string> L{lhsSchema.begin(), lhsSchema.end()}, R{rhsSchema.begin(), rhsSchema.end()};
            i = ordered_intersection(L,R);
        }
        if (i.empty()) {
            return false;
        }
        hasiPosLOneNested = false;
        bool firstStr = true;
        for (const auto& str : i) {
            for (size_t j = 0, N = lhsSchema.size(); j<N; j++) {
                if (firstStr)
                    remainingL.emplace_back(j);
                if (str == (lhsSchema.at(j))) {
                    if ((considerNestedDatum && rowWithNesting) && (rowWithNesting->at(j).isNested)) {
                        if (hasiPosLOneNested)
                            throw std::runtime_error("ERROR: there could be only one nested value within the match matching a join!");
                        hasiPosLOneNested = true;
                        bool found = false;
                        for (size_t k = 0, Q = rowWithNesting->at(j).table.Schema.size(); k<Q; k++) {
                            if (rowWithNesting->at(j).table.Schema.at(k) == str) {
                                hasOneNested = k;
                                forindex = j;
                                found = true;
                                iposLIndex = iposL.size();
                                break;
                            }
                        }
                    }
                    iposL.emplace_back(j);
                    if (!firstStr) break;
                }
            }
            for (size_t j = 0, N = rhsSchema.size(); j<N; j++) {
                if (firstStr)
                    remainingR.emplace_back(j);
                if (str == (rhsSchema.at(j))) {
                    iposR.emplace_back(j);
                    if (!firstStr) break;
                }
            }
            firstStr = false;
        }
        std::vector<std::string> L = lhsSchema, R = rhsSchema;
        IL = {iposL.begin(), iposL.end()};
        IL = {iposR.begin(), iposR.end()};
//        std::set<size_t> IL{iposL.begin(), iposL.end()}, IR{iposR.begin(), iposR.end()};
        {
            std::vector<size_t> tmpL{IL.begin(), IL.end()}, tmpR{IR.begin(), IR.end()};
            remove_index(L, tmpL);
            remove_index(remainingL, tmpL);
            remove_index(R, tmpR);
            remove_index(remainingR, tmpR);
        }
        schemaResult.insert(schemaResult.end(), i.begin(), i.end());
        schemaResult.insert(schemaResult.end(), L.begin(), L.end());
        schemaResult.insert(schemaResult.end(), R.begin(), R.end());
        return true;
    }

    };



template <typename D>
SimpleTable<D> left_equijoin(const SimpleTable<D>& lhs, const SimpleTable<D>& rhs, D bogus_value) {
    // Providing the schema intersection fo the equi-join part
    SimpleTable<D> result;
    bool considerNestedDatum = !lhs.datum.empty();
    const std::vector<D>* ptr = considerNestedDatum ? &lhs.datum.at(0) : nullptr;
    GetSchemaResultingFromJoin<D> considera{considerNestedDatum, ptr};
    if (!considera.compute(lhs.Schema, rhs.Schema, result.Schema)) {
        return crossProduct(lhs, rhs);
    }

//    std::set<std::string> i;
//    {
//        std::set<std::string> L{lhsSchema.begin(), lhsSchema.end()}, R{rhsSchema.begin(), rhsSchema.end()};
//        i = ordered_intersection(L,R);
//    }
//
//    std::vector<size_t> iposL, iposR;
//    std::vector<size_t> remainingL, remainingR;
//    bool firstStr = true;
//    for (const auto& str : i) {
//        for (size_t j = 0, N = lhsSchema.size(); j<N; j++) {
//            if (firstStr)
//                remainingL.emplace_back(j);
//            if (str == (lhsSchema.at(j))) {
//                if ((!lhs.datum.empty()) && (lhs.datum.at(0).at(j).isNested)) {
//                    if (hasiPosLOneNested)
//                        throw std::runtime_error("ERROR: there could be only one nested value within the match matching a join!");
//                    hasiPosLOneNested = true;
//                    bool found = false;
//                    for (size_t k = 0, Q = lhs.datum.at(0).at(j).table.Schema.size(); k<Q; k++) {
//                        if (lhs.datum.at(0).at(j).table.Schema.at(k) == str) {
//                            hasOneNested = k;
//                            forindex = j;
//                            found = true;
//                            iposLIndex = iposL.size();
//                            break;
//                        }
//                    }
//                }
//                iposL.emplace_back(j);
//                if (!firstStr) break;
//            }
//        }
//        for (size_t j = 0, N = rhsSchema.size(); j<N; j++) {
//            if (firstStr)
//                remainingR.emplace_back(j);
//            if (str == (rhsSchema.at(j))) {
//                iposR.emplace_back(j);
//                if (!firstStr) break;
//            }
//        }
//        firstStr = false;
//    }
//    std::vector<std::string> L = lhsSchema, R = rhsSchema;
//    std::set<size_t> IL{iposL.begin(), iposL.end()}, IR{iposR.begin(), iposR.end()};
//    {
//        std::vector<size_t> tmpL{IL.begin(), IL.end()}, tmpR{IR.begin(), IR.end()};
//        remove_index(L, tmpL);
//        remove_index(remainingL, tmpL);
//        remove_index(R, tmpR);
//        remove_index(remainingR, tmpR);
//    }
//    schemaResult.insert(schemaResult.end(), i.begin(), i.end());
//    schemaResult.insert(schemaResult.end(), L.begin(), L.end());
//    schemaResult.insert(schemaResult.end(), R.begin(), R.end());

    std::vector<D> remainingV(considera.remainingR.size(), bogus_value);
    std::map<std::vector<D>, std::vector<std::vector<D>>> rM, lM;
    for (const auto& record : lhs.datum) {
        std::vector<D> proj, remain;
        for (size_t j = 0, N = record.size(); j<N; j++) {
            if (!considera.IL.contains(j))
                remain.emplace_back(record.at(j));
        }
        for (size_t j : considera.iposL) {
            proj.emplace_back(record.at(j));
        }
        if (!considera.hasiPosLOneNested)
            lM[proj].emplace_back(remain);
        else {
            auto cpy = proj;
            const auto& nestedRef = proj.at(considera.iposLIndex).table.datum;
            for (size_t j = 0, Q = nestedRef.size(); j<Q; j++) {
                auto& extremelyLocalRef = cpy.at(considera.iposLIndex);
                extremelyLocalRef.val = nestedRef.at(j).at(considera.hasOneNested).val;
                extremelyLocalRef.isNested = false;
                lM[cpy].emplace_back(remain);
            }
        }
    }
    for (const auto& record : rhs.datum) {
        std::vector<D> proj, remain;
        for (size_t j = 0, N = record.size(); j<N; j++) {
            if (!considera.IR.contains(j))
                remain.emplace_back(record.at(j));
        }
        for (size_t j : considera.iposR)
            proj.emplace_back(record.at(j));
        rM[proj].emplace_back(remain);
    }


    auto it = lM.begin(), en = lM.end();
    auto it2 = rM.begin(), en2 = rM.end();
    while (it != en && it2 != en2) {
        if (it->first < it2->first) {
            for (const auto& lR : it->second) {
//                for (const auto& rR : it2->second) {
                    auto v = it->first;
                    if (considera.hasiPosLOneNested)
                        v.at(considera.iposLIndex).isNested = true;
                    v.insert(v.end(), lR.begin(), lR.end());
                    v.insert(v.end(), remainingV.begin(), remainingV.end());
                    auto& ref = result.datum.emplace_back(v);
                    for (auto& x : ref) {
                        if (!x.table.Schema.empty())
                            x.isNested = true;
                    }
//                }
            }
            it++;
        } else if (it2->first < it->first) {
            it2++;
        } else {
            for (const auto& lR : it->second) {
                for (const auto& rR : it2->second) {
                    auto v = it->first;
                    v.insert(v.end(), lR.begin(), lR.end());
                    v.insert(v.end(), rR.begin(), rR.end());
                    auto& ref = result.datum.emplace_back(v);
                    for (auto& x : ref) {
                        if (!x.table.Schema.empty())
                            x.isNested = true;
                    }
                }
            }
            it++;
            it2++;
        }
    }
    while (it != en) {
        for (const auto& lR : it->second) {
//                for (const auto& rR : it2->second) {
            auto v = it->first;
            v.insert(v.end(), lR.begin(), lR.end());
            v.insert(v.end(), remainingV.begin(), remainingV.end());
            auto& ref = result.datum.emplace_back(v);
            for (auto& x : ref) {
                if (!x.table.Schema.empty())
                    x.isNested = true;
            }
//                }
        }
        it++;
    }
    DEBUG_ASSERT(result.checkSchemaSizeCompliance());
    return result;
}

template <typename D>
struct NestedValue {
    bool isNested = false;
    D val;
    SimpleTable<NestedValue<D>> table;

    NestedValue() {
        isNested = false;
    }
    NestedValue(D x) : val{x} {
        isNested = false;
    }
    DEFAULT_COPY_ASSGN(NestedValue);
    NestedValue(const SimpleTable<NestedValue<D>> & x) : table{x} {
        isNested = true;
    }
    bool operator==(const NestedValue<D> &rhs) const {
        return isNested == rhs.isNested &&
               (isNested ? table == rhs.table : val == rhs.val);
    }
    bool operator<(const NestedValue<D> &rhs) const {
        return isNested == rhs.isNested &&
               (isNested ? table < rhs.table : val < rhs.val);
    }
};

template <typename D>
std::pair<SimpleTable<NestedValue<D>>,std::vector<std::string>> nest_or_groupby(const SimpleTable<NestedValue<D>>& op, std::vector<std::string>& args, const std::string& nested_arg) {
    std::sort(args.begin(), args.end());
    std::set<size_t> IL;
    std::vector<size_t> iposL;
    std::vector<std::string> remainingV;
    std::vector<std::string> resultingSchema;

    for (size_t i = 0, N = op.Schema.size(); i<N; i++) {
        const auto& oSA = op.Schema.at(i);
        auto it = std::lower_bound(args.begin(), args.end(), oSA);
        if ((std::lower_bound(args.begin(), args.end(), oSA) != args.end()) && (*it == oSA)) {
            IL.emplace(i);
//            iposL.emplace_back(i);
        } else {
            remainingV.emplace_back(oSA);
        }
    }
    for (const size_t x : IL)
        resultingSchema.emplace_back(op.Schema.at(x));
    std::map<std::vector<NestedValue<D>>, std::vector<std::vector<NestedValue<D>>>> lM;
    for (const auto& record : op.datum) {
        std::vector<NestedValue<D>> proj, remain;
        for (size_t j = 0, N = record.size(); j<N; j++) {
            if (!IL.contains(j))
                remain.emplace_back(record.at(j));
        }
        for (size_t j : IL)
            proj.emplace_back(record.at(j));
        lM[proj].emplace_back(remain);
    }
    SimpleTable<NestedValue<D>> result;
    result.Schema = resultingSchema;
    result.Schema.emplace_back(nested_arg);
    for (const auto& [k, futureTable] : lM) {
//        SimpleTable<NestedValue<D>> nested;
//        nested.Schema = remainingV;
//        nested.datum = futureTable;
        std::vector<NestedValue<D>> cp = k;
        SimpleTable<NestedValue<D>> table;
        table.Schema = remainingV;
        table.datum = (futureTable);
        NestedValue<D> value(table);
        cp.emplace_back(value);
        result.datum.emplace_back(cp);
    }

#ifdef DEBUG
    if (!result.datum.empty()) {
        DEBUG_ASSERT(result.datum.at(0).size() == result.Schema.size());
    }
#endif

    return {result, remainingV};
}

#endif //GSM2_SIMPLETABLE_H
