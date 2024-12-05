//
// Created by giacomo on 03/12/24.
//

#include <fstream>
#include "antlr4/schema_language/schemaLexer.h"
#include "antlr4/schema_language/schemaParser.h"
#include "antlr4/schema_language/schemaBaseVisitor.h"
#include <yaucl/data/json.h>

enum FileType {
    JSON,
    LJSON,
    CSV,
    XML
};

enum NativeTypes {
    String,
    UInt,
    Int,
    Double,
    Skip
};

enum FieldCases {
    native_field,
    external_reference,
    local_nested_entity_list,
    local_nested_entity,
    multi_nested_entity
};

struct Entity;

struct Field {
    bool is_id;
    bool xml_tag{false};
    bool xml_property{false};
    bool collective{false};
    bool multi{false};
    bool score{false};
    std::string namespace_;
    std::string entity;
    std::string field_name;
    std::string map_to_actual_field_or_attribute;
    size_t declaration_offset;

    FieldCases type;
    NativeTypes native_field_type;
    std::vector<Entity> nested_decl;

    std::string ext_namespace;
    std::string ext_entity;
    std::string ext_field;

    Field() = default;
    Field(const Field&) = default;
    Field(Field&&) = default;
    Field& operator=(const Field&) = default;
    Field& operator=(Field&&) = default;
};

struct Entity {
    std::string name;
    std::string namespace_;
    std::vector<std::string> fields_order;
    std::unordered_map<std::string, Field> fields;
    std::unordered_map<std::string, std::string> mapped_field_resolution;
    std::optional<std::string> id;
    std::unordered_set<std::string> attributes;
    std::string loading_filename;
    FileType type;
    bool has_csv_header;
    std::string sep;

    const std::optional<const Field*> find(const std::string& field_name_to_resolve) const {
        const auto& it1 = mapped_field_resolution.find(field_name_to_resolve);
        if (it1 != mapped_field_resolution.end()) {
            auto it2 =  fields.find(it1->second);
            if (it2 != fields.end())
                return {&it2->second};
        } else {
            auto it2 = fields.find(field_name_to_resolve);
            if (it2 != fields.end())
                return {&it2->second};
        }
        return {};
    }

    Entity() = default;
    Entity(const Entity&) = default;
    Entity(Entity&&) = default;
    Entity& operator=(const Entity&) = default;
    Entity& operator=(Entity&&) = default;
};

#include <yaucl/data/csv/parser.hpp>
#include <yaucl/data/csv/csv.h>

#include "rapidjson/reader.h"
#include <iostream>

using namespace rapidjson;
using namespace std;



struct NestingState {
    std::vector<std::pair<std::string,union_minimal>> data_row;
    std::vector<double> scores;
    std::vector<std::pair<std::string,size_t>> containment;
    const Entity* entity_stack{nullptr};
    bool skipCurrentKey;
    std::string key{};
    bool isThisScore{false};
    std::vector<size_t> objects;
    NativeTypes _keyType;
    size_t countFor = 0;
    size_t countAt = 0;
    std::string current_tag_name;

    NestingState(const Entity* e) : entity_stack{e} {}
};


#include "rapidjson/filereadstream.h"

#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>

void start_element_callback(void *ctx, const xmlChar *name, const xmlChar **attrs);
void end_element(void *user_data, const xmlChar *name);
void character_callback(void *ctx,
                        const xmlChar *ch,
                        int len);

#include <yaucl/structures/any_to_uint_bimap.h>
#include <yaucl/strings/serializers.h>
#include <stxxl.h>

struct DataLoaderFromSchema : schemaBaseVisitor {

    std::string namespace_;
    std::string loading_filename;
    FileType type;
    bool has_csv_header;
    bool first_pass;
    std::string sep;


    // TODO: secondary memory
    std::unordered_map<std::string, std::unordered_map<std::string, Entity>> loading_with_scheme;

    void load(const std::string& path) {
        std::ifstream data{path};
        antlr4::ANTLRInputStream input(data);
        schemaLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        schemaParser parser(&tokens);
        visitLanguage(parser.language());
    }

    std::any visitLanguage(schemaParser::LanguageContext *context) override {
        if (context) {
            for (const auto& ref : context->entity_declaration()) {
                visitEntity_declaration(ref);
            }

            globalObjectId = 0;
            for (auto& [namesp, map2] : loading_with_scheme) {
                for (auto& [entity_name, entity] : map2) {
                    switch (entity.type) {
                        case CSV:
                            load_csv(entity, true);
                            break;
                        case LJSON:
                            load_ljson(entity, true);
                        case JSON:
                            load_json(entity, true);
                        case XML:
                            load_xml(entity, true);
                        default:
                            break;
                    }
                }
            }

            globalObjectId = 0;
            for (auto& [namesp, map2] : loading_with_scheme) {
                for (auto& [entity_name, entity] : map2) {
                    switch (entity.type) {
                        case CSV:
                            load_csv(entity, false);
                            break;
                        case LJSON:
                            load_ljson(entity, false);
                        case JSON:
                            load_json(entity, false);
                        case XML:
                            load_xml(entity, true);
                        default:
                            break;
                    }
                }
            }
        }
        return {};
    }



