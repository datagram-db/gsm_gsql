
// Generated from antlr4/script/script.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  scriptLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, TYPEOF = 44, 
    SIGMA = 45, ASSERT = 46, STRINGT = 47, DOUBLET = 48, BOOLT = 49, INTT = 50, 
    START = 51, KIND = 52, LISTT = 53, SUBTYPE = 54, ALPAREN = 55, ARPAREN = 56, 
    LPAREN = 57, RPAREN = 58, BOOL = 59, AND_TYPE = 60, OR_TYPE = 61, FUN = 62, 
    NOT = 63, IF = 64, THEN = 65, ELSE = 66, REMOVE = 67, FROM = 68, LOG = 69, 
    POW = 70, SIN = 71, COS = 72, TAN = 73, PHI = 74, ELL = 75, XI = 76, 
    INJ = 77, OBJ = 78, FLAT = 79, SELFX = 80, VARPHI = 81, CROSS = 82, 
    SCRIPT = 83, GSQL = 84, CREATEDB = 85, VARNAME = 86, CREATE = 87, ELECT = 88, 
    MAP = 89, DISJOINT = 90, FOLD = 91, EscapedString = 92, NUMBER = 93, 
    INTEGER = 94, SPACE = 95, COMMENT = 96, LINE_COMMENT = 97
  };

  explicit scriptLexer(antlr4::CharStream *input);

  ~scriptLexer() override;


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

