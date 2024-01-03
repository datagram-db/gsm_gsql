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

#include "parsing.h"

namespace gsm2 {
    namespace tables {

        struct LinearGSM {
            size_t nGraphs = 0;
            std::map<size_t, std::string> minRecordToContaimentLabel;
            const std::string noLabelStr;
            yaucl::structures::any_to_uint_bimap<std::string> label_map;
            std::unordered_map<std::string, PhiTable> containment_tables;
            std::unordered_set<std::string> containment_relationships;
            std::unordered_map<std::string, AttributeTable> KeyValueProperties;
            FuzzyMatchSerializer ell_values, xi_values;
            ActivityTable                main_registry;
            std::vector<gsm_db_indices> all_indices; // index associated to each graph
            std::vector<gsm_object_xi_content> empty_containment;
            std::vector<size_t> nodesInGraph;
            std::vector<std::vector<std::vector<double>>> objectScores;
            std::unordered_map<std::pair<size_t,size_t>, std::vector<double>> objectScoresLoading;
            bool doInitLoading{true};
            size_t noLabel{0};

            const std::map<size_t, std::string>::const_iterator findLabelFromID(size_t k) const {
                DEBUG_ASSERT(minRecordToContaimentLabel.begin()->first == 0);
                auto it = minRecordToContaimentLabel.lower_bound(k);
                if (it->first>k) it--;
                return it;
            }
            const std::map<size_t, std::string>::const_iterator notALabel() const {
                return minRecordToContaimentLabel.end();
            }
            const gsm2::tables::PhiTable::record* resolveRecord(size_t k) const {
                DEBUG_ASSERT(minRecordToContaimentLabel.begin()->first == 0);
                auto it = minRecordToContaimentLabel.lower_bound(k);
                if (it->first>k) it--;
                return &containment_tables.at(it->second).table.at(k-it->first);
            }

            void asObjects(std::vector<std::vector<gsm_object>> &simpleGraphs) const {
                simpleGraphs.clear();
                simpleGraphs.resize(all_indices.size());
                for(size_t i = 0, N = all_indices.size(); i<N; i++) {
                    simpleGraphs[i].resize(nodesInGraph.at(i));
                }
                std::pair<size_t, size_t> cp;
                std::vector<yaucl::structures::any_to_uint_bimap<size_t>> nodesBeingInsertedAlready(all_indices.size());
                size_t offsetMainRegistryTable = 0;
                for (const auto& record : main_registry.table) {
                    cp.first = record.graph_id;
                    cp.second = record.event_id;
                    auto& nodeMap = nodesBeingInsertedAlready[record.graph_id];
                    auto& g = simpleGraphs[record.graph_id];
                    size_t id = nodeMap.put(record.event_id).first;
                    gsm_object& result = simpleGraphs[record.graph_id][record.event_id];
                    result.id = record.event_id;
                    result.xi = xi_values.resolve_object_id(cp);
                    result.ell = ell_values.resolve_object_id(cp);
//                    size_t gid;
                    for (const auto& [keyAttribute, Table] : KeyValueProperties) {
                        auto tmp2 = Table.resolve_record_if_exists2(offsetMainRegistryTable);
                        if (tmp2) {
                            result.content[keyAttribute] = tmp2.value();
//                            tmp = tmp+"|"+keyAttribute+"="+(std::holds_alternative <std::string>(tmp2.value()) ? std::get<std::string>(tmp2.value()) : std::to_string(std::get<double>(tmp2.value())));
                        }
                    }
//                    gid = g.addNewNodeWithLabel(tmp);
//                    DEBUG_ASSERT(id == gid);
                    offsetMainRegistryTable++;
                }
                for (const auto& [edgeLabel, outEdges] : containment_tables) {
                    for (const auto& record : outEdges.table) {
                        const auto& map = nodesBeingInsertedAlready.at(record.graph_id);
                        gsm_object& result = simpleGraphs[record.graph_id][record.object_id];
                        result.phi[edgeLabel].emplace_back(record.id_contained);
//                        auto src = map.getKey(record.object_id);
//                        auto dst = map.getKey(record.id_contained);
//                        auto& g = simpleGraphs[record.graph_id];
//                        g.addNewEdgeFromId(src, dst, edgeLabel);
                    }
                }
            }


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
//                std::pair<size_t,size_t>cp{graphid, id};
                for (const auto& [key, table] : containment_tables) {
                    auto it = table.secondary_index.find(graphid);
                    if (table.secondary_index.find(graphid)!= table.secondary_index.end()) {
                        if (it->second.find(id) != it->second.end()) {
                            result.emplace_back(key);
                        }
                    }
                }
                return result;
            }

