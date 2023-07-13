#include <chrono>
#include <iostream>
#include "gsql_gsm/gsm_db_indices.h"
#include <gsql_gsm/gsql_operators.h>
#include <gsql_gsm/igc_operators.h>
#include <gsql_gsm/json_operators.h>

#include <string>
#include <gsql_gsm/dump_to_xml.h>

#include <vector>
#include <fstream>
#include "submodules/yaucl/submodules/rapidcsv/src/rapidcsv.h"
#include <nlohmann/json.hpp>
#include <filesystem>
#include <curl/curl.h>

#include <chrono>
#include "sys/types.h"
#include "sys/sysinfo.h"

using json = nlohmann::json;


void put_db(gsm_inmemory_db &db, int &iterator, std::vector<gsm_object_xi_content>&tablePhi,
            std::vector<double> &scores, std::string ell, std::string xi, double score = 1.0)
{
    create_fast(db, ++iterator, {ell}, {xi});
    tablePhi.emplace_back(iterator, score);
    scores.emplace_back(score);
}

void load_csvfile(gsm_inmemory_db &db, std::string csvFileDir, int &iterator, bool graph = false)
{

    char separator = (graph ? ';' : ','); // ; or ,


    rapidcsv::Document doc(csvFileDir, rapidcsv::LabelParams(0, -1), rapidcsv::SeparatorParams(separator));

    std::vector<std::string> colHeaders = doc.GetColumnNames();
    std::vector<gsm_object_xi_content> tablePhiCsv = {}; // phi table for csv file
    std::vector<double> scoresCsv = {}; // score table for csv file
    std::vector<gsm_object_xi_content> tablePhi = {}; // phi table for rows
    std::vector<double> scores = {}; // score table for rows

    for(int i = 0; i < doc.GetRowCount(); i++)
    {
        std::vector<std::string> row = doc.GetRow<std::string>(i);
        tablePhi = {};
        scores = {};

        for(int j = 0; j < row.size(); j++)
        {
            if(graph && (row.at(j).at(0) == '{' || row.at(j).at(0) == '['))
            {
                json data = json::parse(row.at(j));
                json_recursion(data, iterator, tablePhi, scores, db, colHeaders.at(j));
            }
            else
            {
                std::string x = colHeaders.at(j);
                put_db(db, iterator, tablePhi, scores, colHeaders.at(j), row.at(j));
            }
        }

        create_fast(db, ++iterator, {"row"}, {row.at(0)}, {scores}, {{"data", {tablePhi}}});
        tablePhiCsv.emplace_back(iterator, 1.0);
        scoresCsv.emplace_back(1.0);
    }
    create_fast(db, ++iterator, {"csv_file"}, {csvFileDir}, {scoresCsv}, {{"row", {tablePhiCsv}}});
}

void load_csvdb(gsm_inmemory_db &db, std::string pathToDb, int &iterator)
{
    std::vector<gsm_object_xi_content> tablePhiDb = {}; // Phi table for csv db
    std::vector<double> scoresCsvDb = {}; // Scores table for csv db
    for(const auto & entry : std::filesystem::directory_iterator(pathToDb))
    {
        std::cout << entry.path() << std::endl;
        load_csvfile(db, entry.path(), iterator);
        tablePhiDb.emplace_back(iterator, 1.0);
        scoresCsvDb.emplace_back(1.0);
    }
    create(db, ++iterator, {"csv_db"}, {pathToDb}, {scoresCsvDb}, {{"csv_file", {tablePhiDb}}});
}