    std::any visitEntity_declaration(schemaParser::Entity_declarationContext *context) override {
        if (context) {
            auto file = context->file();
            if (file) {
                namespace_ = context->WORD()->getText();
                auto csv = file->csv();
                if (file->XML())
                    type = XML;
                else if (file->JSON())
                    type = JSON;
                else if (file->LJSON())
                    type = LJSON;
                else if (csv) {
                    type = CSV;
                    has_csv_header = csv->WITH_HEADER();
                    if (csv->SEP()) {
                        sep = UNESCAPE(csv->EscapedString()->getText());
                    } else {
                        sep = ",";
                    }
                } else {
                    sep.clear();
                    has_csv_header = false;
                }
                loading_filename = UNESCAPE(file->EscapedString()->getText());
                auto e = std::any_cast<Entity>(visitLocal_entity_declaration(context->local_entity_declaration()));
                loading_with_scheme[namespace_][e.name] = std::move(e);
            }
        }
        return {};
    }

    std::any visitLocal_entity_declaration(schemaParser::Local_entity_declarationContext *ctx) override {
        if (ctx) {
            std::string name = ctx->entity->getText();
            Entity e;
            e.name = name;
            e.namespace_ = this->namespace_;
            size_t declaration_offset = 0;
            for (auto& field : ctx->field()) {
                auto f = std::any_cast<Field>(visit(field));
                f.declaration_offset = declaration_offset;
                e.fields_order.emplace_back(f.field_name);
                f.entity = e.name;
                f.namespace_ = e.namespace_;
                e.fields.emplace(f.field_name, f);
                if (f.is_id) {
                    if (!e.id) {
                        e.id = f.field_name;
                    }
                }
                if (f.xml_property) {
                    e.attributes.emplace(f.field_name);
                }
                if (!f.map_to_actual_field_or_attribute.empty())
                    e.mapped_field_resolution[f.map_to_actual_field_or_attribute] = f.field_name;
                declaration_offset++;
            }
            e.has_csv_header = has_csv_header;
            e.loading_filename = loading_filename;
            e.type = type;
            e.has_csv_header = has_csv_header;
            e.sep = sep;
            return e;
        }
        return {};
    }

    virtual std::any visitNative_field(schemaParser::Native_fieldContext *ctx) override {
        Field f;
        f.type = native_field;
        if (ctx) {
            f.is_id = ctx->STAR();
            f.xml_tag = ctx->TAG();
            f.xml_property = ctx->PROPERTY();
            if ((!f.xml_tag) && (!f.xml_property)) {
                f.xml_property = f.is_id;
                f.xml_tag = !f.xml_property;
            }
            f.field_name = ctx->name->getText();
            if (ctx->map) {
                f.map_to_actual_field_or_attribute = UNESCAPE(ctx->map->getText());
            }
            f.native_field_type = std::any_cast<NativeTypes>(visit(ctx->type()));
            if (ctx->SCORE()) {
                f.score= (f.native_field_type == NativeTypes::Double);
            }
        }
        return f;
    }

    virtual std::any visitExternal_reference(schemaParser::External_referenceContext *ctx) override {
        Field f;
        f.type = external_reference;
        if (ctx) {
            auto nd = ctx->name_declar();
            f.is_id = ctx->STAR();
            f.xml_tag = ctx->TAG();
            f.xml_property = ctx->PROPERTY();
            if ((!f.xml_tag) && (!f.xml_property)) {
                f.xml_tag = false;
                f.xml_property = true;
            }
            f.field_name = ctx->name->getText();
            if (ctx->map) {
                f.map_to_actual_field_or_attribute = UNESCAPE(ctx->map->getText());
            }
            if (nd) {
                f.ext_namespace = nd->namespace_->getText();
                f.ext_entity = nd->entity->getText();
            }
            f.ext_field = ctx->ext_field_name->getText();
        }
        return f;
    }

    virtual std::any visitLocal_nested_entity_list(schemaParser::Local_nested_entity_listContext *ctx) override {
        Field f;
        f.type = local_nested_entity_list;
        if (ctx) {
            f.is_id = ctx->STAR();
            f.xml_tag = true;
            f.xml_property = false;
            f.field_name = ctx->name->getText();
            if (ctx->map) {
                f.map_to_actual_field_or_attribute = UNESCAPE(ctx->map->getText());
            }
            f.collective = true;
            f.nested_decl.emplace_back(std::any_cast<Entity>(visitLocal_entity_declaration(ctx->local_entity_declaration())));
        }
        return f;
    }

