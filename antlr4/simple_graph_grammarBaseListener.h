
// Generated from antlr4/simple_graph_grammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "simple_graph_grammarListener.h"


/**
 * This class provides an empty implementation of simple_graph_grammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  simple_graph_grammarBaseListener : public simple_graph_grammarListener {
public:

  virtual void enterAll_matches(simple_graph_grammarParser::All_matchesContext * /*ctx*/) override { }
  virtual void exitAll_matches(simple_graph_grammarParser::All_matchesContext * /*ctx*/) override { }

  virtual void enterNode(simple_graph_grammarParser::NodeContext * /*ctx*/) override { }
  virtual void exitNode(simple_graph_grammarParser::NodeContext * /*ctx*/) override { }

  virtual void enterCentralmatch(simple_graph_grammarParser::CentralmatchContext * /*ctx*/) override { }
  virtual void exitCentralmatch(simple_graph_grammarParser::CentralmatchContext * /*ctx*/) override { }

  virtual void enterMany_edges(simple_graph_grammarParser::Many_edgesContext * /*ctx*/) override { }
  virtual void exitMany_edges(simple_graph_grammarParser::Many_edgesContext * /*ctx*/) override { }

  virtual void enterDel_node_or_edge(simple_graph_grammarParser::Del_node_or_edgeContext * /*ctx*/) override { }
  virtual void exitDel_node_or_edge(simple_graph_grammarParser::Del_node_or_edgeContext * /*ctx*/) override { }

  virtual void enterNeu_obj(simple_graph_grammarParser::Neu_objContext * /*ctx*/) override { }
  virtual void exitNeu_obj(simple_graph_grammarParser::Neu_objContext * /*ctx*/) override { }

  virtual void enterUpdate_expr(simple_graph_grammarParser::Update_exprContext * /*ctx*/) override { }
  virtual void exitUpdate_expr(simple_graph_grammarParser::Update_exprContext * /*ctx*/) override { }

  virtual void enterNode_xi(simple_graph_grammarParser::Node_xiContext * /*ctx*/) override { }
  virtual void exitNode_xi(simple_graph_grammarParser::Node_xiContext * /*ctx*/) override { }

  virtual void enterNode_ell(simple_graph_grammarParser::Node_ellContext * /*ctx*/) override { }
  virtual void exitNode_ell(simple_graph_grammarParser::Node_ellContext * /*ctx*/) override { }

  virtual void enterNode_prop(simple_graph_grammarParser::Node_propContext * /*ctx*/) override { }
  virtual void exitNode_prop(simple_graph_grammarParser::Node_propContext * /*ctx*/) override { }

  virtual void enterNode_containment(simple_graph_grammarParser::Node_containmentContext * /*ctx*/) override { }
  virtual void exitNode_containment(simple_graph_grammarParser::Node_containmentContext * /*ctx*/) override { }

  virtual void enterEdge_label(simple_graph_grammarParser::Edge_labelContext * /*ctx*/) override { }
  virtual void exitEdge_label(simple_graph_grammarParser::Edge_labelContext * /*ctx*/) override { }

  virtual void enterEdge_src(simple_graph_grammarParser::Edge_srcContext * /*ctx*/) override { }
  virtual void exitEdge_src(simple_graph_grammarParser::Edge_srcContext * /*ctx*/) override { }

  virtual void enterEdge_dst(simple_graph_grammarParser::Edge_dstContext * /*ctx*/) override { }
  virtual void exitEdge_dst(simple_graph_grammarParser::Edge_dstContext * /*ctx*/) override { }

  virtual void enterIfte_expr(simple_graph_grammarParser::Ifte_exprContext * /*ctx*/) override { }
  virtual void exitIfte_expr(simple_graph_grammarParser::Ifte_exprContext * /*ctx*/) override { }

  virtual void enterNode_or_edge(simple_graph_grammarParser::Node_or_edgeContext * /*ctx*/) override { }
  virtual void exitNode_or_edge(simple_graph_grammarParser::Node_or_edgeContext * /*ctx*/) override { }

  virtual void enterJust_par(simple_graph_grammarParser::Just_parContext * /*ctx*/) override { }
  virtual void exitJust_par(simple_graph_grammarParser::Just_parContext * /*ctx*/) override { }

  virtual void enterTest_expr(simple_graph_grammarParser::Test_exprContext * /*ctx*/) override { }
  virtual void exitTest_expr(simple_graph_grammarParser::Test_exprContext * /*ctx*/) override { }

  virtual void enterTest_data(simple_graph_grammarParser::Test_dataContext * /*ctx*/) override { }
  virtual void exitTest_data(simple_graph_grammarParser::Test_dataContext * /*ctx*/) override { }

  virtual void enterTest_value(simple_graph_grammarParser::Test_valueContext * /*ctx*/) override { }
  virtual void exitTest_value(simple_graph_grammarParser::Test_valueContext * /*ctx*/) override { }

  virtual void enterOutedge(simple_graph_grammarParser::OutedgeContext * /*ctx*/) override { }
  virtual void exitOutedge(simple_graph_grammarParser::OutedgeContext * /*ctx*/) override { }

  virtual void enterInedge(simple_graph_grammarParser::InedgeContext * /*ctx*/) override { }
  virtual void exitInedge(simple_graph_grammarParser::InedgeContext * /*ctx*/) override { }

  virtual void enterHook(simple_graph_grammarParser::HookContext * /*ctx*/) override { }
  virtual void exitHook(simple_graph_grammarParser::HookContext * /*ctx*/) override { }

  virtual void enterEdge_joining(simple_graph_grammarParser::Edge_joiningContext * /*ctx*/) override { }
  virtual void exitEdge_joining(simple_graph_grammarParser::Edge_joiningContext * /*ctx*/) override { }

  virtual void enterEdgelabel(simple_graph_grammarParser::EdgelabelContext * /*ctx*/) override { }
  virtual void exitEdgelabel(simple_graph_grammarParser::EdgelabelContext * /*ctx*/) override { }

  virtual void enterMultiple_labels(simple_graph_grammarParser::Multiple_labelsContext * /*ctx*/) override { }
  virtual void exitMultiple_labels(simple_graph_grammarParser::Multiple_labelsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

