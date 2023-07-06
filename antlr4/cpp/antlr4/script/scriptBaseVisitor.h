
// Generated from antlr4/script/script.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "scriptVisitor.h"


/**
 * This class provides an empty implementation of scriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  scriptBaseVisitor : public scriptVisitor {
public:

  virtual std::any visitScript(scriptParser::ScriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTuple_pair(scriptParser::Tuple_pairContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCoerce(scriptParser::CoerceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarphi(scriptParser::VarphiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelect(scriptParser::SelectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMod(scriptParser::ModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMult(scriptParser::MultContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRfold(scriptParser::RfoldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCos(scriptParser::CosContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLt(scriptParser::LtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProject(scriptParser::ProjectContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPut(scriptParser::PutContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiv(scriptParser::DivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(scriptParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSelfcross(scriptParser::SelfcrossContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLeq(scriptParser::LeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_label(scriptParser::Type_labelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNeq(scriptParser::NeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTan(scriptParser::TanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdd(scriptParser::AddContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubtype_of(scriptParser::Subtype_ofContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_bool(scriptParser::Type_boolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnsure(scriptParser::EnsureContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImply(scriptParser::ImplyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEll(scriptParser::EllContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar(scriptParser::VarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKind(scriptParser::KindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_bool(scriptParser::Atom_boolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCeil(scriptParser::CeilContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConcat(scriptParser::ConcatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEq(scriptParser::EqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_tuple(scriptParser::Type_tupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_or(scriptParser::Type_orContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_lex(scriptParser::Type_lexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSigma_type(scriptParser::Sigma_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContains(scriptParser::ContainsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEval(scriptParser::EvalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_number(scriptParser::Atom_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAt(scriptParser::AtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNull(scriptParser::NullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnforce(scriptParser::EnforceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSub(scriptParser::SubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_array(scriptParser::Atom_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLog(scriptParser::LogContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLfold(scriptParser::LfoldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSubstring(scriptParser::SubstringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRemove(scriptParser::RemoveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParen(scriptParser::ParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNot(scriptParser::NotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_string(scriptParser::Type_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_any(scriptParser::Type_anyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGeq(scriptParser::GeqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFlat(scriptParser::FlatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAnd(scriptParser::AndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPow(scriptParser::PowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSin(scriptParser::SinContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloor(scriptParser::FloorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMap(scriptParser::MapContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeof(scriptParser::TypeofContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_int(scriptParser::Type_intContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOr(scriptParser::OrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInj(scriptParser::InjContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitApply(scriptParser::ApplyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_and(scriptParser::Type_andContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCross(scriptParser::CrossContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGt(scriptParser::GtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_tuple(scriptParser::Atom_tupleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_double(scriptParser::Type_doubleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFilter(scriptParser::FilterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPhi(scriptParser::PhiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitXi(scriptParser::XiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_list(scriptParser::Type_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAbs(scriptParser::AbsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObj(scriptParser::ObjContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType_bot(scriptParser::Type_botContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariable(scriptParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAppend(scriptParser::AppendContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfte(scriptParser::IfteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtom_string(scriptParser::Atom_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(scriptParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }


};