    virtual std::any visitLocal_nested_entity(schemaParser::Local_nested_entityContext *ctx) override {
        Field f;
        f.type = local_nested_entity;
        if (ctx) {
            f.is_id = ctx->STAR();
            f.xml_tag = true;
            f.xml_property = false;
            f.field_name = ctx->name->getText();
            if (ctx->map) {
                f.map_to_actual_field_or_attribute = UNESCAPE(ctx->map->getText());
            }
            f.nested_decl.emplace_back(std::any_cast<Entity>(visitLocal_entity_declaration(ctx->local_entity_declaration())));
        }
        return f;
    }

    virtual std::any visitMulti_nested_entity(schemaParser::Multi_nested_entityContext *ctx) override {
        Field f;
        f.type = multi_nested_entity;
        if (ctx) {
            f.is_id = ctx->STAR();
            f.xml_tag = true;
            f.xml_property = false;
            f.field_name = ctx->name->getText();
            if (ctx->map) {
                f.map_to_actual_field_or_attribute = UNESCAPE(ctx->map->getText());
            }
            f.multi = true;
            f.nested_decl.emplace_back(std::any_cast<Entity>(visitLocal_entity_declaration(ctx->local_entity_declaration())));
        }
        return f;
    }

    virtual std::any visitT_string(schemaParser::T_stringContext *ctx) override {
        return NativeTypes::String;
    }

    virtual std::any visitT_uint(schemaParser::T_uintContext *ctx) override {
        return NativeTypes::UInt;
    }

    virtual std::any visitT_int(schemaParser::T_intContext *ctx) override {
        return NativeTypes::Int;
    }

    virtual std::any visitT_double(schemaParser::T_doubleContext *ctx) override {
        return NativeTypes::Double;
    }

    size_t globalObjectId = 0;
    struct CompareGreaterString {
        bool operator () (const std::string& a, const std::string& b) const {
            return a > b;
        }
        static std::string max_value() {
            return std::string(10000, std::numeric_limits<unsigned char>::max());
        }
    };


    typedef stxxl::map<std::string,size_t,CompareGreaterString, 4096, 4096> map_type;
    std::map<std::tuple<size_t,size_t,size_t>,size_t> mampa;
    std::list<stxxl::map<std::string,size_t,CompareGreaterString>> result;
    std::vector<std::list<stxxl::map<std::string,size_t,CompareGreaterString>>::reverse_iterator> offsetMap;


//    std::map<std::tuple<std::string,std::string,std::string>, std::unordered_map<std::string,size_t>> increasingIdCorrespondence;
    yaucl::structures::any_to_uint_bimap<std::string> namespace_idx;
    yaucl::structures::any_to_uint_bimap<std::string> entities_idx;
    yaucl::structures::any_to_uint_bimap<std::string> fields_idx;

    inline void update(const std::string& ns, const std::string& e, const std::string& f, const std::string& value, size_t set) {
        std::tuple<size_t, size_t, size_t> s{namespace_idx.put(ns).first,entities_idx.put(e).first,fields_idx.put(f).first};
        size_t offset = mampa.emplace(s, mampa.size()).first->second;
        if (result.size() == offset) {
            result.emplace_back((map_type::node_block_type::raw_size)*3, (map_type::leaf_block_type::raw_size)*3);
            offsetMap.emplace_back(result.rbegin());
        }
        (*offsetMap[offset])[value] = set;
    }

    inline size_t retrieve(const std::string& ns, const std::string& e, const std::string& f, const std::string& value) {
        std::tuple<size_t, size_t, size_t> s{namespace_idx.put(ns).first,entities_idx.put(e).first,fields_idx.put(f).first};
        size_t offset = mampa.emplace(s, mampa.size()).first->second;
        if (result.size() == offset) {
            result.emplace_back((map_type::node_block_type::raw_size)*3, (map_type::leaf_block_type::raw_size)*3);
            offsetMap.emplace_back(result.rbegin());
        }
        return (*offsetMap[offset])[value];
    }
    
