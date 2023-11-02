#include <vector>
#include <fstream>
#include <queries/closure.h>
#include <args.hxx>


int main(int argc, char **argv) {
    args::ArgumentParser parser("gsm_gsql v2", "This provides an extended implementation of the GSM model for enabling the querying of generalised graph grammars over rooted DAGs.");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
    args::Positional<std::string> pattern(parser, "pattern", "The pattern file");
    args::Positional<std::string> data(parser, "data", "The multi-graph file in .gsm format");
    args::Group group(parser, "Intermediate output generation", args::Group::Validators::DontCare);
    args::Flag indot(group, "indot", "Generating dot files for each input graph", {'i', "indot"});
    args::Flag outdot(group, "outdot", "Generating dot files representing the materialised views for the graphs", {'o', "outdot"});
    args::Flag print(group, "print", "Printing the matching edges", {'p', "print"});
    args::Flag verbose(group, "verbose", "Verbose table generation", {'v', "verbose"});
    args::ValueFlag<std::string> benchmark_log(group, "benchmark", "Prints out the benchmark log", {'b', "benchmark"});
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

    closure result;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Loading the query
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//    std::ifstream stream{args::get(pattern)};
    result.load_query_from_file(args::get(pattern));
//    antlr4::ANTLRInputStream input(stream);
//    simple_graph_grammarLexer lexer(&input);
//    antlr4::CommonTokenStream tokens(&lexer);
//    simple_graph_grammarParser parser(&tokens);
//    GSMPatternVisitor pv;
//    auto vl =  std::any_cast<std::vector<node_match>>(pv.visit(parser.all_matches()));
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Loading the data
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // setting up the database
    result.load_data_from_file(args::get(data)); // "./data/einstein.txt"
    // loading the data from the file specification

    // Plotting the loaded data if required
    if (indot) {
        std::vector<FlexibleGraph<std::string,std::string>> graphs;
        result.asGraphs(graphs);
        size_t idx = 1;
        for (const auto& g : graphs){
            std::ofstream f{args::get(data)+"_in_"+std::to_string(idx)+".dot"};
            g.dot(f, false, "record"); f << std::endl;
            idx++;
        }
    }

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Starting to query
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (verbose) {
        std::cout << "VERBOSE MODE: ON" << std::endl;
    } else {
        std::cout << "VERBOSE MODE: OFF" << std::endl;
    }
    result.perform_query(verbose);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    if (print) {
        std::ofstream f{args::get(pattern)+"_debug_edge_matching.txt"};
        result.pr.print_preliminary_edge_match_results(f);
    }

    //    result.generate_materialised_view();
    if (outdot) {
        std::vector<FlexibleGraph<std::string,std::string>> graphs;
        result.generateGraphsFromMaterialisedViews(graphs);
        size_t idx = 1;
        for (const auto& g : graphs){
            std::ofstream f{args::get(data)+"_out_"+std::to_string(idx)+".dot"};
            g.dot(f, false, "record"); f << std::endl;
            idx++;
        }
    }

    if (benchmark_log) {
        std::filesystem::path file_name = args::get(benchmark_log);
        bool doHeader = !exists(file_name);
        std::cout << "Loading: " << result.loading_time << " (ms)" << std::endl;
        std::cout << "Indexing: " << result.indexing_time << " (ms)" << std::endl << std::endl;
        std::cout << "Querying: " << std::endl << "----------" << std::endl;
        std::cout << "* node matching: " << result.query_collect_node_match << " (ms)" << std::endl;
        std::cout << "* edge matching: " << result.query_collect_edge_match << " (ms)" << std::endl;
        std::cout << "* ν-morphism gen: " << result.generate_nested_morphisms << " (ms)" << std::endl;
        std::cout << "* transformations: " << result.run_transform << " (ms)" << std::endl;
        std::cout << "=>  TOTAL: " << result.query_collect_node_match+result.query_collect_edge_match+result.generate_nested_morphisms+result.run_transform << " (ms)" << std::endl << std::endl;;
        std::cout << "Materialisation: " << std::endl << "-----------------" << std::endl;
        std::cout << " * Old data migration to old representation: " << result.materialise_time_collection << " (ms)" << std::endl;
        std::cout << " * Merging old data with updates: " << result.materialise_time_final << " (ms)" << std::endl;
        std::cout << "=>  TOTAL: " << result.materialise_time_collection+result.materialise_time_final << " (ms)" << std::endl;
        std::cout << "Serialising into a csv file..." << std::flush;
        std::ofstream file(file_name);
        if (doHeader)
            result.log_header(file);
        result.log_data(file);
        std::cout << " done " << std::endl;
    }

    return 0;
}
