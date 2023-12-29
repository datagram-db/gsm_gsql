//
// Created by giacomo on 26/12/23.
//

#ifndef GSM2_GSMISO_H
#define GSM2_GSMISO_H

#include "roaring64map.hh"
#include <functional>
#include "database/gsm_object.h"
#include <yaucl/structures/any_to_uint_bimap.h>

struct GSMIso {

    struct TopologicalSort {
        const std::vector<gsm_object>& O;
        yaucl::structures::any_to_uint_bimap<size_t> db;
        std::vector<std::vector<size_t>> levels;

        TopologicalSort(const std::vector<gsm_object>& O) : O{O} {
            for (size_t i = 0, N = O.size(); i<N; i++) {
                const auto& ref = db.put(O.at(i).id);
                DEBUG_ASSERT(ref.first == i);
            }
            for (size_t i = 0, N = O.size(); i<N; i++) {
                if (!visited.contains(O.at(i).id)) {
                    topologicalSortUtil(O.at(i).id);
                }
            }
            finaliseStack();
        }

    private:
        std::unordered_map<size_t, std::unordered_set<size_t>> ingoing_edges;

        roaring::Roaring64Map visited;
        std::vector<size_t> Stack;

        std::unordered_map<size_t, size_t> time;
        void topologicalSortUtil(size_t v)
        {
            // Mark the current node as visited.
            visited.add(v);

            // Recur for all the vertices adjacent to this vertex
            for (const auto& [k,u] : O.at(db.getKey(v)).phi) {
                for (const auto& w : u) {
                    if (!visited.contains(w.id)) {
                        ingoing_edges[w.id].insert(v);
                        topologicalSortUtil(w.id);
                    }
                }
            }

            // Push current vertex to stack which stores result
            Stack.emplace_back(v);
        }
        void finaliseStack() {
//            db.clear();
            std::reverse(Stack.begin(), Stack.end());
            bool firstVisit = true;
            size_t T = 0;
            for (size_t v : Stack) {
                if (firstVisit) {
                    time[v] = 0;
                    firstVisit = false;
                } else {
                    time[v] = 0;
                    auto it = ingoing_edges.find(v);
                    if (it != ingoing_edges.end()) {
                        for (size_t edgeId : it->second)
                            time[v] = std::max(time[edgeId], time[v]);
                        time[v]++;
                    }
                    T = std::max(T, time[v]);
                }
            }
            ingoing_edges.clear();
            levels.resize(T+1);
            for (const auto& [id,t] : time) {
                levels.at(t).emplace_back(id);
            }
            time.clear();
        }
    };

