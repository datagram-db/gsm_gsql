#include <iostream>
#include <vector>
#include <fstream>
#include "LinearGSM.h"


int main() {
    // setting up the database
    gsm2::tables::LinearGSM forloading;
    // loading the data from the file specification
    gsm2::tables::primary_memory_load_gsm2( "./data/text_visio.txt", forloading);

    // returning all the graphs and objects ids having det as a first label
    {
        auto result = forloading.timed_dataless_exists("det");
        for (const auto& x : result) {
            std::cout << x << std::endl;
        }
    }

    // Returning all nodes providing an approximate string matching on the node of the graph
    {
        auto result = forloading.approx_value_query(0.4, 100, "testem");
        for (const auto& x : result) {
            std::cout << x << std::endl;
        }
    }

    // Returning all the contents for the obejcts having "det" as a containment collection
    {
        std::unordered_map<std::pair<size_t, size_t>, std::vector<result>> resulted;
        std::vector<std::unordered_map<std::pair<size_t, size_t>, std::vector<result>>> v;
        v.emplace_back(forloading.query_container_or_containment("", "det"));
        v.emplace_back(forloading.query_container_or_containment("", "aux"));
        v.emplace_back(forloading.query_container_or_containment("", "nmod:poss"));
        multi_map_union(v, resulted, [](double x, double y)->double {
            return std::max(x,y);
        });
        v.clear();
    }

    // Getting the content associated to the object {0,0}, first from the first graph
    {
        auto phi = forloading.phi({0,0,false}, "advmod");
        for (const auto& x : phi) {
            std::cout << x << std::endl;
        } phi = forloading.phi({0,0,false}, "nsubj");
        for (const auto& x : phi) {
            std::cout << x << std::endl;
        }
    }


    return 0;
}
