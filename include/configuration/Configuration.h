//
// Created by giacomo on 28/12/23.
//

#ifndef GSM2_CONFIGURATION_H
#define GSM2_CONFIGURATION_H

#include <string>
#include <optional>
#include <vector>
#include "Serialisation.h"

struct ConfigurationArguments {
    std::string load_value{""};
    bool        file_or_string_otherwise{false};

    ConfigurationArguments() = default;
    ConfigurationArguments(const ConfigurationArguments&) = default;
    ConfigurationArguments(ConfigurationArguments&&) = default;
    ConfigurationArguments& operator=(const ConfigurationArguments&) = default;
    ConfigurationArguments& operator=(ConfigurationArguments&&) = default;
};


struct Configuration {
    ConfigurationArguments                                            data;
    std::optional<ConfigurationArguments>                             query;
    std::string                                                       opt_data_schema;
    std::string                                                       output_folder;
    ssize_t                                                           run_script_over_graph{-1};

    bool                            full_server_output;
    std::string                     benchmark_log;

    std::vector<Serialisation>      conf;
};


#endif //GSM2_CONFIGURATION_H
