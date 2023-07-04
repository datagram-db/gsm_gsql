//
// Created by giacomo on 10/04/23.
//

#include <gsql_gsm/script_1/ScriptVisitor.h>
#include <gsql_gsm/script_1/ScriptAST.h>
#include <gsql_gsm/script_1/Funzione.h>
#include "scriptLexer.h"

namespace script {
    namespace compiler {
        gsm_inmemory_db* ScriptVisitor::db = nullptr;

        std::any ScriptVisitor::visitScript(scriptParser::ScriptContext *context) {
            auto result = std::make_shared<script::structures::ScriptAST>();
            result->optGamma = this->context;
            result->db = db;
            for (const auto& x : context->expr()) {
                auto tmp = any_cast<DPtr<script::structures::ScriptAST>>(visit(x));
                tmp->setContext(result->optGamma, result->db);
                result = tmp->run();
            }
            return result;
        }

        std::any ScriptVisitor::visitSub(scriptParser::SubContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::MinusE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitAtom_array(scriptParser::Atom_arrayContext *context) {
            std::vector<DPtr<script::structures::ScriptAST>> w;
            if (context) {
                for (const auto& ref : context->expr()) {
                    w.emplace_back(std::any_cast<DPtr<script::structures::ScriptAST>>(visit(ref)));
                }
            }
            auto result = script::structures::ScriptAST::array_(std::move(w));
            
            return result;
        }

        std::any ScriptVisitor::visitSelect(scriptParser::SelectContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::FilterE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitMult(scriptParser::MultContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::MulE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitLt(scriptParser::LtContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::LtE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitSubstring(scriptParser::SubstringContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto mx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(2)));
            auto result= script::structures::ScriptAST::terop_(this->context, script::structures::t::SubElementsE, std::move(lx), std::move(mx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitRemove(scriptParser::RemoveContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::RemoveE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitPut(scriptParser::PutContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto mx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(2)));
            auto result= script::structures::ScriptAST::terop_(this->context, script::structures::t::PutE, std::move(lx), std::move(mx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitDiv(scriptParser::DivContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::DivE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitParen(scriptParser::ParenContext *context) {
            return visit(context->expr());
        }

        std::any ScriptVisitor::visitNot(scriptParser::NotContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::NotE, std::move(lx));
            
            return result;
        }

        std::any ScriptVisitor::visitGeq(scriptParser::GeqContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::GEqE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitAnd(scriptParser::AndContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::AndE, std::move(lx), std::move(rx));
            
            return result;
        }


        std::any ScriptVisitor::visitFunction(scriptParser::FunctionContext *context) {
            auto f = std::make_shared<script::structures::Funzione>(this->context, context->VARNAME()->getText());
            for (const auto& child : context->expr()) {
                f->addExpression(std::any_cast<DPtr<script::structures::ScriptAST>>(visit(child)));
            }
            auto result =  script::structures::ScriptAST::function_(std::move(f));
            
            return result;
        }

        std::any ScriptVisitor::visitLeq(scriptParser::LeqContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::LEqE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitNeq(scriptParser::NeqContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::NeqE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitMap(scriptParser::MapContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::MapE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitAdd(scriptParser::AddContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::AddE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitOr(scriptParser::OrContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::OrE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitImply(scriptParser::ImplyContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ImplyE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitApply(scriptParser::ApplyContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
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
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ConcatE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitEq(scriptParser::EqContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::EqE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitGt(scriptParser::GtContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::GtE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitContains(scriptParser::ContainsContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ContainsE, std::move(lx), std::move(rx));
            
            return result;
        }

        std::any ScriptVisitor::visitEval(scriptParser::EvalContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
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
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
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
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            return {script::structures::ScriptAST::binop_(this->context, script::structures::t::AppendE, std::move(lx), std::move(rx))};
        }

        std::any ScriptVisitor::visitIfte(scriptParser::IfteContext *context) {
            return std::any();
        }

#include "yaucl/strings/string_utils.h"

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
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            return {script::structures::ScriptAST::assignment_(this->context, std::move(lx), std::move(rx))};
        }

        ScriptVisitor::ScriptVisitor() {
            context = std::make_shared<std::unordered_map<std::string, DPtr<script::structures::ScriptAST>>>();
        }

        std::any ScriptVisitor::visitVarphi(scriptParser::VarphiContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::VarPhiX, std::move(lx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitEll(scriptParser::EllContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::EllX, std::move(lx));
            return {ptr};
        }

        std::any ScriptVisitor::visitPhi(scriptParser::PhiContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::PhiX, std::move(lx), std::move(rx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitXi(scriptParser::XiContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::XiX, std::move(lx));
            return {ptr};
        }

        std::any ScriptVisitor::visitMod(scriptParser::ModContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::ModE, std::move(lx), std::move(rx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitFlat(scriptParser::FlatContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::FlatE, std::move(lx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitSelfcross(scriptParser::SelfcrossContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::SelfCrossE, std::move(lx));
           
            return {ptr};
        }

//        std::any ScriptVisitor::visitInvoke(scriptParser::InvokeContext *context) {
//            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
//            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
//            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::InvokeE, std::move(lx), std::move(rx));
//            return result;
//        }

        std::any ScriptVisitor::visitInj(scriptParser::InjContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::InjE, std::move(lx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitCross(scriptParser::CrossContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::CrossE, std::move(lx), std::move(rx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitAbs(scriptParser::AbsContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::AbsE, std::move(lx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitRfold(scriptParser::RfoldContext *context) {

            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto mx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(2)));
            return script::structures::ScriptAST::terop_(this->context, script::structures::t::RFoldE, std::move(lx), std::move(mx), std::move(rx));
        }

        std::any ScriptVisitor::visitLfold(scriptParser::LfoldContext *context) {

            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto mx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(2)));
            return script::structures::ScriptAST::terop_(this->context, script::structures::t::LFoldE, std::move(lx), std::move(mx), std::move(rx));
        }

        std::any ScriptVisitor::visitFilter(scriptParser::FilterContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::ModE, std::move(lx), std::move(rx));
           
            return {ptr};
        }

        DPtr<script::structures::ScriptAST> ScriptVisitor::eval(std::istream &is) {
            antlr4::ANTLRInputStream input(is);
            scriptLexer lexer(&input);
            antlr4::CommonTokenStream tokens(&lexer);
            scriptParser parser(&tokens);
            ScriptVisitor ptr;
            return std::any_cast<DPtr<script::structures::ScriptAST>>(ptr.visit(parser.script()));
        }

        std::any ScriptVisitor::visitCos(scriptParser::CosContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::CosE, std::move(lx));
            
            return result;
        }

        std::any ScriptVisitor::visitTan(scriptParser::TanContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::TanE, std::move(lx));
            
            return result;
        }

        std::any ScriptVisitor::visitCeil(scriptParser::CeilContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::CeilE, std::move(lx));
            return result;
        }

        std::any ScriptVisitor::visitLog(scriptParser::LogContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::LogE, std::move(lx), std::move(rx));
            return {ptr};
        }

        std::any ScriptVisitor::visitPow(scriptParser::PowContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::ExpE, std::move(lx), std::move(rx));
           
            return {ptr};
        }

        std::any ScriptVisitor::visitSin(scriptParser::SinContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
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
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::ArrayOfT, std::move(lx));
            return result;
        }

        std::any ScriptVisitor::visitTuple_pair(scriptParser::Tuple_pairContext *context) {
            std::pair<std::string, DPtr<script::structures::ScriptAST>> cp;
            cp.second = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            cp.first = context->EscapedString()->getSymbol()->getText();
            cp.first = cp.first.substr(1, cp.first.size()-2);
            cp.first = yaucl::strings::replace_all(cp.first, "\\\"", "\"");
            return {cp};
        }

        std::any ScriptVisitor::visitObj(scriptParser::ObjContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto ptr = script::structures::ScriptAST::unop_(this->context, script::structures::t::ObjX, std::move(lx));
            return {ptr};
        }

        std::any ScriptVisitor::visitEnsure(scriptParser::EnsureContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::AssertE, std::move(lx));
            return result;
        }

        std::any ScriptVisitor::visitKind(scriptParser::KindContext *context) {
            return {script::structures::ScriptAST::star_T()};
        }

        std::any ScriptVisitor::visitType_tuple(scriptParser::Type_tupleContext *context) {
            StringMap<DPtr<script::structures::ScriptAST>> map;
            if (context) {
                for (const auto& ref : context->tuple_pair()) {
                    auto cp = std::any_cast<std::pair<std::string, DPtr<script::structures::ScriptAST>>>(
                            visitTuple_pair(ref));
                    map[cp.first] = cp.second;
                }
            }
            return {script::structures::ScriptAST::tuple_type_(std::move(map))};
        }

        std::any ScriptVisitor::visitSigma_type(scriptParser::Sigma_typeContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto ptr = script::structures::ScriptAST::binop_(this->context, structures::SigmaT, std::move(lx), std::move(rx));
            return {ptr};
        }

        std::any ScriptVisitor::visitTypeof(scriptParser::TypeofContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr()));
            auto result= script::structures::ScriptAST::unop_(this->context, script::structures::t::TypeOf, std::move(lx));
            return result;
        }

        std::any ScriptVisitor::visitAtom_tuple(scriptParser::Atom_tupleContext *context) {
            StringMap<DPtr<script::structures::ScriptAST>> map;
            if (context) {
                for (const auto& ref : context->tuple_pair()) {
                    auto cp = std::any_cast<std::pair<std::string, DPtr<script::structures::ScriptAST>>>(
                            visitTuple_pair(ref));
                    map[cp.first] = cp.second;
                }
            }
            return {script::structures::ScriptAST::tuple_(std::move(map))};
        }

        std::any ScriptVisitor::visitSubtype_of(scriptParser::Subtype_ofContext *context) {
            throw std::runtime_error("ERROR: FUTURE WORK!");
        }

        std::any ScriptVisitor::visitType_or(scriptParser::Type_orContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ORT, std::move(lx), std::move(rx));

            return result;
        }

        std::any ScriptVisitor::visitType_and(scriptParser::Type_andContext *context) {
            auto lx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(0)));
            auto rx = std::any_cast<DPtr<script::structures::ScriptAST>>(visit(context->expr(1)));
            auto result = script::structures::ScriptAST::binop_(this->context, script::structures::t::ANDT, std::move(lx), std::move(rx));

            return result;
        }

//        std::any ScriptVisitor::visitStar(scriptParser::StarContext *context) {
//            return std::any();
//        }

    } // script
} // compiler