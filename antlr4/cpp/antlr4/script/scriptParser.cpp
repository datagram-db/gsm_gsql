
// Generated from antlr4/script/script.g4 by ANTLR 4.11.1


#include "scriptListener.h"
#include "scriptVisitor.h"

#include "scriptParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ScriptParserStaticData final {
  ScriptParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ScriptParserStaticData(const ScriptParserStaticData&) = delete;
  ScriptParserStaticData(ScriptParserStaticData&&) = delete;
  ScriptParserStaticData& operator=(const ScriptParserStaticData&) = delete;
  ScriptParserStaticData& operator=(ScriptParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag scriptParserOnceFlag;
ScriptParserStaticData *scriptParserStaticData = nullptr;

void scriptParserInitialize() {
  assert(scriptParserStaticData == nullptr);
  auto staticData = std::make_unique<ScriptParserStaticData>(
    std::vector<std::string>{
      "script", "expr"
    },
    std::vector<std::string>{
      "", "';'", "'('", "')'", "'+'", "'-'", "'/'", "'%'", "'*'", "'++'", 
      "'@'", "'&&'", "'||'", "'|'", "'=='", "'!='", "'<='", "'>='", "'>'", 
      "'<'", "':='", "'.'", "'eval('", "'var('", "'not'", "'=>'", "'if'", 
      "'then'", "'else'", "'sub('", "','", "':'", "'['", "']'", "']:='", 
      "'in'", "'remove'", "'from'", "'{'", "'}'", "'->'", "'map('", "'select('", 
      "'filter('", "'rfold('", "'lfold('", "'log'", "'pow'", "'sin'", "'cos'", 
      "'tan'", "'|_'", "'_|'", "'|-'", "'-|'", "'phi'", "'ell'", "'xi'", 
      "'inj'", "'flat'", "'x'", "'selfx'", "'varphi'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "BOOL", "VARNAME", 
      "FUNVAR", "EscapedString", "NUMBER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,68,239,2,0,7,0,2,1,7,1,1,0,1,0,1,0,5,0,8,8,0,10,0,12,0,11,9,0,1,0,
  	1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,
  	1,66,8,1,10,1,12,1,69,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,80,
  	8,1,10,1,12,1,83,9,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,161,8,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,234,
  	8,1,10,1,12,1,237,9,1,1,1,0,1,2,2,0,2,0,0,294,0,9,1,0,0,0,2,160,1,0,0,
  	0,4,5,3,2,1,0,5,6,5,1,0,0,6,8,1,0,0,0,7,4,1,0,0,0,8,11,1,0,0,0,9,7,1,
  	0,0,0,9,10,1,0,0,0,10,12,1,0,0,0,11,9,1,0,0,0,12,13,3,2,1,0,13,1,1,0,
  	0,0,14,15,6,1,-1,0,15,16,5,2,0,0,16,17,3,2,1,0,17,18,5,3,0,0,18,161,1,
  	0,0,0,19,20,5,13,0,0,20,21,3,2,1,0,21,22,5,13,0,0,22,161,1,0,0,0,23,24,
  	5,22,0,0,24,25,3,2,1,0,25,26,5,3,0,0,26,161,1,0,0,0,27,28,5,2,0,0,28,
  	29,3,2,1,0,29,30,3,2,1,0,30,31,5,3,0,0,31,161,1,0,0,0,32,33,5,23,0,0,
  	33,34,3,2,1,0,34,35,5,3,0,0,35,161,1,0,0,0,36,37,5,24,0,0,37,161,3,2,
  	1,34,38,39,5,26,0,0,39,40,3,2,1,0,40,41,5,27,0,0,41,42,3,2,1,0,42,43,
  	5,28,0,0,43,44,3,2,1,32,44,161,1,0,0,0,45,46,5,29,0,0,46,47,3,2,1,0,47,
  	48,5,30,0,0,48,49,3,2,1,0,49,50,5,31,0,0,50,51,3,2,1,0,51,52,5,3,0,0,
  	52,161,1,0,0,0,53,54,5,36,0,0,54,55,3,2,1,0,55,56,5,37,0,0,56,57,3,2,
  	1,27,57,161,1,0,0,0,58,161,5,66,0,0,59,161,5,63,0,0,60,161,5,67,0,0,61,
  	67,5,38,0,0,62,63,3,2,1,0,63,64,5,30,0,0,64,66,1,0,0,0,65,62,1,0,0,0,
  	66,69,1,0,0,0,67,65,1,0,0,0,67,68,1,0,0,0,68,70,1,0,0,0,69,67,1,0,0,0,
  	70,71,3,2,1,0,71,72,5,39,0,0,72,161,1,0,0,0,73,74,5,64,0,0,74,75,5,40,
  	0,0,75,81,5,38,0,0,76,77,3,2,1,0,77,78,5,1,0,0,78,80,1,0,0,0,79,76,1,
  	0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,81,82,1,0,0,0,82,84,1,0,0,0,83,81,1,
  	0,0,0,84,85,3,2,1,0,85,86,5,39,0,0,86,161,1,0,0,0,87,161,5,64,0,0,88,
  	89,5,41,0,0,89,90,3,2,1,0,90,91,5,31,0,0,91,92,3,2,1,0,92,93,5,3,0,0,
  	93,161,1,0,0,0,94,95,5,42,0,0,95,96,3,2,1,0,96,97,5,31,0,0,97,98,3,2,
  	1,0,98,99,5,3,0,0,99,161,1,0,0,0,100,101,5,43,0,0,101,102,3,2,1,0,102,
  	103,5,31,0,0,103,104,3,2,1,0,104,105,5,3,0,0,105,161,1,0,0,0,106,107,
  	5,44,0,0,107,108,3,2,1,0,108,109,5,30,0,0,109,110,3,2,1,0,110,111,5,31,
  	0,0,111,112,3,2,1,0,112,113,5,3,0,0,113,161,1,0,0,0,114,115,5,45,0,0,
  	115,116,3,2,1,0,116,117,5,30,0,0,117,118,3,2,1,0,118,119,5,31,0,0,119,
  	120,3,2,1,0,120,121,5,3,0,0,121,161,1,0,0,0,122,123,5,46,0,0,123,124,
  	3,2,1,0,124,125,3,2,1,15,125,161,1,0,0,0,126,127,5,47,0,0,127,128,3,2,
  	1,0,128,129,3,2,1,14,129,161,1,0,0,0,130,131,5,48,0,0,131,161,3,2,1,13,
  	132,133,5,49,0,0,133,161,3,2,1,12,134,135,5,50,0,0,135,161,3,2,1,11,136,
  	137,5,51,0,0,137,138,3,2,1,0,138,139,5,52,0,0,139,161,1,0,0,0,140,141,
  	5,53,0,0,141,142,3,2,1,0,142,143,5,54,0,0,143,161,1,0,0,0,144,145,5,55,
  	0,0,145,146,3,2,1,0,146,147,3,2,1,8,147,161,1,0,0,0,148,149,5,56,0,0,
  	149,161,3,2,1,7,150,151,5,57,0,0,151,161,3,2,1,6,152,153,5,58,0,0,153,
  	161,3,2,1,5,154,155,5,59,0,0,155,161,3,2,1,4,156,157,5,61,0,0,157,161,
  	3,2,1,2,158,159,5,62,0,0,159,161,3,2,1,1,160,14,1,0,0,0,160,19,1,0,0,
  	0,160,23,1,0,0,0,160,27,1,0,0,0,160,32,1,0,0,0,160,36,1,0,0,0,160,38,
  	1,0,0,0,160,45,1,0,0,0,160,53,1,0,0,0,160,58,1,0,0,0,160,59,1,0,0,0,160,
  	60,1,0,0,0,160,61,1,0,0,0,160,73,1,0,0,0,160,87,1,0,0,0,160,88,1,0,0,
  	0,160,94,1,0,0,0,160,100,1,0,0,0,160,106,1,0,0,0,160,114,1,0,0,0,160,
  	122,1,0,0,0,160,126,1,0,0,0,160,130,1,0,0,0,160,132,1,0,0,0,160,134,1,
  	0,0,0,160,136,1,0,0,0,160,140,1,0,0,0,160,144,1,0,0,0,160,148,1,0,0,0,
  	160,150,1,0,0,0,160,152,1,0,0,0,160,154,1,0,0,0,160,156,1,0,0,0,160,158,
  	1,0,0,0,161,235,1,0,0,0,162,163,10,55,0,0,163,164,5,4,0,0,164,234,3,2,
  	1,56,165,166,10,54,0,0,166,167,5,5,0,0,167,234,3,2,1,55,168,169,10,53,
  	0,0,169,170,5,6,0,0,170,234,3,2,1,54,171,172,10,52,0,0,172,173,5,7,0,
  	0,173,234,3,2,1,53,174,175,10,51,0,0,175,176,5,8,0,0,176,234,3,2,1,52,
  	177,178,10,50,0,0,178,179,5,9,0,0,179,234,3,2,1,51,180,181,10,49,0,0,
  	181,182,5,10,0,0,182,234,3,2,1,50,183,184,10,48,0,0,184,185,5,11,0,0,
  	185,234,3,2,1,49,186,187,10,47,0,0,187,188,5,12,0,0,188,234,3,2,1,48,
  	189,190,10,45,0,0,190,191,5,14,0,0,191,234,3,2,1,46,192,193,10,44,0,0,
  	193,194,5,15,0,0,194,234,3,2,1,45,195,196,10,43,0,0,196,197,5,16,0,0,
  	197,234,3,2,1,44,198,199,10,42,0,0,199,200,5,17,0,0,200,234,3,2,1,43,
  	201,202,10,41,0,0,202,203,5,18,0,0,203,234,3,2,1,42,204,205,10,40,0,0,
  	205,206,5,19,0,0,206,234,3,2,1,41,207,208,10,39,0,0,208,209,5,20,0,0,
  	209,234,3,2,1,40,210,211,10,38,0,0,211,212,5,21,0,0,212,234,3,2,1,39,
  	213,214,10,33,0,0,214,215,5,25,0,0,215,234,3,2,1,34,216,217,10,29,0,0,
  	217,218,5,32,0,0,218,219,3,2,1,0,219,220,5,34,0,0,220,221,3,2,1,30,221,
  	234,1,0,0,0,222,223,10,28,0,0,223,224,5,35,0,0,224,234,3,2,1,29,225,226,
  	10,3,0,0,226,227,5,60,0,0,227,234,3,2,1,4,228,229,10,30,0,0,229,230,5,
  	32,0,0,230,231,3,2,1,0,231,232,5,33,0,0,232,234,1,0,0,0,233,162,1,0,0,
  	0,233,165,1,0,0,0,233,168,1,0,0,0,233,171,1,0,0,0,233,174,1,0,0,0,233,
  	177,1,0,0,0,233,180,1,0,0,0,233,183,1,0,0,0,233,186,1,0,0,0,233,189,1,
  	0,0,0,233,192,1,0,0,0,233,195,1,0,0,0,233,198,1,0,0,0,233,201,1,0,0,0,
  	233,204,1,0,0,0,233,207,1,0,0,0,233,210,1,0,0,0,233,213,1,0,0,0,233,216,
  	1,0,0,0,233,222,1,0,0,0,233,225,1,0,0,0,233,228,1,0,0,0,234,237,1,0,0,
  	0,235,233,1,0,0,0,235,236,1,0,0,0,236,3,1,0,0,0,237,235,1,0,0,0,6,9,67,
  	81,160,233,235
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  scriptParserStaticData = staticData.release();
}

}

scriptParser::scriptParser(TokenStream *input) : scriptParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

scriptParser::scriptParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  scriptParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *scriptParserStaticData->atn, scriptParserStaticData->decisionToDFA, scriptParserStaticData->sharedContextCache, options);
}

