//
// Created by neo on 29/03/23.
//

#ifndef GSM_GSQL_IGC_OPERATORS_H
#define GSM_GSQL_IGC_OPERATORS_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <curl/curl.h>
#include <gsql_gsm/gsm_inmemory_db.h>
#include <gsql_gsm/json_operators.h>

inline double to_degrees(double radians)
{
    return radians * (180.0 / M_PI);
}


//for finding circles for thermals
//https://github.com/marcin-osowski/igc_lib/blob/master/igc_lib.py
static inline
void calculate_bearing_change(gsm_inmemory_db &db, int &nodesIterator)
{
    double previousLong = '\0';
    double previousLat = '\0';
    long long previousTime = '\0';
    double previousBearing = '\0';

    for(auto &bFix : db.O[nodesIterator].phi["b_fix"])
    {
        double nowLong;
        double nowLat;
        long long nowTime;
        for(auto &data : db.O[bFix.id].phi["data"])
        {
            if(db.O[data.id].ell[0] == "latitude_double")
                nowLat = stod(db.O[data.id].xi[0]);
            else if(db.O[data.id].ell[0] == "longitude_double")
                nowLong = stod(db.O[data.id].xi[0]);
            else if(db.O[data.id].ell[0] == "unix_time")
                nowTime = stoll(db.O[data.id].xi[0]);
            else
                continue;
        }
        if(previousLong == '\0' && previousLat == '\0' && previousTime == '\0')
        {
            previousLat = nowLat;
            previousLong = nowLong;
            previousTime = nowTime;
            continue;
        }

        double dLon = (nowLong - previousLong);

        double y = sin(dLon) * cos(nowLat);
        double x = (cos(previousLat) * sin(nowLat)) - (sin(previousLat) * cos(nowLat) * cos(dLon));

        double bearing = atan2(y, x);

        bearing = to_degrees(bearing);
        bearing = fmod((bearing + 360), 360);
        bearing = 360 - bearing;
        long long timeDiff = nowTime - previousTime;

        previousLong = nowLong;
        previousLat = nowLat;
        previousTime = nowTime;
        if(previousBearing == '\0')
        {
            previousBearing = bearing;
        }
        else
        {
            double bearingChange = previousBearing - bearing;
            if(fabs(bearingChange) > 180.0)
            {
                if(bearingChange < 0.0)
                    bearingChange += 360.0;
                else
                    bearingChange -= 360.0;
            }
            double changeRate = bearingChange/timeDiff;
            std::cout << "chng:" << changeRate << std::endl;
        }

    }
}



static inline
void calculate_lift(gsm_inmemory_db &db, int &bFixesIterator, int &iterator)
{
    std::vector<gsm_object_xi_content> tablePhiLifts = {};
    std::vector<double> scoresLifts = {};
    std::vector<gsm_object_xi_content> tablePhiLiftSeries = {};
    std::vector<double> scoresLiftSeries = {};
    int previousId;
    int previousAltitude = '\0';
    bool newLiftSeries = true;

    for(auto &bFix : db.O[bFixesIterator].phi["b_fix"])
    {
        int altitude;
        int dataId;
        for(auto &data : db.O[bFix.id].phi["data"])
        {
            if (db.O[data.id].ell[0] == "pressure_altitude")
            {
                altitude = stoi(db.O[data.id].xi[0]);
                dataId = data.id;
            }
        }
        if(previousAltitude == '\0')
        {
            previousAltitude = altitude;
            previousId = dataId;
            continue;
        }
        if(altitude > previousAltitude)
        {
            if(newLiftSeries)
            {
                tablePhiLiftSeries = {};
                scoresLiftSeries = {};
                newLiftSeries = false;
            }

            int diffAltitude = altitude - previousAltitude;
            std::vector<gsm_object_xi_content> tablePhiLift = {};
            std::vector<double> scoresLift = {};

            tablePhiLift.emplace_back(previousId);
            scoresLift.emplace_back(1.0);
            tablePhiLift.emplace_back(dataId);
            scoresLift.emplace_back(1.0);

            create_fast(db, ++iterator, {"lift"}, {std::to_string(diffAltitude)}, {scoresLift},
                        {{"altitudes", {tablePhiLift}}});
            tablePhiLiftSeries.push_back(iterator);
            scoresLiftSeries.push_back(1.0);
        }
        else
        {
            if(!newLiftSeries)
            {
                create_fast(db, ++iterator, {"lift_series"}, {}, {scoresLiftSeries}, {{"lift", {tablePhiLiftSeries}}});
                tablePhiLifts.emplace_back(iterator);
                scoresLifts.emplace_back(1.0);
            }
            newLiftSeries = true;
        }
        previousAltitude = altitude;
        previousId = dataId;
    }
    create_fast(db, ++iterator, {"lifts"}, {}, {scoresLifts}, {{"lift_series", {tablePhiLifts}}});
}

