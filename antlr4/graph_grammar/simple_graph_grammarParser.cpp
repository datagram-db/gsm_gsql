
// Generated from antlr4/graph_grammar/simple_graph_grammar.g4 by ANTLR 4.11.1


#include "simple_graph_grammarListener.h"
#include "simple_graph_grammarVisitor.h"

#include "simple_graph_grammarParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Simple_graph_grammarParserStaticData final {
  Simple_graph_grammarParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Simple_graph_grammarParserStaticData(const Simple_graph_grammarParserStaticData&) = delete;
  Simple_graph_grammarParserStaticData(Simple_graph_grammarParserStaticData&&) = delete;
  Simple_graph_grammarParserStaticData& operator=(const Simple_graph_grammarParserStaticData&) = delete;
  Simple_graph_grammarParserStaticData& operator=(Simple_graph_grammarParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag simple_graph_grammarParserOnceFlag;
Simple_graph_grammarParserStaticData *simple_graph_grammarParserStaticData = nullptr;

void simple_graph_grammarParserInitialize() {
  assert(simple_graph_grammarParserStaticData == nullptr);
  auto staticData = std::make_unique<Simple_graph_grammarParserStaticData>(
    std::vector<std::string>{
      "all_matches", "node", "centralmatch", "many_edges", "rewrite_to", 
      "rewrite_expr", "test_expr", "test_expr_side", "edge", "edge_joining", 
      "edgelabel", "multiple_labels"
    },
    std::vector<std::string>{
      "", "';'", "'del'", "'new'", "'set'", "'\\U0001D709'", "'@'", "'\\u2113'", 
      "'\\U0001D70B'", "'\\u03C6'", "','", "'label'", "'src'", "'dst'", 
      "'SCRIPT'", "'\\u2260'", "'<'", "'\\u2264'", "'\\u2228'", "'\\u2227'", 
      "'TEST'", "'unmatched'", "'.'", "'matched'", "'FILL'", "'--'", "'->'", 
      "'<-'", "'hook'", "'||'", "'where'", "'if'", "'then'", "'else'", "'as'", 
      "'>>'", "'\\u21AA'", "'\\u2200'", "'\\u003F'", "'='", "'*'", "'('", 
      "')'", "':'", "'['", "']'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "WHERE", "IF", 
      "THEN", "ELSE", "AS", "VEC", "REWRITE_TO", "FORALL", "QM", "EQ", "STAR", 
      "LPAR", "RPAR", "COL", "QPAR", "PPAR", "EscapedString", "OTHERS", 
      "SPACE", "COMMENT", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,50,230,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,5,0,28,8,0,10,0,
  	12,0,31,9,0,1,0,1,0,1,1,1,1,3,1,37,8,1,1,1,3,1,40,8,1,1,1,1,1,1,1,3,1,
  	45,8,1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,53,8,2,1,2,5,2,56,8,2,10,2,12,2,59,
  	9,2,1,2,1,2,3,2,63,8,2,1,2,1,2,5,2,67,8,2,10,2,12,2,70,9,2,1,2,3,2,73,
  	8,2,1,3,4,3,76,8,3,11,3,12,3,77,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,
  	4,89,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,
  	5,123,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,132,8,5,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,169,8,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,5,6,177,8,6,10,6,12,6,180,9,6,1,7,1,7,3,7,184,8,7,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,200,8,8,1,9,1,
  	9,1,9,1,10,1,10,3,10,207,8,10,1,10,3,10,210,8,10,1,10,1,10,3,10,214,8,
  	10,1,10,3,10,217,8,10,1,10,1,10,1,11,1,11,5,11,223,8,11,10,11,12,11,226,
  	9,11,1,11,1,11,1,11,0,1,12,12,0,2,4,6,8,10,12,14,16,18,20,22,0,0,258,
  	0,29,1,0,0,0,2,34,1,0,0,0,4,48,1,0,0,0,6,75,1,0,0,0,8,88,1,0,0,0,10,131,
  	1,0,0,0,12,168,1,0,0,0,14,183,1,0,0,0,16,199,1,0,0,0,18,201,1,0,0,0,20,
  	204,1,0,0,0,22,224,1,0,0,0,24,25,3,4,2,0,25,26,5,1,0,0,26,28,1,0,0,0,
  	27,24,1,0,0,0,28,31,1,0,0,0,29,27,1,0,0,0,29,30,1,0,0,0,30,32,1,0,0,0,
  	31,29,1,0,0,0,32,33,3,4,2,0,33,1,1,0,0,0,34,36,5,41,0,0,35,37,5,40,0,
  	0,36,35,1,0,0,0,36,37,1,0,0,0,37,39,1,0,0,0,38,40,5,35,0,0,39,38,1,0,
  	0,0,39,40,1,0,0,0,40,41,1,0,0,0,41,44,3,22,11,0,42,43,5,43,0,0,43,45,
  	5,47,0,0,44,42,1,0,0,0,44,45,1,0,0,0,45,46,1,0,0,0,46,47,5,42,0,0,47,
  	3,1,0,0,0,48,49,5,47,0,0,49,50,5,39,0,0,50,52,3,2,1,0,51,53,3,6,3,0,52,
  	51,1,0,0,0,52,53,1,0,0,0,53,57,1,0,0,0,54,56,3,18,9,0,55,54,1,0,0,0,56,
  	59,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,62,1,0,0,0,59,57,1,0,0,0,60,
  	61,5,30,0,0,61,63,3,12,6,0,62,60,1,0,0,0,62,63,1,0,0,0,63,72,1,0,0,0,
  	64,68,5,36,0,0,65,67,3,8,4,0,66,65,1,0,0,0,67,70,1,0,0,0,68,66,1,0,0,
  	0,68,69,1,0,0,0,69,71,1,0,0,0,70,68,1,0,0,0,71,73,3,2,1,0,72,64,1,0,0,
  	0,72,73,1,0,0,0,73,5,1,0,0,0,74,76,3,16,8,0,75,74,1,0,0,0,76,77,1,0,0,
  	0,77,75,1,0,0,0,77,78,1,0,0,0,78,7,1,0,0,0,79,80,5,2,0,0,80,89,5,47,0,
  	0,81,82,5,3,0,0,82,89,5,47,0,0,83,84,5,4,0,0,84,85,3,10,5,0,85,86,5,34,
  	0,0,86,87,3,10,5,0,87,89,1,0,0,0,88,79,1,0,0,0,88,81,1,0,0,0,88,83,1,
  	0,0,0,89,9,1,0,0,0,90,91,5,5,0,0,91,92,5,47,0,0,92,93,5,6,0,0,93,132,
  	3,10,5,0,94,95,5,7,0,0,95,96,5,47,0,0,96,97,5,6,0,0,97,132,3,10,5,0,98,
  	99,5,8,0,0,99,100,3,10,5,0,100,101,5,6,0,0,101,102,3,10,5,0,102,132,1,
  	0,0,0,103,104,5,9,0,0,104,105,3,10,5,0,105,106,5,10,0,0,106,107,3,10,
  	5,0,107,132,1,0,0,0,108,109,5,11,0,0,109,132,3,10,5,0,110,111,5,12,0,
  	0,111,132,3,10,5,0,112,113,5,13,0,0,113,132,3,10,5,0,114,115,5,31,0,0,
  	115,116,5,41,0,0,116,117,3,12,6,0,117,118,5,42,0,0,118,119,5,32,0,0,119,
  	122,3,10,5,0,120,121,5,33,0,0,121,123,3,10,5,0,122,120,1,0,0,0,122,123,
  	1,0,0,0,123,132,1,0,0,0,124,132,5,47,0,0,125,126,5,41,0,0,126,127,3,10,
  	5,0,127,128,5,42,0,0,128,132,1,0,0,0,129,130,5,14,0,0,130,132,5,46,0,
  	0,131,90,1,0,0,0,131,94,1,0,0,0,131,98,1,0,0,0,131,103,1,0,0,0,131,108,
  	1,0,0,0,131,110,1,0,0,0,131,112,1,0,0,0,131,114,1,0,0,0,131,124,1,0,0,
  	0,131,125,1,0,0,0,131,129,1,0,0,0,132,11,1,0,0,0,133,134,6,6,-1,0,134,
  	135,3,14,7,0,135,136,5,39,0,0,136,137,3,14,7,0,137,169,1,0,0,0,138,139,
  	3,14,7,0,139,140,5,15,0,0,140,141,3,14,7,0,141,169,1,0,0,0,142,143,3,
  	14,7,0,143,144,5,16,0,0,144,145,3,14,7,0,145,169,1,0,0,0,146,147,3,14,
  	7,0,147,148,5,17,0,0,148,149,3,14,7,0,149,169,1,0,0,0,150,151,5,41,0,
  	0,151,152,3,12,6,0,152,153,5,42,0,0,153,169,1,0,0,0,154,155,5,20,0,0,
  	155,169,5,46,0,0,156,157,5,47,0,0,157,158,5,21,0,0,158,159,5,47,0,0,159,
  	160,5,22,0,0,160,169,5,47,0,0,161,162,5,47,0,0,162,163,5,23,0,0,163,164,
  	5,47,0,0,164,165,5,22,0,0,165,169,5,47,0,0,166,167,5,24,0,0,167,169,3,
  	12,6,1,168,133,1,0,0,0,168,138,1,0,0,0,168,142,1,0,0,0,168,146,1,0,0,
  	0,168,150,1,0,0,0,168,154,1,0,0,0,168,156,1,0,0,0,168,161,1,0,0,0,168,
  	166,1,0,0,0,169,178,1,0,0,0,170,171,10,7,0,0,171,172,5,18,0,0,172,177,
  	3,12,6,8,173,174,10,6,0,0,174,175,5,19,0,0,175,177,3,12,6,7,176,170,1,
  	0,0,0,176,173,1,0,0,0,177,180,1,0,0,0,178,176,1,0,0,0,178,179,1,0,0,0,
  	179,13,1,0,0,0,180,178,1,0,0,0,181,184,3,10,5,0,182,184,5,47,0,0,183,
  	181,1,0,0,0,183,182,1,0,0,0,184,15,1,0,0,0,185,186,5,25,0,0,186,187,3,
  	20,10,0,187,188,5,26,0,0,188,189,3,2,1,0,189,200,1,0,0,0,190,191,5,27,
  	0,0,191,192,3,20,10,0,192,193,5,25,0,0,193,194,3,2,1,0,194,200,1,0,0,
  	0,195,196,5,25,0,0,196,197,3,20,10,0,197,198,5,28,0,0,198,200,1,0,0,0,
  	199,185,1,0,0,0,199,190,1,0,0,0,199,195,1,0,0,0,200,17,1,0,0,0,201,202,
  	3,2,1,0,202,203,3,16,8,0,203,19,1,0,0,0,204,206,5,44,0,0,205,207,5,37,
  	0,0,206,205,1,0,0,0,206,207,1,0,0,0,207,209,1,0,0,0,208,210,5,38,0,0,
  	209,208,1,0,0,0,209,210,1,0,0,0,210,213,1,0,0,0,211,212,5,47,0,0,212,
  	214,5,43,0,0,213,211,1,0,0,0,213,214,1,0,0,0,214,216,1,0,0,0,215,217,
  	3,22,11,0,216,215,1,0,0,0,216,217,1,0,0,0,217,218,1,0,0,0,218,219,5,45,
  	0,0,219,21,1,0,0,0,220,221,5,47,0,0,221,223,5,29,0,0,222,220,1,0,0,0,
  	223,226,1,0,0,0,224,222,1,0,0,0,224,225,1,0,0,0,225,227,1,0,0,0,226,224,
  	1,0,0,0,227,228,5,47,0,0,228,23,1,0,0,0,23,29,36,39,44,52,57,62,68,72,
  	77,88,122,131,168,176,178,183,199,206,209,213,216,224
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  simple_graph_grammarParserStaticData = staticData.release();
}

}

simple_graph_grammarParser::simple_graph_grammarParser(TokenStream *input) : simple_graph_grammarParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

simple_graph_grammarParser::simple_graph_grammarParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  simple_graph_grammarParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *simple_graph_grammarParserStaticData->atn, simple_graph_grammarParserStaticData->decisionToDFA, simple_graph_grammarParserStaticData->sharedContextCache, options);
}

