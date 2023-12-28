#include <scriptv2/ScriptAST.h>
#include <scriptv2/ScriptVisitor.h>
#include <fstream>
#include <filesystem>
#include <catch2/catch_test_macros.hpp>
//#include <gtest/gtest.h>

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