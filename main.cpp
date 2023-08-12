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
    auto result = forloading.timed_dataless_exists("det");
    for (const auto& x : result) {
        std::cout << x << std::endl;
    }

    auto resulte = forloading.approx_value_query(0.4, 100, "testem");
    for (const auto& x : resulte) {
        std::cout << x << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
