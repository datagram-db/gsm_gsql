//
// Created by giacomo on 28/12/23.
//

#ifndef GSM2_PARSING_H
#define GSM2_PARSING_H

#include <sstream>
#include <iostream>
#include <string_view>
static bool endsWith(std::string_view str, std::string_view suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

static bool startsWith(std::string_view str, std::string_view prefix)
{
    return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}

static inline std::string getLine() {
    std::cout << "> " << std::flush;
    std::stringstream s;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (endsWith(line, ";")) {
            s << line;
            std::string tmp = s.str();
            tmp.pop_back();
            return tmp;
        } else {
            s << line << std::endl;
        }
    }
    std::string tmp;
    if (endsWith(line, ";")) {
        tmp = s.str();
        tmp.pop_back();
    }
    return tmp;
}

#include <chrono>
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

static inline
std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    //https://stackoverflow.com/a/24315631/1376095
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

#endif //GSM2_PARSING_H
