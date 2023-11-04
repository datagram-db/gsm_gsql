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

include_directories(submodules/args)
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


add_library(yaucl_structures OBJECT #submodules/yaucl/src/yaucl/structures/StringPrevNext.cpp
     #   submodules/yaucl/include/yaucl/structures/StringPrevNext.h
      #  submodules/yaucl/src/yaucl/structures/DoublePrevNext.cpp
       # submodules/yaucl/include/yaucl/structures/DoublePrevNext.h
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

add_library(gsm_script ./antlr4/scriptv2/scriptBaseListener.cpp
        ./antlr4/scriptv2/scriptBaseVisitor.cpp
        ./antlr4/scriptv2/scriptLexer.cpp
        ./antlr4/scriptv2/scriptParser.cpp
        ./antlr4/scriptv2/scriptVisitor.cpp
        ./antlr4/scriptv2/scriptListener.cpp
        ./src/scriptv2/ScriptAST.cpp ./include/scriptv2/ScriptAST.h ./src/scriptv2/Funzione.cpp ./include/scriptv2/Funzione.h ./src/scriptv2/Javification.cpp ./include/scriptv2/Javification.h ./src/scriptv2/ScriptVisitor.cpp ./include/scriptv2/ScriptVisitor.h)
target_link_libraries(gsm_script antlr4_static)

add_library(gsm2 main.cpp antlr4/graph_grammar/simple_graph_grammarLexer.cpp antlr4/graph_grammar/simple_graph_grammarParser.cpp antlr4/graph_grammar/simple_graph_grammarListener.cpp  antlr4/graph_grammar/simple_graph_grammarVisitor.cpp src/database/PhiTable.cpp include/database/PhiTable.h src/database/AttributeTable.cpp include/database/AttributeTable.h src/database/SimplifiedFuzzyStringMatching.cpp include/database/SimplifiedFuzzyStringMatching.h src/database/LinearGSM.cpp include/database/LinearGSM.h src/database/ActivityTable.cpp include/database/ActivityTable.h src/result.cpp include/result.h src/database/gsm_indices.cpp include/database/gsm_indices.h src/queries/DataQuery.cpp include/queries/DataQuery.h src/database/gsm_object_xi_content.cpp include/database/gsm_object_xi_content.h include/simple_pair_hash.h src/queries/DataPredicate.cpp include/queries/DataPredicate.h
        #src/database/AtomizingPipeline2.cpp include/database/AtomizingPipeline2.h
        src/database/GSMPatternVisitor.cpp include/database/GSMPatternVisitor.h src/database/GraphEdgeMatchTable.cpp include/database/GraphEdgeMatchTable.h src/database/SimpleTable.cpp include/database/SimpleTable.h include/database/gsm_object.h src/database/gsm_object.cpp include/database/gsm_inmemory_db.h src/database/gsm_inmemory_db.cpp include/database/utility.h src/queries/preserve_results.cpp include/queries/preserve_results.h src/queries/delta_updates.cpp include/queries/delta_updates.h src/queries/closure.cpp include/queries/closure.h)
target_link_libraries(gsm2 antlr4_static yaucl_structures roaring  yaucl_hashing yaucl_graph )

add_executable(gsm2_server )
target_link_libraries(gsm2_server  antlr4_static yaucl_structures roaring  yaucl_hashing yaucl_graph gsm2 )

enable_testing ()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(gsm_gsql_script src/tests/script_runs.cpp)
target_link_libraries(gsm_gsql_script gtest_main gsm_script gsm2)
gtest_discover_tests(gsm_gsql_script)