    std::vector<NestingState> state_stack;
//    NativeTypes _keyType;
    bool _isFirstPass;
    bool Null() {  return true; }
    bool Bool(bool b) {
        auto& toppe = *state_stack.rbegin();
        if (!toppe.isThisScore) {
            if (!toppe.skipCurrentKey) {
                if (_isFirstPass) {
                    std::string val3=b ? "true" : "false";
                    if ((toppe.entity_stack->find(toppe.key).value()->is_id)) {
                        update(toppe.entity_stack->namespace_, toppe.entity_stack->name, toppe.key,val3,globalObjectId);
                    }
                    if (toppe._keyType == NativeTypes::String)
                        toppe.data_row.emplace_back(toppe.key, b ? "true" : "false");
                    else
                        toppe.data_row.emplace_back(toppe.key, b ? 1.0 : 0.0);
                }
            } else if (!_isFirstPass) {
                auto f = toppe.entity_stack->find(toppe.key).value();
                auto result = retrieve(f->ext_namespace, f->ext_entity, f->ext_field, b ? "true"
                                                                          : "false");
//                auto result = increasingIdCorrespondence[{f->ext_namespace, f->ext_entity, f->ext_field}][(b ? "true"
//                                                                                                             : "false")];
                toppe.containment.emplace_back(toppe.key, result);
            }
        }
        toppe.isThisScore = false;
        toppe.key.clear();
        return true;
    }
    bool Int(int d) {
        auto& toppe = *state_stack.rbegin();
        if (!toppe.isThisScore) {
            if (!toppe.skipCurrentKey) {
                if (_isFirstPass) {
                    std::string val3=std::to_string(d);
                    if ((toppe.entity_stack->find(toppe.key).value()->is_id)) {
                        update(toppe.entity_stack->namespace_, toppe.entity_stack->name, toppe.key,val3,globalObjectId);
                    }
                    if ((toppe._keyType != NativeTypes::Int))
                        return false;
                    toppe.data_row.emplace_back(toppe.key, (double) d);
                }
            } else if (!_isFirstPass) {
                auto f = toppe.entity_stack->find(toppe.key).value();
                auto result = retrieve(f->ext_namespace, f->ext_entity,
                                                          f->ext_field,std::to_string(d));
                toppe.containment.emplace_back(toppe.key, result);
            }
        }
        toppe.isThisScore = false;
        toppe.key.clear();
        return true;
    }
    bool Uint(unsigned d) {
        auto& toppe =*state_stack.rbegin();
        if (!toppe.isThisScore) {
            if (!toppe.skipCurrentKey) {
                if (_isFirstPass) {
                    std::string val3=std::to_string(d);
                    if ((toppe.entity_stack->find(toppe.key).value()->is_id)) {
                        update(toppe.entity_stack->namespace_, toppe.entity_stack->name, toppe.key,val3,globalObjectId);
                    }
                    if ((toppe._keyType != NativeTypes::UInt) && (toppe._keyType != NativeTypes::Int))
                        return false;
                    toppe.data_row.emplace_back(toppe.key, (double) d);
                }
            } else if (!_isFirstPass) {
                auto f = toppe.entity_stack->find(toppe.key).value();
                auto result = retrieve(f->ext_namespace, f->ext_entity,
                                                          f->ext_field,std::to_string(d));
                toppe.containment.emplace_back(toppe.key, result);
            }
        }
        toppe.isThisScore=false;
        toppe.key.clear();
        return true;
    }
    bool Int64(int64_t d) {
        auto& toppe = *state_stack.rbegin();
        if (!toppe.isThisScore) {
            if (!toppe.skipCurrentKey) {
                if (_isFirstPass) {
                    std::string val3=std::to_string(d);
                    if ((toppe.entity_stack->find(toppe.key).value()->is_id)) {
                        update(toppe.entity_stack->namespace_, toppe.entity_stack->name, toppe.key,val3,globalObjectId);
                    }
                    if ((toppe._keyType != NativeTypes::UInt) && (toppe._keyType != NativeTypes::Int))
                        return false;
                    toppe.data_row.emplace_back(toppe.key, (double) d);
                }
            } else if (!_isFirstPass) {
                auto f = toppe.entity_stack->find(toppe.key).value();
                auto result = retrieve(f->ext_namespace, f->ext_entity,
                                                          f->ext_field,std::to_string(d));
                toppe.containment.emplace_back(toppe.key, result);
            }
        }
        toppe.isThisScore = false;
        toppe.key.clear();
        return true;
    }
    bool Uint64(uint64_t d) {
        auto& toppe = *state_stack.rbegin();
        if (!toppe.isThisScore) {
            if ((!toppe.skipCurrentKey)) {
                if (_isFirstPass) {
                    std::string val3=std::to_string(d);
                    if ((toppe.entity_stack->find(toppe.key).value()->is_id)) {
                        update(toppe.entity_stack->namespace_, toppe.entity_stack->name, toppe.key,val3,globalObjectId);
                    }
                    if ((toppe._keyType != NativeTypes::UInt) && (toppe._keyType != NativeTypes::Int))
                        return false;

                    toppe.data_row.emplace_back(toppe.key, (double) d);
                }
            } else if (!_isFirstPass) {
                auto f = toppe.entity_stack->find(toppe.key).value();
                auto result = retrieve(f->ext_namespace, f->ext_entity,
                                                          f->ext_field,std::to_string(d));
                toppe.containment.emplace_back(toppe.key, result);
            }
        }
        toppe.isThisScore = false;
        toppe.key.clear();
        return true;
    }
    bool Double(double d) {
        auto& toppe = *state_stack.rbegin();
        if (!toppe.skipCurrentKey) {
            if (_isFirstPass) {
                std::string val3=std::to_string(d);
                if ((toppe.entity_stack->find(toppe.key).value()->is_id)) {
                    update(toppe.entity_stack->namespace_, toppe.entity_stack->name, toppe.key,val3,globalObjectId);
                }
                if (toppe._keyType != NativeTypes::Double)
                    return false;
                if (toppe.isThisScore)
                    toppe.scores.emplace_back(d);
                else
                    toppe.data_row.emplace_back(toppe.key, d);
            }
        } else if (!_isFirstPass) {
            auto f = toppe.entity_stack->find(toppe.key).value();
            auto result = retrieve(f->ext_namespace,f->ext_entity,f->ext_field,std::to_string(d));
//            auto result = increasingIdCorrespondence[{f->ext_namespace,f->ext_entity,f->ext_field}][std::to_string(d)];
            toppe.containment.emplace_back(toppe.key, result);
        }
        toppe.isThisScore = false;
        toppe.key.clear();
        return true;
    }
    bool RawNumber(const char* str, SizeType length, bool copy) {
        auto& toppe = *state_stack.rbegin();
        if (!toppe.skipCurrentKey) {
            if (_isFirstPass) {
                std::string val3(str, length);
                if ((toppe.entity_stack->find(toppe.key).value()->is_id)) {
                    update(toppe.entity_stack->namespace_, toppe.entity_stack->name, toppe.key,val3,globalObjectId);
                }
                if (toppe._keyType == NativeTypes::String)
                    toppe.data_row.emplace_back(toppe.key, std::string(str, length));
                else if (toppe.isThisScore)
                    toppe.scores.emplace_back(std::stod(std::string(str, length)));
                else {
                    toppe.data_row.emplace_back(toppe.key,std::stod(std::string(str, length)));
                }
            }
        } else if (!_isFirstPass) {
            auto f = toppe.entity_stack->find(toppe.key).value();
            auto result = retrieve(f->ext_namespace,f->ext_entity,f->ext_field, std::string(str, length));
//            auto result = increasingIdCorrespondence[{f->ext_namespace,f->ext_entity,f->ext_field}][std::string(str, length)];
            toppe.containment.emplace_back(toppe.key, result);
        }
        toppe.skipCurrentKey= false;
        toppe.key.clear();
        return true;
    }
    bool String(const char* str, SizeType length, bool copy) {
        auto& toppe = *state_stack.rbegin();
        if (!toppe.skipCurrentKey) {
            if (!toppe.skipCurrentKey) {
                if (_isFirstPass) {
                    std::string val3(str, length);
                    if ((toppe.entity_stack->find(toppe.key).value()->is_id)) {
                        update(toppe.entity_stack->namespace_, toppe.entity_stack->name, toppe.key,val3,globalObjectId);
                    }
                    if (toppe._keyType != NativeTypes::String) {
                        toppe.data_row.emplace_back(toppe.key, std::stod(std::string(str, length)));
                    } else
                        toppe.data_row.emplace_back(toppe.key, std::string(str, length));
                }
            } else if (!_isFirstPass) {
                auto f = toppe.entity_stack->find(toppe.key).value();

                auto result = retrieve(f->ext_namespace,f->ext_entity,f->ext_field, std::string(
                        str, length));
//                auto result = increasingIdCorrespondence[{f->ext_namespace, f->ext_entity, f->ext_field}][std::string(
//                        str, length)];
                toppe.containment.emplace_back(toppe.key, result);
            }
        }
        toppe.skipCurrentKey = false;
        toppe.key.clear();
        return true;
    }
    bool StartObject() {
        state_stack.rbegin()->countAt--;
        return true;
    }

