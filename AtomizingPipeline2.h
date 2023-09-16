//
// Created by giacomo on 16/04/2022.
//

#ifndef KNOBAB_SERVER_ATOMIZINGPIPELINE_H
#define KNOBAB_SERVER_ATOMIZINGPIPELINE_H

#include    <string>
#include    <unordered_map>
#include    <unordered_set>
#include <yaucl/bpm/structures/commons/DataPredicate.h>
#include <yaucl/structures/query_interval_set.h>
#include <yaucl/structures/StringPrevNext.h>
#include <yaucl/structures/DoublePrevNext.h>
#include <yaucl/structures/set_operations.h>
#include <ostream>
#include <yaucl/bpm/structures/commons/easy_prop.h>
#include <yaucl/structures/query_interval_set/structures/segment_partition_tree.h>
#include <random>

using dnf_data_predicate = std::vector<std::unordered_map<std::string, DataPredicate>>;
using node_data_predicate_references = std::unordered_map<std::string, std::pair<std::string,dnf_data_predicate>>;

using label_var_atoms_map_t = std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_set<DataPredicate>>>;
using double_bulk_map_t = std::unordered_map<std::string, std::unordered_map<std::string, spt_bulk_insertion<double>>>;
using string_bulk_map_t = std::unordered_map<std::string, std::unordered_map<std::string, spt_bulk_insertion<std::string>>>;
using double_map_t = std::unordered_map<std::string, std::unordered_map<std::string, segment_partition_tree<double, DoublePrevNext>>>;
using string_map_t = std::unordered_map<std::string, std::unordered_map<std::string, segment_partition_tree<std::string, StringPrevNext>>>;
using label_set_t = std::unordered_set<std::string>;
using semantic_atom_set = std::unordered_set<std::string>;

enum AtomizationStrategy {
    AtomizeEverythingIfAnyDataPredicate,
    AtomizeOnlyOnDataPredicates
};

struct AtomizingPipeline2 {
    AtomizationStrategy strategy = AtomizeEverythingIfAnyDataPredicate;

    label_var_atoms_map_t map1;
    double                d_min = DataPredicate::MIN_DOUBLE;
    double                d_max = DataPredicate::MAX_DOUBLE;
    std::string           s_min = DataPredicate::MIN_STRING;
    std::string           s_max = DataPredicate::MAX_STRING;
    std::string           fresh_atom_label{"p"};

    label_set_t           act_universe;
    label_set_t           act_atoms;
    semantic_atom_set      atom_universe;
    semantic_atom_set      data_query_atoms;

    double_bulk_map_t     double_bulk_map;
    double_map_t          double_map;
    string_bulk_map_t     string_bulk_map;
    string_map_t          string_map;

    std::unordered_map<std::string, std::vector<std::vector<DataPredicate>>> interval_map;
    std::unordered_map<std::pair<std::string, size_t>, std::string>          clause_to_atomization_map;
    std::unordered_map<DataPredicate, std::vector<std::string>>              Mcal;
    std::unordered_map<std::string, size_t>                                  max_ctam_iteration;
    std::unordered_map<std::string, std::vector<DataPredicate>>              atom_to_conjunctedPredicates;

//    void serialize_atom_list_to_xes(const std::vector<std::vector<std::string>>& atomised_log, std::ostream& stream) const;

    /**
     * Generating a new atom associated to the data interval associated to an event label
     * @return  Fresh atom
     */
    std::string generate_fresh_atom();
    void finalise() {
        act_atoms = unordered_intersection(act_atoms, atom_universe);
    }
    /**
     * Decomposition of a formula atom associated to a single element
     * @param act           Act/Event label that might appear in the log
     * @param isNegated     Whether the act might appear negated in the ltlf formula
     * @return              Set of atoms associated to the act, after decomposition
     */
    semantic_atom_set atom_decomposition(const std::string &act, bool isNegated = false);

