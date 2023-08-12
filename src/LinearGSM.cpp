//
// Created by giacomo on 28/05/23.
//

#include "LinearGSM.h"
extern "C" {
#include <string.h>
}
/**
 *  haspos()
 * Dato un campo di testo \a text dove deve essere cercato \a BASE dalla
 * posizione \a pos in \a text, restituisce -1 se BASE è inesistente dal primo
 * suo carattere, altrimenti la posizione successiva all'ultimo carattere in BASE.
 */
static inline char* haspos(char* text, char* BASE, int pos, size_t* len) {
    int i;
    for (i=0;i<strlen(BASE); i++)
        if ((!(text[pos+i]==BASE[i]))&&(!(BASE[i]=='\0'))) {
            *len=0;
            return nullptr;
        }
    *len -= (pos+1);
    return &text[pos+i];
}



/**
 *  atreturn()
 *
 * FUNZIONE DI PARSING/LEXING
 * --------------------------
 * Restituisce eventualmente il puntatore alla stringa dopo una andata a capo
 */
static inline char* atreturn(char* buf,size_t* len) {
    int  end=0;
    for (end=0; end<*len; end++)
        if (buf[end]=='\n') {
            *len -= (end+1);
            return &buf[end+1];
        }
    *len = 0;
    return nullptr;
}

static inline char* skipSpaces(char*buf, size_t* len ) {
    while (isspace(*buf) && (*len)) { buf++; (*len)--; }
    if (!(*len)) return nullptr;
    return buf;
}

#include <yaucl/data/json.h>
static inline void parse(char* string, size_t len, gsm2::tables::LinearGSM& forloading) {
    string = skipSpaces(string, &len);
//    size_t graphId = 0;
    std::vector<std::string> ell, xi;
    size_t noLabel = forloading.label_map.put("").first;
    double weight; size_t content;
    size_t act_id = noLabel;
    int scanSkip = 0;
    constexpr char const * ID = "id:";
    constexpr char const * DOT = ".";
    constexpr char const * ELL = "ell:";
    constexpr char const * XI = "xi:";
    constexpr char const * PROP = "properties:";
    constexpr char const * PHI = "phi:";
//    size_t id;
    std::pair<size_t,size_t> graphId_eventId{0,0};
    // Defining a simple format to scan, so to avoid using a parser for this.
    while (string && *string) {
        // Reading a new object from the database for value querying
        graphId_eventId.second = 0;
        ell.clear();
        if (!(string = haspos(string, (char*)ID, 0, &len))) return;
        if (sscanf(string, "%lu%n", &graphId_eventId.second, &scanSkip)==EOF) return;
        len-=scanSkip;
        string+=scanSkip;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)ELL, 0, &len))) return;
        act_id = noLabel;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != '.') {
            char* beforeReturn = atreturn(string, &len);
            ell.emplace_back(string, beforeReturn-1);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
        if (!ell.empty()) {
            // Sending to fuzzy ell match
            forloading.ell_values.addGramsToMap(ell[0], graphId_eventId, ell);
            act_id = forloading.label_map.put(ell[0]).first;
        } else {
            act_id = noLabel;
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)XI, 0, &len))) return;
        // Setting up the new object
        forloading.main_registry.load_record(graphId_eventId.first, act_id, graphId_eventId.second);

        xi.clear();
        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != '.') {
            char* beforeReturn = atreturn(string, &len);
            xi.emplace_back(string, beforeReturn-1);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
        if (!xi.empty()) {
            // Sending to fuzzy xi match
            forloading.xi_values.addGramsToMap(xi[0], graphId_eventId, xi);
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)PROP, 0, &len))) return;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != '.') {
            char* beforeReturn = atreturn(string, &len);
            std::string tmp{string, beforeReturn-1};
            size_t idx = tmp.find("\t");
            if (idx == std::string::npos) return;
            std::string key = UNESCAPE(tmp.substr(0, idx));
            std::string val = UNESCAPE(tmp.substr(idx+1));
            // Setting up the properties associated to the node
            auto& table = forloading.KeyValueContainment[key];
            table.type = gsm2::tables::StringAtt;
            table.record_load(act_id, val, graphId_eventId.first, graphId_eventId.second);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string,  (char*)PHI, 0, &len))) return;

        if (!(string = atreturn(string, &len))) return;
        if (!(string = skipSpaces(string, &len))) return;
        while (*string != '.') {
            char* beforeReturn = atreturn(string, &len);
            std::string tmp{string, beforeReturn-1};
            tmp = UNESCAPE(tmp);
            string =beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
            while (*string != ';') {
                if (sscanf(string, "%lf\t%lu%n", &weight, &content,&scanSkip)==EOF) return;
                len-=scanSkip;
                string+=scanSkip;
                // Setting up the containment associated to the node
                forloading.containment_tables[tmp].add(act_id, graphId_eventId, weight, content);
                if (!(string = skipSpaces(string, &len))) return;
            }
            string++;
            len--;
            if (!(string = skipSpaces(string, &len))) return;
        }
        string++;
        len--;
        if (!(string = skipSpaces(string, &len))) return;

        if (strncmp(string,"~~",2)==0) {
            // Finding a new graph
            graphId_eventId.first++; string+=2; len-=2;
            if (!(string = skipSpaces(string, &len))) return;
        }
    }
    // TODO: indexing
}