scriptParser::~scriptParser() {
  delete _interpreter;
}

const atn::ATN& scriptParser::getATN() const {
  return *scriptParserStaticData->atn;
}

std::string scriptParser::getGrammarFileName() const {
  return "script.g4";
}

const std::vector<std::string>& scriptParser::getRuleNames() const {
  return scriptParserStaticData->ruleNames;
}

const dfa::Vocabulary& scriptParser::getVocabulary() const {
  return scriptParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView scriptParser::getSerializedATN() const {
  return scriptParserStaticData->serializedATN;
}


//----------------- ScriptContext ------------------------------------------------------------------

scriptParser::ScriptContext::ScriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scriptParser::ExprContext *> scriptParser::ScriptContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::ScriptContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}


size_t scriptParser::ScriptContext::getRuleIndex() const {
  return scriptParser::RuleScript;
}

void scriptParser::ScriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScript(this);
}

void scriptParser::ScriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScript(this);
}


std::any scriptParser::ScriptContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitScript(this);
  else
    return visitor->visitChildren(this);
}

scriptParser::ScriptContext* scriptParser::script() {
  ScriptContext *_localctx = _tracker.createInstance<ScriptContext>(_ctx, getState());
  enterRule(_localctx, 0, scriptParser::RuleScript);

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
    setState(9);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(4);
        expr(0);
        setState(5);
        match(scriptParser::T__0); 
      }
      setState(11);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(12);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

scriptParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t scriptParser::ExprContext::getRuleIndex() const {
  return scriptParser::RuleExpr;
}

void scriptParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarphiContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::VarphiContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::VarphiContext::VarphiContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::VarphiContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarphi(this);
}
void scriptParser::VarphiContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarphi(this);
}

std::any scriptParser::VarphiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitVarphi(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SelectContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::SelectContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::SelectContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::SelectContext::SelectContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::SelectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect(this);
}
void scriptParser::SelectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect(this);
}

std::any scriptParser::SelectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitSelect(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ModContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::ModContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::ModContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::ModContext::ModContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::ModContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMod(this);
}
void scriptParser::ModContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMod(this);
}

std::any scriptParser::ModContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitMod(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::MultContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::MultContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::MultContext::MultContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::MultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMult(this);
}
void scriptParser::MultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMult(this);
}

std::any scriptParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RfoldContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::RfoldContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::RfoldContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::RfoldContext::RfoldContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::RfoldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRfold(this);
}
void scriptParser::RfoldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRfold(this);
}

std::any scriptParser::RfoldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitRfold(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CosContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::CosContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::CosContext::CosContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::CosContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCos(this);
}
void scriptParser::CosContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCos(this);
}

