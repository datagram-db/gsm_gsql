//
// Created by neo on 29/03/23.
//

#ifndef GSM_GSQL_IGC_OPERATORS_H
#define GSM_GSQL_IGC_OPERATORS_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "yaucl/functional/assert.h"

#include <string>
#include <curl/curl.h>
#include <gsql_gsm/gsm_inmemory_db.h>
#include <gsql_gsm/json_operators.h>

std::string downloadedResponse;

static inline
std::size_t writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
{
    if(buffer_in != NULL)
    {
        downloadedResponse.append(data);
        return size*nmemb;
    }
    return 0;
}


static
inline double to_degrees(double radians)
{
    return radians * (180.0 / M_PI);
}

//https://github.com/chrisveness/latlon-geohash/blob/master/latlon-geohash.js
// precision 7 = ~153m x 153m grid
// precision 6 = ~1200m x 610m grid
static inline
std::string geohash_encode(double lat, double lon, const int precision = 6)
{
    const std::string base32 = "0123456789bcdefghjkmnpqrstuvwxyz";
    int idx = 0;
    int bit = 0;
    bool evenBit = true;
    std::string geoHash = "";
    double latMin =  -90; double latMax =  90;
    double lonMin = -180; double lonMax = 180;
    std::string output = "";
    while(output.length() < precision)
    {
        if(evenBit)
        {
            const double lonMid = (lonMin + lonMax) / 2;
            if(lon >= lonMid)
            {
                idx = idx*2 + 1;
                lonMin = lonMid;
            }
            else
            {
                idx = idx*2;
                lonMax = lonMid;
            }
        }
        else
        {
            const double latMid = (latMin + latMax) / 2;
            if(lat >= latMid)
            {
                idx = idx*2 + 1;
                latMin = latMid;
            }
            else
            {
                idx = idx*2;
                latMax = latMid;
            }
        }
        evenBit = !evenBit;
        if(++bit == 5)
        {
            output += base32.at(idx);
            bit = 0;
            idx = 0;
        }
    }
    return output;
}

static inline
std::string weather_curl(const std::string& URL)
{
    downloadedResponse = "";
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "charset: utf-8");
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, URL.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        res = curl_easy_perform(curl);

        if(CURLE_OK == res)
        {
            char *ct;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_TYPE, &ct);
            if((CURLE_OK == res) && ct)
                return downloadedResponse;
        }
    }
    curl_slist_free_all(headers);
    return 0;
}

static inline
int vcweather_load(gsm_inmemory_db &db, int &iterator, double lat, double lon, std::time_t start)
{
    std::string geoHashString = geohash_encode(lat, lon);
    int result;
    std::string fileName = "_" + geoHashString + "_" + std::to_string(start) + ".json";
    std::string vcPath = "json_files/vc" + fileName;
    if(std::filesystem::exists(vcPath))
    {
        std::string path = "json_files/vc" + fileName;
        result = load_jsonEllXiFile(db, path, iterator, {"currentConditions"}, "weather_vc");
    }
    else
    {
        std::ifstream fileAnother("api_keys/visualcrossing.txt");
        std::string visualCrossingApiKey;
        fileAnother >> visualCrossingApiKey;

        std::stringstream vc;
        vc << "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/"
           << lat << ',' << lon
           << '/' << start
           << "?key=" << visualCrossingApiKey
           << "&include=current";

        std::string url = vc.str();
        std::string weatherString = weather_curl(url);

        std::ofstream vcFile("json_files/vc" + fileName);
        vcFile << weatherString;
        result = load_jsonEllXiData(db, weatherString, iterator, {"currentConditions"}, "weather_vc");
    }
    return result;
}

//for finding circles for thermals
//https://github.com/marcin-osowski/igc_lib/blob/master/igc_lib.py

struct for_bearing_change {
    double lat, lon;
    long long time;
    double bearing;

    DEFAULT_CONSTRUCTORS(for_bearing_change)

