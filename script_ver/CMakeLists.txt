cmake_minimum_required(VERSION 3.22)
project(gsm_gsql)

set(CMAKE_CXX_STANDARD 23)
include_directories(include)
include_directories(submodules/tinyxml2)
add_subdirectory(submodules/tinyxml2)
include_directories(submodules/yaucl/include)
include_directories(submodules/yaucl/submodules/CRoaring/cpp)
include_directories(submodules/yaucl/submodules/CRoaring/include)
add_subdirectory(submodules/yaucl)
include_directories(submodules/yaucl/submodules/json/include)

find_package(CURL REQUIRED)

include_directories(antlr4/cpp/antlr4/script/)
include_directories(submodules/yaucl/submodules/antlr4/runtime/Cpp/runtime/src)
add_library(gsm_script ../antlr4/scriptv2/scriptBaseListener.cpp
        ../antlr4/scriptv2/scriptBaseVisitor.cpp
        ../antlr4/scriptv2/scriptLexer.cpp
        ../antlr4/scriptv2/scriptParser.cpp
        ../antlr4/scriptv2/scriptVisitor.cpp
        ../antlr4/scriptv2/scriptListener.cpp
        ../src/scriptv2/ScriptAST.cpp ../include/scriptv2/ScriptAST.h ../src/scriptv2/Funzione.cpp ../include/scriptv2/Funzione.h ../src/scriptv2/Javification.cpp ../include/scriptv2/Javification.h ../src/scriptv2/ScriptVisitor.cpp ../include/scriptv2/ScriptVisitor.h)
target_link_libraries(gsm_script antlr4_static)


add_library(gsm_gsql src/gsql_gsm/gsm_object_xi_content.cpp include/gsql_gsm/gsm_object_xi_content.h src/gsql_gsm/gsm_object.cpp include/gsql_gsm/gsm_object.h src/gsql_gsm/gsm_inmemory_db.cpp include/gsql_gsm/gsm_inmemory_db.h include/gsql_gsm/gsql_operators.h src/gsql_gsm/dump_to_xml.cpp include/gsql_gsm/dump_to_xml.h src/gsql_gsm/gsm_db_indices.cpp include/gsql_gsm/gsm_db_indices.h include/gsql_gsm/igc_operators.h include/gsql_gsm/gsm_transformation_operators.h)
target_link_libraries(gsm_gsql CURL::libcurl yaucl_graph yaucl_hashing roaring antlr4_static tinyxml2)

add_executable(gsm_gsql_test main.cpp)
target_link_libraries(gsm_gsql_test CURL::libcurl yaucl_graph yaucl_hashing roaring antlr4_static gsm_script tinyxml2 gsm_gsql )


enable_testing ()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(gsm_gsql_script ../src/tests/script_runs.cpp)
target_link_libraries(gsm_gsql_script gtest_main gsm_script gsm_gsql)
gtest_discover_tests(gsm_gsql_script)