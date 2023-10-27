#include <vector>
#include <fstream>
#include <queries/closure.h>



int main() {
    closure result;

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Loading the query
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    std::ifstream stream{"./patterns.txt"};
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
    result.load_data_from_file("/home/giacomo/projects/tweetyPrEAF/broker/haxe/protocol/out.txt");
    // loading the data from the file specification

    std::vector<FlexibleGraph<std::string,std::string>> graphs;
    result.asGraphs(graphs);
    for (const auto& g : graphs){
        g.dot(std::cout, false, "record"); std::cout << std::endl;
    }
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Starting to query
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    result.perform_query();

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    result.pr.print_preliminary_edge_match_results(std::cout);

//    result.generate_materialised_view();
    graphs.clear();
    result.generateGraphsFromMaterialisedViews(graphs);
    for (const auto& g : graphs){
        g.dot(std::cout, false, "record"); std::cout << std::endl;
    }

//    std::cout << "<" << std::endl;
//
//
//    // returning all the graphs and objects ids having det as a first label
//    {
//        auto result = forloading.timed_dataless_exists("det");
//        for (const auto& x : result) {
//            std::cout << x << std::endl;
//        }
//    }
//
//    // Returning all nodes providing an approximate string matching on the node of the graph
//    {
//        auto result = forloading.approx_value_query(0.4, 100, "testem");
//        for (const auto& x : result) {
//            std::cout << x << std::endl;
//        }
//    }
//
//    // Returning all the contents for the objects having "det" as a containment collection
//    {
//        std::unordered_map<std::pair<size_t, size_t>, std::vector<result>> resulted;
//
//        // Temporary Data
//        std::vector<std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>> v;
//        forloading.query_container_or_containment(v.emplace_back(), "", "det");
//        forloading.query_container_or_containment(v.emplace_back(),"", "aux");
//        forloading.query_container_or_containment(v.emplace_back(),"", "nmod:poss");
//        multi_map_union(v, resulted, [](double x, double y)->double {
//            return std::max(x,y);
//        });
//        v.clear();
//    }
//
//    // Getting the content associated to the object {0,0}, first from the first graph
//    {
//        auto phi = forloading.phi({0,0,false}, "advmod");
//        for (const auto& x : phi) {
//            std::cout << x << std::endl;
//        } phi = forloading.phi({0,0,false}, "nsubj");
//        for (const auto& x : phi) {
//            std::cout << x << std::endl;
//        }
//    }


    return 0;
}
