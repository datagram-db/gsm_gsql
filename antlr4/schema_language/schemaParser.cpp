
// Generated from antlr4/schema_language/schema.g4 by ANTLR 4.11.1


#include "schemaListener.h"
#include "schemaVisitor.h"

#include "schemaParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SchemaParserStaticData final {
  SchemaParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SchemaParserStaticData(const SchemaParserStaticData&) = delete;
  SchemaParserStaticData(SchemaParserStaticData&&) = delete;
  SchemaParserStaticData& operator=(const SchemaParserStaticData&) = delete;
  SchemaParserStaticData& operator=(SchemaParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag schemaParserOnceFlag;
SchemaParserStaticData *schemaParserStaticData = nullptr;

void schemaParserInitialize() {
  assert(schemaParserStaticData == nullptr);
  auto staticData = std::make_unique<SchemaParserStaticData>(
    std::vector<std::string>{
      "language", "type", "entity_declaration", "local_entity_declaration", 
      "field", "name_declar", "file", "csv"
    },
    std::vector<std::string>{
      "", "'\\u03C3'", "'\\U0001D70F'", "'\\u03C0'", "'+'", "'FROM'", "'FILE'", 
      "'CSV'", "'XML'", "'JSON'", "'LJSON'", "'HEADER'", "'SEP'", "'String'", 
      "'UInt'", "'Int'", "'Double'", "'('", "')'", "'['", "']'", "','", 
      "':>'", "", "'.'", "'='", "'::'", "':'", "'*'"
    },
    std::vector<std::string>{
      "", "SCORE", "TAG", "PROPERTY", "MULTI", "FROM", "FILE", "CSV", "XML", 
      "JSON", "LJSON", "WITH_HEADER", "SEP", "String", "UInt", "Int", "Double", 
      "LPAR", "RPAR", "LCOLL", "RCOLL", "COMMA", "MAP", "COMMENT", "DOT", 
      "EQ", "TYPE_SEP", "OFTYPE", "STAR", "LINE_COMMENT", "WS", "EscapedString", 
      "WORD"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,32,138,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,1,0,5,0,18,8,0,10,0,12,0,21,9,0,1,1,1,1,1,1,1,1,3,1,27,8,1,1,2,
  	1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,5,3,39,8,3,10,3,12,3,42,9,3,1,3,1,
  	3,1,3,1,4,3,4,48,8,4,1,4,3,4,51,8,4,1,4,3,4,54,8,4,1,4,1,4,1,4,3,4,59,
  	8,4,1,4,1,4,1,4,3,4,64,8,4,1,4,3,4,67,8,4,1,4,1,4,1,4,3,4,72,8,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,3,4,80,8,4,1,4,1,4,1,4,3,4,85,8,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,3,4,93,8,4,1,4,1,4,1,4,3,4,98,8,4,1,4,1,4,1,4,3,4,103,8,4,1,4,
  	1,4,1,4,3,4,108,8,4,1,4,1,4,1,4,3,4,113,8,4,1,5,1,5,1,5,1,5,1,6,1,6,1,
  	6,1,6,1,6,3,6,124,8,6,1,6,1,6,1,6,1,6,1,7,3,7,131,8,7,1,7,1,7,1,7,3,7,
  	136,8,7,1,7,0,0,8,0,2,4,6,8,10,12,14,0,1,1,0,2,3,156,0,19,1,0,0,0,2,26,
  	1,0,0,0,4,28,1,0,0,0,6,33,1,0,0,0,8,112,1,0,0,0,10,114,1,0,0,0,12,118,
  	1,0,0,0,14,130,1,0,0,0,16,18,3,4,2,0,17,16,1,0,0,0,18,21,1,0,0,0,19,17,
  	1,0,0,0,19,20,1,0,0,0,20,1,1,0,0,0,21,19,1,0,0,0,22,27,5,13,0,0,23,27,
  	5,14,0,0,24,27,5,15,0,0,25,27,5,16,0,0,26,22,1,0,0,0,26,23,1,0,0,0,26,
  	24,1,0,0,0,26,25,1,0,0,0,27,3,1,0,0,0,28,29,5,32,0,0,29,30,5,26,0,0,30,
  	31,3,6,3,0,31,32,3,12,6,0,32,5,1,0,0,0,33,34,5,32,0,0,34,40,5,17,0,0,
  	35,36,3,8,4,0,36,37,5,21,0,0,37,39,1,0,0,0,38,35,1,0,0,0,39,42,1,0,0,
  	0,40,38,1,0,0,0,40,41,1,0,0,0,41,43,1,0,0,0,42,40,1,0,0,0,43,44,3,8,4,
  	0,44,45,5,18,0,0,45,7,1,0,0,0,46,48,5,28,0,0,47,46,1,0,0,0,47,48,1,0,
  	0,0,48,50,1,0,0,0,49,51,7,0,0,0,50,49,1,0,0,0,50,51,1,0,0,0,51,53,1,0,
  	0,0,52,54,5,1,0,0,53,52,1,0,0,0,53,54,1,0,0,0,54,55,1,0,0,0,55,58,5,32,
  	0,0,56,57,5,22,0,0,57,59,5,31,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,60,1,
  	0,0,0,60,61,5,27,0,0,61,113,3,2,1,0,62,64,5,28,0,0,63,62,1,0,0,0,63,64,
  	1,0,0,0,64,66,1,0,0,0,65,67,7,0,0,0,66,65,1,0,0,0,66,67,1,0,0,0,67,68,
  	1,0,0,0,68,71,5,32,0,0,69,70,5,22,0,0,70,72,5,31,0,0,71,69,1,0,0,0,71,
  	72,1,0,0,0,72,73,1,0,0,0,73,74,5,25,0,0,74,75,3,10,5,0,75,76,5,24,0,0,
  	76,77,5,32,0,0,77,113,1,0,0,0,78,80,5,28,0,0,79,78,1,0,0,0,79,80,1,0,
  	0,0,80,81,1,0,0,0,81,84,5,32,0,0,82,83,5,22,0,0,83,85,5,31,0,0,84,82,
  	1,0,0,0,84,85,1,0,0,0,85,86,1,0,0,0,86,87,5,25,0,0,87,88,5,19,0,0,88,
  	89,3,6,3,0,89,90,5,20,0,0,90,113,1,0,0,0,91,93,5,28,0,0,92,91,1,0,0,0,
  	92,93,1,0,0,0,93,94,1,0,0,0,94,97,5,32,0,0,95,96,5,22,0,0,96,98,5,31,
  	0,0,97,95,1,0,0,0,97,98,1,0,0,0,98,99,1,0,0,0,99,100,5,25,0,0,100,113,
  	3,6,3,0,101,103,5,28,0,0,102,101,1,0,0,0,102,103,1,0,0,0,103,104,1,0,
  	0,0,104,107,5,32,0,0,105,106,5,22,0,0,106,108,5,31,0,0,107,105,1,0,0,
  	0,107,108,1,0,0,0,108,109,1,0,0,0,109,110,5,25,0,0,110,111,5,4,0,0,111,
  	113,3,6,3,0,112,47,1,0,0,0,112,63,1,0,0,0,112,79,1,0,0,0,112,92,1,0,0,
  	0,112,102,1,0,0,0,113,9,1,0,0,0,114,115,5,32,0,0,115,116,5,26,0,0,116,
  	117,5,32,0,0,117,11,1,0,0,0,118,123,5,5,0,0,119,124,3,14,7,0,120,124,
  	5,8,0,0,121,124,5,9,0,0,122,124,5,10,0,0,123,119,1,0,0,0,123,120,1,0,
  	0,0,123,121,1,0,0,0,123,122,1,0,0,0,124,125,1,0,0,0,125,126,5,6,0,0,126,
  	127,5,27,0,0,127,128,5,31,0,0,128,13,1,0,0,0,129,131,5,11,0,0,130,129,
  	1,0,0,0,130,131,1,0,0,0,131,132,1,0,0,0,132,135,5,7,0,0,133,134,5,12,
  	0,0,134,136,5,31,0,0,135,133,1,0,0,0,135,136,1,0,0,0,136,15,1,0,0,0,20,
  	19,26,40,47,50,53,58,63,66,71,79,84,92,97,102,107,112,123,130,135
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  schemaParserStaticData = staticData.release();
}

}

schemaParser::schemaParser(TokenStream *input) : schemaParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

schemaParser::schemaParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  schemaParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *schemaParserStaticData->atn, schemaParserStaticData->decisionToDFA, schemaParserStaticData->sharedContextCache, options);
}

