/*
 * dump_to_xml.h
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

#ifndef GSM_GSQL_DUMP_TO_XML_H
#define GSM_GSQL_DUMP_TO_XML_H

#include <gsql_gsm/gsm_db_indices.h>

/**
 * Dumps the database and its indices to an XML file
 * @param db        GSM database
 * @param idx       Indices
 * @param filename  XML file name
 */
void dump_to_xml(const gsm_inmemory_db& db,
                 const gsm_db_indices& idx,
                 const std::string& filename);

#endif //GSM_GSQL_DUMP_TO_XML_H
