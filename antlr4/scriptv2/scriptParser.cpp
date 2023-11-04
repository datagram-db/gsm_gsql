
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
      "script", "tuple_pair", "expr"
    },
    std::vector<std::string>{
      "", "';'", "'>>'", "'('", "')'", "'+'", "'-'", "'/'", "'%'", "'*'", 
      "'++'", "'@'", "'&&'", "'||'", "'|'", "'=='", "'!='", "'<='", "'>='", 
      "':='", "'var('", "'eval('", "'=>'", "'sub('", "','", "':'", "'['", 
      "']'", "'[['", "']]'", "']:='", "'in'", "'t<'", "'->'", "'map('", 
      "'select('", "'filter('", "'rfold('", "'lfold('", "'|_'", "'_|'", 
      "'|-'", "'-|'", "'where'", "'as'", "'void'", "", "'coerce'", "'ObjT'", 
      "'typeof'", "'sigma'", "'assert'", "'string'", "'label'", "'double'", 
      "", "'bool'", "'int'", "'star'", "'kind'", "'listof'", "'<:'", "'<'", 
      "'>'", "'{'", "'}'", "", "'/\\'", "'\\/'", "'fun'", "'not'", "'if'", 
      "'then'", "'else'", "'remove'", "'from'", "'log'", "'pow'", "'sin'", 
      "'cos'", "'tan'", "'phi'", "'ell'", "'xi'", "'inj'", "'OBJ'", "'flat'", 
      "'selfx'", "'varphi'", "'cross'", "'script'", "'gsql'", "'CREATEDB'", 
      "", "'CREATE'", "'ELECT'", "'MAP'", "'DISJOINT'", "'FOLD'", "'enforce_subtype'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "VOID", "BOT", "COERCE", 
      "ObjT", "TYPEOF", "SIGMA", "ASSERT", "STRINGT", "LABELT", "DOUBLET", 
      "ANYT", "BOOLT", "INTT", "START", "KIND", "LISTT", "SUBTYPE", "ALPAREN", 
      "ARPAREN", "LPAREN", "RPAREN", "BOOL", "AND_TYPE", "OR_TYPE", "FUN", 
      "NOT", "IF", "THEN", "ELSE", "REMOVE", "FROM", "LOG", "POW", "SIN", 
      "COS", "TAN", "PHI", "ELL", "XI", "INJ", "OBJ", "FLAT", "SELFX", "VARPHI", 
      "CROSS", "SCRIPT", "GSQL", "CREATEDB", "VARNAME", "CREATE", "ELECT", 
      "MAP", "DISJOINT", "FOLD", "ENFORCE", "EscapedString", "NUMBER", "INTEGER", 
      "SPACE", "COMMENT", "LINE_COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,105,317,2,0,7,0,2,1,7,1,2,2,7,2,1,0,1,0,1,0,5,0,10,8,0,10,0,12,0,
  	13,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,79,8,2,10,2,
  	12,2,82,9,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,5,2,99,8,2,10,2,12,2,102,9,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,112,
  	8,2,10,2,12,2,115,9,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,127,
  	8,2,10,2,12,2,130,9,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,228,8,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,312,8,2,10,2,12,2,315,
  	9,2,1,2,0,1,4,3,0,2,4,0,0,395,0,11,1,0,0,0,2,16,1,0,0,0,4,227,1,0,0,0,
  	6,7,3,4,2,0,7,8,5,1,0,0,8,10,1,0,0,0,9,6,1,0,0,0,10,13,1,0,0,0,11,9,1,
  	0,0,0,11,12,1,0,0,0,12,14,1,0,0,0,13,11,1,0,0,0,14,15,3,4,2,0,15,1,1,
  	0,0,0,16,17,5,100,0,0,17,18,5,2,0,0,18,19,3,4,2,0,19,3,1,0,0,0,20,21,
  	6,2,-1,0,21,22,5,3,0,0,22,23,3,4,2,0,23,24,5,4,0,0,24,228,1,0,0,0,25,
  	26,5,14,0,0,26,27,3,4,2,0,27,28,5,14,0,0,28,228,1,0,0,0,29,30,5,3,0,0,
  	30,31,3,4,2,0,31,32,3,4,2,0,32,33,5,4,0,0,33,228,1,0,0,0,34,35,5,20,0,
  	0,35,36,3,4,2,0,36,37,5,4,0,0,37,228,1,0,0,0,38,39,5,21,0,0,39,40,3,4,
  	2,0,40,41,5,4,0,0,41,228,1,0,0,0,42,43,5,70,0,0,43,228,3,4,2,57,44,45,
  	5,71,0,0,45,46,3,4,2,0,46,47,5,72,0,0,47,48,3,4,2,0,48,49,5,73,0,0,49,
  	50,3,4,2,55,50,228,1,0,0,0,51,52,5,23,0,0,52,53,3,4,2,0,53,54,5,24,0,
  	0,54,55,3,4,2,0,55,56,5,25,0,0,56,57,3,4,2,0,57,58,5,4,0,0,58,228,1,0,
  	0,0,59,60,5,74,0,0,60,61,3,4,2,0,61,62,5,75,0,0,62,63,3,4,2,49,63,228,
  	1,0,0,0,64,228,5,101,0,0,65,228,5,66,0,0,66,228,5,100,0,0,67,228,5,46,
  	0,0,68,228,5,52,0,0,69,228,5,56,0,0,70,228,5,57,0,0,71,228,5,54,0,0,72,
  	73,5,60,0,0,73,228,3,4,2,38,74,80,5,32,0,0,75,76,3,2,1,0,76,77,5,1,0,
  	0,77,79,1,0,0,0,78,75,1,0,0,0,79,82,1,0,0,0,80,78,1,0,0,0,80,81,1,0,0,
  	0,81,83,1,0,0,0,82,80,1,0,0,0,83,84,3,2,1,0,84,85,5,63,0,0,85,228,1,0,
  	0,0,86,228,5,55,0,0,87,228,5,45,0,0,88,89,5,53,0,0,89,228,5,100,0,0,90,
  	91,5,48,0,0,91,92,3,4,2,0,92,93,3,4,2,33,93,228,1,0,0,0,94,100,5,64,0,
  	0,95,96,3,4,2,0,96,97,5,1,0,0,97,99,1,0,0,0,98,95,1,0,0,0,99,102,1,0,
  	0,0,100,98,1,0,0,0,100,101,1,0,0,0,101,103,1,0,0,0,102,100,1,0,0,0,103,
  	104,3,4,2,0,104,105,5,65,0,0,105,228,1,0,0,0,106,228,5,58,0,0,107,113,
  	5,62,0,0,108,109,3,2,1,0,109,110,5,1,0,0,110,112,1,0,0,0,111,108,1,0,
  	0,0,112,115,1,0,0,0,113,111,1,0,0,0,113,114,1,0,0,0,114,116,1,0,0,0,115,
  	113,1,0,0,0,116,117,3,2,1,0,117,118,5,63,0,0,118,228,1,0,0,0,119,120,
  	5,69,0,0,120,121,5,93,0,0,121,122,5,33,0,0,122,128,5,64,0,0,123,124,3,
  	4,2,0,124,125,5,1,0,0,125,127,1,0,0,0,126,123,1,0,0,0,127,130,1,0,0,0,
  	128,126,1,0,0,0,128,129,1,0,0,0,129,131,1,0,0,0,130,128,1,0,0,0,131,132,
  	3,4,2,0,132,133,5,65,0,0,133,228,1,0,0,0,134,228,5,93,0,0,135,136,5,34,
  	0,0,136,137,3,4,2,0,137,138,5,25,0,0,138,139,3,4,2,0,139,140,5,4,0,0,
  	140,228,1,0,0,0,141,142,5,35,0,0,142,143,3,4,2,0,143,144,5,25,0,0,144,
  	145,3,4,2,0,145,146,5,4,0,0,146,228,1,0,0,0,147,148,5,36,0,0,148,149,
  	3,4,2,0,149,150,5,25,0,0,150,151,3,4,2,0,151,152,5,4,0,0,152,228,1,0,
  	0,0,153,154,5,37,0,0,154,155,3,4,2,0,155,156,5,24,0,0,156,157,3,4,2,0,
  	157,158,5,25,0,0,158,159,3,4,2,0,159,160,5,4,0,0,160,228,1,0,0,0,161,
  	162,5,38,0,0,162,163,3,4,2,0,163,164,5,24,0,0,164,165,3,4,2,0,165,166,
  	5,25,0,0,166,167,3,4,2,0,167,168,5,4,0,0,168,228,1,0,0,0,169,170,5,76,
  	0,0,170,171,3,4,2,0,171,172,3,4,2,22,172,228,1,0,0,0,173,174,5,77,0,0,
  	174,175,3,4,2,0,175,176,3,4,2,21,176,228,1,0,0,0,177,178,5,78,0,0,178,
  	228,3,4,2,20,179,180,5,79,0,0,180,228,3,4,2,19,181,182,5,80,0,0,182,228,
  	3,4,2,18,183,184,5,39,0,0,184,185,3,4,2,0,185,186,5,40,0,0,186,228,1,
  	0,0,0,187,188,5,41,0,0,188,189,3,4,2,0,189,190,5,42,0,0,190,228,1,0,0,
  	0,191,192,5,81,0,0,192,193,3,4,2,0,193,194,3,4,2,15,194,228,1,0,0,0,195,
  	196,5,82,0,0,196,228,3,4,2,14,197,198,5,83,0,0,198,228,3,4,2,13,199,200,
  	5,84,0,0,200,228,3,4,2,12,201,202,5,85,0,0,202,228,3,4,2,11,203,204,5,
  	86,0,0,204,228,3,4,2,10,205,206,5,89,0,0,206,207,3,4,2,0,207,208,3,4,
  	2,9,208,228,1,0,0,0,209,210,5,87,0,0,210,228,3,4,2,8,211,212,5,88,0,0,
  	212,228,3,4,2,7,213,214,5,49,0,0,214,228,3,4,2,6,215,216,5,50,0,0,216,
  	217,3,4,2,0,217,218,5,43,0,0,218,219,3,4,2,5,219,228,1,0,0,0,220,221,
  	5,51,0,0,221,228,3,4,2,3,222,223,5,47,0,0,223,224,3,4,2,0,224,225,5,44,
  	0,0,225,226,3,4,2,1,226,228,1,0,0,0,227,20,1,0,0,0,227,25,1,0,0,0,227,
  	29,1,0,0,0,227,34,1,0,0,0,227,38,1,0,0,0,227,42,1,0,0,0,227,44,1,0,0,
  	0,227,51,1,0,0,0,227,59,1,0,0,0,227,64,1,0,0,0,227,65,1,0,0,0,227,66,
  	1,0,0,0,227,67,1,0,0,0,227,68,1,0,0,0,227,69,1,0,0,0,227,70,1,0,0,0,227,
  	71,1,0,0,0,227,72,1,0,0,0,227,74,1,0,0,0,227,86,1,0,0,0,227,87,1,0,0,
  	0,227,88,1,0,0,0,227,90,1,0,0,0,227,94,1,0,0,0,227,106,1,0,0,0,227,107,
  	1,0,0,0,227,119,1,0,0,0,227,134,1,0,0,0,227,135,1,0,0,0,227,141,1,0,0,
  	0,227,147,1,0,0,0,227,153,1,0,0,0,227,161,1,0,0,0,227,169,1,0,0,0,227,
  	173,1,0,0,0,227,177,1,0,0,0,227,179,1,0,0,0,227,181,1,0,0,0,227,183,1,
  	0,0,0,227,187,1,0,0,0,227,191,1,0,0,0,227,195,1,0,0,0,227,197,1,0,0,0,
  	227,199,1,0,0,0,227,201,1,0,0,0,227,203,1,0,0,0,227,205,1,0,0,0,227,209,
  	1,0,0,0,227,211,1,0,0,0,227,213,1,0,0,0,227,215,1,0,0,0,227,220,1,0,0,
  	0,227,222,1,0,0,0,228,313,1,0,0,0,229,230,10,77,0,0,230,231,5,5,0,0,231,
  	312,3,4,2,78,232,233,10,76,0,0,233,234,5,6,0,0,234,312,3,4,2,77,235,236,
  	10,75,0,0,236,237,5,7,0,0,237,312,3,4,2,76,238,239,10,74,0,0,239,240,
  	5,8,0,0,240,312,3,4,2,75,241,242,10,73,0,0,242,243,5,9,0,0,243,312,3,
  	4,2,74,244,245,10,72,0,0,245,246,5,10,0,0,246,312,3,4,2,73,247,248,10,
  	71,0,0,248,249,5,11,0,0,249,312,3,4,2,72,250,251,10,70,0,0,251,252,5,
  	12,0,0,252,312,3,4,2,71,253,254,10,69,0,0,254,255,5,13,0,0,255,312,3,
  	4,2,70,256,257,10,67,0,0,257,258,5,15,0,0,258,312,3,4,2,68,259,260,10,
  	66,0,0,260,261,5,16,0,0,261,312,3,4,2,67,262,263,10,65,0,0,263,264,5,
  	17,0,0,264,312,3,4,2,66,265,266,10,64,0,0,266,267,5,18,0,0,267,312,3,
  	4,2,65,268,269,10,63,0,0,269,270,5,63,0,0,270,312,3,4,2,64,271,272,10,
  	62,0,0,272,273,5,62,0,0,273,312,3,4,2,63,274,275,10,61,0,0,275,276,5,
  	19,0,0,276,312,3,4,2,62,277,278,10,56,0,0,278,279,5,22,0,0,279,312,3,
  	4,2,57,280,281,10,51,0,0,281,282,5,26,0,0,282,283,3,4,2,0,283,284,5,30,
  	0,0,284,285,3,4,2,52,285,312,1,0,0,0,286,287,10,50,0,0,287,288,5,31,0,
  	0,288,312,3,4,2,51,289,290,10,40,0,0,290,291,5,67,0,0,291,312,3,4,2,41,
  	292,293,10,39,0,0,293,294,5,68,0,0,294,312,3,4,2,40,295,296,10,4,0,0,
  	296,297,5,61,0,0,297,312,3,4,2,5,298,299,10,2,0,0,299,300,5,99,0,0,300,
  	312,3,4,2,3,301,302,10,53,0,0,302,303,5,26,0,0,303,304,3,4,2,0,304,305,
  	5,27,0,0,305,312,1,0,0,0,306,307,10,52,0,0,307,308,5,28,0,0,308,309,3,
  	4,2,0,309,310,5,29,0,0,310,312,1,0,0,0,311,229,1,0,0,0,311,232,1,0,0,
  	0,311,235,1,0,0,0,311,238,1,0,0,0,311,241,1,0,0,0,311,244,1,0,0,0,311,
  	247,1,0,0,0,311,250,1,0,0,0,311,253,1,0,0,0,311,256,1,0,0,0,311,259,1,
  	0,0,0,311,262,1,0,0,0,311,265,1,0,0,0,311,268,1,0,0,0,311,271,1,0,0,0,
  	311,274,1,0,0,0,311,277,1,0,0,0,311,280,1,0,0,0,311,286,1,0,0,0,311,289,
  	1,0,0,0,311,292,1,0,0,0,311,295,1,0,0,0,311,298,1,0,0,0,311,301,1,0,0,
  	0,311,306,1,0,0,0,312,315,1,0,0,0,313,311,1,0,0,0,313,314,1,0,0,0,314,
  	5,1,0,0,0,315,313,1,0,0,0,8,11,80,100,113,128,227,311,313
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
    setState(11);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(6);
        expr(0);
        setState(7);
        match(scriptParser::T__0); 
      }
      setState(13);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(14);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tuple_pairContext ------------------------------------------------------------------

