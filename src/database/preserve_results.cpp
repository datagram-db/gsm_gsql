/*
 * preserve_results.cpp
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
// Created by giacomo on 17/09/23.
//

#include "database/preserve_results.h"
#include "database/utility.h"

void preserve_results::instantiate_morphisms(const std::vector<node_match> &vl, bool verbose) {
    abstract_value abstract_true = true;
    nested_index.clear();
    nested_index.insert(nested_index.end(), vl.size(), -1);
    map_orig.resize(vl.size());
    map_nested.resize(vl.size());
    size_t map_orig_offset = 0;

    for (const auto& graph_grammar_entry_point: vl) {
        std::vector<std::string> nested_schema;
        if (verbose) {
            std::cout << " * Pattern = ";
            if (graph_grammar_entry_point.vec)
                std::cout << "[";
            std::cout << graph_grammar_entry_point.pattern_name;
            if (graph_grammar_entry_point.vec)
                std::cout << "]";
            std::cout << std::endl;
        }

        if (graph_grammar_entry_point.var.size() > 1) {
            throw std::runtime_error("ERROR: pattern "+graph_grammar_entry_point.pattern_name+" cannot have multi-variable entry point");
        }
        if (graph_grammar_entry_point.var.empty()) {
            throw std::runtime_error("ERROR: pattern "+graph_grammar_entry_point.pattern_name+" must have just one entry point");
        }
        std::vector<nested_table> matching_tables, optional_match_tables,
                hooks_for_vecs, opt_hooks_for_vecs; // TODO!
        const auto& entry_pattern = graph_grammar_entry_point.var.at(0);

        /// Outgoing edges
        for (const auto& [outEdge, dst] : graph_grammar_entry_point.out) {
            if (dst.var.empty()) {
                throw std::runtime_error("ERROR: outgoing edge for pattern "+graph_grammar_entry_point.pattern_name+" must have at least one entry point");
            }
            if (!outEdge.question_mark)
                loadColumnarTablesFromEdges(matching_tables, entry_pattern, outEdge, dst, true);
            else
                loadColumnarTablesFromEdges(optional_match_tables, entry_pattern, outEdge, dst, true);
        }
        std::vector<std::string> all;
        /// Ingoing edges
        for (const auto& [src, inEdge] : graph_grammar_entry_point.in) {
            if (src.var.empty()) {
                throw std::runtime_error("ERROR: ingoing edge for pattern "+graph_grammar_entry_point.pattern_name+" must have at least one entry point");
            }
            if (inEdge.forall) {
                all.emplace_back(inEdge.var.value());
                for (const auto& x : src.var) all.emplace_back(x);
            }
            if (!inEdge.question_mark)
                loadColumnarTablesFromEdges(matching_tables, entry_pattern, inEdge, src, false);
            else
                loadColumnarTablesFromEdges(optional_match_tables, entry_pattern, inEdge, src, false);
        }
        /// Hooks
        for (const auto& edge : graph_grammar_entry_point.hook) {
            if (!edge.question_mark)
                loadColumnarTablesFromEdges(graph_grammar_entry_point.vec ? hooks_for_vecs : matching_tables, entry_pattern, edge, graph_grammar_entry_point, true, false);
            else
                loadColumnarTablesFromEdges(graph_grammar_entry_point.vec ? opt_hooks_for_vecs : optional_match_tables, entry_pattern, edge, graph_grammar_entry_point, true, false);
        }
        /// Join edges
        for (const auto& joineEdge : graph_grammar_entry_point.join_edges) {
            if (joineEdge.var == graph_grammar_entry_point.var)
                throw std::runtime_error("ERROR: expecting that a join edge should be different from one starting from the egonet! (1)");
            if (!joineEdge.hook.empty()) {
                DEBUG_ASSERT(joineEdge.hook.size() == 1);
                const auto& outEdge = joineEdge.out.at(0);
                if (outEdge.second.var == graph_grammar_entry_point.var)
                    throw std::runtime_error("ERROR: expecting that a join edge should be different from one starting from the egonet! (2)");
                for (const auto& src_pattern : joineEdge.var) {
                    if (!outEdge.first.question_mark)
                        loadColumnarTablesFromEdges(graph_grammar_entry_point.vec ? hooks_for_vecs : matching_tables, src_pattern, outEdge.first, outEdge.second, true);
                    else
                        loadColumnarTablesFromEdges(graph_grammar_entry_point.vec ? opt_hooks_for_vecs : optional_match_tables, src_pattern, outEdge.first, outEdge.second, true);
                }
            } else if (!joineEdge.out.empty()) {
                DEBUG_ASSERT(joineEdge.out.size() == 1);
                const auto& outEdge = joineEdge.out.at(0);
                if (outEdge.second.var == graph_grammar_entry_point.var)
                    throw std::runtime_error("ERROR: expecting that a join edge should be different from one starting from the egonet! (3)");
                for (const auto& src_pattern : joineEdge.var) {
                    if (!outEdge.first.question_mark)
                        loadColumnarTablesFromEdges(matching_tables, src_pattern, outEdge.first, outEdge.second, true);
                    else
                        loadColumnarTablesFromEdges(optional_match_tables, src_pattern, outEdge.first, outEdge.second, true);
                }
            } else if (!joineEdge.in.empty()) {
                DEBUG_ASSERT(joineEdge.in.size() == 1);
                const auto& inEdge = joineEdge.in.at(0);
                if (inEdge.first.var == graph_grammar_entry_point.var)
                    throw std::runtime_error("ERROR: expecting that a join edge should be different from one starting from the egonet! (4)");
                for (const auto& dst_pattern : joineEdge.var) {
                    if (!inEdge.second.question_mark)
                        loadColumnarTablesFromEdges(matching_tables, dst_pattern, inEdge.second, inEdge.first, false);
                    else
                        loadColumnarTablesFromEdges(optional_match_tables, dst_pattern, inEdge.second, inEdge.first, false);
                }
            }
        }


        nested_table result;
        if (matching_tables.empty()) {
            throw std::runtime_error("ERROR: you should have in pattern "+graph_grammar_entry_point.pattern_name+" at least one non-optional edge!");
        } else if (matching_tables.size() == 1) {
            result = matching_tables.at(0);
        } else if (matching_tables.size() == 2) {
            if ((!matching_tables.at(0).datum.empty()) && (!matching_tables.at(1).datum.empty())) {
                if (verbose) {
                    std::cout << print_table(matching_tables.at(0)) << std::endl;
                    std::cout << print_table(matching_tables.at(1)) << std::endl;
                }
                result = natural_equijoin<value>(matching_tables.at(0), matching_tables.at(1));
            }
        } else {
            std::sort(matching_tables.begin(), matching_tables.end(), [](const auto& x, const auto& y) {
                return x.datum.size() < y.datum.size();
            });
            if (!matching_tables.at(0).datum.empty()) {
                result = matching_tables.at(0);
                if (verbose)
                    std::cout << print_table(result)<< std::endl;
                for (size_t i = 1; i<matching_tables.size(); i++) {
                    if (verbose)
                        std::cout << print_table(matching_tables.at(i)) << std::endl;
                    result = natural_equijoin(result, matching_tables.at(i));
                    if (verbose) {
                        std::cout << "with previous:" << std::endl;
                        std::cout << print_table(result) << std::endl;
                        std::cout << ":end with previous" << std::endl;
                    }
                }
            }
        }

        if ((!result.datum.empty()) && (!optional_match_tables.empty())) {
            std::sort(optional_match_tables.begin(), optional_match_tables.end(), [](const auto& x, const auto& y) {
                return x.datum.size() < y.datum.size();
            });
            for (const auto & optional_match_table : optional_match_tables) {
                if (!optional_match_table.datum.empty()) {
//                        std::cout << print_table(optional_match_table) << std::endl;
                    result = left_equijoin<value>(result, optional_match_table, abstract_true);
                }
            }
        }
        if (graph_grammar_entry_point.vec) {
            std::map<std::pair<size_t, size_t>, std::set<size_t>> M;
            std::map<size_t, std::set<std::set<size_t>>> M2;
            for (const auto& t : hooks_for_vecs) {
                DEBUG_ASSERT(t.Schema.at(0) == "graph");
                DEBUG_ASSERT(t.Schema.at(1) == t.Schema.at(2));
                DEBUG_ASSERT(t.Schema.size() == 3);
                for (const auto& rec : t.datum) {
//                        auto& ref = M[std::make_pair(std::get<size_t>(rec.at(0).val), std::get<size_t>(rec.at(1).val))];
                    auto&  ref1 = M[std::make_pair(std::get<size_t>(rec.at(0).val), std::get<size_t>(rec.at(1).val))];
                    ref1.insert(std::get<size_t>(rec.at(1).val));
                    ref1.insert(std::get<size_t>(rec.at(2).val));
                    auto& ref2 = M[std::make_pair(std::get<size_t>(rec.at(0).val), std::get<size_t>(rec.at(2).val))];
                    ref2.insert(std::get<size_t>(rec.at(2).val));
                    ref2.insert(std::get<size_t>(rec.at(1).val));
                }
            }
            for (const auto& [k,v] : M) {
                M2[k.first].insert(v);
            }
            M.clear();
            size_t foundInPos = 0;
            size_t graphPos = 0;
            bool foundPos = false, foundGraph = false;
            for (const auto& findH : result.Schema) {
                if (findH == graph_grammar_entry_point.var.at(0)) {
                    foundPos = true;
                    if (foundPos && foundGraph)
                        break;
                }
                if (findH == "graph") {
                    foundGraph = true;
                    if (foundPos && foundGraph)
                        break;
                }
                if (!foundGraph) graphPos++;
                if (!foundPos) foundInPos++;
            }
            size_t recordToRemove = 0;
            std::vector<size_t> idx_to_remove;
            for (const auto& record : result.datum) {
                auto fg = M2.find(std::get<size_t>(record.at(foundGraph).val));
                if (fg == M2.end())
                    idx_to_remove.emplace_back(recordToRemove);
                else {
                    bool found = false;
                    for (const auto& set : fg->second) {
                        if (set.contains(std::get<size_t>(record.at(foundInPos).val))) {
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        idx_to_remove.emplace_back(recordToRemove);
                }
                recordToRemove++;
            }
            remove_index(result.datum, idx_to_remove);
            all.emplace_back("graph");
            std::reverse(all.begin(), all.end());
            std::tie(result, nested_schema) = nest_or_groupby(result, all, "*");
            idx_to_remove.clear();

            recordToRemove = 0; foundInPos = -1; size_t graphInPos = -1;
            for (const auto& x : result.datum) {
                if (graphInPos == -1) {
                    graphInPos = 0;
                    for (const auto& findH : result.Schema) {
                        if (findH == "graph") {
                            break;
                        }
                        graphInPos++;
                    }
                }
                auto it = M2.find(std::get<size_t>(x.at(graphInPos).val));
                DEBUG_ASSERT(it != M2.end());
                const auto& t = x.at(x.size()-1).table;
                if (foundInPos == -1) {
                    foundInPos = 0;
                    for (const auto& findH : t.Schema) {
                        if (findH == graph_grammar_entry_point.var.at(0)) {
                            break;
                        }
                        foundInPos++;
                    }
                }
                std::set<size_t> offsets;
                for (const auto& recordT : t.datum) {
                    offsets.insert(std::get<size_t>(recordT.at(foundInPos).val));
                }
                bool found = false;
                for (auto& s : it->second) {
                    if (ordered_intersection(s, offsets).size() == s.size()) {
                        found = true;
                        break;
                    }
                }
                if (!found) idx_to_remove.emplace_back(recordToRemove);
                recordToRemove++;
            }
            remove_index(result.datum, idx_to_remove);
        }


        std::sort(result.datum.begin(), result.datum.end());
        size_t graphInPos = 0;
        for (const auto& findH : result.Schema) {
            if (findH == "graph") {
                break;
            }
            graphInPos++;
        }
        bool isFirst = false;
        std::string toLookFor;
        if (graph_grammar_entry_point.vec) {
            DEBUG_ASSERT(graph_grammar_entry_point.in.size() == 1);
            DEBUG_ASSERT(graph_grammar_entry_point.in.at(0).first.var.size() == 1);
            toLookFor = graph_grammar_entry_point.in.at(0).first.var.at(0);
        } else {
            toLookFor = graph_grammar_entry_point.var.at(0);
        }


        size_t offsetForStar = 0;
        for (const auto& k : result.Schema) {
            if (k != "*") {
                map_orig[map_orig_offset].put(k);
            } else {
                nested_index[map_orig_offset] = offsetForStar;
                for (const auto& w : nested_schema) {
                    map_nested[map_orig_offset].put(w);
                }
            }
            offsetForStar++;
        }

        size_t expectedOffset = -1;
        bool isNested = false;
        for (size_t k = 0, O = result.Schema.size(); k<O; k++) {
            if (result.Schema.at(k) == toLookFor) {
                expectedOffset = k;
                break;
            }
        }
        if (!result.datum.empty()) {
            DEBUG_ASSERT(expectedOffset != -1);
            for (const auto& record : result.datum) {
                auto& local_results = morphisms[std::get<size_t>(record.at(graphInPos).val)][graph_grammar_entry_point.pattern_name];
                if (local_results.second.empty() && local_results.first.empty()) {
                    local_results.first = result.Schema;
                }
                local_results.second[std::get<size_t>(record.at(expectedOffset).val)].datum.emplace_back(record);
            }

            if (verbose) {
                std::cout << print_table(result) << std::endl;
                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~" << std::endl<< std::endl<< std::endl;
            }
        }
        map_orig_offset++;
    }
}

void preserve_results::print_preliminary_edge_match_results(std::ostream &os) {
    size_t N = edge_query_ref.int_to_T.size();
    for (size_t idx = 0; idx<N; idx++) {
        const auto& q = edge_query_ref.int_to_T.at(idx);
        os << " * Outgoing: " << q.first << std::endl;
        if (q.second == IS_OUTGOING) {
            os << " * Outgoing: " << q.first << std::endl;
            for (const auto& ref : out.at(idx)) {
                for (const auto& sec : ref.second) {
                    os << "\t\t - " << sec.graphid << ": (" << ref.first.second <<")--["<< q.first<< "]->(" << sec.eventid << ")" << std::endl;
                }
            }
        } else {
            os << " * Ingoing: " << q.first << std::endl;
            for (const auto& ref : out.at(idx)) {
                for (const auto& sec : ref.second) {
                    os << "\t\t - " << sec.graphid << ": (" << ref.first.second <<")<-["<< q.first<< "]--(" << sec.eventid << ")" << std::endl;
                }
            }
        }
    }
}

void preserve_results::init() {
    edge_query_ref.clear();
    out.clear();
    copyOut.clear();
    copyIn.clear();
//        intermediate_graph_view_delta_updates.clear();
    map_orig.clear();
    nested_index.clear();
    map_nested.clear();
}

std::pair<bool, ssize_t> preserve_results::resolve_entry_match(size_t patternId, const std::string &element) const {
    ssize_t id = map_orig.at(patternId).signed_get(element);
    if (id >= 0)
        return {false, id};
    else /*if ((id < 0))*/ {
        if (nested_index.at(patternId) == -1)
            return {false, -1};
        else {
            ssize_t id2 = map_nested.at(patternId).signed_get(element);
            if (id2 < 0)
                return {false, -1};
            else
                return {true, id2};
        }
    }
