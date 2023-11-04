//
// Created by giacomo on 09/04/23.
//

#ifndef GSM_GSQL_FUNZIONE_H
#define GSM_GSQL_FUNZIONE_H


#include <ostream>
#include <gsql_gsm/script_1/java_types.h>
#include <gsql_gsm/gsm_inmemory_db.h>

namespace script::structures {
    struct ScriptAST;

    struct Funzione {
        std::string parameter;
        ArrayList<DPtr<ScriptAST>> body;
        DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>> externalToUpdate;
        gsm_inmemory_db* database;

        void setDBRecursively(gsm_inmemory_db* db);

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
                        gsm_inmemory_db* db);
    };
}

#endif //GSM_GSQL_FUNZIONE_H
