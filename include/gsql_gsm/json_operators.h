/*
 * main.cpp
 * This file is part of gsm_gsql
 *
 * Copyright (C) 2023 - Wiktor Zegadło
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
// Created by neo on 23/04/23.
//

#ifndef GSM_GSQL_JSON_OPERATORS_H
#define GSM_GSQL_JSON_OPERATORS_H
#include <iostream>
#include <nlohmann/json.hpp>
#include <gsql_gsm/gsm_inmemory_db.h>
#include <gsql_gsm/gsql_operators.h>
using json = nlohmann::json;

static inline
void json_recursion(json data, int &iterator, std::vector<gsm_object_xi_content> &tablePhi, std::vector<double> &scores, gsm_inmemory_db &db, std::string previousKey = "")
{
    for(auto &it : data.items()) {
        if(it.value().is_object() || it.value().is_array())
        {
            std::vector<gsm_object_xi_content> tablePhiObject = {};
            std::vector<double> scoresObject = {};
            json_recursion(it.value(), iterator, tablePhiObject, scoresObject, db, it.key());
            std::string phiString = (data.is_array() ? previousKey : it.key());
            create_fast(db, ++iterator, {"json_object"}, {}, {scoresObject}, {{phiString, {tablePhiObject}}});
        }
        else
        {
            std::string ell = (data.is_array() ? previousKey : it.key());
            create_fast(db, ++iterator, {ell}, {to_string(it.value())});
        }
        tablePhi.emplace_back(iterator);
//        scores.emplace_back(1.0);
    }
}

//std::vector<std::string> ignore = {"datetime", "datetimeEpoch", "conditions", "icon", "stations", "source", "sunrise",
//                                   "sunriseEpoch", "sunset", "sunsetEpoch", "moonphase"};

static inline
void json_ellxi(gsm_inmemory_db& db, json data, int &iterator, const std::unordered_set<std::string>& ignore = {"datetime", "datetimeEpoch", "conditions", "icon", "stations", "source", "sunrise",
                                                                                                         "sunriseEpoch", "sunset", "sunsetEpoch", "moonphase"})
{
    std::vector<std::string> tableEllObject;
    std::vector<std::string> tableXiObject;
    for(auto &it : data.items()) {
        if (!it.value().is_object() && !it.value().is_array()) {
            if (ignore.contains(it.key())) continue;
            db.O[iterator].ell.push_back((data.is_array() ? "previousKey" : it.key()));
            db.O[iterator].xi.push_back((to_string(it.value()) == "null" ? "0" : to_string(it.value())));
        }
    }
}

static inline
int load_jsonEllXiFile(gsm_inmemory_db &db, const std::string& pathToFile, int &iterator, const std::vector<std::string>& specific = {}, const std::string& ell = "") {
    json data;
    std::ifstream f(pathToFile);
    data = json::parse(f);
    create_fast(db, ++iterator, {ell}, {""}, {});
    int objIterator = iterator;
    for(auto& it : specific)
        json_ellxi(db, data[it], objIterator);
    return objIterator;
}

static inline
int load_jsonEllXiData(gsm_inmemory_db &db,
                       const std::string& jsonData,
                       int &iterator,
                       const std::vector<std::string>& specific = {},
                       const std::string& ell = "") {
    json data;
    data = json::parse(jsonData);
    create_fast(db, ++iterator, {ell}, {""}, {});
    int objIterator = iterator;
    for(auto& it : specific)
        json_ellxi(db, data[it], objIterator);
    return objIterator;
}


static inline
void load_jsondata(gsm_inmemory_db &db, std::string jsonData, int &iterator, std::string xi, std::string specific = "")
{
    json data;
    data = json::parse(jsonData);
    std::vector<gsm_object_xi_content> tablePhiJson = {};
    std::vector<double> scoresJson = {};
    if(specific != "")
        json_recursion(data[specific], iterator, tablePhiJson, scoresJson, db);
    else
        json_recursion(data, iterator, tablePhiJson, scoresJson, db);
    create_fast(db, ++iterator, {"json_file"}, {xi}, {scoresJson}, {{"json_object", {tablePhiJson}}});
}

static inline
void load_jsonfile(gsm_inmemory_db &db, std::string pathToFile, int &iterator, std::string specific = "", std::string xi = "")
{
    json data;
    std::ifstream f(pathToFile);
    if(xi == "")
        xi = pathToFile;

    data = json::parse(f);
    std::vector<gsm_object_xi_content> tablePhiJson = {};
    std::vector<double> scoresJson = {};
    json_recursion(data[specific], iterator, tablePhiJson, scoresJson, db);
    create_fast(db, ++iterator, {"json_file"}, {xi}, {scoresJson}, {{"json_object", {tablePhiJson}}});
}
#endif //GSM_GSQL_JSON_OPERATORS_H
