
// Generated from antlr4/simple_graph_grammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "simple_graph_grammarVisitor.h"


/**
 * This class provides an empty implementation of simple_graph_grammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  simple_graph_grammarBaseVisitor : public simple_graph_grammarVisitor {
public:

  virtual std::any visitAll_matches(simple_graph_grammarParser::All_matchesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode(simple_graph_grammarParser::NodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCentralmatch(simple_graph_grammarParser::CentralmatchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMany_edges(simple_graph_grammarParser::Many_edgesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDel_node_or_edge(simple_graph_grammarParser::Del_node_or_edgeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNeu_obj(simple_graph_grammarParser::Neu_objContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUpdate_expr(simple_graph_grammarParser::Update_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_xi(simple_graph_grammarParser::Node_xiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_ell(simple_graph_grammarParser::Node_ellContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_prop(simple_graph_grammarParser::Node_propContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_containment(simple_graph_grammarParser::Node_containmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdge_label(simple_graph_grammarParser::Edge_labelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdge_src(simple_graph_grammarParser::Edge_srcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdge_dst(simple_graph_grammarParser::Edge_dstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfte_expr(simple_graph_grammarParser::Ifte_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNode_or_edge(simple_graph_grammarParser::Node_or_edgeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitJust_par(simple_graph_grammarParser::Just_parContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTest_expr(simple_graph_grammarParser::Test_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTest_data(simple_graph_grammarParser::Test_dataContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTest_value(simple_graph_grammarParser::Test_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOutedge(simple_graph_grammarParser::OutedgeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInedge(simple_graph_grammarParser::InedgeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHook(simple_graph_grammarParser::HookContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdge_joining(simple_graph_grammarParser::Edge_joiningContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEdgelabel(simple_graph_grammarParser::EdgelabelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiple_labels(simple_graph_grammarParser::Multiple_labelsContext *ctx) override {
    return visitChildren(ctx);
  }


};

