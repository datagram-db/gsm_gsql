
// Generated from antlr4/script/script.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "scriptListener.h"


/**
 * This class provides an empty implementation of scriptListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  scriptBaseListener : public scriptListener {
public:

  virtual void enterScript(scriptParser::ScriptContext * /*ctx*/) override { }
  virtual void exitScript(scriptParser::ScriptContext * /*ctx*/) override { }

  virtual void enterTuple_pair(scriptParser::Tuple_pairContext * /*ctx*/) override { }
  virtual void exitTuple_pair(scriptParser::Tuple_pairContext * /*ctx*/) override { }

  virtual void enterVarphi(scriptParser::VarphiContext * /*ctx*/) override { }
  virtual void exitVarphi(scriptParser::VarphiContext * /*ctx*/) override { }

  virtual void enterSelect(scriptParser::SelectContext * /*ctx*/) override { }
  virtual void exitSelect(scriptParser::SelectContext * /*ctx*/) override { }

  virtual void enterMod(scriptParser::ModContext * /*ctx*/) override { }
  virtual void exitMod(scriptParser::ModContext * /*ctx*/) override { }

  virtual void enterMult(scriptParser::MultContext * /*ctx*/) override { }
  virtual void exitMult(scriptParser::MultContext * /*ctx*/) override { }

  virtual void enterRfold(scriptParser::RfoldContext * /*ctx*/) override { }
  virtual void exitRfold(scriptParser::RfoldContext * /*ctx*/) override { }

  virtual void enterCos(scriptParser::CosContext * /*ctx*/) override { }
  virtual void exitCos(scriptParser::CosContext * /*ctx*/) override { }

  virtual void enterLt(scriptParser::LtContext * /*ctx*/) override { }
  virtual void exitLt(scriptParser::LtContext * /*ctx*/) override { }

  virtual void enterPut(scriptParser::PutContext * /*ctx*/) override { }
  virtual void exitPut(scriptParser::PutContext * /*ctx*/) override { }

  virtual void enterDiv(scriptParser::DivContext * /*ctx*/) override { }
  virtual void exitDiv(scriptParser::DivContext * /*ctx*/) override { }

  virtual void enterFunction(scriptParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(scriptParser::FunctionContext * /*ctx*/) override { }

  virtual void enterSelfcross(scriptParser::SelfcrossContext * /*ctx*/) override { }
  virtual void exitSelfcross(scriptParser::SelfcrossContext * /*ctx*/) override { }

  virtual void enterLeq(scriptParser::LeqContext * /*ctx*/) override { }
  virtual void exitLeq(scriptParser::LeqContext * /*ctx*/) override { }

  virtual void enterNeq(scriptParser::NeqContext * /*ctx*/) override { }
  virtual void exitNeq(scriptParser::NeqContext * /*ctx*/) override { }

  virtual void enterTan(scriptParser::TanContext * /*ctx*/) override { }
  virtual void exitTan(scriptParser::TanContext * /*ctx*/) override { }

  virtual void enterAdd(scriptParser::AddContext * /*ctx*/) override { }
  virtual void exitAdd(scriptParser::AddContext * /*ctx*/) override { }

  virtual void enterType_bool(scriptParser::Type_boolContext * /*ctx*/) override { }
  virtual void exitType_bool(scriptParser::Type_boolContext * /*ctx*/) override { }

  virtual void enterEnsure(scriptParser::EnsureContext * /*ctx*/) override { }
  virtual void exitEnsure(scriptParser::EnsureContext * /*ctx*/) override { }

  virtual void enterImply(scriptParser::ImplyContext * /*ctx*/) override { }
  virtual void exitImply(scriptParser::ImplyContext * /*ctx*/) override { }

  virtual void enterEll(scriptParser::EllContext * /*ctx*/) override { }
  virtual void exitEll(scriptParser::EllContext * /*ctx*/) override { }

  virtual void enterVar(scriptParser::VarContext * /*ctx*/) override { }
  virtual void exitVar(scriptParser::VarContext * /*ctx*/) override { }

  virtual void enterKind(scriptParser::KindContext * /*ctx*/) override { }
  virtual void exitKind(scriptParser::KindContext * /*ctx*/) override { }

  virtual void enterAtom_bool(scriptParser::Atom_boolContext * /*ctx*/) override { }
  virtual void exitAtom_bool(scriptParser::Atom_boolContext * /*ctx*/) override { }

  virtual void enterCeil(scriptParser::CeilContext * /*ctx*/) override { }
  virtual void exitCeil(scriptParser::CeilContext * /*ctx*/) override { }

  virtual void enterConcat(scriptParser::ConcatContext * /*ctx*/) override { }
  virtual void exitConcat(scriptParser::ConcatContext * /*ctx*/) override { }

  virtual void enterEq(scriptParser::EqContext * /*ctx*/) override { }
  virtual void exitEq(scriptParser::EqContext * /*ctx*/) override { }

  virtual void enterType_tuple(scriptParser::Type_tupleContext * /*ctx*/) override { }
  virtual void exitType_tuple(scriptParser::Type_tupleContext * /*ctx*/) override { }

  virtual void enterSigma_type(scriptParser::Sigma_typeContext * /*ctx*/) override { }
  virtual void exitSigma_type(scriptParser::Sigma_typeContext * /*ctx*/) override { }

  virtual void enterContains(scriptParser::ContainsContext * /*ctx*/) override { }
  virtual void exitContains(scriptParser::ContainsContext * /*ctx*/) override { }

  virtual void enterEval(scriptParser::EvalContext * /*ctx*/) override { }
  virtual void exitEval(scriptParser::EvalContext * /*ctx*/) override { }

  virtual void enterAtom_number(scriptParser::Atom_numberContext * /*ctx*/) override { }
  virtual void exitAtom_number(scriptParser::Atom_numberContext * /*ctx*/) override { }

  virtual void enterAt(scriptParser::AtContext * /*ctx*/) override { }
  virtual void exitAt(scriptParser::AtContext * /*ctx*/) override { }

  virtual void enterSub(scriptParser::SubContext * /*ctx*/) override { }
  virtual void exitSub(scriptParser::SubContext * /*ctx*/) override { }

  virtual void enterAtom_array(scriptParser::Atom_arrayContext * /*ctx*/) override { }
  virtual void exitAtom_array(scriptParser::Atom_arrayContext * /*ctx*/) override { }

  virtual void enterLog(scriptParser::LogContext * /*ctx*/) override { }
  virtual void exitLog(scriptParser::LogContext * /*ctx*/) override { }

  virtual void enterLfold(scriptParser::LfoldContext * /*ctx*/) override { }
  virtual void exitLfold(scriptParser::LfoldContext * /*ctx*/) override { }

  virtual void enterSubstring(scriptParser::SubstringContext * /*ctx*/) override { }
  virtual void exitSubstring(scriptParser::SubstringContext * /*ctx*/) override { }

  virtual void enterRemove(scriptParser::RemoveContext * /*ctx*/) override { }
  virtual void exitRemove(scriptParser::RemoveContext * /*ctx*/) override { }

  virtual void enterParen(scriptParser::ParenContext * /*ctx*/) override { }
  virtual void exitParen(scriptParser::ParenContext * /*ctx*/) override { }

  virtual void enterNot(scriptParser::NotContext * /*ctx*/) override { }
  virtual void exitNot(scriptParser::NotContext * /*ctx*/) override { }

  virtual void enterType_string(scriptParser::Type_stringContext * /*ctx*/) override { }
  virtual void exitType_string(scriptParser::Type_stringContext * /*ctx*/) override { }

  virtual void enterGeq(scriptParser::GeqContext * /*ctx*/) override { }
  virtual void exitGeq(scriptParser::GeqContext * /*ctx*/) override { }

  virtual void enterFlat(scriptParser::FlatContext * /*ctx*/) override { }
  virtual void exitFlat(scriptParser::FlatContext * /*ctx*/) override { }

  virtual void enterAnd(scriptParser::AndContext * /*ctx*/) override { }
  virtual void exitAnd(scriptParser::AndContext * /*ctx*/) override { }

  virtual void enterPow(scriptParser::PowContext * /*ctx*/) override { }
  virtual void exitPow(scriptParser::PowContext * /*ctx*/) override { }

  virtual void enterSin(scriptParser::SinContext * /*ctx*/) override { }
  virtual void exitSin(scriptParser::SinContext * /*ctx*/) override { }

  virtual void enterFloor(scriptParser::FloorContext * /*ctx*/) override { }
  virtual void exitFloor(scriptParser::FloorContext * /*ctx*/) override { }

  virtual void enterMap(scriptParser::MapContext * /*ctx*/) override { }
  virtual void exitMap(scriptParser::MapContext * /*ctx*/) override { }

  virtual void enterTypeof(scriptParser::TypeofContext * /*ctx*/) override { }
  virtual void exitTypeof(scriptParser::TypeofContext * /*ctx*/) override { }

  virtual void enterType_int(scriptParser::Type_intContext * /*ctx*/) override { }
  virtual void exitType_int(scriptParser::Type_intContext * /*ctx*/) override { }

  virtual void enterOr(scriptParser::OrContext * /*ctx*/) override { }
  virtual void exitOr(scriptParser::OrContext * /*ctx*/) override { }

  virtual void enterInj(scriptParser::InjContext * /*ctx*/) override { }
  virtual void exitInj(scriptParser::InjContext * /*ctx*/) override { }

  virtual void enterApply(scriptParser::ApplyContext * /*ctx*/) override { }
  virtual void exitApply(scriptParser::ApplyContext * /*ctx*/) override { }

  virtual void enterCross(scriptParser::CrossContext * /*ctx*/) override { }
  virtual void exitCross(scriptParser::CrossContext * /*ctx*/) override { }

  virtual void enterGt(scriptParser::GtContext * /*ctx*/) override { }
  virtual void exitGt(scriptParser::GtContext * /*ctx*/) override { }

  virtual void enterAtom_tuple(scriptParser::Atom_tupleContext * /*ctx*/) override { }
  virtual void exitAtom_tuple(scriptParser::Atom_tupleContext * /*ctx*/) override { }

  virtual void enterType_double(scriptParser::Type_doubleContext * /*ctx*/) override { }
  virtual void exitType_double(scriptParser::Type_doubleContext * /*ctx*/) override { }

  virtual void enterFilter(scriptParser::FilterContext * /*ctx*/) override { }
  virtual void exitFilter(scriptParser::FilterContext * /*ctx*/) override { }

  virtual void enterPhi(scriptParser::PhiContext * /*ctx*/) override { }
  virtual void exitPhi(scriptParser::PhiContext * /*ctx*/) override { }

  virtual void enterXi(scriptParser::XiContext * /*ctx*/) override { }
  virtual void exitXi(scriptParser::XiContext * /*ctx*/) override { }

  virtual void enterType_list(scriptParser::Type_listContext * /*ctx*/) override { }
  virtual void exitType_list(scriptParser::Type_listContext * /*ctx*/) override { }

  virtual void enterAbs(scriptParser::AbsContext * /*ctx*/) override { }
  virtual void exitAbs(scriptParser::AbsContext * /*ctx*/) override { }

  virtual void enterObj(scriptParser::ObjContext * /*ctx*/) override { }
  virtual void exitObj(scriptParser::ObjContext * /*ctx*/) override { }

  virtual void enterVariable(scriptParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(scriptParser::VariableContext * /*ctx*/) override { }

  virtual void enterAppend(scriptParser::AppendContext * /*ctx*/) override { }
  virtual void exitAppend(scriptParser::AppendContext * /*ctx*/) override { }

  virtual void enterIfte(scriptParser::IfteContext * /*ctx*/) override { }
  virtual void exitIfte(scriptParser::IfteContext * /*ctx*/) override { }

  virtual void enterAtom_string(scriptParser::Atom_stringContext * /*ctx*/) override { }
  virtual void exitAtom_string(scriptParser::Atom_stringContext * /*ctx*/) override { }

  virtual void enterAssign(scriptParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(scriptParser::AssignContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

