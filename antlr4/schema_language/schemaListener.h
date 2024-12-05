
// Generated from antlr4/schema_language/schema.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "schemaParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by schemaParser.
 */
class  schemaListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterLanguage(schemaParser::LanguageContext *ctx) = 0;
  virtual void exitLanguage(schemaParser::LanguageContext *ctx) = 0;

  virtual void enterT_string(schemaParser::T_stringContext *ctx) = 0;
  virtual void exitT_string(schemaParser::T_stringContext *ctx) = 0;

  virtual void enterT_uint(schemaParser::T_uintContext *ctx) = 0;
  virtual void exitT_uint(schemaParser::T_uintContext *ctx) = 0;

  virtual void enterT_int(schemaParser::T_intContext *ctx) = 0;
  virtual void exitT_int(schemaParser::T_intContext *ctx) = 0;

  virtual void enterT_double(schemaParser::T_doubleContext *ctx) = 0;
  virtual void exitT_double(schemaParser::T_doubleContext *ctx) = 0;

  virtual void enterEntity_declaration(schemaParser::Entity_declarationContext *ctx) = 0;
  virtual void exitEntity_declaration(schemaParser::Entity_declarationContext *ctx) = 0;

  virtual void enterLocal_entity_declaration(schemaParser::Local_entity_declarationContext *ctx) = 0;
  virtual void exitLocal_entity_declaration(schemaParser::Local_entity_declarationContext *ctx) = 0;

  virtual void enterNative_field(schemaParser::Native_fieldContext *ctx) = 0;
  virtual void exitNative_field(schemaParser::Native_fieldContext *ctx) = 0;

  virtual void enterExternal_reference(schemaParser::External_referenceContext *ctx) = 0;
  virtual void exitExternal_reference(schemaParser::External_referenceContext *ctx) = 0;

  virtual void enterLocal_nested_entity_list(schemaParser::Local_nested_entity_listContext *ctx) = 0;
  virtual void exitLocal_nested_entity_list(schemaParser::Local_nested_entity_listContext *ctx) = 0;

  virtual void enterLocal_nested_entity(schemaParser::Local_nested_entityContext *ctx) = 0;
  virtual void exitLocal_nested_entity(schemaParser::Local_nested_entityContext *ctx) = 0;

  virtual void enterMulti_nested_entity(schemaParser::Multi_nested_entityContext *ctx) = 0;
  virtual void exitMulti_nested_entity(schemaParser::Multi_nested_entityContext *ctx) = 0;

  virtual void enterName_declar(schemaParser::Name_declarContext *ctx) = 0;
  virtual void exitName_declar(schemaParser::Name_declarContext *ctx) = 0;

  virtual void enterFile(schemaParser::FileContext *ctx) = 0;
  virtual void exitFile(schemaParser::FileContext *ctx) = 0;

  virtual void enterCsv(schemaParser::CsvContext *ctx) = 0;
  virtual void exitCsv(schemaParser::CsvContext *ctx) = 0;


};

