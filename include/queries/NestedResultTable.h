//
// Created by giacomo on 02/01/24.
//

#ifndef GSM2_NESTEDRESULTTABLE_H
#define GSM2_NESTEDRESULTTABLE_H

#include <yaucl/structures/default_constructors.h>
#include "yaucl/numeric/ssize_t.h"
#include <variant>
#include <string>
#include <vector>
#include "database/gsm_object_xi_content.h"
#include "roaring64map.hh"
#include <memory>
#include <stdexcept>

namespace script::structures {
    struct ScriptAST;
}

enum ComparisonForNestedResultTable {
    CFNRT_EQ,
    CFNRT_NEQ,
    CFNRT_LT,
    CFNRT_LEQ
};

using SimpleNestedResultTableValue = std::variant<std::string, size_t, std::vector<gsm_object_xi_content>>;

struct OrderedSet {
    roaring::Roaring64Map   set;
    size_t                  cardo;
//    bool                    ignore;

    OrderedSet(roaring::Roaring64Map&& set, size_t cardinality) : set(set), cardo(cardinality){}
    OrderedSet(size_t maxSize) : cardo{maxSize}  {
        if (maxSize > 0) set.addRange(0, maxSize);
    }
//    OrderedSet(bool ignore) : cardo{0}, ignore{ignore} {}

    void fillWithPreviouslyLess(size_t maxSize) {
//        if (ignore) return;
        cardo = maxSize;
        set.addRange(0, maxSize);
    }

    void clearWithMaxCardinality(size_t maxSize) {
//        if (ignore) return;
        set.clear();
        cardo= maxSize;
    }
    bool full() const {
//        if (ignore) return false;
        return (set.cardinality() == cardo) && (cardo != 0);
    }
    bool empty() const {
//        if (ignore) return true;
        return set.cardinality() == 0;
    }
    size_t available() const {
//        if (ignore) return 0;
        return set.cardinality();
    }
    size_t cardinality() const {
        return cardo;
    }
    bool contains(size_t x) const {
        return set.contains(x);
    }
    void add(size_t x) {
        set.add(x);
    }
    OrderedSet& operator&=(const OrderedSet& x) {
        set &= x.set;
        cardo = std::max(x.cardo, cardo);
        return *this;
    }
    OrderedSet& operator|=(const OrderedSet& x) {
        set |= x.set;
        cardo = std::max(x.cardo, cardo);
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const OrderedSet& x) {
        return os << x.cardo << ":" << x.set.toString();
    }
};

struct NestedResultTable {
    ssize_t cell_nested_morphism{-1};
    ssize_t column{-1};
    std::variant<
            std::string,
            std::vector<std::string>,
            size_t,
            std::vector<size_t>,
            std::vector<gsm_object_xi_content>,
            std::vector<std::vector<gsm_object_xi_content>>,
            std::shared_ptr<script::structures::ScriptAST>
    > content{(size_t) 0};
    enum variant_type_cpp {
        RT_STRING,
        RT_VSTRING,
        RT_SIZET,
        RT_VSIZET,
        RT_CONTENT,
        RT_VCONTENT,
        RT_SCRIPT,
        RT_NONE
    };
    enum variant_type {
        R_LABEL, // RT_STRING
        R_NESTED_LABEL, // RT_SIZET
        R_NODE, // RT_SIZET
        R_EDGE, // RT_SIZET
        R_EDGE_SRC,// RT_SIZET
        R_NESTD_EDGE_SRC,// RT_VSIZET
        R_DO_EDGE_SRC,// RT_SIZET
        R_DO_NESTED_EDGE_SRC,// RT_VSIZET
        R_EDGE_DST,// RT_SIZET
        R_DO_EDGE_DST,// RT_SIZET
        R_NESTED_EDGE_DST,// RT_VSIZET
        R_DO_NESTED_EDGE_DST,// RT_VSIZET
        R_NESTED_NODE,// RT_VSIZET
        R_NESTED_EDGE,// RT_VSIZET
        R_CONTENT,// RT_CONTENT
        R_NESTED_CONTENT,// RT_VSTRING
        R_PROP,// RT_STRING
        R_NESTED_PROP,// RT_VSTRING
        R_XI,// RT_STRING
        R_DO_XI,// RT_SIZET
        R_NESTED_XI,// RT_VSTRING
        R_DO_NESTED_XI,// RT_VSIZET
        R_ELL,// RT_STRING
        R_NESTED_ELL,// RT_SIZET
        R_DO_ELL,// RT_SIZET
        R_DO_NESTED_ELL,// RT_VSTRING
        R_EDGE_LABEL,// RT_STRING
        R_NESTED_EDGE_LABEL,// RT_VSTRING
        R_DO_EDGE_LABEL,// RT_SIZET
        R_DO_NESTED_EDGE_LABEL,// RT_VSIZET
        R_DO_CONTENT,//RT_SIZET
        R_DO_NESTED_CONTENT,//RT_VSIZET
        R_DO_PROP,//RT_SIZET
        R_DO_NESTED_PROP,//RT_VSIZET
        R_SCRIPT,//RT_SCRIPT,
        R_NONE//RT_NONE
    };
    variant_type t{R_NONE};
    bool areIndicesIndicated{false};
//    std::vector<size_t> indices{};
    std::shared_ptr<NestedResultTable> fields{nullptr};
    size_t opt_offset{0};
    variant_type_cpp expectedType{RT_NONE};


