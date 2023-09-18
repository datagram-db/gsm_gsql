
// Generated from antlr4/simple_graph_grammar.g4 by ANTLR 4.11.1


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
      "'--'", "'->'", "'<-'", "'hook'", "'||'", "'if'", "'then'", "'else'", 
      "'as'", "'>>'", "'\\u21AA'", "'\\u2200'", "'\\u003F'", "'='", "'*'", 
      "'('", "')'", "':'", "'['", "']'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "IF", "THEN", "ELSE", "AS", "VEC", "REWRITE_TO", "FORALL", 
      "QM", "EQ", "STAR", "LPAR", "RPAR", "COL", "QPAR", "PPAR", "OTHERS", 
      "SPACE", "COMMENT", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,37,182,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,5,0,28,8,0,10,0,
  	12,0,31,9,0,1,0,1,0,1,1,1,1,3,1,37,8,1,1,1,3,1,40,8,1,1,1,1,1,1,1,3,1,
  	45,8,1,1,1,1,1,1,2,1,2,1,2,1,2,3,2,53,8,2,1,2,5,2,56,8,2,10,2,12,2,59,
  	9,2,1,2,1,2,5,2,63,8,2,10,2,12,2,66,9,2,1,2,3,2,69,8,2,1,3,4,3,72,8,3,
  	11,3,12,3,73,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,85,8,4,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,119,8,5,1,5,1,5,1,
  	5,1,5,1,5,3,5,126,8,5,1,6,1,6,1,6,1,6,1,7,1,7,3,7,134,8,7,1,8,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,150,8,8,1,9,1,9,1,9,1,
  	10,1,10,3,10,157,8,10,1,10,3,10,160,8,10,3,10,162,8,10,1,10,1,10,3,10,
  	166,8,10,1,10,3,10,169,8,10,1,10,1,10,1,11,1,11,5,11,175,8,11,10,11,12,
  	11,178,9,11,1,11,1,11,1,11,0,0,12,0,2,4,6,8,10,12,14,16,18,20,22,0,0,
  	199,0,29,1,0,0,0,2,34,1,0,0,0,4,48,1,0,0,0,6,71,1,0,0,0,8,84,1,0,0,0,
  	10,125,1,0,0,0,12,127,1,0,0,0,14,133,1,0,0,0,16,149,1,0,0,0,18,151,1,
  	0,0,0,20,154,1,0,0,0,22,176,1,0,0,0,24,25,3,4,2,0,25,26,5,1,0,0,26,28,
  	1,0,0,0,27,24,1,0,0,0,28,31,1,0,0,0,29,27,1,0,0,0,29,30,1,0,0,0,30,32,
  	1,0,0,0,31,29,1,0,0,0,32,33,3,4,2,0,33,1,1,0,0,0,34,36,5,29,0,0,35,37,
  	5,28,0,0,36,35,1,0,0,0,36,37,1,0,0,0,37,39,1,0,0,0,38,40,5,23,0,0,39,
  	38,1,0,0,0,39,40,1,0,0,0,40,41,1,0,0,0,41,44,3,22,11,0,42,43,5,31,0,0,
  	43,45,5,34,0,0,44,42,1,0,0,0,44,45,1,0,0,0,45,46,1,0,0,0,46,47,5,30,0,
  	0,47,3,1,0,0,0,48,49,5,34,0,0,49,50,5,27,0,0,50,52,3,2,1,0,51,53,3,6,
  	3,0,52,51,1,0,0,0,52,53,1,0,0,0,53,57,1,0,0,0,54,56,3,18,9,0,55,54,1,
  	0,0,0,56,59,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,68,1,0,0,0,59,57,1,
  	0,0,0,60,64,5,24,0,0,61,63,3,8,4,0,62,61,1,0,0,0,63,66,1,0,0,0,64,62,
  	1,0,0,0,64,65,1,0,0,0,65,67,1,0,0,0,66,64,1,0,0,0,67,69,3,2,1,0,68,60,
  	1,0,0,0,68,69,1,0,0,0,69,5,1,0,0,0,70,72,3,16,8,0,71,70,1,0,0,0,72,73,
  	1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,7,1,0,0,0,75,76,5,2,0,0,76,85,
  	5,34,0,0,77,78,5,3,0,0,78,85,5,34,0,0,79,80,5,4,0,0,80,81,3,10,5,0,81,
  	82,5,22,0,0,82,83,3,10,5,0,83,85,1,0,0,0,84,75,1,0,0,0,84,77,1,0,0,0,
  	84,79,1,0,0,0,85,9,1,0,0,0,86,87,5,5,0,0,87,88,5,34,0,0,88,89,5,6,0,0,
  	89,126,3,10,5,0,90,91,5,7,0,0,91,92,5,34,0,0,92,93,5,6,0,0,93,126,3,10,
  	5,0,94,95,5,8,0,0,95,96,3,10,5,0,96,97,5,6,0,0,97,98,3,10,5,0,98,126,
  	1,0,0,0,99,100,5,9,0,0,100,101,3,10,5,0,101,102,5,10,0,0,102,103,3,10,
  	5,0,103,126,1,0,0,0,104,105,5,11,0,0,105,126,3,10,5,0,106,107,5,12,0,
  	0,107,126,3,10,5,0,108,109,5,13,0,0,109,126,3,10,5,0,110,111,5,19,0,0,
  	111,112,5,29,0,0,112,113,3,12,6,0,113,114,5,30,0,0,114,115,5,20,0,0,115,
  	118,3,10,5,0,116,117,5,21,0,0,117,119,3,10,5,0,118,116,1,0,0,0,118,119,
  	1,0,0,0,119,126,1,0,0,0,120,126,5,34,0,0,121,122,5,29,0,0,122,123,3,10,
  	5,0,123,124,5,30,0,0,124,126,1,0,0,0,125,86,1,0,0,0,125,90,1,0,0,0,125,
  	94,1,0,0,0,125,99,1,0,0,0,125,104,1,0,0,0,125,106,1,0,0,0,125,108,1,0,
  	0,0,125,110,1,0,0,0,125,120,1,0,0,0,125,121,1,0,0,0,126,11,1,0,0,0,127,
  	128,3,14,7,0,128,129,5,27,0,0,129,130,3,14,7,0,130,13,1,0,0,0,131,134,
  	3,10,5,0,132,134,5,34,0,0,133,131,1,0,0,0,133,132,1,0,0,0,134,15,1,0,
  	0,0,135,136,5,14,0,0,136,137,3,20,10,0,137,138,5,15,0,0,138,139,3,2,1,
  	0,139,150,1,0,0,0,140,141,5,16,0,0,141,142,3,20,10,0,142,143,5,14,0,0,
  	143,144,3,2,1,0,144,150,1,0,0,0,145,146,5,14,0,0,146,147,3,20,10,0,147,
  	148,5,17,0,0,148,150,1,0,0,0,149,135,1,0,0,0,149,140,1,0,0,0,149,145,
  	1,0,0,0,150,17,1,0,0,0,151,152,3,2,1,0,152,153,3,16,8,0,153,19,1,0,0,
  	0,154,161,5,32,0,0,155,157,5,25,0,0,156,155,1,0,0,0,156,157,1,0,0,0,157,
  	162,1,0,0,0,158,160,5,26,0,0,159,158,1,0,0,0,159,160,1,0,0,0,160,162,
  	1,0,0,0,161,156,1,0,0,0,161,159,1,0,0,0,162,165,1,0,0,0,163,164,5,34,
  	0,0,164,166,5,31,0,0,165,163,1,0,0,0,165,166,1,0,0,0,166,168,1,0,0,0,
  	167,169,3,22,11,0,168,167,1,0,0,0,168,169,1,0,0,0,169,170,1,0,0,0,170,
  	171,5,33,0,0,171,21,1,0,0,0,172,173,5,34,0,0,173,175,5,18,0,0,174,172,
  	1,0,0,0,175,178,1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,179,1,0,0,
  	0,178,176,1,0,0,0,179,180,5,34,0,0,180,23,1,0,0,0,20,29,36,39,44,52,57,
  	64,68,73,84,118,125,133,149,156,159,161,165,168,176
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
    if (_la == simple_graph_grammarParser::T__13

    || _la == simple_graph_grammarParser::T__15) {
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
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::REWRITE_TO) {
      setState(60);
      match(simple_graph_grammarParser::REWRITE_TO);
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 28) != 0) {
        setState(61);
        rewrite_to();
        setState(66);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(67);
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
    setState(71); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(70);
      edge();
      setState(73); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == simple_graph_grammarParser::T__13

    || _la == simple_graph_grammarParser::T__15);
   
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
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case simple_graph_grammarParser::T__1: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Del_node_or_edgeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(75);
        match(simple_graph_grammarParser::T__1);
        setState(76);
        match(simple_graph_grammarParser::OTHERS);
        break;
      }

      case simple_graph_grammarParser::T__2: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Neu_objContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(77);
        match(simple_graph_grammarParser::T__2);
        setState(78);
        antlrcpp::downCast<Neu_objContext *>(_localctx)->dst = match(simple_graph_grammarParser::OTHERS);
        break;
      }

      case simple_graph_grammarParser::T__3: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Update_exprContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(79);
        match(simple_graph_grammarParser::T__3);
        setState(80);
        antlrcpp::downCast<Update_exprContext *>(_localctx)->to = rewrite_expr();
        setState(81);
        match(simple_graph_grammarParser::AS);
        setState(82);
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
    setState(125);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case simple_graph_grammarParser::T__4: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Node_xiContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(86);
        match(simple_graph_grammarParser::T__4);
        setState(87);
        antlrcpp::downCast<Node_xiContext *>(_localctx)->num = match(simple_graph_grammarParser::OTHERS);
        setState(88);
        match(simple_graph_grammarParser::T__5);
        setState(89);
        antlrcpp::downCast<Node_xiContext *>(_localctx)->nodeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__6: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Node_ellContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(90);
        match(simple_graph_grammarParser::T__6);
        setState(91);
        antlrcpp::downCast<Node_ellContext *>(_localctx)->num = match(simple_graph_grammarParser::OTHERS);
        setState(92);
        match(simple_graph_grammarParser::T__5);
        setState(93);
        antlrcpp::downCast<Node_ellContext *>(_localctx)->nodeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__7: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Node_propContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(94);
        match(simple_graph_grammarParser::T__7);
        setState(95);
        antlrcpp::downCast<Node_propContext *>(_localctx)->key = rewrite_expr();
        setState(96);
        match(simple_graph_grammarParser::T__5);
        setState(97);
        antlrcpp::downCast<Node_propContext *>(_localctx)->nodeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__8: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Node_containmentContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(99);
        match(simple_graph_grammarParser::T__8);
        setState(100);
        antlrcpp::downCast<Node_containmentContext *>(_localctx)->key = rewrite_expr();
        setState(101);
        match(simple_graph_grammarParser::T__9);
        setState(102);
        antlrcpp::downCast<Node_containmentContext *>(_localctx)->nodeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__10: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Edge_labelContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(104);
        match(simple_graph_grammarParser::T__10);
        setState(105);
        antlrcpp::downCast<Edge_labelContext *>(_localctx)->edgeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__11: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Edge_srcContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(106);
        match(simple_graph_grammarParser::T__11);
        setState(107);
        antlrcpp::downCast<Edge_srcContext *>(_localctx)->edgeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::T__12: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Edge_dstContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(108);
        match(simple_graph_grammarParser::T__12);
        setState(109);
        antlrcpp::downCast<Edge_dstContext *>(_localctx)->edgeVar = rewrite_expr();
        break;
      }

      case simple_graph_grammarParser::IF: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Ifte_exprContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(110);
        match(simple_graph_grammarParser::IF);
        setState(111);
        match(simple_graph_grammarParser::LPAR);
        setState(112);
        antlrcpp::downCast<Ifte_exprContext *>(_localctx)->ifcond = test_expr();
        setState(113);
        match(simple_graph_grammarParser::RPAR);
        setState(114);
        match(simple_graph_grammarParser::THEN);
        setState(115);
        antlrcpp::downCast<Ifte_exprContext *>(_localctx)->then_effect = rewrite_expr();
        setState(118);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          setState(116);
          match(simple_graph_grammarParser::ELSE);
          setState(117);
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
        setState(120);
        match(simple_graph_grammarParser::OTHERS);
        break;
      }

      case simple_graph_grammarParser::LPAR: {
        _localctx = _tracker.createInstance<simple_graph_grammarParser::Just_parContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(121);
        match(simple_graph_grammarParser::LPAR);
        setState(122);
        rewrite_expr();
        setState(123);
        match(simple_graph_grammarParser::RPAR);
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

tree::TerminalNode* simple_graph_grammarParser::Test_exprContext::EQ() {
  return getToken(simple_graph_grammarParser::EQ, 0);
}

std::vector<simple_graph_grammarParser::Test_expr_sideContext *> simple_graph_grammarParser::Test_exprContext::test_expr_side() {
  return getRuleContexts<simple_graph_grammarParser::Test_expr_sideContext>();
}

simple_graph_grammarParser::Test_expr_sideContext* simple_graph_grammarParser::Test_exprContext::test_expr_side(size_t i) {
  return getRuleContext<simple_graph_grammarParser::Test_expr_sideContext>(i);
}


size_t simple_graph_grammarParser::Test_exprContext::getRuleIndex() const {
  return simple_graph_grammarParser::RuleTest_expr;
}

void simple_graph_grammarParser::Test_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTest_expr(this);
}