int load_igcfile(gsm_inmemory_db &db, std::string pathToFile, int &iterator)
{
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream stream(pathToFile);
    std::vector<gsm_object_xi_content> tablePhiIgc = {};
    std::vector<double> scoresIgc = {};
    std::string date;
    //get pilot and date
    for(std::string line; std::getline(stream, line);)
    {
        if(line.substr(0,5) == "HFDTE")
        {
            if(line.at(line.size()-1) == '\r' || line.at(line.size()-1) == '\n')
                line.pop_back();
            date = line.substr(line.length()-6, 4) + "20" + line.substr(line.length()-2, 2);
            put_db(db, iterator, tablePhiIgc, scoresIgc, "date", {line.substr(line.length()-6, 6)});
            break;
        }
    }

    std::vector<gsm_object_xi_content> tablePhiBfixes = {};
    std::vector<double> scoresBfixes = {};
    //get flight nodes
    for(std::string line; std::getline(stream, line);)
    {
        if(line.at(0) == 'B')
        {
            create_fast(db, ++iterator, {"b_fix"}, {""});
            std::vector<gsm_object_xi_content> tablePhiBfix = {};
            std::vector<double> scoresBfix = {};

            std::string time = line.substr(1,6);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "time", time);
            //db.O[iterator].ell.push_back("time");
            //db.O[iterator].xi.push_back(time);

            std::string latitude = line.substr(7,8);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "latitude", latitude);
            //db.O[iterator].ell.push_back("latitude");
            //db.O[iterator].xi.push_back(latitude);

            std::string longitude = line.substr(15,9);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "longitude", longitude);
            //db.O[iterator].ell.push_back("longitude");
            //db.O[iterator].xi.push_back(longitude);

            std::string fixValidity = line.substr(24,1);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "fixValidity", fixValidity);
            //db.O[iterator].ell.push_back("fixValidity");
            //db.O[iterator].xi.push_back(fixValidity);

            std::string pressureAltitude = line.substr(25, 5);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "pressure_altitude", pressureAltitude);
            db.O[iterator].ell.push_back("pressure_altitude");
            db.O[iterator].xi.push_back(pressureAltitude);

            std::string gnssAltitude = line.substr(30, 5);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "gnss_altitude", gnssAltitude);
            //db.O[iterator].ell.push_back("gnss_altitude");
            //db.O[iterator].xi.push_back(gnssAltitude);

            std::tm t{};
            std::istringstream ss(date + time);
            //DDMMYYYY HHMMSS
            ss >> std::get_time(&t, "%d%m%Y%H%M%S");
            if (ss.fail())
            {
                throw std::runtime_error{"fail to parse fullDate"};
            }
            std::time_t timeStamp = mktime(&t);
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "unix_time", std::to_string(timeStamp));
            db.O[iterator].ell.push_back("unix_time");
            db.O[iterator].xi.push_back(std::to_string(timeStamp));

            double latDegrees = (double) stoi(latitude.substr(0, 2));
            double latMinutes = (double) stoi(latitude.substr(2, 5));
            latMinutes = latMinutes / 100000;
            latMinutes = (latMinutes*10)/6;
            int latSign = (latitude.at(7) == 'N' ? 1 : -1);
            double latitudeDouble = (latDegrees + latMinutes) * latSign;
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "latitude_double", std::to_string(latitudeDouble));
            db.O[iterator].ell.push_back("latitude_double");
            db.O[iterator].xi.push_back(std::to_string(latitudeDouble));

            double longDegrees = (double) stoi(longitude.substr(0, 3));
            double longMinutes = (double) stoi(longitude.substr(3, 5));
            longMinutes = longMinutes / 100000;
            longMinutes = (longMinutes*10)/6;
            int longSign = (longitude.at(8) == 'E' ? 1 : -1);
            double longitudeDouble = (longDegrees + longMinutes) * longSign;
            //put_db(db, iterator, tablePhiBfix, scoresBfix, "longitude_double", std::to_string(longitudeDouble));
            db.O[iterator].ell.push_back("longitude_double");
            db.O[iterator].xi.push_back(std::to_string(longitudeDouble));

            //create_fast(db, ++iterator, {"b_fix"}, {std::to_string(nodeNumber)}, {scoresBfix},
            //            {{{"data"}, {tablePhiBfix}}});
            tablePhiBfixes.emplace_back(iterator);
            scoresBfixes.emplace_back(1.0);
        }
    }
    create_fast(db, ++iterator, {"b_fixes"}, {}, {scoresBfixes}, {{"b_fix", {tablePhiBfixes}}});
    int bFixesIterator = iterator;

    tablePhiIgc.emplace_back(iterator);
    scoresIgc.emplace_back(1.0);
    create_fast(db, ++iterator, {"igc_file"}, {pathToFile}, {scoresIgc}, {{"fixes", {tablePhiIgc}}});
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end - start);
    std::cout << "x,Loading," << elapsed.count() << std::endl;
    return bFixesIterator;
}