    template<typename T> inline T getV(size_t i) const {
        return std::get<std::vector<T>>(content).at(i);
    }

    [[nodiscard]] inline size_t getInt(size_t i) const {
        if (expectedType == RT_SIZET)
            return std::get<size_t>(content);
        else if (expectedType == RT_VSIZET)
            return std::get<std::vector<size_t>>(content).at(i);
        else
            throw std::runtime_error("unexpected type at int");
    }

    bool containsInt(size_t val) const {
        if (expectedType == RT_SIZET)
            return std::get<size_t>(content) == val;
        else if (expectedType == RT_VSIZET)
            return std::find(std::get<std::vector<size_t>>(content).begin(),
                                      std::get<std::vector<size_t>>(content).end(), val) != std::get<std::vector<size_t>>(content).end();
        else
            return false;
    }

    [[nodiscard]] inline std::vector<gsm_object_xi_content> getContent(size_t i) const {
        if (expectedType == RT_CONTENT)
            return std::get<std::vector<gsm_object_xi_content>>(content);
        else if (expectedType == RT_VCONTENT)
            return std::get<std::vector<std::vector<gsm_object_xi_content>>>(content).at(i);
        else if (expectedType == RT_SIZET) {
            std::vector<gsm_object_xi_content> v;
            v.emplace_back(std::get<size_t>(content));
            return v;
        } else if (expectedType == RT_VSIZET) {
            std::vector<gsm_object_xi_content> v;
            v.emplace_back(std::get<std::vector<size_t>>(content).at(i));
            return v;
        }
        else
            throw std::runtime_error("unexpected type at content");
    }

    [[nodiscard]] inline const std::string& getString(size_t i) const {
        if (expectedType == RT_STRING)
            return std::get<std::string>(content);
        else if (expectedType == RT_VSTRING)
            return std::get<std::vector<std::string>>(content).at(i);
        else
            throw std::runtime_error("unexpected type at string");
    }

    template <typename T> const T& getT(size_t i) const {
        throw std::runtime_error("ERROR: Unexpected type!");
    }

    inline
    SimpleNestedResultTableValue get(size_t i) const {
        switch (expectedType) {
            case RT_STRING:
                return std::get<std::string>(content);

            case RT_VSTRING: {
                const auto& V = std::get<std::vector<std::string>>(content);
                return (V.size() > i) ? V.at(i) : "";
            }

            case RT_SIZET: {
                return std::get<size_t>(content);
            }

            case RT_VSIZET:{
                const auto& V = std::get<std::vector<size_t>>(content);
                return (V.size() > i) ? V.at(i) : -1;
            }

            case RT_CONTENT: {
                return std::get<std::vector<gsm_object_xi_content>>(content);
            }

            case RT_VCONTENT: {
                const auto& V = std::get<std::vector<std::vector<gsm_object_xi_content>>>(content);
                return (V.size() > i) ? V.at(i) : std::vector<gsm_object_xi_content>{};
            }

            case RT_SCRIPT:
            case RT_NONE:
                throw std::runtime_error("Cannot cast a script");
        }
    }