std::any scriptParser::CosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitCos(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LtContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::LtContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::LtContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::LtContext::LtContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::LtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLt(this);
}
void scriptParser::LtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLt(this);
}

std::any scriptParser::LtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitLt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InvokeContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::InvokeContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::InvokeContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::InvokeContext::InvokeContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::InvokeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInvoke(this);
}
void scriptParser::InvokeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInvoke(this);
}

std::any scriptParser::InvokeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitInvoke(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PutContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::PutContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::PutContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::PutContext::PutContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::PutContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPut(this);
}
void scriptParser::PutContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPut(this);
}

std::any scriptParser::PutContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitPut(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::DivContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::DivContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::DivContext::DivContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::DivContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDiv(this);
}
void scriptParser::DivContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDiv(this);
}

std::any scriptParser::DivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::FunctionContext::VARNAME() {
  return getToken(scriptParser::VARNAME, 0);
}

std::vector<scriptParser::ExprContext *> scriptParser::FunctionContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::FunctionContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::FunctionContext::FunctionContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}
void scriptParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

std::any scriptParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SelfcrossContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::SelfcrossContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::SelfcrossContext::SelfcrossContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::SelfcrossContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelfcross(this);
}
void scriptParser::SelfcrossContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelfcross(this);
}

std::any scriptParser::SelfcrossContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitSelfcross(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeqContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::LeqContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::LeqContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::LeqContext::LeqContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::LeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeq(this);
}
void scriptParser::LeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeq(this);
}

std::any scriptParser::LeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitLeq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NeqContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::NeqContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::NeqContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::NeqContext::NeqContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::NeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNeq(this);
}
void scriptParser::NeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNeq(this);
}

std::any scriptParser::NeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitNeq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TanContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::TanContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::TanContext::TanContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::TanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTan(this);
}
void scriptParser::TanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTan(this);
}

std::any scriptParser::TanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitTan(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::AddContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::AddContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::AddContext::AddContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::AddContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd(this);
}
void scriptParser::AddContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd(this);
}

std::any scriptParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ImplyContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::ImplyContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::ImplyContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::ImplyContext::ImplyContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::ImplyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImply(this);
}
void scriptParser::ImplyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImply(this);
}

std::any scriptParser::ImplyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitImply(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EllContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::EllContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::EllContext::EllContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::EllContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEll(this);
}
void scriptParser::EllContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEll(this);
}

std::any scriptParser::EllContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitEll(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::VarContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::VarContext::VarContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::VarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar(this);
}
void scriptParser::VarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar(this);
}

std::any scriptParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_boolContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Atom_boolContext::BOOL() {
  return getToken(scriptParser::BOOL, 0);
}

scriptParser::Atom_boolContext::Atom_boolContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Atom_boolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_bool(this);
}
void scriptParser::Atom_boolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_bool(this);
}

std::any scriptParser::Atom_boolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAtom_bool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CeilContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::CeilContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::CeilContext::CeilContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::CeilContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCeil(this);
}
void scriptParser::CeilContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCeil(this);
}

std::any scriptParser::CeilContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitCeil(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConcatContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::ConcatContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::ConcatContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::ConcatContext::ConcatContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::ConcatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcat(this);
}
void scriptParser::ConcatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcat(this);
}

std::any scriptParser::ConcatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitConcat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::EqContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::EqContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::EqContext::EqContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::EqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEq(this);
}
void scriptParser::EqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEq(this);
}

std::any scriptParser::EqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitEq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContainsContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::ContainsContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::ContainsContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::ContainsContext::ContainsContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::ContainsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContains(this);
}
void scriptParser::ContainsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContains(this);
}

std::any scriptParser::ContainsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitContains(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EvalContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::EvalContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::EvalContext::EvalContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::EvalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEval(this);
}
void scriptParser::EvalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEval(this);
}

std::any scriptParser::EvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitEval(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_numberContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Atom_numberContext::NUMBER() {
  return getToken(scriptParser::NUMBER, 0);
}

scriptParser::Atom_numberContext::Atom_numberContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Atom_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_number(this);
}
void scriptParser::Atom_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_number(this);
}

