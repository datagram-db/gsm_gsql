//
// Created by giacomo on 22/12/24.
//

#include <parser/writers/BulkWriter.h>

void BulkWriter::writeToPath(const std::string& path) {
    std::filesystem::path p{path};
    if ((!std::filesystem::exists(p)) && (!std::filesystem::is_directory(p))) {
        std::filesystem::create_directories(p);
    }
    this->path = p;
    this->dbCounter = 0;
    this->writer = nullptr;
}

void BulkWriter::initDatabase()  {
    if (this->writer) {
        this->writer->close();
        delete this->writer;
        this->dbCounter++;
    } else
        this->dbCounter = 0;
    std::string new_file = this->path / std::to_string(this->dbCounter);
    this->writer = new mapping(new_file);
}

void BulkWriter::close() {
    if (this->writer) {
        this->writer->close();
        delete this->writer;
        this->writer= nullptr;
    }
    this->dbCounter = -1;
}

void BulkWriter::writeObject(const gsm_object &object,
                             const std::unordered_map<std::string, gsm2::tables::AttributeTableType> &propertyname_to_type) {
    if (this->writer) {
        this->writer->serialize(object);
    }
}

#include <parser/readers/BulkReader.h>

DataReader* BulkWriter::asReader() {
    auto* reader = new BulkReader();
    reader->readFromPath(this->path);
    return reader;
}