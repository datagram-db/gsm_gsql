//
// Created by giacomo on 27/10/23.
//

#ifndef GSM2_CLOSURE_H
#define GSM2_CLOSURE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "database/LinearGSM.h"
#include "queries/DataPredicate.h"
#include "ANTLRInputStream.h"
#include "simple_graph_grammarLexer.h"
#include "simple_graph_grammarParser.h"
#include "database/GSMPatternVisitor.h"

// https://stackoverflow.com/a/66969964/1376095
template <typename T>
std::optional<T> get_v_opt(const std::any & tmp)
{
    try {
        return std::optional<T>(std::any_cast<T>(tmp));
    } catch (...) {
        return std::nullopt;
    }
//    std::string tmpType = tmp.type().name();
//    if(tmpType.contains(typeid(T).name()))
//        return std::optional<T>(std::any_cast<T>(tmp));
//    else
//        return std::nullopt;
}


#include "database/preserve_results.h"

template <typename T>
void fill_vector_with_case(std::vector<T>& to_fill, const abstract_value& opts) {
    if (std::holds_alternative<T>(opts))
        to_fill.emplace_back(std::get<T>(opts));
}


#include "database/delta_updates.h"

/**
 * This class is referred to Closure as it wraps around both the loaded data and the intermediate values generating
 * the resulting graph as per matching.
 */
struct closure {
    GSMPatternVisitor pv;
    std::vector<node_match> vl;

    gsm2::tables::LinearGSM forloading;

    preserve_results pr;

    std::vector<delta_updates> delta_updates_per_graph;
    std::vector<std::string> empty_string_vector;
    std::string empty_string;
    std::vector<gsm_object_xi_content> empty_content;
    bool isMaterialised = false;

    /**
     * Loading the query to be run on top of the data
     *
     * @param stream:       Filestream from which read the file
     */
    void load_query_from_file(std::ifstream& stream);

    /**
     * Loading the data to be queried
     *
     * @param filename:     Data expressed in the GSM syntax for fast parsing
     */
    void load_data_from_file(const std::string& filename);

    /**
     * For plotting purposes, representing the loaded data as graphs
     */
    void asGraphs(std::vector<FlexibleGraph<std::string,std::string>>& graphs) const;

    /**
     * For plotting purposes, generating the graphs representing the final result
     */
    void generateGraphsFromMaterialisedViews(std::vector<FlexibleGraph<std::string,std::string>>& simpleGraphs);

    void perform_query(bool materialise = false) {
        isMaterialised = false;
        pr.init(); // For future reference, if this will become a query engine, we need to clear all intermediate results first!
        // TODO: rewrite the matching variables so to allow morphisms to be effectively queried
        for (auto& nm : vl) {
            pr.collect_node_match(nm, forloading);
        }
        // Inialising the morphisms, substantiating the match for the nodes
        pr.finalise_after_all_collections(forloading.all_indices.size());
        // First, matching all the single patterns within the queries, as described in the cached results
        pr.run_simple_edge_queries(forloading);
        // Then, running each morphism separately (now, we are assuming any order will do)
        // TODO: infer the application order of the matching for generating the tables. Does this matter?
        pr.instantiate_morphisms(vl);
        // Only afterwards, we are applying all of the transformations for each of the matches collected in the tables as morphisms
        run_transformations();
        // The previous run just generate delta updates. If we want to better see the results, then we need to materialise such intermediate results
        // while providing a cohesive view of the graph.
        if (materialise) {
            generate_materialised_view();
        }
    }

    /**
     * For plotting purposes, extending the delta updates with the old objects within the originally loaded data
     */
    void generate_materialised_view();



