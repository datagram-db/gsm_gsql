//
// Created by giacomo on 28/12/23.
//

#include "configuration/Environment.h"
#include "easylogging++.h"

#include "magic_enum.hpp"

static inline void parse_schema_map(std::istream& stream,
                                    std::unordered_map<std::string, gsm2::tables::AttributeTableType>& result) {
    std::string line;
    size_t count = 0;
    std::string field_name;
    gsm2::tables::AttributeTableType field_type = gsm2::tables::AttributeTableType::StringAtt;
    while (std::getline(stream, line)) {
        count++;
        if (count == 1)
            field_name = line;
        else {
            auto val = magic_enum::enum_cast<gsm2::tables::AttributeTableType>(line);
            if (val)
                field_type = val.value();
            else
                field_type = gsm2::tables::AttributeTableType::StringAtt;
            result[field_name] = field_type;
        }
    }
}

Environment::Environment(Configuration &conf) : conf{conf} {
    // Binding the query results for the script evaluator
    LOG(INFO) << "Initialisation";
    LOG(TRACE) << "Binding result to script visitor";
//    hasOutput = false;
//    prepare_server_full = false;
    script::compiler::ScriptVisitor::bindGSM(&result);
    script::compiler::ScriptVisitor::doAutoImplode = true;
}

void Environment::schema_loading() {
    LOG(INFO) << "Schema loading attempt";
    if (conf.data.file_or_string_otherwise) {
        LOG(TRACE) << "Loading from files: " << conf.data.load_value;
        std::filesystem::path path{conf.data.load_value};
        auto schema = path.parent_path() / "schema.txt";
        if (std::filesystem::exists(schema)) {
            LOG(TRACE) << "file schema exists";
            std::ifstream file{schema};
            parse_schema_map(file, propertyname_to_type);
        } else if (!conf.opt_data_schema.empty()) {
            LOG(TRACE) << "string schema exists";
            std::stringstream ss;
            ss << conf.opt_data_schema;
            parse_schema_map(ss, propertyname_to_type);
        } else {
            LOG(TRACE) << "no schema information was found";
        }
    } else {
        LOG(TRACE) << "Loading from string values";
        if (!conf.opt_data_schema.empty()) {
            LOG(TRACE) << "string schema exists";
            std::stringstream ss;
            ss << conf.opt_data_schema;
            parse_schema_map(ss, propertyname_to_type);
        } else {
            LOG(TRACE) << "no schema information was found";
        }
    }
}

void Environment::loading_and_indexing() {
    size_t n;
    LOG(INFO) << "Loading data";
    if (conf.data.file_or_string_otherwise) {
        LOG(TRACE) << "Loading data from file: " << conf.data.load_value;
        result.data_name = conf.data.load_value;
        std::string buffer;
        std::ifstream f(conf.data.load_value);
        f.seekg(0, std::ios::end);
        n = f.tellg();
        buffer.resize(f.tellg());
        f.seekg(0);
        f.read(buffer.data(), buffer.size());
        std::swap(buffer, conf.data.load_value);
    } else {
        result.data_name = "__data_value__";
        LOG(TRACE) << "Loading data from value";
        n = conf.data.load_value.size();
    }
    {
        LOG(TRACE) << "starting to parse data";
        auto loading_start = std::chrono::high_resolution_clock::now();
        result.new_data_slate();
        parse(conf.data.load_value.data(), n, *result.forloading, propertyname_to_type, result.forloading->nGraphs);
        auto loading_end = std::chrono::high_resolution_clock::now();
        result.loading_time = std::chrono::duration<double, std::milli>(loading_end-loading_start).count();
        LOG(TRACE) << "data parsed in " << result.loading_time << " ms";
    }
    result.isMaterialised = false;
    result.n_graphs = result.forloading->nGraphs;
    result.n_total_objects = result.forloading->main_registry.table.size();
    result.forloading->nGraphs++;
    neue.resize(result.forloading->nGraphs);
    LOG(INFO) << "Indexing data";
    {
        auto indexing_start = std::chrono::high_resolution_clock::now();
        result.forloading->index();
        auto indexing_end = std::chrono::high_resolution_clock::now();
        result.indexing_time = std::chrono::duration<double, std::milli>(indexing_end-indexing_start).count();
        LOG(TRACE) << "data indexed in " << result.indexing_time << " ms";
    }
}

