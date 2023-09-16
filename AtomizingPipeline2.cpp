//
// Created by giacomo on 17/08/23.
//

#include "AtomizingPipeline2.h"

//
// Created by giacomo on 16/04/2022.
//
#include <yaucl/structures/StringPrevNext.h>
#include <yaucl/structures/set_operations.h>

std::string AtomizingPipeline2::generate_fresh_atom() {
    return fresh_atom_label+std::to_string(count_fresh_atoms++);
}

void AtomizingPipeline2::clear() {
    count_fresh_atoms = 0;

    map1.clear();
    act_atoms.clear();
    atom_universe.clear();
    act_universe.clear();

    double_bulk_map.clear();
    double_map.clear();
    string_bulk_map.clear();
    string_map.clear();

    interval_map.clear();
    clause_to_atomization_map.clear();
    Mcal.clear();
    max_ctam_iteration.clear();
}

semantic_atom_set AtomizingPipeline2::atom_decomposition(const std::string &act, bool isNegated) {
    semantic_atom_set S;
    auto it = interval_map.find(act);
    if (it == interval_map.end()) {
        // If the atom is not associated to an interval, then return the atom itself
        DEBUG_ASSERT(act_atoms.contains(act));
        S.insert(act);
    } else {
        std::pair<std::string, size_t> cp; // convenience element, so not to re-allocate the memory all the time
        cp.first = act;
        for (size_t i = 0, N = max_ctam_iteration.at(act); i<N; i++) {
            cp.second = i;
            S.insert(clause_to_atomization_map.at(cp));
        }
    }
    return isNegated ? unordered_difference(atom_universe, S) : S;
}

semantic_atom_set AtomizingPipeline2::interval_decomposition(const DataPredicate &pred, bool isNegated) {
    semantic_atom_set S;
    if (pred.isStringPredicate()) {
        const auto V = std::get<0>(pred.decompose_single_variable_into_intervals());
        auto& ref = string_map.at(pred.label).at(pred.var);
        for (const auto& cp : V) {
            for (const auto& I : ref.findInterval(cp.first, cp.second)) {
                DataPredicate dp{pred.label, pred.var, I.first, I.second};
                DEBUG_ASSERT(Mcal.contains(dp));
                auto v = Mcal.at(dp);
                S.insert(v.begin(), v.end());
            }
        }
    } else {
        const auto V = std::get<1>(pred.decompose_single_variable_into_intervals());
        auto& ref = double_map.at(pred.label).at(pred.var);
        for (const auto& cp : V) {
            for (const auto& I : ref.findInterval(cp.first, cp.second)) {
                DataPredicate dp{pred.label, pred.var, I.first, I.second};
                DEBUG_ASSERT(Mcal.contains(dp));
                auto v = Mcal.at(dp);
                S.insert(v.begin(), v.end());
            }
        }
    }
    return isNegated ? unordered_difference(atom_universe, S) : S;
}

std::ostream &operator<<(std::ostream &os, const AtomizingPipeline2 &pipeline) {
    os.precision(17);
    os << "Sigma " << std::endl << std::endl;
    os << " * Single acts: " << std::endl;
    os << "================" << std::endl;
    for (const auto& ref : pipeline.act_atoms) {
        os << "    " << ref << std::endl;
    }
    os << std::endl << std::endl;
    os << " * Sigma Boxes: " << std::endl;
    os << "================" << std::endl;
    std::pair<std::string, size_t> cp;         // Just a copy object for the query
    for (const auto& k : pipeline.interval_map) {
        os << "   - " << k.first << std::endl; // Event label
        cp.first = k.first;                    // cp = <Event Label, ...>
        for (size_t i = 0, N = pipeline.max_ctam_iteration.at(cp.first); i<N; i++) {
            cp.second = i;                     // cp = <Event Label, Offset>
            os << "        * "
               << pipeline.clause_to_atomization_map.at(cp) // Atom Name
               << " --> "
               << k.second.at(i)               // Data Predicates in conjunction
               << std::endl;
        }
    }


    os << std::endl << std::endl;
    os << " * Predicate Conversions: " << std::endl;
    os << "==========================" << std::endl;
    for (const auto& k : pipeline.Mcal) {
        os << "   - " << k.first<< " --> " << k.second << std::endl;
    }
    return os;
}

//#include <yaucl/bpm/SimpleXESSerializer.h>
#include <random>

static inline bool are_all_printable(const std::string& s) {
    if ( std::all_of( s.begin(), s.end(), []( char c ) { return std::isgraph( c ); } ) )
    {
        return true;
    } return false;
}

