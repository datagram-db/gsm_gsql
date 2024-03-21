
// Generated from antlr4/scriptv2/script.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "scriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by scriptParser.
 */
class  scriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by scriptParser.
   */
    virtual std::any visitScript(scriptParser::ScriptContext *context) = 0;

    virtual std::any visitExpr_block(scriptParser::Expr_blockContext *context) = 0;

    virtual std::any visitInner_block(scriptParser::Inner_blockContext *context) = 0;

    virtual std::any visitIn_tuple_pair(scriptParser::In_tuple_pairContext *context) = 0;

    virtual std::any visitAtom_number(scriptParser::Atom_numberContext *context) = 0;

    virtual std::any visitAtom_bool(scriptParser::Atom_boolContext *context) = 0;

    virtual std::any visitAtom_string(scriptParser::Atom_stringContext *context) = 0;

    virtual std::any visitNull(scriptParser::NullContext *context) = 0;

    virtual std::any visitType_string(scriptParser::Type_stringContext *context) = 0;

    virtual std::any visitType_bool(scriptParser::Type_boolContext *context) = 0;

    virtual std::any visitType_int(scriptParser::Type_intContext *context) = 0;

    virtual std::any visitType_double(scriptParser::Type_doubleContext *context) = 0;

    virtual std::any visitType_any(scriptParser::Type_anyContext *context) = 0;

    virtual std::any visitType_bot(scriptParser::Type_botContext *context) = 0;

    virtual std::any visitParen(scriptParser::ParenContext *context) = 0;

    virtual std::any visitAbs(scriptParser::AbsContext *context) = 0;

    virtual std::any visitVar(scriptParser::VarContext *context) = 0;

    virtual std::any visitEval(scriptParser::EvalContext *context) = 0;

    virtual std::any visitType_tuple(scriptParser::Type_tupleContext *context) = 0;

    virtual std::any visitFloor(scriptParser::FloorContext *context) = 0;

    virtual std::any visitCeil(scriptParser::CeilContext *context) = 0;

    virtual std::any visitAtom_array(scriptParser::Atom_arrayContext *context) = 0;

    virtual std::any visitType_label(scriptParser::Type_labelContext *context) = 0;

    virtual std::any visitKind(scriptParser::KindContext *context) = 0;

    virtual std::any visitVariable(scriptParser::VariableContext *context) = 0;

    virtual std::any visitTerm_operand(scriptParser::Term_operandContext *context) = 0;

    virtual std::any visitNot(scriptParser::NotContext *context) = 0;

    virtual std::any visitType_list(scriptParser::Type_listContext *context) = 0;

    virtual std::any visitSin(scriptParser::SinContext *context) = 0;

    virtual std::any visitCos(scriptParser::CosContext *context) = 0;

    virtual std::any visitTan(scriptParser::TanContext *context) = 0;

    virtual std::any visitEll(scriptParser::EllContext *context) = 0;

    virtual std::any visitXi(scriptParser::XiContext *context) = 0;

    virtual std::any visitInj(scriptParser::InjContext *context) = 0;

    virtual std::any visitObj(scriptParser::ObjContext *context) = 0;

    virtual std::any visitFlat(scriptParser::FlatContext *context) = 0;

    virtual std::any visitSelfcross(scriptParser::SelfcrossContext *context) = 0;

    virtual std::any visitSelfzip(scriptParser::SelfzipContext *context) = 0;

    virtual std::any visitVarphi(scriptParser::VarphiContext *context) = 0;

    virtual std::any visitTypeof(scriptParser::TypeofContext *context) = 0;

    virtual std::any visitEnsure(scriptParser::EnsureContext *context) = 0;

    virtual std::any visitCp(scriptParser::CpContext *context) = 0;

    virtual std::any visitExprterm(scriptParser::ExprtermContext *context) = 0;

    virtual std::any visitAdd(scriptParser::AddContext *context) = 0;

    virtual std::any visitSub(scriptParser::SubContext *context) = 0;

    virtual std::any visitDiv(scriptParser::DivContext *context) = 0;

    virtual std::any visitMod(scriptParser::ModContext *context) = 0;

    virtual std::any visitMult(scriptParser::MultContext *context) = 0;

    virtual std::any visitConcat(scriptParser::ConcatContext *context) = 0;

    virtual std::any visitAppend(scriptParser::AppendContext *context) = 0;

    virtual std::any visitAnd(scriptParser::AndContext *context) = 0;

    virtual std::any visitOr(scriptParser::OrContext *context) = 0;

    virtual std::any visitEq(scriptParser::EqContext *context) = 0;

    virtual std::any visitNeq(scriptParser::NeqContext *context) = 0;

    virtual std::any visitLeq(scriptParser::LeqContext *context) = 0;

    virtual std::any visitGeq(scriptParser::GeqContext *context) = 0;

    virtual std::any visitGt(scriptParser::GtContext *context) = 0;

    virtual std::any visitLt(scriptParser::LtContext *context) = 0;

    virtual std::any visitAssign(scriptParser::AssignContext *context) = 0;

    virtual std::any visitApply(scriptParser::ApplyContext *context) = 0;

    virtual std::any visitImply(scriptParser::ImplyContext *context) = 0;

    virtual std::any visitIfte(scriptParser::IfteContext *context) = 0;

    virtual std::any visitSubstring(scriptParser::SubstringContext *context) = 0;

    virtual std::any visitAt(scriptParser::AtContext *context) = 0;

    virtual std::any visitProject(scriptParser::ProjectContext *context) = 0;

    virtual std::any visitPut(scriptParser::PutContext *context) = 0;

    virtual std::any visitContains(scriptParser::ContainsContext *context) = 0;

    virtual std::any visitRemove(scriptParser::RemoveContext *context) = 0;

    virtual std::any visitType_and(scriptParser::Type_andContext *context) = 0;

    virtual std::any visitType_or(scriptParser::Type_orContext *context) = 0;

    virtual std::any visitType_lex(scriptParser::Type_lexContext *context) = 0;

    virtual std::any visitAtom_tuple(scriptParser::Atom_tupleContext *context) = 0;

    virtual std::any visitFunction(scriptParser::FunctionContext *context) = 0;

    virtual std::any visitMap(scriptParser::MapContext *context) = 0;

    virtual std::any visitSelect(scriptParser::SelectContext *context) = 0;

    virtual std::any visitFilter(scriptParser::FilterContext *context) = 0;

    virtual std::any visitRfold(scriptParser::RfoldContext *context) = 0;

    virtual std::any visitLfold(scriptParser::LfoldContext *context) = 0;

    virtual std::any visitLog(scriptParser::LogContext *context) = 0;

    virtual std::any visitPow(scriptParser::PowContext *context) = 0;

    virtual std::any visitPhi(scriptParser::PhiContext *context) = 0;

    virtual std::any visitCross(scriptParser::CrossContext *context) = 0;

    virtual std::any visitSigma_type(scriptParser::Sigma_typeContext *context) = 0;

    virtual std::any visitSubtype_of(scriptParser::Subtype_ofContext *context) = 0;

    virtual std::any visitEnforce(scriptParser::EnforceContext *context) = 0;

    virtual std::any visitCoerce(scriptParser::CoerceContext *context) = 0;


};

