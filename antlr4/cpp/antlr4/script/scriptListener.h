
// Generated from antlr4/script/script.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "scriptParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by scriptParser.
 */
class  scriptListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterScript(scriptParser::ScriptContext *ctx) = 0;
  virtual void exitScript(scriptParser::ScriptContext *ctx) = 0;

  virtual void enterTuple_pair(scriptParser::Tuple_pairContext *ctx) = 0;
  virtual void exitTuple_pair(scriptParser::Tuple_pairContext *ctx) = 0;

  virtual void enterVarphi(scriptParser::VarphiContext *ctx) = 0;
  virtual void exitVarphi(scriptParser::VarphiContext *ctx) = 0;

  virtual void enterSelect(scriptParser::SelectContext *ctx) = 0;
  virtual void exitSelect(scriptParser::SelectContext *ctx) = 0;

  virtual void enterMod(scriptParser::ModContext *ctx) = 0;
  virtual void exitMod(scriptParser::ModContext *ctx) = 0;

  virtual void enterMult(scriptParser::MultContext *ctx) = 0;
  virtual void exitMult(scriptParser::MultContext *ctx) = 0;

  virtual void enterRfold(scriptParser::RfoldContext *ctx) = 0;
  virtual void exitRfold(scriptParser::RfoldContext *ctx) = 0;

  virtual void enterCos(scriptParser::CosContext *ctx) = 0;
  virtual void exitCos(scriptParser::CosContext *ctx) = 0;

  virtual void enterLt(scriptParser::LtContext *ctx) = 0;
  virtual void exitLt(scriptParser::LtContext *ctx) = 0;

  virtual void enterPut(scriptParser::PutContext *ctx) = 0;
  virtual void exitPut(scriptParser::PutContext *ctx) = 0;

  virtual void enterDiv(scriptParser::DivContext *ctx) = 0;
  virtual void exitDiv(scriptParser::DivContext *ctx) = 0;

  virtual void enterFunction(scriptParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(scriptParser::FunctionContext *ctx) = 0;

  virtual void enterSelfcross(scriptParser::SelfcrossContext *ctx) = 0;
  virtual void exitSelfcross(scriptParser::SelfcrossContext *ctx) = 0;

  virtual void enterLeq(scriptParser::LeqContext *ctx) = 0;
  virtual void exitLeq(scriptParser::LeqContext *ctx) = 0;

  virtual void enterNeq(scriptParser::NeqContext *ctx) = 0;
  virtual void exitNeq(scriptParser::NeqContext *ctx) = 0;

  virtual void enterTan(scriptParser::TanContext *ctx) = 0;
  virtual void exitTan(scriptParser::TanContext *ctx) = 0;

  virtual void enterAdd(scriptParser::AddContext *ctx) = 0;
  virtual void exitAdd(scriptParser::AddContext *ctx) = 0;

  virtual void enterType_bool(scriptParser::Type_boolContext *ctx) = 0;
  virtual void exitType_bool(scriptParser::Type_boolContext *ctx) = 0;

  virtual void enterEnsure(scriptParser::EnsureContext *ctx) = 0;
  virtual void exitEnsure(scriptParser::EnsureContext *ctx) = 0;

  virtual void enterImply(scriptParser::ImplyContext *ctx) = 0;
  virtual void exitImply(scriptParser::ImplyContext *ctx) = 0;

  virtual void enterEll(scriptParser::EllContext *ctx) = 0;
  virtual void exitEll(scriptParser::EllContext *ctx) = 0;

  virtual void enterVar(scriptParser::VarContext *ctx) = 0;
  virtual void exitVar(scriptParser::VarContext *ctx) = 0;

  virtual void enterKind(scriptParser::KindContext *ctx) = 0;
  virtual void exitKind(scriptParser::KindContext *ctx) = 0;

  virtual void enterAtom_bool(scriptParser::Atom_boolContext *ctx) = 0;
  virtual void exitAtom_bool(scriptParser::Atom_boolContext *ctx) = 0;

  virtual void enterCeil(scriptParser::CeilContext *ctx) = 0;
  virtual void exitCeil(scriptParser::CeilContext *ctx) = 0;

  virtual void enterConcat(scriptParser::ConcatContext *ctx) = 0;
  virtual void exitConcat(scriptParser::ConcatContext *ctx) = 0;

  virtual void enterEq(scriptParser::EqContext *ctx) = 0;
  virtual void exitEq(scriptParser::EqContext *ctx) = 0;

  virtual void enterType_tuple(scriptParser::Type_tupleContext *ctx) = 0;
  virtual void exitType_tuple(scriptParser::Type_tupleContext *ctx) = 0;

  virtual void enterSigma_type(scriptParser::Sigma_typeContext *ctx) = 0;
  virtual void exitSigma_type(scriptParser::Sigma_typeContext *ctx) = 0;

  virtual void enterContains(scriptParser::ContainsContext *ctx) = 0;
  virtual void exitContains(scriptParser::ContainsContext *ctx) = 0;

  virtual void enterEval(scriptParser::EvalContext *ctx) = 0;
  virtual void exitEval(scriptParser::EvalContext *ctx) = 0;

  virtual void enterAtom_number(scriptParser::Atom_numberContext *ctx) = 0;
  virtual void exitAtom_number(scriptParser::Atom_numberContext *ctx) = 0;

  virtual void enterAt(scriptParser::AtContext *ctx) = 0;
  virtual void exitAt(scriptParser::AtContext *ctx) = 0;

  virtual void enterSub(scriptParser::SubContext *ctx) = 0;
  virtual void exitSub(scriptParser::SubContext *ctx) = 0;

  virtual void enterAtom_array(scriptParser::Atom_arrayContext *ctx) = 0;
  virtual void exitAtom_array(scriptParser::Atom_arrayContext *ctx) = 0;

  virtual void enterLog(scriptParser::LogContext *ctx) = 0;
  virtual void exitLog(scriptParser::LogContext *ctx) = 0;

  virtual void enterLfold(scriptParser::LfoldContext *ctx) = 0;
  virtual void exitLfold(scriptParser::LfoldContext *ctx) = 0;

  virtual void enterSubstring(scriptParser::SubstringContext *ctx) = 0;
  virtual void exitSubstring(scriptParser::SubstringContext *ctx) = 0;

  virtual void enterRemove(scriptParser::RemoveContext *ctx) = 0;
  virtual void exitRemove(scriptParser::RemoveContext *ctx) = 0;

  virtual void enterParen(scriptParser::ParenContext *ctx) = 0;
  virtual void exitParen(scriptParser::ParenContext *ctx) = 0;

  virtual void enterNot(scriptParser::NotContext *ctx) = 0;
  virtual void exitNot(scriptParser::NotContext *ctx) = 0;

  virtual void enterType_string(scriptParser::Type_stringContext *ctx) = 0;
  virtual void exitType_string(scriptParser::Type_stringContext *ctx) = 0;

  virtual void enterGeq(scriptParser::GeqContext *ctx) = 0;
  virtual void exitGeq(scriptParser::GeqContext *ctx) = 0;

  virtual void enterFlat(scriptParser::FlatContext *ctx) = 0;
  virtual void exitFlat(scriptParser::FlatContext *ctx) = 0;

  virtual void enterAnd(scriptParser::AndContext *ctx) = 0;
  virtual void exitAnd(scriptParser::AndContext *ctx) = 0;

  virtual void enterPow(scriptParser::PowContext *ctx) = 0;
  virtual void exitPow(scriptParser::PowContext *ctx) = 0;

  virtual void enterSin(scriptParser::SinContext *ctx) = 0;
  virtual void exitSin(scriptParser::SinContext *ctx) = 0;

  virtual void enterFloor(scriptParser::FloorContext *ctx) = 0;
  virtual void exitFloor(scriptParser::FloorContext *ctx) = 0;

  virtual void enterMap(scriptParser::MapContext *ctx) = 0;
  virtual void exitMap(scriptParser::MapContext *ctx) = 0;

  virtual void enterTypeof(scriptParser::TypeofContext *ctx) = 0;
  virtual void exitTypeof(scriptParser::TypeofContext *ctx) = 0;

  virtual void enterType_int(scriptParser::Type_intContext *ctx) = 0;
  virtual void exitType_int(scriptParser::Type_intContext *ctx) = 0;

  virtual void enterOr(scriptParser::OrContext *ctx) = 0;
  virtual void exitOr(scriptParser::OrContext *ctx) = 0;

  virtual void enterInj(scriptParser::InjContext *ctx) = 0;
  virtual void exitInj(scriptParser::InjContext *ctx) = 0;

  virtual void enterApply(scriptParser::ApplyContext *ctx) = 0;
  virtual void exitApply(scriptParser::ApplyContext *ctx) = 0;

  virtual void enterCross(scriptParser::CrossContext *ctx) = 0;
  virtual void exitCross(scriptParser::CrossContext *ctx) = 0;

  virtual void enterGt(scriptParser::GtContext *ctx) = 0;
  virtual void exitGt(scriptParser::GtContext *ctx) = 0;

  virtual void enterAtom_tuple(scriptParser::Atom_tupleContext *ctx) = 0;
  virtual void exitAtom_tuple(scriptParser::Atom_tupleContext *ctx) = 0;

  virtual void enterType_double(scriptParser::Type_doubleContext *ctx) = 0;
  virtual void exitType_double(scriptParser::Type_doubleContext *ctx) = 0;

  virtual void enterFilter(scriptParser::FilterContext *ctx) = 0;
  virtual void exitFilter(scriptParser::FilterContext *ctx) = 0;

  virtual void enterPhi(scriptParser::PhiContext *ctx) = 0;
  virtual void exitPhi(scriptParser::PhiContext *ctx) = 0;

  virtual void enterXi(scriptParser::XiContext *ctx) = 0;
  virtual void exitXi(scriptParser::XiContext *ctx) = 0;

  virtual void enterType_list(scriptParser::Type_listContext *ctx) = 0;
  virtual void exitType_list(scriptParser::Type_listContext *ctx) = 0;

  virtual void enterAbs(scriptParser::AbsContext *ctx) = 0;
  virtual void exitAbs(scriptParser::AbsContext *ctx) = 0;

  virtual void enterObj(scriptParser::ObjContext *ctx) = 0;
  virtual void exitObj(scriptParser::ObjContext *ctx) = 0;

  virtual void enterVariable(scriptParser::VariableContext *ctx) = 0;
  virtual void exitVariable(scriptParser::VariableContext *ctx) = 0;

  virtual void enterAppend(scriptParser::AppendContext *ctx) = 0;
  virtual void exitAppend(scriptParser::AppendContext *ctx) = 0;

  virtual void enterIfte(scriptParser::IfteContext *ctx) = 0;
  virtual void exitIfte(scriptParser::IfteContext *ctx) = 0;

  virtual void enterAtom_string(scriptParser::Atom_stringContext *ctx) = 0;
  virtual void exitAtom_string(scriptParser::Atom_stringContext *ctx) = 0;

  virtual void enterAssign(scriptParser::AssignContext *ctx) = 0;
  virtual void exitAssign(scriptParser::AssignContext *ctx) = 0;


};

