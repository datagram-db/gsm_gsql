#include <vector>
#include "database/GSMIso.h"

#include <args.hxx>
#include <string>
#include <iostream>
#include <configuration/Environment.h>

#include <easylogging++.h>
INITIALIZE_EASYLOGGINGPP

int main(int argc, char **argv) {
    // "data/queries/patterns.txt" "/home/giacomo/projects/gsm2/data/einstein.txt" -iortv -b out.csv
    args::ArgumentParser parser("gsm_gsql v2", "This provides an extended implementation of the GSM model for enabling the querying of generalised graph grammars over rooted DAGs.");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    args::Positional<std::string> pattern(parser, "pattern", "The pattern file");
    args::Positional<std::string> data(parser, "data", "The multi-graph file in .gsm format");
    args::Group group(parser, "Intermediate output generation", args::Group::Validators::DontCare);
    args::Flag input_data(group, "inputString", "Remarks that the -data field represents a string and not a file path", {'j', "inputString"});
    args::Flag query_data(group, "queryString", "Remarks that the -pattern field represents a string and not a file path", {'k', "queryString"});

    args::Flag in(group, "indot", "Generating files for each input graph", {'i', "input"});
    args::Flag out(group, "outdot", "Generating files representing the materialised views for the graphs", {'o', "output"});
    args::Flag removed(group, "removed", "Generating the .json representation of a list of removed nodes", {'r', "removed"});
    args::Flag inserted(group, "removed", "Generating the .json representation of a list of newly inserted nodes", {'t', "inserted"});

    args::Flag graph(group, "graph", "Determines that the output files should be in .dot format. Otherwise, everything is in .json for viz/", {'g', "graph"});
    args::Flag verbose(group, "verbose", "Full viz/data/ output", {'v', "verbose"});
    args::ValueFlag<std::string> benchmark_log(group, "benchmark", "Prints out the benchmark log", {'b', "benchmark"});
    args::ValueFlag<std::string> alternative_output(group, "benchmark", "Provides an alternative folder to the output, which is not viz/data", {'w', "outputFolder"});

    args::ValueFlag<size_t> script(group, "script", "runs script2 on the terminal over a specified DB", {'s', "script"});
    args::ValueFlag<std::string> schema(group, "schema", "provides an optional schema from string", {'z', "schema"});
    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (const args::Help&)
    {
        std::cout << parser;
        return 0;
    }
    catch (const args::ParseError& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    if ((!pattern) || (!data)) {
        std::cout << parser;
        return 1;
    }

    Configuration configuration;
    SerialisationStyle type;
    if (graph) {
        type = DOT_OUTPUT;
    } else {
        type = JSON_OUTPUT;
    }
    configuration.data.load_value = args::get(data);
    if (verbose) {
        configuration.full_server_output = true;
    } else {
        configuration.full_server_output = false;
    }
    if (input_data) {
        configuration.data.file_or_string_otherwise = false;
    } else {
        configuration.data.file_or_string_otherwise = true;
    }
    if (alternative_output) {
        configuration.output_folder = args::get(alternative_output);
    } else {
        configuration.output_folder = "";
    }
    if (script) {
        configuration.run_script_over_graph = args::get(script);
    } else {
        configuration.run_script_over_graph = -1;
        if (out) {
            configuration.conf.emplace_back(SerialisationType::OUTPUT_DATA, type);
        }
        if (removed) {
            configuration.conf.emplace_back(SerialisationType::REMOVED_DATA, type);
        }
        if (inserted) {
            configuration.conf.emplace_back(SerialisationType::INSERTED_DATA, type);
        }
        if (benchmark_log) {
            configuration.benchmark_log = args::get(benchmark_log);
        } else {
            configuration.benchmark_log = "";
        }
        ConfigurationArguments query;
        query.load_value = args::get(pattern);
        if (query_data) {
            query.file_or_string_otherwise = false;
        } else {
            query.file_or_string_otherwise = true;
        }
        configuration.query = query;
        if (schema) {
            configuration.opt_data_schema = args::get(schema);
        } else {
            configuration.opt_data_schema = "";
        }
    }
    if (in) {
        configuration.conf.emplace_back(SerialisationType::INPUT_DATA, type);
    }


    std::vector<std::vector<gsm_object>> output, expected;

    Environment env(configuration);
    env.run();

//    std::filesystem::path f{"/home/giacomo/projects/gsm2/data/test/einstein_expected.txt"};
//    parse(f, expected);
//    GSMIso eqSort;
//    bool result = eqSort.equals(output.at(0),
//                  expected.at(0),
//                  [](const gsm_object& lhs, const gsm_object& rhs) {
//        return lhs.xi == rhs.xi;
//    });

    return 0;
}
