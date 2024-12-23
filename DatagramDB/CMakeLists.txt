cmake_minimum_required(VERSION 3.22.1)
project(gsm2)
set(CMAKE_CXX_STANDARD 23)
# https://github.com/esa/kep3/blob/7841842952d4d252f56bf86ac42774743a1149fb/CMakeLists.txt#L6
set(CMAKE_CXX_SCAN_FOR_MODULES 0)
set(CAPNP_LITE ON)
set(BUILD_TESTING OFF)
set(CMAKE_C_COMPILER clang-19 CACHE INTERNAL "C compiler" )
set(CMAKE_CXX_COMPILER clang++-19 CACHE INTERNAL "C++ compiler")
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
set(WITH_DEMO false)
#add_subdirectory(../submodules/capnproto binbuild/capnproto)
include_directories(../submodules/capnproto/c++/src/)
set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "" FORCE)
#set(USE_COROUTINES ON CACHE BOOL "" FORCE)
#set(USE_FOLLY OFF CACHE BOOL "" FORCE)
set(ANTLR_BUILD_CPP_TESTS OFF)
include_directories(../submodules/rapidjson/include)
include_directories(../submodules/cpp-lru-cache/include)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(PYBIND11_NEWPYTHON ON)
set(PYBIND11_PYTHON_VERSION 3.8 CACHE STRING "")
set(PYBIND11_PYTHON_VERSION 3)
set(PYBIND11_FINDPYTHON ON)
find_package(PythonInterp REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
find_package(LibXml2 REQUIRED)
include_directories(${LIBXML2_INCLUDE_DIR})
include_directories(../submodules/easylogging/src)
#add_subdirectory(../submodules/easylogging binbuild/easylogging)

set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES "/usr/local/gcc-14.2.0/include/")
SET(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,/usr/local/gcc-14.2.0/lib/../lib64")
Include(FetchContent)
include(CTest)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
    message(WARNING "Compiling in debug mode")
    add_compile_definitions(DEBUG)
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
else()
    message(WARNING "Compiling in optimized mode. Level=3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)
include_directories(../submodules/yaucl/submodules/rocksdb/include)
include_directories(../submodules/args)
include_directories(../include)
include_directories(../antlr4)
include_directories(../submodules/yaucl/submodules/magic_enum/include)
include_directories(../submodules/yaucl/include)
include_directories(../submodules/yaucl/submodules/json/include)
include_directories(../submodules/yaucl/submodules/CRoaring/cpp)
include_directories(../submodules/yaucl/submodules/CRoaring/include)
add_subdirectory(../submodules/yaucl/submodules/CRoaring binbuild/croaring)
add_subdirectory(../submodules/yaucl/submodules/antlr4/runtime/Cpp binbuild/antlrcpp)
add_subdirectory(../submodules/pybind11 binbuild/pybind11)
include_directories(../submodules/yaucl/submodules/antlr4/runtime/Cpp/runtime/src)
include_directories(../submodules/yaucl/antlr4/cpp/antlr4)
include_directories(../submodules/tabulate/include)
add_subdirectory(../submodules/yaucl/submodules/rocksdb binbuild/rocksdb)

#<<<<<<< HEAD

add_library(kj OBJECT  ../submodules/capnproto/c++/src/kj/array.c++
        ../submodules/capnproto/c++/src/kj/cidr.c++
        ../submodules/capnproto/c++/src/kj/list.c++
        ../submodules/capnproto/c++/src/kj/common.c++
        ../submodules/capnproto/c++/src/kj/debug.c++
        ../submodules/capnproto/c++/src/kj/exception.c++
        ../submodules/capnproto/c++/src/kj/io.c++
        ../submodules/capnproto/c++/src/kj/memory.c++
        ../submodules/capnproto/c++/src/kj/mutex.c++
        ../submodules/capnproto/c++/src/kj/string.c++
        ../submodules/capnproto/c++/src/kj/source-location.c++
        ../submodules/capnproto/c++/src/kj/glob-filter.c++
        ../submodules/capnproto/c++/src/kj/hash.c++
        ../submodules/capnproto/c++/src/kj/table.c++
        ../submodules/capnproto/c++/src/kj/thread.c++
        ../submodules/capnproto/c++/src/kj/main.c++
        ../submodules/capnproto/c++/src/kj/arena.c++
        ../submodules/capnproto/c++/src/kj/test-helpers.c++
        ../submodules/capnproto/c++/src/kj/units.c++
        ../submodules/capnproto/c++/src/kj/encoding.c++)

add_library(capnp OBJECT   ../submodules/capnproto/c++/src/capnp/c++.capnp.c++
        ../submodules/capnproto/c++/src/capnp/blob.c++
        ../submodules/capnproto/c++/src/capnp/arena.c++
        ../submodules/capnproto/c++/src/capnp/layout.c++
        ../submodules/capnproto/c++/src/capnp/list.c++
        ../submodules/capnproto/c++/src/capnp/any.c++
        ../submodules/capnproto/c++/src/capnp/message.c++
        ../submodules/capnproto/c++/src/capnp/schema.capnp.c++
        ../submodules/capnproto/c++/src/capnp/stream.capnp.c++
        ../submodules/capnproto/c++/src/capnp/serialize.c++
        ../submodules/capnproto/c++/src/capnp/serialize-packed.c++)

add_library(yaucl_ndp OBJECT ../submodules/yaucl/src/yaucl/data/RocksDBMap.cpp
        ../submodules/yaucl/include/yaucl/data/RocksDBMap.h)
target_link_libraries(yaucl_ndp snappy bz2  z rt rocksdb)

add_library(yaucl_hashing OBJECT
        ../submodules/yaucl/include/yaucl/hashing/evaluateHashes.h
        ../submodules/yaucl/src/yaucl/hashing/evaluateHashes.c
        ../submodules/yaucl/src/yaucl/hashing/hash_combine.cpp
        ../submodules/yaucl/include/yaucl/hashing/hash_combine.h
        ../submodules/yaucl/src/yaucl/hashing/hashing.cpp
        ../submodules/yaucl/include/yaucl/hashing/hashing.h
        ../submodules/yaucl/include/yaucl/hashing/pair_hash.h
        ../submodules/yaucl/include/yaucl/hashing/vector_hash.h
        ../submodules/yaucl/include/yaucl/hashing/uset_hash.h)
target_include_directories(yaucl_hashing PUBLIC ${CMAKE_SOURCE_DIR}/include/yaucl/hashing/ ${CMAKE_CURRENT_BINARY_DIR})


add_library(yaucl_structures OBJECT #../submodules/yaucl/src/yaucl/structures/StringPrevNext.cpp
     #   ../submodules/yaucl/include/yaucl/structures/StringPrevNext.h
      #  ../submodules/yaucl/src/yaucl/structures/DoublePrevNext.cpp
       # ../submodules/yaucl/include/yaucl/structures/DoublePrevNext.h
        ../submodules/yaucl/include/yaucl/structures/setoids/set_comparators.h
        ../submodules/yaucl/include/yaucl/structures/setoids/set_partitioning.h
        ../submodules/yaucl/include/yaucl/structures/setoids/basics.h
        ../submodules/yaucl/include/yaucl/structures/indexed/BlockOfRecordsIndexedTable.h
        ../submodules/yaucl/src/yaucl/structures/RoaringBitmapWrapper.cpp
        ../submodules/yaucl/src/yaucl/structures/NAryTree.cpp
        ../submodules/yaucl/include/yaucl/structures/NAryTree.h
        ../submodules/yaucl/include/yaucl/structures/RelationalTables.h)
target_link_libraries(yaucl_structures roaring)


add_library(yaucl_graph OBJECT
        ../submodules/yaucl/src/yaucl/graphs/adjacency_graph.cpp
        ../submodules/yaucl/include/yaucl/graphs/adjacency_graph.h
        ../submodules/yaucl/include/yaucl/graphs/FlexibleGraph.h
        ../submodules/yaucl/include/yaucl/graphs/NodeLabelBijectionGraph.h
        ../submodules/yaucl/src/yaucl/graphs/graph_join_pm_algorithms.cpp
        ../submodules/yaucl/src/yaucl/graphs/graph_join_pm_conversion.cpp
        ../submodules/yaucl/include/yaucl/graphs/NodeLabelBijectionFA.h
        ../submodules/yaucl/src/yaucl/graphs/adjacency_entry.cpp
        ../submodules/yaucl/include/yaucl/graphs/adjacency_entry.h
        ../submodules/yaucl/src/yaucl/graphs/graph_join_pm.cpp
        ../submodules/yaucl/include/yaucl/graphs/graph_join_pm.h
        ../submodules/yaucl/include/yaucl/graphs/graph_join_pm.h
        ../submodules/yaucl/src/yaucl/graphs/graph_join_pm_conversion.cpp
        ../submodules/yaucl/src/yaucl/graphs/graph_join_pm_algorithms.cpp
        ../submodules/yaucl/src/yaucl/graphs/minimizeDFA.cpp
        ../submodules/yaucl/include/yaucl/graphs/algorithms/minimizeDFA.h
        ../submodules/yaucl/include/yaucl/graphs/algorithms/all_cycles.h
        ../submodules/yaucl/include/yaucl/graphs/algorithms/AllDirectedPaths.h
        ../submodules/yaucl/src/yaucl/graphs/algorithms/prim.cpp
        ../submodules/yaucl/include/yaucl/graphs/algorithms/prim.h
        ../submodules/yaucl/src/yaucl/graphs/algorithms/connected_components.cpp
        ../submodules/yaucl/include/yaucl/graphs/algorithms/connected_components.h
        )
target_link_libraries(yaucl_graph  yaucl_hashing roaring)

add_library(gsm_script OBJECT ../antlr4/scriptv2/scriptBaseListener.cpp
        ../antlr4/scriptv2/scriptBaseVisitor.cpp
        ../antlr4/scriptv2/scriptLexer.cpp
        ../antlr4/scriptv2/scriptParser.cpp
        ../antlr4/scriptv2/scriptVisitor.cpp
        ../antlr4/scriptv2/scriptListener.cpp
        ../src/scriptv2/ScriptAST.cpp
        ../include/scriptv2/ScriptAST.h
        ../src/scriptv2/Funzione.cpp
        ../include/scriptv2/Funzione.h
        ../src/scriptv2/Javification.cpp
        ../include/scriptv2/Javification.h
        ../src/scriptv2/ScriptVisitor.cpp
        ../include/scriptv2/ScriptVisitor.h)
target_link_libraries(gsm_script antlr4_static)

add_library(gsm_load OBJECT ../antlr4/schema_language/schemaBaseListener.cpp
        ../antlr4/schema_language/schemaBaseVisitor.cpp
        ../antlr4/schema_language/schemaLexer.cpp
        ../antlr4/schema_language/schemaListener.cpp
        ../antlr4/schema_language/schemaParser.cpp
        ../antlr4/schema_language/schemaVisitor.cpp)

add_library(gsm2 OBJECT
        ../submodules/easylogging/src/easylogging++.cc
        ../antlr4/graph_grammar/simple_graph_grammarLexer.cpp
        ../antlr4/graph_grammar/simple_graph_grammarParser.cpp
        ../antlr4/graph_grammar/simple_graph_grammarListener.cpp
        ../antlr4/graph_grammar/simple_graph_grammarVisitor.cpp
        ../src/database/PhiTable.cpp
        ../include/database/PhiTable.h
        ../src/database/AttributeTable.cpp
        ../include/database/AttributeTable.h
        ../src/database/SimplifiedFuzzyStringMatching.cpp
        ../include/database/SimplifiedFuzzyStringMatching.h
        ../src/database/LinearGSM.cpp
        ../include/database/LinearGSM.h
        ../src/database/ActivityTable.cpp
        ../include/database/ActivityTable.h
        ../src/result.cpp
        ../include/result.h
        ../src/database/gsm_indices.cpp
        ../include/database/gsm_indices.h
        ../src/queries/DataQuery.cpp
        ../include/queries/DataQuery.h
        ../src/database/gsm_object_xi_content.cpp
        ../include/database/gsm_object_xi_content.h
        ../include/simple_pair_hash.h
        ../src/queries/DataPredicate.cpp
        ../include/queries/DataPredicate.h
        ../submodules/easylogging/src/easylogging++.cc
        ../submodules/easylogging/src/easylogging++.h
        ../src/database/GSMPatternVisitor.cpp
        ../include/database/GSMPatternVisitor.h
        ../src/database/GraphEdgeMatchTable.cpp
        ../include/database/GraphEdgeMatchTable.h
        ../src/database/SimpleTable.cpp
        ../include/database/SimpleTable.h
        ../include/database/gsm_object.h
        ../src/database/gsm_object.cpp
        ../include/database/gsm_inmemory_db.h
        ../src/database/gsm_inmemory_db.cpp
        ../include/database/utility.h
        ../src/queries/preserve_results.cpp
        ../include/queries/preserve_results.h
        ../src/queries/delta_updates.cpp
        ../include/queries/delta_updates.h
        ../src/queries/closure.cpp
        ../include/queries/closure.h
        ../src/database/GSMIso.cpp
        ../include/database/GSMIso.h
        ../include/parsing.h
        ../include/configuration/base.h
        ../src/configuration/Serialisation.cpp
        ../include/configuration/Serialisation.h
        ../src/configuration/Configuration.cpp
        ../include/configuration/Configuration.h
        ../src/configuration/Environment.cpp
        ../include/configuration/Environment.h
        ../src/queries/NestedResultTable.cpp
        ../include/queries/NestedResultTable.h
        ../src/database/SchemaIndexer.cpp
        ../include/database/SchemaIndexer.h
       )
target_link_libraries(gsm2 antlr4_static yaucl_structures roaring  yaucl_hashing yaucl_graph ${LIBXML2_LIBRARIES} snappy bz2  z rt yaucl_ndp gsm_load kj capnp)

pybind11_add_module(pydatagramdb
        python.cpp)

target_link_libraries(pydatagramdb PRIVATE pybind11::headers pybind11::module antlr4_static yaucl_structures roaring  yaucl_hashing yaucl_graph  gsm2 gsm_script ${LIBXML2_LIBRARIES} snappy bz2  z rt yaucl_ndp gsm_load kj capnp)

install(TARGETS pydatagramdb LIBRARY DESTINATION .)