std::any scriptParser::Atom_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAtom_number(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::AtContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::AtContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::AtContext::AtContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::AtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAt(this);
}
void scriptParser::AtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAt(this);
}

std::any scriptParser::AtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::SubContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::SubContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::SubContext::SubContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::SubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSub(this);
}
void scriptParser::SubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSub(this);
}

std::any scriptParser::SubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_arrayContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::Atom_arrayContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::Atom_arrayContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::Atom_arrayContext::Atom_arrayContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Atom_arrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_array(this);
}
void scriptParser::Atom_arrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_array(this);
}

std::any scriptParser::Atom_arrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAtom_array(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::LogContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::LogContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::LogContext::LogContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::LogContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLog(this);
}
void scriptParser::LogContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLog(this);
}

std::any scriptParser::LogContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitLog(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LfoldContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::LfoldContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::LfoldContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::LfoldContext::LfoldContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::LfoldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLfold(this);
}
void scriptParser::LfoldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLfold(this);
}

std::any scriptParser::LfoldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitLfold(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubstringContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::SubstringContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::SubstringContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::SubstringContext::SubstringContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::SubstringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubstring(this);
}
void scriptParser::SubstringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubstring(this);
}

std::any scriptParser::SubstringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitSubstring(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RemoveContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::RemoveContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::RemoveContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::RemoveContext::RemoveContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::RemoveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRemove(this);
}
void scriptParser::RemoveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRemove(this);
}

std::any scriptParser::RemoveContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitRemove(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::ParenContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::ParenContext::ParenContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::ParenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParen(this);
}
void scriptParser::ParenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParen(this);
}

std::any scriptParser::ParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitParen(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::NotContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::NotContext::NotContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::NotContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot(this);
}
void scriptParser::NotContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot(this);
}

std::any scriptParser::NotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GeqContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::GeqContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::GeqContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::GeqContext::GeqContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::GeqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGeq(this);
}
void scriptParser::GeqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGeq(this);
}

std::any scriptParser::GeqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitGeq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FlatContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::FlatContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::FlatContext::FlatContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::FlatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFlat(this);
}
void scriptParser::FlatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFlat(this);
}

std::any scriptParser::FlatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitFlat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::AndContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::AndContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::AndContext::AndContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::AndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnd(this);
}
void scriptParser::AndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnd(this);
}

std::any scriptParser::AndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::PowContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::PowContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::PowContext::PowContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::PowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPow(this);
}
void scriptParser::PowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPow(this);
}

std::any scriptParser::PowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitPow(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SinContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::SinContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::SinContext::SinContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::SinContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSin(this);
}
void scriptParser::SinContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSin(this);
}

std::any scriptParser::SinContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitSin(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloorContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::FloorContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::FloorContext::FloorContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::FloorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloor(this);
}
void scriptParser::FloorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloor(this);
}

std::any scriptParser::FloorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitFloor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MapContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::MapContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::MapContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::MapContext::MapContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::MapContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMap(this);
}
void scriptParser::MapContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMap(this);
}

std::any scriptParser::MapContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitMap(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::OrContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::OrContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::OrContext::OrContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::OrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOr(this);
}
void scriptParser::OrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOr(this);
}

std::any scriptParser::OrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InjContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::InjContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::InjContext::InjContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::InjContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInj(this);
}
void scriptParser::InjContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInj(this);
}

std::any scriptParser::InjContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitInj(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ApplyContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::ApplyContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::ApplyContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::ApplyContext::ApplyContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::ApplyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterApply(this);
}
void scriptParser::ApplyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitApply(this);
}

std::any scriptParser::ApplyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitApply(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CrossContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::CrossContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::CrossContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::CrossContext::CrossContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::CrossContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCross(this);
}
void scriptParser::CrossContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCross(this);
}

std::any scriptParser::CrossContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitCross(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GtContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::GtContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::GtContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::GtContext::GtContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::GtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGt(this);
}
void scriptParser::GtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGt(this);
}

std::any scriptParser::GtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitGt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FilterContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::FilterContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::FilterContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::FilterContext::FilterContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::FilterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFilter(this);
}
void scriptParser::FilterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFilter(this);
}

std::any scriptParser::FilterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitFilter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PhiContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::PhiContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::PhiContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::PhiContext::PhiContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::PhiContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhi(this);
}
void scriptParser::PhiContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhi(this);
}

std::any scriptParser::PhiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitPhi(this);
  else
    return visitor->visitChildren(this);
}
//----------------- XiContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::XiContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::XiContext::XiContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::XiContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXi(this);
}
void scriptParser::XiContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXi(this);
}

