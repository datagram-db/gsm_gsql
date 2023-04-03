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

void calculate_lift(gsm_inmemory_db &db, int &nodesIterator)
{
    int previousAltitude = '\0';
    std::vector<std::vector<int>> lifts;
    lifts.push_back(std::vector<int>());
    bool newLift = true;
    int x = 0;
    for(auto &bFix : db.O[nodesIterator].phi["b_fix"])
    {
        int altitude;
        for(auto &data : db.O[bFix.id].phi["data"])
        {
            if (db.O[data.id].ell[0] == "pressure_altitude")
            {
                altitude = stoi(db.O[data.id].xi[0]);
            }
        }
        if (previousAltitude == '\0')
        {
            previousAltitude = altitude;
            continue;
        }

        if(altitude > previousAltitude)
        {
            if(newLift)
            {
                lifts.push_back(std::vector<int>());
                newLift = false;
            }
            int diffAltitude = altitude - previousAltitude;
            lifts.at(x).push_back(diffAltitude);
            previousAltitude = altitude;
        }
        else
        {
            if(!newLift)
                x++;
            newLift = true;
            previousAltitude = '\0';
        }
    }

    for(auto &it : lifts)
    {
        std::cout << "NEW LIFT PATTERN" << '\n';
        for(auto &it2 : it)
        {
            std::cout << it2 << '\n';
        }

    }
}

#endif //GSM_GSQL_IGC_OPERATORS_H