            inline std::vector<std::string> resolvePropertyLabels(size_t graphid, size_t id ) const {
                std::pair<size_t,size_t>cp{graphid, id};
                std::vector<std::string> result;
                for (const auto& [key, table] : KeyValueProperties) {
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
                auto it3 = it->second.secondary_index.find(graphid);
                if (it3 == it->second.secondary_index.end())
                    return false;
                else return it3->second.find(id) != it3->second.end();
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
         * @param path  File containing the serialised representation of the databases
         * @param db    Object where to load the databases
         * @return      The loading and indexing time
         */
        std::pair<double,double> primary_memory_load_gsm2(const std::filesystem::path& path, gsm2::tables::LinearGSM& db);

        /**
         * Direct loading of the GSM model from a collection of databases, where each database is a collection of objects
         *
         * @param db        Collection of databases
         * @param schema    Schema associated to each field type
         * @param target    Element where
         * @return          The loading and indexing time
         */
        std::pair<double,double> primary_memory_load_direct(std::vector<std::vector<gsm_object>>& db,
                const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& schema,
                gsm2::tables::LinearGSM& target);
    } // gsm2
} // structures




#include "yaucl/data/json.h"

static inline size_t loadObjectEll(gsm2::tables::LinearGSM &db,
                                   std::vector<std::string> &ell,
                                   size_t noLabel,
                                   const std::pair<size_t, size_t> &graphId_eventId) {
    size_t act_id;
    if (!ell.empty()) {
        // Sending to fuzzy ell match
        std::string pop = ell.front();
        ell.erase(ell.begin());
        db.ell_values.addGramsToMap(pop, graphId_eventId, ell);
        act_id = db.label_map.put(pop).first;
    } else {
        act_id = noLabel;
    }
    return act_id;
}

static inline size_t loadObjectEll2(gsm2::tables::LinearGSM &db,
                                    const std::vector<std::string> &ell,
                                    size_t noLabel,
                                    const std::pair<size_t, size_t> &graphId_eventId) {
    size_t act_id;
    if (!ell.empty()) {
        // Sending to fuzzy ell match
        std::string pop = ell.front();
        std::vector<std::string> rest{ell.begin()+1, ell.end()};
        db.ell_values.addGramsToMap(pop, graphId_eventId, rest);
        act_id = db.label_map.put(pop).first;
    } else {
        act_id = noLabel;
    }
    return act_id;
}

static inline void registerObjectByFirstLabel(gsm2::tables::LinearGSM &db,
                                              size_t act_id,
                                              const std::pair<size_t, size_t> &graphId_eventId) {
    // Setting up the new object
    db.main_registry.load_record(graphId_eventId.first, act_id, graphId_eventId.second);
}

static inline void loadObjectXi(gsm2::tables::LinearGSM &db, std::vector<std::string> &xi,
                                const std::pair<size_t, size_t> &graphId_eventId) {
    if (!xi.empty()) {
        // Sending to fuzzy xi match
        std::string front = xi[0];
        xi.erase(xi.begin());
        db.xi_values.addGramsToMap(front, graphId_eventId, xi);
    }
}

static inline void loadObjectXi2(gsm2::tables::LinearGSM &db, const std::vector<std::string> &xi,
                                 const std::pair<size_t, size_t> &graphId_eventId) {
    if (!xi.empty()) {
        // Sending to fuzzy xi match
        std::string front = xi[0];
        std::vector<std::string> rest{xi.begin()+1, xi.end()};
        db.xi_values.addGramsToMap(front, graphId_eventId, rest);
    }
}

static inline void loadObjectProperty(gsm2::tables::LinearGSM &db,
                                      const std::unordered_map<std::string, gsm2::tables::AttributeTableType> &property_to_type,
                                      size_t act_id,
                                      const std::pair<size_t, size_t> &graphId_eventId,
                                      const std::string &property_key,
                                      const std::string &property_value) {
    auto& table = db.KeyValueProperties[property_key];
    auto it = property_to_type.find(property_key);
    if (it != property_to_type.end())
        table.type = it->second;
    else
        table.type = gsm2::tables::StringAtt;
    switch (table.type) {
        case gsm2::tables::DoubleAtt:
            table.record_load(act_id, std::stod(property_value), graphId_eventId.first, graphId_eventId.second);
            break;
        case gsm2::tables::SizeTAtt:
            table.record_load(act_id, std::stoull(property_value), graphId_eventId.first, graphId_eventId.second);
            break;
        case gsm2::tables::LongAtt:
            table.record_load(act_id, std::stoll(property_value), graphId_eventId.first, graphId_eventId.second);
            break;
        case gsm2::tables::StringAtt:
            table.record_load(act_id, property_value, graphId_eventId.first, graphId_eventId.second);
            break;
        case gsm2::tables::BoolAtt:
            table.record_load(act_id, (property_value == "True" || property_value == "true" || property_value == "tt" || property_value == "t"), graphId_eventId.first, graphId_eventId.second);
            break;
    }
}

static inline void loadObjectProperty(gsm2::tables::LinearGSM &db,
                                      const std::unordered_map<std::string, gsm2::tables::AttributeTableType> &property_to_type,
                                      size_t act_id,
                                      const std::pair<size_t, size_t> &graphId_eventId,
                                      const std::string &property_key,
                                      const union_type &property_value) {
    auto& table = db.KeyValueProperties[property_key];
    auto it = property_to_type.find(property_key);
    if (it != property_to_type.end())
        table.type = it->second;
    else
        table.type = gsm2::tables::StringAtt;
    switch (table.type) {
        case gsm2::tables::DoubleAtt:
            if (std::holds_alternative<std::string>(property_value))
                table.record_load(act_id, std::stod(std::get<std::string>(property_value)), graphId_eventId.first, graphId_eventId.second);
            else if (std::holds_alternative<double>(property_value))
                table.record_load(act_id, (std::get<double>(property_value)), graphId_eventId.first, graphId_eventId.second);
            else
                throw std::runtime_error("Type mismatch: expecting " +property_key+" to have type: double");
            break;
        case gsm2::tables::SizeTAtt:
            if (std::holds_alternative<std::string>(property_value))
                table.record_load(act_id, std::stoull(std::get<std::string>(property_value)), graphId_eventId.first, graphId_eventId.second);
            else if (std::holds_alternative<size_t>(property_value))
                table.record_load(act_id, (std::get<size_t>(property_value)), graphId_eventId.first, graphId_eventId.second);
            else
                throw std::runtime_error("Type mismatch: expecting " +property_key+" to have type: stoull");
            break;
        case gsm2::tables::LongAtt:
            if (std::holds_alternative<std::string>(property_value))
                table.record_load(act_id, std::stoll(std::get<std::string>(property_value)), graphId_eventId.first, graphId_eventId.second);
            else if (std::holds_alternative<long long>(property_value))
                table.record_load(act_id, (std::get<long long>(property_value)), graphId_eventId.first, graphId_eventId.second);
            else
                throw std::runtime_error("Type mismatch: expecting " +property_key+" to have type: stoll");
            break;
        case gsm2::tables::StringAtt:
            table.record_load(act_id, property_value, graphId_eventId.first, graphId_eventId.second);
            break;
        case gsm2::tables::BoolAtt:
            if (std::holds_alternative<std::string>(property_value)) {
                const auto& actual = std::get<std::string>(property_value);
                table.record_load(act_id, (actual == "True" || actual == "true" || actual == "tt" || actual == "t"), graphId_eventId.first, graphId_eventId.second);
            } else if (std::holds_alternative<bool>(property_value)) {
                table.record_load(act_id, std::get<bool>(property_value), graphId_eventId.first, graphId_eventId.second);
            } else {
                throw std::runtime_error("Type mismatch: expecting " +property_key+" to have type: bool");
            }
            break;
    }
}


static inline size_t initLoading(gsm2::tables::LinearGSM &db) {
    if (db.doInitLoading) {
        size_t noLabel = db.noLabel = db.label_map.put("").first;
        size_t act_id = noLabel;
        db.doInitLoading = false;
        return noLabel;
    } else {
        return db.noLabel;
    }
}



#include <fstream>
#include "magic_enum.hpp"

static inline
void convertMap(const NodeLabelBijectionGraph<size_t, std::string>& map,
                std::unordered_map<size_t, std::vector<size_t>>& original) {
    std::unordered_map<size_t, std::vector<size_t>> final;
    for (const auto& [k, ls] : original) {
        auto newKey = k;
        auto& v = final[newKey];
        for (size_t x : ls) {
            v.emplace_back(map.getUniqueLabel(x));
        }
    }
    std::swap(final, original);
}

static inline void parse(char* string,
                         size_t len,
                         gsm2::tables::LinearGSM& forloading,
                         const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& map_for_types,
                         size_t& maxGraphId) {
    string = skipSpaces(string, &len);
//    size_t graphId = 0;
    std::vector<std::string> ell, xi;
    double weight; size_t content;
    size_t act_id;
    size_t noLabel = initLoading(forloading);
    int scanSkip = 0;
    constexpr char const * ID = "id:";
    constexpr char const  DOT = '.';
    constexpr char const * ELL = "ell:";
    constexpr char const * XI = "xi:";
    constexpr char const * PROP = "properties:";
    constexpr char const * PHI = "phi:";
//    size_t id;
    std::pair<size_t,size_t> graphId_eventId{0,0};
    // Defining a simple format to scan, so to avoid using a parser for this.
    while (string && *string) {
        // Reading a new object from the database for value querying
        graphId_eventId.second = 0;
        if (forloading.nodesInGraph.size() == graphId_eventId.first) {
            forloading.nodesInGraph.emplace_back(graphId_eventId.second);
        }
        ell.clear();
        if (!(string = haspos(string, (char*)ID, 0, &len))) return;
        if (sscanf(string, "%lu%n", &graphId_eventId.second, &scanSkip)==EOF) return;
        forloading.nodesInGraph[graphId_eventId.first] = std::max(forloading.nodesInGraph[graphId_eventId.first],graphId_eventId.second);
        len-=scanSkip;
        string+=scanSkip;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)ELL, 0, &len))) return;
        act_id = noLabel;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            ell.emplace_back(string, beforeReturn-1);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }

        act_id = loadObjectEll(forloading, ell, noLabel, graphId_eventId);//// HOC!

        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)XI, 0, &len))) return;
        registerObjectByFirstLabel(forloading, act_id, graphId_eventId); //// HOC!

        xi.clear();
        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            xi.emplace_back(string, beforeReturn-1);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
        loadObjectXi(forloading, xi, graphId_eventId);//// HOC!

        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)PROP, 0, &len))) return;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            std::string tmp{string, beforeReturn-1};
            size_t idx = tmp.find("\t");
            if (idx == std::string::npos) return;
            std::string key = UNESCAPE(tmp.substr(0, idx));
            std::string val = UNESCAPE(tmp.substr(idx+1));

            // Setting up the properties associated to the node
            loadObjectProperty(forloading, map_for_types, act_id, graphId_eventId, key, val);

            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)PHI, 0, &len))) return;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;

        forloading.objectScoresLoading[graphId_eventId].emplace_back(1.0);
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            std::string tmp{string, beforeReturn-1};
            tmp = UNESCAPE(tmp);
            string =beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
            while (*string != ';') {
                if (sscanf(string, "%lf\t%lu%n", &weight, &content,&scanSkip)==EOF) return;
                len-=scanSkip;
                string+=scanSkip;
                // Setting up the containment associated to the node
                forloading.containment_tables[tmp].add(act_id, graphId_eventId, weight, content);
                forloading.containment_relationships.emplace(tmp);
                if (!(string = skipSpaces(string, &len))) return;
            }
            string++;
            len--;
            if (!(string = skipSpaces(string, &len))) return;
        }
        string++;
        len--;
        if (!(string = skipSpaces(string, &len))) return;

        if (strncmp(string,"~~",2)==0) {
            // Finding a new graph
            forloading.nodesInGraph.emplace_back(0);
            graphId_eventId.first++; string+=2; len-=2;
            if (!(string = skipSpaces(string, &len))) return;
        }
    }
    maxGraphId = graphId_eventId.first;
}

