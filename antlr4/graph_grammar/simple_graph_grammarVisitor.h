
// Generated from antlr4/graph_grammar/simple_graph_grammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "simple_graph_grammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by simple_graph_grammarParser.
 */
class  simple_graph_grammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by simple_graph_grammarParser.
   */
    virtual std::any visitAll_matches(simple_graph_grammarParser::All_matchesContext *context) = 0;

    virtual std::any visitNode(simple_graph_grammarParser::NodeContext *context) = 0;

    virtual std::any visitCentralmatch(simple_graph_grammarParser::CentralmatchContext *context) = 0;

    virtual std::any visitMany_edges(simple_graph_grammarParser::Many_edgesContext *context) = 0;

    virtual std::any visitDel_node_or_edge(simple_graph_grammarParser::Del_node_or_edgeContext *context) = 0;

    virtual std::any visitNeu_obj(simple_graph_grammarParser::Neu_objContext *context) = 0;

    virtual std::any visitUpdate_expr(simple_graph_grammarParser::Update_exprContext *context) = 0;

    virtual std::any visitNode_xi(simple_graph_grammarParser::Node_xiContext *context) = 0;

    virtual std::any visitNode_ell(simple_graph_grammarParser::Node_ellContext *context) = 0;

    virtual std::any visitNode_prop(simple_graph_grammarParser::Node_propContext *context) = 0;

    virtual std::any visitNode_containment(simple_graph_grammarParser::Node_containmentContext *context) = 0;

    virtual std::any visitEdge_label(simple_graph_grammarParser::Edge_labelContext *context) = 0;

    virtual std::any visitEdge_src(simple_graph_grammarParser::Edge_srcContext *context) = 0;

    virtual std::any visitEdge_dst(simple_graph_grammarParser::Edge_dstContext *context) = 0;

    virtual std::any visitIfte_expr(simple_graph_grammarParser::Ifte_exprContext *context) = 0;

    virtual std::any visitNode_or_edge(simple_graph_grammarParser::Node_or_edgeContext *context) = 0;

    virtual std::any visitJust_par(simple_graph_grammarParser::Just_parContext *context) = 0;

    virtual std::any visitScript(simple_graph_grammarParser::ScriptContext *context) = 0;

    virtual std::any visitLeq_test(simple_graph_grammarParser::Leq_testContext *context) = 0;

    virtual std::any visitScript_test(simple_graph_grammarParser::Script_testContext *context) = 0;

    virtual std::any visitOr_test(simple_graph_grammarParser::Or_testContext *context) = 0;

    virtual std::any visitPar_test(simple_graph_grammarParser::Par_testContext *context) = 0;

    virtual std::any visitMatched(simple_graph_grammarParser::MatchedContext *context) = 0;

    virtual std::any visitEq_test(simple_graph_grammarParser::Eq_testContext *context) = 0;

    virtual std::any visitNeq_test(simple_graph_grammarParser::Neq_testContext *context) = 0;

    virtual std::any visitLt_test(simple_graph_grammarParser::Lt_testContext *context) = 0;

    virtual std::any visitUnmatched(simple_graph_grammarParser::UnmatchedContext *context) = 0;

    virtual std::any visitAnd_test(simple_graph_grammarParser::And_testContext *context) = 0;

    virtual std::any visitTest_data(simple_graph_grammarParser::Test_dataContext *context) = 0;

    virtual std::any visitTest_value(simple_graph_grammarParser::Test_valueContext *context) = 0;

    virtual std::any visitOutedge(simple_graph_grammarParser::OutedgeContext *context) = 0;

    virtual std::any visitInedge(simple_graph_grammarParser::InedgeContext *context) = 0;

    virtual std::any visitHook(simple_graph_grammarParser::HookContext *context) = 0;

    virtual std::any visitEdge_joining(simple_graph_grammarParser::Edge_joiningContext *context) = 0;

    virtual std::any visitEdgelabel(simple_graph_grammarParser::EdgelabelContext *context) = 0;

    virtual std::any visitMultiple_labels(simple_graph_grammarParser::Multiple_labelsContext *context) = 0;


};