    bool Key(const char* str, SizeType length, bool copy) {
         auto& toppe = *state_stack.rbegin();
        const auto& e = toppe.entity_stack;
        toppe.key = std::string(str, length);
        toppe.skipCurrentKey = !_isFirstPass;
        auto itv2 = e->find(toppe.key);
//        auto it = e->fields.find(toppe.key);
        if (itv2.has_value()) {
            toppe._keyType = itv2.value()->native_field_type;
            switch (itv2.value()->type) {
                case native_field:
                    toppe.isThisScore = itv2.value()->score;
                    break;
                case external_reference:
                {
                    if (!_isFirstPass) {
                        auto it1 = loading_with_scheme.find(itv2.value()->ext_namespace);
                        if (it1 == loading_with_scheme.end())
                            return false;
                        auto it2 = it1->second.find(itv2.value()->ext_entity);
                        if (it2 == it1->second.end())
                            return false;
                        auto it3 = it2->second.fields.find(itv2.value()->ext_field);
                        if (it3 == it2->second.fields.end())
                            return false;
                        toppe.skipCurrentKey = false;
                    } else {
                        toppe.skipCurrentKey = true;
                    }
                }
                    break;
                case local_nested_entity_list:
                case local_nested_entity:
                case multi_nested_entity: {
                    if ((itv2.value()->nested_decl.empty()))
                        return false;
                    state_stack.emplace_back(&itv2.value()->nested_decl[0]);
                    state_stack.rbegin()->countFor = state_stack.rbegin()->countAt = itv2.value()->type == local_nested_entity ? 1 : 2;
                }
                   break;
            }
        }
        return true;
    }
    bool EndObject(SizeType memberCount) {
        // TODO: serialize the object in the stack
        auto it = state_stack.rbegin();
        it->countAt++;
        if (it->countAt == it->countFor) {
            auto prev = it;
            prev++;
            // TODO: associate it->data_row (first) or it-> containment to globalObjectId;
            it->data_row.clear();
            it->containment.clear();
            it->scores.clear();
            prev->containment.emplace_back(prev->key, globalObjectId);
            globalObjectId++;
            state_stack.pop_back();
        } else {
            // associate it->data_row (first) or it-> containment to globalObjectId;
            it->objects.emplace_back(globalObjectId);
            globalObjectId++;
        }
        return true;
    }
    bool StartArray() {
        state_stack.rbegin()->countAt--;
        return true;
    }
    bool EndArray(SizeType elementCount) {
        auto it = state_stack.rbegin();
        it->countAt++;
        if (it->countAt == it->countFor) {
            auto prev = it;
            prev++;
            for (size_t object : it->objects)
                prev->containment.emplace_back(prev->key, object);
            state_stack.pop_back();
        } else {
            // associate it->data_row (first) or it-> containment to globalObjectId;
            it->objects.emplace_back(globalObjectId);
            globalObjectId++;
        }
        return true;
    }

