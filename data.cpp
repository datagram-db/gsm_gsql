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
    dfh.data_to_format("/home/giacomo/projects/DATA_IDEAS2021/Schema.txt",
                       DataFormat::Schema,
                       "/home/giacomo/projects/DATA_IDEAS2021/gsm.txt",
                       DataFormat::GSM);

    return EXIT_SUCCESS;
}