//        return {false, -1};
}

void preserve_results::loadColumnarTablesFromEdges(std::vector<nested_table> &matching_tables,
                                                   const std::string &entry_pattern, const edge_match &edge,
                                                   const node_match &dst, bool isOutgoing, bool filterHook) {

    std::vector<std::string> ignore;
    if (edge.var.has_value()) {
        RawThreewayTable raw_table;
        if (isOutgoing)
            raw_table.src = entry_pattern;
        else
            raw_table.dst = entry_pattern;

        auto var_table_edge = edge.var.value();
        bool isForall = edge.forall;
        bool isDstForall = dst.vec;


        // Target value will be instantiated dynamically over dst.var
        for (const auto& idx : edge.outputQuery) {
            const auto& q = edge_query_ref.int_to_T.at(idx);
            const auto& result = out.at(idx);

            for (const auto& [graph_src, list_dst] : result) {
                for (const auto& [g,e,s] : list_dst) {
                    if (filterHook && (e != graph_src.second)) continue;
                    DEBUG_ASSERT(isOutgoing == q.second);
                    if (isOutgoing)
                        raw_table.table.emplace_back(graph_src.first, graph_src.second, q.first, e, s);
                    else
                        raw_table.table.emplace_back(graph_src.first, e, q.first, graph_src.second, s);
                }
            }
        }

        for (const auto& dstE : dst.var) {
            std::vector<std::string> first;
            std::string nesting;
            if (isOutgoing) {
                raw_table.dst = dstE;//"O("+dstE+")";
//                    raw_table.score = dstE+","+var_table_edge; //"OEs("+dstE+","+raw_table.edge+")";
                raw_table.edge = var_table_edge; // + ":"+ raw_table.dst;
                first = {raw_table.graph, raw_table.src};
                nesting = raw_table.dst;
            } else {
                raw_table.src = dstE;// "I("+dstE+")";
//                    raw_table.score = dstE+","+var_table_edge;//"IEs("+dstE+","+raw_table.edge+")";
                raw_table.edge = var_table_edge; // + ":"+ raw_table.src;
                first = {raw_table.graph, raw_table.dst};
                nesting = raw_table.src;
            }
            auto& table = matching_tables.emplace_back();
            fillFrom(table, raw_table);
            if (isForall && isDstForall) {
                std::tie(table, ignore) = nest_or_groupby(table, first, nesting);
//                    std::cout << "BENE" << std::endl;
//                    std::cout << print_table(result) << std::endl;
//                    std::cout << "BENE" << std::endl;
            }
        }
    } else {
        RawTwowayTable raw_table;
        if (isOutgoing)
            raw_table.src = entry_pattern;
        else
            raw_table.dst = entry_pattern;
        bool isForall = edge.forall;
        bool isDstForall = dst.vec;
        // Target value will be instantiated dynamically over dst.var
        for (const auto& idx : edge.outputQuery) {
            const auto& q = edge_query_ref.int_to_T.at(idx);
            const auto& result = out.at(idx);
            for (const auto& [graph_src, list_dst] : result) {
                for (const auto& [g,e,s] : list_dst) {
                    if (filterHook && (e != graph_src.second)) continue;
                    DEBUG_ASSERT(isOutgoing == q.second);
                    if (isOutgoing)
                        raw_table.table.emplace_back(graph_src.first, graph_src.second, e, s);
                    else
                        raw_table.table.emplace_back(graph_src.first, e, graph_src.second, s);
                }
            }
        }
        for (const auto& dstE : dst.var) {
            std::vector<std::string> first;
            std::string nesting;
            if (isOutgoing) {
                raw_table.dst =  dstE;//"O("+dstE+")";
//                    raw_table.score = "Os("+dstE+")";
                first = {raw_table.graph, raw_table.src};
                nesting = raw_table.dst;
            } else {
                raw_table.src = dstE;//"I("+dstE+")";
//                    raw_table.score = "Is("+dstE+")";
                first = {raw_table.graph, raw_table.dst};
                nesting = raw_table.src;
            }
            auto& table = matching_tables.emplace_back();
            fillFrom(table, raw_table);
            if (isForall && isDstForall) {
                std::tie(table, ignore) = nest_or_groupby(table, first, nesting);
//                    std::cout << "BENE" << std::endl;
            }
        }
    }
}

