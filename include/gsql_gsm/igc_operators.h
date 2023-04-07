//
// Created by neo on 29/03/23.
//

#ifndef GSM_GSQL_IGC_OPERATORS_H
#define GSM_GSQL_IGC_OPERATORS_H
#include <cmath>
#include <iostream>
#include <gsql_gsm/gsm_inmemory_db.h>
#include <iomanip>


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
void calculate_lift(gsm_inmemory_db &db, int &nodesIterator, int &iterator)
{
    std::vector<gsm_object_xi_content> tablePhiLifts = {};
    std::vector<double> scoresLifts = {};
    std::vector<gsm_object_xi_content> tablePhiLiftSeries = {};
    std::vector<double> scoresLiftSeries = {};
    int previousId;
    int previousAltitude = '\0';
    bool newLiftSeries = true;

    for(auto &bFix : db.O[nodesIterator].phi["b_fix"])
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

            createFast(db, ++iterator, {"lift"}, {std::to_string(diffAltitude)}, {scoresLift}, {{"altitudes", {tablePhiLift}}});
            tablePhiLiftSeries.push_back(iterator);
            scoresLiftSeries.push_back(1.0);
        }
        else
        {
            if(!newLiftSeries)
            {
                createFast(db, ++iterator, {"lift_series"}, {}, {scoresLiftSeries}, {{"lift", {tablePhiLiftSeries}}});
                tablePhiLifts.emplace_back(iterator);
                scoresLifts.emplace_back(1.0);
            }
            newLiftSeries = true;
        }
        previousAltitude = altitude;
        previousId = dataId;
    }
    createFast(db, ++iterator, {"lifts"}, {}, {scoresLifts}, {{"lift_series", {tablePhiLifts}}});
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

static inline
void generate_weatherbucket(gsm_inmemory_db &db, int &nodesIterator, int &iterator) {
    std::vector<gsm_object_xi_content> tablePhiGeoHashes = {};
    std::vector<double> scoresGeohashes = {};
    std::unordered_map<std::string, std::vector<gsm_object_xi_content>> tablePhiGeoHash;
    std::unordered_map<std::string, std::vector<double>> scoresGeohash;
    long long previousUnixTime = -1;
    long long unixTime;
    bool added = false;
    for (auto &bFix: db.O[nodesIterator].phi["b_fix"]) {
        double lat;
        double lon;

        for (auto &data: db.O[bFix.id].phi["data"]) {
            if (db.O[data.id].ell[0] == "latitude_double") {
                lat = stod(db.O[data.id].xi[0]);
            } else if (db.O[data.id].ell[0] == "longitude_double") {
                lon = stod(db.O[data.id].xi[0]);
            } else if (db.O[data.id].ell[0] == "unix_time") {
                unixTime = stoll(db.O[data.id].xi[0]);
            }
        }
        if (previousUnixTime == -1) {
            previousUnixTime = unixTime - (unixTime % 3600);
        }

        std::string geoHash = geohash_encode(lat, lon);

        if (unixTime - previousUnixTime >= 3600) {
            //at time bucket
            for (auto &geoHashObject: tablePhiGeoHash) {
                //TODO: load weather, add weather to phi
                createFast(db, ++iterator, {"geohash"}, {geoHashObject.first}, {scoresGeohash[geoHashObject.first]},
                           {{{"data"}, {geoHashObject.second}}});
                tablePhiGeoHashes.emplace_back(iterator);
                scoresGeohashes.emplace_back(1.0);
            }
            createFast(db, ++iterator, {"geohashes"}, {std::to_string(previousUnixTime)}, {scoresGeohashes},
                       {{{"geohash"}, {tablePhiGeoHashes}}});
            tablePhiGeoHash = {};
            scoresGeohash = {};
            previousUnixTime = unixTime - (unixTime % 3600);
        }

        if (tablePhiGeoHash.find(geoHash) == tablePhiGeoHash.end()) {
            tablePhiGeoHash[geoHash] = std::vector<gsm_object_xi_content>();
            scoresGeohash[geoHash] = std::vector<double>();
        }
        tablePhiGeoHash[geoHash].emplace_back(bFix.id);
        scoresGeohash[geoHash].emplace_back(1.0);
    }
    if(unixTime - previousUnixTime <= 3600)
    {
        for (auto &geoHashObject: tablePhiGeoHash)
        {
            //TODO: load weather, add weather to phi
            createFast(db, ++iterator, {"geohash"}, {geoHashObject.first},{scoresGeohash[geoHashObject.first]},{{{"data"}, {geoHashObject.second}}});
            tablePhiGeoHashes.emplace_back(iterator);
            scoresGeohashes.emplace_back(1.0);
        }
        createFast(db, ++iterator, {"geohashes"}, {std::to_string(previousUnixTime)},{scoresGeohashes},{{{"geohash"}, {tablePhiGeoHashes}}});
    }
}


#endif //GSM_GSQL_IGC_OPERATORS_H
