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
        bool test = script::compiler::ScriptVisitor::eval(file, {}, {})->toString() == "10";
        REQUIRE(test);
    }

    SECTION("second") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_02.txt"};
        bool test = script::compiler::ScriptVisitor::eval(file, {}, {})->toString() == "Hello, world!";
        REQUIRE(test);
    }

    SECTION("third") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_03.txt"};
        bool test = script::compiler::ScriptVisitor::eval(file, {}, {})->toString() == "{\"H\"; \"e\"; \"l\"; \"l\"; \"o\"; \",\"; \" \"; \"w\"; \"o\"; \"r\"; \"l\"; \"d\"; \"!\"}";
        REQUIRE(test);
    }

    SECTION("fourth") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_04.txt"};
        bool test = script::compiler::ScriptVisitor::eval(file, {}, {})->toString() == "5";
        REQUIRE(test);
    }

    SECTION("fifth") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_05.txt"};
        bool test = script::compiler::ScriptVisitor::eval(file, {}, {})->toString() == "tt";
        REQUIRE(test);
    }

    SECTION("sixth") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_06.txt"};
        bool test = script::compiler::ScriptVisitor::eval(file, {}, {})->toString() == "tt";
        REQUIRE(test);
    }

    SECTION("seventh") {
        closure database;
        script::compiler::ScriptVisitor::bindGSM(&database);
        std::ifstream file{scripts_folder / "script_07.txt"};
        bool test = script::compiler::ScriptVisitor::eval(file, {}, {})->toString() == "ff";
        REQUIRE(test);
    }
}
//
//class simple_scripts : public testing::Test {
//protected:
//    void SetUp() override {
//    }
//
//};
//
//TEST_F(simple_scripts, first) {
//
//}
//
//TEST_F(simple_scripts, second) {
//    std::ifstream file{scripts_folder / "script_02.txt"};
//    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file, {}, {})->toString().c_str(), "Hello, world!");
//}
//
//TEST_F(simple_scripts, third) {
//    std::ifstream file{scripts_folder / "script_03.txt"};
//    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file, {}, {})->toString().c_str(),
//                 "{\"H\"; \"e\"; \"l\"; \"l\"; \"o\"; \",\"; \" \"; \"w\"; \"o\"; \"r\"; \"l\"; \"d\"; \"!\"}");
//}
//
//TEST_F(simple_scripts, fourth) {
//    std::ifstream file{scripts_folder / "script_04.txt"};
//    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file, {}, {})->toString().c_str(),
//                 "5");
//}
//
//TEST_F(simple_scripts, fifth) {
//    std::ifstream file{scripts_folder / "script_05.txt"};
//    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file, {}, {})->toString().c_str(),
//                 "tt");
//}
//
//TEST_F(simple_scripts, sixth) {
//    std::ifstream file{scripts_folder / "script_06.txt"};
//    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file, {}, {})->toString().c_str(),
//                 "tt");
//}
//
//TEST_F(simple_scripts, seventh) {
//    std::ifstream file{scripts_folder / "script_07.txt"};
//    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file, {}, {})->toString().c_str(),
//                 "ff");
//}