    bool load_ljson(const Entity& e, bool isFirstPass) {
        std::string line;
        std::ifstream infile{e.loading_filename};
        while (std::getline(infile, line))
        {
            if (!load_json(e, isFirstPass, line))
                return false;
        }
        return true;
    }

    bool load_json(const Entity& e, bool isFirstPass, const std::string& json = "") {
        state_stack.emplace_back(&e);
        rapidjson::Reader reader;
        if (!json.empty()) {
            rapidjson::StringStream ss{json.c_str()};
            _isFirstPass = isFirstPass;
            if (!reader.Parse(ss, *this))
                return false;
        } else {
            FILE *ff = fopen(e.loading_filename.c_str(), "r");
            char buffer[4096];
            rapidjson::FileReadStream ss{ff, buffer, sizeof(buffer)};
            _isFirstPass = isFirstPass;
            if (!reader.Parse(ss, *this))
                return false;
            fclose(ff);
        }
        state_stack.clear();
        return true;
    }

    bool load_xml(const Entity& e, bool isFirstPass) {
        first_pass = true;
        state_stack.emplace_back(&e);
        _isFirstPass = isFirstPass;
        //    dl.load("/home/giacomo/Scaricati/Unibench-0.2/Dataset/Schema.txt");
//    std::cout << "Hello world!" << std::endl;

        // Initialize all fields to zero
        xmlSAXHandler sh = { 0 };

        // register callback
        sh.startElement = start_element_callback;
        sh.endElement = end_element;
        sh.characters =character_callback;

        xmlParserCtxtPtr ctxt;

        // create the context
        if ((ctxt = xmlCreateFileParserCtxt(e.loading_filename.c_str() )) == NULL) {
            fprintf(stderr, "Erreur lors de la création du contexte\n");
            return EXIT_FAILURE;
        }
        // register sax handler with the context
        ctxt->sax = &sh;
        ctxt->userData = this;

        // parse the doc
        xmlParseDocument(ctxt);
        // well-formed document?
        return ctxt->wellFormed;
    }