void preserve_results::finalise_after_all_collections(size_t nGraphs) {
//        intermediate_graph_view_delta_updates.resize()
//        out.insert(out.end(), ref_id.int_to_T.size(), std::vector<result>{});
    morphisms.clear();
    morphisms.resize(nGraphs);
}

void preserve_results::run_simple_edge_queries(gsm2::tables::LinearGSM &storage) {
    size_t N = edge_query_ref.int_to_T.size();
//        intermediate_graph_view_delta_updates.resize(N);
    for (size_t idx = 0; idx<N; idx++) {
        const auto& q = edge_query_ref.int_to_T.at(idx);
//            if (!q.second)
//                std::cout << "HERE: alert" << std::endl;
        storage.query_container_or_containment(out.emplace_back(), "", q.first, q.second);
    }
}

void preserve_results::extractForHook(std::vector<edge_match *> &emptyOutRefs, std::pair<std::string, bool> &q,
                                      edge_match &src_and_dst) {
    if (src_and_dst.type.empty()) {
        emptyOutRefs.emplace_back(&src_and_dst);
    } else {
        for (const auto& edgeLabel: src_and_dst.type) {
            DEBUG_ASSERT(q.second);
            q.first = edgeLabel;
            size_t query_id = edge_query_ref.put(q).first;
            src_and_dst.outputQuery.emplace_back(query_id);
            copyOut.erase(edgeLabel);
        }
    }
}