schemaParser::~schemaParser() {
  delete _interpreter;
}

const atn::ATN& schemaParser::getATN() const {
  return *schemaParserStaticData->atn;
}

std::string schemaParser::getGrammarFileName() const {
  return "schema.g4";
}

const std::vector<std::string>& schemaParser::getRuleNames() const {
  return schemaParserStaticData->ruleNames;
}

const dfa::Vocabulary& schemaParser::getVocabulary() const {
  return schemaParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView schemaParser::getSerializedATN() const {
  return schemaParserStaticData->serializedATN;
}


//----------------- LanguageContext ------------------------------------------------------------------

schemaParser::LanguageContext::LanguageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<schemaParser::Entity_declarationContext *> schemaParser::LanguageContext::entity_declaration() {
  return getRuleContexts<schemaParser::Entity_declarationContext>();
}

schemaParser::Entity_declarationContext* schemaParser::LanguageContext::entity_declaration(size_t i) {
  return getRuleContext<schemaParser::Entity_declarationContext>(i);
}


size_t schemaParser::LanguageContext::getRuleIndex() const {
  return schemaParser::RuleLanguage;
}

void schemaParser::LanguageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLanguage(this);
}

void schemaParser::LanguageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLanguage(this);
}


std::any schemaParser::LanguageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitLanguage(this);
  else
    return visitor->visitChildren(this);
}

