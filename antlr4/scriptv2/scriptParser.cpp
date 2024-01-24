
// Generated from antlr4/scriptv2/script.g4 by ANTLR 4.11.1


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
      "script", "expr_block", "inner_block", "in_tuple_pair", "operand", 
      "term", "cp", "expr"
    },
    std::vector<std::string>{
      "", "';'", "'\\u21A6'", "','", "'('", "')'", "'|'", "'\\u2983'", "'\\u2984'", 
      "'\\u298B'", "'\\u298C'", "'\\u27EA'", "'\\u27EB'", "'\\u230A'", "'\\u230B'", 
      "'\\u2308'", "'\\u2309'", "'a'", "'cp'", "'+'", "'-'", "'\\u00F7'", 
      "'%'", "'\\u00B7'", "'^'", "'@'", "'\\u2227'", "'\\u2228'", "'='", 
      "'\\u2260'", "'\\u2264'", "'\\u2265'", "'>'", "'<'", "'\\u225D'", 
      "'.'", "'\\u21D2'", "'e'", "'\\u03C2'", "'['", "']'", "'\\u27E6'", 
      "'\\u27E7'", "'\\u2946'", "'\\u2208'", "'\\u03B3'", "'\\u2192'", "'\\u00B0'", 
      "'\\u03C3'", "'mod'", "'r'", "'l'", "'void'", "'\\u2534'", "'coerce'", 
      "'ObjT'", "'typeof'", "'\\U0001D6F4'", "'assert'", "'string'", "'label'", 
      "'double'", "'\\u252C'", "'bool'", "'int'", "'star'", "'kind'", "'listof'", 
      "'\\u2991'", "'\\u23A8'", "'\\u23AC'", "'{'", "'}'", "", "'\\u22CF'", 
      "'\\u22CE'", "'fun'", "'\\u00AC'", "'log'", "'pow'", "'sin'", "'cos'", 
      "'tan'", "'\\U0001D719'", "'\\u2113'", "'\\U0001D709'", "'inj'", "'J'", 
      "'flat'", "'selfx'", "'\\U0001D711'", "'\\u2A2F'", "", "'enforce_subtype'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "VOID", "BOT", "COERCE", "ObjT", "TYPEOF", "SIGMA", "ASSERT", 
      "STRINGT", "LABELT", "DOUBLET", "ANYT", "BOOLT", "INTT", "START", 
      "KIND", "LISTT", "SUBTYPE", "ALPAREN", "ARPAREN", "LPAREN", "RPAREN", 
      "BOOL", "AND_TYPE", "OR_TYPE", "FUN", "NOT", "LOG", "POW", "SIN", 
      "COS", "TAN", "PHI", "ELL", "XI", "INJ", "OBJ", "FLAT", "SELFX", "VARPHI", 
      "CROSS", "VARNAME", "ENFORCE", "EscapedString", "NUMBER", "INTEGER", 
      "SPACE", "COMMENT", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,99,293,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,3,2,26,8,2,1,3,1,3,1,3,1,3,
  	1,3,3,3,33,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,79,8,4,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,110,8,5,1,6,1,6,1,6,1,6,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,
  	7,291,8,7,1,7,0,0,8,0,2,4,6,8,10,12,14,0,0,363,0,16,1,0,0,0,2,18,1,0,
  	0,0,4,22,1,0,0,0,6,27,1,0,0,0,8,78,1,0,0,0,10,109,1,0,0,0,12,111,1,0,
  	0,0,14,290,1,0,0,0,16,17,3,4,2,0,17,1,1,0,0,0,18,19,5,71,0,0,19,20,3,
  	4,2,0,20,21,5,72,0,0,21,3,1,0,0,0,22,25,3,14,7,0,23,24,5,1,0,0,24,26,
  	3,4,2,0,25,23,1,0,0,0,25,26,1,0,0,0,26,5,1,0,0,0,27,28,5,94,0,0,28,29,
  	5,2,0,0,29,32,3,14,7,0,30,31,5,3,0,0,31,33,3,6,3,0,32,30,1,0,0,0,32,33,
  	1,0,0,0,33,7,1,0,0,0,34,79,5,95,0,0,35,79,5,73,0,0,36,79,5,94,0,0,37,
  	79,5,53,0,0,38,79,5,59,0,0,39,79,5,63,0,0,40,79,5,64,0,0,41,79,5,61,0,
  	0,42,79,5,62,0,0,43,79,5,52,0,0,44,45,5,4,0,0,45,46,3,14,7,0,46,47,5,
  	5,0,0,47,79,1,0,0,0,48,49,5,6,0,0,49,50,3,14,7,0,50,51,5,6,0,0,51,79,
  	1,0,0,0,52,53,5,7,0,0,53,54,3,14,7,0,54,55,5,8,0,0,55,79,1,0,0,0,56,57,
  	5,9,0,0,57,58,3,14,7,0,58,59,5,10,0,0,59,79,1,0,0,0,60,61,5,11,0,0,61,
  	62,3,6,3,0,62,63,5,12,0,0,63,79,1,0,0,0,64,65,5,13,0,0,65,66,3,14,7,0,
  	66,67,5,14,0,0,67,79,1,0,0,0,68,69,5,15,0,0,69,70,3,14,7,0,70,71,5,16,
  	0,0,71,79,1,0,0,0,72,73,5,17,0,0,73,79,3,2,1,0,74,75,5,60,0,0,75,79,5,
  	94,0,0,76,79,5,65,0,0,77,79,5,92,0,0,78,34,1,0,0,0,78,35,1,0,0,0,78,36,
  	1,0,0,0,78,37,1,0,0,0,78,38,1,0,0,0,78,39,1,0,0,0,78,40,1,0,0,0,78,41,
  	1,0,0,0,78,42,1,0,0,0,78,43,1,0,0,0,78,44,1,0,0,0,78,48,1,0,0,0,78,52,
  	1,0,0,0,78,56,1,0,0,0,78,60,1,0,0,0,78,64,1,0,0,0,78,68,1,0,0,0,78,72,
  	1,0,0,0,78,74,1,0,0,0,78,76,1,0,0,0,78,77,1,0,0,0,79,9,1,0,0,0,80,110,
  	3,8,4,0,81,82,5,77,0,0,82,110,3,8,4,0,83,84,5,67,0,0,84,110,3,8,4,0,85,
  	86,5,80,0,0,86,110,3,8,4,0,87,88,5,81,0,0,88,110,3,8,4,0,89,90,5,82,0,
  	0,90,110,3,8,4,0,91,92,5,84,0,0,92,110,3,8,4,0,93,94,5,85,0,0,94,110,
  	3,8,4,0,95,96,5,86,0,0,96,110,3,8,4,0,97,98,5,87,0,0,98,110,3,8,4,0,99,
  	100,5,88,0,0,100,110,3,8,4,0,101,102,5,89,0,0,102,110,3,8,4,0,103,104,
  	5,90,0,0,104,110,3,8,4,0,105,106,5,56,0,0,106,110,3,8,4,0,107,108,5,58,
  	0,0,108,110,3,8,4,0,109,80,1,0,0,0,109,81,1,0,0,0,109,83,1,0,0,0,109,
  	85,1,0,0,0,109,87,1,0,0,0,109,89,1,0,0,0,109,91,1,0,0,0,109,93,1,0,0,
  	0,109,95,1,0,0,0,109,97,1,0,0,0,109,99,1,0,0,0,109,101,1,0,0,0,109,103,
  	1,0,0,0,109,105,1,0,0,0,109,107,1,0,0,0,110,11,1,0,0,0,111,112,5,18,0,
  	0,112,113,3,10,5,0,113,114,3,10,5,0,114,13,1,0,0,0,115,291,3,10,5,0,116,
  	117,5,19,0,0,117,118,3,10,5,0,118,119,3,14,7,0,119,291,1,0,0,0,120,121,
  	5,20,0,0,121,122,3,10,5,0,122,123,3,14,7,0,123,291,1,0,0,0,124,125,5,
  	21,0,0,125,126,3,10,5,0,126,127,3,14,7,0,127,291,1,0,0,0,128,129,5,22,
  	0,0,129,130,3,10,5,0,130,131,3,14,7,0,131,291,1,0,0,0,132,133,5,23,0,
  	0,133,134,3,10,5,0,134,135,3,14,7,0,135,291,1,0,0,0,136,137,5,24,0,0,
  	137,138,3,10,5,0,138,139,3,14,7,0,139,291,1,0,0,0,140,141,5,25,0,0,141,
  	142,3,10,5,0,142,143,3,14,7,0,143,291,1,0,0,0,144,145,5,26,0,0,145,146,
  	3,10,5,0,146,147,3,14,7,0,147,291,1,0,0,0,148,149,5,27,0,0,149,150,3,
  	10,5,0,150,151,3,14,7,0,151,291,1,0,0,0,152,153,5,28,0,0,153,154,3,10,
  	5,0,154,155,3,14,7,0,155,291,1,0,0,0,156,157,5,29,0,0,157,158,3,10,5,
  	0,158,159,3,14,7,0,159,291,1,0,0,0,160,161,5,30,0,0,161,162,3,10,5,0,
  	162,163,3,14,7,0,163,291,1,0,0,0,164,165,5,31,0,0,165,166,3,10,5,0,166,
  	167,3,14,7,0,167,291,1,0,0,0,168,169,5,32,0,0,169,170,3,10,5,0,170,171,
  	3,14,7,0,171,291,1,0,0,0,172,173,5,33,0,0,173,174,3,10,5,0,174,175,3,
  	14,7,0,175,291,1,0,0,0,176,177,5,34,0,0,177,178,3,10,5,0,178,179,3,14,
  	7,0,179,291,1,0,0,0,180,181,5,35,0,0,181,182,3,10,5,0,182,183,3,14,7,
  	0,183,291,1,0,0,0,184,185,5,36,0,0,185,186,3,10,5,0,186,187,3,14,7,0,
  	187,291,1,0,0,0,188,189,5,37,0,0,189,190,3,12,6,0,190,191,3,14,7,0,191,
  	291,1,0,0,0,192,193,5,38,0,0,193,194,3,12,6,0,194,195,3,14,7,0,195,291,
  	1,0,0,0,196,197,5,39,0,0,197,198,3,10,5,0,198,199,3,14,7,0,199,200,5,
  	40,0,0,200,291,1,0,0,0,201,202,5,41,0,0,202,203,3,10,5,0,203,204,3,14,
  	7,0,204,205,5,42,0,0,205,291,1,0,0,0,206,207,5,43,0,0,207,208,3,12,6,
  	0,208,209,3,14,7,0,209,291,1,0,0,0,210,211,5,44,0,0,211,212,3,10,5,0,
  	212,213,3,14,7,0,213,291,1,0,0,0,214,215,5,45,0,0,215,216,3,10,5,0,216,
  	217,3,14,7,0,217,291,1,0,0,0,218,219,5,74,0,0,219,220,3,10,5,0,220,221,
  	3,14,7,0,221,291,1,0,0,0,222,223,5,75,0,0,223,224,3,10,5,0,224,225,3,
  	14,7,0,225,291,1,0,0,0,226,227,5,55,0,0,227,228,3,10,5,0,228,229,3,14,
  	7,0,229,291,1,0,0,0,230,231,5,69,0,0,231,232,3,6,3,0,232,233,5,70,0,0,
  	233,291,1,0,0,0,234,235,5,76,0,0,235,236,5,92,0,0,236,237,5,46,0,0,237,
  	291,3,2,1,0,238,239,5,47,0,0,239,240,3,10,5,0,240,241,3,14,7,0,241,291,
  	1,0,0,0,242,243,5,48,0,0,243,244,3,10,5,0,244,245,3,14,7,0,245,291,1,
  	0,0,0,246,247,5,49,0,0,247,248,3,10,5,0,248,249,3,14,7,0,249,291,1,0,
  	0,0,250,251,5,50,0,0,251,252,3,12,6,0,252,253,3,14,7,0,253,291,1,0,0,
  	0,254,255,5,51,0,0,255,256,3,12,6,0,256,257,3,14,7,0,257,291,1,0,0,0,
  	258,259,5,78,0,0,259,260,3,10,5,0,260,261,3,14,7,0,261,291,1,0,0,0,262,
  	263,5,79,0,0,263,264,3,10,5,0,264,265,3,14,7,0,265,291,1,0,0,0,266,267,
  	5,83,0,0,267,268,3,10,5,0,268,269,3,14,7,0,269,291,1,0,0,0,270,271,5,
  	91,0,0,271,272,3,10,5,0,272,273,3,14,7,0,273,291,1,0,0,0,274,275,5,57,
  	0,0,275,276,3,10,5,0,276,277,3,14,7,0,277,291,1,0,0,0,278,279,5,68,0,
  	0,279,280,3,10,5,0,280,281,3,14,7,0,281,291,1,0,0,0,282,283,5,93,0,0,
  	283,284,3,10,5,0,284,285,3,14,7,0,285,291,1,0,0,0,286,287,5,54,0,0,287,
  	288,3,10,5,0,288,289,3,14,7,0,289,291,1,0,0,0,290,115,1,0,0,0,290,116,
  	1,0,0,0,290,120,1,0,0,0,290,124,1,0,0,0,290,128,1,0,0,0,290,132,1,0,0,
  	0,290,136,1,0,0,0,290,140,1,0,0,0,290,144,1,0,0,0,290,148,1,0,0,0,290,
  	152,1,0,0,0,290,156,1,0,0,0,290,160,1,0,0,0,290,164,1,0,0,0,290,168,1,
  	0,0,0,290,172,1,0,0,0,290,176,1,0,0,0,290,180,1,0,0,0,290,184,1,0,0,0,
  	290,188,1,0,0,0,290,192,1,0,0,0,290,196,1,0,0,0,290,201,1,0,0,0,290,206,
  	1,0,0,0,290,210,1,0,0,0,290,214,1,0,0,0,290,218,1,0,0,0,290,222,1,0,0,
  	0,290,226,1,0,0,0,290,230,1,0,0,0,290,234,1,0,0,0,290,238,1,0,0,0,290,
  	242,1,0,0,0,290,246,1,0,0,0,290,250,1,0,0,0,290,254,1,0,0,0,290,258,1,
  	0,0,0,290,262,1,0,0,0,290,266,1,0,0,0,290,270,1,0,0,0,290,274,1,0,0,0,
  	290,278,1,0,0,0,290,282,1,0,0,0,290,286,1,0,0,0,291,15,1,0,0,0,5,25,32,
  	78,109,290
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

scriptParser::Inner_blockContext* scriptParser::ScriptContext::inner_block() {
  return getRuleContext<scriptParser::Inner_blockContext>(0);
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
    enterOuterAlt(_localctx, 1);
    setState(16);
    inner_block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_blockContext ------------------------------------------------------------------

scriptParser::Expr_blockContext::Expr_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scriptParser::Expr_blockContext::LPAREN() {
  return getToken(scriptParser::LPAREN, 0);
}

scriptParser::Inner_blockContext* scriptParser::Expr_blockContext::inner_block() {
  return getRuleContext<scriptParser::Inner_blockContext>(0);
}

tree::TerminalNode* scriptParser::Expr_blockContext::RPAREN() {
  return getToken(scriptParser::RPAREN, 0);
}


size_t scriptParser::Expr_blockContext::getRuleIndex() const {
  return scriptParser::RuleExpr_block;
}

void scriptParser::Expr_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_block(this);
}

void scriptParser::Expr_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_block(this);
}


