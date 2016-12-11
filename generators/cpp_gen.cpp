//
// Created by Giacomo Bergami on 06/12/16.
//

#include "cpp_gen.h"

#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

int main() {

    json j;
    j["string"]["name"] = "std::string";
    j["string"]["mutable"] = true;

    j["array"]["name"] = "std::vector<@@>";
    j["array"]["mutable"] = true;

    j["ushort"]["name"] = "uint_fast8_t";
    j["ushort"]["mutable"] = false;
    j["ushort"]["size"] = sizeof(uint_fast8_t);

    j["short"]["name"] = "uint_fast8_t";
    j["short"]["mutable"] = false;
    j["short"]["size"] = sizeof(int_fast8_t);

    j["uint"]["name"] = "uint_fast32_t";
    j["uint"]["mutable"] = false;
    j["uint"]["size"] = sizeof(uint_fast32_t);

    j["int"]["name"] = "int_fast32_t";
    j["int"]["mutable"] = false;
    j["int"]["size"] = sizeof(int_fast32_t);

    j["ulong"]["name"] = "uint_fast64_t";
    j["ulong"]["mutable"] = false;
    j["ulong"]["size"] = sizeof(uint_fast64_t);

    j["long"]["name"] = "int_fast64_t";
    j["long"]["mutable"] = false;
    j["long"]["size"] = sizeof(int_fast64_t);

    std::ofstream o("../cpp/native.json");
    o << std::setw(4) << j << std::endl;

}
