
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
    VOID = 45, BOT = 46, COERCE = 47, ObjT = 48, TYPEOF = 49, SIGMA = 50, 
    ASSERT = 51, STRINGT = 52, LABELT = 53, DOUBLET = 54, ANYT = 55, BOOLT = 56, 
    INTT = 57, START = 58, KIND = 59, LISTT = 60, SUBTYPE = 61, ALPAREN = 62, 
    ARPAREN = 63, LPAREN = 64, RPAREN = 65, BOOL = 66, AND_TYPE = 67, OR_TYPE = 68, 
    FUN = 69, NOT = 70, IF = 71, THEN = 72, ELSE = 73, REMOVE = 74, FROM = 75, 
    LOG = 76, POW = 77, SIN = 78, COS = 79, TAN = 80, PHI = 81, ELL = 82, 
    XI = 83, INJ = 84, OBJ = 85, FLAT = 86, SELFX = 87, VARPHI = 88, CROSS = 89, 
    SCRIPT = 90, GSQL = 91, CREATEDB = 92, VARNAME = 93, CREATE = 94, ELECT = 95, 
    MAP = 96, DISJOINT = 97, FOLD = 98, ENFORCE = 99, EscapedString = 100, 
    NUMBER = 101, INTEGER = 102, SPACE = 103, COMMENT = 104, LINE_COMMENT = 105
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