    void computeBearing(struct for_bearing_change& previous) {
        double dLon = (lon - previous.lon);
        double y = sin(dLon) * cos(lat);
        double x = (cos(previous.lat) * sin(lat)) - (sin(previous.lat) * cos(lat) * cos(dLon));
        bearing = atan2(y, x);
        bearing = to_degrees(bearing);
        bearing = fmod((bearing + 360), 360);
        bearing = 360 - bearing;
    }
};


template <typename T, typename F>
void incollection_tuple_extend(gsm_inmemory_db &db,
                               int &bFixIterator,
                               const std::string&collection_name,
                               const std::string&filed_name, // "bearing_rate"
                              T initial_value,
                               const std::function<void(const gsm_object&, F&)>& extract,
                               const std::function<void(const T& , F& , F& , std::string &)>& compute_current) // 0)
{
    auto start = std::chrono::high_resolution_clock::now();
    F previous;
    bool first = true;


    FOLD_COLLECTION(bFixIterator,collection_name,bFix) {
        F current;
        const auto& object = db.O.at(bFix.id);
        extract(object, current);
        std::string value_to_emplace;
        if(first)
        {
            previous = (current);
            value_to_emplace = (std::to_string(initial_value));
            first = false;
        } else {
            compute_current(initial_value, previous, current, value_to_emplace);
        }
        db.O[bFix.id].ell.emplace_back(filed_name);
        db.O[bFix.id].xi.emplace_back(value_to_emplace);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end - start);
    std::cout << "x,ExtendObjects," << elapsed.count() << std::endl;
}

template <typename T>
using generate_cp_container = std::function<void(gsm_inmemory_db &db,
                                                 int previousId,
                                                 const gsm_object_xi_content &bFix,
                                                 const gsm_object &obj,
                                                 T previousAltitude,
                                                 T altitude,
                                                 std::pair<size_t, double> &out)>;

template <typename T>
int time_series_nesting(gsm_inmemory_db &db,
                        int &object_iteration_holder,
                        int &iterator,
                        const std::function<T(const gsm_object_xi_content&, const gsm_object&)> extractor,
                        const std::function<bool(const T&, const T&)>& comparatorCurrWithPrev,
                        const generate_cp_container<T>& generate_pair_cont,
                        const std::string& collection_name,
                        const std::string& series_name, // "lift"
                   const std::string& collection_series_name, // "lift_series"
                   const std::string& meta_collection_name // "lifts"
                   )
{
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<gsm_object_xi_content> tablePhiLifts;
    std::vector<double> scoresLifts{1.0};
    std::vector<gsm_object_xi_content> tablePhiLiftSeries;
    std::vector<double> scoresLiftSeries{1.0};
    bool first_in_series = true;
    int previousId;
    T previous_value;
    bool newLiftSeries = true;
    std::pair<size_t, double> cp{0,1.0};

    for(auto &bFix : db.O[object_iteration_holder].phi[collection_name])
    {
        const auto& obj = db.O.at(bFix.id);

        // Finding pressure_altitude
        T current_value = extractor(bFix, obj);

        if(first_in_series) {
            first_in_series = false;
            previous_value = current_value;
            previousId = bFix.id;
            continue;
        }

        if(comparatorCurrWithPrev(current_value, previous_value)) {
            if(newLiftSeries)
            {
                tablePhiLiftSeries.clear();
                newLiftSeries = false;
            }
            cp.first = ++iterator;
            generate_pair_cont(db, previousId, bFix, obj, current_value, previous_value, cp);
            tablePhiLiftSeries.emplace_back(cp.first, cp.second);
        }
        else {
            if(!newLiftSeries) {
                create_fast(db, ++iterator, {collection_series_name}, {}, scoresLiftSeries, {{series_name, {tablePhiLiftSeries}}});
                tablePhiLifts.emplace_back(iterator);
            }
            newLiftSeries = true;
        }
        previous_value = current_value;
        previousId = bFix.id;
    }
    create_fast(db, ++iterator, {meta_collection_name}, {}, scoresLifts, {{collection_series_name, {tablePhiLifts}}});
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end - start);
    std::cout << "x,CollectionNesting," << elapsed.count() << std::endl;
    return iterator;
}








