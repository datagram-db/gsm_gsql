//
// Created by giacomo on 09/04/23.
//

#ifndef GSM_GSQL_JAVA_TYPES_H
#define GSM_GSQL_JAVA_TYPES_H

#include <string>
#include <vector>
#include <utility>
#include <memory>
#include <unordered_map>
using Boolean = bool;
using Double = double;
using String = std::string;
template <typename T> using ArrayList = std::vector<T>;
template <typename T> using List = std::vector<T>;
template <typename K, typename V> using JPair = std::pair<K,V>;
template <typename T> using DPtr = std::shared_ptr<T>;
template <typename K, typename V> using HashMap = std::unordered_map<K,V>;
template <typename T> using StringMap = HashMap<String, T>;



#endif //GSM_GSQL_JAVA_TYPES_HString