    inline
    OrderedSet compare(const struct NestedResultTable& x, ComparisonForNestedResultTable cmp ) const {
        size_t N = std::max(size(), x.size());
        roaring::Roaring64Map result;
        for (size_t i = 0; i<N; i++) {
            switch(cmp) {
                case CFNRT_EQ:
                    if ((get(i) == x.get(i))) result.add(i);
                    break;
                case CFNRT_NEQ:
                    if ((get(i) != x.get(i))) result.add(i);
                    break;
                case CFNRT_LT:
                    if ((get(i) < x.get(i)))result.add(i);
                    break;
                case CFNRT_LEQ:
                    if ((get(i) <= x.get(i)))result.add(i);
                    break;
            }
        }
        return {std::move(result),N};
    }


    DEFAULT_COPY_ASSGN(NestedResultTable);

    NestedResultTable()
            : areIndicesIndicated{false}, t{R_NONE}, content{(size_t) 0}, column{-1},
              cell_nested_morphism{-1}, expectedType{RT_NONE} {}

    NestedResultTable(size_t index, bool node_or_edge_otherwise, ssize_t cnm = -1, ssize_t c = -1)
            : cell_nested_morphism{cnm}, column{c}, content(index), t{node_or_edge_otherwise ? R_NODE : R_EDGE},
              expectedType{RT_SIZET}, areIndicesIndicated{false} {}

    NestedResultTable(size_t index, variant_type node_or_edge_otherwise, ssize_t cnm = -1, ssize_t c = -1)
            : cell_nested_morphism{cnm}, column{c}, content(index), t{node_or_edge_otherwise},
              expectedType{RT_SIZET}, areIndicesIndicated{false} {}

    NestedResultTable(const std::string &index, ssize_t cnm = -1, ssize_t c = -1) : cell_nested_morphism{cnm},
                                                                                    column{c}, content(index),
                                                                                    t{R_LABEL}, expectedType{RT_STRING},
                                                                                    areIndicesIndicated{false} {}

    NestedResultTable(const std::vector<std::string> &index, ssize_t cnm = -1, ssize_t c = -1) : cell_nested_morphism{
            cnm}, column{c}, content(index), t{R_NESTED_LABEL}, expectedType{RT_VSTRING}, areIndicesIndicated{false} {}

//    NestedResultTable(const std::vector<std::string> &index, ssize_t cnm = -1, ssize_t c = -1) : cell_nested_morphism{cnm},
//                                                                                            column{c}, content(index),
//                                                                                            t{R_NESTED_LABEL},expectedType{RT_VSTRING},
//                                                                                            areIndicesIndicated{
//                                                                                                    false} {}

    NestedResultTable(const std::vector<size_t> &index, bool node_or_edge_otherwise, ssize_t cnm = -1, ssize_t c = -1)
            : cell_nested_morphism{cnm}, column{c}, content(index), expectedType{RT_VSIZET},
              t{node_or_edge_otherwise ? R_NESTED_NODE : R_NESTED_EDGE}, areIndicesIndicated{false} {}

    NestedResultTable(const std::vector<size_t> &index, variant_type node_or_edge_otherwise, ssize_t cnm = -1,
                      ssize_t c = -1) : cell_nested_morphism{cnm}, column{c}, content(index), t{node_or_edge_otherwise},
                                        areIndicesIndicated{false}, expectedType{RT_VSIZET} {}

    NestedResultTable(const std::vector<gsm_object_xi_content> &index, ssize_t cnm = -1, ssize_t c = -1)
            : cell_nested_morphism{cnm}, column{c}, content(index), t{R_CONTENT}, areIndicesIndicated{false}, expectedType{RT_CONTENT} {}

    NestedResultTable(const std::vector<std::vector<gsm_object_xi_content>> &index, ssize_t cnm = -1, ssize_t c = -1)
            : cell_nested_morphism{cnm}, column{c}, content(index), t{R_NESTED_CONTENT}, areIndicesIndicated{false}, expectedType{RT_VCONTENT} {}

    NestedResultTable(std::shared_ptr<script::structures::ScriptAST> &&index, ssize_t cnm = -1, ssize_t c = -1)
            : cell_nested_morphism{cnm}, column{c}, content(index), t{R_SCRIPT}, areIndicesIndicated{false}, expectedType{RT_SCRIPT} {}