simple_graph_grammarParser::~simple_graph_grammarParser() {
  delete _interpreter;
}

const atn::ATN& simple_graph_grammarParser::getATN() const {
  return *simple_graph_grammarParserStaticData->atn;
}

std::string simple_graph_grammarParser::getGrammarFileName() const {
  return "simple_graph_grammar.g4";
}

const std::vector<std::string>& simple_graph_grammarParser::getRuleNames() const {
  return simple_graph_grammarParserStaticData->ruleNames;
}

const dfa::Vocabulary& simple_graph_grammarParser::getVocabulary() const {
  return simple_graph_grammarParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView simple_graph_grammarParser::getSerializedATN() const {
  return simple_graph_grammarParserStaticData->serializedATN;
}


//----------------- All_matchesContext ------------------------------------------------------------------

simple_graph_grammarParser::All_matchesContext::All_matchesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<simple_graph_grammarParser::CentralmatchContext *> simple_graph_grammarParser::All_matchesContext::centralmatch() {
  return getRuleContexts<simple_graph_grammarParser::CentralmatchContext>();
}

simple_graph_grammarParser::CentralmatchContext* simple_graph_grammarParser::All_matchesContext::centralmatch(size_t i) {
  return getRuleContext<simple_graph_grammarParser::CentralmatchContext>(i);
}


size_t simple_graph_grammarParser::All_matchesContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleAll_matches;
}

void simple_graph_grammarParser::All_matchesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAll_matches(this);
}

void simple_graph_grammarParser::All_matchesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAll_matches(this);
}


std::any simple_graph_grammarParser::All_matchesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitAll_matches(this);
  else
    return visitor->visitChildren(this);
}

simple_graph_grammarParser::All_matchesContext* simple_graph_grammarParser::all_matches() {
  All_matchesContext *_localctx = _tracker.createInstance<All_matchesContext>(_ctx, getState());
  enterRule(_localctx, 0, simple_graph_grammarParser::RuleAll_matches);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(29);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(24);
        centralmatch();
        setState(25);
        match(simple_graph_grammarParser::T__0); 
      }
      setState(31);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(32);
    centralmatch();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NodeContext ------------------------------------------------------------------