std::any scriptParser::Expr_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitExpr_block(this);
  else
    return visitor->visitChildren(this);
}

scriptParser::Expr_blockContext* scriptParser::expr_block() {
  Expr_blockContext *_localctx = _tracker.createInstance<Expr_blockContext>(_ctx, getState());
  enterRule(_localctx, 2, scriptParser::RuleExpr_block);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    match(scriptParser::LPAREN);
    setState(19);
    inner_block();
    setState(20);
    match(scriptParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Inner_blockContext ------------------------------------------------------------------

scriptParser::Inner_blockContext::Inner_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

scriptParser::ExprContext* scriptParser::Inner_blockContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::Inner_blockContext* scriptParser::Inner_blockContext::inner_block() {
  return getRuleContext<scriptParser::Inner_blockContext>(0);
}


size_t scriptParser::Inner_blockContext::getRuleIndex() const {
  return scriptParser::RuleInner_block;
}

void scriptParser::Inner_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInner_block(this);
}

void scriptParser::Inner_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInner_block(this);
}


std::any scriptParser::Inner_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitInner_block(this);
  else
    return visitor->visitChildren(this);
}

scriptParser::Inner_blockContext* scriptParser::inner_block() {
  Inner_blockContext *_localctx = _tracker.createInstance<Inner_blockContext>(_ctx, getState());
  enterRule(_localctx, 4, scriptParser::RuleInner_block);
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
    setState(22);
    expr();
    setState(25);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scriptParser::T__0) {
      setState(23);
      match(scriptParser::T__0);
      setState(24);
      inner_block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- In_tuple_pairContext ------------------------------------------------------------------

scriptParser::In_tuple_pairContext::In_tuple_pairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scriptParser::In_tuple_pairContext::EscapedString() {
  return getToken(scriptParser::EscapedString, 0);
}

scriptParser::ExprContext* scriptParser::In_tuple_pairContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::In_tuple_pairContext* scriptParser::In_tuple_pairContext::in_tuple_pair() {
  return getRuleContext<scriptParser::In_tuple_pairContext>(0);
}


size_t scriptParser::In_tuple_pairContext::getRuleIndex() const {
  return scriptParser::RuleIn_tuple_pair;
}

void scriptParser::In_tuple_pairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIn_tuple_pair(this);
}