schemaParser::LanguageContext* schemaParser::language() {
  LanguageContext *_localctx = _tracker.createInstance<LanguageContext>(_ctx, getState());
  enterRule(_localctx, 0, schemaParser::RuleLanguage);
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
    setState(19);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == schemaParser::WORD) {
      setState(16);
      entity_declaration();
      setState(21);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

schemaParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t schemaParser::TypeContext::getRuleIndex() const {
  return schemaParser::RuleType;
}

void schemaParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- T_stringContext ------------------------------------------------------------------

tree::TerminalNode* schemaParser::T_stringContext::String() {
  return getToken(schemaParser::String, 0);
}

schemaParser::T_stringContext::T_stringContext(TypeContext *ctx) { copyFrom(ctx); }

void schemaParser::T_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterT_string(this);
}
void schemaParser::T_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitT_string(this);
}

std::any schemaParser::T_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitT_string(this);
  else
    return visitor->visitChildren(this);
}
//----------------- T_doubleContext ------------------------------------------------------------------

tree::TerminalNode* schemaParser::T_doubleContext::Double() {
  return getToken(schemaParser::Double, 0);
}

schemaParser::T_doubleContext::T_doubleContext(TypeContext *ctx) { copyFrom(ctx); }

void schemaParser::T_doubleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterT_double(this);
}
void schemaParser::T_doubleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitT_double(this);
}

std::any schemaParser::T_doubleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitT_double(this);
  else
    return visitor->visitChildren(this);
}
//----------------- T_uintContext ------------------------------------------------------------------

tree::TerminalNode* schemaParser::T_uintContext::UInt() {
  return getToken(schemaParser::UInt, 0);
}

schemaParser::T_uintContext::T_uintContext(TypeContext *ctx) { copyFrom(ctx); }

void schemaParser::T_uintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterT_uint(this);
}
void schemaParser::T_uintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitT_uint(this);
}

std::any schemaParser::T_uintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitT_uint(this);
  else
    return visitor->visitChildren(this);
}
//----------------- T_intContext ------------------------------------------------------------------

tree::TerminalNode* schemaParser::T_intContext::Int() {
  return getToken(schemaParser::Int, 0);
}

schemaParser::T_intContext::T_intContext(TypeContext *ctx) { copyFrom(ctx); }

void schemaParser::T_intContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterT_int(this);
}
void schemaParser::T_intContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitT_int(this);
}

