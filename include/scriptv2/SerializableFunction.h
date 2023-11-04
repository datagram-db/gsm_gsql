//
// Created by giacomo on 09/04/23.
//

#ifndef GSM_GSQL_SERIALIZABLEFUNCTION_H
#define GSM_GSQL_SERIALIZABLEFUNCTION_H

#include <string>
#include <vector>
#include <scriptv2/java_types.h>
struct ScriptAST;

struct SerializableFunction {
        virtual std::string toString(List<ScriptAST> x) = 0;
};

struct SerializableListFunctions : public SerializableFunction {
    virtual DPtr<ScriptAST> operator()(const List<DPtr<ScriptAST>>& x) = 0;
};



#endif //GSM_GSQL_SERIALIZABLEFUNCTION_H
