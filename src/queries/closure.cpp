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
//                std::cout << idX << std::endl;
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
                tmp = tmp+"|"+keyAttribute+"="+(value);
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
//                    else {
//                        std::cout<< idX << "--["<< edgelabel << "]-->" << record.id << std::endl;
//                    }
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
