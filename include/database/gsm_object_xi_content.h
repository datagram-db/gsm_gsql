/*
 * gsm_object_xi_content.h
 * This file is part of gsm_gsql
 *
 * Copyright (C) 2018-2023 - Giacomo Bergami
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
// Created by giacomo on 05/02/23.
//

#ifndef GSM_GSQL_GSM_OBJECT_XI_CONTENT_H
#define GSM_GSQL_GSM_OBJECT_XI_CONTENT_H

#include <cstdlib>

struct gsm_object_xi_content {
    size_t id;
    double score;

    gsm_object_xi_content(size_t id = 0, double score=1.0);
    gsm_object_xi_content(const gsm_object_xi_content&) = default;
    gsm_object_xi_content(gsm_object_xi_content&&) = default;
    gsm_object_xi_content& operator=(const gsm_object_xi_content&) = default;
    gsm_object_xi_content& operator=(gsm_object_xi_content&&) = default;
    bool operator==(const gsm_object_xi_content &rhs) const;
    bool operator!=(const gsm_object_xi_content &rhs) const;

    bool operator<(const gsm_object_xi_content &rhs) const {
        return (id <rhs.id) || (id == rhs.id && (score == rhs.score));
    }
};


#endif //GSM_GSQL_GSM_OBJECT_XI_CONTENT_H
