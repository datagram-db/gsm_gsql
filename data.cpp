//
// Created by giacomo on 03/12/24.
//


#include <easylogging++.h>
INITIALIZE_EASYLOGGINGPP

//#include <fstream>
//#include "antlr4/schema_language/schemaLexer.h"
//#include "antlr4/schema_language/schemaParser.h"
//#include "antlr4/schema_language/schemaBaseVisitor.h"




//#include <parser/schema.h>



#include <iostream>

//using namespace rapidjson;
//using namespace std;



#include <parser/schema/DataLoaderFromSchema.h>


//#include <yaucl/strings/serializers.h>
//#include <stxxl.h>



int main(void) {
//    SchemaReader dl;
//    dl.readFromPath("/home/giacomo/Scaricati/Unibench-0.2/Dataset/Schema.txt");
//    std::cout << "Hello world!" << std::endl;
    DataFormatHandler dfh;

//    dfh.open_data_writer("/home/giacomo/writing_test_bulk", DataFormat::BulkFolder);
//    dfh.newDB();
//    dfh.writeObject({0, {"salutation"}, {"ciao", "mondo"}, {1.0}, {}, {{"language","italian"}}});
//    dfh.writeObject({1, {"salutation"}, {"hello", "world"}, {1.0}, {}, {{"language","english"}}});
//    dfh.writeObject({2, {"container"}, {}, {1.0}, {{"instances", {{0}, {1}}}}});
//    dfh.newDB();
//    dfh.writeObject({0, {"commiato"}, {"goodbye"}, {1.0}, {}, {{"language","english"}}});
//    dfh.writeObject({1, {"commiato"}, {"arrivederci"}, {1.0}, {{"instances", {{0}}}}});
//    dfh.close_writer();

    dfh.load_to_primary_memory("/home/giacomo/Scaricati/Unibench-0.2/Dataset/Schema.txt", DataFormat::Schema);
    std::cout << dfh.count_databases() << std::endl;
//    std::cout << dfh.retrieve(1,1).value().xi[0] << std::endl;


//    dfh.data_converter("/home/giacomo/projects/DATA_IDEAS2021/Schema.txt",
//                       DataFormat::Schema,
//                       "/home/giacomo/projects/DATA_IDEAS2021/gsm.txt",
//                       DataFormat::GSM);

    return EXIT_SUCCESS;
}
