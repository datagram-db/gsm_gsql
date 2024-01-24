//
// Created by giacomo on 10/04/23.
//

#ifndef GSM_GSQL_SCRIPTVISITOR_H
#define GSM_GSQL_SCRIPTVISITOR_H


class closure;
#include "yaucl/graphs/NodeLabelBijectionGraph.h"
#include "database/utility.h"
#include <scriptv2/scriptVisitor.h>
#include <scriptv2/java_types.h>
#include <optional>

namespace script {
    namespace structures {
        struct ScriptAST;
    }
    namespace compiler {

        struct ScriptVisitor : public scriptVisitor {
            static bool doAutoImplode;
            static ScriptVisitor* instance;
            static NodeLabelBijectionGraph<std::string,std::function<DPtr<script::structures::ScriptAST>(DPtr<script::structures::ScriptAST>&&)>> typecaster;
            DPtr<std::unordered_map<std::string, DPtr<script::structures::ScriptAST>>> context;
            static closure* db; // WARNING: THIS CANNOT BE USED IN CONCURRENT SETTINGS WHERE MULTIPLE DATABASES ARE USED!
            ScriptVisitor();
            static void bindGSM(closure* gsm);

            static ScriptVisitor* getInstance() {
                if (!instance)
                    instance = new ScriptVisitor();
                return instance;
            }


//            bool eval2Bool(script::structures::ScriptAST* tmp);
//            static DPtr<script::structures::ScriptAST> eval(std::istream &is,
//                             scriptParser::ScriptContext** ptrResult,
//                                 const std::vector<std::string>& schema,
//                                 const std::vector<value>& nestedRow);
//            static DPtr<script::structures::ScriptAST> eval(std::istream& is,
//                             scriptParser::ScriptContext** ptrResult,
//                             DPtr<std::unordered_map<std::string, DPtr<script::structures::ScriptAST>>> context);
            static DPtr<script::structures::ScriptAST> eval(const char* str, size_t strlen,size_t patt,
                                                            DPtr<script::structures::ScriptAST>& ptrResult,
            const std::vector<std::string>& schema,
            const std::vector<value>& nestedRow);

            static bool evalBool(const char* data,size_t len,size_t patt,
                                         DPtr<script::structures::ScriptAST>& ptrResult,
                                         const std::vector<std::string>& schema,
                                         const std::vector<value>& nestedRow);
            static DPtr<script::structures::ScriptAST> eval3(const char* str, size_t strlen,
                                                             DPtr<script::structures::ScriptAST>& ptrResult,
            DPtr<std::unordered_map<std::string, DPtr<script::structures::ScriptAST>>> context);
//            static DPtr<script::structures::ScriptAST> eval2(
//                    DPtr<script::structures::ScriptAST>& ptrResult,
//                                     const std::vector<std::string>& schema,
//                                     const std::vector<value>& nestedRow);

            static size_t isEnforced(const DPtr<script::structures::ScriptAST>& left,
                                   const DPtr<script::structures::ScriptAST>& right);
            static std::optional<std::function<DPtr<script::structures::ScriptAST>(DPtr<script::structures::ScriptAST>&&)>> isEnforcedWithCast(const DPtr<script::structures::ScriptAST>& left,
                                   const DPtr<script::structures::ScriptAST>& right);