std::any schemaParser::T_intContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitT_int(this);
  else
    return visitor->visitChildren(this);
}
schemaParser::TypeContext* schemaParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 2, schemaParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(26);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case schemaParser::String: {
        _localctx = _tracker.createInstance<schemaParser::T_stringContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(22);
        match(schemaParser::String);
        break;
      }

      case schemaParser::UInt: {
        _localctx = _tracker.createInstance<schemaParser::T_uintContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(23);
        match(schemaParser::UInt);
        break;
      }

      case schemaParser::Int: {
        _localctx = _tracker.createInstance<schemaParser::T_intContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(24);
        match(schemaParser::Int);
        break;
      }

      case schemaParser::Double: {
        _localctx = _tracker.createInstance<schemaParser::T_doubleContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(25);
        match(schemaParser::Double);
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

//----------------- Entity_declarationContext ------------------------------------------------------------------

schemaParser::Entity_declarationContext::Entity_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* schemaParser::Entity_declarationContext::TYPE_SEP() {
  return getToken(schemaParser::TYPE_SEP, 0);
}

schemaParser::Local_entity_declarationContext* schemaParser::Entity_declarationContext::local_entity_declaration() {
  return getRuleContext<schemaParser::Local_entity_declarationContext>(0);
}

schemaParser::FileContext* schemaParser::Entity_declarationContext::file() {
  return getRuleContext<schemaParser::FileContext>(0);
}

tree::TerminalNode* schemaParser::Entity_declarationContext::WORD() {
  return getToken(schemaParser::WORD, 0);
}


size_t schemaParser::Entity_declarationContext::getRuleIndex() const {
  return schemaParser::RuleEntity_declaration;
}

void schemaParser::Entity_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntity_declaration(this);
}

void schemaParser::Entity_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntity_declaration(this);
}


std::any schemaParser::Entity_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitEntity_declaration(this);
  else
    return visitor->visitChildren(this);
}

schemaParser::Entity_declarationContext* schemaParser::entity_declaration() {
  Entity_declarationContext *_localctx = _tracker.createInstance<Entity_declarationContext>(_ctx, getState());
  enterRule(_localctx, 4, schemaParser::RuleEntity_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    antlrcpp::downCast<Entity_declarationContext *>(_localctx)->namespace_ = match(schemaParser::WORD);
    setState(29);
    match(schemaParser::TYPE_SEP);
    setState(30);
    local_entity_declaration();
    setState(31);
    file();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Local_entity_declarationContext ------------------------------------------------------------------

schemaParser::Local_entity_declarationContext::Local_entity_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* schemaParser::Local_entity_declarationContext::LPAR() {
  return getToken(schemaParser::LPAR, 0);
}

std::vector<schemaParser::FieldContext *> schemaParser::Local_entity_declarationContext::field() {
  return getRuleContexts<schemaParser::FieldContext>();
}

schemaParser::FieldContext* schemaParser::Local_entity_declarationContext::field(size_t i) {
  return getRuleContext<schemaParser::FieldContext>(i);
}

tree::TerminalNode* schemaParser::Local_entity_declarationContext::RPAR() {
  return getToken(schemaParser::RPAR, 0);
}

tree::TerminalNode* schemaParser::Local_entity_declarationContext::WORD() {
  return getToken(schemaParser::WORD, 0);
}

std::vector<tree::TerminalNode *> schemaParser::Local_entity_declarationContext::COMMA() {
  return getTokens(schemaParser::COMMA);
}

tree::TerminalNode* schemaParser::Local_entity_declarationContext::COMMA(size_t i) {
  return getToken(schemaParser::COMMA, i);
}


size_t schemaParser::Local_entity_declarationContext::getRuleIndex() const {
  return schemaParser::RuleLocal_entity_declaration;
}

void schemaParser::Local_entity_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocal_entity_declaration(this);
}

void schemaParser::Local_entity_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocal_entity_declaration(this);
}


std::any schemaParser::Local_entity_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitLocal_entity_declaration(this);
  else
    return visitor->visitChildren(this);
}