std::vector<int> weather_load(gsm_inmemory_db &db, int &iterator, double lat, double lon, std::time_t start)
{
    std::string geoHashString = geohash_encode(lat, lon);
    std::vector<int> result;
    std::string fileName = "_" + geoHashString + "_" + std::to_string(start) + ".json";
    std::string owPath = "json_files/ow" + fileName;
    std::string vcPath = "json_files/vc" + fileName;
    if(std::filesystem::exists(owPath) || std::filesystem::exists(vcPath))
    {
        std::string path = "json_files/ow" + fileName;
        result.push_back(iterator);
        load_jsonfile(db, path, iterator, "0", "weather_ow");

        path = "json_files/vc" + fileName;
        result.push_back(iterator);
        load_jsonfile(db, path, iterator, "currentConditions", "weather_vc");
    }
    else
    {
        std::ifstream file("api_keys/openweather.txt");
        std::string openWeatherApiKey;
        file >> openWeatherApiKey;

        std::ifstream fileAnother("api_keys/visualcrossing.txt");
        std::string visualCrossingApiKey;
        fileAnother >> visualCrossingApiKey;

        std::stringstream vc;
        vc << "https://weather.visualcrossing.com/VisualCrossingWebServices/rest/services/timeline/"
           << lat << ',' << lon
           << '/' << start
           << "?key=" << visualCrossingApiKey
           << "&include=current";

        std::stringstream ow;
        ow << "https://history.openweathermap.org/data/2.5/history/city?"
           << "lat=" << lat
           << "&lon=" << lon
           << "&type=hour&start=" << start
           << "&cnt=" << 1
           << "&appid=" << openWeatherApiKey;

        std::string url = ow.str();
        std::cout << "URL:" << url << std::endl;
        std::string weatherString = weather_curl(url);
        std::cout << weatherString << std::endl;

        std::ofstream owFile("json_files/ow" + fileName);
        owFile << weatherString;
        result.push_back(iterator);
        load_jsondata(db, weatherString, iterator, "weather_ow", "0");

        url = vc.str();
        std::cout << "URL:" << url << std::endl;
        weatherString = weather_curl(url);
        std::cout << weatherString << std::endl;

        std::ofstream vcFile("json_files/vc" + fileName);
        vcFile << weatherString;
        result.push_back(iterator);
        load_jsondata(db, weatherString, iterator, "weather_vc", "currentConditions");
    }
    return result;
}

struct geo_hash_support {
    long long unixTime = 0;
    double lat = 0;
    double lon = 0;
    std::string geoHashString;

    geo_hash_support() = default;
    geo_hash_support(const geo_hash_support&) = default;
    geo_hash_support(geo_hash_support&&) = default;
    geo_hash_support& operator=(const geo_hash_support&) = default;
    geo_hash_support& operator=(geo_hash_support&&) = default;
};

