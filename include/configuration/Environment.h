//
// Created by giacomo on 28/12/23.
//

#ifndef GSM2_ENVIRONMENT_H
#define GSM2_ENVIRONMENT_H


#include "queries/closure.h"
#include "Configuration.h"


struct Environment {
    // Result for the intermediate query graphs
    closure result;
    struct Configuration conf;

    // loaded settings
    std::unordered_map<std::string, gsm2::tables::AttributeTableType> propertyname_to_type;
    std::vector<roaring::Roaring64Map> neue;
//    bool hasOutput;
//    bool prepare_server_full;
    std::filesystem::path output_viz;

    Environment(const struct Configuration& conf);
    void schema_loading();
    void loading_and_indexing();
    void run_script();
    void prepare_output_folders(const std::filesystem::path& output_viz);
    void input();
    void removed();
    void inserted();
    void output();
    void prepare_output_folders();
    void benchmark_log() const;

    void run_test( std::vector<std::vector<gsm_object>>&  dbs) {
        schema_loading();
        loading_and_indexing();
        if (!conf.query.has_value()) {
            LOG(ERROR) << "ERROR: a querying environment must specify the patterns to be queried!";
            exit(1);
        }
        if (conf.query->file_or_string_otherwise) {
            result.load_query_from_file(conf.query->load_value);
        } else {
            std::stringstream ss;
            ss << conf.query->load_value;
            result.load_query_from_string(ss);
        }
        result.perform_query(conf.full_server_output, conf.output_folder);
        result.fillInForSerialization(dbs);
    }

    void run() {
        schema_loading();
        loading_and_indexing();
        prepare_output_folders();
        if (conf.run_script_over_graph != -1) {
            run_script();
        } else {
            if (!conf.query.has_value()) {
                LOG(ERROR) << "ERROR: a querying environment must specify the patterns to be queried!";
                exit(1);
            }
            if (conf.query->file_or_string_otherwise) {
                result.load_query_from_file(conf.query->load_value);
            } else {
                std::stringstream ss;
                ss << conf.query->load_value;
                result.load_query_from_string(ss);
            }
            result.perform_query(conf.full_server_output, conf.output_folder);

            output();
            input();
            inserted();
            removed();

            benchmark_log();
        }
    }

};

#endif //GSM2_ENVIRONMENT_H
