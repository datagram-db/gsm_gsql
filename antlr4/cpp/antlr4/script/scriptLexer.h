
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
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    COERCE = 45, LEXT = 46, TYPEOF = 47, SIGMA = 48, ASSERT = 49, STRINGT = 50, 
    LABELT = 51, DOUBLET = 52, BOOLT = 53, INTT = 54, START = 55, KIND = 56, 
    LISTT = 57, SUBTYPE = 58, ALPAREN = 59, ARPAREN = 60, LPAREN = 61, RPAREN = 62, 
    BOOL = 63, AND_TYPE = 64, OR_TYPE = 65, FUN = 66, NOT = 67, IF = 68, 
    THEN = 69, ELSE = 70, REMOVE = 71, FROM = 72, LOG = 73, POW = 74, SIN = 75, 
    COS = 76, TAN = 77, PHI = 78, ELL = 79, XI = 80, INJ = 81, OBJ = 82, 
    FLAT = 83, SELFX = 84, VARPHI = 85, CROSS = 86, SCRIPT = 87, GSQL = 88, 
    CREATEDB = 89, VARNAME = 90, CREATE = 91, ELECT = 92, MAP = 93, DISJOINT = 94, 
    FOLD = 95, ENFORCE = 96, EscapedString = 97, NUMBER = 98, INTEGER = 99, 
    SPACE = 100, COMMENT = 101, LINE_COMMENT = 102
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

