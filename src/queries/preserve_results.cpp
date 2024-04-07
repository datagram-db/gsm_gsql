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

#include "queries/preserve_results.h"
#include "database/utility.h"


nested_table nested_natural_equijoin(const IndexedSchemaCoordinates& lhs,
                                     const IndexedSchemaCoordinates& rhs,
                                     bool isEquiJoin = false) {
    static abstract_value abstract_true = true;
    std::vector<std::string> lhsNotNested, lhsNested, rhsSchema, sToNest, L, R;
    std::vector<size_t> iposL, iposR;
    std::unordered_set<std::string> sharedParents, sIR;

    lhs.fillBothNested(lhsNested, lhsNotNested);
    std::sort(lhsNotNested.begin(), lhsNotNested.end());
    std::sort(lhsNested.begin(), lhsNested.end());
    rhsSchema = rhs.table->Schema;
    std::sort(rhsSchema.begin(), rhsSchema.end());
    std::set_intersection(lhsNotNested.begin(), lhsNotNested.end(), rhsSchema.begin(), rhsSchema.end(), std::inserter(sIR, sIR.begin()));
    if (sIR.empty()) {
        return crossProduct(*lhs.table, *rhs.table);
    }

    for (const auto& x : sIR) {
        iposL.emplace_back(lhs.mainHeaderKeyOffset(x));
        iposR.emplace_back(rhs.mainHeaderKeyOffset(x));
    }
    std::set_intersection(lhsNested.begin(), lhsNested.end(), rhsSchema.begin(), rhsSchema.end(), std::back_inserter(sToNest));
    if (sToNest.empty()) {
        if (isEquiJoin) {
            return natural_equijoin<value>(*lhs.table, *rhs.table);
        } else {
            return left_equijoin<value>(*lhs.table, *rhs.table, abstract_true);
        }
    }

    if (rhs.hasNestedColumns()) {
        throw std::runtime_error("ERROR: this operator does not support RHS being a nested table");
    }
    for (const auto& pepper : sToNest) {
        lhs.getAllParents(pepper, sharedParents);
        if (sharedParents.size()>1)
            throw new std::runtime_error("ERROR: this implementation does not support rhs table being ");
    }
    std::string colN = *sToNest.begin();

    auto LHSNV = lhs.getNestedSchemaAssociatedToCol(colN);
    std::vector<size_t> iposL2, iposR2, forReodreing;
    std::set<std::string> i;
    std::vector<std::string> resultingNestedSchema;
    size_t missingToBeAdded = 0;
    {
        std::set<std::string> LN{LHSNV.begin(), LHSNV.end()}, RTBN{rhsSchema.begin(), rhsSchema.end()};
        i = ordered_intersection(LN,RTBN);
        std::vector<size_t> remainingL, remainingR;
        bool firstStr = true;
        for (const auto& str : i) {
            for (size_t j = 0, N = LHSNV.size(); j<N; j++) {
                if (firstStr)
                    remainingL.emplace_back(j);
                if (str == (LHSNV.at(j))) {
                    iposL2.emplace_back(j);
                    if (!firstStr) break;
                }
            }
            for (size_t j = 0, N = rhsSchema.size(); j<N; j++) {
                if (firstStr)
                    remainingR.emplace_back(j);
                if (str == (rhsSchema.at(j))) {
                    iposR2.emplace_back(j);
                    if (!firstStr) break;
                }
            }
            firstStr = false;
        }
        std::vector<std::string> L2 = LHSNV, R2 = rhsSchema;
        std::set<size_t> IL{iposL2.begin(), iposL2.end()}, IR{iposR2.begin(), iposR2.end()};
        {
            std::vector<size_t> tmpL{IL.begin(), IL.end()}, tmpR{IR.begin(), IR.end()};
            remove_index(L2, tmpL);
            remove_index(remainingL, tmpL);
            remove_index(R2, tmpR);
            remove_index(remainingR, tmpR);
        }
        for (size_t j : iposL2) {
            resultingNestedSchema.emplace_back(LHSNV.at(j));
            forReodreing.emplace_back(j);
        }
        for (size_t j = 0, N = LHSNV.size(); j<N; j++) {
            if (!IL.contains(j)) {
                resultingNestedSchema.emplace_back(LHSNV.at(j));
                forReodreing.emplace_back(j);
            }
        }
        for (size_t j = 0, N = R2.size(); j<N; j++) {
            if (!IR.contains(j)) {
                missingToBeAdded++;
                resultingNestedSchema.emplace_back(R2.at(j));
            }
        }
    }

    DEBUG_ASSERT(lhs.table->checkSchemaSizeCompliance());
    std::map<std::vector<NestedValue<abstract_value>>, std::vector<std::vector<NestedValue<abstract_value>>>> rM, lM;
    for (const auto& record : lhs.table->datum) {
        std::vector<NestedValue<abstract_value>> proj, remain;
        for (size_t j = 0, N = record.size(); j<N; j++) {
            if (!sIR.contains(lhs.table->Schema.at(j)))
                remain.emplace_back(record.at(j));
        }
        for (size_t j : iposL)
            proj.emplace_back(record.at(j));
        lM[proj].emplace_back(remain);
    }
//

    for (const auto& record : rhs.table->datum) {
        std::vector<NestedValue<abstract_value>> proj, remain;
        for (size_t j = 0, N = record.size(); j<N; j++) {
            if (!sIR.contains(rhs.table->Schema.at(j)))
                remain.emplace_back(record.at(j));
        }
        for (size_t j : iposR)
            proj.emplace_back(record.at(j));
        rM[proj].emplace_back(remain);
    }

    nested_table result;
    size_t nestingOffset = -1;
    result.Schema.insert(result.Schema.end(), sIR.begin(), sIR.end());
    std::vector<std::string> matchingInternal;
    for (const auto& ref : lhs.table->Schema) {
        if (!sIR.contains(ref))  {
            L.emplace_back(ref);
            if (ref == colN) {
                nestingOffset = L.size()-1;
                matchingInternal = lhs.getNestedSchemaFromOffset(ref);
                std::sort(matchingInternal.begin(), matchingInternal.end());
            }
        }
    }
    DEBUG_ASSERT(nestingOffset != -1);
    for (const auto& ref : rhs.table->Schema)
        if (!sIR.contains(ref))
            R.emplace_back(ref);
    size_t remainingSize = 0;
    {
        auto Rsorted = R;
        std::vector<std::string> diff;
        std::sort(Rsorted.begin(), Rsorted.end());
        std::set_difference(Rsorted.begin(), Rsorted.end(), matchingInternal.begin(), matchingInternal.end(), std::back_inserter(diff));
        remainingSize = diff.size();
    }

    std::vector<value> remainingV(missingToBeAdded, abstract_true);
    result.Schema.insert(result.Schema.end(), L.begin(), L.end());
    auto it = lM.begin(), en = lM.end();
    auto it2 = rM.begin(), en2 = rM.end();
    bool hasiPosLOneNested = false;
    nested_table fixed_table;
    fixed_table.Schema = R;
    while (it != en && it2 != en2) {
        if (it->first < it2->first) {
            if (!isEquiJoin) {
                for (const auto& lR : it->second) {
                    auto v = it->first;
                    v.insert(v.end(), lR.begin(), lR.end());
                    v.at(it->first.size()+nestingOffset).table.Schema = resultingNestedSchema;
                    for (auto& nestedRow : v.at(it->first.size()+nestingOffset).table.datum) {
                        reorder(nestedRow, forReodreing);
                        nestedRow.insert(nestedRow.end(), remainingV.begin(), remainingV.end());
                    }
                    DEBUG_ASSERT(v.size() == result.Schema.size());
                    auto& ref = result.datum.emplace_back(v);
                    for (auto& x : ref) {
                        if (!x.table.Schema.empty())
                            x.isNested = true;
                    }
                }
            }
            it++;
        } else if (it2->first < it->first) {
            it2++;
        } else {
            for (const auto& lR : it->second) {
                auto refL = lR.at(nestingOffset);
                fixed_table.datum = it2->second;
                refL.table = left_equijoin<value>(refL.table, fixed_table, abstract_true);
                DEBUG_ASSERT(refL.table.Schema == resultingNestedSchema);
                DEBUG_ASSERT(refL.isNested || (!refL.table.Schema.empty()));
                auto v = it->first;
                v.insert(v.end(), lR.begin(), (lR.begin()+nestingOffset));
                v.emplace_back(refL);
                if (nestingOffset-1 != lR.size())
                    v.insert(v.end(), (lR.begin()+nestingOffset+1), lR.end());
                DEBUG_ASSERT(v.size() == result.Schema.size());
                auto& ref = result.datum.emplace_back(v);
                for (auto& x : ref) {
                    if (!x.table.Schema.empty())
                        x.isNested = true;
                }
            }
            it++;
            it2++;
        }
    }
    if (!isEquiJoin) {
        while (it != en) {
            for (const auto& lR : it->second) {
                auto v = it->first;
                v.insert(v.end(), lR.begin(), lR.end());
                v.at(it->first.size()+nestingOffset).table.Schema = resultingNestedSchema;
                for (auto& nestedRow : v.at(it->first.size()+nestingOffset).table.datum) {
                    reorder(nestedRow, forReodreing);
                    nestedRow.insert(nestedRow.end(), remainingV.begin(), remainingV.end());
                }
                DEBUG_ASSERT(v.size() == result.Schema.size());
                auto& ref = result.datum.emplace_back(v);
                for (auto& x : ref) {
                    if (!x.table.Schema.empty())
                        x.isNested = true;
                }
//                auto lRecordCommon = it->first;
//#ifdef DEBUG
//                size_t lRSize = lRecordReminder.size();
//                size_t rvSize = 0;//remainingV.size();
//                size_t vSize = lRecordCommon.size();
//                DEBUG_ASSERT((lRSize+rvSize+vSize) == result.Schema.size());
//#endif
//                lRecordCommon.insert(lRecordCommon.end(), lRecordReminder.begin(), lRecordReminder.end());
////            lRecordCommon.insert(lRecordCommon.end(), remainingV.begin(), remainingV.end());
//                DEBUG_ASSERT(lRecordCommon.size() == result.Schema.size());
//                auto& ref = result.datum.emplace_back(lRecordCommon);
//                for (auto& x : ref) {
//                    if (!x.table.Schema.empty())
//                        x.isNested = true;
//                }
            }
            it++;
        }
    }
    DEBUG_ASSERT(result.checkSchemaSizeCompliance());
    return result;
}