static inline void parse(char* string,
                         size_t len,
                         std::vector<std::vector<gsm_object>>& db) {
    string = skipSpaces(string, &len);
//    size_t graphId = 0;
//    std::vector<std::string> ell, xi;
    double weight; size_t content;
    size_t act_id;
//    size_t noLabel = initLoading(forloading);
    int scanSkip = 0;
    constexpr char const * ID = "id:";
    constexpr char const  DOT = '.';
    constexpr char const * ELL = "ell:";
    constexpr char const * XI = "xi:";
    constexpr char const * PROP = "properties:";
    constexpr char const * PHI = "phi:";
//    size_t id;
//    std::pair<size_t,size_t> graphId_eventId{0,0};

    // Defining a simple format to scan, so to avoid using a parser for this.
    while (string && *string) {
        // Reading a new object from the database for value querying
        if (db.empty())
            db.emplace_back();
        auto& current = db.back().emplace_back();
        current.id = 0;
//        if (forloading.nodesInGraph.size() == graphId_eventId.first) {
//            forloading.nodesInGraph.emplace_back(graphId_eventId.second);
//        }
//        ell.clear();
        if (!(string = haspos(string, (char*)ID, 0, &len))) return;
        current.scores.clear();
        current.ell.clear();
        current.xi.clear();
        current.content.clear();
        current.phi.clear();
        if (sscanf(string, "%lu%n", &current.id, &scanSkip)==EOF) return;
//        forloading.nodesInGraph[graphId_eventId.first] = std::max(forloading.nodesInGraph[graphId_eventId.first],graphId_eventId.second);
        len-=scanSkip;
        string+=scanSkip;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)ELL, 0, &len))) return;
