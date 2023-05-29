cmake_minimum_required(VERSION 3.22.3)
project(gsm2)

include_directories(include)
include_directories(submodules/yaucl/include)
include_directories(submodules/yaucl/submodules/json/include)

set(CMAKE_CXX_STANDARD 23)

add_executable(gsm2 main.cpp src/PhiTable.cpp include/PhiTable.h src/AttributeTable.cpp include/AttributeTable.h src/SimplifiedFuzzyStringMatching.cpp include/SimplifiedFuzzyStringMatching.h src/LinearGSM.cpp include/LinearGSM.h src/ActivityTable.cpp include/ActivityTable.h)