schemaParser::Local_entity_declarationContext* schemaParser::local_entity_declaration() {
  Local_entity_declarationContext *_localctx = _tracker.createInstance<Local_entity_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, schemaParser::RuleLocal_entity_declaration);

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
    setState(33);
    antlrcpp::downCast<Local_entity_declarationContext *>(_localctx)->entity = match(schemaParser::WORD);
    setState(34);
    match(schemaParser::LPAR);
    setState(40);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(35);
        field();
        setState(36);
        match(schemaParser::COMMA); 
      }
      setState(42);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(43);
    field();
    setState(44);
    match(schemaParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldContext ------------------------------------------------------------------

schemaParser::FieldContext::FieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t schemaParser::FieldContext::getRuleIndex() const {
  return schemaParser::RuleField;
}

void schemaParser::FieldContext::copyFrom(FieldContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Native_fieldContext ------------------------------------------------------------------

tree::TerminalNode* schemaParser::Native_fieldContext::OFTYPE() {
  return getToken(schemaParser::OFTYPE, 0);
}

schemaParser::TypeContext* schemaParser::Native_fieldContext::type() {
  return getRuleContext<schemaParser::TypeContext>(0);
}

tree::TerminalNode* schemaParser::Native_fieldContext::WORD() {
  return getToken(schemaParser::WORD, 0);
}

tree::TerminalNode* schemaParser::Native_fieldContext::STAR() {
  return getToken(schemaParser::STAR, 0);
}

tree::TerminalNode* schemaParser::Native_fieldContext::SCORE() {
  return getToken(schemaParser::SCORE, 0);
}

tree::TerminalNode* schemaParser::Native_fieldContext::MAP() {
  return getToken(schemaParser::MAP, 0);
}

tree::TerminalNode* schemaParser::Native_fieldContext::TAG() {
  return getToken(schemaParser::TAG, 0);
}

tree::TerminalNode* schemaParser::Native_fieldContext::PROPERTY() {
  return getToken(schemaParser::PROPERTY, 0);
}

tree::TerminalNode* schemaParser::Native_fieldContext::EscapedString() {
  return getToken(schemaParser::EscapedString, 0);
}

schemaParser::Native_fieldContext::Native_fieldContext(FieldContext *ctx) { copyFrom(ctx); }

void schemaParser::Native_fieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNative_field(this);
}
void schemaParser::Native_fieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNative_field(this);
}

std::any schemaParser::Native_fieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitNative_field(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Multi_nested_entityContext ------------------------------------------------------------------

tree::TerminalNode* schemaParser::Multi_nested_entityContext::EQ() {
  return getToken(schemaParser::EQ, 0);
}

tree::TerminalNode* schemaParser::Multi_nested_entityContext::MULTI() {
  return getToken(schemaParser::MULTI, 0);
}

schemaParser::Local_entity_declarationContext* schemaParser::Multi_nested_entityContext::local_entity_declaration() {
  return getRuleContext<schemaParser::Local_entity_declarationContext>(0);
}

tree::TerminalNode* schemaParser::Multi_nested_entityContext::WORD() {
  return getToken(schemaParser::WORD, 0);
}

tree::TerminalNode* schemaParser::Multi_nested_entityContext::STAR() {
  return getToken(schemaParser::STAR, 0);
}

tree::TerminalNode* schemaParser::Multi_nested_entityContext::MAP() {
  return getToken(schemaParser::MAP, 0);
}

tree::TerminalNode* schemaParser::Multi_nested_entityContext::EscapedString() {
  return getToken(schemaParser::EscapedString, 0);
}

schemaParser::Multi_nested_entityContext::Multi_nested_entityContext(FieldContext *ctx) { copyFrom(ctx); }

void schemaParser::Multi_nested_entityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulti_nested_entity(this);
}
void schemaParser::Multi_nested_entityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulti_nested_entity(this);
}

std::any schemaParser::Multi_nested_entityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitMulti_nested_entity(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Local_nested_entityContext ------------------------------------------------------------------

tree::TerminalNode* schemaParser::Local_nested_entityContext::EQ() {
  return getToken(schemaParser::EQ, 0);
}

schemaParser::Local_entity_declarationContext* schemaParser::Local_nested_entityContext::local_entity_declaration() {
  return getRuleContext<schemaParser::Local_entity_declarationContext>(0);
}

tree::TerminalNode* schemaParser::Local_nested_entityContext::WORD() {
  return getToken(schemaParser::WORD, 0);
}

tree::TerminalNode* schemaParser::Local_nested_entityContext::STAR() {
  return getToken(schemaParser::STAR, 0);
}

tree::TerminalNode* schemaParser::Local_nested_entityContext::MAP() {
  return getToken(schemaParser::MAP, 0);
}

tree::TerminalNode* schemaParser::Local_nested_entityContext::EscapedString() {
  return getToken(schemaParser::EscapedString, 0);
}

schemaParser::Local_nested_entityContext::Local_nested_entityContext(FieldContext *ctx) { copyFrom(ctx); }

void schemaParser::Local_nested_entityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocal_nested_entity(this);
}
void schemaParser::Local_nested_entityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocal_nested_entity(this);
}