            std::any visitScript(scriptParser::ScriptContext *context) override;
            DPtr<script::structures::ScriptAST> visitScript2(scriptParser::ScriptContext *context);
//            DPtr<script::structures::ScriptAST> evalExpr(script::structures::ScriptAST* tmp);
            std::any visitSub(scriptParser::SubContext *context) override;
            std::any visitAtom_array(scriptParser::Atom_arrayContext *context) override;
            std::any visitSelect(scriptParser::SelectContext *context) override;
            std::any visitMult(scriptParser::MultContext *context) override;
            std::any visitLt(scriptParser::LtContext *context) override;
            std::any visitSubstring(scriptParser::SubstringContext *context) override;
            std::any visitRemove(scriptParser::RemoveContext *context) override;
            std::any visitPut(scriptParser::PutContext *context) override;
            std::any visitDiv(scriptParser::DivContext *context) override;
            std::any visitParen(scriptParser::ParenContext *context) override;
            std::any visitNot(scriptParser::NotContext *context) override;
            std::any visitGeq(scriptParser::GeqContext *context) override;
            std::any visitAnd(scriptParser::AndContext *context) override;
            std::any visitFunction(scriptParser::FunctionContext *context) override;
            std::any visitLeq(scriptParser::LeqContext *context) override;
            std::any visitNeq(scriptParser::NeqContext *context) override;
            std::any visitMap(scriptParser::MapContext *context) override;
            std::any visitAdd(scriptParser::AddContext *context) override;
            std::any visitOr(scriptParser::OrContext *context) override;
            std::any visitImply(scriptParser::ImplyContext *context) override;
            std::any visitApply(scriptParser::ApplyContext *context) override;
            std::any visitVar(scriptParser::VarContext *context) override;
            std::any visitAtom_bool(scriptParser::Atom_boolContext *context) override;
            std::any visitConcat(scriptParser::ConcatContext *context) override;
            std::any visitEq(scriptParser::EqContext *context) override;
            std::any visitGt(scriptParser::GtContext *context) override;
            std::any visitContains(scriptParser::ContainsContext *context) override;
            std::any visitEval(scriptParser::EvalContext *context) override;
            std::any visitAtom_number(scriptParser::Atom_numberContext *context) override;
            std::any visitAt(scriptParser::AtContext *context) override;
            std::any visitVariable(scriptParser::VariableContext *context) override;
            std::any visitAppend(scriptParser::AppendContext *context) override;
            std::any visitIfte(scriptParser::IfteContext *context) override;
            std::any visitAtom_string(scriptParser::Atom_stringContext *context) override;
            std::any visitAssign(scriptParser::AssignContext *context) override;
            std::any visitVarphi(scriptParser::VarphiContext *context) override;
            std::any visitEll(scriptParser::EllContext *context) override;
            std::any visitPhi(scriptParser::PhiContext *context) override;
            std::any visitXi(scriptParser::XiContext *context) override;
            std::any visitMod(scriptParser::ModContext *context) override;
            std::any visitFlat(scriptParser::FlatContext *context) override;
            std::any visitSelfcross(scriptParser::SelfcrossContext *context) override;
            std::any visitInj(scriptParser::InjContext *context) override;
            std::any visitCross(scriptParser::CrossContext *context) override;
            std::any visitAbs(scriptParser::AbsContext *context) override;
            std::any visitRfold(scriptParser::RfoldContext *context) override;
            std::any visitLfold(scriptParser::LfoldContext *context) override;
            std::any visitFilter(scriptParser::FilterContext *context) override;
            std::any visitCos(scriptParser::CosContext *context) override;
            std::any visitTan(scriptParser::TanContext *context) override;
            std::any visitCeil(scriptParser::CeilContext *context) override;
            std::any visitLog(scriptParser::LogContext *context) override;
            std::any visitPow(scriptParser::PowContext *context) override;
            std::any visitSin(scriptParser::SinContext *context) override;
            std::any visitFloor(scriptParser::FloorContext *context) override;
//            std::any visitTuple_pair(scriptParser::Tuple_pairContext *context) override;
            std::any visitType_bool(scriptParser::Type_boolContext *context) override;
            std::any visitEnsure(scriptParser::EnsureContext *context) override;
            std::any visitKind(scriptParser::KindContext *context) override;
            std::any visitType_tuple(scriptParser::Type_tupleContext *context) override;
            std::any visitSigma_type(scriptParser::Sigma_typeContext *context) override;
            std::any visitType_string(scriptParser::Type_stringContext *context) override;
            std::any visitTypeof(scriptParser::TypeofContext *context) override;
            std::any visitType_int(scriptParser::Type_intContext *context) override;
            std::any visitAtom_tuple(scriptParser::Atom_tupleContext *context) override;
            std::any visitType_double(scriptParser::Type_doubleContext *context) override;
            std::any visitType_list(scriptParser::Type_listContext *context) override;
            std::any visitObj(scriptParser::ObjContext *context) override;
            std::any visitSubtype_of(scriptParser::Subtype_ofContext *context) override;
            std::any visitType_or(scriptParser::Type_orContext *context) override;
            std::any visitType_and(scriptParser::Type_andContext *context) override;
            std::any visitProject(scriptParser::ProjectContext *context) override;
            std::any visitType_label(scriptParser::Type_labelContext *context) override;
            std::any visitEnforce(scriptParser::EnforceContext *context) override;
            std::any visitType_lex(scriptParser::Type_lexContext *context) override;
            std::any visitCoerce(scriptParser::CoerceContext *context) override;
            std::any visitType_bot(scriptParser::Type_botContext *context) override;
            std::any visitNull(scriptParser::NullContext *context) override;
            std::any visitType_any(scriptParser::Type_anyContext *context) override;

            std::any visitExpr_block(scriptParser::Expr_blockContext *context) override;

            void innerBlock(scriptParser::Inner_blockContext*, ArrayList<DPtr<script::structures::ScriptAST>>&);
            void inTuplePair(scriptParser::In_tuple_pairContext*, StringMap<DPtr<script::structures::ScriptAST>>&);
            std::any visitInner_block(scriptParser::Inner_blockContext *context) override;

            std::any visitIn_tuple_pair(scriptParser::In_tuple_pairContext *context) override;

            std::any visitTerm_operand(scriptParser::Term_operandContext *context) override;

            std::any visitExprterm(scriptParser::ExprtermContext *context) override;

            std::any visitCp(scriptParser::CpContext *context) override;
        };

    } // script
} // compiler

#endif //GSM_GSQL_SCRIPTVISITOR_H
