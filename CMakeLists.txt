cmake_minimum_required(VERSION 3.22.1)
project(gsm2)


include_directories(include)
include_directories(submodules/yaucl/include)
include_directories(submodules/yaucl/submodules/json/include)
#include_directories(submodules/yaucl/submodules/CRoaring/cpp)
add_subdirectory(submodules/yaucl)

set(CMAKE_CXX_STANDARD 23)

add_executable(gsm2 main.cpp src/PhiTable.cpp include/PhiTable.h src/AttributeTable.cpp include/AttributeTable.h src/SimplifiedFuzzyStringMatching.cpp include/SimplifiedFuzzyStringMatching.h src/LinearGSM.cpp include/LinearGSM.h src/ActivityTable.cpp include/ActivityTable.h src/result.cpp include/result.h src/gsm_indices.cpp include/gsm_indices.h)