    size_t size() const {
        switch (t) {
            case R_LABEL:
            case R_NODE:
            case R_EDGE:
            case R_EDGE_SRC:
            case R_DO_EDGE_SRC:
            case R_EDGE_DST:
            case R_DO_EDGE_DST:
            case R_PROP:
            case R_XI:
            case R_DO_XI:
            case R_CONTENT: //  std::vector<gsm_object_xi_content>
            case R_ELL:
            case R_DO_ELL:
            case R_EDGE_LABEL:
            case R_DO_EDGE_LABEL:
            case R_DO_CONTENT:
            case R_DO_PROP:
                return 1;

            case R_NESTED_LABEL:
            case R_NESTED_PROP:
            case R_NESTED_XI:
            case R_NESTED_ELL:
            case R_NESTED_EDGE_LABEL:
                return std::get<std::vector<std::string>>(content).size();

            case R_NESTED_NODE:
            case R_NESTED_EDGE:
            case R_NESTD_EDGE_SRC:
            case R_DO_NESTED_EDGE_SRC:
            case R_NESTED_EDGE_DST:
            case R_DO_NESTED_EDGE_DST:
            case R_DO_NESTED_XI:
            case R_DO_NESTED_ELL:
            case R_DO_NESTED_EDGE_LABEL:
            case R_DO_NESTED_CONTENT:
            case R_DO_NESTED_PROP:
                return std::get<std::vector<size_t>>(content).size();

            case R_NESTED_CONTENT:
                return std::get<std::vector<std::vector<gsm_object_xi_content>>>(content).size();

            case R_SCRIPT:
                return 0;

            case R_NONE:
                return 0;
        }
    }
};


static inline NestedResultTable::variant_type_cpp getExpectedType(NestedResultTable::variant_type x) {
    switch (x) {
        case NestedResultTable::R_NODE:
        case NestedResultTable::R_EDGE:
        case NestedResultTable::R_EDGE_SRC:
        case NestedResultTable::R_EDGE_DST:
        case NestedResultTable::R_DO_EDGE_SRC:
        case NestedResultTable::R_DO_EDGE_DST:
            return NestedResultTable::RT_SIZET;

        case NestedResultTable::R_NESTED_NODE:
        case NestedResultTable::R_NESTED_EDGE:
        case NestedResultTable::R_NESTD_EDGE_SRC:
        case NestedResultTable::R_DO_NESTED_EDGE_SRC:
        case NestedResultTable::R_NESTED_EDGE_DST:
        case NestedResultTable::R_DO_NESTED_EDGE_DST:
            return NestedResultTable::RT_VSIZET;

        case NestedResultTable::R_CONTENT:
        case NestedResultTable::R_DO_CONTENT:
            return NestedResultTable::RT_CONTENT;

        case NestedResultTable::R_NESTED_CONTENT:
        case NestedResultTable::R_DO_NESTED_CONTENT:
            return NestedResultTable::RT_VCONTENT;

        case NestedResultTable::R_NESTED_PROP:
        case NestedResultTable::R_NESTED_ELL:
        case NestedResultTable::R_NESTED_XI:
        case NestedResultTable::R_NESTED_EDGE_LABEL:
        case NestedResultTable::R_DO_NESTED_ELL:
        case NestedResultTable::R_DO_NESTED_XI:
        case NestedResultTable::R_DO_NESTED_EDGE_LABEL:
        case NestedResultTable::R_DO_NESTED_PROP:
        case NestedResultTable::R_NESTED_LABEL:
            return NestedResultTable::RT_VSTRING;

        case NestedResultTable::R_DO_ELL:
        case NestedResultTable::R_DO_XI:
        case NestedResultTable::R_DO_EDGE_LABEL:
        case NestedResultTable::R_DO_PROP:
        case NestedResultTable::R_LABEL:
        case NestedResultTable::R_PROP:
        case NestedResultTable::R_XI:
        case NestedResultTable::R_ELL:
        case NestedResultTable::R_EDGE_LABEL:
            return NestedResultTable::RT_STRING;

        case NestedResultTable::R_SCRIPT:
            return NestedResultTable::RT_SCRIPT;
        case NestedResultTable::R_NONE:
            return NestedResultTable::RT_NONE;
    }
}



#endif //GSM2_NESTEDRESULTTABLE_H