#include <fstream>

namespace gsm2 {
    namespace tables {
        void primary_memory_load_gsm2(const std::filesystem::path& path, gsm2::tables::LinearGSM& db) {
            std::string buffer;
            std::ifstream f(path);
            f.seekg(0, std::ios::end);
            size_t n = f.tellg();
            buffer.resize(f.tellg());
            f.seekg(0);
            f.read(buffer.data(), buffer.size());
            parse(buffer.data(), n, db);
            db.index();
        }

        void LinearGSM::clear() {
            label_map.clear();
            containment_tables.clear();
            KeyValueContainment.clear();
            ell_values.clear();
            xi_values.clear();
            main_registry.clear();
        }

        void LinearGSM::index() {
            const auto& idx = main_registry.indexing1();
            for (auto& [key, table]: containment_tables)
                table.index();
            for (auto& [key, table] : KeyValueContainment)
                table.index(idx);
            main_registry.indexing2();
            main_registry.sanityCheck();
        }

        std::vector<result> LinearGSM::timed_dataless_exists(const std::string &act) const {
            std::vector<result> foundData;
            ssize_t mappedVal = getMappedValueFromAction(act);
            if(mappedVal < 0){
                return foundData;
            }
            auto indexes = main_registry.resolve_index(mappedVal);
            if(indexes.first < 0){
                return foundData;
            }
            for (auto it = main_registry.table.begin() + indexes.first; it != main_registry.table.begin() + indexes.second + 1; ++it) {
                foundData.emplace_back(it->graph_id, it->event_id);
            }
            return foundData;
        }

        std::vector<result>
        LinearGSM::approx_value_query(double min_threshold, size_t nmax, const std::string &xi) const {
            std::vector<result> result;
            std::function<void(const std::unordered_map<std::pair<size_t,size_t>, double>&)> f = [&result](const std::unordered_map<std::pair<size_t,size_t>, double>& m) {
                for (const auto& [k,v]: m) {
                    result.emplace_back(k.first, k.second, v);
                }
                std::sort(result.begin(), result.end());
            };
            xi_values.fuzzyMatch(min_threshold, nmax, xi, f);
            return result;
        }

        std::vector<result>
        LinearGSM::approx_label_query(double min_threshold, size_t nmax, const std::string &xi) const {
            std::vector<result> result;
            std::function<void(const std::unordered_map<std::pair<size_t,size_t>, double>&)> f = [&result](const std::unordered_map<std::pair<size_t,size_t>, double>& m) {
                for (const auto& [k,v]: m) {
                    result.emplace_back(k.first, k.second, v);
                }
                std::sort(result.begin(), result.end());
            };
            ell_values.fuzzyMatch(min_threshold, nmax, xi, f);
            return result;
        }

        std::vector<result> LinearGSM::query_container_or_containment(const std::string &container_object_label,
                                                                      const std::string &phi_label,
                                                                      std::function<double(
                                                                              const std::vector<double> &)> aggregate_scores,
                                                                      bool container_containementOth) const {
            std::vector<result> result;
            std::unordered_map<std::pair<size_t,size_t>, std::vector<double>> int_result;
            ssize_t phi_label_id = getMappedValueFromAction(phi_label);
            if (phi_label_id<0)
                return result;
            auto it = containment_tables.find(container_object_label);
            if (it == containment_tables.end())
                return result;
            auto it2 = it->second.primary_index.find(phi_label_id);
            if (it2 == it->second.primary_index.end())
                return result;
            auto iterator = it2->second;
            iterator.second++;
            for (; iterator.first != iterator.second; iterator.first++) {
                int_result[{iterator.first->graph_id,
                            container_containementOth ? iterator.first->object_id : iterator.first->id_contained}]
                        .emplace_back(iterator.first->w_contained);
            }
            for (const auto& [k,v] : int_result) {
                result.emplace_back(k.first, k.second, aggregate_scores(v));
            }
            std::sort(result.begin(), result.end());
            return result;
        }
    } // gsm2
} // structures