void LoadGraph(gsm_inmemory_db &db, int &iterator, std::vector<std::string> &graphPaths)
{
    std::vector<gsm_object_xi_content> tablePhiGraph = {};
    std::vector<double> scoresGraph = {};
    for(auto &file : graphPaths)
    {
        load_csvfile(db, file, iterator, true);
        tablePhiGraph.emplace_back(iterator);
        scoresGraph.emplace_back(iterator);
    }
}

//void expand_with_lift_type(const gsm_inmemory_db& db,
//                           gsm_db_indices& idx,
//                           const std::set<std::string>& left ,
//                           const std::set<std::string>& right,
//                           const std::set<std::string>& additional,
//                           const gsm_object_xi_content& left_record,
//                           const gsm_object& left_object,
//                           const gsm_object_xi_content& right_record,
//                           const gsm_object& right_object,
//                           std::unordered_map<std::string, std::string>& row) {
//    if (left.contains(left_object.ell.at(0)))
//        row[left_object.ell.at(0)] = std::to_string(left_record.id);
//    bool isInLift = false;
//    bool isBeginLift = false;
//    for(auto& lift_series : db.O.at(liftsIterator).phi.at("lift_series"))
//    {
//        size_t count = 0;
//        for (auto& liftPart : db.O.at(lift_series.id).phi.at("lift")) {
//            size_t dst = idx.containedBy.addUniqueStateOrGetExisting(liftPart.id);
//            for(auto const& it : idx.containedBy.outgoingEdgesById2(idx.containedBy.addUniqueStateOrGetExisting(right_record.id)))
//            {
//                if(it.second == dst) {
//                    isInLift = true;
//                    if (count == 0)
//                        isBeginLift = true;
//                }
//                if(isInLift)
//                    break;
//            }
//            if(isInLift)
//                break;
//            count++;
//        }
//        if(isInLift)
//            break;
//    }
//    row["lift"] = (isInLift ? "1" : "0");
//    row["isbeginlift"] = (isBeginLift ? "1" : "0");
//}

