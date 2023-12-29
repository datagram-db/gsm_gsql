#include <scriptv2/ScriptAST.h>
#include <scriptv2/ScriptVisitor.h>
#include <fstream>
#include <filesystem>
#include <catch2/catch_test_macros.hpp>
#include "configuration/Configuration.h"
#include "configuration/Environment.h"
#include "database/GSMIso.h"
//#include <gtest/gtest.h>
#include <easylogging++.h>
INITIALIZE_EASYLOGGINGPP

TEST_CASE("simple_scripts") {
    std::filesystem::path scripts_folder = std::filesystem::current_path().parent_path() / "data" / "script";

    SECTION("first") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_01.txt"};
        DPtr<script::structures::ScriptAST> ptr;
        script::compiler::ScriptVisitor::eval(file, ptr, {}, {});
        bool test = ptr->toString() == "10";
        REQUIRE(test);
    }

    SECTION("second") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_02.txt"};
        DPtr<script::structures::ScriptAST> ptr;
        script::compiler::ScriptVisitor::eval(file, ptr, {}, {});
        bool test = ptr->toString() == "Hello, world!";
        REQUIRE(test);
    }

    SECTION("third") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_03.txt"};
        DPtr<script::structures::ScriptAST> ptr;
        script::compiler::ScriptVisitor::eval(file, ptr, {}, {});
        bool test = ptr->toString() == R"({"H"; "e"; "l"; "l"; "o"; ","; " "; "w"; "o"; "r"; "l"; "d"; "!"})";
        REQUIRE(test);
    }

    SECTION("fourth") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_04.txt"};
        DPtr<script::structures::ScriptAST> ptr;
        script::compiler::ScriptVisitor::eval(file, ptr, {}, {});
        bool test = ptr->toString() == "5";
        REQUIRE(test);
    }

    SECTION("fifth") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_05.txt"};
        DPtr<script::structures::ScriptAST> ptr;
        script::compiler::ScriptVisitor::eval(file, ptr, {}, {});
        bool test = ptr->toString() == "tt";
        REQUIRE(test);
    }

    SECTION("sixth") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_06.txt"};
        DPtr<script::structures::ScriptAST> ptr;
        script::compiler::ScriptVisitor::eval(file, ptr, {}, {});
        bool test = ptr->toString() == "tt";
        REQUIRE(test);
    }

    SECTION("seventh") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_07.txt"};
        DPtr<script::structures::ScriptAST> ptr;
        script::compiler::ScriptVisitor::eval(file, ptr, {}, {});
        bool test = ptr->toString() == "ff";
        REQUIRE(test);
    }
}

TEST_CASE("einstein") {
    Configuration configuration;
    SerialisationStyle type;
    type = JSON_OUTPUT;

    std::filesystem::path input_data = std::filesystem::current_path().parent_path() / ("data") / "test" / "einstein.txt";
    configuration.full_server_output = true;
    configuration.data.file_or_string_otherwise = true;
    configuration.data.load_value = input_data;
    configuration.output_folder = "";
    configuration.run_script_over_graph = -1;
    configuration.conf.emplace_back(SerialisationType::OUTPUT_DATA, type);
    configuration.benchmark_log = "";
    ConfigurationArguments query;
    std::filesystem::path query_data = std::filesystem::current_path().parent_path() / ("data") / "test" / "einstein_query.txt";
    query.load_value = query_data;
    query.file_or_string_otherwise = true;
    configuration.opt_data_schema = "";
    configuration.query = query;


    std::vector<std::vector<gsm_object>> output, expected;

    Environment env(configuration);
    env.run_test(output);

    std::filesystem::path f = std::filesystem::current_path().parent_path() / ("data") / "test" / "einstein_expected.txt";
    parse(f, expected);
    GSMIso eqSort;
    bool result = eqSort.equals(output.at(0),
                                expected.at(0),
                                [](const gsm_object& lhs, const gsm_object& rhs) {
                                    return lhs.xi == rhs.xi;
                                });
    REQUIRE(result);
}