simple_graph_grammarParser::NodeContext::NodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* simple_graph_grammarParser::NodeContext::LPAR() {
  return getToken(simple_graph_grammarParser::LPAR, 0);
}

tree::TerminalNode* simple_graph_grammarParser::NodeContext::RPAR() {
  return getToken(simple_graph_grammarParser::RPAR, 0);
}

simple_graph_grammarParser::Multiple_labelsContext* simple_graph_grammarParser::NodeContext::multiple_labels() {
  return getRuleContext<simple_graph_grammarParser::Multiple_labelsContext>(0);
}

tree::TerminalNode* simple_graph_grammarParser::NodeContext::STAR() {
  return getToken(simple_graph_grammarParser::STAR, 0);
}

tree::TerminalNode* simple_graph_grammarParser::NodeContext::VEC() {
  return getToken(simple_graph_grammarParser::VEC, 0);
}

tree::TerminalNode* simple_graph_grammarParser::NodeContext::COL() {
  return getToken(simple_graph_grammarParser::COL, 0);
}

tree::TerminalNode* simple_graph_grammarParser::NodeContext::OTHERS() {
  return getToken(simple_graph_grammarParser::OTHERS, 0);
}


size_t simple_graph_grammarParser::NodeContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleNode;
}

void simple_graph_grammarParser::NodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode(this);
}

void simple_graph_grammarParser::NodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode(this);
}


std::any simple_graph_grammarParser::NodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitNode(this);
  else
    return visitor->visitChildren(this);
}

simple_graph_grammarParser::NodeContext* simple_graph_grammarParser::node() {
  NodeContext *_localctx = _tracker.createInstance<NodeContext>(_ctx, getState());
  enterRule(_localctx, 2, simple_graph_grammarParser::RuleNode);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(34);
    match(simple_graph_grammarParser::LPAR);
    setState(36);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::STAR) {
      setState(35);
      match(simple_graph_grammarParser::STAR);
    }
    setState(39);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::VEC) {
      setState(38);
      match(simple_graph_grammarParser::VEC);
    }
    setState(41);
    antlrcpp::downCast<NodeContext *>(_localctx)->var = multiple_labels();
    setState(44);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::COL) {
      setState(42);
      match(simple_graph_grammarParser::COL);
      setState(43);
      match(simple_graph_grammarParser::OTHERS);
    }
    setState(46);
    match(simple_graph_grammarParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CentralmatchContext ------------------------------------------------------------------

simple_graph_grammarParser::CentralmatchContext::CentralmatchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* simple_graph_grammarParser::CentralmatchContext::EQ() {
  return getToken(simple_graph_grammarParser::EQ, 0);
}

tree::TerminalNode* simple_graph_grammarParser::CentralmatchContext::OTHERS() {
  return getToken(simple_graph_grammarParser::OTHERS, 0);
}

std::vector<simple_graph_grammarParser::NodeContext *> simple_graph_grammarParser::CentralmatchContext::node() {
  return getRuleContexts<simple_graph_grammarParser::NodeContext>();
}

simple_graph_grammarParser::NodeContext* simple_graph_grammarParser::CentralmatchContext::node(size_t i) {
  return getRuleContext<simple_graph_grammarParser::NodeContext>(i);
}

std::vector<simple_graph_grammarParser::Edge_joiningContext *> simple_graph_grammarParser::CentralmatchContext::edge_joining() {
  return getRuleContexts<simple_graph_grammarParser::Edge_joiningContext>();
}

simple_graph_grammarParser::Edge_joiningContext* simple_graph_grammarParser::CentralmatchContext::edge_joining(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Edge_joiningContext>(i);
}

tree::TerminalNode* simple_graph_grammarParser::CentralmatchContext::WHERE() {
  return getToken(simple_graph_grammarParser::WHERE, 0);
}

simple_graph_grammarParser::Test_exprContext* simple_graph_grammarParser::CentralmatchContext::test_expr() {
  return getRuleContext<simple_graph_grammarParser::Test_exprContext>(0);
}

tree::TerminalNode* simple_graph_grammarParser::CentralmatchContext::REWRITE_TO() {
  return getToken(simple_graph_grammarParser::REWRITE_TO, 0);
}

simple_graph_grammarParser::Many_edgesContext* simple_graph_grammarParser::CentralmatchContext::many_edges() {
  return getRuleContext<simple_graph_grammarParser::Many_edgesContext>(0);
}

std::vector<simple_graph_grammarParser::Rewrite_toContext *> simple_graph_grammarParser::CentralmatchContext::rewrite_to() {
  return getRuleContexts<simple_graph_grammarParser::Rewrite_toContext>();
}

simple_graph_grammarParser::Rewrite_toContext* simple_graph_grammarParser::CentralmatchContext::rewrite_to(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Rewrite_toContext>(i);
}


size_t simple_graph_grammarParser::CentralmatchContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleCentralmatch;
}

void simple_graph_grammarParser::CentralmatchContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCentralmatch(this);
}

void simple_graph_grammarParser::CentralmatchContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCentralmatch(this);
}


std::any simple_graph_grammarParser::CentralmatchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitCentralmatch(this);
  else
    return visitor->visitChildren(this);
}

simple_graph_grammarParser::CentralmatchContext* simple_graph_grammarParser::centralmatch() {
  CentralmatchContext *_localctx = _tracker.createInstance<CentralmatchContext>(_ctx, getState());
  enterRule(_localctx, 4, simple_graph_grammarParser::RuleCentralmatch);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    antlrcpp::downCast<CentralmatchContext *>(_localctx)->var = match(simple_graph_grammarParser::OTHERS);
    setState(49);
    match(simple_graph_grammarParser::EQ);
    setState(50);
    antlrcpp::downCast<CentralmatchContext *>(_localctx)->src = node();
    setState(52);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::T__24

    || _la == simple_graph_grammarParser::T__26) {
      setState(51);
      antlrcpp::downCast<CentralmatchContext *>(_localctx)->e1 = many_edges();
    }
    setState(57);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == simple_graph_grammarParser::LPAR) {
      setState(54);
      edge_joining();
      setState(59);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(62);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::WHERE) {
      setState(60);
      match(simple_graph_grammarParser::WHERE);
      setState(61);
      test_expr(0);
    }
    setState(72);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::REWRITE_TO) {
      setState(64);
      match(simple_graph_grammarParser::REWRITE_TO);
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 28) != 0) {
        setState(65);
        rewrite_to();
        setState(70);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(71);
      antlrcpp::downCast<CentralmatchContext *>(_localctx)->dst = node();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Many_edgesContext ------------------------------------------------------------------

simple_graph_grammarParser::Many_edgesContext::Many_edgesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<simple_graph_grammarParser::EdgeContext *> simple_graph_grammarParser::Many_edgesContext::edge() {
  return getRuleContexts<simple_graph_grammarParser::EdgeContext>();
}

simple_graph_grammarParser::EdgeContext* simple_graph_grammarParser::Many_edgesContext::edge(size_t i) {
  return getRuleContext<simple_graph_grammarParser::EdgeContext>(i);
}


size_t simple_graph_grammarParser::Many_edgesContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleMany_edges;
}