int main() {
    // Database initialisation, with an empty root
    gsm_inmemory_db db;
    // latest object id added to the DB: adding those incrementally
    int max_obj_id = 0;

    std::string csvPath = "csv_files/";
    std::string jsonPath = "json_files/vc_6dk65ff_1673719200.json";
    std::string igcPath = "igc_files/long_10.igc";

    //load_jsonEllXiFile(db, jsonPath, iterator, {"currentConditions"}, "weather");

    // Load: Transformation function
    int multivariate_time_series_container = load_igcfile(db, igcPath, max_obj_id);
    create_fast(db, ++max_obj_id, {"result"});
    int join_result = max_obj_id;
    auto& join_table = db.O[join_result];

    ///////////////////////////////////
    ///////////////////////////////////
    /// - Value extractor for time series
    auto lift_extractor = [](const gsm_object_xi_content& rec, const gsm_object& obj) -> int{
        int altitude;
        for(int i = 0; i < obj.ell.size(); i++) {
            if (obj.ell.at(i) == "pressure_altitude") {
                altitude = stoi(obj.xi[i]);
                return altitude;
            }
        }
        return -1; // not found!
    };
    /// - Comparing between current and previous value: if the condition holds, this will be still part of the same time series
    auto comparator = [](const int& left, const int& right) {
        return left > right;
    };
    /// - Generating one holder for previous and current step in time series
    generate_cp_container<int> generate_pair_container = [](gsm_inmemory_db &db,
                            int previousId,
                            const gsm_object_xi_content &bFix,
                            const gsm_object &obj,
                            int previousAltitude,
                            int altitude,
                            std::pair<size_t, double> &out) {
        int diffAltitude = altitude - previousAltitude;
        static std::vector<gsm_object_xi_content> tablePhiLift(2);
        static std::vector<double> scoresLift(2, 1.0);
        tablePhiLift[0].id = previousId;
        tablePhiLift[1].id = (bFix.id);
        create_fast(db, out.first, {"lift"}, {std::to_string(diffAltitude)}, {scoresLift},
                    {{"b_fix", {tablePhiLift}}});
        out.second = 1.0;
    };
    //// - Actual invocation!
    int lift_series_collection = time_series_nesting<int>(db, multivariate_time_series_container, max_obj_id,
                                                          lift_extractor, comparator, generate_pair_container,
                                                          "b_fix", "lift", "lift_series", "lifts");
    ///////////////////////////////////
    ///////////////////////////////////

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

    ///////////////////////////////////
    ///////////////////////////////////
    /// - Extracting the current values for the bearing change
    auto extractor = [](const gsm_object& object, for_bearing_change& current) {
        current.bearing = 0;
        int got = 0;
        for(int i = 0; i < object.ell.size(); i++)
        {
            const auto& label = object.ell.at(i);
            if(label == "latitude_double") {
                current.lat = stod(object.xi.at(i));
                got++;
            } else if(label == "longitude_double") {
                current.lon = stod(object.xi.at(i));
                got++;
            } else if(label == "unix_time") {
                current.time = stoll(object.xi.at(i));
                got++;
            }
            if (got==3) break;
        }
    };
    /// - Actually performing the extension of the current object via the computation of the bearing change
    auto update_current = [](const double& initial_value,
                             for_bearing_change& previous,
                             for_bearing_change& current,
                             std::string &value_to_emplace) {
        current.computeBearing(previous);
        long long timeDiff = current.time - previous.time;

        previous.lon = current.lon;
        previous.lat = current.lat;
        previous.time = current.time;
        if(std::abs(previous.bearing) <= std::numeric_limits<double>::round_error()) {
            previous.bearing = current.bearing;
            value_to_emplace = std::to_string(initial_value);
        } else {
            double bearingChange = previous.bearing - current.bearing;
            if(std::abs(bearingChange) > 180.0) {
                if(bearingChange < 0.0)
                    bearingChange += 360.0;
                else
                    bearingChange -= 360.0;
            }
            double changeRate = bearingChange/((double)timeDiff);
            value_to_emplace = std::to_string(changeRate);
        }
    };
    incollection_tuple_extend<double, for_bearing_change>(db, multivariate_time_series_container, "b_fix",
                                                          "bearing_rate", 0, extractor,
                                                          update_current);
    ///////////////////////////////////
    ///////////////////////////////////

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

    ///////////////////////////////////
    ///////////////////////////////////
    /// - Definition of the hashing function associated to the current object
    auto hasher = [](const gsm_object_xi_content&, const gsm_object& current_object, geo_hash_support& values) -> std::string {
                for(int i = 0; i < current_object.ell.size(); i++)
        {
            if (current_object.ell.at(i) == "latitude_double") {
                values.lat = stod(current_object.xi[i]);
            } else if (current_object.ell.at(i) == "longitude_double") {
                values.lon = stod(current_object.xi[i]);
            } else if (current_object.ell.at(i) == "unix_time") {
                values.unixTime = stoll(current_object.xi[i]);
                values.unixTime = values.unixTime - (values.unixTime % 3600);
            }
        }
        values.geoHashString = geohash_encode(values.lat, values.lon, 6);
        return values.geoHashString + std::to_string((values.unixTime / 3600) % 24);
    };
    /// - Values associated to the bucket, for further unpacking the values from the hash!
    auto values = [](const geo_hash_support& values) -> std::vector<std::string> {
       return {values.geoHashString, std::to_string(values.unixTime), std::to_string(values.lat), std::to_string(values.lon)};
    };
    /// - Actual bucketing of obejcts within the collection
    int structural_hash_join_via_buckets = structural_hashbucket<geo_hash_support>(db,
                                                                                   multivariate_time_series_container,
                                                                                   max_obj_id, "geohashes", "b_fix",
                                                                                   hasher, "geohash", values);

    ///// 1. Loading the weather information
    auto embedder = [](gsm_inmemory_db &db,
                       int &iterator,
                       gsm_object &current_object) {
        long long unixTime = std::stoll(current_object.xi[1]);
        double lat = std::stod(current_object.xi[2]);
        double lon = std::stod(current_object.xi[3]);
        // Adding an object in one of its collections
        int val = vcweather_load(db, iterator, lat, lon, unixTime);
        current_object.phi["weather"].emplace_back(val);
    };
    ///// Magnani's embedding operator: extending an object with other objects at runtime
    ///// In particuilar, extending the structural hash join buckets with the second collection
    incollection_map(db, structural_hash_join_via_buckets, max_obj_id, embedder);

    auto start_indexing = std::chrono::high_resolution_clock::now();
    gsm_db_indices idx;
    idx.init(db);
    idx.valid_data();
    auto end_indexing = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(end_indexing - start_indexing);
    std::cout << "x,Indexing," << elapsed.count() << std::endl;
    bool getHeaders = true;
    std::string fn = "csv_files/lift10k.csv";
    std::ofstream fileOut(fn);

    auto calc_and_flat_to_disk = [lift_series_collection,&max_obj_id,&join_table](gsm_inmemory_db& db,
                                                                               const gsm_db_indices& idx,
                                                                               const std::set<std::string>& left ,
                                                                               const std::set<std::string>& right,
                                                                               const std::set<std::string>& additional,
                                                                               const std::vector<std::string>& header,
                                                                               const gsm_object_xi_content& left_record,
                                                                               const gsm_object& left_object,
                                                                               const gsm_object_xi_content& right_record,
                                                                               const gsm_object& right_object,
                                                                               std::unordered_map<std::string, std::string>& row) {
        if (left.contains(left_object.ell.at(0)))
            row[left_object.ell.at(0)] = std::to_string(left_record.id);
        bool isInLift = false;
        bool isBeginLift = false;

        size_t right_val = idx.containedBy.GetExisting(right_record.id);
        if (right_val !=-1) {
            for(auto const& it : idx.containedBy.outgoingEdgesById2(right_val)) {
                if (it.first == "b_fix") {;
                    size_t actual_lift_id = idx.containedBy.getUniqueLabel(it.second);
                    const auto& obj = db.O.at(actual_lift_id);
                    if ((obj.ell.size() < 1) || (obj.ell[0] != "lift"))
                        continue;
                    else
                        isInLift = true;
                    for (auto const& it2 : idx.containedBy.outgoingEdgesById2(it.second)) {
                        if (it2.first == "lift") {
                            size_t actual_liftseries_id = idx.containedBy.getUniqueLabel(it2.second);
                            const auto& obj2 = db.O.at(actual_liftseries_id);
                            if ((obj2.ell.size() < 1) || (obj2.ell[0] != "lift_series"))
                                continue;
                            if (obj2.phi.at("lift").at(0).id == actual_lift_id) {
                                isBeginLift = true;
                                break;
                            }
                        }
                    }
                    if (isInLift && isBeginLift)
                        break;
                }
                if (isInLift && isBeginLift)
                    break;
            }
        }


        row["lift"] = (isInLift ? "1" : "0");
        row["isbeginlift"] = (isBeginLift ? "1" : "0");

        std::vector<std::string> headers;
        std::vector<std::string> values;
        headers.emplace_back("tuple");
        values.emplace_back("");
        for (const auto& [k,v] : row) {
            headers.emplace_back(k);
            values.emplace_back(v);
        }
        create_fast(db, ++max_obj_id, headers, values);
        join_table.phi["table_rows"].emplace_back((size_t)max_obj_id);


//        if(getHeaders)
//        {
//            for (auto it = header.begin(), en = header.end(); it != en; ) {
//                fileOut << *it;
//                it++;
//                if (it != en)
//                    fileOut << ",";
//            }
//            fileOut << '\n';
//            getHeaders = false;
//        }
//        {
//            for (auto it = header.begin(), en = header.end(); it != en; ) {
//                fileOut << row.at(*it);
//                it++;
//                if (it != en)
//                    fileOut << ",";
//            }
//            fileOut << '\n';
//        }
    };



    std::string csvOutputFileName = "lift10k.csv";

    flat_natural_hash_join(db, structural_hash_join_via_buckets, idx, csvOutputFileName, "weather", "b_fix",
                           {"cloudcover", "dew", "feelslike", "humidity", "precip", "precipprob", "preciptype",
                            "pressure",
                                   /*"severerisk",*/ "snow", "snowdepth", "solarenergy", "solarradiation", "temp",
                            "uvindex", "visibility",
                            "weather_vc", "winddir", "windgust", "windspeed"},
                           {"bearing_rate", "latitude_double", "longitude_double", "pressure_altitude", "unix_time"},
                           {"lift", "isbeginlift"},
                           calc_and_flat_to_disk);

    // Dumping the db into a XML format
//    dump_to_xml(db, idx, "question_mark.xml");
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}