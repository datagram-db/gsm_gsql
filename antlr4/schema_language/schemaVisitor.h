
// Generated from antlr4/schema_language/schema.g4 by ANTLR 4.11.1

#pragma once


#include "antlr4-runtime.h"
#include "schemaParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by schemaParser.
 */
class  schemaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by schemaParser.
   */
    virtual std::any visitLanguage(schemaParser::LanguageContext *context) = 0;

    virtual std::any visitT_string(schemaParser::T_stringContext *context) = 0;

    virtual std::any visitT_uint(schemaParser::T_uintContext *context) = 0;

    virtual std::any visitT_int(schemaParser::T_intContext *context) = 0;

    virtual std::any visitT_double(schemaParser::T_doubleContext *context) = 0;

    virtual std::any visitEntity_declaration(schemaParser::Entity_declarationContext *context) = 0;

    virtual std::any visitLocal_entity_declaration(schemaParser::Local_entity_declarationContext *context) = 0;

    virtual std::any visitNative_field(schemaParser::Native_fieldContext *context) = 0;

    virtual std::any visitExternal_reference(schemaParser::External_referenceContext *context) = 0;

    virtual std::any visitLocal_nested_entity_list(schemaParser::Local_nested_entity_listContext *context) = 0;

    virtual std::any visitLocal_nested_entity(schemaParser::Local_nested_entityContext *context) = 0;

    virtual std::any visitMulti_nested_entity(schemaParser::Multi_nested_entityContext *context) = 0;

    virtual std::any visitName_declar(schemaParser::Name_declarContext *context) = 0;

    virtual std::any visitFile(schemaParser::FileContext *context) = 0;

    virtual std::any visitCsv(schemaParser::CsvContext *context) = 0;


};