void simple_graph_grammarParser::Many_edgesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMany_edges(this);
}

void simple_graph_grammarParser::Many_edgesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMany_edges(this);
}


std::any simple_graph_grammarParser::Many_edgesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitMany_edges(this);
  else
    return visitor->visitChildren(this);
}

simple_graph_grammarParser::Many_edgesContext* simple_graph_grammarParser::many_edges() {
  Many_edgesContext *_localctx = _tracker.createInstance<Many_edgesContext>(_ctx, getState());
  enterRule(_localctx, 6, simple_graph_grammarParser::RuleMany_edges);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(74);
      edge();
      setState(77); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == simple_graph_grammarParser::T__24

    || _la == simple_graph_grammarParser::T__26);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rewrite_toContext ------------------------------------------------------------------

simple_graph_grammarParser::Rewrite_toContext::Rewrite_toContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t simple_graph_grammarParser::Rewrite_toContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleRewrite_to;
}

void simple_graph_grammarParser::Rewrite_toContext::copyFrom(Rewrite_toContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Del_node_or_edgeContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Del_node_or_edgeContext::OTHERS() {
  return getToken(simple_graph_grammarParser::OTHERS, 0);
}

simple_graph_grammarParser::Del_node_or_edgeContext::Del_node_or_edgeContext(Rewrite_toContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Del_node_or_edgeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDel_node_or_edge(this);
}
void simple_graph_grammarParser::Del_node_or_edgeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDel_node_or_edge(this);
}

std::any simple_graph_grammarParser::Del_node_or_edgeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitDel_node_or_edge(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Update_exprContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Update_exprContext::AS() {
  return getToken(simple_graph_grammarParser::AS, 0);
}

std::vector<simple_graph_grammarParser::Rewrite_exprContext *> simple_graph_grammarParser::Update_exprContext::rewrite_expr() {
  return getRuleContexts<simple_graph_grammarParser::Rewrite_exprContext>();
}

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Update_exprContext::rewrite_expr(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(i);
}

simple_graph_grammarParser::Update_exprContext::Update_exprContext(Rewrite_toContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Update_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdate_expr(this);
}
void simple_graph_grammarParser::Update_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdate_expr(this);
}

std::any simple_graph_grammarParser::Update_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitUpdate_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Neu_objContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Neu_objContext::OTHERS() {
  return getToken(simple_graph_grammarParser::OTHERS, 0);
}

simple_graph_grammarParser::Neu_objContext::Neu_objContext(Rewrite_toContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Neu_objContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNeu_obj(this);
}
void simple_graph_grammarParser::Neu_objContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNeu_obj(this);
}

std::any simple_graph_grammarParser::Neu_objContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitNeu_obj(this);
  else
    return visitor->visitChildren(this);
}
simple_graph_grammarParser::Rewrite_toContext* simple_graph_grammarParser::rewrite_to() {
  Rewrite_toContext *_localctx = _tracker.createInstance<Rewrite_toContext>(_ctx, getState());
  enterRule(_localctx, 8, simple_graph_grammarParser::RuleRewrite_to);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(88);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case simple_graph_grammarParser::T__1: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Del_node_or_edgeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(79);
        match(simple_graph_grammarParser::T__1);
        setState(80);
        match(simple_graph_grammarParser::OTHERS);
        break;
      }

      case simple_graph_grammarParser::T__2: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Neu_objContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(81);
        match(simple_graph_grammarParser::T__2);
        setState(82);
        antlrcpp::downCast<Neu_objContext *>(_localctx)->dst = match(simple_graph_grammarParser::OTHERS);
        break;
      }

      case simple_graph_grammarParser::T__3: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Update_exprContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(83);
        match(simple_graph_grammarParser::T__3);
        setState(84);
        antlrcpp::downCast<Update_exprContext *>(_localctx)->to = rewrite_expr();
        setState(85);
        match(simple_graph_grammarParser::AS);
        setState(86);
        antlrcpp::downCast<Update_exprContext *>(_localctx)->from = rewrite_expr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rewrite_exprContext ------------------------------------------------------------------

simple_graph_grammarParser::Rewrite_exprContext::Rewrite_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t simple_graph_grammarParser::Rewrite_exprContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleRewrite_expr;
}

void simple_graph_grammarParser::Rewrite_exprContext::copyFrom(Rewrite_exprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Node_containmentContext ------------------------------------------------------------------

std::vector<simple_graph_grammarParser::Rewrite_exprContext *> simple_graph_grammarParser::Node_containmentContext::rewrite_expr() {
  return getRuleContexts<simple_graph_grammarParser::Rewrite_exprContext>();
}

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Node_containmentContext::rewrite_expr(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(i);
}

simple_graph_grammarParser::Node_containmentContext::Node_containmentContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Node_containmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_containment(this);
}
void simple_graph_grammarParser::Node_containmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_containment(this);
}

std::any simple_graph_grammarParser::Node_containmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitNode_containment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Node_propContext ------------------------------------------------------------------

std::vector<simple_graph_grammarParser::Rewrite_exprContext *> simple_graph_grammarParser::Node_propContext::rewrite_expr() {
  return getRuleContexts<simple_graph_grammarParser::Rewrite_exprContext>();
}

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Node_propContext::rewrite_expr(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(i);
}

simple_graph_grammarParser::Node_propContext::Node_propContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Node_propContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_prop(this);
}
void simple_graph_grammarParser::Node_propContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_prop(this);
}

std::any simple_graph_grammarParser::Node_propContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitNode_prop(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Ifte_exprContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Ifte_exprContext::IF() {
  return getToken(simple_graph_grammarParser::IF, 0);
}

tree::TerminalNode* simple_graph_grammarParser::Ifte_exprContext::LPAR() {
  return getToken(simple_graph_grammarParser::LPAR, 0);
}

tree::TerminalNode* simple_graph_grammarParser::Ifte_exprContext::RPAR() {
  return getToken(simple_graph_grammarParser::RPAR, 0);
}

tree::TerminalNode* simple_graph_grammarParser::Ifte_exprContext::THEN() {
  return getToken(simple_graph_grammarParser::THEN, 0);
}

simple_graph_grammarParser::Test_exprContext* simple_graph_grammarParser::Ifte_exprContext::test_expr() {
  return getRuleContext<simple_graph_grammarParser::Test_exprContext>(0);
}

std::vector<simple_graph_grammarParser::Rewrite_exprContext *> simple_graph_grammarParser::Ifte_exprContext::rewrite_expr() {
  return getRuleContexts<simple_graph_grammarParser::Rewrite_exprContext>();
}

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Ifte_exprContext::rewrite_expr(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(i);
}

tree::TerminalNode* simple_graph_grammarParser::Ifte_exprContext::ELSE() {
  return getToken(simple_graph_grammarParser::ELSE, 0);
}

simple_graph_grammarParser::Ifte_exprContext::Ifte_exprContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Ifte_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfte_expr(this);
}
void simple_graph_grammarParser::Ifte_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfte_expr(this);
}

std::any simple_graph_grammarParser::Ifte_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitIfte_expr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Edge_srcContext ------------------------------------------------------------------

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Edge_srcContext::rewrite_expr() {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(0);
}

