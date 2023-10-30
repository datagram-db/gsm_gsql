/*
 * LinearGSM.cpp
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

#include "database/LinearGSM.h"
extern "C" {
#include <string.h>
}
/**
 *  haspos()
 * Dato un campo di testo \a text dove deve essere cercato \a BASE dalla
 * posizione \a pos in \a text, restituisce -1 se BASE è inesistente dal primo
 * suo carattere, altrimenti la posizione successiva all'ultimo carattere in BASE.
 */
static inline char* haspos(char* text, char* BASE, int pos, size_t* len) {
    int i;
    for (i=0;i<strlen(BASE); i++)
        if ((!(text[pos+i]==BASE[i]))&&(!(BASE[i]=='\0'))) {
            *len=0;
            return nullptr;
        }
    *len -= (pos+1);
    return &text[pos+i];
}



/**
 *  atreturn()
 *
 * FUNZIONE DI PARSING/LEXING
 * --------------------------
 * Restituisce eventualmente il puntatore alla stringa dopo una andata a capo
 */
static inline char* atreturn(char* buf,size_t* len) {
    int  end=0;
    for (end=0; end<*len; end++)
        if (buf[end]=='\n') {
            *len -= (end+1);
            return &buf[end+1];
        }
    *len = 0;
    return nullptr;
}

static inline char* skipSpaces(char*buf, size_t* len ) {
    while (isspace(*buf) && (*len)) { buf++; (*len)--; }
    if (!(*len)) return nullptr;
    return buf;
}

#include "yaucl/data/json.h"
static inline void parse(char* string,
                         size_t len,
                         gsm2::tables::LinearGSM& forloading,
                         const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& map_for_types,
                         size_t& maxGraphId) {
    string = skipSpaces(string, &len);
//    size_t graphId = 0;
    std::vector<std::string> ell, xi;
    size_t noLabel = forloading.label_map.put("").first;
    double weight; size_t content;
    size_t act_id = noLabel;
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
        ell.clear();
        if (!(string = haspos(string, (char*)ID, 0, &len))) return;
        if (sscanf(string, "%lu%n", &graphId_eventId.second, &scanSkip)==EOF) return;
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
        if (!ell.empty()) {
            // Sending to fuzzy ell match
            std::string pop = ell.front();
            ell.erase(ell.begin());
            forloading.ell_values.addGramsToMap(pop, graphId_eventId, ell);
            act_id = forloading.label_map.put(pop).first;
        } else {
            act_id = noLabel;
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)XI, 0, &len))) return;
        // Setting up the new object
        forloading.main_registry.load_record(graphId_eventId.first, act_id, graphId_eventId.second);

        xi.clear();
        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != DOT) {
            char* beforeReturn = atreturn(string, &len);
            xi.emplace_back(string, beforeReturn-1);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
        if (!xi.empty()) {
            // Sending to fuzzy xi match
            forloading.xi_values.addGramsToMap(xi[0], graphId_eventId, xi);
        }
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
            auto& table = forloading.KeyValueContainment[key];
            auto it = map_for_types.find(key);
            if (it != map_for_types.end())
                table.type = it->second;
            else
                table.type = gsm2::tables::StringAtt;
            switch (table.type) {
                case gsm2::tables::DoubleAtt:
                    table.record_load(act_id, std::stod(val), graphId_eventId.first, graphId_eventId.second);
                    break;
                case gsm2::tables::SizeTAtt:
                    table.record_load(act_id, std::stoull(val), graphId_eventId.first, graphId_eventId.second);
                    break;
                case gsm2::tables::LongAtt:
                    table.record_load(act_id, std::stoll(val), graphId_eventId.first, graphId_eventId.second);
                    break;
                case gsm2::tables::StringAtt:
                    table.record_load(act_id, val, graphId_eventId.first, graphId_eventId.second);
                    break;
                case gsm2::tables::BoolAtt:
                    table.record_load(act_id, (val == "True" || val == "true" || val == "tt" || val == "t"), graphId_eventId.first, graphId_eventId.second);
                    break;
            }
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)PHI, 0, &len))) return;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
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
            graphId_eventId.first++; string+=2; len-=2;
            if (!(string = skipSpaces(string, &len))) return;
        }
    }
    maxGraphId = graphId_eventId.first;
    // TODO: indexing
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

namespace gsm2 {
    namespace tables {
        void primary_memory_load_gsm2(const std::filesystem::path& path, gsm2::tables::LinearGSM& db) {
            auto schema = path.parent_path() / "schema.txt";
            std::unordered_map<std::string, gsm2::tables::AttributeTableType> propertyname_to_type;
            if (exists(schema)) {
                std::ifstream fschema{schema};
                std::string line;
                size_t count = 0;
                std::string field_name;
                gsm2::tables::AttributeTableType field_type = gsm2::tables::AttributeTableType::StringAtt;
                while (std::getline(fschema, line)) {
                    count++;
                    if (count == 1)
                        field_name = line;
                    else {
                        auto val = magic_enum::enum_cast<gsm2::tables::AttributeTableType>(line);
                        if (val)
                            field_type = val.value();
                        else
                            field_type = gsm2::tables::AttributeTableType::StringAtt;
                        propertyname_to_type[field_name] = field_type;
                    }
                }
            }
            std::string buffer;
            std::ifstream f(path);
            f.seekg(0, std::ios::end);
            size_t n = f.tellg();
            buffer.resize(f.tellg());
            f.seekg(0);
            f.read(buffer.data(), buffer.size());
            parse(buffer.data(), n, db, propertyname_to_type, db.nGraphs);
            db.nGraphs++;
            db.index();
        }