    /**
     * Returning the content associated to either an existing node from the loaded data, or something being recently
     * created
     *
     * @param graphid       Graph Id of interest
     * @param id            ObjectId of reference
     * @param key_content   Key string associated to the φ containment function
     * @return  The contained object associated to the object. If the object is missing, we are returning an empty vector
     */
    inline std::vector<gsm_object_xi_content> resolve_content(size_t graphid,
                                                              size_t id,
                                                              const std::string& key_content) const {
        auto& updates = delta_updates_per_graph.at(graphid);
        {
            auto it = updates.replacement_map.find(id);
            if (it != updates.replacement_map.end() && (!updates.newIterationInsertedObjects.contains(it->second)))
                id = it->second;
        }
        if (updates.hasXBeenRemoved(id))
            return empty_content;
        {
            auto it = updates.delta_plus_db.O.find(id);
            if (it != updates.delta_plus_db.O.end()) {
                auto it2 =  it->second.phi.find(key_content);
//                auto it2 = it->second.content.find(key_prop);
                if (it2 != it->second.phi.end()) {
                    return it2->second;
                }
            }
        }
        auto legacy = forloading.resolveContent(graphid, id, key_content);
        bool subst=false;
        for (auto& ref : legacy) {
            auto& map = delta_updates_per_graph.at(graphid).replacement_map;
            auto it =  (map.find(ref.id));
            if (it != map.end()) {
                ref.id = it->second;
                subst = true;
            }
        }
        if (subst)
            remove_duplicates(legacy);
        return legacy;
    }

    /**
     * Resolving a property π associated to the node. This behaves similarly to resolve_content
     *
     * @param graphid
     * @param id
     * @param key_prop
     * @return
     */
    inline std::string resolve_prop(size_t graphid, size_t id, const std::string& key_prop) const {
        auto& updates = delta_updates_per_graph.at(graphid);
        {
            auto it = updates.replacement_map.find(id);
            if (it != updates.replacement_map.end() && (!updates.newIterationInsertedObjects.contains(it->second)))
                id = it->second;
        }
        if (updates.hasXBeenRemoved(id))
            return empty_string;
        {
            auto it = updates.delta_plus_db.O.find(id);
            if (it != updates.delta_plus_db.O.end()) {
                auto it2 = it->second.content.find(key_prop);
                if (it2 != it->second.content.end()) {
                    return it2->second;
                }
            }
        }
        std::optional<union_minimal> result = forloading.resolveProperties(graphid, id, key_prop);
        if (result.has_value()) {
            if (std::holds_alternative<std::string>(result.value()))
                return std::get<std::string>(result.value());
            else
                return std::to_string(std::get<double>(result.value()));
        } else
            return empty_string;
    }

    inline const std::vector<std::string>& resolve_ell(size_t graphid, size_t id) const {
        return resolve_ellxi(graphid, id, false);
    }

    inline const std::vector<std::string>& resolve_xi(size_t graphid, size_t id) const {
        return resolve_ellxi(graphid, id, true);
    }

private:

    inline const std::vector<std::string>& resolve_ellxi(size_t graphid, size_t id, bool isXiEllOtherwise) const {
        auto& updates = delta_updates_per_graph.at(graphid);
        {
            auto it = updates.replacement_map.find(id);
            if (it != updates.replacement_map.end() && (!updates.newIterationInsertedObjects.contains(it->second)))
                id = it->second;
        }
        if (updates.hasXBeenRemoved(id))
            return empty_string_vector;
        {
            auto it = updates.delta_plus_db.O.find(id);
            if (it != updates.delta_plus_db.O.end()) {
                if (isXiEllOtherwise) {
                    if (!it->second.xi.empty()) {
                        return it->second.xi;
                    }
                } else {
                    if (!it->second.ell.empty()) {
                        return it->second.ell;
                    }
                }

            }
        }
        return isXiEllOtherwise ? forloading.xi(graphid, id) : forloading.ell(graphid, id);
    }

    /**
     *
     */
    void interpret_closure_set(rewrite_expr* ptr,
                               size_t graph_id,
                               size_t pattern_id,
                               const std::vector<std::string>& schema,
                               const nested_table& table,
                               size_t record_id,
                               std::any match_rhs) {
        if (!ptr)
            return;
        switch (ptr->t) {
            case rewrite_expr::NONE_CASES_REWRITE:
                break;
            case rewrite_expr::NODE_XI: {
                size_t xi_offset = ptr->id;
                auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id));
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
                for (const auto& id : object_ids) {
                    auto& xi = delta_updates_per_graph[graph_id].delta_plus_db.generateId(id).xi;
                    if (xi.size() <= xi_offset)
                        xi.insert(xi.end(), xi.size()-xi_offset+1, "");
                    xi[xi_offset] = std::any_cast<std::string>(match_rhs);
                }
            } break;