simple_graph_grammarParser::Edge_srcContext::Edge_srcContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Edge_srcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdge_src(this);
}
void simple_graph_grammarParser::Edge_srcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdge_src(this);
}

std::any simple_graph_grammarParser::Edge_srcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitEdge_src(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Edge_dstContext ------------------------------------------------------------------

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Edge_dstContext::rewrite_expr() {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(0);
}

simple_graph_grammarParser::Edge_dstContext::Edge_dstContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Edge_dstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdge_dst(this);
}
void simple_graph_grammarParser::Edge_dstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdge_dst(this);
}

std::any simple_graph_grammarParser::Edge_dstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitEdge_dst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Node_or_edgeContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Node_or_edgeContext::OTHERS() {
  return getToken(simple_graph_grammarParser::OTHERS, 0);
}

simple_graph_grammarParser::Node_or_edgeContext::Node_or_edgeContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Node_or_edgeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_or_edge(this);
}
void simple_graph_grammarParser::Node_or_edgeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_or_edge(this);
}

std::any simple_graph_grammarParser::Node_or_edgeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitNode_or_edge(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Node_xiContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Node_xiContext::OTHERS() {
  return getToken(simple_graph_grammarParser::OTHERS, 0);
}

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Node_xiContext::rewrite_expr() {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(0);
}

simple_graph_grammarParser::Node_xiContext::Node_xiContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Node_xiContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_xi(this);
}
void simple_graph_grammarParser::Node_xiContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_xi(this);
}

std::any simple_graph_grammarParser::Node_xiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitNode_xi(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Just_parContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Just_parContext::LPAR() {
  return getToken(simple_graph_grammarParser::LPAR, 0);
}

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Just_parContext::rewrite_expr() {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(0);
}

tree::TerminalNode* simple_graph_grammarParser::Just_parContext::RPAR() {
  return getToken(simple_graph_grammarParser::RPAR, 0);
}

simple_graph_grammarParser::Just_parContext::Just_parContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Just_parContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJust_par(this);
}
void simple_graph_grammarParser::Just_parContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJust_par(this);
}

std::any simple_graph_grammarParser::Just_parContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitJust_par(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Node_ellContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Node_ellContext::OTHERS() {
  return getToken(simple_graph_grammarParser::OTHERS, 0);
}

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Node_ellContext::rewrite_expr() {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(0);
}

simple_graph_grammarParser::Node_ellContext::Node_ellContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Node_ellContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNode_ell(this);
}
void simple_graph_grammarParser::Node_ellContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNode_ell(this);
}

std::any simple_graph_grammarParser::Node_ellContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitNode_ell(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Edge_labelContext ------------------------------------------------------------------

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Edge_labelContext::rewrite_expr() {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(0);
}

simple_graph_grammarParser::Edge_labelContext::Edge_labelContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Edge_labelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdge_label(this);
}
void simple_graph_grammarParser::Edge_labelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdge_label(this);
}

std::any simple_graph_grammarParser::Edge_labelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitEdge_label(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ScriptContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::ScriptContext::EscapedString() {
  return getToken(simple_graph_grammarParser::EscapedString, 0);
}

simple_graph_grammarParser::ScriptContext::ScriptContext(Rewrite_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::ScriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScript(this);
}
void simple_graph_grammarParser::ScriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScript(this);
}

std::any simple_graph_grammarParser::ScriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitScript(this);
  else
    return visitor->visitChildren(this);
}
simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::rewrite_expr() {
  Rewrite_exprContext *_localctx = _tracker.createInstance<Rewrite_exprContext>(_ctx, getState());
  enterRule(_localctx, 10, simple_graph_grammarParser::RuleRewrite_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(131);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case simple_graph_grammarParser::T__4: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Node_xiContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(90);
        match(simple_graph_grammarParser::T__4);
        setState(91);
        antlrcpp::downCast<Node_xiContext *>(_localctx)->num = match(simple_graph_grammarParser::OTHERS);
        setState(92);
        match(simple_graph_grammarParser::T__5);
        setState(93);
        antlrcpp::downCast<Node_xiContext *>(_localctx)->nodeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__6: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Node_ellContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(94);
        match(simple_graph_grammarParser::T__6);
        setState(95);
        antlrcpp::downCast<Node_ellContext *>(_localctx)->num = match(simple_graph_grammarParser::OTHERS);
        setState(96);
        match(simple_graph_grammarParser::T__5);
        setState(97);
        antlrcpp::downCast<Node_ellContext *>(_localctx)->nodeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__7: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Node_propContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(98);
        match(simple_graph_grammarParser::T__7);
        setState(99);
        antlrcpp::downCast<Node_propContext *>(_localctx)->key = rewrite_expr();
        setState(100);
        match(simple_graph_grammarParser::T__5);
        setState(101);
        antlrcpp::downCast<Node_propContext *>(_localctx)->nodeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__8: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Node_containmentContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(103);
        match(simple_graph_grammarParser::T__8);
        setState(104);
        antlrcpp::downCast<Node_containmentContext *>(_localctx)->key = rewrite_expr();
        setState(105);
        match(simple_graph_grammarParser::T__9);
        setState(106);
        antlrcpp::downCast<Node_containmentContext *>(_localctx)->nodeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__10: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Edge_labelContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(108);
        match(simple_graph_grammarParser::T__10);
        setState(109);
        antlrcpp::downCast<Edge_labelContext *>(_localctx)->edgeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__11: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Edge_srcContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(110);
        match(simple_graph_grammarParser::T__11);
        setState(111);
        antlrcpp::downCast<Edge_srcContext *>(_localctx)->edgeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__12: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Edge_dstContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(112);
        match(simple_graph_grammarParser::T__12);
        setState(113);
        antlrcpp::downCast<Edge_dstContext *>(_localctx)->edgeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::IF: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Ifte_exprContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(114);
        match(simple_graph_grammarParser::IF);
        setState(115);
        match(simple_graph_grammarParser::LPAR);
        setState(116);
        antlrcpp::downCast<Ifte_exprContext *>(_localctx)->ifcond = test_expr(0);
        setState(117);
        match(simple_graph_grammarParser::RPAR);
        setState(118);
        match(simple_graph_grammarParser::THEN);
        setState(119);
        antlrcpp::downCast<Ifte_exprContext *>(_localctx)->then_effect = rewrite_expr();
        setState(122);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          setState(120);
          match(simple_graph_grammarParser::ELSE);
          setState(121);
          antlrcpp::downCast<Ifte_exprContext *>(_localctx)->else_effect = rewrite_expr();
          break;
        }

        default:
          break;
        }
        break;
      }

      case simple_graph_grammarParser::OTHERS: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Node_or_edgeContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(124);
        match(simple_graph_grammarParser::OTHERS);
        break;
      }

      case simple_graph_grammarParser::LPAR: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Just_parContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(125);
        match(simple_graph_grammarParser::LPAR);
        setState(126);
        rewrite_expr();
        setState(127);
        match(simple_graph_grammarParser::RPAR);
        break;
      }

      case simple_graph_grammarParser::T__13: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::ScriptContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(129);
        match(simple_graph_grammarParser::T__13);
        setState(130);
        match(simple_graph_grammarParser::EscapedString);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Test_exprContext ------------------------------------------------------------------

