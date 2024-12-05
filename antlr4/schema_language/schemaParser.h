
// Generated from antlr4/schema_language/schema.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"




class  schemaParser : public antlr4::Parser {
public:
  enum {
    SCORE = 1, TAG = 2, PROPERTY = 3, MULTI = 4, FROM = 5, FILE = 6, CSV = 7, 
    XML = 8, JSON = 9, LJSON = 10, WITH_HEADER = 11, SEP = 12, String = 13, 
    UInt = 14, Int = 15, Double = 16, LPAR = 17, RPAR = 18, LCOLL = 19, 
    RCOLL = 20, COMMA = 21, MAP = 22, COMMENT = 23, DOT = 24, EQ = 25, TYPE_SEP = 26, 
    OFTYPE = 27, STAR = 28, LINE_COMMENT = 29, WS = 30, EscapedString = 31, 
    WORD = 32
  };

  enum {
    RuleLanguage = 0, RuleType = 1, RuleEntity_declaration = 2, RuleLocal_entity_declaration = 3, 
    RuleField = 4, RuleName_declar = 5, RuleFile = 6, RuleCsv = 7
  };

  explicit schemaParser(antlr4::TokenStream *input);

  schemaParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~schemaParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class LanguageContext;
  class TypeContext;
  class Entity_declarationContext;
  class Local_entity_declarationContext;
  class FieldContext;
  class Name_declarContext;
  class FileContext;
  class CsvContext; 

  class  LanguageContext : public antlr4::ParserRuleContext {
  public:
    LanguageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Entity_declarationContext *> entity_declaration();
    Entity_declarationContext* entity_declaration(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LanguageContext* language();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  T_stringContext : public TypeContext {
  public:
    T_stringContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *String();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  T_doubleContext : public TypeContext {
  public:
    T_doubleContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *Double();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  T_uintContext : public TypeContext {
  public:
    T_uintContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *UInt();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  T_intContext : public TypeContext {
  public:
    T_intContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *Int();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();

  class  Entity_declarationContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *namespace_ = nullptr;
    Entity_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_SEP();
    Local_entity_declarationContext *local_entity_declaration();
    FileContext *file();
    antlr4::tree::TerminalNode *WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Entity_declarationContext* entity_declaration();

  class  Local_entity_declarationContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *entity = nullptr;
    Local_entity_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAR();
    std::vector<FieldContext *> field();
    FieldContext* field(size_t i);
    antlr4::tree::TerminalNode *RPAR();
    antlr4::tree::TerminalNode *WORD();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Local_entity_declarationContext* local_entity_declaration();

  class  FieldContext : public antlr4::ParserRuleContext {
  public:
    FieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FieldContext() = default;
    void copyFrom(FieldContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  Native_fieldContext : public FieldContext {
  public:
    Native_fieldContext(FieldContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::Token *map = nullptr;
    antlr4::tree::TerminalNode *OFTYPE();
    TypeContext *type();
    antlr4::tree::TerminalNode *WORD();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SCORE();
    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *TAG();
    antlr4::tree::TerminalNode *PROPERTY();
    antlr4::tree::TerminalNode *EscapedString();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Multi_nested_entityContext : public FieldContext {
  public:
    Multi_nested_entityContext(FieldContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::Token *map = nullptr;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *MULTI();
    Local_entity_declarationContext *local_entity_declaration();
    antlr4::tree::TerminalNode *WORD();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *EscapedString();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Local_nested_entityContext : public FieldContext {
  public:
    Local_nested_entityContext(FieldContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::Token *map = nullptr;
    antlr4::tree::TerminalNode *EQ();
    Local_entity_declarationContext *local_entity_declaration();
    antlr4::tree::TerminalNode *WORD();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *EscapedString();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  External_referenceContext : public FieldContext {
  public:
    External_referenceContext(FieldContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::Token *map = nullptr;
    antlr4::Token *ext_field_name = nullptr;
    antlr4::tree::TerminalNode *EQ();
    Name_declarContext *name_declar();
    antlr4::tree::TerminalNode *DOT();
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *TAG();
    antlr4::tree::TerminalNode *PROPERTY();
    antlr4::tree::TerminalNode *EscapedString();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  Local_nested_entity_listContext : public FieldContext {
  public:
    Local_nested_entity_listContext(FieldContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::Token *map = nullptr;
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *LCOLL();
    Local_entity_declarationContext *local_entity_declaration();
    antlr4::tree::TerminalNode *RCOLL();
    antlr4::tree::TerminalNode *WORD();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *EscapedString();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FieldContext* field();

  class  Name_declarContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *namespace_ = nullptr;
    antlr4::Token *entity = nullptr;
    Name_declarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_SEP();
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Name_declarContext* name_declar();

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *FILE();
    antlr4::tree::TerminalNode *OFTYPE();
    antlr4::tree::TerminalNode *EscapedString();
    CsvContext *csv();
    antlr4::tree::TerminalNode *XML();
    antlr4::tree::TerminalNode *JSON();
    antlr4::tree::TerminalNode *LJSON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  CsvContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *sep = nullptr;
    CsvContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CSV();
    antlr4::tree::TerminalNode *WITH_HEADER();
    antlr4::tree::TerminalNode *SEP();
    antlr4::tree::TerminalNode *EscapedString();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CsvContext* csv();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

