/*
 * closure.cpp
 * This file is part of gsm_gsql
 *
 * Copyright (C) 2023 - Giacomo Bergami
 *
 * fuzzyStringMatching is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * fuzzyStringMatching is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with fuzzyStringMatching. If not, see <http://www.gnu.org/licenses/>.
 */
//
// Created by giacomo on 27/10/23.
//

#include "queries/closure.h"

void closure::load_query_from_file(const std::string& filename) {
    std::ifstream stream(filename);
    antlr4::ANTLRInputStream input(stream);
    simple_graph_grammarLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    simple_graph_grammarParser parser(&tokens);
    GSMPatternVisitor pv;
    // Loading the query from the visitor
    vl = std::any_cast<std::vector<node_match>>(pv.visit(parser.all_matches()));
    sortVL();
    n_patterns = vl.size();
    query_name = filename;
}

void closure::load_data_from_file(const std::string &filename) {
    std::tie(loading_time,indexing_time) = gsm2::tables::primary_memory_load_gsm2( filename, forloading);
    isMaterialised = false;
    n_graphs = forloading.nGraphs;
    n_total_objects = forloading.main_registry.table.size();
    data_name = filename;
}

void closure::asGraphs(std::vector<FlexibleGraph<std::string, std::string>> &graphs) const {
    forloading.asGraphs(graphs);
}


void closure::generateOODbFromMaterialisedViews(gsm2::tables::LinearGSM& newDB) {
    std::unordered_map<std::string, gsm2::tables::AttributeTableType> propertyname_to_type;
    std::vector<adjacency_graph> simpleGraphs(delta_updates_per_graph.size());
    generate_materialised_view();
    std::pair<size_t, size_t> cp;
    std::vector<yaucl::structures::any_to_uint_bimap<size_t>> nodesBeingInsertedAlready(delta_updates_per_graph.size());
    size_t offsetMainRegistryTable = 0;
    std::vector<std::vector<size_t>> initialNodes(delta_updates_per_graph.size());
    std::vector<std::unordered_map<size_t, size_t>> time(delta_updates_per_graph.size());
    for (size_t i = 0, N = delta_updates_per_graph.size(); i<N; i++) {
        const auto& graph_index = forloading.all_indices.at(i).container_order.at(0);
        initialNodes[i].reserve(N);
        for (size_t j = 0, M = graph_index.size(); j<M; j++) {
            initialNodes[i][j] = getOrDefault(delta_updates_per_graph.at(i).replacement_map, graph_index.at(j), graph_index.at(j));
        }
        for (const auto& [idX,object] : delta_updates_per_graph.at(i).delta_plus_db.O) {
            if (delta_updates_per_graph.at(i).hasXBeenRemoved(idX)) {
                continue;
            }
            cp.first = i;
            cp.second = idX;
            auto& nodeMap = nodesBeingInsertedAlready[i];
            auto& g = simpleGraphs[i];
            size_t id = nodeMap.put(idX).first;
            size_t gid;
            gid = g.add_node();
            std::string tmp;
            DEBUG_ASSERT(id == gid);
            offsetMainRegistryTable++;
        }
        for (const auto& [idX,object] : delta_updates_per_graph.at(i).delta_plus_db.O) {
            if (delta_updates_per_graph.at(i).hasXBeenRemoved(idX))
                continue;
            for (const auto& [edgelabel,records] : object.phi) {
                for (const auto& record: records) {
                    if (delta_updates_per_graph.at(i).hasXBeenRemoved(record.id))
                        continue;
                    const auto& map = nodesBeingInsertedAlready.at(i);
                    auto src = map.getKey(idX);
                    auto dst = map.signed_get(record.id);
                    if (dst >= 0) {
                        auto& g = simpleGraphs[i];
                        g.add_edge(src, dst);
                    }
                }
            }
        }
    }
    for (size_t k = 0, N = delta_updates_per_graph.size(); k<N; k++) {
        roaring::Roaring64Map visited;
        std::vector<size_t> Stack;
        auto& g = simpleGraphs[k];
        for (size_t start_from : initialNodes[k]) {
            g.topologicalSortUtil(start_from, visited, Stack);
        }
        for (size_t i = 0; i < g.V_size; i++)
            if (!visited.contains(i))
                g.topologicalSortUtil(i, visited, Stack);
        bool firstVisit = true;
        std::reverse(Stack.begin(), Stack.end());
        for (size_t v : Stack) {
            if (firstVisit) {
                time[k][v] = 0;
                firstVisit = false;
            } else {
                time[k][v] = 0;
                auto it = g.ingoing_edges.find(v);
                if (it != g.ingoing_edges.end()) {
                    for (size_t edgeId : it->second)
                        time[k][v] = std::max(time[k][g.edge_ids.at(edgeId).first], time[k][v]);
                    time[k][v]++;
                }
            }
        }
    }
    gsm_object orig;
    size_t vt;
    std::vector<size_t> idx_to_remove;
    for (size_t i = 0, N = delta_updates_per_graph.size(); i<N; i++) {
        const auto& map = nodesBeingInsertedAlready.at(i);
        for (const auto& [idX,object] : delta_updates_per_graph.at(i).delta_plus_db.O) {
            if (delta_updates_per_graph.at(i).hasXBeenRemoved(idX)) {
                continue;
            }
            cp.first = i;
            cp.second = idX;
            orig = object;
            orig.id = map.signed_get(orig.id);
            vt = time.at(i).at(orig.id);
            for (auto it = orig.phi.begin(); it != orig.phi.end(); it++) {
                idx_to_remove.clear();
                for (size_t j = 0; j<it->second.size(); j++) {
                    auto& content = it->second[j];
                    content.id = map.signed_get(content.id);
                    if (time[i][content.id] <= vt) {
                        idx_to_remove.emplace_back(j);
                    }
                }
                if (!idx_to_remove.empty())
                    remove_index(it->second, idx_to_remove);
                newDB.loadGSMObject(i, propertyname_to_type, orig);
            }
        }
    }
    newDB.index();
}