simple_graph_grammarParser::Test_exprContext::Test_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t simple_graph_grammarParser::Test_exprContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleTest_expr;
}

void simple_graph_grammarParser::Test_exprContext::copyFrom(Test_exprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Leq_testContext ------------------------------------------------------------------

std::vector<simple_graph_grammarParser::Test_expr_sideContext *> simple_graph_grammarParser::Leq_testContext::test_expr_side() {
  return getRuleContexts<simple_graph_grammarParser::Test_expr_sideContext>();
}

simple_graph_grammarParser::Test_expr_sideContext* simple_graph_grammarParser::Leq_testContext::test_expr_side(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Test_expr_sideContext>(i);
}

simple_graph_grammarParser::Leq_testContext::Leq_testContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Leq_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeq_test(this);
}
void simple_graph_grammarParser::Leq_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeq_test(this);
}

std::any simple_graph_grammarParser::Leq_testContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitLeq_test(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Script_testContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Script_testContext::EscapedString() {
  return getToken(simple_graph_grammarParser::EscapedString, 0);
}

simple_graph_grammarParser::Script_testContext::Script_testContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Script_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScript_test(this);
}
void simple_graph_grammarParser::Script_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScript_test(this);
}

std::any simple_graph_grammarParser::Script_testContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitScript_test(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Or_testContext ------------------------------------------------------------------

std::vector<simple_graph_grammarParser::Test_exprContext *> simple_graph_grammarParser::Or_testContext::test_expr() {
  return getRuleContexts<simple_graph_grammarParser::Test_exprContext>();
}

simple_graph_grammarParser::Test_exprContext* simple_graph_grammarParser::Or_testContext::test_expr(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Test_exprContext>(i);
}

simple_graph_grammarParser::Or_testContext::Or_testContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Or_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOr_test(this);
}
void simple_graph_grammarParser::Or_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOr_test(this);
}

std::any simple_graph_grammarParser::Or_testContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitOr_test(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Par_testContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Par_testContext::LPAR() {
  return getToken(simple_graph_grammarParser::LPAR, 0);
}

simple_graph_grammarParser::Test_exprContext* simple_graph_grammarParser::Par_testContext::test_expr() {
  return getRuleContext<simple_graph_grammarParser::Test_exprContext>(0);
}

tree::TerminalNode* simple_graph_grammarParser::Par_testContext::RPAR() {
  return getToken(simple_graph_grammarParser::RPAR, 0);
}

simple_graph_grammarParser::Par_testContext::Par_testContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Par_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPar_test(this);
}
void simple_graph_grammarParser::Par_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPar_test(this);
}

std::any simple_graph_grammarParser::Par_testContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitPar_test(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatchedContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> simple_graph_grammarParser::MatchedContext::OTHERS() {
  return getTokens(simple_graph_grammarParser::OTHERS);
}

tree::TerminalNode* simple_graph_grammarParser::MatchedContext::OTHERS(size_t i) {
  return getToken(simple_graph_grammarParser::OTHERS, i);
}

simple_graph_grammarParser::MatchedContext::MatchedContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::MatchedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatched(this);
}
void simple_graph_grammarParser::MatchedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatched(this);
}

std::any simple_graph_grammarParser::MatchedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitMatched(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Eq_testContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Eq_testContext::EQ() {
  return getToken(simple_graph_grammarParser::EQ, 0);
}

std::vector<simple_graph_grammarParser::Test_expr_sideContext *> simple_graph_grammarParser::Eq_testContext::test_expr_side() {
  return getRuleContexts<simple_graph_grammarParser::Test_expr_sideContext>();
}

simple_graph_grammarParser::Test_expr_sideContext* simple_graph_grammarParser::Eq_testContext::test_expr_side(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Test_expr_sideContext>(i);
}

simple_graph_grammarParser::Eq_testContext::Eq_testContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Eq_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEq_test(this);
}
void simple_graph_grammarParser::Eq_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEq_test(this);
}

std::any simple_graph_grammarParser::Eq_testContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitEq_test(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Neq_testContext ------------------------------------------------------------------

std::vector<simple_graph_grammarParser::Test_expr_sideContext *> simple_graph_grammarParser::Neq_testContext::test_expr_side() {
  return getRuleContexts<simple_graph_grammarParser::Test_expr_sideContext>();
}

simple_graph_grammarParser::Test_expr_sideContext* simple_graph_grammarParser::Neq_testContext::test_expr_side(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Test_expr_sideContext>(i);
}

simple_graph_grammarParser::Neq_testContext::Neq_testContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Neq_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNeq_test(this);
}
void simple_graph_grammarParser::Neq_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNeq_test(this);
}

std::any simple_graph_grammarParser::Neq_testContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitNeq_test(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FillContext ------------------------------------------------------------------

simple_graph_grammarParser::Test_exprContext* simple_graph_grammarParser::FillContext::test_expr() {
  return getRuleContext<simple_graph_grammarParser::Test_exprContext>(0);
}

simple_graph_grammarParser::FillContext::FillContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::FillContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFill(this);
}
void simple_graph_grammarParser::FillContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFill(this);
}

std::any simple_graph_grammarParser::FillContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitFill(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Lt_testContext ------------------------------------------------------------------

std::vector<simple_graph_grammarParser::Test_expr_sideContext *> simple_graph_grammarParser::Lt_testContext::test_expr_side() {
  return getRuleContexts<simple_graph_grammarParser::Test_expr_sideContext>();
}

simple_graph_grammarParser::Test_expr_sideContext* simple_graph_grammarParser::Lt_testContext::test_expr_side(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Test_expr_sideContext>(i);
}

simple_graph_grammarParser::Lt_testContext::Lt_testContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Lt_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLt_test(this);
}
void simple_graph_grammarParser::Lt_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLt_test(this);
}

std::any simple_graph_grammarParser::Lt_testContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitLt_test(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnmatchedContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> simple_graph_grammarParser::UnmatchedContext::OTHERS() {
  return getTokens(simple_graph_grammarParser::OTHERS);
}

tree::TerminalNode* simple_graph_grammarParser::UnmatchedContext::OTHERS(size_t i) {
  return getToken(simple_graph_grammarParser::OTHERS, i);
}

simple_graph_grammarParser::UnmatchedContext::UnmatchedContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::UnmatchedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnmatched(this);
}
void simple_graph_grammarParser::UnmatchedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnmatched(this);
}

std::any simple_graph_grammarParser::UnmatchedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitUnmatched(this);
  else
    return visitor->visitChildren(this);
}
//----------------- And_testContext ------------------------------------------------------------------

std::vector<simple_graph_grammarParser::Test_exprContext *> simple_graph_grammarParser::And_testContext::test_expr() {
  return getRuleContexts<simple_graph_grammarParser::Test_exprContext>();
}

simple_graph_grammarParser::Test_exprContext* simple_graph_grammarParser::And_testContext::test_expr(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Test_exprContext>(i);
}

simple_graph_grammarParser::And_testContext::And_testContext(Test_exprContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::And_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnd_test(this);
}
void simple_graph_grammarParser::And_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnd_test(this);
}