    bool equals(const std::vector<gsm_object>& left,
                const std::vector<gsm_object>& right,
                const std::function<bool(const gsm_object&, const gsm_object&)>& obj_eq) {
        if (left.size() != right.size())
            return false;

        TopologicalSort topoLeft(left);
        TopologicalSort topoRight(right);
        if (topoLeft.levels.size() != topoRight.levels.size())
            return false;

        std::vector<std::vector<std::unordered_map<size_t,size_t>>> leftFM, rightFM;
        leftFM.reserve(topoLeft.levels.size());
        rightFM.reserve(topoLeft.levels.size());
        for (size_t i = 0, N = topoLeft.levels.size(); i<N; i++) {
            std::unordered_map<size_t, std::unordered_set<size_t>> leftRightMap;
            std::vector<std::pair<size_t, std::vector<size_t>>> flattened;
            auto& LLL = leftFM.emplace_back();
            auto& RRR = rightFM.emplace_back();

            const auto& leftLevel = topoLeft.levels.at(i);
            const auto& rightLevel = topoRight.levels.at(i);
            if (leftLevel.size() != rightLevel.size())
                return false;
            for (size_t j = 0, M = leftLevel.size(); j<M; j++) {
                const auto& leftItemIdx = leftLevel.at(j);
                const auto& leftItem = left.at(topoLeft.db.getKey(leftItemIdx));

                for (size_t k = 0; k<M; k++) {
                    const auto& rightItemIdx = rightLevel.at(k);
                    // Restraining the morphisms to the value equivalence, thus reducing the
                    // attempts to morphisms to the ones being value equivalent
                    if (obj_eq(leftItem, right.at(topoRight.db.getKey(rightItemIdx)))) {
                        leftRightMap[leftItemIdx].emplace(rightItemIdx);
                    }
                }
            }
            for (const auto& [k,v] : leftRightMap) {
                flattened.emplace_back(k, std::move(std::vector<size_t>{v.begin(), v.end()}));
            }
            leftRightMap.clear();
            const long long O = std::accumulate( flattened.begin(), flattened.end(), 1LL, []( long long a, const std::pair<size_t, std::vector<size_t>>& b ) { return a*b.second.size(); } );
            std::unordered_map<size_t, size_t> u(flattened.size()), rU(flattened.size());
//            bool skip = false;
            for( long long n=0 ; n<O ; ++n ) {
//                skip = false;
                lldiv_t q { n, 0 };
                for( long long j=flattened.size()-1 ; 0<=j ; --j ) {
                    q = lldiv( q.quot, flattened[j].second.size() );
                    u[flattened[j].first] = flattened[j].second[q.rem];
                    rU[flattened[j].second[q.rem]] = flattened[j].first;
                }
                LLL.emplace_back(std::move(u));
                RRR.emplace_back(std::move(rU));
//                u.clear();
//                rU.clear();
            }
        }

        std::vector<std::unordered_map<size_t,size_t>> LR, RR;
        {
            const long long O = std::accumulate( leftFM.begin(), leftFM.end(), 1LL, []( long long a, const std::vector<std::unordered_map<size_t,size_t>>& b ) { return a*b.size(); } );
//            const long long P = ;
            DEBUG_ASSERT(O == std::accumulate( rightFM.begin(), rightFM.end(), 1LL, []( long long a, const std::vector<std::unordered_map<size_t,size_t>>& b ) { return a*b.size(); } ));
            std::unordered_map<size_t,size_t> tmpL, tmpR;
            for( long long n=0 ; n<O ; ++n ) {
                tmpL.clear(); tmpR.clear();
                lldiv_t q { n, 0 };
                for( long long j=leftFM.size()-1 ; 0<=j ; --j ) {
                    q = lldiv(q.quot, leftFM[j].size());
                    tmpL.insert(leftFM[j][q.rem].begin(),  leftFM[j][q.rem].end());
                    tmpR.insert(rightFM[j][q.rem].begin(),  rightFM[j][q.rem].end());
                }
                LR.emplace_back(std::move(tmpL)); tmpL.clear();
                RR.emplace_back(std::move(tmpR)); tmpR.clear();
            }
        }

        bool skip = false;
        for (size_t i = 0, N = RR.size(); i<N; i++){
            const auto& u = LR.at(i);
            const auto& rU = RR.at(i);
            for (const auto& [orig,dst] : u) {
                if (!comparison(left.at(topoLeft.db.getKey(orig)).phi,
                                u,
                                right.at(topoRight.db.getKey(dst)).phi)) {
                    skip = true;
                    break;
                }
            }
            for (const auto& [dst,orig]: rU) {
                if (!comparison(right.at(topoRight.db.getKey(dst)).phi,
                                rU,
                                left.at(topoLeft.db.getKey(orig)).phi)) {
                    skip = true;
                    break;
                }
            }
            if (skip) continue;
            else return true; // I found a correspondence!
        }
        return false;
    }

private:

    inline bool comparison(const std::unordered_map<std::string, std::vector<gsm_object_xi_content>>& src,
                    const std::unordered_map<size_t, size_t>& conversion,
                    const std::unordered_map<std::string, std::vector<gsm_object_xi_content>>& target) {
        if (src.size() != target.size())
            return false;
        else {
            std::unordered_map<std::string, std::vector<gsm_object_xi_content>> result;
            for (const auto& [k, vec] : src) {
                for (const auto& u : vec) {
                    auto j = u;
                    j.id = conversion.at(j.id);
                    result[k].emplace_back(std::move(j));
                }
            }
            return result == target;
        }
    }

};


#endif //GSM2_GSMISO_H