void preserve_results::getOutgoingEdge(std::vector<edge_match *> &emptyOutRefs, std::pair<std::string, bool> &q,
                                       edge_match &outEdge) {//            for (const auto& srcVar : ref.var) {
//                std::get<0>(t) = srcVar;
    if (outEdge.type.empty()) {
        emptyOutRefs.emplace_back(&outEdge);
    } else {
        for (const auto& edgeLabel: outEdge.type) {
            DEBUG_ASSERT(q.second);
            /*std::get<1>(t) =*/ q.first = edgeLabel;
            size_t query_id = edge_query_ref.put(q).first;
            outEdge.outputQuery.emplace_back(query_id);
            copyOut.erase(edgeLabel);
//                    for (const auto& dstVar : dst.var) {
//                        std::get<2>(t) = dstVar;
//                        size_t id_composed = ref_id.put(t).first;
//                    }
        }
//            }
    }
}

void preserve_results::extractIngoingEdge(std::vector<edge_match *> &emptyInRefs, std::pair<std::string, bool> &q,
                                          edge_match &inEdge) {
    if (inEdge.type.empty()) {
        emptyInRefs.emplace_back(&inEdge);
    } else {
        for (const auto& edgeLabel: inEdge.type) {
            DEBUG_ASSERT(!q.second);
            copyIn.erase(edgeLabel);
            /*std::get<1>(t) =*/ q.first = edgeLabel;
            size_t query_id = edge_query_ref.put(q).first;

            inEdge.outputQuery.emplace_back(query_id);
//                    for (const auto& srcVar : src.var) {
//                        std::get<0>(t) = srcVar;
//                        size_t id_composed = ref_id.put(t).first;
//                    }
        }
    }
}