            case rewrite_expr::NODE_ELL: {
                size_t ell_offset = ptr->id;
                auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id));
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
                for (const auto& id : object_ids) {
                    auto& ell = delta_updates_per_graph[graph_id].delta_plus_db.generateId(id).ell;
                    if (ell.size() <= ell_offset)
                        ell.insert(ell.end(), ell.size()-ell_offset+1, "");
                    ell[ell_offset] = std::any_cast<std::string>(match_rhs);
                }
            } break;

            case rewrite_expr::NODE_PROP: {
                auto prop_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->pi_key_arg_or_then.get(), graph_id, pattern_id, schema, table, record_id));
                auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id));
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);
                for (const auto& id : object_ids) {
                    delta_updates_per_graph[graph_id].delta_plus_db.generateId(id).content[prop_name] = std::any_cast<std::string>(match_rhs);
                }
            } break;

            case rewrite_expr::NODE_CONT: {
                auto prop_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->pi_key_arg_or_then.get(), graph_id, pattern_id, schema, table, record_id));
                auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id));
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
                std::string L, R;
                if (std::holds_alternative<std::string>(ptr->ifcond.first)) {
                    L = std::get<std::string>(ptr->ifcond.first);
                } else {
                    auto j = std::get<std::shared_ptr<rewrite_expr>>(ptr->ifcond.first).get();
                    L = std::any_cast<std::string>(interpret_closure_evaluate(j, graph_id, pattern_id, schema, table, record_id));
                }
                if (std::holds_alternative<std::string>(ptr->ifcond.second)) {
                    R = std::get<std::string>(ptr->ifcond.second);
                } else {
                    auto j = std::get<std::shared_ptr<rewrite_expr>>(ptr->ifcond.second).get();
                    R = std::any_cast<std::string>(interpret_closure_evaluate(j, graph_id, pattern_id, schema, table, record_id));
                }
                if (L == R) {
                    return interpret_closure_set(ptr->pi_key_arg_or_then.get(), graph_id, pattern_id, schema, table, record_id, match_rhs);
                } else {
                    return interpret_closure_set(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id, match_rhs);
                }
            } break;

            case rewrite_expr::NODE_OR_EDGE:
                break;
        }
    }


    std::any interpret_closure_evaluate(rewrite_expr* ptr,
                                        size_t graph_id,
                                        size_t pattern_id,
                                        const std::vector<std::string>& schema,
                                        const nested_table& table,
                                        size_t record_id) {
        if (!ptr)
            return {};
        switch (ptr->t) {
            // Returning the specific XI for the nodes
            case rewrite_expr::NODE_XI: {
                size_t xi_offset = ptr->id;
                auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id));
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);

                // for each object_id in the vector, I continuously append
                return std::accumulate(
                        object_ids.begin(),
                        object_ids.end(),
                        std::string(""),
                        [this,graph_id,xi_offset](const std::string& b, size_t a) {
                            const auto& resolution = resolve_xi(graph_id,a);
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
                auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id,schema,  table, record_id));
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);

                // for each object_id in the vector, I continuously append
                return std::accumulate(
                        object_ids.begin(),
                        object_ids.end(),
                        std::string(""),
                        [this,graph_id,ell_offset](const std::string& b, size_t a) {
                            const auto& resolution = resolve_ell(graph_id,a);
                            if (b.empty())
                                return resolution.empty() ? "" : resolution.at(ell_offset);
                            else
                                return  b + (resolution.empty() ? "" : " "+resolution.at(ell_offset));
                        }
                );
            }

                // Returning the property associated to a node
            case rewrite_expr::NODE_PROP: {
                auto prop_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->pi_key_arg_or_then.get(), graph_id, pattern_id,schema,  table, record_id));
                auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id,schema,  table, record_id));
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);

                // for each object_id in the vector, I continuously append
                return std::accumulate(
                        object_ids.begin(),
                        object_ids.end(),
                        std::string(""),
                        [this,graph_id,prop_name](const std::string& b, size_t a) {
                            if (b.empty())
                                return resolve_prop(graph_id, a, prop_name);
                            else
                                return  b + " " + resolve_prop(graph_id, a, prop_name);
                        }
                );
            } break;

            case rewrite_expr::NODE_CONT: {
                size_t ell_offset = ptr->id;
                auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id));
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolveIdsOverVariableName(graph_id, pattern_id, variable_name, record);

                std::vector<gsm_object_xi_content> collected;
                for (size_t id : object_ids) {
                    auto local = resolve_content(graph_id, id, variable_name);
                    collected.insert(collected.end(), local.begin(), local.end());
                }
                remove_duplicates(collected);
                return collected;
            } break;

                // Returning the edge label (if nested, imploding the collection into a string!) TODO: what if we need singled out?
            case rewrite_expr::EDGE_LABEL: {
                auto variable_name = std::any_cast<std::string>(interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id));
                const auto& record = table.datum.at(record_id);
                auto object_ids = resolvelabelsOverVariableName(pattern_id, variable_name, record);
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
                std::string L, R;
                if (std::holds_alternative<std::string>(ptr->ifcond.first)) {
                    L = std::get<std::string>(ptr->ifcond.first);
                } else {
                    auto j = std::get<std::shared_ptr<rewrite_expr>>(ptr->ifcond.first).get();
                    L = std::any_cast<std::string>(interpret_closure_evaluate(j, graph_id, pattern_id,schema,  table, record_id));
                }
                if (std::holds_alternative<std::string>(ptr->ifcond.second)) {
                    R = std::get<std::string>(ptr->ifcond.second);
                } else {
                    auto j = std::get<std::shared_ptr<rewrite_expr>>(ptr->ifcond.second).get();
                    R = std::any_cast<std::string>(interpret_closure_evaluate(j, graph_id, pattern_id, schema, table, record_id));
                }
                if (L == R) {
                    return interpret_closure_evaluate(ptr->pi_key_arg_or_then.get(), graph_id, pattern_id,schema,  table, record_id);
                } else {
                    return interpret_closure_evaluate(ptr->ptr_or_else.get(), graph_id, pattern_id, schema, table, record_id);
                }
            } break;