void scriptParser::In_tuple_pairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIn_tuple_pair(this);
}


std::any scriptParser::In_tuple_pairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitIn_tuple_pair(this);
  else
    return visitor->visitChildren(this);
}

scriptParser::In_tuple_pairContext* scriptParser::in_tuple_pair() {
  In_tuple_pairContext *_localctx = _tracker.createInstance<In_tuple_pairContext>(_ctx, getState());
  enterRule(_localctx, 6, scriptParser::RuleIn_tuple_pair);
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
    setState(27);
    match(scriptParser::EscapedString);
    setState(28);
    match(scriptParser::T__1);
    setState(29);
    expr();
    setState(32);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == scriptParser::T__2) {
      setState(30);
      match(scriptParser::T__2);
      setState(31);
      in_tuple_pair();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandContext ------------------------------------------------------------------

scriptParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t scriptParser::OperandContext::getRuleIndex() const {
  return scriptParser::RuleOperand;
}

void scriptParser::OperandContext::copyFrom(OperandContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Type_boolContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_boolContext::BOOLT() {
  return getToken(scriptParser::BOOLT, 0);
}

scriptParser::Type_boolContext::Type_boolContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_boolContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_bool(this);
}
void scriptParser::Type_boolContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_bool(this);
}

std::any scriptParser::Type_boolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_bool(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_arrayContext ------------------------------------------------------------------

scriptParser::Expr_blockContext* scriptParser::Atom_arrayContext::expr_block() {
  return getRuleContext<scriptParser::Expr_blockContext>(0);
}

scriptParser::Atom_arrayContext::Atom_arrayContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- VarContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::VarContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::VarContext::VarContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- KindContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::KindContext::START() {
  return getToken(scriptParser::START, 0);
}

scriptParser::KindContext::KindContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::KindContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKind(this);
}
void scriptParser::KindContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKind(this);
}

std::any scriptParser::KindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitKind(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_boolContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Atom_boolContext::BOOL() {
  return getToken(scriptParser::BOOL, 0);
}

scriptParser::Atom_boolContext::Atom_boolContext(OperandContext *ctx) { copyFrom(ctx); }

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

scriptParser::CeilContext::CeilContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_tupleContext ------------------------------------------------------------------

scriptParser::In_tuple_pairContext* scriptParser::Type_tupleContext::in_tuple_pair() {
  return getRuleContext<scriptParser::In_tuple_pairContext>(0);
}

scriptParser::Type_tupleContext::Type_tupleContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_tupleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_tuple(this);
}
void scriptParser::Type_tupleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_tuple(this);
}

std::any scriptParser::Type_tupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_tuple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_doubleContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_doubleContext::DOUBLET() {
  return getToken(scriptParser::DOUBLET, 0);
}

scriptParser::Type_doubleContext::Type_doubleContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_doubleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_double(this);
}
void scriptParser::Type_doubleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_double(this);
}

std::any scriptParser::Type_doubleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_double(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_stringContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_stringContext::STRINGT() {
  return getToken(scriptParser::STRINGT, 0);
}

scriptParser::Type_stringContext::Type_stringContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_stringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_string(this);
}
void scriptParser::Type_stringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_string(this);
}

std::any scriptParser::Type_stringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_string(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_anyContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_anyContext::ANYT() {
  return getToken(scriptParser::ANYT, 0);
}

scriptParser::Type_anyContext::Type_anyContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_anyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_any(this);
}
void scriptParser::Type_anyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_any(this);
}

std::any scriptParser::Type_anyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_any(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::ParenContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::ParenContext::ParenContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- Atom_numberContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Atom_numberContext::NUMBER() {
  return getToken(scriptParser::NUMBER, 0);
}

scriptParser::Atom_numberContext::Atom_numberContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- AbsContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::AbsContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::AbsContext::AbsContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- EvalContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::EvalContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::EvalContext::EvalContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- NullContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::NullContext::BOT() {
  return getToken(scriptParser::BOT, 0);
}

scriptParser::NullContext::NullContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::NullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNull(this);
}
void scriptParser::NullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNull(this);
}

std::any scriptParser::NullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitNull(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_botContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_botContext::VOID() {
  return getToken(scriptParser::VOID, 0);
}

scriptParser::Type_botContext::Type_botContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_botContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_bot(this);
}
void scriptParser::Type_botContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_bot(this);
}

std::any scriptParser::Type_botContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_bot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::VariableContext::VARNAME() {
  return getToken(scriptParser::VARNAME, 0);
}