    bool load_csv(const Entity& e, bool isFirstPass) {
        // TODO: loader
        std::vector<std::pair<std::string,union_minimal>> dr;
        std::vector<std::pair<std::string,size_t>> cc;
        std::vector<double> score;
        std::ifstream input_file(e.loading_filename);
        aria::csv::CsvParser parser = aria::csv::CsvParser(input_file);
        parser.delimiter(e.sep[0]);

        bool first_row = e.has_csv_header;
        table data;
//        std::vector<std::pair<std::string,union_minimal>> data_row;
//        std::vector<std::pair<std::string,size_t>> containment;
        std::vector<std::string> headers;
        std::unordered_map<std::string, size_t> S;
        std::vector<ssize_t> header_mapping;

        for (auto &row : parser) {
            if (first_row) {
                first_row = false;
                size_t offset = 0;
                for (auto &field : row) {
                    S.emplace(field, offset);
                    offset++;
                }
                header_mapping.resize(offset, -1);

                for (auto& declared_field_name: e.fields_order) {
                    const auto f = e.fields.find(declared_field_name);
                    if (f->second.map_to_actual_field_or_attribute.empty()) {
                        auto it = S.find(f->first);
                        if (it == S.end()) {
                            return false;
                        } else {
                            headers.push_back(declared_field_name);
                            header_mapping[it->second] = f->second.declaration_offset;
                        }
                    } else {
                        const auto& first = f->second.map_to_actual_field_or_attribute;
                        auto it = S.find(first);
                        if (it == S.end()) {
                            return false;
                        } else {
                            headers.push_back(declared_field_name);
                            header_mapping[it->second] = f->second.declaration_offset;
                        }
                    }
                }

                data.SetHeaders(headers);
                continue;
            }

            size_t idx = 0;
            for (auto &field : row) {

                auto offset = header_mapping.empty() ? idx : header_mapping[idx];
                if ((!field.empty()) && (offset != -1)) {
                    auto it = e.find(e.fields_order[offset]);
                    if (it.has_value()) {
                        auto val = it.value();
                        if (isFirstPass && (val->is_id)) {
                            update(e.namespace_, e.name, val->field_name,field,globalObjectId);
                        }
                        auto type_ = val->native_field_type;
                        switch (val->type) {
                            case native_field:
                                break;
                            case external_reference:
                            {
                                auto it1 = loading_with_scheme.find(val->ext_namespace);
                                if (it1 == loading_with_scheme.end())
                                    return false;
                                auto it2 = it1->second.find(val->ext_entity);
                                if (it2 == it1->second.end())
                                    return false;
                                auto it3 = it2->second.find(val->ext_field);
                                if (!it3.has_value())
                                    return false;
                                if ((!isFirstPass) && (it3.value()->is_id)) {
                                    type_ = Skip;

                                    auto result = retrieve(val->ext_namespace,val->ext_entity,val->ext_field, field);
//                                    auto result = increasingIdCorrespondence[{val->ext_namespace,val->ext_entity,val->ext_field}][field];
                                    cc.emplace_back(headers.empty() ? val->field_name : headers.at(idx), result);
                                } else
                                    type_ = it3.value()->native_field_type;
                            }
                                break;
                            case local_nested_entity_list:
                            case local_nested_entity:
                            case multi_nested_entity:
                                return false;
                        }
                        if (isFirstPass && (!val->score)) {
                            switch (type_) {
                                case NativeTypes::String:
                                    dr.emplace_back(headers.empty() ? val->field_name : headers.at(idx), field);
                                    break;
                                case NativeTypes::UInt:
                                    dr.emplace_back(headers.empty() ? val->field_name : headers.at(idx), (double)std::stoull(field));
                                    break;
                                case NativeTypes::Int:
                                    dr.emplace_back(headers.empty() ? val->field_name : headers.at(idx), (double)std::stoll(field));
                                    break;
                                case NativeTypes::Double:
                                    dr.emplace_back(headers.empty() ? val->field_name : headers.at(idx), std::stod(field));
                                    break;
                                default:
                                    break;
                            }
                        } else if (val->score && type_ == NativeTypes::Double) {
                            score.emplace_back(std::stod(field));
                        }
                    }
                }
                idx++;
            }

            if (isFirstPass) {
                // TODO: set the attributes value to the current object ids, and consider score
                data.AddRow(dr);
            } else {
                // TODO: set the containment attributes to the current object ids
            }
            dr.clear();
            cc.clear();
            globalObjectId++;
        }
        return true;
    }

};