scriptParser::Tuple_pairContext::Tuple_pairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* scriptParser::Tuple_pairContext::EscapedString() {
  return getToken(scriptParser::EscapedString, 0);
}

scriptParser::ExprContext* scriptParser::Tuple_pairContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}


size_t scriptParser::Tuple_pairContext::getRuleIndex() const {
  return scriptParser::RuleTuple_pair;
}

void scriptParser::Tuple_pairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTuple_pair(this);
}

void scriptParser::Tuple_pairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<scriptListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTuple_pair(this);
}


std::any scriptParser::Tuple_pairContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<scriptVisitor*>(visitor))
    return parserVisitor->visitTuple_pair(this);
  else
    return visitor->visitChildren(this);
}

scriptParser::Tuple_pairContext* scriptParser::tuple_pair() {
  Tuple_pairContext *_localctx = _tracker.createInstance<Tuple_pairContext>(_ctx, getState());
  enterRule(_localctx, 2, scriptParser::RuleTuple_pair);

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
    match(scriptParser::EscapedString);
    setState(17);
    match(scriptParser::T__1);
    setState(18);
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

//----------------- CoerceContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::CoerceContext::COERCE() {
  return getToken(scriptParser::COERCE, 0);
}

std::vector<scriptParser::ExprContext *> scriptParser::CoerceContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::CoerceContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
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
//----------------- VarphiContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::VarphiContext::VARPHI() {
  return getToken(scriptParser::VARPHI, 0);
}

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