scriptParser::VariableContext::VariableContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_labelContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_labelContext::LABELT() {
  return getToken(scriptParser::LABELT, 0);
}

tree::TerminalNode* scriptParser::Type_labelContext::EscapedString() {
  return getToken(scriptParser::EscapedString, 0);
}

scriptParser::Type_labelContext::Type_labelContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_labelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_label(this);
}
void scriptParser::Type_labelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_label(this);
}

std::any scriptParser::Type_labelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_label(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloorContext ------------------------------------------------------------------

scriptParser::ExprContext* scriptParser::FloorContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::FloorContext::FloorContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- Atom_stringContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Atom_stringContext::EscapedString() {
  return getToken(scriptParser::EscapedString, 0);
}

scriptParser::Atom_stringContext::Atom_stringContext(OperandContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_intContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_intContext::INTT() {
  return getToken(scriptParser::INTT, 0);
}

scriptParser::Type_intContext::Type_intContext(OperandContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_intContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_int(this);
}
void scriptParser::Type_intContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_int(this);
}

std::any scriptParser::Type_intContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_int(this);
  else
    return visitor->visitChildren(this);
}
scriptParser::OperandContext* scriptParser::operand() {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState());
  enterRule(_localctx, 8, scriptParser::RuleOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(78);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scriptParser::NUMBER: {
        _localctx = _tracker.createInstance<scriptParser::Atom_numberContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(34);
        match(scriptParser::NUMBER);
        break;
      }

      case scriptParser::BOOL: {
        _localctx = _tracker.createInstance<scriptParser::Atom_boolContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(35);
        match(scriptParser::BOOL);
        break;
      }

      case scriptParser::EscapedString: {
        _localctx = _tracker.createInstance<scriptParser::Atom_stringContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(36);
        match(scriptParser::EscapedString);
        break;
      }

      case scriptParser::BOT: {
        _localctx = _tracker.createInstance<scriptParser::NullContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(37);
        match(scriptParser::BOT);
        break;
      }

      case scriptParser::STRINGT: {
        _localctx = _tracker.createInstance<scriptParser::Type_stringContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(38);
        match(scriptParser::STRINGT);
        break;
      }

      case scriptParser::BOOLT: {
        _localctx = _tracker.createInstance<scriptParser::Type_boolContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(39);
        match(scriptParser::BOOLT);
        break;
      }

      case scriptParser::INTT: {
        _localctx = _tracker.createInstance<scriptParser::Type_intContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(40);
        match(scriptParser::INTT);
        break;
      }

      case scriptParser::DOUBLET: {
        _localctx = _tracker.createInstance<scriptParser::Type_doubleContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(41);
        match(scriptParser::DOUBLET);
        break;
      }

      case scriptParser::ANYT: {
        _localctx = _tracker.createInstance<scriptParser::Type_anyContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(42);
        match(scriptParser::ANYT);
        break;
      }

      case scriptParser::VOID: {
        _localctx = _tracker.createInstance<scriptParser::Type_botContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(43);
        match(scriptParser::VOID);
        break;
      }

      case scriptParser::T__3: {
        _localctx = _tracker.createInstance<scriptParser::ParenContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(44);
        match(scriptParser::T__3);
        setState(45);
        expr();
        setState(46);
        match(scriptParser::T__4);
        break;
      }

      case scriptParser::T__5: {
        _localctx = _tracker.createInstance<scriptParser::AbsContext>(_localctx);
        enterOuterAlt(_localctx, 12);
        setState(48);
        match(scriptParser::T__5);
        setState(49);
        expr();
        setState(50);
        match(scriptParser::T__5);
        break;
      }

      case scriptParser::T__6: {
        _localctx = _tracker.createInstance<scriptParser::VarContext>(_localctx);
        enterOuterAlt(_localctx, 13);
        setState(52);
        match(scriptParser::T__6);
        setState(53);
        expr();
        setState(54);
        match(scriptParser::T__7);
        break;
      }

      case scriptParser::T__8: {
        _localctx = _tracker.createInstance<scriptParser::EvalContext>(_localctx);
        enterOuterAlt(_localctx, 14);
        setState(56);
        match(scriptParser::T__8);
        setState(57);
        expr();
        setState(58);
        match(scriptParser::T__9);
        break;
      }

      case scriptParser::T__10: {
        _localctx = _tracker.createInstance<scriptParser::Type_tupleContext>(_localctx);
        enterOuterAlt(_localctx, 15);
        setState(60);
        match(scriptParser::T__10);
        setState(61);
        in_tuple_pair();
        setState(62);
        match(scriptParser::T__11);
        break;
      }

      case scriptParser::T__12: {
        _localctx = _tracker.createInstance<scriptParser::FloorContext>(_localctx);
        enterOuterAlt(_localctx, 16);
        setState(64);
        match(scriptParser::T__12);
        setState(65);
        expr();
        setState(66);
        match(scriptParser::T__13);
        break;
      }

      case scriptParser::T__14: {
        _localctx = _tracker.createInstance<scriptParser::CeilContext>(_localctx);
        enterOuterAlt(_localctx, 17);
        setState(68);
        match(scriptParser::T__14);
        setState(69);
        expr();
        setState(70);
        match(scriptParser::T__15);
        break;
      }

      case scriptParser::T__16: {
        _localctx = _tracker.createInstance<scriptParser::Atom_arrayContext>(_localctx);
        enterOuterAlt(_localctx, 18);
        setState(72);
        match(scriptParser::T__16);
        setState(73);
        expr_block();
        break;
      }

      case scriptParser::LABELT: {
        _localctx = _tracker.createInstance<scriptParser::Type_labelContext>(_localctx);
        enterOuterAlt(_localctx, 19);
        setState(74);
        match(scriptParser::LABELT);
        setState(75);
        match(scriptParser::EscapedString);
        break;
      }

      case scriptParser::START: {
        _localctx = _tracker.createInstance<scriptParser::KindContext>(_localctx);
        enterOuterAlt(_localctx, 20);
        setState(76);
        match(scriptParser::START);
        break;
      }

      case scriptParser::VARNAME: {
        _localctx = _tracker.createInstance<scriptParser::VariableContext>(_localctx);
        enterOuterAlt(_localctx, 21);
        setState(77);
        match(scriptParser::VARNAME);
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

//----------------- TermContext ------------------------------------------------------------------

scriptParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t scriptParser::TermContext::getRuleIndex() const {
  return scriptParser::RuleTerm;
}

void scriptParser::TermContext::copyFrom(TermContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TanContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::TanContext::TAN() {
  return getToken(scriptParser::TAN, 0);
}

scriptParser::OperandContext* scriptParser::TanContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::TanContext::TanContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- Term_operandContext ------------------------------------------------------------------

scriptParser::OperandContext* scriptParser::Term_operandContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::Term_operandContext::Term_operandContext(TermContext *ctx) { copyFrom(ctx); }

void scriptParser::Term_operandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm_operand(this);
}
void scriptParser::Term_operandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm_operand(this);
}

std::any scriptParser::Term_operandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitTerm_operand(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarphiContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::VarphiContext::VARPHI() {
  return getToken(scriptParser::VARPHI, 0);
}

scriptParser::OperandContext* scriptParser::VarphiContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::VarphiContext::VarphiContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- EnsureContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::EnsureContext::ASSERT() {
  return getToken(scriptParser::ASSERT, 0);
}

scriptParser::OperandContext* scriptParser::EnsureContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::EnsureContext::EnsureContext(TermContext *ctx) { copyFrom(ctx); }

void scriptParser::EnsureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnsure(this);
}
void scriptParser::EnsureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnsure(this);
}

