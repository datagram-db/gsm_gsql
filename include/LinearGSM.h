//
// Created by giacomo on 28/05/23.
//

#ifndef GSM2_LINEARGSM_H
#define GSM2_LINEARGSM_H

#include "SimplifiedFuzzyStringMatching.h"
#include "PhiTable.h"
#include "AttributeTable.h"
#include "ActivityTable.h"

namespace gsm2 {
    namespace tables {
        struct LinearGSM {
            yaucl::structures::any_to_uint_bimap<std::string> label_map;
            std::unordered_map<std::string, PhiTable> containment_tables;
            std::unordered_map<std::string, AttributeTable> KeyValueContainment;
            FuzzyMatchSerializer ell_values, xi_values; //TODO: proper version, with multiple values associated to the string!
            ActivityTable                main_registry;

            // TODO : Loading from file representation
            // TODO: indexing from file representation
        };
    } // gsm2
} // structures

#endif //GSM2_LINEARGSM_H
