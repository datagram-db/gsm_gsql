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

//struct MatchQueryType {
//    enum type {
//        OutgoingEdge,
//        IngoingEdge,
//        NodePropertyPredicate,
//        NodeEllPredicate,
//        NodeXiPredicate
//    };
//
//    type t;
//    std::string node_label_or_ellxi_match;
//    std::string edge_label;
//    double approx_ellxi;
//    size_t maxn_ellxi;
//    DataPredicate data_predicate;
//};

#include "database/delta_updates.h"

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

    void load_query_from_file(std::ifstream& stream) {
        antlr4::ANTLRInputStream input(stream);
        simple_graph_grammarLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        simple_graph_grammarParser parser(&tokens);
        GSMPatternVisitor pv;
        vl = std::any_cast<std::vector<node_match>>(pv.visit(parser.all_matches()));
    }

    void load_data_from_file(const std::string& filename) {
        gsm2::tables::primary_memory_load_gsm2( filename, forloading);
    }

    void asGraphs(std::vector<FlexibleGraph<std::string,std::string>>& graphs) const {
        forloading.asGraphs(graphs);
    }

    void perform_query(bool materialise = false) {
        isMaterialised = false;
        pr.init(); // For future reference, if this will become a query engine!
        // TODO: rewrite the matching variables so to allow morphisms to be effectively queried
        for (auto& nm : vl) {
            pr.collect_node_match(nm, forloading);
        }
        pr.finalise_after_all_collections(forloading.all_indices.size());
        pr.run_simple_edge_queries(forloading);
        pr.instantiate_morphisms(vl);
        run_transformations();
        if (materialise) {
            generate_materialised_view();
        }
    }

    void generate_materialised_view() {
        isMaterialised = true;
        forloading.iterateOverObjects([this](size_t graphid, const gsm_object& legacy_object_old_data) {
            auto& updates = delta_updates_per_graph[graphid];
            if (!updates.hasXBeenRemoved(legacy_object_old_data.id)) {
//
                size_t new_id = legacy_object_old_data.id;
//                if (it != updates.replacement_map.end()) {
//                    new_id = it->second;
//                }
//                if (legacy_object_old_data.id == 10)
//                    std::cout << "debug" << std::endl;
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
    }

    void generateGraphsFromMaterialisedViews(std::vector<FlexibleGraph<std::string,std::string>>& simpleGraphs) {
        if (!isMaterialised)
            generate_materialised_view();
        simpleGraphs.clear();
        simpleGraphs.resize(delta_updates_per_graph.size());
        std::pair<size_t, size_t> cp;
        std::vector<yaucl::structures::any_to_uint_bimap<size_t>> nodesBeingInsertedAlready(delta_updates_per_graph.size());
        size_t offsetMainRegistryTable = 0;
        for (size_t i = 0, N = delta_updates_per_graph.size(); i<N; i++) {
            for (const auto& [idX,object] : delta_updates_per_graph.at(i).delta_plus_db.O) {
                if (delta_updates_per_graph.at(i).hasXBeenRemoved(idX)) {
                    std::cout << idX << std::endl;
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
                        } else {
                            std::cout<< idX << "--["<< edgelabel << "]-->" << record.id << std::endl;
                        }
                    }
                }
            }
        }
    }

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

//            delta_updates updates{};

            // For each graph in the actual graphs
            for (size_t time = 0, T = g.container_order.size(); time<T; time++)
                for (const auto& vertex : g.container_order.at(T-time-1)) {
                    if (vertex == 16)
                        std::cout << "debug" << std::endl;
                    for (size_t pattern_id = 0, M = vl.size(); pattern_id < M; pattern_id++) {
                        const auto& pattern = vl.at(pattern_id);
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
                                            if (idx.second >= 0) {
                                                if (idx.first) {
                                                    for (const auto& sub_entries : entries.at(pr.nested_index.at(pattern_id)).table.datum) {
                                                        size_t default_val = std::get<size_t>(sub_entries.at(idx.second).val);
                                                        updates.set_removed(default_val);
//                                                        removed_objects.add(getOrDefault(replacement_map, default_val, default_val));
                                                    }
                                                } else {
                                                    size_t default_val = std::get<size_t>(entries.at(idx.second).val);
                                                    updates.set_removed(default_val);
//                                                    removed_objects.add(getOrDefault(replacement_map, default_val, default_val));
                                                }
                                            }
                                        } break;

                                        case rewrite_to::NEU_RW: {
                                            // Allocating a new empty object, and returning this potentially in place of the previous one.
//                                            delta_plus_db.max_id++;
                                            auto& obj = updates.getNewObject(); //delta_plus_db.O[delta_plus_db.max_id];
                                            if (obj.id == 29)
                                                std::cout << "debug" << std::endl;
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

int main() {
    closure result;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Loading the query
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    std::ifstream stream{"./patterns.txt"};
    result.load_query_from_file(stream);
//    antlr4::ANTLRInputStream input(stream);
//    simple_graph_grammarLexer lexer(&input);
//    antlr4::CommonTokenStream tokens(&lexer);
//    simple_graph_grammarParser parser(&tokens);
//    GSMPatternVisitor pv;
//    auto vl =  std::any_cast<std::vector<node_match>>(pv.visit(parser.all_matches()));
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Loading the data
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // setting up the database
    result.load_data_from_file("./data/einstein.txt");
    // loading the data from the file specification

    std::vector<FlexibleGraph<std::string,std::string>> graphs;
    result.asGraphs(graphs);
    for (const auto& g : graphs){
        g.dot(std::cout, false, "record"); std::cout << std::endl;
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Starting to query
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    result.perform_query();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    result.pr.print_preliminary_edge_match_results(std::cout);

//    result.generate_materialised_view();
    graphs.clear();
    result.generateGraphsFromMaterialisedViews(graphs);
    for (const auto& g : graphs){
        g.dot(std::cout, false, "record"); std::cout << std::endl;
    }

//    std::cout << "<" << std::endl;
//
//
//    // returning all the graphs and objects ids having det as a first label
//    {
//        auto result = forloading.timed_dataless_exists("det");
//        for (const auto& x : result) {
//            std::cout << x << std::endl;
//        }
//    }
//
//    // Returning all nodes providing an approximate string matching on the node of the graph
//    {
//        auto result = forloading.approx_value_query(0.4, 100, "testem");
//        for (const auto& x : result) {
//            std::cout << x << std::endl;
//        }
//    }
//
//    // Returning all the contents for the objects having "det" as a containment collection
//    {
//        std::unordered_map<std::pair<size_t, size_t>, std::vector<result>> resulted;
//
//        // Temporary Data
//        std::vector<std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>> v;
//        forloading.query_container_or_containment(v.emplace_back(), "", "det");
//        forloading.query_container_or_containment(v.emplace_back(),"", "aux");
//        forloading.query_container_or_containment(v.emplace_back(),"", "nmod:poss");
//        multi_map_union(v, resulted, [](double x, double y)->double {
//            return std::max(x,y);
//        });
//        v.clear();
//    }
//
//    // Getting the content associated to the object {0,0}, first from the first graph
//    {
//        auto phi = forloading.phi({0,0,false}, "advmod");
//        for (const auto& x : phi) {
//            std::cout << x << std::endl;
//        } phi = forloading.phi({0,0,false}, "nsubj");
//        for (const auto& x : phi) {
//            std::cout << x << std::endl;
//        }
//    }


    return 0;
}
