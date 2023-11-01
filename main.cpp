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
    std::ifstream stream{args::get(pattern)};
    result.load_query_from_file(stream);
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


    return 0;
}