void simple_graph_grammarParser::Test_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<simple_graph_grammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTest_expr(this);
}


std::any simple_graph_grammarParser::Test_exprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<simple_graph_grammarVisitor*>(visitor))
    return parserVisitor->visitTest_expr(this);
  else
    return visitor->visitChildren(this);
}

simple_graph_grammarParser::Test_exprContext* simple_graph_grammarParser::test_expr() {
  Test_exprContext *_localctx = _tracker.createInstance<Test_exprContext>(_ctx, getState());
  enterRule(_localctx, 12, simple_graph_grammarParser::RuleTest_expr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    antlrcpp::downCast<Test_exprContext *>(_localctx)->src = test_expr_side();
    setState(128);
    match(simple_graph_grammarParser::EQ);
    setState(129);
    antlrcpp::downCast<Test_exprContext *>(_localctx)->dst = test_expr_side();
   
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
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::Test_dataContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(131);
      rewrite_expr();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::Test_valueContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(132);
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
    setState(149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::OutedgeContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(135);
      match(simple_graph_grammarParser::T__13);
      setState(136);
      edgelabel();
      setState(137);
      match(simple_graph_grammarParser::T__14);
      setState(138);
      node();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::InedgeContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(140);
      match(simple_graph_grammarParser::T__15);
      setState(141);
      edgelabel();
      setState(142);
      match(simple_graph_grammarParser::T__13);
      setState(143);
      node();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<simple_graph_grammarParser::HookContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(145);
      match(simple_graph_grammarParser::T__13);
      setState(146);
      edgelabel();
      setState(147);
      match(simple_graph_grammarParser::T__16);
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
    setState(151);
    node();
    setState(152);
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
    setState(154);
    match(simple_graph_grammarParser::QPAR);
    setState(161);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(156);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == simple_graph_grammarParser::FORALL) {
        setState(155);
        match(simple_graph_grammarParser::FORALL);
      }
      break;
    }

    case 2: {
      setState(159);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == simple_graph_grammarParser::QM) {
        setState(158);
        match(simple_graph_grammarParser::QM);
      }
      break;
    }

    default:
      break;
    }
    setState(165);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(163);
      antlrcpp::downCast<EdgelabelContext *>(_localctx)->var = match(simple_graph_grammarParser::OTHERS);
      setState(164);
      match(simple_graph_grammarParser::COL);
      break;
    }

    default:
      break;
    }
    setState(168);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == simple_graph_grammarParser::OTHERS) {
      setState(167);
      multiple_labels();
    }
    setState(170);
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
    setState(176);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(172);
        match(simple_graph_grammarParser::OTHERS);
        setState(173);
        match(simple_graph_grammarParser::T__17); 
      }
      setState(178);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
    setState(179);
    match(simple_graph_grammarParser::OTHERS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void simple_graph_grammarParser::initialize() {
  ::antlr4::internal::call_once(simple_graph_grammarParserOnceFlag, simple_graph_grammarParserInitialize);
}