void preserve_results::collect_node_match(node_match &ref, gsm2::tables::LinearGSM &storage) {
    // now, merely querying by edge label.
    copyOut = storage.containmentRelationships();
    copyIn = storage.containmentRelationships();
    std::vector<edge_match*> emptyOutRefs, emptyInRefs;

    // JOIN Edges: collecting all hooks, out, and in edges before the rest. Considering hooks as a specific case of outgoing
    // Refinement on hooks will be done over instantiation of the templates
    std::pair<std::string,bool> q{"", IS_OUTGOING};
    for (auto& joineEdge : ref.join_edges) {
        if (!joineEdge.hook.empty()) {
            q.second = IS_OUTGOING;
            DEBUG_ASSERT(joineEdge.hook.size() == 1);
            auto& src_and_dst = joineEdge.hook.at(0);
            extractForHook(emptyOutRefs, q, src_and_dst);
        } else if (!joineEdge.out.empty()) {
            q.second = IS_OUTGOING;
            DEBUG_ASSERT(joineEdge.out.size() == 1);
            auto& outEdge = joineEdge.out.at(0).first;
            getOutgoingEdge(emptyOutRefs, q, outEdge);
        } else if (!joineEdge.in.empty()) {
            q.second = IS_INGOING;
            DEBUG_ASSERT(joineEdge.in.size() == 1);
            auto& inEdge = joineEdge.in.at(0).second;
            extractIngoingEdge(emptyInRefs, q, inEdge);
        }
    }

    // OUT
    q.second = IS_OUTGOING;
    for (auto& [outEdge, dst] : ref.out) {
        getOutgoingEdge(emptyOutRefs, q, outEdge);
    }
    // HOOK Edges, considering them as Outgoing edges
    for (auto& src_and_dst : ref.hook) {
        extractForHook(emptyOutRefs, q, src_and_dst);
    }
    if (!emptyOutRefs.empty()) {
        for (const auto& outEdgeLabel : copyOut) {
            q.first = outEdgeLabel;
            size_t query_id = edge_query_ref.put(q).first;
        }
        for (edge_match* ptr : emptyOutRefs) {
            for (size_t query_id = 0, N = edge_query_ref.int_to_T.size(); query_id<N; query_id++) {
                if (edge_query_ref.int_to_T.at(query_id).second)
                    ptr->outputQuery.emplace_back(query_id);
            }
        }
    } else {
        copyOut.clear();
    }

    // IN
    q.second = IS_INGOING;
//        for (const auto& dstVar : ref.var) {
//            std::get<2>(t) = dstVar;
    for (auto& [src, inEdge] : ref.in) {
        extractIngoingEdge(emptyInRefs, q, inEdge);
    }
    if (!emptyInRefs.empty()) {
        for (const auto& inEdgeLabel : copyIn) {
            q.first = inEdgeLabel;
            edge_query_ref.put(q);
        }
        for (edge_match* ptr : emptyInRefs) {
            for (size_t query_id = 0, N = edge_query_ref.int_to_T.size(); query_id<N; query_id++) {
                if (!edge_query_ref.int_to_T.at(query_id).second)
                    ptr->outputQuery.emplace_back(query_id);
            }
        }
    } else {
        copyIn.clear();
    }
//        }
}
