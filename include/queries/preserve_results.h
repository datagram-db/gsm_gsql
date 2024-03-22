/*
 * preserve_results.h
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

#ifndef GSM2_PRESERVE_RESULTS_H
#define GSM2_PRESERVE_RESULTS_H

#include "database/utility.h"
#include "yaucl/structures/any_to_uint_bimap.h"
#include <vector>
#include <string>
#include <unordered_set>
#include "database/LinearGSM.h"
#include "database/GSMPatternVisitor.h"
#include "database/GraphEdgeMatchTable.h"

/**
 * Preserves the representation of the morphisms from the pattern match
 */
struct preserve_results {
    // Intermediate queries associated to the ingoing/outgoing edges
    yaucl::structures::any_to_uint_bimap<std::pair<std::string,bool>> edge_query_ref; //bool=true, out. bool=false, in.
    std::vector<std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>> out;
    std::unordered_set<std::string> copyOut, copyIn;
//    std::vector<results_to_preserve> intermediate_graph_view_delta_updates;

    std::vector<std::unordered_map<std::string,size_t>> map_orig;
    std::vector<std::vector<size_t>> nested_index;
    std::vector<std::vector<yaucl::structures::any_to_uint_bimap<std::string>>> map_nested;

    /**
     * Under the assumption that the algorithm will only consider * as the main entry-point for handling the
     * content,
     * @param patternId     Specific graph grammar element.
     * @param element       Variable id
     *
     * @return returning a pair, determining whether the offset of the schema refers to a field within the main
     *         table or a field within *
     */
    std::pair<ssize_t, ssize_t> resolve_entry_match(size_t patternId, const std::string& element) const;


    /**
     * Preparse running the system by clearing all the maps
     */
    void init();

    /**
     * Loading the matching patterns within a nested relational table
     *
     * @param matching_tables       Resulting tables resulting from the match, where each table will be natural equi-joined
     * @param entry_pattern         entry variable associated to the pattern
     * @param edge                  Single edge match, from which extract the data
     * @param dst                   Target id node.
     * @param isOutgoing            Whether the pattern represents an outgoing edge, an ingoing otherwise
     * @param filterHook            Whether the pattern represents a hook
     */
    void
    loadColumnarTablesFromEdges(std::vector<nested_table> &matching_tables,
                                const std::string &entry_pattern,
                                const edge_match &edge,
                                const node_match &dst,
                                bool isOutgoing = true,
                                bool filterHook = false);

    std::vector<std::unordered_map<std::string, std::pair<std::vector<std::string>, std::unordered_map<size_t, nested_table>>>> morphisms; // graph to morphism

    /**
     * Given the collection of patterns, it instantiates the morphisms for each GSM database being loaded
     * mapping each variable in the pattern to a GSM object id or a containment label
     *
     * @param vl    Collection of patterns
     */
    void instantiate_morphisms(const std::vector<node_match>& vl, bool verbose = false, const std::unordered_set<std::string>& nodes = {}, const std::unordered_set<std::string>& edges = {}, const std::string& output_folder = "");

    /**
     * Preparing teh hook queries edges
     * @param emptyOutRefs
     * @param q
     * @param src_and_dst
     */
    void
    extractForHook(std::vector<edge_match *> &emptyOutRefs,
                   std::pair<std::string, bool> &q,
                   edge_match &src_and_dst);

    /**
     * Preparing the outgoing edges queries
     * @param emptyOutRefs
     * @param q
     * @param outEdge
     */
    void
    getOutgoingEdge(std::vector<edge_match*> &emptyOutRefs,
                    std::pair<std::string, bool> &q,
                    edge_match &outEdge);

    /**
     * Preparing the ingoing edges queries
     */
    void
    extractIngoingEdge(std::vector<edge_match *> &emptyInRefs,
                       std::pair<std::string, bool> &q,
                       edge_match &inEdge);

    /**
     * Prepares the queries associated to the pattern by associating each atomic value to the object
     *
     * @param graph_pattern     Graph pattern to be resolved
     * @param storage           Storage where to perform the queries
     */
    void collect_node_match(node_match& graph_pattern,
                            gsm2::tables::LinearGSM& storage);

    /**
     * Initalises the query answering systems by clearning the previous matches
     *
     * @param nGraphs   number of GSM databases loded in the dataset
     */
    void finalise_after_all_collections(size_t nGraphs);


    /**
     * Running all the tokenized queries over the dataset
     * @param storage   Storage over which perform the queries
     */
    void run_simple_edge_queries(gsm2::tables::LinearGSM& storage);


    void print_preliminary_edge_match_results(std::ostream& os);
};

#endif //GSM2_PRESERVE_RESULTS_H
