//
// Created by giacomo on 10/04/23.
//
#include <queries/closure.h>
#include "yaucl/graphs/NodeLabelBijectionGraph.h"
#include <scriptv2/ScriptVisitor.h>
#include <database/SchemaIndexer.h>
#include <scriptv2/Funzione.h>
#include "scriptv2/scriptLexer.h"

#include "yaucl/strings/string_utils.h"

namespace script {
    namespace compiler {
        bool ScriptVisitor::doAutoImplode= false;
        closure* ScriptVisitor::db = nullptr;
        ScriptVisitor* ScriptVisitor::instance = nullptr;
        NodeLabelBijectionGraph<std::string,std::function<DPtr<script::structures::ScriptAST>(DPtr<script::structures::ScriptAST>&&)>> ScriptVisitor::typecaster {};

        std::any ScriptVisitor::visitScript(scriptParser::ScriptContext *context) {
            auto result = std::make_shared<script::structures::ScriptAST>();
            result->optGamma = this->context;
            result->db = db;
            ArrayList<DPtr<script::structures::ScriptAST>> v;
            innerBlock(context->inner_block(), v);

            for (const auto& tmp : v) {
//                auto tmp = any_cast<DPtr<script::structures::ScriptAST>>(visit(x));
                tmp->setContext(result->optGamma, result->db);
                auto currDB = result->db;
                result = tmp->run(doAutoImplode);
                if (!result->db)
                    result->db = currDB;
                if (!result->optGamma)
                    result->optGamma = this->context;
            }
            return result;
        }

        DPtr<script::structures::ScriptAST> ScriptVisitor::visitScript2(scriptParser::ScriptContext *context) {
            return any_cast<DPtr<script::structures::ScriptAST>>(visit(context->inner_block()->expr()));
        }

//        DPtr<script::structures::ScriptAST> ScriptVisitor::evalExpr(script::structures::ScriptAST* tmp) {
////            tmp->setContext(this->context, db);
////            tmp->setDBRecursively(db);
//            auto result = tmp->run(doAutoImplode);
//            return result;
//        }

        bool ScriptVisitor::evalBool(const char* data,size_t len,size_t patt,
                                                                DPtr<script::structures::ScriptAST>& ptrResult,
                                                                const std::vector<std::string>& schema,
                                                                const std::vector<value>& nestedRow) {
            script::structures::ScriptAST::globals.clear();
            script::structures::ScriptAST::idxers->current_template =patt;
            script::structures::ScriptAST::idxers->attemptInitialise(patt, &schema).initialize(&nestedRow);
#if 1
            // Setting up the environment variables from the record
            for (size_t i = 0; i < std::min(schema.size(), nestedRow.size()); i++) {
                const std::string &varName2 = schema.at(i);
                const auto &id = nestedRow.at(i);
                if (id.isNested)
//                {
//                    if (
                    //                    girt <double>(id.val)) {
//                        script::structures::ScriptAST::globals.emplace(varName2, std::move(script::structures::ScriptAST::double_(
//                                std::get<double>(id.val))));
//                    } else if (std::holds_alternative<std::string>(id.val)) {
//                        script::structures::ScriptAST::globals.emplace(varName2, std::move(script::structures::ScriptAST::string_(
//                                std::get<std::string>(id.val))));
//                    } else if (std::holds_alternative<size_t>(id.val)) {
//                        script::structures::ScriptAST::globals.emplace(varName2, std::move(script::structures::ScriptAST::integer_(
//                                (long long) std::get<size_t>(id.val))));
//                    }
//                } else
                {
                    ArrayList<DPtr<script::structures::ScriptAST>> listOfRows;
                    for (size_t k = 0; k < id.table.datum.size(); k++) {
                        StringMap<DPtr<script::structures::ScriptAST>> record;
                        for (size_t j = 0; j < id.table.Schema.size(); j++) {
                            const std::string &varName3 = id.table.Schema.at(j);
                            const auto &id3 = id.table.datum.at(k).at(j);
                            if (!id3.isNested) {
                                if (std::holds_alternative<double>(id3.val)) {
                                    record.emplace(varName3, std::move((script::structures::ScriptAST::double_(
                                            std::get<double>(id3.val)))));
//                                    record[varName3] = ;
                                } else if (std::holds_alternative<std::string>(id3.val)) {
                                    record.emplace(varName3, std::move(script::structures::ScriptAST::string_(
                                            std::get<std::string>(id3.val))));
                                } else if (std::holds_alternative<size_t>(id3.val)) {
                                    record.emplace(varName3, std::move((script::structures::ScriptAST::integer_(
                                            (long long) std::get<size_t>(id3.val)))));
                                }
                            }
                        }
                        listOfRows.emplace_back(std::move(script::structures::ScriptAST::tuple_(std::move(record))));
                    }
                    script::structures::ScriptAST::globals.emplace(varName2, std::move(script::structures::ScriptAST::array_(std::move(listOfRows))));
                }
            }
#endif
            if (!ptrResult.get()) {
                antlr4::ANTLRInputStream input(data, len);
                scriptLexer lexer(&input);
                antlr4::CommonTokenStream tokens(&lexer);
                scriptParser parser(&tokens);
                ptrResult = getInstance()->visitScript2(parser.script());
            }
//            ptrResult->setDBRecursively(db);
            return ptrResult->toBoolean(doAutoImplode);
        }

//        bool ScriptVisitor::eval2Bool(script::structures::ScriptAST* tmp) {
//            tmp->setContext(this->context, db);
//            return tmp->run(doAutoImplode)->toBoolean();
//        }