void preserve_results::instantiate_morphisms(const std::vector<node_match> &vl, bool verbose, const std::unordered_set<std::string>& nodes, const std::unordered_set<std::string>& edges, const std::string& output_folder) {
    abstract_value abstract_true = true;
    nested_index.clear();
    nested_index.resize(vl.size());
    map_orig.resize(vl.size()); // One element per pattern
    map_nested.resize(vl.size());   // One element per pattern
    size_t map_orig_offset = 0;
    std::filesystem::path folder = output_folder;

    // We instantiate a table for each pattern
    for (const auto& graph_grammar_entry_point: vl) {
        size_t versions = 1;
        std::vector<std::string> nested_schema;
//

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
                //all.emplace_back(inEdge.var.value());
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

        /// Now, computing the join across all the tables
        nested_table result;
        if (matching_tables.empty()) {
            /// No table associated to the pattern
            throw std::runtime_error("ERROR: you should have in pattern "+graph_grammar_entry_point.pattern_name+" at least one non-optional edge!");
        } else if (matching_tables.size() == 1) {
            // Just one table: no join is required
            result = matching_tables.at(0);
        } else if (matching_tables.size() == 2) {
            // Otherwise, you need to natural join the two tables
            if ((!matching_tables.at(0).datum.empty()) && (!matching_tables.at(1).datum.empty())) {
                if (verbose) {
                    {
                        std::ofstream file{folder / (graph_grammar_entry_point.pattern_name+"("+std::to_string(versions++)+").ncsv")};
                        serialised_nested_table(file, graph_grammar_entry_point.pattern_name, matching_tables.at(0), edges);
                    }
                    {
                        std::ofstream file{folder / (graph_grammar_entry_point.pattern_name+"("+std::to_string(versions++)+").ncsv")};
                        serialised_nested_table(file, graph_grammar_entry_point.pattern_name, matching_tables.at(1), edges);
                    }
//                    std::cout << print_table(matching_tables.at(0)) << std::endl;
//                    std::cout << print_table(matching_tables.at(1)) << std::endl;
                }
                IndexedSchemaCoordinates L{&matching_tables.at(0)};
                IndexedSchemaCoordinates R{&matching_tables.at(1)};
                L.index();
                R.index();
//                DEBUG_ASSERT(result.checkSchemaSizeCompliance());
//                DEBUG_ASSERT(optional_match_table.checkSchemaSizeCompliance());
//                    if ((graph_grammar_entry_point.pattern_name == "p3") && (std::find(optional_match_table.Schema.begin(), optional_match_table.Schema.end(), "NN") != optional_match_table.Schema.end())) {
//                        std::cout << "DEBUG" << std::endl;
//                    }
                result = nested_natural_equijoin(L, R, true);
//                result = natural_equijoin<value>(matching_tables.at(0), matching_tables.at(1));
                DEBUG_ASSERT(result.checkSchemaSizeCompliance());
            }
        } else {
            // Having more than one table, sorting the tables by increasing size.
            // This heuristic tries to minimise the chance of matches
            std::sort(matching_tables.begin(), matching_tables.end(), [](const auto& x, const auto& y) {
                return x.datum.size() < y.datum.size();
            });
            // If the first table is empty, I abort computing the join
            if (!matching_tables.at(0).datum.empty()) {
                // Computing the equi-join across all the tables being provided
                result = matching_tables.at(0);
                if (verbose) {
                    std::ofstream file{folder / (graph_grammar_entry_point.pattern_name+"("+std::to_string(versions++)+").ncsv")};
                    serialised_nested_table(file, graph_grammar_entry_point.pattern_name, result, edges);
//                    std::cout << print_table(result) << std::endl;
                } for (size_t i = 1; i<matching_tables.size(); i++) {
                    if (verbose) {
                        std::ofstream file{folder / (graph_grammar_entry_point.pattern_name+"("+std::to_string(versions++)+").ncsv")};
                        serialised_nested_table(file, graph_grammar_entry_point.pattern_name, matching_tables.at(i), edges);
//                        std::cout << print_table(matching_tables.at(i)) << std::endl;
                    }
                    IndexedSchemaCoordinates L{&result};
                    IndexedSchemaCoordinates R{&matching_tables.at(i)};
                    L.index();
                    R.index();
//                DEBUG_ASSERT(result.checkSchemaSizeCompliance());
//                DEBUG_ASSERT(optional_match_table.checkSchemaSizeCompliance());
//                    if ((graph_grammar_entry_point.pattern_name == "p3") && (std::find(optional_match_table.Schema.begin(), optional_match_table.Schema.end(), "NN") != optional_match_table.Schema.end())) {
//                        std::cout << "DEBUG" << std::endl;
//                    }
                    result = nested_natural_equijoin(L, R, true);

//                    result = natural_equijoin(result, matching_tables.at(i));
                    DEBUG_ASSERT(result.checkSchemaSizeCompliance());
                    if (result.datum.empty()) break; // Stopping as soon as I reckon the table becomes empty
                    if (verbose) {
//                        std::cout << "with previous:" << std::endl;
                        std::ofstream file{folder / (graph_grammar_entry_point.pattern_name+"("+std::to_string(versions++)+").ncsv")};
                        serialised_nested_table(file, graph_grammar_entry_point.pattern_name, result, edges);
//                        std::cout << ":end with previous" << std::endl;
                    }
                }
            }
        }

        DEBUG_ASSERT(result.checkSchemaSizeCompliance());

        // Performing the left joins only if there are results in the pre-computed table,
        // and  if, of course, there are some optional matches to consider
        if ((!result.datum.empty()) && (!optional_match_tables.empty())) {
            // Similarly, computing the left join against the optional tables for the optional matches
            std::sort(optional_match_tables.begin(), optional_match_tables.end(), [](const auto& x, const auto& y) {
                return x.datum.size() < y.datum.size();
            });
            for (const auto & optional_match_table : optional_match_tables) {
                if (!optional_match_table.datum.empty()) {
                    // TODO: when a field is nested in result but not nested in the optional table, then
                    //       it has to go inside each row, while equijoining the rest being outside the nesting
                    // FUTURE
                    IndexedSchemaCoordinates L{&result};
                    IndexedSchemaCoordinates R{&optional_match_table};
                    L.index();
                    R.index();
                    DEBUG_ASSERT(result.checkSchemaSizeCompliance());
                    DEBUG_ASSERT(optional_match_table.checkSchemaSizeCompliance());
//                    if ((graph_grammar_entry_point.pattern_name == "p3") && (std::find(optional_match_table.Schema.begin(), optional_match_table.Schema.end(), "NN") != optional_match_table.Schema.end())) {
//                        std::cout << "DEBUG" << std::endl;
//                    }
                    result = nested_natural_equijoin(L, R);
                    DEBUG_ASSERT(result.checkSchemaSizeCompliance());
                }
            }
        }

        /// If I need to group-by
        if (graph_grammar_entry_point.vec && !graph_grammar_entry_point.hook.empty()) {
            // Indexing the hooks and the join edges
            std::map<std::pair<size_t, size_t>, std::set<size_t>> graphAndObject_to_edgeTarget; // <graph,objId> --> <edgeTarget>
            std::map<size_t, std::set<std::set<size_t>>> graphToEdgeTarget;         // <graph> --> [<edgeTarget>]
            for (const auto& t : hooks_for_vecs) {
//                std::cout <<print_table(t)<<std::endl;
                DEBUG_ASSERT(t.Schema.at(0) == "graph");
                DEBUG_ASSERT(t.Schema.at(1) == t.Schema.at(2));
                DEBUG_ASSERT(t.Schema.size() == 3);
                for (const auto& rec : t.datum) {
//                        auto& ref = M[std::make_pair(std::get<size_t>(rec.at(0).val), std::get<size_t>(rec.at(1).val))];
                    auto&  ref1 = graphAndObject_to_edgeTarget[std::make_pair(std::get<size_t>(rec.at(0).val), std::get<size_t>(rec.at(1).val))];
                    ref1.insert(std::get<size_t>(rec.at(1).val));
                    ref1.insert(std::get<size_t>(rec.at(2).val));
                    auto& ref2 = graphAndObject_to_edgeTarget[std::make_pair(std::get<size_t>(rec.at(0).val), std::get<size_t>(rec.at(2).val))];
                    ref2.insert(std::get<size_t>(rec.at(2).val));
                    ref2.insert(std::get<size_t>(rec.at(1).val));
                }
            }
            for (const auto& [k,v] : graphAndObject_to_edgeTarget) {
                graphToEdgeTarget[k.first].insert(v);
            }
            graphAndObject_to_edgeTarget.clear();

            /// Looking in the schema of the result table, where the 'graph' variable is (graphPos), as well as the variable
            /// associated to entrypoint for the match (foundInPos)
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
            std::vector<size_t> idx_to_remove; // Indices for the rows to be removed in the main table, as they do not match
            // with the other "spare" edges, for hooks or "join" edges (not within the ego-net)
            for (const auto& record : result.datum) {
                auto fg = graphToEdgeTarget.find(std::get<size_t>(record.at(graphPos).val));
                if (fg == graphToEdgeTarget.end())
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
            // Removing all the matches not matching with the join edges
            remove_index(result.datum, idx_to_remove);
            all.emplace_back("graph");
            std::reverse(all.begin(), all.end());
            // Nesting the table using the variables associate to a .vec, alongside with their associated graph id.
            // The remaining rows will be nested within the * node
//            std::cout << print_table(result) << std::endl;
            std::tie(result, nested_schema) = nest_or_groupby(result, all, "*");
            idx_to_remove.clear();
//            std::cout << print_table(result) << std::endl;
            recordToRemove = 0; foundInPos = -1; size_t graphInPos = -1;
            std::vector<std::vector<std::vector<size_t>>> osagai;

            // Iterating over the rows of the nested relationship
            for (const auto& topRow : result.datum) {
                if (graphInPos == -1) {
                    // After the group-by, re-calculating the position of "graph" within the schema of the nested table
                    graphInPos = 0;
                    for (const auto& findH : result.Schema) {
                        if (findH == "graph") {
                            break;
                        }
                        graphInPos++;
                    }
                }
                auto it = graphToEdgeTarget.find(std::get<size_t>(topRow.at(graphInPos).val));
                DEBUG_ASSERT(it != graphToEdgeTarget.end());
                const auto& nestedTableInTable = topRow.at(topRow.size() - 1).table;
//                std::cout << print_table(nestedTableInTable) << std::endl;
                if (foundInPos == -1) {
                    // After the group-by, re-calculating the position of the "variable" associated to the group by
                    foundInPos = 0;
                    for (const auto& findH : nestedTableInTable.Schema) {
                        if (findH == graph_grammar_entry_point.var.at(0)) {
                            break;
                        }
                        foundInPos++;
                    }
                }
                std::set<size_t> offsets;
                bool found = false;
//                size_t idxByOffset = 0;
                size_t recordId = 0;
                std::unordered_map<size_t,std::vector<size_t>> hookNodeIdToRecordOffset;
                for (const auto& recordT : nestedTableInTable.datum) {
                    const auto& cell = std::get<size_t>(recordT.at(foundInPos).val);
                    hookNodeIdToRecordOffset[cell].emplace_back(recordId++);
                    offsets.insert(cell);
                }
                for (const auto& s : it->second) {
                    // Hook intersection should target all the outputs that are associated to the aggregation, if any
                    if (ordered_intersection(s, offsets).size() == s.size()) {
                        found = true;
                        break;
                    }
                }
                auto& emplaced = osagai.emplace_back();
                // If not found, then removing the entry from the match
                if (!found)
                    idx_to_remove.emplace_back(recordToRemove);
                else {
                    std::vector<size_t> result_set;
                    for (const auto& s : it->second) {
                        auto it3 = s.begin();
                        if (!hookNodeIdToRecordOffset.contains(*it3))
                            continue;
                        auto current = hookNodeIdToRecordOffset.at(*it3);
                        it3++;
                        result_set.clear();
                        for (; it3!=s.end(); it3++) {
                            auto nextTwo = hookNodeIdToRecordOffset.find(*it3);
                            if (nextTwo == hookNodeIdToRecordOffset.end()) {
                                current.clear();
                                result_set.clear();
                                continue;
                            }
                            const auto& next = nextTwo->second;
                            std::set_union(current.begin(), current.end(), next.begin(), next.end(), std::back_inserter(result_set));
                            std::swap(current, result_set);
                            result_set.clear();
                        }
                        if (!current.empty())
                            emplaced.emplace_back(current);
                    }
                }
                recordToRemove++;
            }

            // Removing the records not matching the hook
            remove_index(result.datum, idx_to_remove);
            remove_index(osagai, idx_to_remove);
            nested_table final_table;
            final_table.Schema = result.Schema;

            for (size_t i = 0, N = osagai.size(); i<N; i++) {
                const auto& x = result.datum.at(i);
                const auto& t = x.at(x.size()-1).table;
                std::vector<value> recordToCopy(x.begin(), x.end()-1);

                for (const auto& records : osagai.at(i)) {
                    nested_table tableCopy;
                    tableCopy.Schema = t.Schema;
                    for (size_t idx : records) {
                        tableCopy.datum.emplace_back(t.datum.at(idx));
                    }
                    auto& final_row = final_table.datum.emplace_back(recordToCopy);
                    final_row.emplace_back(tableCopy);
                }
            }

            DEBUG_ASSERT(result.checkSchemaSizeCompliance());
//            std::cout << print_table(result) << std::endl;
//            std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
//            std::cout << print_table(final_table) << std::endl;
//            std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
            std::swap(final_table, result);
        } else if (graph_grammar_entry_point.vec && graph_grammar_entry_point.hook.empty()) {
            all.emplace_back("graph");
            std::reverse(all.begin(), all.end());
            std::tie(result, nested_schema) = nest_or_groupby(result, all, "*");

            DEBUG_ASSERT(result.checkSchemaSizeCompliance());
//            result.Schema = nested_schema;
        }

        /// If I need to group-by: finish
        std::sort(result.datum.begin(), result.datum.end());
        size_t graphInPos = 0;
        // Looking for where the "graph" is declared within the schema
        for (const auto& findH : result.Schema) {
            if (findH == "graph") {
                break;
            }
            graphInPos++;
        }
        bool isFirst = false;
        std::string toLookFor;
//        if (graph_grammar_entry_point.vec && !graph_grammar_entry_point.hook.empty()) {
        if (graph_grammar_entry_point.vec) {
            // If the match is a vec (it was grouped-by), then  getting the variable within the nested element
            // TODO: requiring that a vec has at least one ingoing edge (TODO: generalise!)
            DEBUG_ASSERT(graph_grammar_entry_point.in.size() == 1);
            DEBUG_ASSERT(graph_grammar_entry_point.in.at(0).first.var.size() == 1);
            toLookFor = graph_grammar_entry_point.in.at(0).first.var.at(0);
        } else {
            // Otherwise, the variable is
            toLookFor = graph_grammar_entry_point.var.at(0);
        }


        // Determining the mapping for the relevant element for the schema for eventually resolving the
        // coordinates of the variables within the nested table
        size_t offsetForStar = 0;
        for (const auto& k : result.Schema) {
            if (k != "*") {
                if ((!result.datum.empty())) {
                    if (result.datum.at(0).at(offsetForStar).isNested) {
                        // Remembering the location of the sole nested cell
                        nested_index[map_orig_offset].emplace_back(offsetForStar);
                        auto& W = map_nested[map_orig_offset].emplace_back();
                        // Remembering the offsets for the other nested cells
                        for (const auto& w : result.datum.at(0).at(offsetForStar).table.Schema) {
                            W.put(w);
                        }
                    } else {
                        map_orig[map_orig_offset].emplace(k, offsetForStar); // Used f
                    }
                } else
                    // Remembering that pattern map_orig_offset contains k in the current position
                    // This works under the assumption that * is always located at the last element of the table!
                    map_orig[map_orig_offset].emplace(k, offsetForStar); // Used f
            } else {
                // Remembering the location of the sole nested cell
                nested_index[map_orig_offset].emplace_back(offsetForStar);
                auto& W = map_nested[map_orig_offset].emplace_back();
                // Remembering the offsets for the other nested cells
                for (const auto& w : nested_schema) {
                    W.put(w);
                }
            }
            offsetForStar++;
        }

        // Last, ensuring that all the nodes and edges are different for each nested label.
        std::vector<size_t> removeIndex2;
        if (!nested_index[map_orig_offset].empty()) {
            for (size_t i = 0, N = result.datum.size(); i<N; i++) {
                auto& row = result.datum.at(i);
                for (size_t k : nested_index[map_orig_offset]) {
                    std::vector<size_t> removeIndex;
                    for (size_t l = 0, O = row.at(k).table.datum.size(); l<O; l++) {
                        std::multiset<size_t> nodeIds, edgeIds;
                        for (size_t j = 0, M = row.at(k).table.Schema.size(); j<M; j++) {
                            if (nodes.contains(row.at(k).table.Schema.at(j))) {
                                if (std::holds_alternative<size_t>((row.at(k).table.datum.at(l).at(j).val))) {
                                    nodeIds.insert(std::get<size_t>((row.at(k).table.datum.at(l).at(j).val)));
                                }
                            }
                            else if (edges.contains(row.at(k).table.Schema.at(j))) {
                                    if (std::holds_alternative<size_t>((row.at(k).table.datum.at(l).at(j).val))) {
                                        edgeIds.insert(std::get<size_t>((row.at(k).table.datum.at(l).at(j).val)));
                                    }
                            }
                        }
                        bool multi = false;
                        for (const auto& key : nodeIds) {
                            if (nodeIds.count(key)>1) {
                                removeIndex.emplace_back(l);
                                multi = true;
                                break;
                            }
                        }
                        if (!multi) {
                            for (const auto& key : edgeIds) {
                                if (edgeIds.count(key)>1) {
                                    removeIndex.emplace_back(l);
                                    break;
                                }
                            }
                        }
                    }
                    if (!removeIndex.empty()) {
                        remove_index(row[k].table.datum, removeIndex);
                        if (row[k].table.datum.empty()) {
                            removeIndex2.emplace_back(i);
                            break;
                        }
                    }
                }
            }
            remove_index(result.datum, removeIndex2);
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
            // Populating the morphisms
            DEBUG_ASSERT(expectedOffset != -1);
            for (const auto& record : result.datum) {
                // Retrieving the graph of interest, registered at offset graphInPos
                // Then, retrieving the results associated to the pattern
                auto& local_results = morphisms[std::get<size_t>(record.at(graphInPos).val)][graph_grammar_entry_point.pattern_name];
                if (local_results.second.empty() && local_results.first.empty()) {
                    // Might not have a schema yet for efficiency purposes: now, I am setting this once and for all.
                    local_results.first = result.Schema;
                }
                // expectedOffset will contain now the information related to the main entry point.
                // This will then contain the information related to the record of interest
                if (std::holds_alternative<bool>(record.at(expectedOffset).val)) {
                    local_results.second[-1].datum.emplace_back(record);
                } else {
                    local_results.second[std::get<size_t>(record.at(expectedOffset).val)].datum.emplace_back(record);
                }
            }

            if (verbose) {
                std::ofstream file{folder / ( graph_grammar_entry_point.pattern_name+"("+std::to_string(versions++)+").ncsv")};
                serialised_nested_table(file, graph_grammar_entry_point.pattern_name, result, edges);
//                std::cout << print_table(result) << std::endl;
//                std::cout << "~~~~~~~~~~~~~~~~~~~~~~~" << std::endl<< std::endl<< std::endl;
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

std::pair<ssize_t, ssize_t> preserve_results::resolve_entry_match(size_t patternId, const std::string &element) const {
    auto it = map_orig.at(patternId).find(element);
//    ssize_t id = map_orig.at(patternId).signed_get(element);
    if (it != map_orig.at(patternId).end())
        return {-1, it->second};
    else /*if ((id < 0))*/ {
        if (nested_index.at(patternId).empty())
            return {-1, -1};
        else {
            size_t idx = 0;
            for (const auto& ref : map_nested.at(patternId)) {
                ssize_t id2 = ref.signed_get(element);
                if (id2 >=0 )
                    return {idx, id2};
                idx++;
            }
//            ssize_t id2 = map_nested.at(patternId).signed_get(element);
//            if (id2 < 0)
                return {-1, -1};
//            else
//                return {true, id2};
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
                        raw_table.table.emplace_back(graph_src.first, graph_src.second, q.first, s, e);
                    else
                        raw_table.table.emplace_back(graph_src.first, e, q.first, s, graph_src.second);
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
                raw_table.edgeLabel = raw_table.edge +"_label";
                first = {raw_table.graph, raw_table.src, raw_table.edgeLabel};
                nesting = raw_table.dst;
            } else {
                raw_table.src = dstE;// "I("+dstE+")";
//                    raw_table.score = dstE+","+var_table_edge;//"IEs("+dstE+","+raw_table.edge+")";
                raw_table.edge = var_table_edge; // + ":"+ raw_table.src;
                raw_table.edgeLabel = raw_table.edge +"_label";
                first = {raw_table.graph, raw_table.dst, raw_table.edgeLabel};
                nesting = raw_table.src;
            }
            auto& table = matching_tables.emplace_back();
            fillFrom(table, raw_table);
            DEBUG_ASSERT(table.checkSchemaSizeCompliance());
            if (isForall && isDstForall) {
                std::tie(table, ignore) = nest_or_groupby(table, first, nesting);
                DEBUG_ASSERT(table.checkSchemaSizeCompliance());
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
                for (const auto& [g,event,edgeId] : list_dst) {
                    if (filterHook && (event != graph_src.second)) continue;
                    DEBUG_ASSERT(isOutgoing == q.second);
                    if (isOutgoing)
                        raw_table.table.push_back({graph_src.first, graph_src.second, event});
                    else
                        raw_table.table.push_back({graph_src.first, event, graph_src.second});
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
            DEBUG_ASSERT(table.checkSchemaSizeCompliance());
            if (isForall && isDstForall) {
                std::tie(table, ignore) = nest_or_groupby(table, first, nesting);
                DEBUG_ASSERT(table.checkSchemaSizeCompliance());
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