#include "scriptv2/ScriptAST.h"

void Environment::run_script() {
    LOG(INFO) << "Console script for graph: " << conf.run_script_over_graph;
    std::string str;
    DPtr<std::unordered_map<std::string, DPtr<script::structures::ScriptAST>>> map = std::make_shared<std::unordered_map<std::string, DPtr<script::structures::ScriptAST>>>();
    map->insert(std::make_pair("graph", script::structures::ScriptAST::integer_(conf.run_script_over_graph)));
    while ((str = getLine()) != "quit!") {
//        void* parser{nullptr};
        DPtr<script::structures::ScriptAST> ptr;
        DPtr<script::structures::ScriptAST> program = script::compiler::ScriptVisitor::eval3(str.c_str(), str.length(),ptr, map);
        std::cout << program->run()->toString() << std::endl;
//        delete ((((scriptParser*)parser)));
    }
}

void Environment::prepare_output_folders(const std::filesystem::path &output_viz) {
    // Default folder for serialising the data
//        std::filesystem::path output_viz = std::filesystem::path("viz") / "data";
    if (std::filesystem::exists(output_viz)) {
        LOG(TRACE) << "removing previously created folder: " << output_viz;
        std::filesystem::remove_all(output_viz);
    }
    std::filesystem::create_directory(output_viz);
    for (size_t i = 0, N = result.forloading->nGraphs; i<N; i++) {
        auto output_viz_path = output_viz / std::to_string(i);
        LOG(TRACE) << "preparing folder: " << output_viz_path;
        if (!std::filesystem::is_directory(output_viz_path) || !std::filesystem::exists(output_viz_path)) { // Check if src folder exists
            std::filesystem::create_directory(output_viz_path); // create src folder
        } else {
            if (std::filesystem::is_regular_file(output_viz_path)) {
                std::filesystem::remove(output_viz_path);
                std::filesystem::create_directory(output_viz_path); // create src folder
            } else {
                for (const auto& entry : std::filesystem::directory_iterator(output_viz_path))
                    std::filesystem::remove_all(entry.path());
            }
        }
    }
}

void Environment::input() {
    for (const auto& ref : conf.conf) {
        if (ref.type == INPUT_DATA) {
            switch (ref.style) {
                case DOT_OUTPUT: {
                    std::vector<FlexibleGraph<std::string,std::string>> graphs;
                    result.asGraphs(graphs);
                    for (size_t i = 0, N = graphs.size(); i<N; i++) {
                        auto output_viz_path = output_viz / std::to_string(i);
                        std::ofstream f{output_viz_path / "in.dot"};
                        graphs.at(i).dot(f, false, "record");
                    }
                } break;

                case JSON_OUTPUT: {
                    std::vector<std::vector<gsm_object>> dbs2;
                    result.asObjects(dbs2);
                    size_t idx2 = 1;
                    for (const auto& json2 : dbs2){
                        auto output_viz_path = output_viz / std::to_string(idx2-1);
                        std::ofstream f{output_viz_path / "input.json"};
                        f << "[";
                        for (size_t i = 0, N = json2.size(); i<N; i++) {
                            neue[idx2-1].remove(json2.at(i).id);
                            json2.at(i).out_json(f);
                            if (i != (N-1)) f <<", " << std::endl;
                        }
                        if (neue[idx2-1].cardinality()>0) {
                            f<<","<<std::endl;
                            size_t i = 1;
                            for (size_t v : neue[idx2-1]) {
                                result.delta_updates_per_graph.at(idx2-1).delta_plus_db.O.at(v).out_json(f, true);
                                i++;
                                if (i <= neue[idx2-1].cardinality())
                                    f <<", " << std::endl;
                            }
                        }
                        f << "]";
                        idx2++;
                    }
                } break;

                case NONE_SS:
                    break;
            }
        }
    }
}

void Environment::removed() {
    for (const auto& ref : conf.conf) {
        if (ref.type == REMOVED_DATA) {
            for (size_t i = 0, N = result.delta_updates_per_graph.size(); i<N; i++) {
                auto output_viz_path = output_viz / std::to_string(i);
                std::ofstream f{output_viz_path / "removed.json"};
                f << "[";
                for (auto it = result.delta_updates_per_graph.at(i).removed_objects.begin(),
                             en = result.delta_updates_per_graph.at(i).removed_objects.end();
                     it != en; ) {
                    f << *it;
                    it++;
                    if (it != en) f <<", " << std::endl;
                }
                f << "]";
            }
        }
    }
}