        std::any ScriptVisitor::visitSub(scriptParser::SubContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::MinusE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitAtom_array(scriptParser::Atom_arrayContext *context) {
            ArrayList<DPtr<script::structures::ScriptAST>> w;
            if (context) {
                innerBlock(context->expr_block()->inner_block(), w);
            }
            auto result = script::structures::ScriptAST::array_(std::move(w));
            return result;
        }

        std::any ScriptVisitor::visitSelect(scriptParser::SelectContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::FilterE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitMult(scriptParser::MultContext *context) {

            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::MulE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitLt(scriptParser::LtContext *context) {

            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::LtE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitSubstring(scriptParser::SubstringContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->cp()->term(0)));
            auto mx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->cp()->term(1)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::terop_(this->context, script::structures::t::SubElementsE, std::move(lx), std::move(mx), std::move(rx));

            return result;
        }

        std::any ScriptVisitor::visitRemove(scriptParser::RemoveContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::RemoveE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitPut(scriptParser::PutContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->cp()->term(0)));
            auto mx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->cp()->term(1)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::terop_(this->context, script::structures::t::PutE, std::move(lx), std::move(mx), std::move(rx));
            return result;
        }

        std::any ScriptVisitor::visitDiv(scriptParser::DivContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::DivE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitParen(scriptParser::ParenContext *context) {
            return visit(context->expr());
        }

        std::any ScriptVisitor::visitNot(scriptParser::NotContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::NotE, std::move(lx));
            
            return result;
        }

        std::any ScriptVisitor::visitGeq(scriptParser::GeqContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::GEqE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitAnd(scriptParser::AndContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::AndE, std::move(lx), std::move(rx));
            
            return result;
        }


        std::any ScriptVisitor::visitFunction(scriptParser::FunctionContext *context) {
            auto f = std::make_shared<script::structures::Funzione>(this->context, context->VARNAME()->getText());
            f->addExpressios(std::move(std::any_cast<ArrayList<DPtr<script::structures::ScriptAST>>>(visit(context->expr_block()))));
            return script::structures::ScriptAST::function_(std::move(f));
        }

        std::any ScriptVisitor::visitLeq(scriptParser::LeqContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::LEqE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitNeq(scriptParser::NeqContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::NeqE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitMap(scriptParser::MapContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::MapE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitAdd(scriptParser::AddContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::AddE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitOr(scriptParser::OrContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::OrE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitImply(scriptParser::ImplyContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ImplyE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitApply(scriptParser::ApplyContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ApplyE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitVar(scriptParser::VarContext *context) {
            auto result = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()))->var();
            
            return result;
        }

        std::any ScriptVisitor::visitAtom_bool(scriptParser::Atom_boolContext *context) {
            if (context) {
                auto s = context->BOOL()->getSymbol()->getText();
                if (s == "tt")
                    return script::structures::ScriptAST::true_();
                else if (s == "ff")
                    return script::structures::ScriptAST::false_();
                std::cerr << "ERROR on bool: " << s << std::endl;
            }
            return script::structures::ScriptAST::false_();
        }

        std::any ScriptVisitor::visitConcat(scriptParser::ConcatContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ConcatE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitEq(scriptParser::EqContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::EqE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitGt(scriptParser::GtContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::GtE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitContains(scriptParser::ContainsContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ContainsE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitEval(scriptParser::EvalContext *context) {
            auto expr = visit(context->expr());
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(expr);
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::EvalE, std::move(lx));

            return {ptr};
        }

        std::any ScriptVisitor::visitAtom_number(scriptParser::Atom_numberContext *context) {
            std::string val = context->NUMBER()->getSymbol()->getText();
            if (val.contains("e") || val.contains(".")) {
                return {script::structures::ScriptAST::double_(std::stod(val))};
            } else {
                return {script::structures::ScriptAST::integer_(std::stoll(val))};
            }
        }

        std::any ScriptVisitor::visitAt(scriptParser::AtContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return {script::structures::ScriptAST::binop_(this->context, script::structures::t::AtE, std::move(lx), std::move(rx))};
        }

        std::any ScriptVisitor::visitVariable(scriptParser::VariableContext *context) {
            std::string text = "x";
            if (context) {
                text = context->VARNAME()->getText();
            }
            return {script::structures::ScriptAST::variable_(this->context, text)};
        }

        std::any ScriptVisitor::visitAppend(scriptParser::AppendContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return {script::structures::ScriptAST::binop_(this->context, script::structures::t::AppendE, std::move(lx), std::move(rx))};
        }

        std::any ScriptVisitor::visitIfte(scriptParser::IfteContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->cp()->term(0)));
            auto M = visit(context->cp()->term(1));
            auto mx = std::any_cast<DPtr<script::structures::ScriptAST>>(M);
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return script::structures::ScriptAST::terop_(this->context, script::structures::t::IfteE, std::move(lx), std::move(mx), std::move(rx));
        }


        std::any ScriptVisitor::visitAtom_string(scriptParser::Atom_stringContext *context) {
            std::string result;
            if (context) {
                result = context->EscapedString()->getSymbol()->getText();
                result = result.substr(1, result.size()-2);
                result = yaucl::strings::replace_all(result, "\\\"", "\"");
            }
            return {script::structures::ScriptAST::string_(result)};
        }

        std::any ScriptVisitor::visitAssign(scriptParser::AssignContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return {script::structures::ScriptAST::assignment_(this->context, std::move(lx), std::move(rx))};
        }

        ScriptVisitor::ScriptVisitor() {
            context = std::make_shared<std::unordered_map<std::string, DPtr<script::structures::ScriptAST>>>();
        }

        std::any ScriptVisitor::visitVarphi(scriptParser::VarphiContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::VarPhiX, std::move(lx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitEll(scriptParser::EllContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::EllX, std::move(lx));
            return {ptr};
        }

        std::any ScriptVisitor::visitPhi(scriptParser::PhiContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::PhiX, std::move(lx), std::move(rx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitXi(scriptParser::XiContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::XiX, std::move(lx));
            return {ptr};
        }

        std::any ScriptVisitor::visitMod(scriptParser::ModContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::ModE, std::move(lx), std::move(rx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitFlat(scriptParser::FlatContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::FlatE, std::move(lx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitSelfcross(scriptParser::SelfcrossContext *context) {
            auto V = visit(context->operand());
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(V);
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::SelfCrossE, std::move(lx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitSelfzip(scriptParser::SelfzipContext *context) {
            auto V = visit(context->operand());
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(V);
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::SelfZipE, std::move(lx));
            return {ptr};
        }

//        std::any ScriptVisitor::visitInvoke(scriptParser::InvokeContext *context) {
//            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
//            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
//            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::InvokeE, std::move(lx), std::move(rx));
//            return result;
//        }

        std::any ScriptVisitor::visitInj(scriptParser::InjContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::InjE, std::move(lx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitCross(scriptParser::CrossContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::CrossE, std::move(lx), std::move(rx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitAbs(scriptParser::AbsContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::AbsE, std::move(lx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitRfold(scriptParser::RfoldContext *context) {

            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->cp()->term(0)));
            auto mx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->cp()->term(1)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return script::structures::ScriptAST::terop_(this->context, script::structures::t::RFoldE, std::move(lx), std::move(mx), std::move(rx));
        }

        std::any ScriptVisitor::visitLfold(scriptParser::LfoldContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->cp()->term(0)));
            auto M = visit(context->cp()->term(1));
            auto mx = std::any_cast<DPtr<script::structures::ScriptAST>>(M);
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return script::structures::ScriptAST::terop_(this->context, script::structures::t::LFoldE, std::move(lx), std::move(mx), std::move(rx));
        }

        std::any ScriptVisitor::visitFilter(scriptParser::FilterContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::ModE, std::move(lx), std::move(rx));
           
            return {ptr};
        }



//        DPtr<script::structures::ScriptAST> ScriptVisitor::eval2(
//                DPtr<script::structures::ScriptAST>& ptrResult,
//                                 const std::vector<std::string>& schema,
//                                 const std::vector<value>& nestedRow) {
//
//            if ((!ptrResult.get())) {
//                return {nullptr};
//            }
////            std::unordered_map<std::string, DPtr<script::structures::ScriptAST>> contexto;
//
//            ScriptVisitor ptr;
//            // Setting up the environment variables from the record
//            for (size_t i = 0; i<std::min(schema.size(), nestedRow.size()); i++) {
//                const std::string& varName2 = schema.at(i);
//                const auto& id = nestedRow.at(i);
//                if (!id.isNested) {
//                    if (std::holds_alternative<double>(id.val)) {
//                        ptr.context->insert(std::make_pair(varName2, script::structures::ScriptAST::double_(std::get<double>(id.val))));
//                    } else if (std::holds_alternative<std::string>(id.val)) {
//                        ptr.context->insert(std::make_pair(varName2, script::structures::ScriptAST::string_(std::get<std::string>(id.val))));
//                    } else if (std::holds_alternative<size_t>(id.val)) {
//                        ptr.context->insert(std::make_pair(varName2, script::structures::ScriptAST::integer_((long long)std::get<size_t>(id.val))));
//                    } else if (std::holds_alternative<bool>(id.val)) {
//                        if (std::get<bool>(id.val))
//                            ptr.context->insert(std::make_pair(varName2, script::structures::ScriptAST::true_()));
//                        else
//                            ptr.context->insert(std::make_pair(varName2, script::structures::ScriptAST::false_()));
//                    }
//                } else {
//                    ArrayList<DPtr<script::structures::ScriptAST>> listOfRows;
//                    for (size_t k = 0; k<id.table.datum.size(); k++) {
//                        StringMap<DPtr<script::structures::ScriptAST>> record;
//                        for (size_t j = 0; j<std::min(id.table.Schema.size(), id.table.datum.size()); j++) {
//                            const std::string& varName3 = id.table.Schema.at(j);
//                            const auto& id3 = id.table.datum.at(k).at(j);
//                            if (!id3.isNested) {
//                                if (std::holds_alternative<double>(id3.val)) {
//                                    record[varName3] = script::structures::ScriptAST::double_(std::get<double>(id3.val));
//                                } else if (std::holds_alternative<std::string>(id.val)) {
//                                    record[varName3] = (script::structures::ScriptAST::string_(std::get<std::string>(id3.val)));
//                                } else if (std::holds_alternative<size_t>(id.val)) {
//                                    record[varName3] = ((script::structures::ScriptAST::integer_((long long)std::get<size_t>(id3.val))));
//                                } else if (std::holds_alternative<bool>(id3.val)) {
//                                    if (std::get<bool>(id3.val))
//                                        record[varName3] = (( script::structures::ScriptAST::true_()));
//                                    else
//                                        record[varName3] = ((script::structures::ScriptAST::false_()));
//                                }
//                            }
//                        }
//                        listOfRows.emplace_back(script::structures::ScriptAST::tuple_(std::move(record)));
//                    }
//                    ptr.context->insert(std::make_pair(varName2, script::structures::ScriptAST::array_(std::move(listOfRows))));
//                }
//            }
////            ptr.context = std::move(contexto);
////            ptrResult->setOptGammaRecursively(std::move(contexto));
////            return true;
////            auto result =ptr.evalExpr(ptrResult.get());
//            return ptr.evalExpr(ptrResult.get());
//        }

        DPtr<script::structures::ScriptAST> ScriptVisitor::eval(const char* data,size_t len,size_t patt,
                                                                DPtr<script::structures::ScriptAST>& ptrResult,
                                 const std::vector<std::string>& schema,
                                 const std::vector<value>& nestedRow) {
            script::structures::ScriptAST::idxers->current_template =patt;
//            script::structures::ScriptAST::idxers->map.clear(); // Doing this all the times makes it successful, but also slows down the computation.
            script::structures::ScriptAST::idxers->attemptInitialise(patt, &schema).initialize(&nestedRow);
            script::structures::ScriptAST::globals.clear();
//            ScriptVisitor ptr;
#if 1
//             Setting up the environment variables from the record
            for (size_t i = 0; i<std::min(schema.size(), nestedRow.size()); i++) {
                const std::string& varName2 = schema.at(i);
                const auto& id = nestedRow.at(i);
                if (id.isNested) {
//                    if (std::holds_alternative<double>(id.val)) {
//                        script::structures::ScriptAST::globals.emplace(varName2, std::move(script::structures::ScriptAST::double_(std::get<double>(id.val))));
//                    } else if (std::holds_alternative<std::string>(id.val)) {
//                        script::structures::ScriptAST::globals.emplace(varName2, std::move(script::structures::ScriptAST::string_(std::get<std::string>(id.val))));
//                    } else if (std::holds_alternative<size_t>(id.val)) {
//                        script::structures::ScriptAST::globals.emplace(varName2, std::move(script::structures::ScriptAST::integer_((long long)std::get<size_t>(id.val))));
//                    }
//                } else
//                {
                    ArrayList<DPtr<script::structures::ScriptAST>> listOfRows;
                    for (size_t k = 0; k<id.table.datum.size(); k++) {
                        StringMap<DPtr<script::structures::ScriptAST>> record;
                        for (size_t j = 0; j<id.table.Schema.size(); j++) {
                            const std::string& varName3 = id.table.Schema.at(j);
                            const auto& id3 = id.table.datum.at(k).at(j);
                            if (std::holds_alternative<double>(id3.val)) {
                                record.emplace(varName3, std::move((script::structures::ScriptAST::double_(std::get<double>(id3.val)))));
                            } else if (std::holds_alternative<std::string>(id3.val)) {
                                record.emplace(varName3, std::move (script::structures::ScriptAST::string_(std::get<std::string>(id3.val))));
                            } else if (std::holds_alternative<size_t>(id3.val)) {
                                record.emplace(varName3, std::move( ((script::structures::ScriptAST::integer_((long long)std::get<size_t>(id3.val))))));
                            }
                        }
                        listOfRows.emplace_back(std::move(script::structures::ScriptAST::tuple_(std::move(record))));
                    }
                    script::structures::ScriptAST::globals.emplace(varName2, std::move(script::structures::ScriptAST::array_(std::move(listOfRows))));
                }
            }
#endif
            if (!ptrResult.get()) {
                antlr4::ANTLRInputStream input(data,len);
                scriptLexer lexer(&input);
                antlr4::CommonTokenStream tokens(&lexer);
                scriptParser parser(&tokens);
                ptrResult = getInstance()->visitScript2(parser.script());
            }
            return ptrResult->run(doAutoImplode);
        }

        DPtr<script::structures::ScriptAST> ScriptVisitor::eval3(const char* data, size_t len,
                                                                 DPtr<script::structures::ScriptAST>& ptrResult,
                                                                DPtr<std::unordered_map<std::string, DPtr<script::structures::ScriptAST>>> context) {
            ScriptVisitor ptr;
            ptr.context = std::move(context);
            if ((!ptrResult.get())) {
                antlr4::ANTLRInputStream input(data, len);
                scriptLexer lexer(&input);
                antlr4::CommonTokenStream tokens(&lexer);
                scriptParser parser(&tokens);
                ptrResult = ptr.visitScript2(parser.script());
            }
            return ptrResult->run(doAutoImplode);
        }

        std::any ScriptVisitor::visitCos(scriptParser::CosContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::CosE, std::move(lx));
            
            return result;
        }

        std::any ScriptVisitor::visitTan(scriptParser::TanContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::TanE, std::move(lx));
            
            return result;
        }

        std::any ScriptVisitor::visitCeil(scriptParser::CeilContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::CeilE, std::move(lx));
            return result;
        }

        std::any ScriptVisitor::visitLog(scriptParser::LogContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::LogE, std::move(lx), std::move(rx));
            return {ptr};
        }

        std::any ScriptVisitor::visitPow(scriptParser::PowContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::ExpE, std::move(lx), std::move(rx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitSin(scriptParser::SinContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::SinE, std::move(lx));
            
            return result;
        }

        std::any ScriptVisitor::visitFloor(scriptParser::FloorContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::FloorE, std::move(lx));
            return result;
        }

        std::any ScriptVisitor::visitType_bool(scriptParser::Type_boolContext *context) {
            return {script::structures::ScriptAST::boolean_T()};
        }

        std::any ScriptVisitor::visitType_double(scriptParser::Type_doubleContext *context) {
            return {script::structures::ScriptAST::double_T()};
        }

        std::any ScriptVisitor::visitType_int(scriptParser::Type_intContext *context) {
            return {script::structures::ScriptAST::integer_T()};
        }

        std::any ScriptVisitor::visitType_string(scriptParser::Type_stringContext *context) {
            return {script::structures::ScriptAST::string_T()};
        }

        std::any ScriptVisitor::visitType_list(scriptParser::Type_listContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::ArrayOfT, std::move(lx));
            return result;
        }

//        std::any ScriptVisitor::visitTuple_pair(scriptParser::Tuple_pairContext *context) {
//            std::pair<std::string, DPtr<script::structures::ScriptAST>> cp;
//            cp.second = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
//            cp.first = context->EscapedString()->getSymbol()->getText();
//            cp.first = cp.first.substr(1, cp.first.size()-2);
//            cp.first = yaucl::strings::replace_all(cp.first, "\\\"", "\"");
//            return {cp};
//        }

        std::any ScriptVisitor::visitObj(scriptParser::ObjContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::ObjX, std::move(lx));
            return {ptr};
        }

        std::any ScriptVisitor::visitEnsure(scriptParser::EnsureContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::AssertE, std::move(lx));
            return result;
        }

        std::any ScriptVisitor::visitKind(scriptParser::KindContext *context) {
            return {script::structures::ScriptAST::star_T()};
        }

        std::any ScriptVisitor::visitType_tuple(scriptParser::Type_tupleContext *context) {
            StringMap<DPtr<script::structures::ScriptAST>> map;
            if (context) {
                inTuplePair(context->in_tuple_pair(), map);
            }
            return {script::structures::ScriptAST::tuple_type_(std::move(map))};
//            StringMap<DPtr<script::structures::ScriptAST>> map;
//            if (context) {
//                for (const auto& ref : context->tuple_pair()) {
//                    auto cp = std::any_cast<std::pair<std::string, DPtr<script::structures::ScriptAST>>>(
//                            visitTuple_pair(ref));
//                    map[cp.first] = cp.second;
//                }
//            }
//            return {script::structures::ScriptAST::tuple_type_(std::move(map))};
        }

        std::any ScriptVisitor::visitSigma_type(scriptParser::Sigma_typeContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::SigmaT, std::move(lx), std::move(rx));
            return {ptr};
        }

        std::any ScriptVisitor::visitTypeof(scriptParser::TypeofContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->operand()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::TypeOf, std::move(lx));
            return result;
        }


        void ScriptVisitor::inTuplePair(scriptParser::In_tuple_pairContext* c, StringMap<DPtr<script::structures::ScriptAST>>& map) {
//            cp.second = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(c->expr()));
            auto first = c->EscapedString()->getSymbol()->getText();
            first = first.substr(1, first.size()-2);
            first = yaucl::strings::replace_all(first, "\\\"", "\"");
            map.emplace(first, std::move(std::any_cast<DPtr<script::structures::ScriptAST>>(visit(c->expr()))));
            if (c) {
                inTuplePair(c->in_tuple_pair(), map);
            }
        }

        std::any ScriptVisitor::visitAtom_tuple(scriptParser::Atom_tupleContext *context) {
            StringMap<DPtr<script::structures::ScriptAST>> map;
            if (context) {
                inTuplePair(context->in_tuple_pair(), map);
            }
            return {script::structures::ScriptAST::tuple_(std::move(map))};
        }

        std::any ScriptVisitor::visitSubtype_of(scriptParser::Subtype_ofContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return {script::structures::ScriptAST::binop_(this->context, script::structures::t::SubtypeOfE, std::move(lx), std::move(rx))};
        }

        std::any ScriptVisitor::visitType_or(scriptParser::Type_orContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ORT, std::move(lx), std::move(rx));

            return result;
        }

        std::any ScriptVisitor::visitType_and(scriptParser::Type_andContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ANDT, std::move(lx), std::move(rx));

            return result;
        }

        std::any ScriptVisitor::visitProject(scriptParser::ProjectContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return {script::structures::ScriptAST::binop_(this->context, script::structures::t::ProjectE, std::move(lx), std::move(rx))};
        }

        std::any ScriptVisitor::visitType_label(scriptParser::Type_labelContext *context) {
            auto result = context->EscapedString()->getSymbol()->getText();
            result = result.substr(1, result.size()-2);
            result = yaucl::strings::replace_all(result, "\\\"", "\"");
            return {script::structures::ScriptAST::label_T_(result)};
        }

        std::any ScriptVisitor::visitEnforce(scriptParser::EnforceContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return {script::structures::ScriptAST::binop_(this->context, script::structures::t::ENFORCET, std::move(lx), std::move(rx))};
        }

        std::any ScriptVisitor::visitType_lex(scriptParser::Type_lexContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return {script::structures::ScriptAST::binop_(this->context, script::structures::t::ObjTT, std::move(lx), std::move(rx))};
        }

        std::any ScriptVisitor::visitCoerce(scriptParser::CoerceContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->term()));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            return {script::structures::ScriptAST::binop_(this->context, script::structures::t::CoerceE, std::move(lx), std::move(rx))};
        }

        size_t ScriptVisitor::isEnforced(const DPtr<script::structures::ScriptAST> &left, const DPtr<script::structures::ScriptAST> &right) {
            size_t l = typecaster.getId(left->toString());
            if (l == -1) return -1;
            size_t r = typecaster.getId(right->toString());
            if (r == -1) return -1;
            const auto& outs = typecaster.g.nodes.at(l);
//            bool found = false;
            for (size_t f : outs) {
                if (typecaster.g.edge_ids.at(f).second == r) {
                    return f;
                }
            }
            return -1;
        }

        std::optional<std::function<DPtr<script::structures::ScriptAST>(DPtr<script::structures::ScriptAST>&&)>> ScriptVisitor::isEnforcedWithCast(const DPtr<script::structures::ScriptAST> &left, const DPtr<script::structures::ScriptAST> &right) {
            size_t l = typecaster.getId(left->toString());
            size_t r = typecaster.getId(right->toString());
            const auto& outs = typecaster.g.nodes.at(l);
            for (size_t f : outs) {
                if (typecaster.g.edge_ids.at(f).second == r) {
                    return {typecaster.getEdgeLabel(f)};
                }
            }
            return {};
        }

        std::any ScriptVisitor::visitType_bot(scriptParser::Type_botContext *context) {
            return {script::structures::ScriptAST::bot_t_()};
        }

        std::any ScriptVisitor::visitNull(scriptParser::NullContext *context) {
            return {script::structures::ScriptAST::null_()};
        }

        std::any ScriptVisitor::visitType_any(scriptParser::Type_anyContext *context) {
            return {script::structures::ScriptAST::any_T()};
        }

        void ScriptVisitor::bindGSM(closure *gsm) {
            typecaster.clear();
            db = gsm;
            script::structures::ScriptAST::setDBRecursively(db);
        }

        void ScriptVisitor::innerBlock(scriptParser::Inner_blockContext* b, ArrayList<DPtr<script::structures::ScriptAST>>& v) {
            auto V = visit(b->expr());
            v.emplace_back(std::move(std::any_cast<DPtr<script::structures::ScriptAST>>(V)));
            if (b->inner_block()) {
                innerBlock(b->inner_block(), v);
            }
        }

        std::any ScriptVisitor::visitExpr_block(scriptParser::Expr_blockContext *context) {
            if (context) {
                ArrayList<DPtr<script::structures::ScriptAST>> v;
                innerBlock(context->inner_block(), v);
                return v;
            }
            return {};
        }

        std::any ScriptVisitor::visitInner_block(scriptParser::Inner_blockContext *context) {
            throw std::runtime_error("UNEXPECTED METHOD;");
        }

        std::any ScriptVisitor::visitIn_tuple_pair(scriptParser::In_tuple_pairContext *context) {
            throw std::runtime_error("UNEXPECTED METHOD;");
        }

        std::any ScriptVisitor::visitTerm_operand(scriptParser::Term_operandContext *context) {
            if (context) {
                return visit(context->operand());
            }
            return {};
        }

        std::any ScriptVisitor::visitExprterm(scriptParser::ExprtermContext *context) {
            if (context) {
                return visit(context->term());
            }
            return {};
        }

        std::any ScriptVisitor::visitCp(scriptParser::CpContext *context) {
            return {};
        }

    } // script
} // compiler