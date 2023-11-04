#include <scriptv2/ScriptVisitor.h>
#include <scriptv2/ScriptAST.h>
#include <fstream>
#include <filesystem>
#include <gtest/gtest.h>

class simple_scripts : public testing::Test {
protected:
    void SetUp() override {
        script::compiler::ScriptVisitor::bindGSM(&database);
    }
    std::filesystem::path scripts_folder = std::filesystem::current_path().parent_path() / "data" / "script";
    gsm_inmemory_db database;
};

TEST_F(simple_scripts, first) {
    std::ifstream file{scripts_folder / "script_01.txt"};
    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file)->toString().c_str(), "10");
}

TEST_F(simple_scripts, second) {
    std::ifstream file{scripts_folder / "script_02.txt"};
    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file)->toString().c_str(), "Hello, world!");
}

TEST_F(simple_scripts, third) {
    std::ifstream file{scripts_folder / "script_03.txt"};
    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file)->toString().c_str(),
                 "{\"H\"; \"e\"; \"l\"; \"l\"; \"o\"; \",\"; \" \"; \"w\"; \"o\"; \"r\"; \"l\"; \"d\"; \"!\"}");
}

TEST_F(simple_scripts, fourth) {
    std::ifstream file{scripts_folder / "script_04.txt"};
    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file)->toString().c_str(),
                 "5");
}

TEST_F(simple_scripts, fifth) {
    std::ifstream file{scripts_folder / "script_05.txt"};
    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file)->toString().c_str(),
                 "tt");
}

TEST_F(simple_scripts, sixth) {
    std::ifstream file{scripts_folder / "script_06.txt"};
    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file)->toString().c_str(),
                 "tt");
}

TEST_F(simple_scripts, seventh) {
    std::ifstream file{scripts_folder / "script_07.txt"};
    ASSERT_STREQ(script::compiler::ScriptVisitor::eval(file)->toString().c_str(),
                 "ff");
}