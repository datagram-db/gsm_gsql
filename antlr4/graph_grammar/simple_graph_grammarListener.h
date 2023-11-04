
// Generated from antlr4/graph_grammar/simple_graph_grammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "simple_graph_grammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by simple_graph_grammarParser.
 */
class  simple_graph_grammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAll_matches(simple_graph_grammarParser::All_matchesContext *ctx) = 0;
  virtual void exitAll_matches(simple_graph_grammarParser::All_matchesContext *ctx) = 0;

  virtual void enterNode(simple_graph_grammarParser::NodeContext *ctx) = 0;
  virtual void exitNode(simple_graph_grammarParser::NodeContext *ctx) = 0;

  virtual void enterCentralmatch(simple_graph_grammarParser::CentralmatchContext *ctx) = 0;
  virtual void exitCentralmatch(simple_graph_grammarParser::CentralmatchContext *ctx) = 0;

  virtual void enterMany_edges(simple_graph_grammarParser::Many_edgesContext *ctx) = 0;
  virtual void exitMany_edges(simple_graph_grammarParser::Many_edgesContext *ctx) = 0;

  virtual void enterDel_node_or_edge(simple_graph_grammarParser::Del_node_or_edgeContext *ctx) = 0;
  virtual void exitDel_node_or_edge(simple_graph_grammarParser::Del_node_or_edgeContext *ctx) = 0;

  virtual void enterNeu_obj(simple_graph_grammarParser::Neu_objContext *ctx) = 0;
  virtual void exitNeu_obj(simple_graph_grammarParser::Neu_objContext *ctx) = 0;

  virtual void enterUpdate_expr(simple_graph_grammarParser::Update_exprContext *ctx) = 0;
  virtual void exitUpdate_expr(simple_graph_grammarParser::Update_exprContext *ctx) = 0;

  virtual void enterNode_xi(simple_graph_grammarParser::Node_xiContext *ctx) = 0;
  virtual void exitNode_xi(simple_graph_grammarParser::Node_xiContext *ctx) = 0;

  virtual void enterNode_ell(simple_graph_grammarParser::Node_ellContext *ctx) = 0;
  virtual void exitNode_ell(simple_graph_grammarParser::Node_ellContext *ctx) = 0;

  virtual void enterNode_prop(simple_graph_grammarParser::Node_propContext *ctx) = 0;
  virtual void exitNode_prop(simple_graph_grammarParser::Node_propContext *ctx) = 0;

  virtual void enterNode_containment(simple_graph_grammarParser::Node_containmentContext *ctx) = 0;
  virtual void exitNode_containment(simple_graph_grammarParser::Node_containmentContext *ctx) = 0;

  virtual void enterEdge_label(simple_graph_grammarParser::Edge_labelContext *ctx) = 0;
  virtual void exitEdge_label(simple_graph_grammarParser::Edge_labelContext *ctx) = 0;

  virtual void enterEdge_src(simple_graph_grammarParser::Edge_srcContext *ctx) = 0;
  virtual void exitEdge_src(simple_graph_grammarParser::Edge_srcContext *ctx) = 0;

  virtual void enterEdge_dst(simple_graph_grammarParser::Edge_dstContext *ctx) = 0;
  virtual void exitEdge_dst(simple_graph_grammarParser::Edge_dstContext *ctx) = 0;

  virtual void enterIfte_expr(simple_graph_grammarParser::Ifte_exprContext *ctx) = 0;
  virtual void exitIfte_expr(simple_graph_grammarParser::Ifte_exprContext *ctx) = 0;

  virtual void enterNode_or_edge(simple_graph_grammarParser::Node_or_edgeContext *ctx) = 0;
  virtual void exitNode_or_edge(simple_graph_grammarParser::Node_or_edgeContext *ctx) = 0;

  virtual void enterJust_par(simple_graph_grammarParser::Just_parContext *ctx) = 0;
  virtual void exitJust_par(simple_graph_grammarParser::Just_parContext *ctx) = 0;

  virtual void enterScript(simple_graph_grammarParser::ScriptContext *ctx) = 0;
  virtual void exitScript(simple_graph_grammarParser::ScriptContext *ctx) = 0;

  virtual void enterLeq_test(simple_graph_grammarParser::Leq_testContext *ctx) = 0;
  virtual void exitLeq_test(simple_graph_grammarParser::Leq_testContext *ctx) = 0;

  virtual void enterScript_test(simple_graph_grammarParser::Script_testContext *ctx) = 0;
  virtual void exitScript_test(simple_graph_grammarParser::Script_testContext *ctx) = 0;

  virtual void enterOr_test(simple_graph_grammarParser::Or_testContext *ctx) = 0;
  virtual void exitOr_test(simple_graph_grammarParser::Or_testContext *ctx) = 0;

  virtual void enterPar_test(simple_graph_grammarParser::Par_testContext *ctx) = 0;
  virtual void exitPar_test(simple_graph_grammarParser::Par_testContext *ctx) = 0;

  virtual void enterEq_test(simple_graph_grammarParser::Eq_testContext *ctx) = 0;
  virtual void exitEq_test(simple_graph_grammarParser::Eq_testContext *ctx) = 0;

  virtual void enterNeq_test(simple_graph_grammarParser::Neq_testContext *ctx) = 0;
  virtual void exitNeq_test(simple_graph_grammarParser::Neq_testContext *ctx) = 0;

  virtual void enterLt_test(simple_graph_grammarParser::Lt_testContext *ctx) = 0;
  virtual void exitLt_test(simple_graph_grammarParser::Lt_testContext *ctx) = 0;

  virtual void enterAnd_test(simple_graph_grammarParser::And_testContext *ctx) = 0;
  virtual void exitAnd_test(simple_graph_grammarParser::And_testContext *ctx) = 0;

  virtual void enterTest_data(simple_graph_grammarParser::Test_dataContext *ctx) = 0;
  virtual void exitTest_data(simple_graph_grammarParser::Test_dataContext *ctx) = 0;

  virtual void enterTest_value(simple_graph_grammarParser::Test_valueContext *ctx) = 0;
  virtual void exitTest_value(simple_graph_grammarParser::Test_valueContext *ctx) = 0;

  virtual void enterOutedge(simple_graph_grammarParser::OutedgeContext *ctx) = 0;
  virtual void exitOutedge(simple_graph_grammarParser::OutedgeContext *ctx) = 0;

  virtual void enterInedge(simple_graph_grammarParser::InedgeContext *ctx) = 0;
  virtual void exitInedge(simple_graph_grammarParser::InedgeContext *ctx) = 0;

  virtual void enterHook(simple_graph_grammarParser::HookContext *ctx) = 0;
  virtual void exitHook(simple_graph_grammarParser::HookContext *ctx) = 0;

  virtual void enterEdge_joining(simple_graph_grammarParser::Edge_joiningContext *ctx) = 0;
  virtual void exitEdge_joining(simple_graph_grammarParser::Edge_joiningContext *ctx) = 0;

  virtual void enterEdgelabel(simple_graph_grammarParser::EdgelabelContext *ctx) = 0;
  virtual void exitEdgelabel(simple_graph_grammarParser::EdgelabelContext *ctx) = 0;

  virtual void enterMultiple_labels(simple_graph_grammarParser::Multiple_labelsContext *ctx) = 0;
  virtual void exitMultiple_labels(simple_graph_grammarParser::Multiple_labelsContext *ctx) = 0;


};