std::any schemaParser::Local_nested_entityContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitLocal_nested_entity(this);
  else
    return visitor->visitChildren(this);
}
//----------------- External_referenceContext ------------------------------------------------------------------

tree::TerminalNode* schemaParser::External_referenceContext::EQ() {
  return getToken(schemaParser::EQ, 0);
}

schemaParser::Name_declarContext* schemaParser::External_referenceContext::name_declar() {
  return getRuleContext<schemaParser::Name_declarContext>(0);
}

tree::TerminalNode* schemaParser::External_referenceContext::DOT() {
  return getToken(schemaParser::DOT, 0);
}

std::vector<tree::TerminalNode *> schemaParser::External_referenceContext::WORD() {
  return getTokens(schemaParser::WORD);
}

tree::TerminalNode* schemaParser::External_referenceContext::WORD(size_t i) {
  return getToken(schemaParser::WORD, i);
}

tree::TerminalNode* schemaParser::External_referenceContext::STAR() {
  return getToken(schemaParser::STAR, 0);
}

tree::TerminalNode* schemaParser::External_referenceContext::MAP() {
  return getToken(schemaParser::MAP, 0);
}

tree::TerminalNode* schemaParser::External_referenceContext::TAG() {
  return getToken(schemaParser::TAG, 0);
}

tree::TerminalNode* schemaParser::External_referenceContext::PROPERTY() {
  return getToken(schemaParser::PROPERTY, 0);
}

tree::TerminalNode* schemaParser::External_referenceContext::EscapedString() {
  return getToken(schemaParser::EscapedString, 0);
}

schemaParser::External_referenceContext::External_referenceContext(FieldContext *ctx) { copyFrom(ctx); }

void schemaParser::External_referenceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternal_reference(this);
}
void schemaParser::External_referenceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternal_reference(this);
}

std::any schemaParser::External_referenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitExternal_reference(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Local_nested_entity_listContext ------------------------------------------------------------------

tree::TerminalNode* schemaParser::Local_nested_entity_listContext::EQ() {
  return getToken(schemaParser::EQ, 0);
}

tree::TerminalNode* schemaParser::Local_nested_entity_listContext::LCOLL() {
  return getToken(schemaParser::LCOLL, 0);
}

schemaParser::Local_entity_declarationContext* schemaParser::Local_nested_entity_listContext::local_entity_declaration() {
  return getRuleContext<schemaParser::Local_entity_declarationContext>(0);
}

tree::TerminalNode* schemaParser::Local_nested_entity_listContext::RCOLL() {
  return getToken(schemaParser::RCOLL, 0);
}

tree::TerminalNode* schemaParser::Local_nested_entity_listContext::WORD() {
  return getToken(schemaParser::WORD, 0);
}

tree::TerminalNode* schemaParser::Local_nested_entity_listContext::STAR() {
  return getToken(schemaParser::STAR, 0);
}

tree::TerminalNode* schemaParser::Local_nested_entity_listContext::MAP() {
  return getToken(schemaParser::MAP, 0);
}

tree::TerminalNode* schemaParser::Local_nested_entity_listContext::EscapedString() {
  return getToken(schemaParser::EscapedString, 0);
}

schemaParser::Local_nested_entity_listContext::Local_nested_entity_listContext(FieldContext *ctx) { copyFrom(ctx); }

void schemaParser::Local_nested_entity_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocal_nested_entity_list(this);
}
void schemaParser::Local_nested_entity_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocal_nested_entity_list(this);
}