//https://github.com/chrisveness/latlon-geohash/blob/master/latlon-geohash.js
std::string geohash_encode(double lat, double lon)
{
    const int precision = 7; // ~153m x 153m grid
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


std::string downloadedResponse;

std::size_t writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
{
    if(buffer_in != NULL)
    {
        downloadedResponse.append(data);
        return size*nmemb;
    }
    return 0;
}


std::string weather_curl(std::string URL)
{
    downloadedResponse = "";
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;
    std::ostringstream oss;
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
}

std::vector<int> weather_load(gsm_inmemory_db &db, int &iterator, double lat, double lon, std::time_t start)
{
    std::string geoHashString = geohash_encode(lat, lon);
    std::vector<int> result;
    std::string fileName = "_" + geoHashString + "_" + std::to_string(start) + ".json";
    std::string owPath = "/home/neo/gsm_gsql/json_files/ow" + fileName;
    std::string vcPath = "/home/neo/gsm_gsql/json_files/vc" + fileName;
    if(std::filesystem::exists(owPath) || std::filesystem::exists(vcPath))
    {
        std::string path = "/home/neo/gsm_gsql/json_files/ow" + fileName;
        result.push_back(iterator);
        load_jsonfile(db, path, iterator, "0", "weather_ow");

        path = "/home/neo/gsm_gsql/json_files/vc" + fileName;
        result.push_back(iterator);
        load_jsonfile(db, path, iterator, "currentConditions", "weather_vc");
    }
    else
    {
        std::ifstream file("/home/neo/gsm_gsql/api_keys/openweather.txt");
        std::string openWeatherApiKey;
        file >> openWeatherApiKey;

        std::ifstream fileAnother("/home/neo/gsm_gsql/api_keys/visualcrossing.txt");
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

        std::ofstream owFile("/home/neo/gsm_gsql/json_files/ow" + fileName);
        owFile << weatherString;
        result.push_back(iterator);
        load_jsondata(db, weatherString, iterator, "weather_ow", "0");

        url = vc.str();
        std::cout << "URL:" << url << std::endl;
        weatherString = weather_curl(url);
        std::cout << weatherString << std::endl;

        std::ofstream vcFile("/home/neo/gsm_gsql/json_files/vc" + fileName);
        vcFile << weatherString;
        result.push_back(iterator);
        load_jsondata(db, weatherString, iterator, "weather_vc", "currentConditions");
    }
    return result;
}


static inline
int generate_weatherbucket(gsm_inmemory_db& db, int bFixesIterator, int& iterator)
{
    create_fast(db, ++iterator, {"geohashes"});
    int ghIterator = iterator;
    long long unixTime;
    for (auto &bFix: db.O[bFixesIterator].phi["b_fix"])
    {
        double lat;
        double lon;

        for (auto &data: db.O[bFix.id].phi["data"])
        {
            if (db.O[data.id].ell[0] == "latitude_double") {
                lat = stod(db.O[data.id].xi[0]);
            } else if (db.O[data.id].ell[0] == "longitude_double") {
                lon = stod(db.O[data.id].xi[0]);
            } else if (db.O[data.id].ell[0] == "unix_time") {
                unixTime = stoll(db.O[data.id].xi[0]);
                unixTime = unixTime - (unixTime % 3600);
            }
        }

        std::string geoHashString = geohash_encode(lat, lon);
        std::string geoHashCombo = geoHashString + std::to_string((unixTime / 3600) % 24);
        if(!db.O[ghIterator].phi.contains(geoHashCombo))
        {
            create_fast(db, ++iterator, {"geohash"}, {geoHashString, std::to_string(unixTime)});
            db.O[ghIterator].phi[geoHashCombo].emplace_back(iterator);
            db.O[ghIterator].scores.emplace_back(1.0);

            std::vector<int> weatherBucket = weather_load(db, iterator, lat, lon, unixTime);
            for(auto &wb : weatherBucket)
            {
                db.O[ghIterator].phi[geoHashCombo].emplace_back(wb);
                db.O[ghIterator].scores.emplace_back(1.0);
            }
        }
        db.O[iterator].phi["data"].emplace_back(bFix.id);
        db.O[iterator].scores.emplace_back(1.0);
    }
    return ghIterator;
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

void weather_operator(gsm_inmemory_db &db, int &iterator, int geoHashesIterator)
{
    for(auto& [geoHashString, geoHashVector] : db.O[geoHashesIterator].phi)
    {
        std::string csvLine = "";
        std::cout << "ghS:" << geoHashString << '\n';
        for(auto& gsmObj : geoHashVector)
        {
            //std::cout << db.O[gsmObj.id].ell << '\n';
            std::cout << db.O[gsmObj.id].xi << '\n';
        }
    }
}
#endif //GSM_GSQL_IGC_OPERATORS_H