void closure::generateGraphsFromMaterialisedViews(std::vector<FlexibleGraph<std::string, std::string>> &simpleGraphs) {
    generate_materialised_view();
    simpleGraphs.clear();
    simpleGraphs.resize(delta_updates_per_graph.size());
    std::pair<size_t, size_t> cp;
    std::vector<yaucl::structures::any_to_uint_bimap<size_t>> nodesBeingInsertedAlready(delta_updates_per_graph.size());
    size_t offsetMainRegistryTable = 0;
    std::vector<std::vector<size_t>> initialNodes(delta_updates_per_graph.size());
    std::vector<std::unordered_map<size_t, size_t>> time(delta_updates_per_graph.size());
    auto real_time_start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0, N = delta_updates_per_graph.size(); i<N; i++) {
        const auto& graph_index = forloading.all_indices.at(i).container_order.at(0);
        initialNodes[i].reserve(N);
        for (size_t j = 0, M = graph_index.size(); j<M; j++) {
            initialNodes[i][j] = getOrDefault(delta_updates_per_graph.at(i).replacement_map, graph_index.at(j), graph_index.at(j));
        }

        for (const auto& [idX,object] : delta_updates_per_graph.at(i).delta_plus_db.O) {
            if (delta_updates_per_graph.at(i).hasXBeenRemoved(idX)) {
                continue;
            }
            cp.first = i;
            cp.second = idX;
            auto& nodeMap = nodesBeingInsertedAlready[i];
            auto& g = simpleGraphs[i];
            size_t id = nodeMap.put(idX).first;
//                const auto& xis = xi_values.resolve_object_id(cp);
            size_t gid;
            std::string tmp;
            if (object.xi.empty())
                if (object.ell.empty())
                    tmp = std::to_string(idX);
                else
                    // If no content exists, using the first label, which should exist
                    tmp = "\""+object.ell[0]+"\"="+std::to_string(idX)+"";
            else
                // Otherwise, using the first value
                tmp = object.xi[0]+"="+std::to_string(idX);
            for (const auto& [keyAttribute, value] : object.content) {
                if (std::holds_alternative<std::string>(value)) {
                    tmp = tmp+"|"+keyAttribute+"="+(std::get<std::string>(value));
                } else {
                    tmp = tmp+"|"+keyAttribute+"="+std::to_string(std::get<double>(value));
                }
            }
            gid = g.addNewNodeWithLabel(tmp);
            DEBUG_ASSERT(id == gid);
            offsetMainRegistryTable++;
        }
        for (const auto& [idX,object] : delta_updates_per_graph.at(i).delta_plus_db.O) {
            if (delta_updates_per_graph.at(i).hasXBeenRemoved(idX))
                continue;
            for (const auto& [edgelabel,records] : object.phi) {
                for (const auto& record: records) {
                    if (delta_updates_per_graph.at(i).hasXBeenRemoved(record.id))
                        continue;
                    const auto& map = nodesBeingInsertedAlready.at(i);
                    auto src = map.getKey(idX);
                    auto dst = map.signed_get(record.id);
                    if (dst >= 0) {
                        auto& g = simpleGraphs[i];
                        g.addNewEdgeFromId(src, dst, edgelabel);
                    }
                }
            }
        }


    }
    for (size_t k = 0, N = delta_updates_per_graph.size(); k<N; k++) {
        roaring::Roaring64Map visited;
        std::vector<size_t> Stack;
        auto& g = simpleGraphs[k];
        for (size_t start_from : initialNodes[k]) {
            g.g.topologicalSortUtil(start_from, visited, Stack);
        }
        for (size_t i = 0; i < g.g.V_size; i++)
            if (!visited.contains(i))
                g.g.topologicalSortUtil(i, visited, Stack);
        bool firstVisit = true;
        std::reverse(Stack.begin(), Stack.end());
        for (size_t v : Stack) {
            if (firstVisit) {
                time[k][v] = 0;
                firstVisit = false;
            } else {
                time[k][v] = 0;
                auto it = g.g.ingoing_edges.find(v);
                if (it != g.g.ingoing_edges.end()) {
                    for (size_t edgeId : it->second)
                        time[k][v] = std::max(time[k][g.g.edge_ids.at(edgeId).first], time[k][v]);
                    time[k][v]++;
                }
            }
        }
        for (size_t v = 0, vN = g.vertexSize(); v<vN; v++) {
            size_t vt = time[k][v];
            std::vector<size_t> edgesToRemove;
            for (size_t edgeId : g.g.nodes.at(v)) {
                if (time[k][g.g.edge_ids.at(edgeId).second] <= vt) {
                    edgesToRemove.emplace_back(edgeId);
                }
            }
            if (!edgesToRemove.empty()) {
                for (size_t edgeId : edgesToRemove) {
                    remove_edge(&g.g, edgeId);
                }
            }
        }
    }
    auto real_time_end = std::chrono::high_resolution_clock::now();
    materialise_time_final = std::chrono::duration<double, std::milli>(real_time_end-real_time_start).count();
}

