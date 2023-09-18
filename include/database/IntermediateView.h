/*
 * IntermediateView.h
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
// Created by giacomo on 13/08/23.
//

#ifndef GSM2_INTERMEDIATEVIEW_H
#define GSM2_INTERMEDIATEVIEW_H

#include <variant>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include <database/AttributeTable.h>
#include <database/gsm_object_xi_content.h>


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
