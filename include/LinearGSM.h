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
#include <gsm_indices.h>

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
            size_t nGraphs = 0;
            yaucl::structures::any_to_uint_bimap<std::string> label_map;
            std::unordered_map<std::string, PhiTable> containment_tables;
            std::unordered_map<std::string, AttributeTable> KeyValueContainment;
            FuzzyMatchSerializer ell_values, xi_values;
            ActivityTable                main_registry;
            std::vector<gsm_db_indices> all_indices; // index associated to each graph

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
             * @param removed   Whether the matched elements should be removed in the final result or not
             * @return      Events with the given activity label and score
             */
            std::vector<result> timed_dataless_exists(const std::string &act, bool removed) const;

            /**
             * Returns the approximate match over the strings for the given value
             * @param min_threshold     Minimum match threshold
             * @param nmax              Maximum number of scores
             * @param xi                String to match
             * @param removed   Whether the matched elements should be removed in the final result or not
             * @return  Objects in graph matching this
             */
            std::vector<result> approx_value_query(double min_threshold, size_t nmax, const std::string& xi, bool removed) const;

            /**
             * Returns the approximate match over the strings for the given label value
             * @param min_threshold     Minimum match threshold
             * @param nmax              Maximum number of scores
             * @param xi                String to match
             * @param removed   Whether the matched elements should be removed in the final result or not
             * @return  Objects in graph matching this
             */
            std::vector<result> approx_label_query(double min_threshold, size_t nmax, const std::string& xi, bool removed) const;


            /**
             * Returns all the objects being contained (container_containementOth=false) or containing (container_containementOth=true)
             * objects, where the former is associated to a container_object_label and contains the latter
             *
             * @param container_object_label        Activity labels associated to the container object
             * @param phi_label                     Containment label associated to the containment function
             * @param container_containementOth     Whether to return the object containing or the objects being contained
             * @param removed   Whether the matched elements should be removed in the final result or not
             * @return
             */
            std::vector<result> query_container_or_containment(const std::string& container_object_label,
                                                               const std::string& phi_label,
                                                               std::function<double(const std::vector<double>&)> aggregate_scores,
                                                               bool removed,
                                                               bool container_containementOth = false) const;

            /**
             * Returning the labels associated to the object
             * @param object    Graph and object association
             * @return  Labels associated to the object
             */
            inline const std::vector<std::string>& ell(const result& object) const {
                return ell_values.resolve_object_id({object.graphid, object.eventid});
            }

            /**
             * Returning the values associated to the object
             * @param object    Graph and object association
             * @return  Labels associated to the object
             */
            inline const std::vector<std::string>& xi(const result& object) const {
                return xi_values.resolve_object_id({object.graphid, object.eventid});
            }


            /**
             * Returning all the contained objects by the specified object
             * @param object
             * @return
             */
            inline std::vector<result> phi_all_records(const result&object, bool removed) const {
                std::vector<result> result;
                const auto& labels = ell(object);
                ssize_t act_label = labels.empty() ? getMappedValueFromAction("") : getMappedValueFromAction(labels.at(0));
                for (const auto& [k,v] : containment_tables) {
                    auto it2 = v.primary_index.find(act_label);
                    if (it2 == v.primary_index.end())
                        continue;
                    auto iterator = it2->second;
                    iterator.second++;
                    for (; iterator.first != iterator.second; iterator.first++) {
                        result
                                .emplace_back(iterator.first->graph_id,iterator.first->id_contained,iterator.first->w_contained, removed);
                    }
                }
                std::sort(result.begin(), result.end());
                return result;
            }

            /**
             * Returns all the containment labels assocaited to the given object
             * @param object
             * @return
             */
            inline std::vector<std::string> phi_labels(const result&object) const {
                std::vector<std::string> result;
                const auto& labels = ell(object);
                ssize_t act_label = labels.empty() ? getMappedValueFromAction("") : getMappedValueFromAction(labels.at(0));
                for (const auto& [k,v] : containment_tables) {
                    auto it2 = v.primary_index.find(act_label);
                    if (it2 == v.primary_index.end())
                        continue;
                    result.emplace_back(k);
                }
                return result;
            }

            /**
             * Specifies the containment function for a specific object
             * @param object        Container object
             * @param label_phi     Containment label (phi(k, object))
             * @param removed       Whether the containments shall be removed
             * @return Contained obejcts
             */
            inline std::vector<result> phi(const result&object, std::string& label_phi, bool removed) const {
                std::vector<result> result;
                auto it = containment_tables.find(label_phi);
                if (it == containment_tables.end())
                    return result;
                const auto& labels = ell(object);
                ssize_t act_label = labels.empty() ? getMappedValueFromAction("") : getMappedValueFromAction(labels.at(0));
                auto it2 = it->second.primary_index.find(act_label);
                if (it2 == it->second.primary_index.end())
                    return result;
                auto iterator = it2->second;
                iterator.second++;
                for (; iterator.first != iterator.second; iterator.first++) {
                    result
                            .emplace_back(iterator.first->graph_id,iterator.first->id_contained,iterator.first->w_contained, removed);
                }
                std::sort(result.begin(), result.end());
                return result;
            }

            /**
             * This returns a map associating the containers to the contents across multiple graphs
             * @param container_object_label
             * @param phi_label
             * @param aggregate_scores
             * @param removed   Whether the matched elements should be removed in the final result or not
             * @return
             */
            std::unordered_map<std::pair<size_t,size_t>,std::vector<result>> query_container_or_containment(const std::string &container_object_label,
                                                                          const std::string &phi_label,
                                                                          bool removed) const;
        };

        void primary_memory_load_gsm2(const std::filesystem::path& path, gsm2::tables::LinearGSM& db);
    } // gsm2
} // structures

#endif //GSM2_LINEARGSM_H