    template <typename T>
    void atom_decomposition(const std::string &act, bool isNegated, T& inserter) {
        semantic_atom_set S;
        auto it = interval_map.find(act);
        if (it == interval_map.end()) {
            // If the atom is not associated to an interval, then return the atom itself
//            DEBUG_ASSERT(act_atoms.contains(act));
            if (!isNegated) AddToContainer(inserter, act); else AddToContainer(S, act);
        } else {
            std::pair<std::string, size_t> cp; // convenience element, so not to re-allocate the memory all the time
            cp.first = act;
            for (size_t i = 0, N = max_ctam_iteration.at(act); i<N; i++) {
                cp.second = i;
                if (!isNegated) AddToContainer(inserter, clause_to_atomization_map.at(cp)); else AddToContainer(S, clause_to_atomization_map.at(cp));
            }
        }
        if (isNegated) {
            auto tmp = unordered_difference(atom_universe, S);
            for (const auto& x : tmp)
                AddToContainer(inserter, x);
        }
    }

    /**
     * Decomposition of a data predicate associated to a Act/Event
     * @param pred          Predicate information, containing also the Act/Event label one
     * @param isNegated     Whether the act might appear negated in the ltlf formula
     * @return              Set of atoms associated to the act, after decomposition
     */
    semantic_atom_set interval_decomposition(const DataPredicate &pred, bool isNegated = false);

    /**
     * Clears all the maps collected for the atomization pipeline
     */
    void clear();

    /**
     * Printing debug information associated to the information collected by the model
     * @param os
     * @param pipeline
     * @return
     */
    friend std::ostream &operator<<(std::ostream &os, const AtomizingPipeline2 &pipeline);
//    void serialise_trace(std::ostream &xes,
//                         std::mt19937_64 &eng,
//                         size_t trace_id, const std::vector<std::string> &trace) const;
//
//    void serialise_event_in_trace(std::ostream &xes, std::mt19937_64 &eng, const std::basic_string<char> &atom_p) const;
private:
    size_t count_fresh_atoms = 0;


};
#include <yaucl/structures/any_to_uint_bimap.h>


double collect_data_from_declare_disjunctive_model(const std::unordered_set<std::string>& all_labels,
        const yaucl::structures::any_to_uint_bimap<std::string>& map, AtomizingPipeline2& pipeline_data, const node_data_predicate_references& disjoint_model);


std::pair<
        double,
        std::unordered_map<std::string,semantic_atom_set>> atomize_model(const std::unordered_set<std::string>& all_labels,
                     AtomizingPipeline2& pipeline_data, const node_data_predicate_references &disjoint_model);



#endif //KNOBAB_SERVER_ATOMIZINGPIPELINE_H
//
// Created by giacomo on 16/04/2022.
//

#ifndef KNOBAB_SERVER_ATOMIZINGPIPELINE_H
#define KNOBAB_SERVER_ATOMIZINGPIPELINE_H

#include    <string>
#include    <unordered_map>
#include    <unordered_set>
#include <knobab/server/dataStructures/atomization_structures.h>
#include <yaucl/bpm/structures/commons/DataPredicate.h>
#include <knobab/server/declare/CNFDeclareDataAware.h>
#include <yaucl/structures/query_interval_set.h>
#include <yaucl/structures/StringPrevNext.h>
#include <yaucl/structures/DoublePrevNext.h>
#include <yaucl/structures/set_operations.h>
#include <ostream>
#include <yaucl/bpm/structures/commons/easy_prop.h>
#include <yaucl/structures/query_interval_set/structures/segment_partition_tree.h>
#include <random>


using label_var_atoms_map_t = std::unordered_map<std::string, std::unordered_map<std::string, std::unordered_set<DataPredicate>>>;
using double_bulk_map_t = std::unordered_map<std::string, std::unordered_map<std::string, spt_bulk_insertion<double>>>;
using string_bulk_map_t = std::unordered_map<std::string, std::unordered_map<std::string, spt_bulk_insertion<std::string>>>;
using double_map_t = std::unordered_map<std::string, std::unordered_map<std::string, segment_partition_tree<double, DoublePrevNext>>>;
using string_map_t = std::unordered_map<std::string, std::unordered_map<std::string, segment_partition_tree<std::string, StringPrevNext>>>;
using label_set_t = std::unordered_set<std::string>;
using semantic_atom_set = std::unordered_set<std::string>;

enum AtomizationStrategy {
    AtomizeEverythingIfAnyDataPredicate,
    AtomizeOnlyOnDataPredicates
};

struct AtomizingPipeline {
    AtomizationStrategy strategy = AtomizeEverythingIfAnyDataPredicate;

