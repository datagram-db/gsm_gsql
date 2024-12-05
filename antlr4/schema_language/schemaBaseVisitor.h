
// Generated from antlr4/schema_language/schema.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "schemaVisitor.h"


/**
 * This class provides an empty implementation of schemaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  schemaBaseVisitor : public schemaVisitor {
public:

  virtual std::any visitLanguage(schemaParser::LanguageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitT_string(schemaParser::T_stringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitT_uint(schemaParser::T_uintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitT_int(schemaParser::T_intContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitT_double(schemaParser::T_doubleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEntity_declaration(schemaParser::Entity_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocal_entity_declaration(schemaParser::Local_entity_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNative_field(schemaParser::Native_fieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExternal_reference(schemaParser::External_referenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocal_nested_entity_list(schemaParser::Local_nested_entity_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLocal_nested_entity(schemaParser::Local_nested_entityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulti_nested_entity(schemaParser::Multi_nested_entityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitName_declar(schemaParser::Name_declarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFile(schemaParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCsv(schemaParser::CsvContext *ctx) override {
    return visitChildren(ctx);
  }


};

