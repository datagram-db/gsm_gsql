//
// Created by giacomo on 09/04/23.
//

#include <scriptv2//Funzione.h>
#include <scriptv2//ScriptAST.h>

std::ostream &script::structures::operator<<(std::ostream &os, const Funzione &funzione) {
    os << funzione.parameter << " -> {";

    for (auto it = funzione.body.begin(), en = funzione.body.end(); it != en; ) {
        os << *it;
        it++;
        if (it != en) os << "; ";
    }
    return os;
}


void script::structures::Funzione::setDBRecursively(gsm_inmemory_db* db) {
    database = db;
    for (auto& ref : body)
        ref->setDBRecursively(db);
    if (externalToUpdate)
        for (auto& [k,v] : *externalToUpdate) {
            v->setDBRecursively(db);
        }
}

script::structures::Funzione::Funzione(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& g, const std::string& x) : externalToUpdate{g}, parameter{x} {}

void script::structures::Funzione::setContext(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& context,
                                              gsm_inmemory_db* db) {
    externalToUpdate = context;
    database = db;
    for (auto& ref : body)
        ref->setContext(context, db);
}

void script::structures::Funzione::addExpression(DPtr<ScriptAST>&& expr) {
    expr->optGamma = externalToUpdate;
    expr->db = database;
    body.emplace_back(expr);
}
        DPtr<script::structures::ScriptAST> script::structures::Funzione::apply(DPtr<script::structures::ScriptAST> x) {
            std::unordered_set<std::string> ve;
            for (const auto& [k,v] : *externalToUpdate)
                ve.insert(k);
            x = x->run();
            auto cp = externalToUpdate->insert_or_assign(parameter, x);
            DPtr<script::structures::ScriptAST> old{nullptr};
            if (!cp.second) {
                old = std::move(cp.first->second);
                cp.first->second = x;
            }
            DPtr<script::structures::ScriptAST> toReturn = std::make_shared<script::structures::ScriptAST>();
            toReturn->type = Array;
            toReturn->optGamma = externalToUpdate;
            for (auto& y : body) {
                y->optGamma = externalToUpdate;
                toReturn = y->run();
            }
            if (!old.get()) {
                externalToUpdate->erase(parameter);
            } else {
                (*externalToUpdate)[parameter] = old;
            }
            // RetainAll
            for (auto it = externalToUpdate->begin(); it != externalToUpdate->end(); ) {
                if (!ve.contains(it->first))
                    it = externalToUpdate->erase(it);
                else
                    it++;
            }
            return toReturn;
        }