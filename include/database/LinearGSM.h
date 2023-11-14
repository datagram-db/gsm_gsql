/*
 * LinearGSM.h
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
// Created by giacomo on 28/05/23.
//

#ifndef GSM2_LINEARGSM_H
#define GSM2_LINEARGSM_H

#include <database/SimplifiedFuzzyStringMatching.h>
#include <database/PhiTable.h>
#include <database/AttributeTable.h>
#include <database/ActivityTable.h>
#include <filesystem>
#include "gsm_object.h"

#include <ostream>
#include <result.h>
#include <database/gsm_indices.h>
#include <database/gsm_object_xi_content.h>
#include <yaucl/graphs/FlexibleGraph.h>

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
            std::unordered_set<std::string> containment_relationships;
            std::unordered_map<std::string, AttributeTable> KeyValueContainment;
            FuzzyMatchSerializer ell_values, xi_values;
            ActivityTable                main_registry;
            std::vector<gsm_db_indices> all_indices; // index associated to each graph
            std::vector<gsm_object_xi_content> empty_containment;
            std::vector<size_t> nodesInGraph;
            std::vector<std::vector<std::vector<double>>> objectScores;
            std::unordered_map<std::pair<size_t,size_t>, std::vector<double>> objectScoresLoading;
            bool doInitLoading{true};
            size_t noLabel{0};

            void loadGSMObject(size_t graphId,
                               std::unordered_map<std::string, gsm2::tables::AttributeTableType>& propertyname_to_type,
                               const struct gsm_object& object);

            /**
             * Returning the conent of a specific graph and object id associated to the key
             *
             * @param graph
             * @param object
             * @param key_content
             * @return
             */
            std::vector<gsm_object_xi_content> resolveContent(size_t graphid,
                                                                size_t object,
                                                                const std::string& key_content) const;


            /**
             * Returns the value associated to the key <key_prop> associated to the object in a specific graph
             *
             * @param graph
             * @param object
             * @param key_prop
             * @return
             */
            std::optional<union_minimal> resolveProperties(size_t graph, size_t object, const std::string& key_prop) const;

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

            inline const std::vector<std::string>& objectRelationships() const {
                return label_map.int_to_T;
            }

            inline const std::unordered_set<std::string>& containmentRelationships() const {
                return containment_relationships;
            }

            /**
             * Iterating over all the objects in the database
             *
             * @param f Iterator lambda function, accepting the graph id and the information associated to a single
             *          object represented as a legacy gsm object
             */
            void iterateOverObjects(const std::function<void(size_t, const gsm_object&)>& f);

            /**
             * Collecting the data as graph data structures, so to better visualise the data that was loaded
             *
             * @param simpleGraphs  Resulting collection of graphs
             */
            void asGraphs(std::vector<FlexibleGraph<std::string,std::string>>& simpleGraphs) const;

            /**
             * Returns all the records associated to a given first label. Records not being associated to an activity
             * label are associated to an empty one
             *
             * @param act       Activity Label
             * @param removed   Whether the matched elements should be removed in the final result or not
             * @return      Events with the given activity label and score
             */
            std::vector<result> timed_dataless_exists(const std::string &act) const;

            /**
             * Returns the approximate match over the strings for the given value
             * @param min_threshold     Minimum match threshold
             * @param nmax              Maximum number of scores
             * @param xi                String to match
             * @param removed   Whether the matched elements should be removed in the final result or not
             * @return  Objects in graph matching this
             */
            std::vector<result> approx_value_query(double min_threshold, size_t nmax, const std::string& xi) const;

            /**
             * Returns the approximate match over the strings for the given label value
             * @param min_threshold     Minimum match threshold
             * @param nmax              Maximum number of scores
             * @param xi                String to match
             * @param removed   Whether the matched elements should be removed in the final result or not
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
             * @param removed   Whether the matched elements should be removed in the final result or not
             * @return
             */
            std::vector<result> query_container_or_containment(const std::string& container_object_label,
                                                               const std::string& phi_label,
                                                               std::function<double(const std::vector<double>&)> aggregate_scores,
                                                               bool container_containementOth = false) const;

            /**
             * Returning the labels associated to the object
             * @param object    Graph and object association
             * @return  Labels associated to the object
             */
            inline const std::vector<std::string>& ell(const result& object) const {
                return ell_values.resolve_object_id({object.graphid, object.eventid});
            }

            inline const std::vector<std::string>& ell(size_t graphid, size_t eventid) const {
                return ell_values.resolve_object_id({graphid, eventid});
            }

            inline std::vector<std::string> resolveContainmentLabels(size_t graphid, size_t id) const {
                std::vector<std::string> result;
                std::pair<size_t,size_t>cp{graphid, id};
                for (const auto& [key, table] : containment_tables) {
                    if (table.secondary_index.find(cp)!= table.secondary_index.end())
                        result.emplace_back(key);
                }
                return result;
            }

            inline std::vector<std::string> resolvePropertyLabels(size_t graphid, size_t id ) const {
                std::pair<size_t,size_t>cp{graphid, id};
                std::vector<std::string> result;
                for (const auto& [key, table] : KeyValueContainment) {
                    if (table.secondary_index2.find(cp)!= table.secondary_index2.end())
                        result.emplace_back(key);
                }
                return result;
            }

           inline bool hasContent(size_t graphid, size_t id, const std::string &key_content) const {
                auto it = (containment_tables.find(key_content));
                if (it == containment_tables.end())
                    return false;
                std::vector<gsm_object_xi_content> result;
                auto it3 = it->second.secondary_index.find({graphid, id});
                if (it3 == it->second.secondary_index.end())
                    return false;
                else return true;
            }

            /**
             * Returning the values associated to the object
             * @param object    Graph and object association
             * @return  Labels associated to the object
             */
            inline const std::vector<std::string>& xi(const result& object) const {
                return xi_values.resolve_object_id({object.graphid, object.eventid});
            }

            inline const std::vector<std::string>& xi(size_t graphid, size_t eventid) const {
                return xi_values.resolve_object_id({graphid, eventid});
            }