#include <chrono>

void closure::generate_materialised_view() {
    if (!isMaterialised) {
        auto real_time_start = std::chrono::high_resolution_clock::now();
        isMaterialised = true;
//    size_t N = pr.morphisms.size();
        forloading.iterateOverObjects([this](size_t graphid, const gsm_object& legacy_object_old_data) {
            auto& updates = delta_updates_per_graph[graphid];
            if ((!updates.hasXBeenRemoved(legacy_object_old_data.id))) {
                size_t new_id = legacy_object_old_data.id;
                auto& obj = updates.delta_plus_db.O[new_id];
                obj.id = new_id;
                obj.updateWith(legacy_object_old_data);
                for (auto& [k, v] :obj.phi) {
                    for (auto& w : v) {
                        auto it = updates.replacement_map.find(w.id);
                        if (it != updates.replacement_map.end()) {
                            w.id = it->second;
                        }
                    }
                }
            }
        });
        auto real_time_end = std::chrono::high_resolution_clock::now();
        materialise_time_collection = std::chrono::duration<double, std::milli>(real_time_end-real_time_start).count();
    }

}

void closure::interpret_closure_set(rewrite_expr *ptr, size_t graph_id, size_t pattern_id,
                                    const std::vector<std::string> &schema, const nested_table &table, size_t record_id,
                                    std::any match_rhs) /** non-const!*/ {
    if (!ptr)
        return;
    Interpret I(graph_id, pattern_id, schema, table, record_id, *this);
    switch (ptr->t) {
        case rewrite_expr::SCRIPT_CASE:
            // Ignoring setting the expression
            break;

        case rewrite_expr::NONE_CASES_REWRITE:
            break;
        case rewrite_expr::NODE_XI: {
            if (match_rhs.has_value()) {
                size_t xi_offset = ptr->id;
                auto hasVar = I.interpret_closure_evaluate(ptr->ptr_or_else.get());
                if (!hasVar.has_value()) return;
                auto variable_name = std::any_cast<std::string>(hasVar);
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
                for (const auto& id : object_ids) {
                    auto& xi = delta_updates_per_graph[graph_id].delta_plus_db.generateId(id).xi;
                    if (xi.size() <= xi_offset)
                        xi.insert(xi.end(), xi.size()-xi_offset+1, "");
                    xi[xi_offset] = std::any_cast<std::string>(match_rhs);
                }
            }
        } break;

        case rewrite_expr::NODE_ELL: {
            if (match_rhs.has_value()) {
                size_t ell_offset = ptr->id;
                auto hasVar = I.interpret_closure_evaluate(ptr->ptr_or_else.get());
                if (!hasVar.has_value()) return;
                auto variable_name = std::any_cast<std::string>(hasVar);
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
                for (const auto& id : object_ids) {
                    auto& ell = delta_updates_per_graph[graph_id].delta_plus_db.generateId(id).ell;
                    if (ell.size() <= ell_offset)
                        ell.insert(ell.end(), ell.size()-ell_offset+1, "");
                    ell[ell_offset] = std::any_cast<std::string>(match_rhs);
                }
            }

        } break;

        case rewrite_expr::NODE_PROP: {
            if (match_rhs.has_value()) {
                auto hasProp = I.interpret_closure_evaluate(ptr->pi_key_arg_or_then.get());
                if (!hasProp.has_value()) return;
                auto prop_name = std::any_cast<std::string>(hasProp);
                auto hasVar = I.interpret_closure_evaluate(ptr->ptr_or_else.get());
                if (!hasVar.has_value()) return;
                auto variable_name = std::any_cast<std::string>(hasVar);
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
                for (const auto& id : object_ids) {
                    delta_updates_per_graph[graph_id].delta_plus_db.generateId(id).content[prop_name] = std::any_cast<std::string>(match_rhs);
                }
            }
        } break;

        case rewrite_expr::NODE_CONT: {
            auto hasProp = I.interpret_closure_evaluate(ptr->pi_key_arg_or_then.get());
            if (!hasProp.has_value()) return;
            auto prop_name = std::any_cast<std::string>(hasProp);
            auto hasVar = I.interpret_closure_evaluate(ptr->ptr_or_else.get());
            if (!hasVar.has_value()) return;
            auto variable_name = std::any_cast<std::string>(hasVar);
            const auto& record = table.datum.at(record_id);
            auto isVariableName = get_v_opt<std::string>(match_rhs);
            if (isVariableName.has_value()) {
                auto orig = resolveIdsOverVariableName(graph_id, pattern_id, isVariableName.value(), record);
                if (!orig.empty()) {
                    auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
                    for (size_t dst : orig) {
                        for (const auto& id : object_ids) {
                            delta_updates_per_graph[graph_id].delta_plus_db.generateId(id).phi[prop_name].emplace_back(dst);
                        }
                    }
                }

            } else {
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
                for (const auto& id : object_ids) {
                    delta_updates_per_graph[graph_id].delta_plus_db.generateId(id).phi[prop_name] = std::any_cast<std::vector<gsm_object_xi_content>>(match_rhs);
                }
            }
        } break;

        case rewrite_expr::EDGE_LABEL: {
            throw std::runtime_error("ERROR: cannot change the edge label! Go for the creation of a new content. TODO: CLEAR CONTENT");
        } break;

        case rewrite_expr::EDGE_SRC:
        case rewrite_expr::EDGE_DST:
            throw std::runtime_error("UNSUPPORTED OPERATION (FUTURE)");
            break;

        case rewrite_expr::VARIABLE: {
            throw std::runtime_error("ERROR: cannot set a variable! You need to specify which property of such variable you want to set");
        } break;

        case rewrite_expr::IFTE_RW: {
            if (I.interpret(ptr->ifcond)) {
                interpret_closure_set(ptr->pi_key_arg_or_then.get(), graph_id, pattern_id, schema, table, record_id, match_rhs);
            } else {
                interpret_closure_set(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id, match_rhs);
            }
        } break;

        case rewrite_expr::NODE_OR_EDGE:
            break;
    }
}