std::any simple_graph_grammarParser::And_testContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitAnd_test(this);
  else
    return visitor->visitChildren(this);
}

simple_graph_grammarParser::Test_exprContext* simple_graph_grammarParser::test_expr() {
   return test_expr(0);
}

simple_graph_grammarParser::Test_exprContext* simple_graph_grammarParser::test_expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  simple_graph_grammarParser::Test_exprContext *_localctx = _tracker.createInstance<Test_exprContext>(_ctx, parentState);
  simple_graph_grammarParser::Test_exprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, simple_graph_grammarParser::RuleTest_expr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Eq_testContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(134);
      antlrcpp::downCast<Eq_testContext *>(_localctx)->src = test_expr_side();
      setState(135);
      match(simple_graph_grammarParser::EQ);
      setState(136);
      antlrcpp::downCast<Eq_testContext *>(_localctx)->dst = test_expr_side();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Neq_testContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(138);
      antlrcpp::downCast<Neq_testContext *>(_localctx)->src = test_expr_side();
      setState(139);
      match(simple_graph_grammarParser::T__14);
      setState(140);
      antlrcpp::downCast<Neq_testContext *>(_localctx)->dst = test_expr_side();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Lt_testContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(142);
      antlrcpp::downCast<Lt_testContext *>(_localctx)->src = test_expr_side();
      setState(143);
      match(simple_graph_grammarParser::T__15);
      setState(144);
      antlrcpp::downCast<Lt_testContext *>(_localctx)->dst = test_expr_side();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Leq_testContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(146);
      antlrcpp::downCast<Leq_testContext *>(_localctx)->src = test_expr_side();
      setState(147);
      match(simple_graph_grammarParser::T__16);
      setState(148);
      antlrcpp::downCast<Leq_testContext *>(_localctx)->dst = test_expr_side();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Par_testContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(150);
      match(simple_graph_grammarParser::LPAR);
      setState(151);
      test_expr(0);
      setState(152);
      match(simple_graph_grammarParser::RPAR);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Script_testContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(154);
      match(simple_graph_grammarParser::T__19);
      setState(155);
      match(simple_graph_grammarParser::EscapedString);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<UnmatchedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(156);
      match(simple_graph_grammarParser::OTHERS);
      setState(157);
      match(simple_graph_grammarParser::T__20);
      setState(158);
      match(simple_graph_grammarParser::OTHERS);
      setState(159);
      match(simple_graph_grammarParser::T__21);
      setState(160);
      match(simple_graph_grammarParser::OTHERS);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<MatchedContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(161);
      match(simple_graph_grammarParser::OTHERS);
      setState(162);
      match(simple_graph_grammarParser::T__22);
      setState(163);
      match(simple_graph_grammarParser::OTHERS);
      setState(164);
      match(simple_graph_grammarParser::T__21);
      setState(165);
      match(simple_graph_grammarParser::OTHERS);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<FillContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(166);
      match(simple_graph_grammarParser::T__23);
      setState(167);
      test_expr(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(178);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(176);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Or_testContext>(_tracker.createInstance<Test_exprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->src = previousContext;
          pushNewRecursionContext(newContext, startState, RuleTest_expr);
          setState(170);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(171);
          match(simple_graph_grammarParser::T__17);
          setState(172);
          antlrcpp::downCast<Or_testContext *>(_localctx)->dst = test_expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<And_testContext>(_tracker.createInstance<Test_exprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->src = previousContext;
          pushNewRecursionContext(newContext, startState, RuleTest_expr);
          setState(173);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(174);
          match(simple_graph_grammarParser::T__18);
          setState(175);
          antlrcpp::downCast<And_testContext *>(_localctx)->dst = test_expr(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(180);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Test_expr_sideContext ------------------------------------------------------------------

simple_graph_grammarParser::Test_expr_sideContext::Test_expr_sideContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t simple_graph_grammarParser::Test_expr_sideContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleTest_expr_side;
}

void simple_graph_grammarParser::Test_expr_sideContext::copyFrom(Test_expr_sideContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Test_dataContext ------------------------------------------------------------------

simple_graph_grammarParser::Rewrite_exprContext* simple_graph_grammarParser::Test_dataContext::rewrite_expr() {
  return getRuleContext<simple_graph_grammarParser::Rewrite_exprContext>(0);
}

simple_graph_grammarParser::Test_dataContext::Test_dataContext(Test_expr_sideContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Test_dataContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTest_data(this);
}
void simple_graph_grammarParser::Test_dataContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTest_data(this);
}

std::any simple_graph_grammarParser::Test_dataContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitTest_data(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Test_valueContext ------------------------------------------------------------------

tree::TerminalNode* simple_graph_grammarParser::Test_valueContext::OTHERS() {
  return getToken(simple_graph_grammarParser::OTHERS, 0);
}

simple_graph_grammarParser::Test_valueContext::Test_valueContext(Test_expr_sideContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::Test_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTest_value(this);
}
void simple_graph_grammarParser::Test_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTest_value(this);
}

std::any simple_graph_grammarParser::Test_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitTest_value(this);
  else
    return visitor->visitChildren(this);
}
simple_graph_grammarParser::Test_expr_sideContext* simple_graph_grammarParser::test_expr_side() {
  Test_expr_sideContext *_localctx = _tracker.createInstance<Test_expr_sideContext>(_ctx, getState());
  enterRule(_localctx, 14, simple_graph_grammarParser::RuleTest_expr_side);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::Test_dataContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(181);
      rewrite_expr();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::Test_valueContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(182);
      match(simple_graph_grammarParser::OTHERS);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgeContext ------------------------------------------------------------------

simple_graph_grammarParser::EdgeContext::EdgeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t simple_graph_grammarParser::EdgeContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleEdge;
}

void simple_graph_grammarParser::EdgeContext::copyFrom(EdgeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- HookContext ------------------------------------------------------------------

simple_graph_grammarParser::EdgelabelContext* simple_graph_grammarParser::HookContext::edgelabel() {
  return getRuleContext<simple_graph_grammarParser::EdgelabelContext>(0);
}

simple_graph_grammarParser::HookContext::HookContext(EdgeContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::HookContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHook(this);
}
void simple_graph_grammarParser::HookContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHook(this);
}

std::any simple_graph_grammarParser::HookContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitHook(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OutedgeContext ------------------------------------------------------------------

simple_graph_grammarParser::EdgelabelContext* simple_graph_grammarParser::OutedgeContext::edgelabel() {
  return getRuleContext<simple_graph_grammarParser::EdgelabelContext>(0);
}

simple_graph_grammarParser::NodeContext* simple_graph_grammarParser::OutedgeContext::node() {
  return getRuleContext<simple_graph_grammarParser::NodeContext>(0);
}

simple_graph_grammarParser::OutedgeContext::OutedgeContext(EdgeContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::OutedgeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutedge(this);
}
void simple_graph_grammarParser::OutedgeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutedge(this);
}

std::any simple_graph_grammarParser::OutedgeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitOutedge(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InedgeContext ------------------------------------------------------------------

simple_graph_grammarParser::EdgelabelContext* simple_graph_grammarParser::InedgeContext::edgelabel() {
  return getRuleContext<simple_graph_grammarParser::EdgelabelContext>(0);
}

simple_graph_grammarParser::NodeContext* simple_graph_grammarParser::InedgeContext::node() {
  return getRuleContext<simple_graph_grammarParser::NodeContext>(0);
}

simple_graph_grammarParser::InedgeContext::InedgeContext(EdgeContext *ctx) { copyFrom(ctx); }

void simple_graph_grammarParser::InedgeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInedge(this);
}
void simple_graph_grammarParser::InedgeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInedge(this);
}

std::any simple_graph_grammarParser::InedgeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitInedge(this);
  else
    return visitor->visitChildren(this);
}
simple_graph_grammarParser::EdgeContext* simple_graph_grammarParser::edge() {
  EdgeContext *_localctx = _tracker.createInstance<EdgeContext>(_ctx, getState());
  enterRule(_localctx, 16, simple_graph_grammarParser::RuleEdge);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(199);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::OutedgeContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(185);
      match(simple_graph_grammarParser::T__24);
      setState(186);
      edgelabel();
      setState(187);
      match(simple_graph_grammarParser::T__25);
      setState(188);
      node();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::InedgeContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(190);
      match(simple_graph_grammarParser::T__26);
      setState(191);
      edgelabel();
      setState(192);
      match(simple_graph_grammarParser::T__24);
      setState(193);
      node();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::HookContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(195);
      match(simple_graph_grammarParser::T__24);
      setState(196);
      edgelabel();
      setState(197);
      match(simple_graph_grammarParser::T__27);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Edge_joiningContext ------------------------------------------------------------------

simple_graph_grammarParser::Edge_joiningContext::Edge_joiningContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

simple_graph_grammarParser::NodeContext* simple_graph_grammarParser::Edge_joiningContext::node() {
  return getRuleContext<simple_graph_grammarParser::NodeContext>(0);
}

simple_graph_grammarParser::EdgeContext* simple_graph_grammarParser::Edge_joiningContext::edge() {
  return getRuleContext<simple_graph_grammarParser::EdgeContext>(0);
}


size_t simple_graph_grammarParser::Edge_joiningContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleEdge_joining;
}