//            /**
//             * Returning all the contained objects by the specified object
//             * @param object
//             * @return
//             */
//            inline std::vector<result> phi_all_records(const result&object) const {
//                std::vector<result> result;
//                const auto& labels = ell(object);
//                ssize_t act_label = labels.empty() ? getMappedValueFromAction("") : getMappedValueFromAction(labels.at(0));
//                for (const auto& [k,v] : containment_tables) {
//                    auto it2 = v.primary_index.find(act_label);
//                    if (it2 == v.primary_index.end())
//                        continue;
//                    auto iterator = it2->second;
//                    iterator.second++;
//                    for (; iterator.first != iterator.second; iterator.first++) {
//                        result
//                                .emplace_back(iterator.first->graph_id,iterator.first->id_contained,iterator.first->w_contained);
//                    }
//                }
//                std::sort(result.begin(), result.end());
//                return result;
//            }

//            /**
//             * Returns all the containment labels assocaited to the given object
//             * @param object
//             * @return
//             */
//            inline std::vector<std::string> phi_labels(const result&object) const {
//                std::vector<std::string> result;
//                const auto& labels = ell(object);
//                ssize_t act_label = labels.empty() ? getMappedValueFromAction("") : getMappedValueFromAction(labels.at(0));
//                for (const auto& [k,v] : containment_tables) {
//                    auto it2 = v.primary_index.find(act_label);
//                    if (it2 == v.primary_index.end())
//                        continue;
//                    result.emplace_back(k);
//                }
//                return result;
//            }
//            /**
//             * Specifies the containment function for a specific object
//             * @param object        Container object
//             * @param label_phi     Containment label (phi(k, object))
//             * @param removed       Whether the containments shall be removed
//             * @return Contained obejcts
//             */
//            inline std::vector<result> phi(const result&object, const std::string& label_phi) const {
//                std::vector<result> result;
//                auto it = containment_tables.find(label_phi);
//                if (it == containment_tables.end())
//                    return result;
//                const auto& labels = ell(object);
//                ssize_t act_label = labels.empty() ? getMappedValueFromAction("") : getMappedValueFromAction(labels.at(0));
//                auto it2 = it->second.primary_index.find(act_label);
//                if (it2 == it->second.primary_index.end())
//                    return result;
//                auto iterator = it2->second;
//                iterator.second++;
//                for (; iterator.first != iterator.second; iterator.first++) {
//                    result
//                            .emplace_back(iterator.first->graph_id,iterator.first->id_contained,iterator.first->w_contained);
//                }
//                std::sort(result.begin(), result.end());
//                return result;
//            }

            /**
             * This returns a map associating the containers to the contents across multiple graphs
             * @param container_object_label
             * @param phi_label
             * @param aggregate_scores
             * @param removed   Whether the matched elements should be removed in the final result or not
             * @return
             */
            void query_container_or_containment(std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& result,
                                                                                                            const std::string &container_object_label,
                                                                                                            const std::string &phi_label,
                                                                                                            bool container_containementOth = false) const;


            /**
             * Performing range/propertyValue queries over the nodes
             * @param field_name
             * @param ActNameToPredicates
             * @param Qs
             */
            void exact_range_query(const std::string &field_name,
                                                  const std::unordered_map<std::string, std::vector<size_t>> &ActNameToPredicates,
                                                  std::vector<std::pair<DataQuery, std::vector<result>>> &Qs) const;
        };

        /**
         * Loading the file representing multiple GSM databases into a single database db
         *
         * @param path
         * @param db
         */
        std::pair<double,double> primary_memory_load_gsm2(const std::filesystem::path& path, gsm2::tables::LinearGSM& db);
    } // gsm2
} // structures

#endif //GSM2_LINEARGSM_H
