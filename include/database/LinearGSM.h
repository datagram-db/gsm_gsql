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

            std::vector<gsm_object_xi_content> resolveContent(size_t graphid,
                                                                size_t id,
                                                                const std::string& key_content) const {
                auto it = (containment_tables.find(key_content));
                if (it == containment_tables.end())
                    return empty_containment;
                std::vector<gsm_object_xi_content> result;
                auto it3 = it->second.secondary_index.find({graphid, id});
                if (it3 == it->second.secondary_index.end())
                    return empty_containment;
                else for (const auto& record : it3->second) {
                        result.emplace_back(record->id_contained, record->w_contained);
                }
//
//                auto it2 = it->second.primary_index.find(label_map.get(ell(graphid,id).at(0)));
//                if (it2 == it->second.primary_index.end())
//                    return empty_containment;
//                auto cp = it2->second;
//                for (; cp.first != (cp.second+1); cp.first++) {
//                    if ((cp.first->graph_id == graphid) && (cp.first->object_id==id)) {
//                        result.emplace_back(cp.first->id_contained, cp.first->w_contained);
//                    }
//                }
                return result;
            }

            std::optional<union_minimal> resolveProperties(size_t graph_id, size_t node_id, const std::string& key_prop) const {
                auto it = KeyValueContainment.find(key_prop);
                if (it == KeyValueContainment.end())
                    return {};
                size_t i, N;
                auto it3= it->second.secondary_index2.find({graph_id,node_id});
                if (it3 !=it->second.secondary_index2.end() ) {
                    return resolveUnionMinimal(it->second, it->second.table.at(it3->second));
                }
//                std::tie(i, N) = it->second.primary_index.at(label_map.get(ell(graph_id,node_id).at(0)));
//                for (; i<N; i++) {
//                    const auto& record = main_registry.table.at(it->second.table.at(i).act_table_offset);
//                    if ((record.graph_id == graph_id) && (record.event_id == node_id)) {
//                        return (it->second.resolve_record_if_exists2(i));
//                    }
//                }
                return {};
            }

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

            const std::vector<std::string>& objectRelationships() const {
                return label_map.int_to_T;
            }

            const std::unordered_set<std::string>& containmentRelationships() const {
                return containment_relationships;
            }


            void iterateOverObjects(const std::function<void(size_t, const gsm_object&)>& f) {
                std::pair<size_t, size_t> cp;
                size_t offsetMainRegistryTable = 0;
                for (const auto& record : main_registry.table) {
                    gsm_object legacy_obj;
                    cp.first = record.graph_id;
                    cp.second = legacy_obj.id = record.event_id;
                    legacy_obj.ell = ell(cp.first, cp.second);
                    legacy_obj.xi = xi(cp.first, cp.second);
                    for (const auto& [keyAttribute, Table] : KeyValueContainment) {
                        auto tmp2 = Table.resolve_record_if_exists2(offsetMainRegistryTable);
                        if (tmp2) {
                            legacy_obj.content[keyAttribute] = (std::holds_alternative <std::string>(tmp2.value()) ? std::get<std::string>(tmp2.value()) : std::to_string(std::get<double>(tmp2.value())));
                        }
                    }
                    for (const auto& [keyAttribute, Table] : containment_tables) {
                        auto it = Table.secondary_index.find(cp);
                        if (it != Table.secondary_index.end()) {
                            for (const auto& record2 : it->second)
                                legacy_obj.phi[keyAttribute].emplace_back(record2->id_contained, record2->w_contained);
                        }
                    }
                    f(cp.first, legacy_obj);
                    offsetMainRegistryTable++;
                }
            }

            void asGraphs(std::vector<FlexibleGraph<std::string,std::string>>& simpleGraphs) const {
                simpleGraphs.clear();
                simpleGraphs.resize(all_indices.size());
                std::pair<size_t, size_t> cp;
                std::vector<yaucl::structures::any_to_uint_bimap<size_t>> nodesBeingInsertedAlready(all_indices.size());
                size_t offsetMainRegistryTable = 0;
                for (const auto& record : main_registry.table) {
                    cp.first = record.graph_id;
                    cp.second = record.event_id;
                    auto& nodeMap = nodesBeingInsertedAlready[record.graph_id];
                    auto& g = simpleGraphs[record.graph_id];
                    size_t id = nodeMap.put(record.event_id).first;
                    const auto& xis = xi_values.resolve_object_id(cp);
                    size_t gid;
                    std::string tmp;
                    if (xis.empty())
                        // If no content exists, using the first label, which should exist
                        tmp = ""+label_map.getValue(record.l0_id)+"="+std::to_string(record.event_id)+"";
                    else
                        // Otherwise, using the first value
                        tmp = xis.at(0)+"="+std::to_string(record.event_id);
                    for (const auto& [keyAttribute, Table] : KeyValueContainment) {
                        auto tmp2 = Table.resolve_record_if_exists2(offsetMainRegistryTable);
                        if (tmp2) {
                            tmp = tmp+"|"+keyAttribute+"="+(std::holds_alternative <std::string>(tmp2.value()) ? std::get<std::string>(tmp2.value()) : std::to_string(std::get<double>(tmp2.value())));
                        }
                    }
                    gid = g.addNewNodeWithLabel(tmp);
                    DEBUG_ASSERT(id == gid);
                    offsetMainRegistryTable++;
                }
                for (const auto& [edgeLabel, outEdges] : containment_tables) {
                    for (const auto& record : outEdges.table) {
                        const auto& map = nodesBeingInsertedAlready.at(record.graph_id);
                        auto src = map.getKey(record.object_id);
                        auto dst = map.getKey(record.id_contained);
                        auto& g = simpleGraphs[record.graph_id];
                        g.addNewEdgeFromId(src, dst, edgeLabel);
                    }
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
                                                  std::vector<std::pair<DataQuery, std::vector<result>>> &Qs) const {

//                bool doTemporalMatchQuery = temporalTimeMatch.has_value();
//                uint16_t isTemproalVal = temporalTimeMatch.value_or(0);
                auto it = KeyValueContainment.find(field_name);
                if (it == KeyValueContainment.end()) {
                    // if no attribute is there, for the exact match I assume that no value was matched
                    return;
                } else {
                    // The attribute exists within the dataset
                    std::vector<std::pair<size_t, std::vector<DataQuery*>>> V;
                    std::unordered_map<DataQuery*, size_t> qToItsId;
                    for (const auto& mapRef : ActNameToPredicates) {
                        std::pair<size_t, std::vector<DataQuery*>>& DQ = V.emplace_back(label_map.get(mapRef.first), std::vector<DataQuery*>{});
                        for (const auto& qId : mapRef.second) {
                            auto& prop = Qs.at(qId).first;
                            auto it2 = qToItsId.emplace(&prop, qId);
                            DEBUG_ASSERT(it2.second);
                            DQ.second.emplace_back(&prop);
                        }
                        // I do not need to compare the pointers, rather than compare the values associated to those
                        std::sort(DQ.second.begin(), DQ.second.end(), [](auto lhs, auto rhs) {return *lhs < *rhs;});
                    }

                    // TODO: this is just the concrete doing.
                    auto tmp = it->second.exact_range_query(V);

                    for (size_t i = 0, N = V.size(); i<N; i++) {
                        const auto& actIdToPropList = V.at(i);
                        auto v_actId = actIdToPropList.first;
                        auto& v_propList = actIdToPropList.second;
                        auto& tmpResult = tmp.at(i);
                        DEBUG_ASSERT(v_propList.size() == tmpResult.size()); // We return the result for each query
                        for (size_t j = 0, M = v_propList.size(); j<M; j++) {
                            auto& tmpRef = tmpResult.at(j);
                            if (!((tmpRef.first == tmpRef.second) && tmpRef.first == nullptr )) {
                                auto qPTr = v_propList.at(j);
                                auto qId = qToItsId.at(qPTr);
                                auto& refQ = Qs.at(qId);
                                DEBUG_ASSERT(refQ.first == *qPTr); // They are the same query
//                    LeafType qT = refQ.first.t;

                                auto& S = refQ.second;
                                size_t Nx = std::distance(tmpRef.first, tmpRef.second);
                                for (size_t k = 0; i<=Nx; k++) {
                                    const auto& exactIt = tmpRef.first[k];
                                    const auto& resolve = main_registry.table.at(exactIt.act_table_offset);
// TODO: for the approximate match, in the later future
//                        bool doInsert = true;
//                        float satisfiability = 1.0;
//                        if (doTemporalMatchQuery) {
//                            auto L = resolve.event_id;
//                            satisfiability = getSatisifiabilityBetweenValues(((L <= 1) ? 0 : isTemproalVal),
//                                                                             cast_to_float2(resolve.event_id,L), approxConstant);
//                            doInsert = satisfiability >= 1.0;
//                        }
//                        if (doInsert)
                                    S.emplace_back(resolve.graph_id, resolve.event_id,1.0);
                                }
                                std::sort(S.begin(), S.end());
                                S.erase(std::unique(S.begin(), S.end()), S.end());
                            }
                        }
                    }
                }
            }
        };

        void primary_memory_load_gsm2(const std::filesystem::path& path, gsm2::tables::LinearGSM& db);
    } // gsm2
} // structures

#endif //GSM2_LINEARGSM_H