template <typename T>
int structural_hashbucket(gsm_inmemory_db& db,
                          int to_hash_collection,
                          int& iterator,
                          const std::string& bucket_holder_type, // "geohashes"
                           const std::string& collection_name,// "b_fix"
                           std::function<std::string(const gsm_object_xi_content&, const gsm_object&, T&)> hasher,
                          const std::string& bucket_label, // "geohash"
                           const std::function<std::vector<std::string>(T&)>& bucket_values
                           )
{
    auto start = std::chrono::high_resolution_clock::now();

    // Creating object holder for the buckes
    create_fast(db, ++iterator, {bucket_holder_type});
    int buckets_holder = iterator;
    auto& bucket_holder_object = db.O[buckets_holder];
    T values; // geo_hash_support
    static std::vector<gsm_object_xi_content> empty;
    for(auto &current_record: db.O[to_hash_collection].phi[collection_name]) {
        const auto& current_object = db.O.at(current_record.id);

        std::string hash_value = hasher(current_record, current_object, values);

        auto it = bucket_holder_object.phi.emplace(hash_value, empty); // attempting at creating a bucket as containment
        int id;
        if(it.second) {
            // Inserting a new object (iterator) into the model, that will contain all the elements belonging to the same shash
            create_fast(db, ++iterator, {bucket_label}, bucket_values(values));
            // Inserting the new bucket as item of the bucket list
            bucket_holder_object.phi[hash_value].emplace_back(iterator);
            id = iterator;
        } else {
            id = bucket_holder_object.phi[hash_value][0].id;
        }

        db.O[id].phi[collection_name].emplace_back(current_record.id);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end - start);
    std::cout << "x,StructuralBucketing," << elapsed.count() << std::endl;
    return buckets_holder;
}



static inline
void incollection_map(gsm_inmemory_db& db,
                      int buckets_holder,
                      int& iterator,
                      const std::function<void(gsm_inmemory_db &db,
                                                         int &iterator,
                                                         gsm_object &current_object)>& transform_as
)
{
    auto start = std::chrono::high_resolution_clock::now();
    PHI_FOLD_BEGIN(buckets_holder, hash_value, record_list, current_record)
        auto& current_object = db.O[current_record.id];
            transform_as(db, iterator, current_object);
    PHI_FOLD_END
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end - start);
    std::cout << "x,WeatherLFold," << elapsed.count() << std::endl;
}

/*
 * OW FILE NAME: ow_{geohash}_{unixtime}.json
 * WHAT TO EXTRACT:
 * json -> list -> 0 -> main -> [temp,..]
 *                   -> wind -> [speed,...]
 *                   -> clouds -> [all]
 * 1. in json
 *
 *
 * VC FILE NAME: vc_{geohash}_{unixtime}.json
 * WHAT TO EXTRACT:
 * everything from currentConditions
 * json -> currentConditions -> [temp,wind,...]
 */

//VC

#include <yaucl/strings/serializers.h>
#include <unordered_map>

//static inline
//bool serialize_to_csv(bool& getHeaders, std::ofstream &fileOut, const std::unordered_map<std::string, std::string> &row,
//                      const std::vector<std::string> &header) {
//    if(getHeaders)
//    {
//        for (auto it = header.begin(), en = header.end(); it != en; ) {
//            fileOut << *it;
//            it++;
//            if (it != en)
//                fileOut << ",";
//        }
//        fileOut << '\n';
//        getHeaders = false;
//    }
//    {
//        for (auto it = header.begin(), en = header.end(); it != en; ) {
//            fileOut << row.at(*it);
//            it++;
//            if (it != en)
//                fileOut << ",";
//        }
//        fileOut << '\n';
//    }
//    return getHeaders;
//}

