//
// Created by giacomo on 21/12/24.
//

#ifndef GSM2_XML_H
#define GSM2_XML_H

#include <libxml/tree.h>
#include <libxml/parser.h>
#include <libxml/parserInternals.h>

void start_element_callback(void *ctx, const xmlChar *name, const xmlChar **attrs);
void end_element(void *user_data, const xmlChar *name);
void character_callback(void *ctx,
                        const xmlChar *ch,
                        int len);

#endif //GSM2_XML_H