std::any scriptParser::EnsureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitEnsure(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EllContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::EllContext::ELL() {
  return getToken(scriptParser::ELL, 0);
}

scriptParser::OperandContext* scriptParser::EllContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::EllContext::EllContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- InjContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::InjContext::INJ() {
  return getToken(scriptParser::INJ, 0);
}

scriptParser::OperandContext* scriptParser::InjContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::InjContext::InjContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- CosContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::CosContext::COS() {
  return getToken(scriptParser::COS, 0);
}

scriptParser::OperandContext* scriptParser::CosContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::CosContext::CosContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- XiContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::XiContext::XI() {
  return getToken(scriptParser::XI, 0);
}

scriptParser::OperandContext* scriptParser::XiContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::XiContext::XiContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- NotContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::NotContext::NOT() {
  return getToken(scriptParser::NOT, 0);
}

scriptParser::OperandContext* scriptParser::NotContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::NotContext::NotContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_listContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_listContext::LISTT() {
  return getToken(scriptParser::LISTT, 0);
}

scriptParser::OperandContext* scriptParser::Type_listContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::Type_listContext::Type_listContext(TermContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_list(this);
}
void scriptParser::Type_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_list(this);
}

std::any scriptParser::Type_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_list(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ObjContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::ObjContext::OBJ() {
  return getToken(scriptParser::OBJ, 0);
}

scriptParser::OperandContext* scriptParser::ObjContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::ObjContext::ObjContext(TermContext *ctx) { copyFrom(ctx); }

void scriptParser::ObjContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObj(this);
}
void scriptParser::ObjContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObj(this);
}

std::any scriptParser::ObjContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitObj(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FlatContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::FlatContext::FLAT() {
  return getToken(scriptParser::FLAT, 0);
}

scriptParser::OperandContext* scriptParser::FlatContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::FlatContext::FlatContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- SelfcrossContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::SelfcrossContext::SELFX() {
  return getToken(scriptParser::SELFX, 0);
}

scriptParser::OperandContext* scriptParser::SelfcrossContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::SelfcrossContext::SelfcrossContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- SinContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::SinContext::SIN() {
  return getToken(scriptParser::SIN, 0);
}

scriptParser::OperandContext* scriptParser::SinContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::SinContext::SinContext(TermContext *ctx) { copyFrom(ctx); }

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
//----------------- TypeofContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::TypeofContext::TYPEOF() {
  return getToken(scriptParser::TYPEOF, 0);
}

scriptParser::OperandContext* scriptParser::TypeofContext::operand() {
  return getRuleContext<scriptParser::OperandContext>(0);
}

scriptParser::TypeofContext::TypeofContext(TermContext *ctx) { copyFrom(ctx); }

void scriptParser::TypeofContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeof(this);
}
void scriptParser::TypeofContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeof(this);
}

std::any scriptParser::TypeofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitTypeof(this);
  else
    return visitor->visitChildren(this);
}
scriptParser::TermContext* scriptParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 10, scriptParser::RuleTerm);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(109);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scriptParser::T__3:
      case scriptParser::T__5:
      case scriptParser::T__6:
      case scriptParser::T__8:
      case scriptParser::T__10:
      case scriptParser::T__12:
      case scriptParser::T__14:
      case scriptParser::T__16:
      case scriptParser::VOID:
      case scriptParser::BOT:
      case scriptParser::STRINGT:
      case scriptParser::LABELT:
      case scriptParser::DOUBLET:
      case scriptParser::ANYT:
      case scriptParser::BOOLT:
      case scriptParser::INTT:
      case scriptParser::START:
      case scriptParser::BOOL:
      case scriptParser::VARNAME:
      case scriptParser::EscapedString:
      case scriptParser::NUMBER: {
        _localctx = _tracker.createInstance<scriptParser::Term_operandContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(80);
        operand();
        break;
      }

      case scriptParser::NOT: {
        _localctx = _tracker.createInstance<scriptParser::NotContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(81);
        match(scriptParser::NOT);
        setState(82);
        operand();
        break;
      }

      case scriptParser::LISTT: {
        _localctx = _tracker.createInstance<scriptParser::Type_listContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(83);
        match(scriptParser::LISTT);
        setState(84);
        operand();
        break;
      }

      case scriptParser::SIN: {
        _localctx = _tracker.createInstance<scriptParser::SinContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(85);
        match(scriptParser::SIN);
        setState(86);
        operand();
        break;
      }

      case scriptParser::COS: {
        _localctx = _tracker.createInstance<scriptParser::CosContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(87);
        match(scriptParser::COS);
        setState(88);
        operand();
        break;
      }

      case scriptParser::TAN: {
        _localctx = _tracker.createInstance<scriptParser::TanContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(89);
        match(scriptParser::TAN);
        setState(90);
        operand();
        break;
      }

      case scriptParser::ELL: {
        _localctx = _tracker.createInstance<scriptParser::EllContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(91);
        match(scriptParser::ELL);
        setState(92);
        operand();
        break;
      }

      case scriptParser::XI: {
        _localctx = _tracker.createInstance<scriptParser::XiContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(93);
        match(scriptParser::XI);
        setState(94);
        operand();
        break;
      }

      case scriptParser::INJ: {
        _localctx = _tracker.createInstance<scriptParser::InjContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(95);
        match(scriptParser::INJ);
        setState(96);
        operand();
        break;
      }

      case scriptParser::OBJ: {
        _localctx = _tracker.createInstance<scriptParser::ObjContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(97);
        match(scriptParser::OBJ);
        setState(98);
        operand();
        break;
      }

      case scriptParser::FLAT: {
        _localctx = _tracker.createInstance<scriptParser::FlatContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(99);
        match(scriptParser::FLAT);
        setState(100);
        operand();
        break;
      }

      case scriptParser::SELFX: {
        _localctx = _tracker.createInstance<scriptParser::SelfcrossContext>(_localctx);
        enterOuterAlt(_localctx, 12);
        setState(101);
        match(scriptParser::SELFX);
        setState(102);
        operand();
        break;
      }

      case scriptParser::VARPHI: {
        _localctx = _tracker.createInstance<scriptParser::VarphiContext>(_localctx);
        enterOuterAlt(_localctx, 13);
        setState(103);
        match(scriptParser::VARPHI);
        setState(104);
        operand();
        break;
      }

      case scriptParser::TYPEOF: {
        _localctx = _tracker.createInstance<scriptParser::TypeofContext>(_localctx);
        enterOuterAlt(_localctx, 14);
        setState(105);
        match(scriptParser::TYPEOF);
        setState(106);
        operand();
        break;
      }

      case scriptParser::ASSERT: {
        _localctx = _tracker.createInstance<scriptParser::EnsureContext>(_localctx);
        enterOuterAlt(_localctx, 15);
        setState(107);
        match(scriptParser::ASSERT);
        setState(108);
        operand();
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

//----------------- CpContext ------------------------------------------------------------------

scriptParser::CpContext::CpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<scriptParser::TermContext *> scriptParser::CpContext::term() {
  return getRuleContexts<scriptParser::TermContext>();
}

scriptParser::TermContext* scriptParser::CpContext::term(size_t i) {
  return getRuleContext<scriptParser::TermContext>(i);
}


size_t scriptParser::CpContext::getRuleIndex() const {
  return scriptParser::RuleCp;
}

void scriptParser::CpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCp(this);
}

