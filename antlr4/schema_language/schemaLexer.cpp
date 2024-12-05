
// Generated from antlr4/schema_language/schema.g4 by ANTLR 4.11.1


#include "schemaLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct SchemaLexerStaticData final {
  SchemaLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SchemaLexerStaticData(const SchemaLexerStaticData&) = delete;
  SchemaLexerStaticData(SchemaLexerStaticData&&) = delete;
  SchemaLexerStaticData& operator=(const SchemaLexerStaticData&) = delete;
  SchemaLexerStaticData& operator=(SchemaLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag schemalexerLexerOnceFlag;
SchemaLexerStaticData *schemalexerLexerStaticData = nullptr;

void schemalexerLexerInitialize() {
  assert(schemalexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<SchemaLexerStaticData>(
    std::vector<std::string>{
      "SCORE", "TAG", "PROPERTY", "MULTI", "FROM", "FILE", "CSV", "XML", 
      "JSON", "LJSON", "WITH_HEADER", "SEP", "String", "UInt", "Int", "Double", 
      "LPAR", "RPAR", "LCOLL", "RCOLL", "COMMA", "MAP", "COMMENT", "DOT", 
      "EQ", "TYPE_SEP", "OFTYPE", "STAR", "LINE_COMMENT", "WS", "EscapedString", 
      "WORD"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,32,208,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,
  	4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,
  	1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,
  	1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,21,
  	1,22,1,22,1,22,1,22,5,22,154,8,22,10,22,12,22,157,9,22,1,22,1,22,1,22,
  	1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,27,1,27,1,28,
  	1,28,1,28,1,28,5,28,179,8,28,10,28,12,28,182,9,28,1,28,1,28,1,29,4,29,
  	187,8,29,11,29,12,29,188,1,29,1,29,1,30,1,30,1,30,1,30,5,30,197,8,30,
  	10,30,12,30,200,9,30,1,30,1,30,1,31,4,31,205,8,31,11,31,12,31,206,1,155,
  	0,32,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,
  	27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,
  	25,51,26,53,27,55,28,57,29,59,30,61,31,63,32,1,0,4,2,0,10,10,13,13,3,
  	0,9,10,13,13,32,32,2,0,34,34,92,92,4,0,36,36,65,90,95,95,97,122,213,0,
  	1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,
  	0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,
  	23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,
  	0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,
  	0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,
  	55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,1,65,1,
  	0,0,0,3,67,1,0,0,0,5,69,1,0,0,0,7,71,1,0,0,0,9,73,1,0,0,0,11,78,1,0,0,
  	0,13,83,1,0,0,0,15,87,1,0,0,0,17,91,1,0,0,0,19,96,1,0,0,0,21,102,1,0,
  	0,0,23,109,1,0,0,0,25,113,1,0,0,0,27,120,1,0,0,0,29,125,1,0,0,0,31,129,
  	1,0,0,0,33,136,1,0,0,0,35,138,1,0,0,0,37,140,1,0,0,0,39,142,1,0,0,0,41,
  	144,1,0,0,0,43,146,1,0,0,0,45,149,1,0,0,0,47,163,1,0,0,0,49,165,1,0,0,
  	0,51,167,1,0,0,0,53,170,1,0,0,0,55,172,1,0,0,0,57,174,1,0,0,0,59,186,
  	1,0,0,0,61,192,1,0,0,0,63,204,1,0,0,0,65,66,5,963,0,0,66,2,1,0,0,0,67,
  	68,5,120591,0,0,68,4,1,0,0,0,69,70,5,960,0,0,70,6,1,0,0,0,71,72,5,43,
  	0,0,72,8,1,0,0,0,73,74,5,70,0,0,74,75,5,82,0,0,75,76,5,79,0,0,76,77,5,
  	77,0,0,77,10,1,0,0,0,78,79,5,70,0,0,79,80,5,73,0,0,80,81,5,76,0,0,81,
  	82,5,69,0,0,82,12,1,0,0,0,83,84,5,67,0,0,84,85,5,83,0,0,85,86,5,86,0,
  	0,86,14,1,0,0,0,87,88,5,88,0,0,88,89,5,77,0,0,89,90,5,76,0,0,90,16,1,
  	0,0,0,91,92,5,74,0,0,92,93,5,83,0,0,93,94,5,79,0,0,94,95,5,78,0,0,95,
  	18,1,0,0,0,96,97,5,76,0,0,97,98,5,74,0,0,98,99,5,83,0,0,99,100,5,79,0,
  	0,100,101,5,78,0,0,101,20,1,0,0,0,102,103,5,72,0,0,103,104,5,69,0,0,104,
  	105,5,65,0,0,105,106,5,68,0,0,106,107,5,69,0,0,107,108,5,82,0,0,108,22,
  	1,0,0,0,109,110,5,83,0,0,110,111,5,69,0,0,111,112,5,80,0,0,112,24,1,0,
  	0,0,113,114,5,83,0,0,114,115,5,116,0,0,115,116,5,114,0,0,116,117,5,105,
  	0,0,117,118,5,110,0,0,118,119,5,103,0,0,119,26,1,0,0,0,120,121,5,85,0,
  	0,121,122,5,73,0,0,122,123,5,110,0,0,123,124,5,116,0,0,124,28,1,0,0,0,
  	125,126,5,73,0,0,126,127,5,110,0,0,127,128,5,116,0,0,128,30,1,0,0,0,129,
  	130,5,68,0,0,130,131,5,111,0,0,131,132,5,117,0,0,132,133,5,98,0,0,133,
  	134,5,108,0,0,134,135,5,101,0,0,135,32,1,0,0,0,136,137,5,40,0,0,137,34,
  	1,0,0,0,138,139,5,41,0,0,139,36,1,0,0,0,140,141,5,91,0,0,141,38,1,0,0,
  	0,142,143,5,93,0,0,143,40,1,0,0,0,144,145,5,44,0,0,145,42,1,0,0,0,146,
  	147,5,58,0,0,147,148,5,62,0,0,148,44,1,0,0,0,149,150,5,47,0,0,150,151,
  	5,42,0,0,151,155,1,0,0,0,152,154,9,0,0,0,153,152,1,0,0,0,154,157,1,0,
  	0,0,155,156,1,0,0,0,155,153,1,0,0,0,156,158,1,0,0,0,157,155,1,0,0,0,158,
  	159,5,42,0,0,159,160,5,47,0,0,160,161,1,0,0,0,161,162,6,22,0,0,162,46,
  	1,0,0,0,163,164,5,46,0,0,164,48,1,0,0,0,165,166,5,61,0,0,166,50,1,0,0,
  	0,167,168,5,58,0,0,168,169,5,58,0,0,169,52,1,0,0,0,170,171,5,58,0,0,171,
  	54,1,0,0,0,172,173,5,42,0,0,173,56,1,0,0,0,174,175,5,47,0,0,175,176,5,
  	47,0,0,176,180,1,0,0,0,177,179,8,0,0,0,178,177,1,0,0,0,179,182,1,0,0,
  	0,180,178,1,0,0,0,180,181,1,0,0,0,181,183,1,0,0,0,182,180,1,0,0,0,183,
  	184,6,28,0,0,184,58,1,0,0,0,185,187,7,1,0,0,186,185,1,0,0,0,187,188,1,
  	0,0,0,188,186,1,0,0,0,188,189,1,0,0,0,189,190,1,0,0,0,190,191,6,29,0,
  	0,191,60,1,0,0,0,192,198,5,34,0,0,193,197,8,2,0,0,194,195,5,92,0,0,195,
  	197,7,2,0,0,196,193,1,0,0,0,196,194,1,0,0,0,197,200,1,0,0,0,198,196,1,
  	0,0,0,198,199,1,0,0,0,199,201,1,0,0,0,200,198,1,0,0,0,201,202,5,34,0,
  	0,202,62,1,0,0,0,203,205,7,3,0,0,204,203,1,0,0,0,205,206,1,0,0,0,206,
  	204,1,0,0,0,206,207,1,0,0,0,207,64,1,0,0,0,7,0,155,180,188,196,198,206,
  	1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  schemalexerLexerStaticData = staticData.release();
}

}

schemaLexer::schemaLexer(CharStream *input) : Lexer(input) {
  schemaLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *schemalexerLexerStaticData->atn, schemalexerLexerStaticData->decisionToDFA, schemalexerLexerStaticData->sharedContextCache);
}

schemaLexer::~schemaLexer() {
  delete _interpreter;
}

std::string schemaLexer::getGrammarFileName() const {
  return "schema.g4";
}

const std::vector<std::string>& schemaLexer::getRuleNames() const {
  return schemalexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& schemaLexer::getChannelNames() const {
  return schemalexerLexerStaticData->channelNames;
}

const std::vector<std::string>& schemaLexer::getModeNames() const {
  return schemalexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& schemaLexer::getVocabulary() const {
  return schemalexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView schemaLexer::getSerializedATN() const {
  return schemalexerLexerStaticData->serializedATN;
}

const atn::ATN& schemaLexer::getATN() const {
  return *schemalexerLexerStaticData->atn;
}




void schemaLexer::initialize() {
  ::antlr4::internal::call_once(schemalexerLexerOnceFlag, schemalexerLexerInitialize);
}
