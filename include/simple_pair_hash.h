//
// Created by giacomo on 13/08/23.
//

#ifndef GSM2_SIMPLE_PAIR_HASH_H
#define GSM2_SIMPLE_PAIR_HASH_H


#include <utility>
#include <unordered_set>
#include <unordered_map>

namespace std {
    template<> struct hash<std::pair<size_t, size_t>> {
        size_t operator()(const std::pair<size_t,size_t>& x) const {
            return x.first ^ x.second;
        }
    };
}


#endif //GSM2_SIMPLE_PAIR_HASH_H
