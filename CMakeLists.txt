cmake_minimum_required(VERSION 3.22.1)
project(gsm2)
set(CMAKE_CXX_STANDARD 23)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message(WARNING "Compiling in debug mode")
    add_compile_definitions(DEBUG)
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
else()
    message(WARNING "Compiling in optimized mode. Level=2")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2")
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)


include_directories(include)
include_directories(antlr4)
include_directories(submodules/yaucl/submodules/magic_enum/include)
include_directories(submodules/yaucl/include)
include_directories(submodules/yaucl/submodules/json/include)
include_directories(submodules/yaucl/submodules/CRoaring/cpp)
include_directories(submodules/yaucl/submodules/CRoaring/include)
add_subdirectory(submodules/yaucl/submodules/CRoaring)
add_subdirectory(submodules/yaucl/submodules/antlr4/runtime/Cpp)
include_directories(submodules/yaucl/submodules/antlr4/runtime/Cpp/runtime/src)
include_directories(submodules/yaucl/antlr4/cpp/antlr4)
include_directories(submodules/tabulate/include)


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


add_library(yaucl_structures OBJECT submodules/yaucl/src/yaucl/structures/StringPrevNext.cpp
        submodules/yaucl/include/yaucl/structures/StringPrevNext.h
        submodules/yaucl/src/yaucl/structures/DoublePrevNext.cpp
        submodules/yaucl/include/yaucl/structures/DoublePrevNext.h
        submodules/yaucl/include/yaucl/structures/setoids/set_comparators.h
        submodules/yaucl/include/yaucl/structures/setoids/set_partitioning.h
        submodules/yaucl/include/yaucl/structures/setoids/basics.h
        submodules/yaucl/include/yaucl/structures/indexed/BlockOfRecordsIndexedTable.h
        submodules/yaucl/src/yaucl/structures/RoaringBitmapWrapper.cpp
        submodules/yaucl/src/yaucl/structures/NAryTree.cpp
        submodules/yaucl/include/yaucl/structures/NAryTree.h
        submodules/yaucl/include/yaucl/structures/RelationalTables.h)
target_link_libraries(yaucl_structures roaring)


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


add_executable(gsm2 main.cpp antlr4/simple_graph_grammarLexer.cpp antlr4/simple_graph_grammarParser.cpp antlr4/simple_graph_grammarListener.cpp  antlr4/simple_graph_grammarVisitor.cpp src/database/PhiTable.cpp include/database/PhiTable.h src/database/AttributeTable.cpp include/database/AttributeTable.h src/database/SimplifiedFuzzyStringMatching.cpp include/database/SimplifiedFuzzyStringMatching.h src/database/LinearGSM.cpp include/database/LinearGSM.h src/database/ActivityTable.cpp include/database/ActivityTable.h src/result.cpp include/result.h src/database/gsm_indices.cpp include/database/gsm_indices.h src/queries/DataQuery.cpp include/queries/DataQuery.h src/database/IntermediateView.cpp include/database/IntermediateView.h src/database/gsm_object_xi_content.cpp include/database/gsm_object_xi_content.h include/simple_pair_hash.h src/queries/DataPredicate.cpp include/queries/DataPredicate.h AtomizingPipeline2.cpp AtomizingPipeline2.h GSMPatternVisitor.cpp GSMPatternVisitor.h GraphEdgeMatchTable.cpp GraphEdgeMatchTable.h SimpleTable.cpp SimpleTable.h)
target_link_libraries(gsm2 antlr4_static yaucl_structures roaring  yaucl_hashing yaucl_graph )