#include <scriptv2/ScriptVisitor.h>
#include <scriptv2/ScriptAST.h>

std::any closure::Interpret::interpret_closure_evaluate(rewrite_expr *ptr) const {
    if (!ptr)
        return {};
    switch (ptr->t) {
        case rewrite_expr::SCRIPT_CASE: {
            std::stringstream ss;
            ss << ptr->prop;
            return script::compiler::ScriptVisitor::eval(ss, schema, table.datum.at(record_id))->run()->toString();
        }
            // Returning the specific XI for the nodes
        case rewrite_expr::NODE_XI: {
            size_t xi_offset = ptr->id;
            auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get()));
            const auto& record = table.datum.at(record_id);
            auto object_ids = clos.resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
            if (object_ids.empty())
                return {};

            // for each object_id in the vector, I continuously append
            return std::accumulate(
                    object_ids.begin(),
                    object_ids.end(),
                    std::string(""),
                    [this,xi_offset](const std::string& b, size_t a) {
                        const auto& resolution = clos.resolve_xi(graph_id,a);
                        if (b.empty())
                            return resolution.empty() ? "" : resolution.at(xi_offset);
                        else
                            return  b + (resolution.empty() ? "" : " "+resolution.at(xi_offset));
                    }
            );
        } break;

            // Returning the specific ELLS for the nodes
        case rewrite_expr::NODE_ELL: {
            size_t ell_offset = ptr->id;
            auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get()));
            const auto& record = table.datum.at(record_id);
            auto object_ids = clos.resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
            if (object_ids.empty())
                return {};

            // for each object_id in the vector, I continuously append
            return std::accumulate(
                    object_ids.begin(),
                    object_ids.end(),
                    std::string(""),
                    [this,ell_offset](const std::string& b, size_t a) {
                        const auto& resolution = clos.resolve_ell(graph_id,a);
                        if (b.empty())
                            return resolution.empty() ? "" : resolution.at(ell_offset);
                        else
                            return  b + (resolution.empty() ? "" : " "+resolution.at(ell_offset));
                    }
            );
        }

            // Returning the property associated to a node
        case rewrite_expr::NODE_PROP: {
            auto prop_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->pi_key_arg_or_then.get()));
            auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get()));
            const auto& record = table.datum.at(record_id);
            auto object_ids = clos.resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
            if (object_ids.empty())
                return {};

            // for each object_id in the vector, I continuously append
            return std::accumulate(
                    object_ids.begin(),
                    object_ids.end(),
                    std::string(""),
                    [this,prop_name](const std::string& b, size_t a) {
                        if (b.empty())
                            return clos.resolve_prop(graph_id, a, prop_name);
                        else
                            return  b + " " + clos.resolve_prop(graph_id, a, prop_name);
                    }
            );
        } break;

        case rewrite_expr::NODE_CONT: {
            size_t ell_offset = ptr->id;
            auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get()));
            const auto& record = table.datum.at(record_id);
            auto object_ids = clos.resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);

            std::vector<gsm_object_xi_content> collected;
            for (size_t id : object_ids) {
                auto local = clos.resolve_content(graph_id, id, variable_name);
                collected.insert(collected.end(), local.begin(), local.end());
            }
            remove_duplicates(collected);
            return collected;
        } break;

            // Returning the edge label (if nested, imploding the collection into a string!) TODO: what if we need singled out?
        case rewrite_expr::EDGE_LABEL: {
            auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get()));
            const auto& record = table.datum.at(record_id);
            auto object_ids = clos.resolvelabelsOverVariableName(pattern_id, variable_name, record);
            if (object_ids.empty())
                return {};

            return std::accumulate(
                    object_ids.empty() ? object_ids.end() : std::next(object_ids.begin()),
                    object_ids.end(),
                    object_ids.empty() ? std::string("") : object_ids.at(0),
                    [](const std::string& b, const std::string& a) {
                        if (b.empty())
                            return a;
                        else
                            return  b + " " + a;
                    }
            );
        } break;


            // Just returning the variable name associated to the object
        case rewrite_expr::VARIABLE:
            return {ptr->prop};
            break;

        case rewrite_expr::IFTE_RW: {
            return interpret(ptr->ifcond);
        } break;

        default:
            throw std::runtime_error("UNSUPPORTED OPERATION (FUTURE)");
    }
}
