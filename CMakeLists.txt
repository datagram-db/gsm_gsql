cmake_minimum_required(VERSION 3.22.1)
project(gsm2)
set(CMAKE_CXX_STANDARD 23)

include_directories(include)
include_directories(submodules/yaucl/submodules/magic_enum/include)
include_directories(submodules/yaucl/include)
include_directories(submodules/yaucl/submodules/json/include)
include_directories(submodules/yaucl/submodules/CRoaring/cpp)
include_directories(submodules/yaucl/submodules/CRoaring/include)
add_subdirectory(submodules/yaucl/submodules/CRoaring)

add_library(yaucl_hashing OBJECT
        submodules/yaucl/include/yaucl/hashing/evaluateHashes.h
        submodules/yaucl/src/yaucl/hashing/evaluateHashes.c
        submodules/yaucl/src/yaucl/hashing/hash_combine.cpp
        submodules/yaucl/include/yaucl/hashing/hash_combine.h
        submodules/yaucl/src/yaucl/hashing/hashing.cpp
        submodules/yaucl/include/yaucl/hashing/hashing.h
        submodules/yaucl/include/yaucl/hashing/pair_hash.h
        submodules/yaucl/include/yaucl/hashing/vector_hash.h
        submodules/yaucl/include/yaucl/hashing/uset_hash.h)
target_include_directories(yaucl_hashing PUBLIC ${CMAKE_SOURCE_DIR}/include/yaucl/hashing/ ${CMAKE_CURRENT_BINARY_DIR})


add_library(yaucl_graph OBJECT
        submodules/yaucl/src/yaucl/graphs/adjacency_graph.cpp
        submodules/yaucl/include/yaucl/graphs/adjacency_graph.h
        submodules/yaucl/include/yaucl/graphs/FlexibleGraph.h
        submodules/yaucl/include/yaucl/graphs/NodeLabelBijectionGraph.h
        submodules/yaucl/src/yaucl/graphs/graph_join_pm_algorithms.cpp
        submodules/yaucl/src/yaucl/graphs/graph_join_pm_conversion.cpp
        submodules/yaucl/include/yaucl/graphs/NodeLabelBijectionFA.h
        submodules/yaucl/src/yaucl/graphs/adjacency_entry.cpp
        submodules/yaucl/include/yaucl/graphs/adjacency_entry.h
        submodules/yaucl/src/yaucl/graphs/graph_join_pm.cpp
        submodules/yaucl/include/yaucl/graphs/graph_join_pm.h
        submodules/yaucl/include/yaucl/graphs/graph_join_pm.h
        submodules/yaucl/src/yaucl/graphs/graph_join_pm_conversion.cpp
        submodules/yaucl/src/yaucl/graphs/graph_join_pm_algorithms.cpp
        submodules/yaucl/src/yaucl/graphs/minimizeDFA.cpp
        submodules/yaucl/include/yaucl/graphs/algorithms/minimizeDFA.h
        submodules/yaucl/include/yaucl/graphs/algorithms/all_cycles.h
        submodules/yaucl/include/yaucl/graphs/algorithms/AllDirectedPaths.h
        submodules/yaucl/src/yaucl/graphs/algorithms/prim.cpp
        submodules/yaucl/include/yaucl/graphs/algorithms/prim.h
        submodules/yaucl/src/yaucl/graphs/algorithms/connected_components.cpp
        submodules/yaucl/include/yaucl/graphs/algorithms/connected_components.h
        )
target_link_libraries(yaucl_graph  yaucl_hashing roaring)


add_executable(gsm2 main.cpp src/PhiTable.cpp include/PhiTable.h src/AttributeTable.cpp include/AttributeTable.h src/SimplifiedFuzzyStringMatching.cpp include/SimplifiedFuzzyStringMatching.h src/LinearGSM.cpp include/LinearGSM.h src/ActivityTable.cpp include/ActivityTable.h src/result.cpp include/result.h src/gsm_indices.cpp include/gsm_indices.h)
target_link_libraries(gsm2 roaring yaucl_hashing yaucl_graph)