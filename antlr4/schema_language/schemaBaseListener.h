
// Generated from antlr4/schema_language/schema.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "schemaListener.h"


/**
 * This class provides an empty implementation of schemaListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  schemaBaseListener : public schemaListener {
public:

  virtual void enterLanguage(schemaParser::LanguageContext * /*ctx*/) override { }
  virtual void exitLanguage(schemaParser::LanguageContext * /*ctx*/) override { }

  virtual void enterT_string(schemaParser::T_stringContext * /*ctx*/) override { }
  virtual void exitT_string(schemaParser::T_stringContext * /*ctx*/) override { }

  virtual void enterT_uint(schemaParser::T_uintContext * /*ctx*/) override { }
  virtual void exitT_uint(schemaParser::T_uintContext * /*ctx*/) override { }

  virtual void enterT_int(schemaParser::T_intContext * /*ctx*/) override { }
  virtual void exitT_int(schemaParser::T_intContext * /*ctx*/) override { }

  virtual void enterT_double(schemaParser::T_doubleContext * /*ctx*/) override { }
  virtual void exitT_double(schemaParser::T_doubleContext * /*ctx*/) override { }

  virtual void enterEntity_declaration(schemaParser::Entity_declarationContext * /*ctx*/) override { }
  virtual void exitEntity_declaration(schemaParser::Entity_declarationContext * /*ctx*/) override { }

  virtual void enterLocal_entity_declaration(schemaParser::Local_entity_declarationContext * /*ctx*/) override { }
  virtual void exitLocal_entity_declaration(schemaParser::Local_entity_declarationContext * /*ctx*/) override { }

  virtual void enterNative_field(schemaParser::Native_fieldContext * /*ctx*/) override { }
  virtual void exitNative_field(schemaParser::Native_fieldContext * /*ctx*/) override { }

  virtual void enterExternal_reference(schemaParser::External_referenceContext * /*ctx*/) override { }
  virtual void exitExternal_reference(schemaParser::External_referenceContext * /*ctx*/) override { }

  virtual void enterLocal_nested_entity_list(schemaParser::Local_nested_entity_listContext * /*ctx*/) override { }
  virtual void exitLocal_nested_entity_list(schemaParser::Local_nested_entity_listContext * /*ctx*/) override { }

  virtual void enterLocal_nested_entity(schemaParser::Local_nested_entityContext * /*ctx*/) override { }
  virtual void exitLocal_nested_entity(schemaParser::Local_nested_entityContext * /*ctx*/) override { }

  virtual void enterMulti_nested_entity(schemaParser::Multi_nested_entityContext * /*ctx*/) override { }
  virtual void exitMulti_nested_entity(schemaParser::Multi_nested_entityContext * /*ctx*/) override { }

  virtual void enterName_declar(schemaParser::Name_declarContext * /*ctx*/) override { }
  virtual void exitName_declar(schemaParser::Name_declarContext * /*ctx*/) override { }

  virtual void enterFile(schemaParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(schemaParser::FileContext * /*ctx*/) override { }

  virtual void enterCsv(schemaParser::CsvContext * /*ctx*/) override { }
  virtual void exitCsv(schemaParser::CsvContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

