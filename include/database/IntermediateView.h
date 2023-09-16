//
// Created by giacomo on 13/08/23.
//

#ifndef GSM2_INTERMEDIATEVIEW_H
#define GSM2_INTERMEDIATEVIEW_H

#include <variant>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include "AttributeTable.h"
#include "gsm_object_xi_content.h"


struct property_content {
    std::string field;
    std::map<gsm2::tables::union_type, size_t> value_to_object_id;
};

struct IntermediateView {
    std::unordered_set<std::size_t>                                                                 no_object_in_graph;
    std::unordered_map<std::string, property_content>                                               property_values;
    std::unordered_map<size_t, std::unordered_map<std::string, std::vector<gsm_object_xi_content>>> phi;
};


#endif //GSM2_INTERMEDIATEVIEW_H