        void LinearGSM::clear() {
            label_map.clear();
            containment_tables.clear();
            containment_relationships.clear();
            KeyValueContainment.clear();
            ell_values.clear();
            xi_values.clear();
            main_registry.clear();
        }

        void LinearGSM::index() {
            const auto& idx = main_registry.indexing1();
            for (auto& [key, table]: containment_tables)
                table.index();
            for (auto& [key, table] : KeyValueContainment)
                table.index(main_registry, idx);
            main_registry.indexing2();
            main_registry.sanityCheck();
            result resolver{0,0,0};
            all_indices.insert(all_indices.begin(), nGraphs, {});
            for (const auto& entry : main_registry.table) {
                auto id = entry.event_id;
            }

            // Creating a gsm_index
            for (const auto& [k1,v] : containment_tables) {
                for (const auto& record_obj : v.table) {
                    auto& gRef = all_indices[record_obj.graph_id];
                    auto cDst = gRef.containedBy.addUniqueStateOrGetExisting(record_obj.object_id);
                    auto oDst = gRef.containerOf.addUniqueStateOrGetExisting(record_obj.object_id);
                    const auto& labels = ell(resolver);
//                    ssize_t act_label = labels.empty() ? getMappedValueFromAction("") : getMappedValueFromAction(labels.at(0));
                    auto src = gRef.siblinghood.addUniqueStateOrGetExisting(record_obj.id_contained);
                    auto cSrc = gRef.containedBy.addUniqueStateOrGetExisting(record_obj.id_contained);
                    auto oSrc = gRef.containerOf.addUniqueStateOrGetExisting(record_obj.id_contained);
                    gRef.containedBy.addNewEdgeFromId(cSrc, cDst, k1);
                    gRef.containerOf.addNewEdgeFromId(oDst, oSrc, k1);
                    resolver.graphid = record_obj.graph_id;
                    resolver.eventid = record_obj.object_id;

                    const auto& labels2 = ell(resolver);
                    ssize_t act_label2 = labels.empty() ? getMappedValueFromAction("") : getMappedValueFromAction(labels2.at(0));
                    for (const auto& [k2,v2] : containment_tables) {
                        if (k2 == k1) continue;
                        auto it2 = v.primary_index.find(act_label2);
                        if (it2 == v.primary_index.end())
                            continue;
                        auto iterator = it2->second;
                        iterator.second++;
                        for (; iterator.first != iterator.second; iterator.first++) {
                            auto dst = gRef.siblinghood.addUniqueStateOrGetExisting(iterator.first->id_contained);
                            gRef.siblinghood.addNewEdgeFromId(src, dst, k2);
                        }
                    }
                }
            }
            for (auto& ref : all_indices){
                // Converting from the index id to the id of the actual data structure
                ref.containement_order = ref.containedBy.g.topological_sort(-1);
                convertMap(ref.containedBy, ref.containement_order);
                ref.container_order = ref.containerOf.g.topological_sort(ref.containerOf.getId(0));
                convertMap(ref.containerOf, ref.container_order);
                ref.traversal_order = ref.siblinghood.g.topological_sort(-1);
                convertMap(ref.siblinghood, ref.traversal_order);
            }
        }



        std::vector<result> LinearGSM::timed_dataless_exists(const std::string &act) const {
            std::vector<result> foundData;
            ssize_t mappedVal = getMappedValueFromAction(act);
            if(mappedVal < 0){
                return foundData;
            }
            auto indexes = main_registry.resolve_index(mappedVal);
            if(indexes.first < 0){
                return foundData;
            }
            for (auto it = main_registry.table.begin() + indexes.first; it != main_registry.table.begin() + indexes.second + 1; ++it) {
                foundData.emplace_back(it->graph_id, it->event_id);
            }
            return foundData;
        }

        std::vector<result>
        LinearGSM::approx_value_query(double min_threshold, size_t nmax, const std::string &xi) const {
            std::vector<result> result;
            std::function<void(const std::unordered_map<std::pair<size_t,size_t>, double>&)> f = [&result](const std::unordered_map<std::pair<size_t,size_t>, double>& m) {
                for (const auto& [k,v]: m) {
                    result.emplace_back(k.first, k.second, v);
                }
                std::sort(result.begin(), result.end());
            };
            xi_values.fuzzyMatch(min_threshold, nmax, xi, f);
            return result;
        }