//void AtomizingPipeline2::serialize_atom_list_to_xes(const std::vector<std::vector<std::string>> &atomised_log,
//                                                   std::ostream &xes) const {
////    constexpr size_t record_size = sizeof(ActTable::record);
//    begin_log(xes);
//    std::mt19937_64 eng{0};
//    for (size_t trace_id = 0, N = atomised_log.size(); trace_id < N; trace_id++) {
//        const auto& trace = atomised_log.at(trace_id);
//        serialise_trace(xes, eng, trace_id, trace);
//    }
//    end_log(xes);
//}

//void AtomizingPipeline::serialise_trace(std::ostream &xes, std::mt19937_64 &eng, size_t trace_id,
//                                        const std::vector<std::string> &trace) const {
//
//    begin_trace_serialize(xes, std::to_string(trace_id));
//    for (size_t event_id = 0, M = trace.size(); event_id<M; event_id++) {
//        const auto& atom_p = trace.at(event_id);
//        serialise_event_in_trace(xes, eng, atom_p);
//    }
//    end_trace_serialize(xes);
//}
//
//void AtomizingPipeline::serialise_event_in_trace(std::ostream &xes,
//                                                 std::mt19937_64 &eng,
//                                                 const std::basic_string<char> &atom_p) const {
//    static const char MIN_CHAR = static_cast<char>(33);
//    static const char MAX_CHAR = static_cast<char>(126);
//    static const char MIN_NP_CHAR = static_cast<char>(std::numeric_limits<unsigned char>::min()+1);
//    static const char MAX_NP_CHAR = static_cast<char>(std::numeric_limits<unsigned char>::max());
//    static const std::uniform_real_distribution<double>   prob(0.0, 1.0);
//    begin_event_serialize(xes);
//    auto it = atom_to_conjunctedPredicates.find(atom_p);
//    if (it == atom_to_conjunctedPredicates.end()) {
//        serialize_event_label(xes, atom_p, -1);
//    } else {
//        bool firstLabel = true;
//        for (const auto& dp : it->second) {
//            if (firstLabel) {
//                serialize_event_label(xes, dp.label, -1);
//                firstLabel = false;
//            }
//            const std::string& var = dp.var;
//            DEBUG_ASSERT(dp.casusu == INTERVAL);
//            if (std::holds_alternative<double>(dp.value)) {
//                std::uniform_int_distribution<size_t> distrI((size_t)std::get<double>(dp.value), (size_t)std::get<double>(dp.value_upper_bound));
////                std::uniform_real_distribution<double>    distr(std::get<double>(dp.value), std::get<double>(dp.value_upper_bound));
//                serialize_event_attribute(xes, var, std::clamp((double)distrI(eng),std::get<double>(dp.value),std::get<double>(dp.value_upper_bound)) );
//            } else {
//                std::vector<std::string> values;
//                values.reserve(100);
//                std::string min = std::get<std::string>(dp.value);
//                std::replace( min.begin(), min.end(), MIN_NP_CHAR, MIN_CHAR);
//                std::replace( min.begin(), min.end(), MAX_NP_CHAR, MAX_CHAR);
////                        min = next_printable_char(std::get<std::string>(dp.value), DataPredicate::msl);
//                std::string max = std::get<std::string>(dp.value_upper_bound);
//                std::replace( max.begin(), max.end(), MIN_NP_CHAR, MIN_CHAR);
//                std::replace( max.begin(), max.end(), MAX_NP_CHAR, MAX_CHAR);
//                max = prev_printable_char(max, DataPredicate::msl);
//                while ((min <= max) && (values.size() <= 100)) {
//                    if (are_all_printable(min))
//                        values.emplace_back(min);
//                    min = next_printable_char(min, DataPredicate::msl);
//                }
//                if (values.empty()) {
//                    serialize_event_attribute(xes, var, std::get<std::string>(dp.value));
//                } else {
//                    std::uniform_int_distribution<size_t>    distr(0, values.size()-1);
//                    serialize_event_attribute(xes, var, values.at(distr(eng)));
//                }
//            }
//        }
//    }
//    end_event_serialize(xes);
//}

#include <chrono>
#include <yaucl/functional/assert.h>