void scriptParser::CpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCp(this);
}


std::any scriptParser::CpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitCp(this);
  else
    return visitor->visitChildren(this);
}

scriptParser::CpContext* scriptParser::cp() {
  CpContext *_localctx = _tracker.createInstance<CpContext>(_ctx, getState());
  enterRule(_localctx, 12, scriptParser::RuleCp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(111);
    match(scriptParser::T__17);
    setState(112);
    term();
    setState(113);
    term();
   
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

//----------------- CoerceContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::CoerceContext::COERCE() {
  return getToken(scriptParser::COERCE, 0);
}

scriptParser::TermContext* scriptParser::CoerceContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::CoerceContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::CoerceContext::CoerceContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::CoerceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCoerce(this);
}
void scriptParser::CoerceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCoerce(this);
}

std::any scriptParser::CoerceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitCoerce(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::SubContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::SubContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- ModContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::ModContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::ModContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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

scriptParser::TermContext* scriptParser::MultContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::MultContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- SelectContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::SelectContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::SelectContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- RfoldContext ------------------------------------------------------------------

scriptParser::CpContext* scriptParser::RfoldContext::cp() {
  return getRuleContext<scriptParser::CpContext>(0);
}

scriptParser::ExprContext* scriptParser::RfoldContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- LogContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::LogContext::LOG() {
  return getToken(scriptParser::LOG, 0);
}

scriptParser::TermContext* scriptParser::LogContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::LogContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- LtContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::LtContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::LtContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- ProjectContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::ProjectContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::ProjectContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::ProjectContext::ProjectContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::ProjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProject(this);
}
void scriptParser::ProjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProject(this);
}

std::any scriptParser::ProjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitProject(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LfoldContext ------------------------------------------------------------------

scriptParser::CpContext* scriptParser::LfoldContext::cp() {
  return getRuleContext<scriptParser::CpContext>(0);
}

scriptParser::ExprContext* scriptParser::LfoldContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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

scriptParser::CpContext* scriptParser::SubstringContext::cp() {
  return getRuleContext<scriptParser::CpContext>(0);
}

scriptParser::ExprContext* scriptParser::SubstringContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- PutContext ------------------------------------------------------------------

scriptParser::CpContext* scriptParser::PutContext::cp() {
  return getRuleContext<scriptParser::CpContext>(0);
}

scriptParser::ExprContext* scriptParser::PutContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- RemoveContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::RemoveContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::RemoveContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- DivContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::DivContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::DivContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- GeqContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::GeqContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::GeqContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- AndContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::AndContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::AndContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- FunctionContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::FunctionContext::FUN() {
  return getToken(scriptParser::FUN, 0);
}

tree::TerminalNode* scriptParser::FunctionContext::VARNAME() {
  return getToken(scriptParser::VARNAME, 0);
}

scriptParser::Expr_blockContext* scriptParser::FunctionContext::expr_block() {
  return getRuleContext<scriptParser::Expr_blockContext>(0);
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
//----------------- LeqContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::LeqContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::LeqContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- PowContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::PowContext::POW() {
  return getToken(scriptParser::POW, 0);
}

scriptParser::TermContext* scriptParser::PowContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::PowContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- NeqContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::NeqContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::NeqContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- MapContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::MapContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::MapContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- AddContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::AddContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::AddContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- Subtype_ofContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Subtype_ofContext::SUBTYPE() {
  return getToken(scriptParser::SUBTYPE, 0);
}

scriptParser::TermContext* scriptParser::Subtype_ofContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::Subtype_ofContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::Subtype_ofContext::Subtype_ofContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Subtype_ofContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubtype_of(this);
}
void scriptParser::Subtype_ofContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubtype_of(this);
}

std::any scriptParser::Subtype_ofContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitSubtype_of(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::OrContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::OrContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- ImplyContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::ImplyContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::ImplyContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- ApplyContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::ApplyContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::ApplyContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- Type_andContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_andContext::AND_TYPE() {
  return getToken(scriptParser::AND_TYPE, 0);
}

scriptParser::TermContext* scriptParser::Type_andContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::Type_andContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::Type_andContext::Type_andContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_andContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_and(this);
}
void scriptParser::Type_andContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_and(this);
}

std::any scriptParser::Type_andContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_and(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CrossContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::CrossContext::CROSS() {
  return getToken(scriptParser::CROSS, 0);
}

scriptParser::TermContext* scriptParser::CrossContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::CrossContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- ConcatContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::ConcatContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::ConcatContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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

scriptParser::TermContext* scriptParser::EqContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::EqContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- GtContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::GtContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::GtContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- Type_orContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_orContext::OR_TYPE() {
  return getToken(scriptParser::OR_TYPE, 0);
}

scriptParser::TermContext* scriptParser::Type_orContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::Type_orContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::Type_orContext::Type_orContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_orContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_or(this);
}
void scriptParser::Type_orContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_or(this);
}

std::any scriptParser::Type_orContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_or(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Type_lexContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_lexContext::ObjT() {
  return getToken(scriptParser::ObjT, 0);
}

scriptParser::TermContext* scriptParser::Type_lexContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::Type_lexContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::Type_lexContext::Type_lexContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Type_lexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_lex(this);
}
void scriptParser::Type_lexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_lex(this);
}

std::any scriptParser::Type_lexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitType_lex(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Atom_tupleContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Atom_tupleContext::ALPAREN() {
  return getToken(scriptParser::ALPAREN, 0);
}

scriptParser::In_tuple_pairContext* scriptParser::Atom_tupleContext::in_tuple_pair() {
  return getRuleContext<scriptParser::In_tuple_pairContext>(0);
}

tree::TerminalNode* scriptParser::Atom_tupleContext::ARPAREN() {
  return getToken(scriptParser::ARPAREN, 0);
}

scriptParser::Atom_tupleContext::Atom_tupleContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Atom_tupleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom_tuple(this);
}
void scriptParser::Atom_tupleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom_tuple(this);
}

std::any scriptParser::Atom_tupleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitAtom_tuple(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FilterContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::FilterContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::FilterContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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

tree::TerminalNode* scriptParser::PhiContext::PHI() {
  return getToken(scriptParser::PHI, 0);
}

scriptParser::TermContext* scriptParser::PhiContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::PhiContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- ContainsContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::ContainsContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::ContainsContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- Sigma_typeContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Sigma_typeContext::SIGMA() {
  return getToken(scriptParser::SIGMA, 0);
}

scriptParser::TermContext* scriptParser::Sigma_typeContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::Sigma_typeContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::Sigma_typeContext::Sigma_typeContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::Sigma_typeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSigma_type(this);
}
void scriptParser::Sigma_typeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSigma_type(this);
}

std::any scriptParser::Sigma_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitSigma_type(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::AtContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::AtContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- EnforceContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::EnforceContext::ENFORCE() {
  return getToken(scriptParser::ENFORCE, 0);
}

scriptParser::TermContext* scriptParser::EnforceContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::EnforceContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::EnforceContext::EnforceContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::EnforceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnforce(this);
}
void scriptParser::EnforceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnforce(this);
}