tree::TerminalNode* scriptParser::CosContext::COS() {
  return getToken(scriptParser::COS, 0);
}

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

tree::TerminalNode* scriptParser::LtContext::ALPAREN() {
  return getToken(scriptParser::ALPAREN, 0);
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

std::vector<scriptParser::ExprContext *> scriptParser::ProjectContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::ProjectContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
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

tree::TerminalNode* scriptParser::FunctionContext::FUN() {
  return getToken(scriptParser::FUN, 0);
}

tree::TerminalNode* scriptParser::FunctionContext::VARNAME() {
  return getToken(scriptParser::VARNAME, 0);
}

tree::TerminalNode* scriptParser::FunctionContext::LPAREN() {
  return getToken(scriptParser::LPAREN, 0);
}

std::vector<scriptParser::ExprContext *> scriptParser::FunctionContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::FunctionContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

tree::TerminalNode* scriptParser::FunctionContext::RPAREN() {
  return getToken(scriptParser::RPAREN, 0);
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

tree::TerminalNode* scriptParser::SelfcrossContext::SELFX() {
  return getToken(scriptParser::SELFX, 0);
}

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
//----------------- Type_labelContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_labelContext::LABELT() {
  return getToken(scriptParser::LABELT, 0);
}

tree::TerminalNode* scriptParser::Type_labelContext::EscapedString() {
  return getToken(scriptParser::EscapedString, 0);
}

scriptParser::Type_labelContext::Type_labelContext(ExprContext *ctx) { copyFrom(ctx); }

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

tree::TerminalNode* scriptParser::TanContext::TAN() {
  return getToken(scriptParser::TAN, 0);
}

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
//----------------- Subtype_ofContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::Subtype_ofContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::Subtype_ofContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

tree::TerminalNode* scriptParser::Subtype_ofContext::SUBTYPE() {
  return getToken(scriptParser::SUBTYPE, 0);
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
//----------------- Type_boolContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_boolContext::BOOLT() {
  return getToken(scriptParser::BOOLT, 0);
}

scriptParser::Type_boolContext::Type_boolContext(ExprContext *ctx) { copyFrom(ctx); }

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
//----------------- EnsureContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::EnsureContext::ASSERT() {
  return getToken(scriptParser::ASSERT, 0);
}

