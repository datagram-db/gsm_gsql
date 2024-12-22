//
// Created by giacomo on 21/12/24.
//

#include <parser/writers/GSMWriter.h>

void GSMWriter::writeToPath(const std::string& p) {
    start = true;
    this->path = p;
    b.open(path);
};

void GSMWriter::initDatabase() {
    if (start)
        start = false;
    else
        b << "~~\n";
};

#include <parsing.h>
#include "parser/readers/GSMReader.h"

void GSMWriter::writeObject(const gsm_object& object,  const std::unordered_map<std::string, gsm2::tables::AttributeTableType>& propertyname_to_type) {
    b << "id:" << object.id << "\n";

    b << "ell:\n";
    for (const auto& x : object.ell) {
        b << ReplaceAll(x, ".", "<dot>") << "\n";
    }
    b << ".\n";

    b << "xi:\n";
    for (const auto& x : object.xi) {
        b << ReplaceAll(x, ".", "<dot>") << "\n";
    }
    b << ".\n";

    b << "properties:\n";
    for (const auto& [c, p] : object.content) {
        if (std::holds_alternative<std::string>(p)) {
            b << std::quoted(c) << "\t" << std::quoted(std::get<std::string>(p)) << "\n";
        } else {
            b << std::quoted(c) << "\t\"" << std::get<double>(p) << "\"\n";
        }
    }
    b << ".\n";

    b << "phi:\n";
    for (const auto& [c, p] : object.phi) {
        b << std::quoted(c) << "\n";
        for (const auto& k : p) {
            b << "\t" << k.score << "\t" << k.id << "\n";
        }
        b << ";";
    }
    b << ".\n\n";

//    return b.str();
};

void GSMWriter::close() {
    b.close();
};


DataReader* GSMWriter::asReader() {
    auto* data = new GSMReader();
    data->readFromPath(this->path);
    return data;
};