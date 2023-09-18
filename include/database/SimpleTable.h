//
// Created by giacomo on 15/09/23.
//

#ifndef GSM2_SIMPLETABLE_H
#define GSM2_SIMPLETABLE_H
#include <string>
#include <vector>
#include <set>
#include "yaucl/structures/default_constructors.h"

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
                    result.datum.emplace_back(v);
                }
            }
            it++;
            it2++;
        }
    }
    return result;
}


template <typename D>
SimpleTable<D> left_equijoin(const SimpleTable<D>& lhs, const SimpleTable<D>& rhs, D bogus_value) {
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
    std::vector<D> remainingV(remainingR.size(), bogus_value);

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
            for (const auto& lR : it->second) {
//                for (const auto& rR : it2->second) {
                    auto v = it->first;
                    v.insert(v.end(), lR.begin(), lR.end());
                    v.insert(v.end(), remainingV.begin(), remainingV.end());
                    result.datum.emplace_back(v);
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
                    result.datum.emplace_back(v);
                }
            }
            it++;
            it2++;
        }
    }
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
    return {result, remainingV};
}

#endif //GSM2_SIMPLETABLE_H