    label_var_atoms_map_t map1;
    double                d_min = DataPredicate::MIN_DOUBLE;
    double                d_max = DataPredicate::MAX_DOUBLE;
    std::string           s_min = DataPredicate::MIN_STRING;
    std::string           s_max = DataPredicate::MAX_STRING;
    std::string           fresh_atom_label{"p"};

    label_set_t           act_universe;
    label_set_t           act_atoms;
    semantic_atom_set      atom_universe;
    semantic_atom_set      data_query_atoms;

    double_bulk_map_t     double_bulk_map;
    double_map_t          double_map;
    string_bulk_map_t     string_bulk_map;
    string_map_t          string_map;

    std::unordered_map<std::string, std::vector<std::vector<DataPredicate>>> interval_map;
    std::unordered_map<std::pair<std::string, size_t>, std::string>          clause_to_atomization_map;
    std::unordered_map<DataPredicate, std::vector<std::string>>              Mcal;
    std::unordered_map<std::string, size_t>                                  max_ctam_iteration;
    std::unordered_map<std::string, std::vector<DataPredicate>>              atom_to_conjunctedPredicates;

    void serialize_atom_list_to_xes(const std::vector<std::vector<std::string>>& atomised_log, std::ostream& stream) const;

    /**
     * Generating a new atom associated to the data interval associated to an event label
     * @return  Fresh atom
     */
    std::string generate_fresh_atom();
    void finalise() {
        act_atoms = unordered_intersection(act_atoms, atom_universe);
    }
    /**
     * Decomposition of a formula atom associated to a single element
     * @param act           Act/Event label that might appear in the log
     * @param isNegated     Whether the act might appear negated in the ltlf formula
     * @return              Set of atoms associated to the act, after decomposition
     */std::pair<
double,
std::unordered_map<std::string,semantic_atom_set>>
    semantic_atom_set atom_decomposition(const std::string &act, bool isNegated = false);

    template <typename T>
    void atom_decomposition(const std::string &act, bool isNegated, T& inserter) {
        semantic_atom_set S;
        auto it = interval_map.find(act);
        if (it == interval_map.end()) {
            // If the atom is not associated to an interval, then return the atom itself
//            DEBUG_ASSERT(act_atoms.contains(act));
            if (!isNegated) AddToContainer(inserter, act); else AddToContainer(S, act);
        } else {
            std::pair<std::string, size_t> cp; // convenience element, so not to re-allocate the memory all the time
            cp.first = act;
            for (size_t i = 0, N = max_ctam_iteration.at(act); i<N; i++) {
                cp.second = i;
                if (!isNegated) AddToContainer(inserter, clause_to_atomization_map.at(cp)); else AddToContainer(S, clause_to_atomization_map.at(cp));
            }
        }
        if (isNegated) {
            auto tmp = unordered_difference(atom_universe, S);
            for (const auto& x : tmp)
                AddToContainer(inserter, x);
        }
    }

    /**
     * Decomposition of a data predicate associated to a Act/Event
     * @param pred          Predicate information, containing also the Act/Event label one
     * @param isNegated     Whether the act might appear negated in the ltlf formula
     * @return              Set of atoms associated to the act, after decomposition
     */
    semantic_atom_set interval_decomposition(const DataPredicate &pred, bool isNegated = false);

    /**
     * Clears all the maps collected for the atomization pipeline
     */
    void clear();

    /**
     * Printing debug information associated to the information collected by the model
     * @param os
     * @param pipeline
     * @return
     */
    friend std::ostream &operator<<(std::ostream &os, const AtomizingPipeline &pipeline);
    void serialise_trace(std::ostream &xes,
                         std::mt19937_64 &eng,
                         size_t trace_id, const std::vector<std::string> &trace) const;

    void serialise_event_in_trace(std::ostream &xes, std::mt19937_64 &eng, const std::basic_string<char> &atom_p) const;
private:
    size_t count_fresh_atoms = 0;


};
#include <yaucl/structures/any_to_uint_bimap.h>


double collect_data_from_declare_disjunctive_model(const yaucl::structures::any_to_uint_bimap<std::string>& map, AtomizingPipeline& pipeline_data, const CNFDeclareDataAware& disjoint_model);


double atomize_model(AtomizingPipeline& pipeline_data, CNFDeclareDataAware &disjoint_model);



#endif //KNOBAB_SERVER_ATOMIZINGPIPELINE_H
