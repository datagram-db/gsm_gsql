//
// Created by giacomo on 22/12/24.
//

#include <parser/commons.h>
#include <iostream>
#include "parser/schema/DataLoaderFromSchema.h"
#include "parser/readers/GSMReader.h"
#include "parser/readers/BulkReader.h"
#include "parser/writers/PrimaryMemoryLoader.h"
#include "parser/writers/GSMWriter.h"
#include "parser/writers/BulkWriter.h"


bool DataFormatHandler::data_to_format(const std::string& inPath,
                    DataFormat input,
                    const std::string& outPath,
                    DataFormat output) {
    std::pair<DataReader*, DataWriter*> cp{nullptr, nullptr};
    bool status=false;
    switch (input) {
        case NoDataFormat:
            cp.first = nullptr;
            break;
        case PrimaryMemoryDB:
            std::cerr << "ERROR: cannot read from a path" << std::endl;
            cp.first = nullptr;
            break;
        case Schema:
            cp.first = new SchemaReader();
            break;
        case GSM:
            cp.first = new GSMReader();
            break;
        case BulkFolder:
            cp.first = new BulkReader();
            break;
    }

    switch (output) {
        case NoDataFormat:
            cp.second = nullptr;
            break;
        case PrimaryMemoryDB:
            cp.second = new PrimaryMemoryLoader();
            break;
        case Schema:
            std::cerr << "ERROR: cannot write to a schema (yet)!" << std::endl;
            cp.second = nullptr;
            break;
        case GSM:
            cp.second = new GSMWriter();
            break;
        case BulkFolder:
            cp.second = new BulkWriter();
            break;
    }
    if (cp.second) {
        cp.second->writeToPath(outPath);
        if (cp.first) {
            cp.first->setWriter(cp.second);
        }
    }
    if ((!cp.first) || (!cp.second)) {
        delete cp.first;
        delete cp.second;
    } else {
        if (cp.first->readFromPath(inPath)) {
            this->memory.emplace(cp);
            status = true;
        } else {
            delete cp.first;
            delete cp.second;
        }
    }
    return status;
}


bool DataFormatHandler::write_from_reader(const std::string& outPath,
                       DataFormat output) {
    std::pair<DataReader*, DataWriter*> cp{nullptr, nullptr};
    if (memory.empty())
        return false;
    auto& top = memory.top();
    if (!top.second)
        return false;
    switch (output) {
        case NoDataFormat:
            cp.second = nullptr;
            break;
        case PrimaryMemoryDB:
            cp.second = new PrimaryMemoryLoader();
            break;
        case Schema:
            std::cerr << "ERROR: cannot write to a schema (yet)!" << std::endl;
            cp.second = nullptr;
            break;
        case GSM:
            cp.second = new GSMWriter();
            break;
        case BulkFolder:
            cp.second = new BulkWriter();
            break;
    }
    if (cp.second) {
        cp.second->writeToPath(outPath);
        cp.first = top.second->asReader(cp.second);
    }
    if ((!cp.first) || (!cp.second)) {
        delete cp.first;
        delete cp.second;
        return false;
    } else {
        this->memory.emplace(cp);
        return true;
    }
}