double collect_data_from_declare_disjunctive_model(const std::unordered_set<std::string>& all_labels,
                                                   const yaucl::structures::any_to_uint_bimap<std::string>& map,
                                                   AtomizingPipeline2 &pipeline_data,
                                                   const node_data_predicate_references &disjoint_model) {
    // old: pipeline_scratch, init_pipeline(3)
    //std::cout << "Collecting the atoms from the formula" << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::unordered_set<std::string> metAtomsGlobally;
    for (const auto& [name,ls] : disjoint_model) {
        for (const auto& itemList : ls.second) {
            for (const auto& item : itemList) {
                auto& formula_numeric_atom = item.second;
                if (formula_numeric_atom.casusu == TTRUE) continue;
                if (formula_numeric_atom.label.empty()) {
                    for (const auto& label : all_labels) {
                        pipeline_data.map1[label][formula_numeric_atom.var].insert(formula_numeric_atom);
                        auto x = formula_numeric_atom.decompose_single_variable_into_intervals();
                        if (formula_numeric_atom.isStringPredicate()) {
                            auto  V = std::get<0>(x);
                            pipeline_data.string_bulk_map[label][formula_numeric_atom.var].insert(V.begin(), V.end());
                        } else {
                            auto  V = std::get<1>(x);
                            pipeline_data.double_bulk_map[label][formula_numeric_atom.var].insert(V.begin(), V.end());
                        }
                    }
                } else {
                    pipeline_data.map1[formula_numeric_atom.label][formula_numeric_atom.var].insert(formula_numeric_atom);
                    auto x = formula_numeric_atom.decompose_single_variable_into_intervals();
                    if (formula_numeric_atom.isStringPredicate()) {
                        auto  V = std::get<0>(x);
                        pipeline_data.string_bulk_map[formula_numeric_atom.label][formula_numeric_atom.var].insert(V.begin(), V.end());
                    } else {
                        auto  V = std::get<1>(x);
                        pipeline_data.double_bulk_map[formula_numeric_atom.label][formula_numeric_atom.var].insert(V.begin(), V.end());
                    }
                }
            }
        }

    }

    // init_pipeline(4)
    //std::cout << "Collecting the atoms associated to no interval" << std::endl;
    for (const auto& act : pipeline_data.act_universe) {
        auto it1 = pipeline_data.double_bulk_map.find(act);
        bool test1 = (it1 == pipeline_data.double_bulk_map.end()) || (it1->second.empty());
        auto it2 = pipeline_data.string_bulk_map.find(act);
        bool test2 = (it2 == pipeline_data.string_bulk_map.end()) || (it2->second.empty());
        if (test1 && test2) {
            pipeline_data.act_atoms.insert(act);
            pipeline_data.atom_universe.insert(act);
        }
    }

    if ((!pipeline_data.double_bulk_map.empty()) || (!(pipeline_data.string_bulk_map.empty()))) {
        for (auto ref = pipeline_data.string_bulk_map.begin(); ref != pipeline_data.string_bulk_map.cend(); ){
            for (auto& ref2 : ref->second) {
                std::vector<DataPredicate> result;

                // old: perform_insertion
                pipeline_data.string_map[ref->first][ref2.first] =
                        ref2.second.finalize<StringPrevNext>(pipeline_data.s_min, pipeline_data.s_max);
                auto ref2Second = pipeline_data.string_map[ref->first][ref2.first];

                for (const auto& I : ref2Second.collect_intervals2()) {
                    result.emplace_back(ref->first, ref2.first, I.first, I.second);
                }
                pipeline_data.interval_map[ref->first].emplace_back(result);
            }
            ref = pipeline_data.string_bulk_map.erase(ref); // Clearing the map from bulk insertions while iterating.
        }

        for (auto ref = pipeline_data.double_bulk_map.begin(); ref != pipeline_data.double_bulk_map.cend(); ){
            for (auto& ref2 : ref->second) {
                std::vector<DataPredicate> result;

                // old: perform_insertion
                pipeline_data.double_map[ref->first][ref2.first] =
                        ref2.second.finalize<DoublePrevNext>(pipeline_data.d_min, pipeline_data.d_max);
                auto ref2Second = pipeline_data.double_map[ref->first][ref2.first];

                for (const auto& I : ref2Second.collect_intervals2()) {
                    result.emplace_back(ref->first, ref2.first, I.first, I.second);
                }
                pipeline_data.interval_map[ref->first].emplace_back(result);
            }
            ref = pipeline_data.double_bulk_map.erase(ref); // Clearing the map from bulk insertions while iterating.
        }

        for (auto& ref: pipeline_data.interval_map) {
            std::vector<std::vector<DataPredicate>> W;
            for (const auto& v : cartesian_product(ref.second)) {
                std::vector<DataPredicate> V;
                V.insert(V.end(), v.begin(), v.end());
                W.emplace_back(V);
            }
            ref.second = W;
            for (size_t i = 0, N = W.size(); i<N; i++) {
                std::string FA = pipeline_data.generate_fresh_atom();
                pipeline_data.atom_universe.insert(FA);
                pipeline_data.data_query_atoms.insert(FA);//Missing! Imported from KnoBABv1.0, where this was working
                pipeline_data.clause_to_atomization_map[std::make_pair(ref.first, i)] = FA;
                for (const DataPredicate& pred : W.at(i)) {
                    pipeline_data.Mcal[pred].emplace_back(FA);
                }
            }
            pipeline_data.max_ctam_iteration[ref.first] = W.size();
        }
    }

    for (const auto& key : map.T_to_int) {
        if (!metAtomsGlobally.contains(key.first)) {
            pipeline_data.act_atoms.insert(key.first);
            pipeline_data.atom_universe.insert(key.first);
        }
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    return ms_double.count();
}

inline
semantic_atom_set atomize_conjunction(AtomizingPipeline2 &pipeline_data,
                                      const std::unordered_map<std::string, DataPredicate> &conj){
    semantic_atom_set S;
    bool isFirst = true;
    for (const auto& ref : conj) {
        if (ref.second.casusu != TTRUE) {
            auto atom = ref.second;
            atom.asInterval();
            if (isFirst) {
                S = pipeline_data.interval_decomposition(atom, false);
                isFirst = false;
                if (S.empty()) return S;
            } else {
                S = unordered_intersection(S, pipeline_data.interval_decomposition(atom, false));
                if (S.empty()) return S;
            }
        }
//        for (const auto& child : ref.second.BiVariableConditions) {
//            if (child.casusu != TTRUE) {
//                auto atom = child;
//                atom.asInterval();
//                if (isFirst) {
//                    S = pipeline_data.interval_decomposition(atom, false);
//                    isFirst = false;
//                    if (S.empty()) return S;
//                } else {
//                    S = unordered_intersection(S, pipeline_data.interval_decomposition(atom, false));
//                    if (S.empty()) return S;
//                }
//            }
//        }
    }
    return S;
}

inline
semantic_atom_set atomize_disjunction(AtomizingPipeline2 &pipeline_data,
                                      const std::vector<std::unordered_map<std::string, DataPredicate>> &disj){
    semantic_atom_set S;
    for (const auto& child : disj) {
        auto tmp = atomize_conjunction(pipeline_data, child);
        S.insert(tmp.begin(), tmp.end());
    }
    return S;
}

std::pair<
double,
std::unordered_map<std::string,semantic_atom_set>>
atomize_model(const std::unordered_set<std::string>& all_labels,
                     AtomizingPipeline2 &pipeline_data,
                     const node_data_predicate_references &disjoint_model) {
    std::unordered_map<std::string,semantic_atom_set> result;
    auto t1 = std::chrono::high_resolution_clock::now();
//    for ( auto& ref : disjoint_model.singleElementOfConjunction) {
        for ( auto& [name,child] : disjoint_model) {
            if (child.first.empty()) {
                semantic_atom_set& left_decomposed_atoms = result[name];
                for (const auto& label : all_labels) {
                    auto g = pipeline_data.atom_decomposition(label, false);
                    left_decomposed_atoms.insert(g.begin(), g.end());
                }
                if (!child.second.empty()) {
                    auto tmp = atomize_disjunction(pipeline_data, child.second);
                    left_decomposed_atoms = unordered_intersection(left_decomposed_atoms, tmp);
                }
            } else {
                auto left_decomposed_atoms = pipeline_data.atom_decomposition(child.first, false);
                if (!child.second.empty()) {
                    auto tmp = atomize_disjunction(pipeline_data, child.second);
                    left_decomposed_atoms = unordered_intersection(left_decomposed_atoms, tmp);
                }
                result[name] = left_decomposed_atoms;
            }
        }
//    }

    // Model Indexing: required only for the KB queries, but NOT for the graph pipeline!
    std::pair<std::string, size_t> cp;         // Just a copy object for the query
    for (const auto& k : pipeline_data.interval_map) {
        cp.first = k.first;                    // cp = <Event Label, ...>
        for (size_t i = 0, N = pipeline_data.max_ctam_iteration.at(cp.first); i<N; i++) {
            cp.second = i;                     // cp = <Event Label, Offset>
            // Assertion: one atom should only appear once!
            auto it = pipeline_data.atom_to_conjunctedPredicates.emplace(pipeline_data.clause_to_atomization_map.at(cp),
                                                                         k.second.at(i));
            //DEBUG_ASSERT(it.second);
        }
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    return {ms_double.count(), result};
}