//            case rewrite_expr::EDGE_SRC:
//            case rewrite_expr::EDGE_DST:
//            case rewrite_expr::NODE_OR_EDGE:
            default:
                throw std::runtime_error("UNSUPPORTED OPERATION (FUTURE)");
                break;
        }
    }

    std::vector<std::string>
    resolvelabelsOverVariableName(size_t pattern_id, const std::string &variable_name, const std::vector<value> &record) {
        std::vector<std::string> object_id;
        auto offset = pr.resolve_entry_match(pattern_id, variable_name);
        if (offset.second<0)
            return object_id;
        if (!offset.first) {
            const auto& cell = record.at(offset.second);
            if (cell.isNested) {
                size_t actualNestedOffset = -1;
                for (size_t k = 0, N = cell.table.Schema.size(); k<N; k++) {
                    if (cell.table.Schema.at(k) == variable_name){
                        actualNestedOffset = k;
                        break;
                    }
                }
                DEBUG_ASSERT(actualNestedOffset != -1);
                for (const auto& record_internal : record.at(offset.second).table.datum) {
                    const auto& cell2 = record_internal.at(actualNestedOffset);
                    DEBUG_ASSERT(!cell2.isNested);
                    fill_vector_with_case(object_id, cell2.val);
                }
            } else {
                fill_vector_with_case(object_id, cell.val);
            }
        } else {
            for (const auto& record_internal : record.at(pr.nested_index.at(pattern_id)).table.datum) {
                const auto& cell = record_internal.at(offset.second);
                DEBUG_ASSERT(!cell.isNested);
                fill_vector_with_case(object_id, cell.val);
            }
        }
        remove_duplicates(object_id);
        return object_id;
    }



    std::vector<size_t>
    resolveIdsOverVariableName(size_t graph_id, size_t pattern_id, const std::string &variable_name, const std::vector<value> &record) {
        std::vector<size_t> object_id;
        auto v = delta_updates_per_graph.at(graph_id).getNewlyInsertedVertices(variable_name);
        if (!v.empty())
            return v;
        auto offset = pr.resolve_entry_match(pattern_id, variable_name);
        if (offset.second<0)
            return object_id;
        if (!offset.first) {
            const auto& cell = record.at(offset.second);
            if (cell.isNested) {
                size_t actualNestedOffset = -1;
                for (size_t k = 0, N = cell.table.Schema.size(); k<N; k++) {
                    if (cell.table.Schema.at(k) == variable_name){
                        actualNestedOffset = k;
                        break;
                    }
                }
                DEBUG_ASSERT(actualNestedOffset != -1);
                for (const auto& record_internal : record.at(offset.second).table.datum) {
                    const auto& cell2 = record_internal.at(actualNestedOffset);
                    DEBUG_ASSERT(!cell2.isNested);
                    fill_vector_with_case(object_id, cell2.val);
                }
            } else {
                fill_vector_with_case(object_id, cell.val);
            }
        } else {
            for (const auto& record_internal : record.at(pr.nested_index.at(pattern_id)).table.datum) {
                const auto& cell = record_internal.at(offset.second);
                DEBUG_ASSERT(!cell.isNested);
                fill_vector_with_case(object_id, cell.val);
            }
        }
        bool subst=false;
        for (auto& ref : object_id) {
            auto& map = delta_updates_per_graph.at(graph_id).replacement_map;
            auto it =  (map.find(ref));
            if (it != map.end() && (!delta_updates_per_graph.at(graph_id).newIterationInsertedObjects.contains(it->second))) {
                ref = it->second;
                subst = true;
            }
        }
        remove_duplicates(object_id);
        return object_id;
    }

    void run_transformations() {
        delta_updates_per_graph.clear();
        for (size_t i = 0, N = forloading.all_indices.size(); i<N; i++) {
            delta_updates_per_graph.emplace_back(forloading.main_registry.secondary_index.at(i).second->event_id);
        }
        for (size_t graph_id = 0, N = forloading.all_indices.size(); graph_id < N; graph_id++) { // on parallel...do
            // For each graph in the collection
            const auto& g = forloading.all_indices.at(graph_id);
            const auto& morphs = pr.morphisms.at(graph_id);
            auto& updates = delta_updates_per_graph.at(graph_id);

            // For each graph in the actual graphs
            for (size_t time = 0, T = g.container_order.size(); time<T; time++)
                for (const auto& vertex : g.container_order.at(T-time-1)) {
//                    if (vertex == 16)
//                        std::cout << "debug" << std::endl;
                    for (size_t pattern_id = 0, M = vl.size(); pattern_id < M; pattern_id++) {
                        const auto& pattern = vl.at(pattern_id);
                        if (morphs.find(pattern.pattern_name) == morphs.end())
                            continue;
                        const auto& pattern_result = morphs.at(pattern.pattern_name);
                        DEBUG_ASSERT(pattern.var.size() == 1);

                        // Ignoring the match if this was removed!
                        if (updates.hasXBeenRemoved(vertex)) continue;

                        // Whether there was a single node being matched
                        auto it = pattern_result.second.find(vertex);
                        if (it != pattern_result.second.end()) {
                            updates.clear_insertions();
//                            DEBUG_ASSERT(updates.replacement_map.find(vertex) == updates.replacement_map.end());
                            size_t table_offset = 0;
                            for (const auto& entries : it->second.datum) {
                                for (const auto& operation : pattern.rwr_to) {
                                    switch (operation.t) {

                                        case rewrite_to::DEL_RW:
                                        {
                                            // Removing objects from the final result
                                            auto idx = pr.resolve_entry_match(pattern_id, operation.others);
                                            if (idx.second >= 0) { // If this is in the table
                                                if (idx.first) { // If a nested variable, removing all the associated entries in the nested
                                                    for (const auto& sub_entries : entries.at(pr.nested_index.at(pattern_id)).table.datum) {
                                                        size_t default_val = std::get<size_t>(sub_entries.at(idx.second).val);
                                                        updates.set_removed(default_val);
                                                    }
                                                } else { // Otherwise, just removing this instance
                                                    size_t default_val = std::get<size_t>(entries.at(idx.second).val);
                                                    updates.set_removed(default_val);
                                                }
                                            }
                                        } break;

                                        case rewrite_to::NEU_RW: {
                                            // Allocating a new empty object, and returning this potentially in place of the previous one.
                                            // Then, associating this to a new variable, not in the morphisms, but in the delta updates
//                                            delta_plus_db.max_id++;
                                            auto& obj = updates.getNewObject(); //delta_plus_db.O[delta_plus_db.max_id];
//                                            if (obj.id == 29)
//                                                std::cout << "debug" << std::endl;
                                            updates.associateNewToVar(operation.others, obj.id);
//                                            obj.id = delta_plus_db.max_id;
//                                            auto idx = pr.resolve_entry_match(j, operation.others);
//                                            newly_inserted_vertices[operation.others].emplace_back(obj.id);

                                        } break;

                                        case rewrite_to::SET_RW: {
                                            DEBUG_ASSERT(operation.from);
                                            DEBUG_ASSERT(operation.to);

                                            std::any rhs = interpret_closure_evaluate(operation.from.get(), graph_id, pattern_id, pattern_result.first, it->second, table_offset);
                                            interpret_closure_set(operation.to.get(), graph_id, pattern_id, pattern_result.first, it->second, table_offset, rhs);
                                        } break;

                                        case rewrite_to::NONE_OF_REWRITE:
                                            break;
                                    }
                                }
//                                if (pattern_id == 2)
//                                    std::cout << "debug" << std::endl;
                                if (pattern.rewrite_match_dst && (pattern.rewrite_match_dst->var.at(0) != pattern.var.at(0))) {
                                    // Perform the rewrite only if the variables appear to be different
                                    if (pattern.vec) {
                                        DEBUG_ASSERT(pattern.in.size() == 1);
                                        DEBUG_ASSERT(pattern.in.at(0).first.var.size() == 1);
                                        auto toReplace = resolveIdsOverVariableName(graph_id, pattern_id, pattern.var.at(0), entries);
                                        auto replaceWith = resolveIdsOverVariableName(graph_id, pattern_id, pattern.rewrite_match_dst->var.at(0), entries);
                                        auto originals = resolveIdsOverVariableName(graph_id, pattern_id, pattern.in.at(0).first.var.at(0), entries);
                                        for (size_t check : toReplace) {
                                            for (size_t id : replaceWith) {
//                                                delta_updates_per_graph[0].replaceWith(check, id);
                                                delta_updates_per_graph[graph_id].replaceWith(check, id);
                                                for (size_t orig : originals) {
                                                    for (const auto& contK : forloading.containment_relationships) {
                                                        auto content = resolve_content(graph_id, orig, contK);
                                                        for (const auto& containmentRel : content) {
                                                            if (containmentRel.id == check) {
                                                                delta_updates_per_graph[graph_id].delta_plus_db.O[orig].phi[contK].emplace_back(id);
                                                            }
                                                        }
                                                    }
                                                }

                                            }
                                        }



//
//                                                    auto tmp = pr.resolve_entry_match(j, pattern.in.at(0).first.var.at(0));
//                                                    DEBUG_ASSERT(tmp.second >= 0);
//                                                    auto result = entries.at(tmp.second);
//                                                    if (std::holds_alternative<size_t>(result.val)) {
//                                                        updates.replaceWith(std::get<size_t>(result.val), obj.id);
//                                                    }

//                                                    replacement_map[result.second] = obj.id;
                                    } else {
                                        DEBUG_ASSERT(pattern.var.size() == 1);
//                                    auto tmp = pr.resolve_entry_match(pattern_id, pattern.var.at(0));
//                                    DEBUG_ASSERT(tmp.second >= 0);
                                        auto originals = resolveIdsOverVariableName(graph_id, pattern_id, pattern.var.at(0), entries);
                                        auto replacements = resolveIdsOverVariableName(graph_id, pattern_id, pattern.rewrite_match_dst->var.at(0), entries);
                                        for (size_t orig : originals) {
                                            for (size_t repl : replacements) {
                                                updates.replaceWith(orig, repl);
                                            }
                                        }
//                                        auto result = entries.at(tmp.second);
//                                        if (std::holds_alternative<size_t>(result.val)) {
//                                            updates.replaceWith(std::get<size_t>(result.val), obj.id);
//                                        }
//                                                    replacement_map[result.second] = obj.id;
                                    }
                                }
                                table_offset++;
                            }

                        }
                    }
//            }
                }
        }
    }
};

#endif //GSM2_CLOSURE_H
