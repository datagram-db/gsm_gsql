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
        auto result = forloading.timed_dataless_exists("det", false);
        for (const auto& x : result) {
            std::cout << x << std::endl;
        }
    }

    // Returning all nodes providing an approximate string matching on the node of the graph
    {
        auto result = forloading.approx_value_query(0.4, 100, "testem", false);
        for (const auto& x : result) {
            std::cout << x << std::endl;
        }
    }

    // Returning all the contents for the obejcts having "det" as a containment collection
    {
        auto result = forloading.query_container_or_containment("", "det",false);
    }

    // Getting the content associated to the object {0,0}, first from the first graph
    {
        auto phi = forloading.phi({0,0,false}, "advmod", false);
        for (const auto& x : phi) {
            std::cout << x << std::endl;
        } phi = forloading.phi({0,0,false}, "nsubj", false);
        for (const auto& x : phi) {
            std::cout << x << std::endl;
        }
    }


    return 0;
}