        std::vector<result>
        LinearGSM::approx_label_query(double min_threshold, size_t nmax, const std::string &xi) const {
            std::vector<result> result;
            std::function<void(const std::unordered_map<std::pair<size_t,size_t>, double>&)> f = [&result](const std::unordered_map<std::pair<size_t,size_t>, double>& m) {
                for (const auto& [k,v]: m) {
                    result.emplace_back(k.first, k.second, v);
                }
                std::sort(result.begin(), result.end());
            };
            ell_values.fuzzyMatch(min_threshold, nmax, xi, f);
            return result;
        }

        std::vector<result> LinearGSM::query_container_or_containment(const std::string &container_object_label,
                                                                      const std::string &phi_label,
                                                                      std::function<double(const std::vector<double> &)> aggregate_scores,
                                                                      bool container_containementOth) const {
            std::vector<result> result;
            ssize_t label_id = getMappedValueFromAction(container_object_label);
            if (label_id<0)
                return result;
            std::unordered_map<std::pair<size_t,size_t>, std::vector<double>> int_result;
            if (container_object_label.empty()) {
                auto it = containment_tables.find(phi_label);
                if (it == containment_tables.end())
                    return result;
                for (const auto& x : it->second.table) {
                    int_result[{x.graph_id,
                                container_containementOth ? x.object_id : x.id_contained}]
                            .emplace_back(x.w_contained);
                }
                for (const auto& [k2,v2] : int_result) {
                    result.emplace_back(k2.first, k2.second, aggregate_scores(v2));
                }
            } else {
                auto it = containment_tables.find(phi_label);
                if (it == containment_tables.end())
                    return result;
                auto it2 = it->second.primary_index.find(label_id);
                if (it2 == it->second.primary_index.end())
                    return result;
                auto iterator = it2->second;
                iterator.second++;
                for (; iterator.first != iterator.second; iterator.first++) {
                    int_result[{iterator.first->graph_id,
                                container_containementOth ? iterator.first->object_id : iterator.first->id_contained}]
                            .emplace_back(iterator.first->w_contained);
                }
                for (const auto& [k,v] : int_result) {
                    result.emplace_back(k.first, k.second, aggregate_scores(v));
                }
            }


            std::sort(result.begin(), result.end());
            return result;
        }


        void LinearGSM::query_container_or_containment(std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>& result,
                                                  const std::string &container_object_label,
                                                  const std::string &phi_label,
                                                  bool container_containementOth) const {
//            std::unordered_map<std::pair<size_t,size_t>,std::vector<result>> result;
            ssize_t label_id = getMappedValueFromAction(container_object_label);
            if (label_id<0)
                return; // result;

            if (container_object_label.empty()) {
                auto it = containment_tables.find(phi_label);
                if (it == containment_tables.end())
                    return; // result;
                for (const auto& x : it->second.table) {
                    result[{x.graph_id,
                            container_containementOth ? x.object_id : x.id_contained}]
                            .emplace_back(x.graph_id,
                                          container_containementOth ?  x.id_contained : x.object_id,
                                          x.w_contained);
                }
            } else {
                auto it = containment_tables.find(phi_label);
                if (it == containment_tables.end())
                    return; // result;
                auto it2 = it->second.primary_index.find(label_id);
                if (it2 == it->second.primary_index.end())
                    return; // result;
                auto iterator = it2->second;
                iterator.second++;
                for (; iterator.first != iterator.second; iterator.first++) {
                    result[{iterator.first->graph_id,
                            container_containementOth ? iterator.first->object_id : iterator.first->id_contained}]
                            .emplace_back(iterator.first->graph_id,
                                          container_containementOth ? iterator.first->id_contained : iterator.first->object_id,
                                          iterator.first->w_contained);
                }
            }


            for (auto& [k,c] : result) {
                std::sort(c.begin(), c.end());
            }
            return; // result;
        }

        std::vector<gsm_object_xi_content>
        LinearGSM::resolveContent(size_t graphid, size_t id, const std::string &key_content) const {
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
            return result;
        }

        std::optional<union_minimal>
        LinearGSM::resolveProperties(size_t graph_id, size_t node_id, const std::string &key_prop) const {
            auto it = KeyValueContainment.find(key_prop);
            if (it == KeyValueContainment.end())
                return {};
            size_t i, N;
            auto it3= it->second.secondary_index2.find({graph_id,node_id});
            if (it3 !=it->second.secondary_index2.end() ) {
                return resolveUnionMinimal(it->second, it->second.table.at(it3->second));
            }
            return {};
        }

        void LinearGSM::iterateOverObjects(const std::function<void(size_t, const gsm_object &)> &f) {
            std::pair<size_t, size_t> cp;
            size_t offsetMainRegistryTable = 0;
            gsm_object legacy_obj;
            for (const auto& record : main_registry.table) {
                cp.first = record.graph_id;
                cp.second = legacy_obj.id = record.event_id;
                legacy_obj.content.clear();
                legacy_obj.phi.clear();
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

        void LinearGSM::asGraphs(std::vector<FlexibleGraph<std::string, std::string>> &simpleGraphs) const {
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

        void LinearGSM::exact_range_query(const std::string &field_name,
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
    } // gsm2
} // structures