std::any scriptParser::XiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitXi(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AbsContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::AbsContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::AbsContext::AbsContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::AbsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAbs(this);
}
void scriptParser::AbsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAbs(this);
}

std::any scriptParser::AbsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAbs(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::VariableContext::VARNAME() {
  return getToken(scriptParser::VARNAME, 0);
}

scriptParser::VariableContext::VariableContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}
void scriptParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

std::any scriptParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AppendContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::AppendContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::AppendContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::AppendContext::AppendContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::AppendContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAppend(this);
}
void scriptParser::AppendContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAppend(this);
}

std::any scriptParser::AppendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAppend(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfteContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::IfteContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::IfteContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::IfteContext::IfteContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::IfteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfte(this);
}
void scriptParser::IfteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfte(this);
}

std::any scriptParser::IfteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitIfte(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_stringContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Atom_stringContext::EscapedString() {
  return getToken(scriptParser::EscapedString, 0);
}

scriptParser::Atom_stringContext::Atom_stringContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Atom_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_string(this);
}
void scriptParser::Atom_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_string(this);
}

std::any scriptParser::Atom_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAtom_string(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::AssignContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::AssignContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

scriptParser::AssignContext::AssignContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}
void scriptParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

std::any scriptParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}

scriptParser::ExprContext* scriptParser::expr() {
   return expr(0);
}