static inline
void natural_join(gsm_inmemory_db &db, const gsm_db_indices &idx, const std::string &left_collection,
                  const std::string &right_collection, const std::set<std::string> &left,
                  const std::set<std::string> &right, const std::set<std::string> &additional,
                  const std::function<void(gsm_inmemory_db& ,const gsm_db_indices &, const std::set<std::string> &, const std::set<std::string> &, const std::set<std::string> &, const std::vector<std::string> &, const gsm_object_xi_content &, const gsm_object &, const gsm_object_xi_content &, const gsm_object &, std::unordered_map<std::string, std::string>&)>expand,
                  std::unordered_map<std::string, std::string> &row,
                  const std::vector<std::string> &header, size_t collection_id/*, float &total_flat,
                  float &total_expansion, float &total_rightiter, float &total_lefttiter*/) {
    const auto& two_collections_to_join = db.O.at(collection_id);
    const auto& LEFT = two_collections_to_join.phi.at(left_collection);
    const auto& RIGHT = two_collections_to_join.phi.at(right_collection);

    for (const auto& left_record : LEFT) {
//        auto start_leftiter = std::chrono::high_resolution_clock::now();
        const auto& left_object = db.O.at(left_record.id);
        for(int i = 0; i < left_object.ell.size(); i++) {
            const auto& label = left_object.ell.at(i);
            if (left.contains(label))
                row[left_object.ell.at(i)] = (left_object.xi.at(i));
        }
//        auto end_leftiter= std::chrono::high_resolution_clock::now();
//        auto elapsed_leftiter = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end_leftiter-start_leftiter);
//        total_lefttiter += elapsed_leftiter.count();

//        float consumed_bfix_iteration = 0.0;
//        auto start_bfixiter = std::chrono::high_resolution_clock::now();
        for(const auto& right_record : RIGHT) {
            auto start_rightiter = std::chrono::high_resolution_clock::now();
            const auto& right_object = db.O.at(right_record.id);
            for(int i = 1; i < db.O.at(right_record.id).ell.size(); i++) {
                if (right.contains(right_object.ell.at(i)))
                    row[right_object.ell.at(i)] =(right_object.xi.at(i));
            }
//            auto end_rightiter = std::chrono::high_resolution_clock::now();
//            auto elapsed_rightiter = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end_rightiter - start_rightiter);
//            consumed_bfix_iteration += elapsed_rightiter.count();
//            total_rightiter += elapsed_rightiter.count();

            // Expansion with the bFixes condition
//            auto start_expansion = std::chrono::high_resolution_clock::now();
            expand(db, idx, left, right, additional, header, left_record, left_object, right_record, right_object, row);
//            auto end_expansion = std::chrono::high_resolution_clock::now();
//            auto elapsed_expansion = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end_expansion - start_expansion);
//            total_expansion += elapsed_expansion.count();
//            consumed_bfix_iteration += elapsed_expansion.count();
        }
//        auto end_bfixiter = std::chrono::high_resolution_clock::now();
//        auto elapsed_bfixiter = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end_bfixiter - start_bfixiter);
//        total_rightiter += (consumed_bfix_iteration - elapsed_bfixiter.count());
    }
}

void flat_natural_hash_join(gsm_inmemory_db &db, int geoHashesIterator, const gsm_db_indices &idx,
                            const std::string &csvFileName, const std::string &left_collection, const std::string &right_collection,
                            const std::set<std::string> &left = {}, const std::set<std::string> &right = {},
                            const std::set<std::string> &additional = {},
                            const std::function<void(gsm_inmemory_db&, const gsm_db_indices &, const std::set<std::string> &, const std::set<std::string> &, const std::set<std::string> &, const std::vector<std::string> &, const gsm_object_xi_content &, const gsm_object &, const gsm_object_xi_content &, const gsm_object &, std::unordered_map<std::string,std::string>&)> expand = {})
{
//    std::string headers;
//    float total_flat = 0.0, total_expansion = 0.0, total_rightiter = 0.0, total_lefttiter = 0.0;

    auto start_all_time = std::chrono::high_resolution_clock::now();
    std::unordered_map<std::string, std::string> row;
    std::vector<std::string> header{left.begin(), left.end()};
    header.insert(header.end(), right.begin(), right.end());
    header.insert(header.end(), additional.begin(), additional.end());
    PHI_FOLD_BEGIN(geoHashesIterator, collection_name, bucket, in_bucket_collection)
            natural_join(db, idx, left_collection, right_collection, left, right, additional, expand,
                         row, header, in_bucket_collection.id/*, total_flat, total_expansion,
                         total_rightiter, total_lefttiter*/);
    PHI_FOLD_END
    auto end_all_time= std::chrono::high_resolution_clock::now();
    auto elapsed_all = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end_all_time - start_all_time);
    float time_bucket_and_left_iteration = elapsed_all.count();

    std::cout << "x,UnnestingHashJoin," << time_bucket_and_left_iteration << std::endl;


}
#endif //GSM_GSQL_IGC_OPERATORS_H
