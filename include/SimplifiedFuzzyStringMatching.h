//
// Created by giacomo on 01/11/2021.
//

#ifndef KNOBAB_SIMPLIFIEDFUZZYSTRINGMATCHING_H
#define KNOBAB_SIMPLIFIEDFUZZYSTRINGMATCHING_H

#include <string>
#include <yaucl/structures/any_to_uint_bimap.h>
#include <unordered_map>
#include <vector>
#include <yaucl/structures/PollMap.h>
#include <unordered_set>

std::vector<std::string> compareString_wordLetterPairs(const std::string& strMixed);

class SimplifiedFuzzyStringMatching {
    static_assert(sizeof(short) == sizeof(char)*2, "Chars should be double the size than chars");
    yaucl::structures::any_to_uint_bimap<std::string> unique_string;
    std::unordered_map<std::string, std::vector<size_t>> shift0_2grams_containment;
    std::unordered_map<std::string, std::unordered_map<std::string, size_t>> gram_multiplicity;
    std::unordered_map<std::string, size_t> objectGramSize;


public:
    std::pair<size_t, bool> put(const std::string& str);
    std::string get(size_t id) const;
    void clear() {
        shift0_2grams_containment.clear();
        gram_multiplicity.clear();
        objectGramSize.clear();
    }

    // TODO: import the code for the indexed approximate string matching
    void getTwoGramAndString(const std::string &argument, std::unordered_map<std::string , size_t> &map) const;

    void fuzzyMatch(double threshold,
                    size_t topk,
                    const std::string& objectString,
                    std::multimap<double, std::string> &result) const;

private:
    void rankCollectionOf(std::unordered_set<size_t> &k, std::unordered_map<std::string , size_t> &m1,
                          unsigned long size, double threshold,
                          yaucl::structures::PollMap<double, std::string> &pollMap) const;
};


#include <codecvt>

class FuzzyMatchSerializer {
    std::hash<std::string> hfunc;
    std::map<size_t, std::vector<std::pair<std::string, std::vector<size_t>>>> gramToObject, objectGramSize, termObject;
    std::map<size_t, std::vector<std::string>> objectMultipleStirngs;
    std::map<size_t, std::vector<std::pair<std::string, std::vector<std::pair<std::string, size_t>>>>> twogramAndStringMultiplicity;
//    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    inline void SLHM_Primary_store(std::map<size_t, std::vector<std::pair<std::string, std::vector<size_t>>>>& ordered_multimap, const std::string &elem, size_t value) {
        auto& hashKey = ordered_multimap[hfunc(elem)];
//        Node<LONG_NUMERIC, std::pair<std::string, std::vector<LONG_NUMERIC>>> *hashKey = ordered_multimap.insertKey(hfunc(elem));
        if (!hashKey.empty()) {
            for (std::pair<std::string, std::vector<size_t>> &x : hashKey) {
                if (x.first == elem) {
                    x.second.emplace_back(value);
                    return;
                }
            }
        }
        std::vector<size_t> element;
        element.push_back(value);
        hashKey.emplace_back(elem, element);
    }
    inline void StringToTwoGramSizeHashMultimapIndexer_store(std::map<size_t, std::vector<std::pair<std::string, std::vector<std::pair<std::string, size_t>>>>>& ordered_multimap, const std::string &elem, const std::string &twogram, size_t value) {
        auto&hashKey = ordered_multimap[hfunc(elem)];
        if (!hashKey.empty()) {
            for (std::pair<std::string, std::vector<std::pair<std::string, size_t>>> &x : hashKey) {
                if (x.first == elem) {
                    x.second.emplace_back(twogram, value);
                    return;
                }
            }
        }
        std::vector<std::pair<std::string, size_t>> element;
        element.emplace_back(twogram, value);
        hashKey.emplace_back(elem, element);
    }
public:
    // TODO: approximate fuzzy matching for this!
    void addGramsToMap(const std::string &string,
                       size_t id,
                       const std::vector<std::string> &associatedOtherStrings);
};


#endif //KNOBAB_SIMPLIFIEDFUZZYSTRINGMATCHING_H