void Environment::inserted() {
    for (const auto& ref : conf.conf) {
        for (size_t i = 0, N = result.delta_updates_per_graph.size(); i<N; i++) {
            auto output_viz_path = output_viz / std::to_string(i);
            std::ofstream f{output_viz_path / "inserted.json"};
//            std::ofstream f{args::get(data)+"_out_"+std::to_string(idx)+".json"};
            f << "[";
            for (auto it = neue[i].begin(),
                         en = neue[i].end();
                 it != en; ) {
                f << *it;
                it++;
                if (it != en) f <<", " << std::endl;
            }
            f << "]";
        }
    }
}

void Environment::output() {
    for (const auto& ref : conf.conf) {
        if ((ref.type == OUTPUT_DATA)) {
            switch (ref.style) {
                case DOT_OUTPUT: {
                    std::vector<FlexibleGraph<std::string, std::string>> graphs;
                    result.generateGraphsFromMaterialisedViews(graphs);
                    for (size_t i = 0, N = graphs.size(); i<N; i++) {
                        auto output_viz_path = output_viz / std::to_string(i);
                        std::ofstream f{output_viz_path / "out.dot"};
                        graphs.at(i).dot(f, false, "record");
                    }
                } break;

                case JSON_OUTPUT: {
                    std::vector<std::vector<gsm_object>> dbs;
                    result.fillInForSerialization(dbs);
                    size_t idx = 1;

                    for (const auto& json : dbs) {
                        {
                            auto output_viz_path = output_viz / std::to_string(idx-1);
                            std::ofstream f{output_viz_path / "result.json"};
                            f << "[";
                            for (size_t i = 0, N = json.size(); i<N; i++) {
                                const auto& o = json.at(i);
                                o.out_json(f);
                                neue[idx-1].add(o.id);
                                if (i != (N-1)) f <<", " << std::endl;
                            }
                            f << "]";
                        }
                        idx++;
                    }
                }

                case NONE_SS:
                    break;
            }
        }
    }
}

void Environment::prepare_output_folders() {
    if ((conf.output_folder.empty())) {
        output_viz = std::filesystem::path("viz") / "data";
    } else {
        output_viz = conf.output_folder;
    }
    LOG(INFO) << "Preparing output data folders in: " << output_viz;
    prepare_output_folders(output_viz);
}

void Environment::benchmark_log() const {
    if (!conf.benchmark_log.empty()) {
        std::filesystem::path file_name{conf.benchmark_log};
        bool doHeader = !exists(file_name);
        LOG(INFO) << "1) Loading: " << result.loading_time << " (ms)";
        LOG(INFO) << "2) Indexing: " << result.indexing_time << " (ms)";
        LOG(INFO) << "3) Querying: " << std::endl << "----------";
        LOG(INFO) << "* node matching: " << result.query_collect_node_match << " (ms)";
        LOG(INFO) << "* edge matching: " << result.query_collect_edge_match << " (ms)";
        LOG(INFO) << "* ν-morphism gen: " << result.generate_nested_morphisms << " (ms)";
        LOG(INFO) << "* transformations: " << result.run_transform << " (ms)";
        LOG(INFO) << "=>  TOTAL Querying: " << result.query_collect_node_match+result.query_collect_edge_match+result.generate_nested_morphisms+result.run_transform << " (ms)";;
        LOG(INFO) << "4) Materialisation: " << std::endl << "-----------------";
        LOG(INFO) << " * Old data migration to old representation: " << result.materialise_time_collection << " (ms)";
        LOG(INFO) << " * Merging old data with updates: " << result.materialise_time_final << " (ms)";
        LOG(INFO) << "=>  TOTAL Materialisation: " << result.materialise_time_collection+result.materialise_time_final << " (ms)";
        LOG(TRACE) << "Serialising into a csv file..." << std::flush;
        std::ofstream file(file_name, std::ios_base::app);
        if (doHeader)
            result.log_header(file);
        result.log_data(file);
        LOG(TRACE) << " done " << std::endl;
    }

}
