//
// Created by giacomo on 09/04/23.
//

#ifndef GSM_GSQL_FUNZIONE_H
#define GSM_GSQL_FUNZIONE_H


#include <queries/closure.h>
#include <ostream>
#include <scriptv2/java_types.h>
#include <database//gsm_inmemory_db.h>

namespace script::structures {
    struct ScriptAST;

    struct Funzione {
        std::string parameter;
        ArrayList<DPtr<ScriptAST>> body;
        DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>> externalToUpdate;
        closure* database;

        void setDBRecursively(closure* db);

        friend std::ostream &operator<<(std::ostream &os, const Funzione &funzione);

        Funzione(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& g, const std::string& x); // : externalToUpdate{g}, parameter{x} {}

        void addExpression(DPtr<ScriptAST>&& expr);
//        void addExpression(DPtr<ScriptAST>&& expr) {
//            expr->optGamma = externalToUpdate;
//            body.emplace_back(expr);
//        }

        DPtr<ScriptAST> apply(DPtr<ScriptAST> x);

//
        void setContext(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& context,
                        closure* db);
    };
}

#endif //GSM_GSQL_FUNZIONE_H
