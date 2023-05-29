#include <iostream>
#include <vector>
extern "C" {
#include <string.h>
}
#include <fstream>
#include "LinearGSM.h"


/**
 *  haspos()
 * Dato un campo di testo \a text dove deve essere cercato \a BASE dalla
 * posizione \a pos in \a text, restituisce -1 se BASE è inesistente dal primo
 * suo carattere, altrimenti la posizione successiva all'ultimo carattere in BASE.
 */
char* haspos(char* text, char* BASE, int pos, size_t* len) {
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
 *  surfto()
 * Dato un campo di testo \a text, si vuole cercare dal suo inizio il carattere
 * base: verrà restituita la posizione successiva al ritrovamento del carattere,
 * altrimenti NULL
 */
char*
surfto(char* text, char base, int text_size)
{
    int i;
    for (i=0; i<text_size; i++)
        if (text[i]==base) return &text[i+1];
    return nullptr;
}



/**
 *  atreturns()
 *
 * FUNZIONE DI PARSING/LEXING
 * --------------------------
 * Restituisce eventualmente il puntatore alla stringa dopo due andate a capo
 */
char* atreturns(char* buf,int len) {
    int  end=0;
    for (end=0; end<len; end++)
        if ((end>0)&&(buf[end]==buf[end-1])&&(buf[end]=='\n')) return &buf[end+1];
    return nullptr;
}

/**
 *  atreturn()
 *
 * FUNZIONE DI PARSING/LEXING
 * --------------------------
 * Restituisce eventualmente il puntatore alla stringa dopo una andata a capo
 */
static char* atreturn(char* buf,size_t* len) {
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
void parse(char* string, size_t len, gsm2::tables::LinearGSM& forloading) {
    string = skipSpaces(string, &len);
    size_t graphId = 0;
    std::vector<std::string> ell, xi;
    size_t noLabel = forloading.label_map.put("").first;
    double weight; size_t content;
    size_t act_id = noLabel;
    size_t scanSkip = 0;
    while (string) {
        size_t id = 200;
        ell.clear();
        if (!(string = haspos(string, "id:", 0, &len))) return;
        if (sscanf(string, "%lu%n", &id, &scanSkip)==EOF) return;
        len-=scanSkip;
        string+=scanSkip;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string, "ell:", 0, &len))) return;
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
            forloading.ell_values.addGramsToMap(ell[0], id, ell);
            act_id = forloading.label_map.put(ell[0]).first;
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string, "xi:", 0, &len))) return;
        // Setting up the new object
        forloading.main_registry.load_record(graphId, act_id, id);

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
            forloading.xi_values.addGramsToMap(xi[0], id, xi);
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string, "properties:", 0, &len))) return;

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
            forloading.KeyValueContainment[key].record_load(act_id, val, graphId, id);
            string = beforeReturn;
            if (!(string = skipSpaces(string, &len))) return;
        }
        string++; len--;
        if (!(string = skipSpaces(string, &len))) return;
        if (!(string = haspos(string, "phi:", 0, &len))) return;

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
                forloading.containment_tables[tmp].add(act_id, id, weight, content);
                if (!(string = skipSpaces(string, &len))) return;
            }
            string++;
            len--;
            if (!(string = skipSpaces(string, &len))) return;
        }
        if (!(string = skipSpaces(string, &len))) return;

        if (strncmp(string,"~~",2)==0) {
            // Finding a new graph
            graphId++; string+=2; len-=2;
        }
    }
    // TODO: indexing
}


int main() {
    gsm2::tables::LinearGSM forloading;
    std::string buffer;
    std::ifstream f("/home/giacomo/text_visio.txt");
    f.seekg(0, std::ios::end);
    size_t n = f.tellg();
    buffer.resize(f.tellg());
    f.seekg(0);
    f.read(buffer.data(), buffer.size());
    parse(buffer.data(), n, forloading);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