std::any scriptParser::EnforceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitEnforce(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprtermContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::ExprtermContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprtermContext::ExprtermContext(ExprContext *ctx) { copyFrom(ctx); }

void scriptParser::ExprtermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprterm(this);
}
void scriptParser::ExprtermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprterm(this);
}

std::any scriptParser::ExprtermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitExprterm(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AppendContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::AppendContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::AppendContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- AssignContext ------------------------------------------------------------------

scriptParser::TermContext* scriptParser::AssignContext::term() {
  return getRuleContext<scriptParser::TermContext>(0);
}

scriptParser::ExprContext* scriptParser::AssignContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
//----------------- IfteContext ------------------------------------------------------------------

scriptParser::CpContext* scriptParser::IfteContext::cp() {
  return getRuleContext<scriptParser::CpContext>(0);
}

scriptParser::ExprContext* scriptParser::IfteContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
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
scriptParser::ExprContext* scriptParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 14, scriptParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(290);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case scriptParser::T__3:
      case scriptParser::T__5:
      case scriptParser::T__6:
      case scriptParser::T__8:
      case scriptParser::T__10:
      case scriptParser::T__12:
      case scriptParser::T__14:
      case scriptParser::T__16:
      case scriptParser::VOID:
      case scriptParser::BOT:
      case scriptParser::TYPEOF:
      case scriptParser::ASSERT:
      case scriptParser::STRINGT:
      case scriptParser::LABELT:
      case scriptParser::DOUBLET:
      case scriptParser::ANYT:
      case scriptParser::BOOLT:
      case scriptParser::INTT:
      case scriptParser::START:
      case scriptParser::LISTT:
      case scriptParser::BOOL:
      case scriptParser::NOT:
      case scriptParser::SIN:
      case scriptParser::COS:
      case scriptParser::TAN:
      case scriptParser::ELL:
      case scriptParser::XI:
      case scriptParser::INJ:
      case scriptParser::OBJ:
      case scriptParser::FLAT:
      case scriptParser::SELFX:
      case scriptParser::VARPHI:
      case scriptParser::VARNAME:
      case scriptParser::EscapedString:
      case scriptParser::NUMBER: {
        _localctx = _tracker.createInstance<scriptParser::ExprtermContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(115);
        term();
        break;
      }

      case scriptParser::T__18: {
        _localctx = _tracker.createInstance<scriptParser::AddContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(116);
        match(scriptParser::T__18);
        setState(117);
        term();
        setState(118);
        expr();
        break;
      }

      case scriptParser::T__19: {
        _localctx = _tracker.createInstance<scriptParser::SubContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(120);
        match(scriptParser::T__19);
        setState(121);
        term();
        setState(122);
        expr();
        break;
      }

      case scriptParser::T__20: {
        _localctx = _tracker.createInstance<scriptParser::DivContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(124);
        match(scriptParser::T__20);
        setState(125);
        term();
        setState(126);
        expr();
        break;
      }

      case scriptParser::T__21: {
        _localctx = _tracker.createInstance<scriptParser::ModContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(128);
        match(scriptParser::T__21);
        setState(129);
        term();
        setState(130);
        expr();
        break;
      }

      case scriptParser::T__22: {
        _localctx = _tracker.createInstance<scriptParser::MultContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(132);
        match(scriptParser::T__22);
        setState(133);
        term();
        setState(134);
        expr();
        break;
      }

      case scriptParser::T__23: {
        _localctx = _tracker.createInstance<scriptParser::ConcatContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(136);
        match(scriptParser::T__23);
        setState(137);
        term();
        setState(138);
        expr();
        break;
      }

      case scriptParser::T__24: {
        _localctx = _tracker.createInstance<scriptParser::AppendContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(140);
        match(scriptParser::T__24);
        setState(141);
        term();
        setState(142);
        expr();
        break;
      }

      case scriptParser::T__25: {
        _localctx = _tracker.createInstance<scriptParser::AndContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(144);
        match(scriptParser::T__25);
        setState(145);
        term();
        setState(146);
        expr();
        break;
      }

      case scriptParser::T__26: {
        _localctx = _tracker.createInstance<scriptParser::OrContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(148);
        match(scriptParser::T__26);
        setState(149);
        term();
        setState(150);
        expr();
        break;
      }

      case scriptParser::T__27: {
        _localctx = _tracker.createInstance<scriptParser::EqContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(152);
        match(scriptParser::T__27);
        setState(153);
        term();
        setState(154);
        expr();
        break;
      }

      case scriptParser::T__28: {
        _localctx = _tracker.createInstance<scriptParser::NeqContext>(_localctx);
        enterOuterAlt(_localctx, 12);
        setState(156);
        match(scriptParser::T__28);
        setState(157);
        term();
        setState(158);
        expr();
        break;
      }

      case scriptParser::T__29: {
        _localctx = _tracker.createInstance<scriptParser::LeqContext>(_localctx);
        enterOuterAlt(_localctx, 13);
        setState(160);
        match(scriptParser::T__29);
        setState(161);
        term();
        setState(162);
        expr();
        break;
      }

      case scriptParser::T__30: {
        _localctx = _tracker.createInstance<scriptParser::GeqContext>(_localctx);
        enterOuterAlt(_localctx, 14);
        setState(164);
        match(scriptParser::T__30);
        setState(165);
        term();
        setState(166);
        expr();
        break;
      }

      case scriptParser::T__31: {
        _localctx = _tracker.createInstance<scriptParser::GtContext>(_localctx);
        enterOuterAlt(_localctx, 15);
        setState(168);
        match(scriptParser::T__31);
        setState(169);
        term();
        setState(170);
        expr();
        break;
      }

      case scriptParser::T__32: {
        _localctx = _tracker.createInstance<scriptParser::LtContext>(_localctx);
        enterOuterAlt(_localctx, 16);
        setState(172);
        match(scriptParser::T__32);
        setState(173);
        term();
        setState(174);
        expr();
        break;
      }

      case scriptParser::T__33: {
        _localctx = _tracker.createInstance<scriptParser::AssignContext>(_localctx);
        enterOuterAlt(_localctx, 17);
        setState(176);
        match(scriptParser::T__33);
        setState(177);
        term();
        setState(178);
        expr();
        break;
      }

      case scriptParser::T__34: {
        _localctx = _tracker.createInstance<scriptParser::ApplyContext>(_localctx);
        enterOuterAlt(_localctx, 18);
        setState(180);
        match(scriptParser::T__34);
        setState(181);
        term();
        setState(182);
        expr();
        break;
      }

      case scriptParser::T__35: {
        _localctx = _tracker.createInstance<scriptParser::ImplyContext>(_localctx);
        enterOuterAlt(_localctx, 19);
        setState(184);
        match(scriptParser::T__35);
        setState(185);
        term();
        setState(186);
        expr();
        break;
      }

      case scriptParser::T__36: {
        _localctx = _tracker.createInstance<scriptParser::IfteContext>(_localctx);
        enterOuterAlt(_localctx, 20);
        setState(188);
        match(scriptParser::T__36);
        setState(189);
        cp();
        setState(190);
        expr();
        break;
      }

      case scriptParser::T__37: {
        _localctx = _tracker.createInstance<scriptParser::SubstringContext>(_localctx);
        enterOuterAlt(_localctx, 21);
        setState(192);
        match(scriptParser::T__37);
        setState(193);
        cp();
        setState(194);
        expr();
        break;
      }

      case scriptParser::T__38: {
        _localctx = _tracker.createInstance<scriptParser::AtContext>(_localctx);
        enterOuterAlt(_localctx, 22);
        setState(196);
        match(scriptParser::T__38);
        setState(197);
        term();
        setState(198);
        expr();
        setState(199);
        match(scriptParser::T__39);
        break;
      }

      case scriptParser::T__40: {
        _localctx = _tracker.createInstance<scriptParser::ProjectContext>(_localctx);
        enterOuterAlt(_localctx, 23);
        setState(201);
        match(scriptParser::T__40);
        setState(202);
        term();
        setState(203);
        expr();
        setState(204);
        match(scriptParser::T__41);
        break;
      }

      case scriptParser::T__42: {
        _localctx = _tracker.createInstance<scriptParser::PutContext>(_localctx);
        enterOuterAlt(_localctx, 24);
        setState(206);
        match(scriptParser::T__42);
        setState(207);
        cp();
        setState(208);
        expr();
        break;
      }

      case scriptParser::T__43: {
        _localctx = _tracker.createInstance<scriptParser::ContainsContext>(_localctx);
        enterOuterAlt(_localctx, 25);
        setState(210);
        match(scriptParser::T__43);
        setState(211);
        term();
        setState(212);
        expr();
        break;
      }

      case scriptParser::T__44: {
        _localctx = _tracker.createInstance<scriptParser::RemoveContext>(_localctx);
        enterOuterAlt(_localctx, 26);
        setState(214);
        match(scriptParser::T__44);
        setState(215);
        term();
        setState(216);
        expr();
        break;
      }

      case scriptParser::AND_TYPE: {
        _localctx = _tracker.createInstance<scriptParser::Type_andContext>(_localctx);
        enterOuterAlt(_localctx, 27);
        setState(218);
        match(scriptParser::AND_TYPE);
        setState(219);
        term();
        setState(220);
        expr();
        break;
      }

      case scriptParser::OR_TYPE: {
        _localctx = _tracker.createInstance<scriptParser::Type_orContext>(_localctx);
        enterOuterAlt(_localctx, 28);
        setState(222);
        match(scriptParser::OR_TYPE);
        setState(223);
        term();
        setState(224);
        expr();
        break;
      }

      case scriptParser::ObjT: {
        _localctx = _tracker.createInstance<scriptParser::Type_lexContext>(_localctx);
        enterOuterAlt(_localctx, 29);
        setState(226);
        match(scriptParser::ObjT);
        setState(227);
        term();
        setState(228);
        expr();
        break;
      }

      case scriptParser::ALPAREN: {
        _localctx = _tracker.createInstance<scriptParser::Atom_tupleContext>(_localctx);
        enterOuterAlt(_localctx, 30);
        setState(230);
        match(scriptParser::ALPAREN);
        setState(231);
        in_tuple_pair();
        setState(232);
        match(scriptParser::ARPAREN);
        break;
      }

      case scriptParser::FUN: {
        _localctx = _tracker.createInstance<scriptParser::FunctionContext>(_localctx);
        enterOuterAlt(_localctx, 31);
        setState(234);
        match(scriptParser::FUN);
        setState(235);
        match(scriptParser::VARNAME);
        setState(236);
        match(scriptParser::T__45);
        setState(237);
        expr_block();
        break;
      }

      case scriptParser::T__46: {
        _localctx = _tracker.createInstance<scriptParser::MapContext>(_localctx);
        enterOuterAlt(_localctx, 32);
        setState(238);
        match(scriptParser::T__46);
        setState(239);
        term();
        setState(240);
        expr();
        break;
      }

      case scriptParser::T__47: {
        _localctx = _tracker.createInstance<scriptParser::SelectContext>(_localctx);
        enterOuterAlt(_localctx, 33);
        setState(242);
        match(scriptParser::T__47);
        setState(243);
        term();
        setState(244);
        expr();
        break;
      }

      case scriptParser::T__48: {
        _localctx = _tracker.createInstance<scriptParser::FilterContext>(_localctx);
        enterOuterAlt(_localctx, 34);
        setState(246);
        match(scriptParser::T__48);
        setState(247);
        term();
        setState(248);
        expr();
        break;
      }

      case scriptParser::T__49: {
        _localctx = _tracker.createInstance<scriptParser::RfoldContext>(_localctx);
        enterOuterAlt(_localctx, 35);
        setState(250);
        match(scriptParser::T__49);
        setState(251);
        cp();
        setState(252);
        expr();
        break;
      }

      case scriptParser::T__50: {
        _localctx = _tracker.createInstance<scriptParser::LfoldContext>(_localctx);
        enterOuterAlt(_localctx, 36);
        setState(254);
        match(scriptParser::T__50);
        setState(255);
        cp();
        setState(256);
        expr();
        break;
      }

      case scriptParser::LOG: {
        _localctx = _tracker.createInstance<scriptParser::LogContext>(_localctx);
        enterOuterAlt(_localctx, 37);
        setState(258);
        match(scriptParser::LOG);
        setState(259);
        term();
        setState(260);
        expr();
        break;
      }

      case scriptParser::POW: {
        _localctx = _tracker.createInstance<scriptParser::PowContext>(_localctx);
        enterOuterAlt(_localctx, 38);
        setState(262);
        match(scriptParser::POW);
        setState(263);
        term();
        setState(264);
        expr();
        break;
      }

      case scriptParser::PHI: {
        _localctx = _tracker.createInstance<scriptParser::PhiContext>(_localctx);
        enterOuterAlt(_localctx, 39);
        setState(266);
        match(scriptParser::PHI);
        setState(267);
        term();
        setState(268);
        expr();
        break;
      }

      case scriptParser::CROSS: {
        _localctx = _tracker.createInstance<scriptParser::CrossContext>(_localctx);
        enterOuterAlt(_localctx, 40);
        setState(270);
        match(scriptParser::CROSS);
        setState(271);
        term();
        setState(272);
        expr();
        break;
      }

      case scriptParser::SIGMA: {
        _localctx = _tracker.createInstance<scriptParser::Sigma_typeContext>(_localctx);
        enterOuterAlt(_localctx, 41);
        setState(274);
        match(scriptParser::SIGMA);
        setState(275);
        term();
        setState(276);
        expr();
        break;
      }

      case scriptParser::SUBTYPE: {
        _localctx = _tracker.createInstance<scriptParser::Subtype_ofContext>(_localctx);
        enterOuterAlt(_localctx, 42);
        setState(278);
        match(scriptParser::SUBTYPE);
        setState(279);
        term();
        setState(280);
        expr();
        break;
      }

      case scriptParser::ENFORCE: {
        _localctx = _tracker.createInstance<scriptParser::EnforceContext>(_localctx);
        enterOuterAlt(_localctx, 43);
        setState(282);
        match(scriptParser::ENFORCE);
        setState(283);
        term();
        setState(284);
        expr();
        break;
      }

      case scriptParser::COERCE: {
        _localctx = _tracker.createInstance<scriptParser::CoerceContext>(_localctx);
        enterOuterAlt(_localctx, 44);
        setState(286);
        match(scriptParser::COERCE);
        setState(287);
        term();
        setState(288);
        expr();
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

void scriptParser::initialize() {
  ::antlr4::internal::call_once(scriptParserOnceFlag, scriptParserInitialize);
}
