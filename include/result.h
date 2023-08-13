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
    double score;

    result(size_t g, size_t e, double d) : graphid{g}, eventid{e}, score{d}{};
    result(size_t g, size_t e) : graphid{g}, eventid{e}, score{1.0} {};
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
                          std::vector<result>& out,
                          std::function<double(double,double)>& combination) {
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
            out.emplace_back(first1->graphid, first1->eventid, combination(first1->score, first2->score));
            first1++;
            first2++;
        }
    }
    std::copy(first2, last2, std::back_inserter(out));
}

static
inline void result_intersection(const std::vector<result>& lhs,
                         const std::vector<result>& rhs,
                         std::vector<result>& out,
                         std::function<double(double,double)>& combination) {
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
            out.emplace_back(first1->graphid, first1->eventid, combination(first1->score, first2->score));
            first1++;
            first2++;
        }
    }
    std::copy(first2, last2, std::back_inserter(out));
}

#endif //GSM2_RESULT_H
