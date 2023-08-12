//
// Created by giacomo on 28/05/23.
//

#ifndef GSM2_LINEARGSM_H
#define GSM2_LINEARGSM_H

#include "SimplifiedFuzzyStringMatching.h"
#include "PhiTable.h"
#include "AttributeTable.h"
#include "ActivityTable.h"
#include <filesystem>
#include <ostream>
#include <result.h>

template <typename Iterator, typename Key, typename Value>
std::map<Key, std::vector<Value>> GroupByKeyExtractor(Iterator begin, Iterator end, std::function<Key(const Value&)> keyExtractor)
{
    DEBUG_ASSERT(std::is_sorted(begin, end));
    std::map<Key, std::vector<Value>> groups;
    decltype(end) upper;

    for(auto lower = begin; lower != end; lower = upper)
    {
        Key k = keyExtractor(*lower);

        // get the upper position of all elements with the same ID
        upper = std::upper_bound(begin, end,  *lower,[keyExtractor](const Value& x, const Value& y) { return keyExtractor(x) < keyExtractor(y); });

        // add those elements as a group to the output vector
        groups[k] = {lower, upper};
    }

    return groups;
}

namespace std {
    template <> struct hash<result> {
        size_t operator()(const result& x ) const {
            return x.graphid ^ x.eventid;
        }
    };
}

namespace gsm2 {
    namespace tables {
        struct LinearGSM {
            yaucl::structures::any_to_uint_bimap<std::string> label_map;
            std::unordered_map<std::string, PhiTable> containment_tables;
            std::unordered_map<std::string, AttributeTable> KeyValueContainment;
            FuzzyMatchSerializer ell_values, xi_values; //TODO: proper version, with multiple values associated to the string!
            ActivityTable                main_registry;

            void clear();
            void index();

            inline ssize_t getMappedValueFromAction(const std::string &act) const {
                try{
                    return label_map.get(act);
                }
                catch(const std::exception& e){
                    return -1;
                }
            }

            /**
             * Returns all the records associated to a given first label. Records not being associated to an activity
             * label are associated to an empty one
             *
             * @param act       Activity Label
             * @return      Events with the given activity label and score
             */
            std::vector<result> timed_dataless_exists(const std::string &act) const;

            /**
             * Returns the approximate match over the strings for the given value
             * @param min_threshold     Minimum match threshold
             * @param nmax              Maximum number of scores
             * @param xi                String to match
             * @return  Objects in graph matching this
             */
            std::vector<result> approx_value_query(double min_threshold, size_t nmax, const std::string& xi) const;

            /**
             * Returns the approximate match over the strings for the given label value
             * @param min_threshold     Minimum match threshold
             * @param nmax              Maximum number of scores
             * @param xi                String to match
             * @return  Objects in graph matching this
             */
            std::vector<result> approx_label_query(double min_threshold, size_t nmax, const std::string& xi) const;


            /**
             * Returns all the objects being contained (container_containementOth=false) or containing (container_containementOth=true)
             * objects, where the former is associated to a container_object_label and contains the latter
             *
             * @param container_object_label        Activity labels associated to the container object
             * @param phi_label                     Containment label associated to the containment function
             * @param container_containementOth     Whether to return the object containing or the objects being contained
             * @return
             */
            std::vector<result> query_container_or_containment(const std::string& container_object_label,
                                                               const std::string& phi_label,
                                                               std::function<double(const std::vector<double>&)> aggregate_scores,
                                                               bool container_containementOth = false) const;
        };

        void primary_memory_load_gsm2(const std::filesystem::path& path, gsm2::tables::LinearGSM& db);
    } // gsm2
} // structures

#endif //GSM2_LINEARGSM_H