std::any schemaParser::Local_nested_entity_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitLocal_nested_entity_list(this);
  else
    return visitor->visitChildren(this);
}
schemaParser::FieldContext* schemaParser::field() {
  FieldContext *_localctx = _tracker.createInstance<FieldContext>(_ctx, getState());
  enterRule(_localctx, 8, schemaParser::RuleField);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<schemaParser::Native_fieldContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(47);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::STAR) {
        setState(46);
        match(schemaParser::STAR);
      }
      setState(50);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::TAG

      || _la == schemaParser::PROPERTY) {
        setState(49);
        _la = _input->LA(1);
        if (!(_la == schemaParser::TAG

        || _la == schemaParser::PROPERTY)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(53);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::SCORE) {
        setState(52);
        match(schemaParser::SCORE);
      }
      setState(55);
      antlrcpp::downCast<Native_fieldContext *>(_localctx)->name = match(schemaParser::WORD);
      setState(58);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::MAP) {
        setState(56);
        match(schemaParser::MAP);
        setState(57);
        antlrcpp::downCast<Native_fieldContext *>(_localctx)->map = match(schemaParser::EscapedString);
      }
      setState(60);
      match(schemaParser::OFTYPE);
      setState(61);
      type();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<schemaParser::External_referenceContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(63);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::STAR) {
        setState(62);
        match(schemaParser::STAR);
      }
      setState(66);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::TAG

      || _la == schemaParser::PROPERTY) {
        setState(65);
        _la = _input->LA(1);
        if (!(_la == schemaParser::TAG

        || _la == schemaParser::PROPERTY)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(68);
      antlrcpp::downCast<External_referenceContext *>(_localctx)->name = match(schemaParser::WORD);
      setState(71);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::MAP) {
        setState(69);
        match(schemaParser::MAP);
        setState(70);
        antlrcpp::downCast<External_referenceContext *>(_localctx)->map = match(schemaParser::EscapedString);
      }
      setState(73);
      match(schemaParser::EQ);
      setState(74);
      name_declar();
      setState(75);
      match(schemaParser::DOT);
      setState(76);
      antlrcpp::downCast<External_referenceContext *>(_localctx)->ext_field_name = match(schemaParser::WORD);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<schemaParser::Local_nested_entity_listContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(79);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::STAR) {
        setState(78);
        match(schemaParser::STAR);
      }
      setState(81);
      antlrcpp::downCast<Local_nested_entity_listContext *>(_localctx)->name = match(schemaParser::WORD);
      setState(84);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::MAP) {
        setState(82);
        match(schemaParser::MAP);
        setState(83);
        antlrcpp::downCast<Local_nested_entity_listContext *>(_localctx)->map = match(schemaParser::EscapedString);
      }
      setState(86);
      match(schemaParser::EQ);
      setState(87);
      match(schemaParser::LCOLL);
      setState(88);
      local_entity_declaration();
      setState(89);
      match(schemaParser::RCOLL);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<schemaParser::Local_nested_entityContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(92);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::STAR) {
        setState(91);
        match(schemaParser::STAR);
      }
      setState(94);
      antlrcpp::downCast<Local_nested_entityContext *>(_localctx)->name = match(schemaParser::WORD);
      setState(97);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::MAP) {
        setState(95);
        match(schemaParser::MAP);
        setState(96);
        antlrcpp::downCast<Local_nested_entityContext *>(_localctx)->map = match(schemaParser::EscapedString);
      }
      setState(99);
      match(schemaParser::EQ);
      setState(100);
      local_entity_declaration();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<schemaParser::Multi_nested_entityContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(102);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::STAR) {
        setState(101);
        match(schemaParser::STAR);
      }
      setState(104);
      antlrcpp::downCast<Multi_nested_entityContext *>(_localctx)->name = match(schemaParser::WORD);
      setState(107);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == schemaParser::MAP) {
        setState(105);
        match(schemaParser::MAP);
        setState(106);
        antlrcpp::downCast<Multi_nested_entityContext *>(_localctx)->map = match(schemaParser::EscapedString);
      }
      setState(109);
      match(schemaParser::EQ);
      setState(110);
      match(schemaParser::MULTI);
      setState(111);
      local_entity_declaration();
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

//----------------- Name_declarContext ------------------------------------------------------------------

schemaParser::Name_declarContext::Name_declarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* schemaParser::Name_declarContext::TYPE_SEP() {
  return getToken(schemaParser::TYPE_SEP, 0);
}

std::vector<tree::TerminalNode *> schemaParser::Name_declarContext::WORD() {
  return getTokens(schemaParser::WORD);
}

tree::TerminalNode* schemaParser::Name_declarContext::WORD(size_t i) {
  return getToken(schemaParser::WORD, i);
}


size_t schemaParser::Name_declarContext::getRuleIndex() const {
  return schemaParser::RuleName_declar;
}

void schemaParser::Name_declarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName_declar(this);
}

void schemaParser::Name_declarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName_declar(this);
}


