//
// Created by giacomo on 21/12/24.
//

#include <parser/xml.h>
#include <parser/schema/DataLoaderFromSchema.h>
#include <parser/writer.h>

void start_element_callback(void *ctx, const xmlChar *name, const xmlChar **attrs) {
    SchemaReader* loader = (SchemaReader*)ctx;
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
                            if (!loader->_isFirstPass) {
                                auto f = toppe.entity_stack->find(toppe.key).value();

                                auto result = loader->retrieve(f->ext_namespace,f->ext_entity,f->ext_field, val);
//                                auto result = loader->increasingIdCorrespondence[{f->ext_namespace,f->ext_entity,f->ext_field}][val];
                                toppe.object.phi[toppe.key].emplace_back( result);
                            }
                        } else if (!loader->_isFirstPass) {
                            if (toppe._keyType != NativeTypes::String) {
                                toppe.object.content.emplace(toppe.key,std::stod(val));
                            } else
                                toppe.object.content.emplace(toppe.key, val);
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
    SchemaReader* loader = (SchemaReader*)user_data;
    std::string tag{(char*)name};
    auto it = loader->state_stack.rbegin();
    auto fieldInfo = it->entity_stack->find(tag);
    if ((fieldInfo.has_value()) && (fieldInfo.value()->type == native_field || fieldInfo.value()->type == external_reference)) {
        // Just closing a normal tag, doing nothign associated with it
    } else if ((!fieldInfo.has_value()) && (it->current_tag_name == tag)) {
        {
            auto prev = it;
            prev++;
            it->object.id = loader->globalObjectId;
            loader->writer->writeObject(it->object, {});
            // TODO: associate it->data_row (first) or it-> containment to globalObjectId;
            it->object.clear();
            prev->object.phi[prev->key].emplace_back( loader->globalObjectId);
            loader->globalObjectId++;
            loader->state_stack.pop_back();
        }
    }
}


#include <yaucl/strings/string_utils.h>

void character_callback(void *ctx,
                        const xmlChar *str,
                        int length) {
    SchemaReader* loader = (SchemaReader*)ctx;
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
            } else {
                auto f = toppe.entity_stack->find(toppe.key).value();
                auto result = loader->retrieve(f->ext_namespace,f->ext_entity,f->ext_field, val);
//                auto result = loader->increasingIdCorrespondence[{f->ext_namespace,f->ext_entity,f->ext_field}][val];
                toppe.object.phi[toppe.key].emplace_back(result);
            }
        } else if (!loader->_isFirstPass) {
            if (toppe._keyType != NativeTypes::String) {
                toppe.object.content.emplace(toppe.key,std::stod(val));
            } else {
                toppe.object.content.emplace(toppe.key, val);
            }
        }
        toppe.key.clear();
    }
}