void simple_graph_grammarParser::Edge_joiningContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdge_joining(this);
}

void simple_graph_grammarParser::Edge_joiningContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdge_joining(this);
}


std::any simple_graph_grammarParser::Edge_joiningContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitEdge_joining(this);
  else
    return visitor->visitChildren(this);
}

simple_graph_grammarParser::Edge_joiningContext* simple_graph_grammarParser::edge_joining() {
  Edge_joiningContext *_localctx = _tracker.createInstance<Edge_joiningContext>(_ctx, getState());
  enterRule(_localctx, 18, simple_graph_grammarParser::RuleEdge_joining);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    node();
    setState(202);
    edge();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EdgelabelContext ------------------------------------------------------------------

simple_graph_grammarParser::EdgelabelContext::EdgelabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* simple_graph_grammarParser::EdgelabelContext::QPAR() {
  return getToken(simple_graph_grammarParser::QPAR, 0);
}

tree::TerminalNode* simple_graph_grammarParser::EdgelabelContext::PPAR() {
  return getToken(simple_graph_grammarParser::PPAR, 0);
}

tree::TerminalNode* simple_graph_grammarParser::EdgelabelContext::COL() {
  return getToken(simple_graph_grammarParser::COL, 0);
}

simple_graph_grammarParser::Multiple_labelsContext* simple_graph_grammarParser::EdgelabelContext::multiple_labels() {
  return getRuleContext<simple_graph_grammarParser::Multiple_labelsContext>(0);
}

tree::TerminalNode* simple_graph_grammarParser::EdgelabelContext::OTHERS() {
  return getToken(simple_graph_grammarParser::OTHERS, 0);
}

tree::TerminalNode* simple_graph_grammarParser::EdgelabelContext::FORALL() {
  return getToken(simple_graph_grammarParser::FORALL, 0);
}

tree::TerminalNode* simple_graph_grammarParser::EdgelabelContext::QM() {
  return getToken(simple_graph_grammarParser::QM, 0);
}


size_t simple_graph_grammarParser::EdgelabelContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleEdgelabel;
}

void simple_graph_grammarParser::EdgelabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEdgelabel(this);
}

void simple_graph_grammarParser::EdgelabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEdgelabel(this);
}


std::any simple_graph_grammarParser::EdgelabelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitEdgelabel(this);
  else
    return visitor->visitChildren(this);
}

simple_graph_grammarParser::EdgelabelContext* simple_graph_grammarParser::edgelabel() {
  EdgelabelContext *_localctx = _tracker.createInstance<EdgelabelContext>(_ctx, getState());
  enterRule(_localctx, 20, simple_graph_grammarParser::RuleEdgelabel);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    match(simple_graph_grammarParser::QPAR);

    setState(206);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::FORALL) {
      setState(205);
      match(simple_graph_grammarParser::FORALL);
    }
    setState(209);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::QM) {
      setState(208);
      match(simple_graph_grammarParser::QM);
    }
    setState(213);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      setState(211);
      antlrcpp::downCast<EdgelabelContext *>(_localctx)->var = match(simple_graph_grammarParser::OTHERS);
      setState(212);
      match(simple_graph_grammarParser::COL);
      break;
    }

    default:
      break;
    }
    setState(216);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::OTHERS) {
      setState(215);
      multiple_labels();
    }
    setState(218);
    match(simple_graph_grammarParser::PPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Multiple_labelsContext ------------------------------------------------------------------

simple_graph_grammarParser::Multiple_labelsContext::Multiple_labelsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> simple_graph_grammarParser::Multiple_labelsContext::OTHERS() {
  return getTokens(simple_graph_grammarParser::OTHERS);
}

tree::TerminalNode* simple_graph_grammarParser::Multiple_labelsContext::OTHERS(size_t i) {
  return getToken(simple_graph_grammarParser::OTHERS, i);
}


size_t simple_graph_grammarParser::Multiple_labelsContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleMultiple_labels;
}

void simple_graph_grammarParser::Multiple_labelsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiple_labels(this);
}

void simple_graph_grammarParser::Multiple_labelsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiple_labels(this);
}


std::any simple_graph_grammarParser::Multiple_labelsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitMultiple_labels(this);
  else
    return visitor->visitChildren(this);
}

simple_graph_grammarParser::Multiple_labelsContext* simple_graph_grammarParser::multiple_labels() {
  Multiple_labelsContext *_localctx = _tracker.createInstance<Multiple_labelsContext>(_ctx, getState());
  enterRule(_localctx, 22, simple_graph_grammarParser::RuleMultiple_labels);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(224);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(220);
        match(simple_graph_grammarParser::OTHERS);
        setState(221);
        match(simple_graph_grammarParser::T__28); 
      }
      setState(226);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(227);
    match(simple_graph_grammarParser::OTHERS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool simple_graph_grammarParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return test_exprSempred(antlrcpp::downCast<Test_exprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool simple_graph_grammarParser::test_exprSempred(Test_exprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

void simple_graph_grammarParser::initialize() {
  ::antlr4::internal::call_once(simple_graph_grammarParserOnceFlag, simple_graph_grammarParserInitialize);
}
