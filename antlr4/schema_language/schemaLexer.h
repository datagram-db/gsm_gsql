
// Generated from antlr4/schema_language/schema.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  schemaLexer : public antlr4::Lexer {
public:
  enum {
    SCORE = 1, TAG = 2, PROPERTY = 3, MULTI = 4, FROM = 5, FILE = 6, CSV = 7, 
    XML = 8, JSON = 9, LJSON = 10, WITH_HEADER = 11, SEP = 12, String = 13, 
    UInt = 14, Int = 15, Double = 16, LPAR = 17, RPAR = 18, LCOLL = 19, 
    RCOLL = 20, COMMA = 21, MAP = 22, COMMENT = 23, DOT = 24, EQ = 25, TYPE_SEP = 26, 
    OFTYPE = 27, STAR = 28, LINE_COMMENT = 29, WS = 30, EscapedString = 31, 
    WORD = 32
  };

  explicit schemaLexer(antlr4::CharStream *input);

  ~schemaLexer() override;


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