scriptParser::ExprContext* scriptParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  scriptParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  scriptParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, scriptParser::RuleExpr, precedence);

    

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
    setState(160);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(15);
      match(scriptParser::T__1);
      setState(16);
      expr(0);
      setState(17);
      match(scriptParser::T__2);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<AbsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(19);
      match(scriptParser::T__12);
      setState(20);
      expr(0);
      setState(21);
      match(scriptParser::T__12);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<EvalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(23);
      match(scriptParser::T__21);
      setState(24);
      expr(0);
      setState(25);
      match(scriptParser::T__2);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ApplyContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(27);
      match(scriptParser::T__1);
      setState(28);
      expr(0);
      setState(29);
      expr(0);
      setState(30);
      match(scriptParser::T__2);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<VarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(32);
      match(scriptParser::T__22);
      setState(33);
      expr(0);
      setState(34);
      match(scriptParser::T__2);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(36);
      match(scriptParser::T__23);
      setState(37);
      expr(34);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<IfteContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(38);
      match(scriptParser::T__25);
      setState(39);
      expr(0);
      setState(40);
      match(scriptParser::T__26);
      setState(41);
      expr(0);
      setState(42);
      match(scriptParser::T__27);
      setState(43);
      expr(32);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<SubstringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(45);
      match(scriptParser::T__28);
      setState(46);
      expr(0);
      setState(47);
      match(scriptParser::T__29);
      setState(48);
      expr(0);
      setState(49);
      match(scriptParser::T__30);
      setState(50);
      expr(0);
      setState(51);
      match(scriptParser::T__2);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<RemoveContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(53);
      match(scriptParser::T__35);
      setState(54);
      expr(0);
      setState(55);
      match(scriptParser::T__36);
      setState(56);
      expr(27);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<Atom_stringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(58);
      match(scriptParser::EscapedString);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<Atom_boolContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(59);
      match(scriptParser::BOOL);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<Atom_numberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(60);
      match(scriptParser::NUMBER);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<Atom_arrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(61);
      match(scriptParser::T__37);
      setState(67);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(62);
          expr(0);
          setState(63);
          match(scriptParser::T__29); 
        }
        setState(69);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      }
      setState(70);
      expr(0);
      setState(71);
      match(scriptParser::T__38);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<FunctionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(73);
      match(scriptParser::VARNAME);
      setState(74);
      match(scriptParser::T__39);
      setState(75);
      match(scriptParser::T__37);
      setState(81);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(76);
          expr(0);
          setState(77);
          match(scriptParser::T__0); 
        }
        setState(83);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      }
      setState(84);
      expr(0);
      setState(85);
      match(scriptParser::T__38);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(87);
      match(scriptParser::VARNAME);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<MapContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(88);
      match(scriptParser::T__40);
      setState(89);
      expr(0);
      setState(90);
      match(scriptParser::T__30);
      setState(91);
      expr(0);
      setState(92);
      match(scriptParser::T__2);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<SelectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(94);
      match(scriptParser::T__41);
      setState(95);
      expr(0);
      setState(96);
      match(scriptParser::T__30);
      setState(97);
      expr(0);
      setState(98);
      match(scriptParser::T__2);
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<FilterContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(100);
      match(scriptParser::T__42);
      setState(101);
      expr(0);
      setState(102);
      match(scriptParser::T__30);
      setState(103);
      expr(0);
      setState(104);
      match(scriptParser::T__2);
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<RfoldContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(106);
      match(scriptParser::T__43);
      setState(107);
      expr(0);
      setState(108);
      match(scriptParser::T__29);
      setState(109);
      expr(0);
      setState(110);
      match(scriptParser::T__30);
      setState(111);
      expr(0);
      setState(112);
      match(scriptParser::T__2);
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<LfoldContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(114);
      match(scriptParser::T__44);
      setState(115);
      expr(0);
      setState(116);
      match(scriptParser::T__29);
      setState(117);
      expr(0);
      setState(118);
      match(scriptParser::T__30);
      setState(119);
      expr(0);
      setState(120);
      match(scriptParser::T__2);
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<LogContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(122);
      match(scriptParser::T__45);
      setState(123);
      expr(0);
      setState(124);
      expr(15);
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<PowContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(126);
      match(scriptParser::T__46);
      setState(127);
      expr(0);
      setState(128);
      expr(14);
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<SinContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(130);
      match(scriptParser::T__47);
      setState(131);
      expr(13);
      break;
    }

    case 24: {
      _localctx = _tracker.createInstance<CosContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(132);
      match(scriptParser::T__48);
      setState(133);
      expr(12);
      break;
    }

    case 25: {
      _localctx = _tracker.createInstance<TanContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(134);
      match(scriptParser::T__49);
      setState(135);
      expr(11);
      break;
    }

    case 26: {
      _localctx = _tracker.createInstance<FloorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(136);
      match(scriptParser::T__50);
      setState(137);
      expr(0);
      setState(138);
      match(scriptParser::T__51);
      break;
    }

    case 27: {
      _localctx = _tracker.createInstance<CeilContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(140);
      match(scriptParser::T__52);
      setState(141);
      expr(0);
      setState(142);
      match(scriptParser::T__53);
      break;
    }

    case 28: {
      _localctx = _tracker.createInstance<PhiContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(144);
      match(scriptParser::T__54);
      setState(145);
      expr(0);
      setState(146);
      expr(8);
      break;
    }

    case 29: {
      _localctx = _tracker.createInstance<EllContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(148);
      match(scriptParser::T__55);
      setState(149);
      expr(7);
      break;
    }

    case 30: {
      _localctx = _tracker.createInstance<XiContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(150);
      match(scriptParser::T__56);
      setState(151);
      expr(6);
      break;
    }

    case 31: {
      _localctx = _tracker.createInstance<InjContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(152);
      match(scriptParser::T__57);
      setState(153);
      expr(5);
      break;
    }

    case 32: {
      _localctx = _tracker.createInstance<FlatContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(154);
      match(scriptParser::T__58);
      setState(155);
      expr(4);
      break;
    }

    case 33: {
      _localctx = _tracker.createInstance<SelfcrossContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(156);
      match(scriptParser::T__60);
      setState(157);
      expr(2);
      break;
    }

    case 34: {
      _localctx = _tracker.createInstance<VarphiContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(158);
      match(scriptParser::T__61);
      setState(159);
      expr(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(235);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(233);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(162);

          if (!(precpred(_ctx, 55))) throw FailedPredicateException(this, "precpred(_ctx, 55)");
          setState(163);
          match(scriptParser::T__3);
          setState(164);
          expr(56);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<SubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(165);

          if (!(precpred(_ctx, 54))) throw FailedPredicateException(this, "precpred(_ctx, 54)");
          setState(166);
          match(scriptParser::T__4);
          setState(167);
          expr(55);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<DivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(168);

          if (!(precpred(_ctx, 53))) throw FailedPredicateException(this, "precpred(_ctx, 53)");
          setState(169);
          match(scriptParser::T__5);
          setState(170);
          expr(54);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ModContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(171);

          if (!(precpred(_ctx, 52))) throw FailedPredicateException(this, "precpred(_ctx, 52)");
          setState(172);
          match(scriptParser::T__6);
          setState(173);
          expr(53);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(174);

          if (!(precpred(_ctx, 51))) throw FailedPredicateException(this, "precpred(_ctx, 51)");
          setState(175);
          match(scriptParser::T__7);
          setState(176);
          expr(52);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ConcatContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(177);

          if (!(precpred(_ctx, 50))) throw FailedPredicateException(this, "precpred(_ctx, 50)");
          setState(178);
          match(scriptParser::T__8);
          setState(179);
          expr(51);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AppendContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(180);

          if (!(precpred(_ctx, 49))) throw FailedPredicateException(this, "precpred(_ctx, 49)");
          setState(181);
          match(scriptParser::T__9);
          setState(182);
          expr(50);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<AndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(183);

          if (!(precpred(_ctx, 48))) throw FailedPredicateException(this, "precpred(_ctx, 48)");
          setState(184);
          match(scriptParser::T__10);
          setState(185);
          expr(49);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<OrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(186);

          if (!(precpred(_ctx, 47))) throw FailedPredicateException(this, "precpred(_ctx, 47)");
          setState(187);
          match(scriptParser::T__11);
          setState(188);
          expr(48);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<EqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(189);

          if (!(precpred(_ctx, 45))) throw FailedPredicateException(this, "precpred(_ctx, 45)");
          setState(190);
          match(scriptParser::T__13);
          setState(191);
          expr(46);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<NeqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(192);

          if (!(precpred(_ctx, 44))) throw FailedPredicateException(this, "precpred(_ctx, 44)");
          setState(193);
          match(scriptParser::T__14);
          setState(194);
          expr(45);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<LeqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(195);

          if (!(precpred(_ctx, 43))) throw FailedPredicateException(this, "precpred(_ctx, 43)");
          setState(196);
          match(scriptParser::T__15);
          setState(197);
          expr(44);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<GeqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(198);

          if (!(precpred(_ctx, 42))) throw FailedPredicateException(this, "precpred(_ctx, 42)");
          setState(199);
          match(scriptParser::T__16);
          setState(200);
          expr(43);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<GtContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(201);

          if (!(precpred(_ctx, 41))) throw FailedPredicateException(this, "precpred(_ctx, 41)");
          setState(202);
          match(scriptParser::T__17);
          setState(203);
          expr(42);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<LtContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(204);

          if (!(precpred(_ctx, 40))) throw FailedPredicateException(this, "precpred(_ctx, 40)");
          setState(205);
          match(scriptParser::T__18);
          setState(206);
          expr(41);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<AssignContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(207);

          if (!(precpred(_ctx, 39))) throw FailedPredicateException(this, "precpred(_ctx, 39)");
          setState(208);
          match(scriptParser::T__19);
          setState(209);
          expr(40);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<InvokeContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(210);

          if (!(precpred(_ctx, 38))) throw FailedPredicateException(this, "precpred(_ctx, 38)");
          setState(211);
          match(scriptParser::T__20);
          setState(212);
          expr(39);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<ImplyContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(213);

          if (!(precpred(_ctx, 33))) throw FailedPredicateException(this, "precpred(_ctx, 33)");
          setState(214);
          match(scriptParser::T__24);
          setState(215);
          expr(34);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<PutContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(216);

          if (!(precpred(_ctx, 29))) throw FailedPredicateException(this, "precpred(_ctx, 29)");
          setState(217);
          match(scriptParser::T__31);
          setState(218);
          expr(0);
          setState(219);
          match(scriptParser::T__33);
          setState(220);
          expr(30);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<ContainsContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(222);

          if (!(precpred(_ctx, 28))) throw FailedPredicateException(this, "precpred(_ctx, 28)");
          setState(223);
          match(scriptParser::T__34);
          setState(224);
          expr(29);
          break;
        }

        case 21: {
          auto newContext = _tracker.createInstance<CrossContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(225);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(226);
          match(scriptParser::T__59);
          setState(227);
          expr(4);
          break;
        }

        case 22: {
          auto newContext = _tracker.createInstance<AtContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(228);

          if (!(precpred(_ctx, 30))) throw FailedPredicateException(this, "precpred(_ctx, 30)");
          setState(229);
          match(scriptParser::T__31);
          setState(230);
          expr(0);
          setState(231);
          match(scriptParser::T__32);
          break;
        }

        default:
          break;
        } 
      }
      setState(237);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool scriptParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool scriptParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 55);
    case 1: return precpred(_ctx, 54);
    case 2: return precpred(_ctx, 53);
    case 3: return precpred(_ctx, 52);
    case 4: return precpred(_ctx, 51);
    case 5: return precpred(_ctx, 50);
    case 6: return precpred(_ctx, 49);
    case 7: return precpred(_ctx, 48);
    case 8: return precpred(_ctx, 47);
    case 9: return precpred(_ctx, 45);
    case 10: return precpred(_ctx, 44);
    case 11: return precpred(_ctx, 43);
    case 12: return precpred(_ctx, 42);
    case 13: return precpred(_ctx, 41);
    case 14: return precpred(_ctx, 40);
    case 15: return precpred(_ctx, 39);
    case 16: return precpred(_ctx, 38);
    case 17: return precpred(_ctx, 33);
    case 18: return precpred(_ctx, 29);
    case 19: return precpred(_ctx, 28);
    case 20: return precpred(_ctx, 3);
    case 21: return precpred(_ctx, 30);

  default:
    break;
  }
  return true;
}

void scriptParser::initialize() {
  ::antlr4::internal::call_once(scriptParserOnceFlag, scriptParserInitialize);
}
