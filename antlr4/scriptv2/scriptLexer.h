
// Generated from antlr4/scriptv2/script.g4 by ANTLR 4.11.1

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
    T__44 = 45, T__45 = 46, T__46 = 47, T__47 = 48, T__48 = 49, T__49 = 50, 
    T__50 = 51, VOID = 52, BOT = 53, COERCE = 54, ObjT = 55, TYPEOF = 56, 
    SIGMA = 57, ASSERT = 58, STRINGT = 59, LABELT = 60, DOUBLET = 61, ANYT = 62, 
    BOOLT = 63, INTT = 64, START = 65, KIND = 66, LISTT = 67, SUBTYPE = 68, 
    ALPAREN = 69, ARPAREN = 70, LPAREN = 71, RPAREN = 72, BOOL = 73, AND_TYPE = 74, 
    OR_TYPE = 75, FUN = 76, NOT = 77, LOG = 78, POW = 79, SIN = 80, COS = 81, 
    TAN = 82, PHI = 83, ELL = 84, XI = 85, INJ = 86, OBJ = 87, FLAT = 88, 
    SELFX = 89, ZIP = 90, VARPHI = 91, CROSS = 92, VARNAME = 93, ENFORCE = 94, 
    EscapedString = 95, NUMBER = 96, INTEGER = 97, SPACE = 98, COMMENT = 99, 
    LINE_COMMENT = 100
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

