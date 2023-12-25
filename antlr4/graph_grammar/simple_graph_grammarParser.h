
// Generated from antlr4/graph_grammar/simple_graph_grammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  simple_graph_grammarParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, WHERE = 29, IF = 30, THEN = 31, ELSE = 32, AS = 33, 
    VEC = 34, REWRITE_TO = 35, FORALL = 36, QM = 37, EQ = 38, STAR = 39, 
    LPAR = 40, RPAR = 41, COL = 42, QPAR = 43, PPAR = 44, EscapedString = 45, 
    OTHERS = 46, SPACE = 47, COMMENT = 48, LINE_COMMENT = 49
  };

  enum {
    RuleAll_matches = 0, RuleNode = 1, RuleCentralmatch = 2, RuleMany_edges = 3, 
    RuleRewrite_to = 4, RuleRewrite_expr = 5, RuleTest_expr = 6, RuleTest_expr_side = 7, 
    RuleEdge = 8, RuleEdge_joining = 9, RuleEdgelabel = 10, RuleMultiple_labels = 11
  };

  explicit simple_graph_grammarParser(antlr4::TokenStream *input);

  simple_graph_grammarParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~simple_graph_grammarParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class All_matchesContext;
  class NodeContext;
  class CentralmatchContext;
  class Many_edgesContext;
  class Rewrite_toContext;
  class Rewrite_exprContext;
  class Test_exprContext;
  class Test_expr_sideContext;
  class EdgeContext;
  class Edge_joiningContext;
  class EdgelabelContext;
  class Multiple_labelsContext; 

  class  All_matchesContext : public antlr4::ParserRuleContext {
  public:
    All_matchesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CentralmatchContext *> centralmatch();
    CentralmatchContext* centralmatch(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  All_matchesContext* all_matches();

  class  NodeContext : public antlr4::ParserRuleContext {
  public:
    simple_graph_grammarParser::Multiple_labelsContext *var = nullptr;
    NodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    Multiple_labelsContext *multiple_labels();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *VEC();
    antlr4::tree::TerminalNode *COL();
    antlr4::tree::TerminalNode *OTHERS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NodeContext* node();

  class  CentralmatchContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *var = nullptr;
    simple_graph_grammarParser::NodeContext *src = nullptr;
    simple_graph_grammarParser::Many_edgesContext *e1 = nullptr;
    simple_graph_grammarParser::NodeContext *dst = nullptr;
    CentralmatchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *OTHERS();
    std::vector<NodeContext *> node();
    NodeContext* node(size_t i);
    std::vector<Edge_joiningContext *> edge_joining();
    Edge_joiningContext* edge_joining(size_t i);
    antlr4::tree::TerminalNode *WHERE();
    Test_exprContext *test_expr();
    antlr4::tree::TerminalNode *REWRITE_TO();
    Many_edgesContext *many_edges();
    std::vector<Rewrite_toContext *> rewrite_to();
    Rewrite_toContext* rewrite_to(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CentralmatchContext* centralmatch();

  class  Many_edgesContext : public antlr4::ParserRuleContext {
  public:
    Many_edgesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EdgeContext *> edge();
    EdgeContext* edge(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Many_edgesContext* many_edges();

  class  Rewrite_toContext : public antlr4::ParserRuleContext {
  public:
    Rewrite_toContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Rewrite_toContext() = default;
    void copyFrom(Rewrite_toContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Del_node_or_edgeContext : public Rewrite_toContext {
  public:
    Del_node_or_edgeContext(Rewrite_toContext *ctx);

    antlr4::tree::TerminalNode *OTHERS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Update_exprContext : public Rewrite_toContext {
  public:
    Update_exprContext(Rewrite_toContext *ctx);

    simple_graph_grammarParser::Rewrite_exprContext *to = nullptr;
    simple_graph_grammarParser::Rewrite_exprContext *from = nullptr;
    antlr4::tree::TerminalNode *AS();
    std::vector<Rewrite_exprContext *> rewrite_expr();
    Rewrite_exprContext* rewrite_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Neu_objContext : public Rewrite_toContext {
  public:
    Neu_objContext(Rewrite_toContext *ctx);

    antlr4::Token *dst = nullptr;
    antlr4::tree::TerminalNode *OTHERS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Rewrite_toContext* rewrite_to();

  class  Rewrite_exprContext : public antlr4::ParserRuleContext {
  public:
    Rewrite_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Rewrite_exprContext() = default;
    void copyFrom(Rewrite_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Node_containmentContext : public Rewrite_exprContext {
  public:
    Node_containmentContext(Rewrite_exprContext *ctx);

    simple_graph_grammarParser::Rewrite_exprContext *key = nullptr;
    simple_graph_grammarParser::Rewrite_exprContext *nodeVar = nullptr;
    std::vector<Rewrite_exprContext *> rewrite_expr();
    Rewrite_exprContext* rewrite_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Node_propContext : public Rewrite_exprContext {
  public:
    Node_propContext(Rewrite_exprContext *ctx);

    simple_graph_grammarParser::Rewrite_exprContext *key = nullptr;
    simple_graph_grammarParser::Rewrite_exprContext *nodeVar = nullptr;
    std::vector<Rewrite_exprContext *> rewrite_expr();
    Rewrite_exprContext* rewrite_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Ifte_exprContext : public Rewrite_exprContext {
  public:
    Ifte_exprContext(Rewrite_exprContext *ctx);

    simple_graph_grammarParser::Test_exprContext *ifcond = nullptr;
    simple_graph_grammarParser::Rewrite_exprContext *then_effect = nullptr;
    simple_graph_grammarParser::Rewrite_exprContext *else_effect = nullptr;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAR();
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *THEN();
    Test_exprContext *test_expr();
    std::vector<Rewrite_exprContext *> rewrite_expr();
    Rewrite_exprContext* rewrite_expr(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Edge_srcContext : public Rewrite_exprContext {
  public:
    Edge_srcContext(Rewrite_exprContext *ctx);

    simple_graph_grammarParser::Rewrite_exprContext *edgeVar = nullptr;
    Rewrite_exprContext *rewrite_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Edge_dstContext : public Rewrite_exprContext {
  public:
    Edge_dstContext(Rewrite_exprContext *ctx);

    simple_graph_grammarParser::Rewrite_exprContext *edgeVar = nullptr;
    Rewrite_exprContext *rewrite_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Node_or_edgeContext : public Rewrite_exprContext {
  public:
    Node_or_edgeContext(Rewrite_exprContext *ctx);

    antlr4::tree::TerminalNode *OTHERS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Node_xiContext : public Rewrite_exprContext {
  public:
    Node_xiContext(Rewrite_exprContext *ctx);

    antlr4::Token *num = nullptr;
    simple_graph_grammarParser::Rewrite_exprContext *nodeVar = nullptr;
    antlr4::tree::TerminalNode *OTHERS();
    Rewrite_exprContext *rewrite_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Just_parContext : public Rewrite_exprContext {
  public:
    Just_parContext(Rewrite_exprContext *ctx);

    antlr4::tree::TerminalNode *LPAR();
    Rewrite_exprContext *rewrite_expr();
    antlr4::tree::TerminalNode *RPAR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Node_ellContext : public Rewrite_exprContext {
  public:
    Node_ellContext(Rewrite_exprContext *ctx);

    antlr4::Token *num = nullptr;
    simple_graph_grammarParser::Rewrite_exprContext *nodeVar = nullptr;
    antlr4::tree::TerminalNode *OTHERS();
    Rewrite_exprContext *rewrite_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Edge_labelContext : public Rewrite_exprContext {
  public:
    Edge_labelContext(Rewrite_exprContext *ctx);

    simple_graph_grammarParser::Rewrite_exprContext *edgeVar = nullptr;
    Rewrite_exprContext *rewrite_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ScriptContext : public Rewrite_exprContext {
  public:
    ScriptContext(Rewrite_exprContext *ctx);

    antlr4::tree::TerminalNode *EscapedString();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Rewrite_exprContext* rewrite_expr();

  class  Test_exprContext : public antlr4::ParserRuleContext {
  public:
    Test_exprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Test_exprContext() = default;
    void copyFrom(Test_exprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Leq_testContext : public Test_exprContext {
  public:
    Leq_testContext(Test_exprContext *ctx);

    simple_graph_grammarParser::Test_expr_sideContext *src = nullptr;
    simple_graph_grammarParser::Test_expr_sideContext *dst = nullptr;
    std::vector<Test_expr_sideContext *> test_expr_side();
    Test_expr_sideContext* test_expr_side(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Script_testContext : public Test_exprContext {
  public:
    Script_testContext(Test_exprContext *ctx);

    antlr4::tree::TerminalNode *EscapedString();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Or_testContext : public Test_exprContext {
  public:
    Or_testContext(Test_exprContext *ctx);

    simple_graph_grammarParser::Test_exprContext *src = nullptr;
    simple_graph_grammarParser::Test_exprContext *dst = nullptr;
    std::vector<Test_exprContext *> test_expr();
    Test_exprContext* test_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Par_testContext : public Test_exprContext {
  public:
    Par_testContext(Test_exprContext *ctx);

    antlr4::tree::TerminalNode *LPAR();
    Test_exprContext *test_expr();
    antlr4::tree::TerminalNode *RPAR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatchedContext : public Test_exprContext {
  public:
    MatchedContext(Test_exprContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> OTHERS();
    antlr4::tree::TerminalNode* OTHERS(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Eq_testContext : public Test_exprContext {
  public:
    Eq_testContext(Test_exprContext *ctx);

    simple_graph_grammarParser::Test_expr_sideContext *src = nullptr;
    simple_graph_grammarParser::Test_expr_sideContext *dst = nullptr;
    antlr4::tree::TerminalNode *EQ();
    std::vector<Test_expr_sideContext *> test_expr_side();
    Test_expr_sideContext* test_expr_side(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Neq_testContext : public Test_exprContext {
  public:
    Neq_testContext(Test_exprContext *ctx);

    simple_graph_grammarParser::Test_expr_sideContext *src = nullptr;
    simple_graph_grammarParser::Test_expr_sideContext *dst = nullptr;
    std::vector<Test_expr_sideContext *> test_expr_side();
    Test_expr_sideContext* test_expr_side(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Lt_testContext : public Test_exprContext {
  public:
    Lt_testContext(Test_exprContext *ctx);

    simple_graph_grammarParser::Test_expr_sideContext *src = nullptr;
    simple_graph_grammarParser::Test_expr_sideContext *dst = nullptr;
    std::vector<Test_expr_sideContext *> test_expr_side();
    Test_expr_sideContext* test_expr_side(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnmatchedContext : public Test_exprContext {
  public:
    UnmatchedContext(Test_exprContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> OTHERS();
    antlr4::tree::TerminalNode* OTHERS(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  And_testContext : public Test_exprContext {
  public:
    And_testContext(Test_exprContext *ctx);

    simple_graph_grammarParser::Test_exprContext *src = nullptr;
    simple_graph_grammarParser::Test_exprContext *dst = nullptr;
    std::vector<Test_exprContext *> test_expr();
    Test_exprContext* test_expr(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Test_exprContext* test_expr();
  Test_exprContext* test_expr(int precedence);
  class  Test_expr_sideContext : public antlr4::ParserRuleContext {
  public:
    Test_expr_sideContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Test_expr_sideContext() = default;
    void copyFrom(Test_expr_sideContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Test_dataContext : public Test_expr_sideContext {
  public:
    Test_dataContext(Test_expr_sideContext *ctx);

    Rewrite_exprContext *rewrite_expr();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Test_valueContext : public Test_expr_sideContext {
  public:
    Test_valueContext(Test_expr_sideContext *ctx);

    antlr4::tree::TerminalNode *OTHERS();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Test_expr_sideContext* test_expr_side();

  class  EdgeContext : public antlr4::ParserRuleContext {
  public:
    EdgeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    EdgeContext() = default;
    void copyFrom(EdgeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  HookContext : public EdgeContext {
  public:
    HookContext(EdgeContext *ctx);

    EdgelabelContext *edgelabel();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OutedgeContext : public EdgeContext {
  public:
    OutedgeContext(EdgeContext *ctx);

    EdgelabelContext *edgelabel();
    NodeContext *node();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InedgeContext : public EdgeContext {
  public:
    InedgeContext(EdgeContext *ctx);

    EdgelabelContext *edgelabel();
    NodeContext *node();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  EdgeContext* edge();

  class  Edge_joiningContext : public antlr4::ParserRuleContext {
  public:
    Edge_joiningContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NodeContext *node();
    EdgeContext *edge();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Edge_joiningContext* edge_joining();

  class  EdgelabelContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *var = nullptr;
    EdgelabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QPAR();
    antlr4::tree::TerminalNode *PPAR();
    antlr4::tree::TerminalNode *COL();
    Multiple_labelsContext *multiple_labels();
    antlr4::tree::TerminalNode *OTHERS();
    antlr4::tree::TerminalNode *FORALL();
    antlr4::tree::TerminalNode *QM();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EdgelabelContext* edgelabel();

  class  Multiple_labelsContext : public antlr4::ParserRuleContext {
  public:
    Multiple_labelsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> OTHERS();
    antlr4::tree::TerminalNode* OTHERS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Multiple_labelsContext* multiple_labels();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool test_exprSempred(Test_exprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

