cmake_minimum_required(VERSION 3.22)
project(gsm_gsql)

set(CMAKE_CXX_STANDARD 23)
include_directories(include)
include_directories(submodules/tinyxml2)
add_subdirectory(submodules/tinyxml2)
include_directories(submodules/yaucl/include)
include_directories(submodules/yaucl/submodules/CRoaring/cpp)
add_subdirectory(submodules/yaucl)
include_directories(submodules/yaucl/submodules/json/include)

find_package(CURL REQUIRED)

add_library(gsm_gsql src/gsql_gsm/gsm_object_xi_content.cpp include/gsql_gsm/gsm_object_xi_content.h src/gsql_gsm/gsm_object.cpp include/gsql_gsm/gsm_object.h src/gsql_gsm/gsm_inmemory_db.cpp include/gsql_gsm/gsm_inmemory_db.h include/gsql_gsm/gsql_operators.h src/gsql_gsm/dump_to_xml.cpp include/gsql_gsm/dump_to_xml.h src/gsql_gsm/gsm_db_indices.cpp include/gsql_gsm/gsm_db_indices.h include/gsql_gsm/igc_operators.h)
target_link_libraries(gsm_gsql CURL::libcurl yaucl_graph yaucl_hashing roaring antlr4_static tinyxml2)

add_executable(gsm_gsql_test main.cpp)
target_link_libraries(gsm_gsql_test CURL::libcurl yaucl_graph yaucl_hashing roaring antlr4_static tinyxml2 gsm_gsql )