void start_element_callback(void *ctx, const xmlChar *name, const xmlChar **attrs) {
    DataLoaderFromSchema* loader = (DataLoaderFromSchema*)ctx;
    std::string tag{(char*)name};
//    printf("Beginning of element : %s \n", name);

//    bool starting_tag = loader->state_stack.size() == 1;
    auto& toppe = *loader->state_stack.rbegin();
    const auto& e = toppe.entity_stack;
    toppe.key = tag;//std::string(str, length);
    toppe.skipCurrentKey = !loader->_isFirstPass;
    auto itv2 = e->find(toppe.key);
//    auto it = e->fields.find(toppe.key);
    if ((loader->first_pass) || (itv2.has_value() && (itv2.value()->xml_tag))) {
        toppe._keyType = loader->first_pass ? Skip : itv2.value()->native_field_type;
        auto root = loader->first_pass ? local_nested_entity : itv2.value()->type;
        switch (root) {
            case native_field:
                return;
            case external_reference:
            {
                if (!loader->_isFirstPass) {
                    auto it1 = loader->loading_with_scheme.find(itv2.value()->ext_namespace);
                    if (it1 == loader->loading_with_scheme.end())
                        return;
                    auto it2 = it1->second.find(itv2.value()->ext_entity);
                    if (it2 == it1->second.end())
                        return;
                    auto it3 = it2->second.find(itv2.value()->ext_field);
                    if (!it3.has_value())
                        return;
                    toppe.skipCurrentKey = false;
                } else {
                    toppe.skipCurrentKey = true;
                }
            }
                break;
            case local_nested_entity_list:
            case local_nested_entity:
            case multi_nested_entity: {
                if (!loader->first_pass) {
                    if ((itv2.value()->nested_decl.empty()))
                        return;
                    loader->state_stack.emplace_back(&itv2.value()->nested_decl[0]).current_tag_name = tag;
                } else {
                    loader->first_pass = false;
                }
                auto final = loader->state_stack.rbegin();
                while (NULL != attrs && NULL != attrs[0]) {
                    auto dis = final->entity_stack->find(std::string((char*)attrs[0]));
                    if ((!dis.has_value()) && (dis.value()->xml_tag)) {
                        std::string val{(char*)attrs[1]};
                        if (!toppe.skipCurrentKey) {
                            if (loader->_isFirstPass) {
                                if (toppe._keyType != NativeTypes::String) {
                                    toppe.data_row.emplace_back(toppe.key,std::stod(val));
                                } else
                                    toppe.data_row.emplace_back(toppe.key, val);
                            } else {
                                auto f = toppe.entity_stack->find(toppe.key).value();

                                auto result = loader->retrieve(f->ext_namespace,f->ext_entity,f->ext_field, val);
//                                auto result = loader->increasingIdCorrespondence[{f->ext_namespace,f->ext_entity,f->ext_field}][val];
                                toppe.containment.emplace_back(toppe.key, result);
                            }
                        }
                    }
                    attrs = &attrs[2];
                }

//                loader->state_stack.rbegin()->countFor = loader->state_stack.rbegin()->countAt = it->second.type == local_nested_entity ? 1 : 2;
            }
                break;
        }
    }
//    return true;

//
//    auto it = loader->state_stack.rbegin();

}

void end_element(void *user_data, const xmlChar *name) {
    DataLoaderFromSchema* loader = (DataLoaderFromSchema*)user_data;
    std::string tag{(char*)name};
    auto it = loader->state_stack.rbegin();
    auto fieldInfo = it->entity_stack->find(tag);
    if ((fieldInfo.has_value()) && (fieldInfo.value()->type == native_field || fieldInfo.value()->type == external_reference)) {
        // Just closing a normal tag, doing nothign associated with it
    } else if ((!fieldInfo.has_value()) && (it->current_tag_name == tag)) {
        {
            auto prev = it;
            prev++;
            // TODO: associate it->data_row (first) or it-> containment to globalObjectId;
            it->data_row.clear();
            it->containment.clear();
            prev->containment.emplace_back(prev->key, loader->globalObjectId);
            loader->globalObjectId++;
            loader->state_stack.pop_back();
        }
    }
}


#include <yaucl/strings/string_utils.h>

void character_callback(void *ctx,
                        const xmlChar *str,
                        int length) {
    DataLoaderFromSchema* loader = (DataLoaderFromSchema*)ctx;
    auto& toppe = *loader->state_stack.rbegin();
    std::string val((char*)str, length);
    yaucl::strings::trim(val);
    if ((!val.empty()) && (!toppe.key.empty())) {
        if (!toppe.skipCurrentKey) {
            if (loader->_isFirstPass) {
                auto val2 = toppe.entity_stack->find(toppe.key).value();
                if ((val2->is_id)) {
                    loader->update(toppe.entity_stack->namespace_, toppe.entity_stack->name, val2->field_name,val,loader->globalObjectId);
                }
                if (toppe._keyType != NativeTypes::String) {
                    toppe.data_row.emplace_back(toppe.key,std::stod(val));
                } else
                    toppe.data_row.emplace_back(toppe.key, val);
            } else {
                auto f = toppe.entity_stack->find(toppe.key).value();
                auto result = loader->retrieve(f->ext_namespace,f->ext_entity,f->ext_field, val);
//                auto result = loader->increasingIdCorrespondence[{f->ext_namespace,f->ext_entity,f->ext_field}][val];
                toppe.containment.emplace_back(toppe.key, result);
            }
        }
        toppe.key.clear();
    }
}

int main(void) {
    DataLoaderFromSchema dl;
    dl.load("/home/giacomo/Scaricati/Unibench-0.2/Dataset/Schema.txt");
    std::cout << "Hello world!" << std::endl;


    return EXIT_SUCCESS;
}