std::any schemaParser::Name_declarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitName_declar(this);
  else
    return visitor->visitChildren(this);
}

schemaParser::Name_declarContext* schemaParser::name_declar() {
  Name_declarContext *_localctx = _tracker.createInstance<Name_declarContext>(_ctx, getState());
  enterRule(_localctx, 10, schemaParser::RuleName_declar);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    antlrcpp::downCast<Name_declarContext *>(_localctx)->namespace_ = match(schemaParser::WORD);
    setState(115);
    match(schemaParser::TYPE_SEP);
    setState(116);
    antlrcpp::downCast<Name_declarContext *>(_localctx)->entity = match(schemaParser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileContext ------------------------------------------------------------------

schemaParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* schemaParser::FileContext::FROM() {
  return getToken(schemaParser::FROM, 0);
}

tree::TerminalNode* schemaParser::FileContext::FILE() {
  return getToken(schemaParser::FILE, 0);
}

tree::TerminalNode* schemaParser::FileContext::OFTYPE() {
  return getToken(schemaParser::OFTYPE, 0);
}

tree::TerminalNode* schemaParser::FileContext::EscapedString() {
  return getToken(schemaParser::EscapedString, 0);
}

schemaParser::CsvContext* schemaParser::FileContext::csv() {
  return getRuleContext<schemaParser::CsvContext>(0);
}

tree::TerminalNode* schemaParser::FileContext::XML() {
  return getToken(schemaParser::XML, 0);
}

tree::TerminalNode* schemaParser::FileContext::JSON() {
  return getToken(schemaParser::JSON, 0);
}

tree::TerminalNode* schemaParser::FileContext::LJSON() {
  return getToken(schemaParser::LJSON, 0);
}


size_t schemaParser::FileContext::getRuleIndex() const {
  return schemaParser::RuleFile;
}

void schemaParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void schemaParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


std::any schemaParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

schemaParser::FileContext* schemaParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 12, schemaParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    match(schemaParser::FROM);
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case schemaParser::CSV:
      case schemaParser::WITH_HEADER: {
        setState(119);
        csv();
        break;
      }

      case schemaParser::XML: {
        setState(120);
        match(schemaParser::XML);
        break;
      }

      case schemaParser::JSON: {
        setState(121);
        match(schemaParser::JSON);
        break;
      }

      case schemaParser::LJSON: {
        setState(122);
        match(schemaParser::LJSON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(125);
    match(schemaParser::FILE);
    setState(126);
    match(schemaParser::OFTYPE);
    setState(127);
    match(schemaParser::EscapedString);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CsvContext ------------------------------------------------------------------

schemaParser::CsvContext::CsvContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* schemaParser::CsvContext::CSV() {
  return getToken(schemaParser::CSV, 0);
}

tree::TerminalNode* schemaParser::CsvContext::WITH_HEADER() {
  return getToken(schemaParser::WITH_HEADER, 0);
}

tree::TerminalNode* schemaParser::CsvContext::SEP() {
  return getToken(schemaParser::SEP, 0);
}

tree::TerminalNode* schemaParser::CsvContext::EscapedString() {
  return getToken(schemaParser::EscapedString, 0);
}


size_t schemaParser::CsvContext::getRuleIndex() const {
  return schemaParser::RuleCsv;
}

void schemaParser::CsvContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCsv(this);
}

void schemaParser::CsvContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<schemaListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCsv(this);
}


std::any schemaParser::CsvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<schemaVisitor*>(visitor))
    return parserVisitor->visitCsv(this);
  else
    return visitor->visitChildren(this);
}

schemaParser::CsvContext* schemaParser::csv() {
  CsvContext *_localctx = _tracker.createInstance<CsvContext>(_ctx, getState());
  enterRule(_localctx, 14, schemaParser::RuleCsv);
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
    setState(130);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == schemaParser::WITH_HEADER) {
      setState(129);
      match(schemaParser::WITH_HEADER);
    }
    setState(132);
    match(schemaParser::CSV);
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == schemaParser::SEP) {
      setState(133);
      match(schemaParser::SEP);
      setState(134);
      antlrcpp::downCast<CsvContext *>(_localctx)->sep = match(schemaParser::EscapedString);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void schemaParser::initialize() {
  ::antlr4::internal::call_once(schemaParserOnceFlag, schemaParserInitialize);
}
