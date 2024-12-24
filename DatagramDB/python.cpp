//
// Created by giacomo on 26/08/24.
//

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>
#include <pybind11/stl/filesystem.h>

#include <vector>
#include "database/GSMIso.h"

#include <args.hxx>
#include <string>
#include <iostream>
#include <configuration/Environment.h>
#include <parser/commons.h>

#include <easylogging++.h>
INITIALIZE_EASYLOGGINGPP

namespace py = pybind11;

PYBIND11_MODULE(pydatagramdb, m) {
    py::class_<result>(m, "result")
    .def(py::init<size_t,size_t,size_t>())
    .def_readwrite("graphid", &result::graphid)
    .def_readwrite("eventid", &result::eventid)
    .def_readwrite("globalEdgeId", &result::globalEdgeId);

    py::class_<gsm_object_xi_content>(m, "gsm_object_xi_content")
    .def(py::init<size_t, double, size_t, std::map<std::string,union_minimal>>())
    .def_readwrite("id", &gsm_object_xi_content::id)
    .def_readwrite("score", &gsm_object_xi_content::score)
    .def_readwrite("orig_edge_id", &gsm_object_xi_content::orig_edge_id)
    .def_readwrite("property_values", &gsm_object_xi_content::property_values);

    py::class_<gsm_object>(m, "gsm_object")
    .def(py::init<size_t,
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<double>,
            std::unordered_map<std::string, std::vector<gsm_object_xi_content>>,
            std::unordered_map<std::string,union_minimal>>())
    .def_readwrite("id", &gsm_object::id)
    .def_readwrite("ell", &gsm_object::ell)
    .def_readwrite("xi", &gsm_object::xi)
    .def_readwrite("scores", &gsm_object::scores)
    .def_readwrite("phi", &gsm_object::phi)
    .def_readwrite("content", &gsm_object::content);

    py::class_<gsm2::tables::LinearGSM>(m, "LinearGSM")
    .def(py::init<>())
    .def_readwrite("objectScores", &gsm2::tables::LinearGSM::objectScores)
    .def("resolveContent", &gsm2::tables::LinearGSM::resolveContent)
    .def("resolveProperties", &gsm2::tables::LinearGSM::resolveProperties)
    .def("objectRelationships", &gsm2::tables::LinearGSM::objectRelationships)
    .def("containmentRelationships", &gsm2::tables::LinearGSM::containmentRelationships)
    .def("ell", &gsm2::tables::LinearGSM::ell_)
    .def("xi", &gsm2::tables::LinearGSM::xi_)
    .def("load_databases", &gsm2::tables::LinearGSM::load_databases)
    .def("resolveContainmentLabels", &gsm2::tables::LinearGSM::resolveContainmentLabels)
    .def("resolvePropertyLabels", &gsm2::tables::LinearGSM::resolvePropertyLabels)
    .def("index", &gsm2::tables::LinearGSM::index)
    ;

    py::class_<ConfigurationArguments>(m, "ConfigurationArguments")
    .def(py::init<std::string, bool>())
    .def_readwrite("load_value", &ConfigurationArguments::load_value)
    .def_readwrite("file_or_string_otherwise", &ConfigurationArguments::file_or_string_otherwise);

    py::enum_<DataFormat>(m, "DataFormat", py::arithmetic())
    .value("NoDataFormat", NoDataFormat)
    .value("PrimaryMemoryDB", PrimaryMemoryDB)
    .value("Schema", Schema)
    .value("GSM", GSM)
    .value("BulkFolder", BulkFolder)
    .export_values();

    py::enum_<SerialisationType>(m, "SerialisationType", py::arithmetic())
    .value("INPUT_DATA", INPUT_DATA)
    .value("OUTPUT_DATA", OUTPUT_DATA)
    .value("REMOVED_DATA", REMOVED_DATA)
    .value("NONE_ST", NONE_ST)
    .value("INSERTED_DATA", INSERTED_DATA)
    .export_values();

    py::enum_<gsm2::tables::AttributeTableType>(m, "AttributeTableType", py::arithmetic())
    .value("DoubleAtt", gsm2::tables::DoubleAtt)
    .value("SizeTAtt", gsm2::tables::SizeTAtt)
    .value("LongAtt", gsm2::tables::LongAtt)
    .value("StringAtt", gsm2::tables::StringAtt)
    .value("BoolAtt", gsm2::tables::BoolAtt)
    .export_values();

    py::enum_<SerialisationStyle>(m, "SerialisationStyle", py::arithmetic())
    .value("DOT_OUTPUT", DOT_OUTPUT)
    .value("JSON_OUTPUT", JSON_OUTPUT)
    .value("NONE_SS", NONE_SS)
    .export_values();

    py::class_<Serialisation>(m, "Serialisation")
    .def(py::init<SerialisationType, SerialisationStyle>())
    .def_readwrite("type", &Serialisation::type)
    .def_readwrite("style", &Serialisation::style);

    py::class_<Configuration>(m, "Configuration")
    .def(py::init<>())
    .def_readwrite("data", &Configuration::data)
    .def_readwrite("query", &Configuration::query)
    .def_readwrite("opt_data_schema", &Configuration::opt_data_schema)
    .def_readwrite("output_folder", &Configuration::output_folder)
    .def_readwrite("run_script_over_graph", &Configuration::run_script_over_graph)
    .def_readwrite("full_server_output", &Configuration::full_server_output)
    .def_readwrite("benchmark_log", &Configuration::benchmark_log)
    .def_readwrite("conf", &Configuration::conf);

    py::class_<Environment>(m, "Environment")
    .def(py::init<Configuration>())
    .def("run", &Environment::run);

    py::class_<RandomAccessBulkReader>(m, "RandomAccessBulkReader")
    .def(py::init<std::string>())
    .def("get_path", &RandomAccessBulkReader::get_path)
    .def("count_databases", &RandomAccessBulkReader::count_databases)
    .def("database_size", &RandomAccessBulkReader::database_size)
    .def("retrieve", &RandomAccessBulkReader::retrieve);


    py::class_<RandomAccessGSMReader>(m, "RandomAccessGSMReader")
    .def(py::init<>())
    .def("count_databases", &RandomAccessGSMReader::count_databases)
    .def("database_size", &RandomAccessGSMReader::database_size)
    .def("retrieve", &RandomAccessGSMReader::retrieve);


py::class_<DataFormatHandler>(m, "DataFormatHandler")
    .def(py::init<>())
    .def("data_converter", &DataFormatHandler::data_converter)
    .def("read_from_bulk_data", &DataFormatHandler::read_from_bulk_data)
    .def("load_to_primary_memory", &DataFormatHandler::load_to_primary_memory)
    .def("callback_reader", &DataFormatHandler::callback_reader)
    .def("open_data_writer", &DataFormatHandler::open_data_writer)
    .def("newDB", &DataFormatHandler::newDB)
    .def("writeObject", &DataFormatHandler::writeObject)
    .def("close_writer", &DataFormatHandler::close_writer)
    .def("close", &DataFormatHandler::close)
    .def("count_databases", &DataFormatHandler::count_databases)
    .def("database_size", &DataFormatHandler::database_size)
    .def("retrieve", &DataFormatHandler::retrieve);
}
