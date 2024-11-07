
// Generated from antlr4/graph_grammar/simple_graph_grammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  simple_graph_grammarLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, WHERE = 32, 
    IF = 33, THEN = 34, ELSE = 35, AS = 36, VEC = 37, REWRITE_TO = 38, FORALL = 39, 
    QM = 40, EQ = 41, STAR = 42, LPAR = 43, RPAR = 44, COL = 45, QPAR = 46, 
    PPAR = 47, EscapedString = 48, OTHERS = 49, SPACE = 50, COMMENT = 51, 
    LINE_COMMENT = 52
  };

  explicit simple_graph_grammarLexer(antlr4::CharStream *input);

  ~simple_graph_grammarLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

