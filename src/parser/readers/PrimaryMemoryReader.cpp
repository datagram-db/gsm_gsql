//
// Created by giacomo on 22/12/24.
//

#include <parser/readers/PrimaryMemoryReader.h>

bool PrimaryMemoryReader::readFromPath(const std::string& path) {
    std::vector<std::vector<gsm_object>> duplet;
    memory.asObjects(duplet);
    for (const auto& g : duplet) {
        this->writer->initDatabase();
        for (const auto& obj : g) {
            this->writer->writeObject(obj, {});
        }
    }
    this->writer->close();
    return true;
}