//        act_id = noLabel;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            current.ell.emplace_back(string, beforeReturn-1);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }


//        act_id = loadObjectEll(forloading, ell, noLabel, graphId_eventId);//// HOC!

        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)XI, 0, &len))) return;
//        registerObjectByFirstLabel(forloading, act_id, graphId_eventId); //// HOC!

//        xi.clear();
        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            current.xi.emplace_back(string, beforeReturn-1);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
//        loadObjectXi(forloading, xi, graphId_eventId);//// HOC!

        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)PROP, 0, &len))) return;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            std::string tmp{string, beforeReturn-1};
            size_t idx = tmp.find("\t");
            if (idx == std::string::npos) return;
            std::string key = UNESCAPE(tmp.substr(0, idx));
            std::string val = UNESCAPE(tmp.substr(idx+1));

            current.content[key] = val;
            // Setting up the properties associated to the node
//            loadObjectProperty(forloading, map_for_types, act_id, graphId_eventId, key, val);

            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)PHI, 0, &len))) return;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;

//        forloading.objectScoresLoading[graphId_eventId].emplace_back(1.0);
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            std::string tmp{string, beforeReturn-1};
            tmp = UNESCAPE(tmp);
            string =beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
            while (*string != ';') {
                if (sscanf(string, "%lf\t%lu%n", &weight, &content,&scanSkip)==EOF) return;
                len-=scanSkip;
                string+=scanSkip;
                // Setting up the containment associated to the node
                current.phi[tmp].emplace_back(content, weight);
//                forloading.containment_tables[tmp].add(act_id, graphId_eventId, weight, content);
//                forloading.containment_relationships.emplace(tmp);
                if (!(string = skipSpaces(string, &len))) return;
            }
            string++;
            len--;
            if (!(string = skipSpaces(string, &len))) return;
        }
        string++;
        len--;
        if (!(string = skipSpaces(string, &len))) return;


        if (strncmp(string,"~~",2)==0) {
            // Finding a new graph
            db.emplace_back();
            string+=2; len-=2;
            if (!(string = skipSpaces(string, &len))) return;
        }
    }
//    maxGraphId = graphId_eventId.first;
}

static inline void parse(const std::filesystem::path& file,
                         std::vector<std::vector<gsm_object>>& db) {
    std::string buffer;
    std::ifstream f(file);
    f.seekg(0, std::ios::end);
    size_t n = f.tellg();
    buffer.resize(f.tellg());
    f.seekg(0);
    f.read(buffer.data(), buffer.size());
    parse((char*)buffer.c_str(), n, db);
}

#endif //GSM2_LINEARGSM_H
