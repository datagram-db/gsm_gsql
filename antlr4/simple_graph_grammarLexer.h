
// Generated from antlr4/simple_graph_grammar.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  simple_graph_grammarLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, IF = 19, THEN = 20, 
    ELSE = 21, AS = 22, VEC = 23, REWRITE_TO = 24, FORALL = 25, QM = 26, 
    EQ = 27, STAR = 28, LPAR = 29, RPAR = 30, COL = 31, QPAR = 32, PPAR = 33, 
    OTHERS = 34, SPACE = 35, COMMENT = 36, LINE_COMMENT = 37
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