scriptParser::ExprContext* scriptParser::EnsureContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::EnsureContext::EnsureContext(ExprContext *ctx) { copyFrom(ctx); }

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

tree::TerminalNode* scriptParser::EllContext::ELL() {
  return getToken(scriptParser::ELL, 0);
}

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
//----------------- KindContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::KindContext::START() {
  return getToken(scriptParser::START, 0);
}

scriptParser::KindContext::KindContext(ExprContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_tupleContext ------------------------------------------------------------------

std::vector<scriptParser::Tuple_pairContext *> scriptParser::Type_tupleContext::tuple_pair() {
  return getRuleContexts<scriptParser::Tuple_pairContext>();
}

scriptParser::Tuple_pairContext* scriptParser::Type_tupleContext::tuple_pair(size_t i) {
  return getRuleContext<scriptParser::Tuple_pairContext>(i);
}

tree::TerminalNode* scriptParser::Type_tupleContext::ARPAREN() {
  return getToken(scriptParser::ARPAREN, 0);
}

scriptParser::Type_tupleContext::Type_tupleContext(ExprContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_orContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::Type_orContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::Type_orContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

tree::TerminalNode* scriptParser::Type_orContext::OR_TYPE() {
  return getToken(scriptParser::OR_TYPE, 0);
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

std::vector<scriptParser::ExprContext *> scriptParser::Type_lexContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::Type_lexContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
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
//----------------- Sigma_typeContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Sigma_typeContext::SIGMA() {
  return getToken(scriptParser::SIGMA, 0);
}

std::vector<scriptParser::ExprContext *> scriptParser::Sigma_typeContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::Sigma_typeContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
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
//----------------- NullContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::NullContext::BOT() {
  return getToken(scriptParser::BOT, 0);
}

scriptParser::NullContext::NullContext(ExprContext *ctx) { copyFrom(ctx); }

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
//----------------- EnforceContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::EnforceContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::EnforceContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

tree::TerminalNode* scriptParser::EnforceContext::ENFORCE() {
  return getToken(scriptParser::ENFORCE, 0);
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

tree::TerminalNode* scriptParser::Atom_arrayContext::LPAREN() {
  return getToken(scriptParser::LPAREN, 0);
}

std::vector<scriptParser::ExprContext *> scriptParser::Atom_arrayContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::Atom_arrayContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

tree::TerminalNode* scriptParser::Atom_arrayContext::RPAREN() {
  return getToken(scriptParser::RPAREN, 0);
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

tree::TerminalNode* scriptParser::LogContext::LOG() {
  return getToken(scriptParser::LOG, 0);
}

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

tree::TerminalNode* scriptParser::RemoveContext::REMOVE() {
  return getToken(scriptParser::REMOVE, 0);
}

std::vector<scriptParser::ExprContext *> scriptParser::RemoveContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::RemoveContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

tree::TerminalNode* scriptParser::RemoveContext::FROM() {
  return getToken(scriptParser::FROM, 0);
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

tree::TerminalNode* scriptParser::NotContext::NOT() {
  return getToken(scriptParser::NOT, 0);
}

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
//----------------- Type_stringContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_stringContext::STRINGT() {
  return getToken(scriptParser::STRINGT, 0);
}

scriptParser::Type_stringContext::Type_stringContext(ExprContext *ctx) { copyFrom(ctx); }

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

scriptParser::Type_anyContext::Type_anyContext(ExprContext *ctx) { copyFrom(ctx); }

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

tree::TerminalNode* scriptParser::FlatContext::FLAT() {
  return getToken(scriptParser::FLAT, 0);
}

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

tree::TerminalNode* scriptParser::PowContext::POW() {
  return getToken(scriptParser::POW, 0);
}

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

tree::TerminalNode* scriptParser::SinContext::SIN() {
  return getToken(scriptParser::SIN, 0);
}

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
//----------------- TypeofContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::TypeofContext::TYPEOF() {
  return getToken(scriptParser::TYPEOF, 0);
}

scriptParser::ExprContext* scriptParser::TypeofContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::TypeofContext::TypeofContext(ExprContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_intContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_intContext::INTT() {
  return getToken(scriptParser::INTT, 0);
}

scriptParser::Type_intContext::Type_intContext(ExprContext *ctx) { copyFrom(ctx); }

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

tree::TerminalNode* scriptParser::InjContext::INJ() {
  return getToken(scriptParser::INJ, 0);
}

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
//----------------- Type_andContext ------------------------------------------------------------------

std::vector<scriptParser::ExprContext *> scriptParser::Type_andContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::Type_andContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

tree::TerminalNode* scriptParser::Type_andContext::AND_TYPE() {
  return getToken(scriptParser::AND_TYPE, 0);
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

tree::TerminalNode* scriptParser::GtContext::ARPAREN() {
  return getToken(scriptParser::ARPAREN, 0);
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
//----------------- Atom_tupleContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Atom_tupleContext::ALPAREN() {
  return getToken(scriptParser::ALPAREN, 0);
}

std::vector<scriptParser::Tuple_pairContext *> scriptParser::Atom_tupleContext::tuple_pair() {
  return getRuleContexts<scriptParser::Tuple_pairContext>();
}

scriptParser::Tuple_pairContext* scriptParser::Atom_tupleContext::tuple_pair(size_t i) {
  return getRuleContext<scriptParser::Tuple_pairContext>(i);
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
//----------------- Type_doubleContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_doubleContext::DOUBLET() {
  return getToken(scriptParser::DOUBLET, 0);
}

scriptParser::Type_doubleContext::Type_doubleContext(ExprContext *ctx) { copyFrom(ctx); }

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

tree::TerminalNode* scriptParser::PhiContext::PHI() {
  return getToken(scriptParser::PHI, 0);
}

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

tree::TerminalNode* scriptParser::XiContext::XI() {
  return getToken(scriptParser::XI, 0);
}

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
//----------------- Type_listContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_listContext::LISTT() {
  return getToken(scriptParser::LISTT, 0);
}

scriptParser::ExprContext* scriptParser::Type_listContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::Type_listContext::Type_listContext(ExprContext *ctx) { copyFrom(ctx); }

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
//----------------- ObjContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::ObjContext::OBJ() {
  return getToken(scriptParser::OBJ, 0);
}

scriptParser::ExprContext* scriptParser::ObjContext::expr() {
  return getRuleContext<scriptParser::ExprContext>(0);
}

scriptParser::ObjContext::ObjContext(ExprContext *ctx) { copyFrom(ctx); }

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
//----------------- Type_botContext ------------------------------------------------------------------

tree::TerminalNode* scriptParser::Type_botContext::VOID() {
  return getToken(scriptParser::VOID, 0);
}

scriptParser::Type_botContext::Type_botContext(ExprContext *ctx) { copyFrom(ctx); }

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

tree::TerminalNode* scriptParser::IfteContext::IF() {
  return getToken(scriptParser::IF, 0);
}

std::vector<scriptParser::ExprContext *> scriptParser::IfteContext::expr() {
  return getRuleContexts<scriptParser::ExprContext>();
}

scriptParser::ExprContext* scriptParser::IfteContext::expr(size_t i) {
  return getRuleContext<scriptParser::ExprContext>(i);
}

tree::TerminalNode* scriptParser::IfteContext::THEN() {
  return getToken(scriptParser::THEN, 0);
}

tree::TerminalNode* scriptParser::IfteContext::ELSE() {
  return getToken(scriptParser::ELSE, 0);
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
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, scriptParser::RuleExpr, precedence);

    

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
    setState(227);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(21);
      match(scriptParser::T__2);
      setState(22);
      expr(0);
      setState(23);
      match(scriptParser::T__3);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<AbsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(25);
      match(scriptParser::T__13);
      setState(26);
      expr(0);
      setState(27);
      match(scriptParser::T__13);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ApplyContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(29);
      match(scriptParser::T__2);
      setState(30);
      expr(0);
      setState(31);
      expr(0);
      setState(32);
      match(scriptParser::T__3);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<VarContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(34);
      match(scriptParser::T__19);
      setState(35);
      expr(0);
      setState(36);
      match(scriptParser::T__3);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<EvalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(38);
      match(scriptParser::T__20);
      setState(39);
      expr(0);
      setState(40);
      match(scriptParser::T__3);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NotContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(42);
      match(scriptParser::NOT);
      setState(43);
      expr(57);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<IfteContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(44);
      match(scriptParser::IF);
      setState(45);
      expr(0);
      setState(46);
      match(scriptParser::THEN);
      setState(47);
      expr(0);
      setState(48);
      match(scriptParser::ELSE);
      setState(49);
      expr(55);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<SubstringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(51);
      match(scriptParser::T__22);
      setState(52);
      expr(0);
      setState(53);
      match(scriptParser::T__23);
      setState(54);
      expr(0);
      setState(55);
      match(scriptParser::T__24);
      setState(56);
      expr(0);
      setState(57);
      match(scriptParser::T__3);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<RemoveContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(59);
      match(scriptParser::REMOVE);
      setState(60);
      expr(0);
      setState(61);
      match(scriptParser::FROM);
      setState(62);
      expr(49);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<Atom_numberContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(64);
      match(scriptParser::NUMBER);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<Atom_boolContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(65);
      match(scriptParser::BOOL);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<Atom_stringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(66);
      match(scriptParser::EscapedString);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<NullContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(67);
      match(scriptParser::BOT);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<Type_stringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(68);
      match(scriptParser::STRINGT);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<Type_boolContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(69);
      match(scriptParser::BOOLT);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<Type_intContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(70);
      match(scriptParser::INTT);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<Type_doubleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(71);
      match(scriptParser::DOUBLET);
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<Type_listContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(72);
      match(scriptParser::LISTT);
      setState(73);
      expr(38);
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<Type_tupleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(74);
      match(scriptParser::T__31);
      setState(80);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(75);
          tuple_pair();
          setState(76);
          match(scriptParser::T__0); 
        }
        setState(82);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      }
      setState(83);
      tuple_pair();
      setState(84);
      match(scriptParser::ARPAREN);
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<Type_anyContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(86);
      match(scriptParser::ANYT);
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<Type_botContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(87);
      match(scriptParser::VOID);
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<Type_labelContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(88);
      match(scriptParser::LABELT);
      setState(89);
      match(scriptParser::EscapedString);
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<Type_lexContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(90);
      match(scriptParser::ObjT);
      setState(91);
      expr(0);
      setState(92);
      expr(33);
      break;
    }

    case 24: {
      _localctx = _tracker.createInstance<Atom_arrayContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(94);
      match(scriptParser::LPAREN);
      setState(100);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(95);
          expr(0);
          setState(96);
          match(scriptParser::T__0); 
        }
        setState(102);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
      }
      setState(103);
      expr(0);
      setState(104);
      match(scriptParser::RPAREN);
      break;
    }

    case 25: {
      _localctx = _tracker.createInstance<KindContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(106);
      match(scriptParser::START);
      break;
    }

    case 26: {
      _localctx = _tracker.createInstance<Atom_tupleContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(107);
      match(scriptParser::ALPAREN);
      setState(113);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(108);
          tuple_pair();
          setState(109);
          match(scriptParser::T__0); 
        }
        setState(115);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
      }
      setState(116);
      tuple_pair();
      setState(117);
      match(scriptParser::ARPAREN);
      break;
    }

    case 27: {
      _localctx = _tracker.createInstance<FunctionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(119);
      match(scriptParser::FUN);
      setState(120);
      match(scriptParser::VARNAME);
      setState(121);
      match(scriptParser::T__32);
      setState(122);
      match(scriptParser::LPAREN);
      setState(128);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(123);
          expr(0);
          setState(124);
          match(scriptParser::T__0); 
        }
        setState(130);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
      }
      setState(131);
      expr(0);
      setState(132);
      match(scriptParser::RPAREN);
      break;
    }

    case 28: {
      _localctx = _tracker.createInstance<VariableContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(134);
      match(scriptParser::VARNAME);
      break;
    }

    case 29: {
      _localctx = _tracker.createInstance<MapContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      match(scriptParser::T__33);
      setState(136);
      expr(0);
      setState(137);
      match(scriptParser::T__24);
      setState(138);
      expr(0);
      setState(139);
      match(scriptParser::T__3);
      break;
    }

    case 30: {
      _localctx = _tracker.createInstance<SelectContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(141);
      match(scriptParser::T__34);
      setState(142);
      expr(0);
      setState(143);
      match(scriptParser::T__24);
      setState(144);
      expr(0);
      setState(145);
      match(scriptParser::T__3);
      break;
    }

    case 31: {
      _localctx = _tracker.createInstance<FilterContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(147);
      match(scriptParser::T__35);
      setState(148);
      expr(0);
      setState(149);
      match(scriptParser::T__24);
      setState(150);
      expr(0);
      setState(151);
      match(scriptParser::T__3);
      break;
    }

    case 32: {
      _localctx = _tracker.createInstance<RfoldContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(153);
      match(scriptParser::T__36);
      setState(154);
      expr(0);
      setState(155);
      match(scriptParser::T__23);
      setState(156);
      expr(0);
      setState(157);
      match(scriptParser::T__24);
      setState(158);
      expr(0);
      setState(159);
      match(scriptParser::T__3);
      break;
    }

    case 33: {
      _localctx = _tracker.createInstance<LfoldContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(161);
      match(scriptParser::T__37);
      setState(162);
      expr(0);
      setState(163);
      match(scriptParser::T__23);
      setState(164);
      expr(0);
      setState(165);
      match(scriptParser::T__24);
      setState(166);
      expr(0);
      setState(167);
      match(scriptParser::T__3);
      break;
    }

    case 34: {
      _localctx = _tracker.createInstance<LogContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(169);
      match(scriptParser::LOG);
      setState(170);
      expr(0);
      setState(171);
      expr(22);
      break;
    }

    case 35: {
      _localctx = _tracker.createInstance<PowContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(173);
      match(scriptParser::POW);
      setState(174);
      expr(0);
      setState(175);
      expr(21);
      break;
    }

    case 36: {
      _localctx = _tracker.createInstance<SinContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(177);
      match(scriptParser::SIN);
      setState(178);
      expr(20);
      break;
    }

    case 37: {
      _localctx = _tracker.createInstance<CosContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(179);
      match(scriptParser::COS);
      setState(180);
      expr(19);
      break;
    }

    case 38: {
      _localctx = _tracker.createInstance<TanContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(181);
      match(scriptParser::TAN);
      setState(182);
      expr(18);
      break;
    }

    case 39: {
      _localctx = _tracker.createInstance<FloorContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(183);
      match(scriptParser::T__38);
      setState(184);
      expr(0);
      setState(185);
      match(scriptParser::T__39);
      break;
    }

    case 40: {
      _localctx = _tracker.createInstance<CeilContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(187);
      match(scriptParser::T__40);
      setState(188);
      expr(0);
      setState(189);
      match(scriptParser::T__41);
      break;
    }

    case 41: {
      _localctx = _tracker.createInstance<PhiContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(191);
      match(scriptParser::PHI);
      setState(192);
      expr(0);
      setState(193);
      expr(15);
      break;
    }

    case 42: {
      _localctx = _tracker.createInstance<EllContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(195);
      match(scriptParser::ELL);
      setState(196);
      expr(14);
      break;
    }

    case 43: {
      _localctx = _tracker.createInstance<XiContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(197);
      match(scriptParser::XI);
      setState(198);
      expr(13);
      break;
    }

    case 44: {
      _localctx = _tracker.createInstance<InjContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(199);
      match(scriptParser::INJ);
      setState(200);
      expr(12);
      break;
    }

    case 45: {
      _localctx = _tracker.createInstance<ObjContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(201);
      match(scriptParser::OBJ);
      setState(202);
      expr(11);
      break;
    }

    case 46: {
      _localctx = _tracker.createInstance<FlatContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(203);
      match(scriptParser::FLAT);
      setState(204);
      expr(10);
      break;
    }

    case 47: {
      _localctx = _tracker.createInstance<CrossContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(205);
      match(scriptParser::CROSS);
      setState(206);
      expr(0);
      setState(207);
      expr(9);
      break;
    }

    case 48: {
      _localctx = _tracker.createInstance<SelfcrossContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(209);
      match(scriptParser::SELFX);
      setState(210);
      expr(8);
      break;
    }

    case 49: {
      _localctx = _tracker.createInstance<VarphiContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(211);
      match(scriptParser::VARPHI);
      setState(212);
      expr(7);
      break;
    }

    case 50: {
      _localctx = _tracker.createInstance<TypeofContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(213);
      match(scriptParser::TYPEOF);
      setState(214);
      expr(6);
      break;
    }

    case 51: {
      _localctx = _tracker.createInstance<Sigma_typeContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(215);
      match(scriptParser::SIGMA);
      setState(216);
      expr(0);
      setState(217);
      match(scriptParser::T__42);
      setState(218);
      expr(5);
      break;
    }

    case 52: {
      _localctx = _tracker.createInstance<EnsureContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(220);
      match(scriptParser::ASSERT);
      setState(221);
      expr(3);
      break;
    }

    case 53: {
      _localctx = _tracker.createInstance<CoerceContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(222);
      match(scriptParser::COERCE);
      setState(223);
      expr(0);
      setState(224);
      match(scriptParser::T__43);
      setState(225);
      expr(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(313);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(311);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(229);

          if (!(precpred(_ctx, 77))) throw FailedPredicateException(this, "precpred(_ctx, 77)");
          setState(230);
          match(scriptParser::T__4);
          setState(231);
          expr(78);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<SubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(232);

          if (!(precpred(_ctx, 76))) throw FailedPredicateException(this, "precpred(_ctx, 76)");
          setState(233);
          match(scriptParser::T__5);
          setState(234);
          expr(77);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<DivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(235);

          if (!(precpred(_ctx, 75))) throw FailedPredicateException(this, "precpred(_ctx, 75)");
          setState(236);
          match(scriptParser::T__6);
          setState(237);
          expr(76);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ModContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(238);

          if (!(precpred(_ctx, 74))) throw FailedPredicateException(this, "precpred(_ctx, 74)");
          setState(239);
          match(scriptParser::T__7);
          setState(240);
          expr(75);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(241);

          if (!(precpred(_ctx, 73))) throw FailedPredicateException(this, "precpred(_ctx, 73)");
          setState(242);
          match(scriptParser::T__8);
          setState(243);
          expr(74);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<ConcatContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(244);

          if (!(precpred(_ctx, 72))) throw FailedPredicateException(this, "precpred(_ctx, 72)");
          setState(245);
          match(scriptParser::T__9);
          setState(246);
          expr(73);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<AppendContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(247);

          if (!(precpred(_ctx, 71))) throw FailedPredicateException(this, "precpred(_ctx, 71)");
          setState(248);
          match(scriptParser::T__10);
          setState(249);
          expr(72);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<AndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(250);

          if (!(precpred(_ctx, 70))) throw FailedPredicateException(this, "precpred(_ctx, 70)");
          setState(251);
          match(scriptParser::T__11);
          setState(252);
          expr(71);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<OrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(253);

          if (!(precpred(_ctx, 69))) throw FailedPredicateException(this, "precpred(_ctx, 69)");
          setState(254);
          match(scriptParser::T__12);
          setState(255);
          expr(70);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<EqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(256);

          if (!(precpred(_ctx, 67))) throw FailedPredicateException(this, "precpred(_ctx, 67)");
          setState(257);
          match(scriptParser::T__14);
          setState(258);
          expr(68);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<NeqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(259);

          if (!(precpred(_ctx, 66))) throw FailedPredicateException(this, "precpred(_ctx, 66)");
          setState(260);
          match(scriptParser::T__15);
          setState(261);
          expr(67);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<LeqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(262);

          if (!(precpred(_ctx, 65))) throw FailedPredicateException(this, "precpred(_ctx, 65)");
          setState(263);
          match(scriptParser::T__16);
          setState(264);
          expr(66);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<GeqContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(265);

          if (!(precpred(_ctx, 64))) throw FailedPredicateException(this, "precpred(_ctx, 64)");
          setState(266);
          match(scriptParser::T__17);
          setState(267);
          expr(65);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<GtContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(268);

          if (!(precpred(_ctx, 63))) throw FailedPredicateException(this, "precpred(_ctx, 63)");
          setState(269);
          match(scriptParser::ARPAREN);
          setState(270);
          expr(64);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<LtContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(271);

          if (!(precpred(_ctx, 62))) throw FailedPredicateException(this, "precpred(_ctx, 62)");
          setState(272);
          match(scriptParser::ALPAREN);
          setState(273);
          expr(63);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<AssignContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(274);

          if (!(precpred(_ctx, 61))) throw FailedPredicateException(this, "precpred(_ctx, 61)");
          setState(275);
          match(scriptParser::T__18);
          setState(276);
          expr(62);
          break;
        }

        case 17: {
          auto newContext = _tracker.createInstance<ImplyContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(277);

          if (!(precpred(_ctx, 56))) throw FailedPredicateException(this, "precpred(_ctx, 56)");
          setState(278);
          match(scriptParser::T__21);
          setState(279);
          expr(57);
          break;
        }

        case 18: {
          auto newContext = _tracker.createInstance<PutContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(280);

          if (!(precpred(_ctx, 51))) throw FailedPredicateException(this, "precpred(_ctx, 51)");
          setState(281);
          match(scriptParser::T__25);
          setState(282);
          expr(0);
          setState(283);
          match(scriptParser::T__29);
          setState(284);
          expr(52);
          break;
        }

        case 19: {
          auto newContext = _tracker.createInstance<ContainsContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(286);

          if (!(precpred(_ctx, 50))) throw FailedPredicateException(this, "precpred(_ctx, 50)");
          setState(287);
          match(scriptParser::T__30);
          setState(288);
          expr(51);
          break;
        }

        case 20: {
          auto newContext = _tracker.createInstance<Type_andContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(289);

          if (!(precpred(_ctx, 40))) throw FailedPredicateException(this, "precpred(_ctx, 40)");
          setState(290);
          match(scriptParser::AND_TYPE);
          setState(291);
          expr(41);
          break;
        }

        case 21: {
          auto newContext = _tracker.createInstance<Type_orContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(292);

          if (!(precpred(_ctx, 39))) throw FailedPredicateException(this, "precpred(_ctx, 39)");
          setState(293);
          match(scriptParser::OR_TYPE);
          setState(294);
          expr(40);
          break;
        }

        case 22: {
          auto newContext = _tracker.createInstance<Subtype_ofContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(295);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(296);
          match(scriptParser::SUBTYPE);
          setState(297);
          expr(5);
          break;
        }

        case 23: {
          auto newContext = _tracker.createInstance<EnforceContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(298);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(299);
          match(scriptParser::ENFORCE);
          setState(300);
          expr(3);
          break;
        }

        case 24: {
          auto newContext = _tracker.createInstance<AtContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(301);

          if (!(precpred(_ctx, 53))) throw FailedPredicateException(this, "precpred(_ctx, 53)");
          setState(302);
          match(scriptParser::T__25);
          setState(303);
          expr(0);
          setState(304);
          match(scriptParser::T__26);
          break;
        }

        case 25: {
          auto newContext = _tracker.createInstance<ProjectContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(306);

          if (!(precpred(_ctx, 52))) throw FailedPredicateException(this, "precpred(_ctx, 52)");
          setState(307);
          match(scriptParser::T__27);
          setState(308);
          expr(0);
          setState(309);
          match(scriptParser::T__28);
          break;
        }

        default:
          break;
        } 
      }
      setState(315);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
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
    case 2: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool scriptParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 77);
    case 1: return precpred(_ctx, 76);
    case 2: return precpred(_ctx, 75);
    case 3: return precpred(_ctx, 74);
    case 4: return precpred(_ctx, 73);
    case 5: return precpred(_ctx, 72);
    case 6: return precpred(_ctx, 71);
    case 7: return precpred(_ctx, 70);
    case 8: return precpred(_ctx, 69);
    case 9: return precpred(_ctx, 67);
    case 10: return precpred(_ctx, 66);
    case 11: return precpred(_ctx, 65);
    case 12: return precpred(_ctx, 64);
    case 13: return precpred(_ctx, 63);
    case 14: return precpred(_ctx, 62);
    case 15: return precpred(_ctx, 61);
    case 16: return precpred(_ctx, 56);
    case 17: return precpred(_ctx, 51);
    case 18: return precpred(_ctx, 50);
    case 19: return precpred(_ctx, 40);
    case 20: return precpred(_ctx, 39);
    case 21: return precpred(_ctx, 4);
    case 22: return precpred(_ctx, 2);
    case 23: return precpred(_ctx, 53);
    case 24: return precpred(_ctx, 52);

  default:
    break;
  }
  return true;
}

void scriptParser::initialize() {
  ::antlr4::internal::call_once(scriptParserOnceFlag, scriptParserInitialize);
}
