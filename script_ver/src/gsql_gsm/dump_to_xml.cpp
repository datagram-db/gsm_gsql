/*
 * dump_to_xml.cpp
 * This file is part of gsm_gsql
 *
 * Copyright (C) 2018-2023 - Giacomo Bergami
 *
 * gsm_gsql is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gsm_gsql is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gsm_gsql. If not, see <http://www.gnu.org/licenses/>.
 */

 
//
// Created by giacomo on 05/02/23.
//

#include <gsql_gsm/dump_to_xml.h>
#include <tinyxml2.h>

void dump_to_xml(const gsm_inmemory_db& db,
                 const gsm_db_indices& idx,
                 const std::string& filename) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement *gsm = doc.NewElement("gsm");
    {
        tinyxml2::XMLElement *db_node = gsm->InsertNewChildElement("database");
        db_node->SetAttribute("o", db.max_id);
        for (const auto& [id, obj] : db.O) {
            tinyxml2::XMLElement *obj_node = db_node->InsertNewChildElement("object");
            std::string o_id = std::to_string(id);
            obj_node->SetAttribute("id", id);

            tinyxml2::XMLElement *ell_node = obj_node->InsertNewChildElement("ell");
//            for (const auto& l : obj.ell) {
                ell_node->InsertNewChildElement("item")->InsertNewText(obj.ell.c_str());
//            }

            tinyxml2::XMLElement *xi_node = obj_node->InsertNewChildElement("xi");
            for (const auto& l : obj.xi) {
                xi_node->InsertNewChildElement("item")->InsertNewText(l.c_str());
            }

            tinyxml2::XMLElement *phi_node = obj_node->InsertNewChildElement("phi");
            for (const auto& [k, vl] : obj.phi) {
                tinyxml2::XMLElement *entry = phi_node->InsertNewChildElement("key");
                entry->SetAttribute("id", k.c_str());
                for (const auto& entry_obj : vl ){
                    tinyxml2::XMLElement *item = entry->InsertNewChildElement("item");
                    std::string obj_id_cont = std::to_string(entry_obj.id);
                    std::string obj_score_cont = std::to_string(entry_obj.score);
                    item->SetAttribute("object", entry_obj.id);
                    item->SetAttribute("score", entry_obj.score);
                }
            }
        }
    }

    {
        tinyxml2::XMLElement *idx_node = gsm->InsertNewChildElement("indices");
        {
            tinyxml2::XMLElement *ell_index = idx_node->InsertNewChildElement("ell_index");
            for (const auto& [l, vl]: idx.ell_types) {
                tinyxml2::XMLElement *currKey = ell_index->InsertNewChildElement("key");
                currKey->SetAttribute("id", l.c_str());
                for (const auto i : vl)
                    currKey->InsertNewChildElement("item")->SetAttribute("id", i);
            }

            tinyxml2::XMLElement *containers = idx_node->InsertNewChildElement("containedBy");
            containers->SetAttribute("type", "graphml");
            containers->SetAttribute("id", "containedBy");
            containers->SetAttribute("edgedefault", "directed");
            for (size_t i = 0, N = idx.containedBy.maximumNodeId(); i<N; i++) {
                tinyxml2::XMLElement *node = containers->InsertNewChildElement("node");
                node->SetAttribute("id", i);
                size_t label = idx.containedBy.getUniqueLabel(i);
                node->SetAttribute("label", label);
                uint32_t high = (label & 0xFFFFFFFF00000000ULL) >> 32;
                uint32_t low = label & 0xFFFFFFFF;
                tinyxml2::XMLElement *datum = node->InsertNewChildElement("data");
                datum->SetAttribute("key_low", low);
                datum = node->InsertNewChildElement("data");
                datum->SetAttribute("key_high", high);
            }
            for (size_t i = 0, M = idx.containedBy.maximumEdgeId(); i<M; i++) {
                tinyxml2::XMLElement *node = containers->InsertNewChildElement("edge");
                node->SetAttribute("id", i);
                const std::string &label = idx.containedBy.getEdgeLabel(i);
                node->SetAttribute("label", label.c_str());
                auto cp = idx.containedBy.resolveEdgeById(i);
                node->SetAttribute("source", cp.first);
                node->SetAttribute("target", cp.second);
            }
            containers = idx_node->InsertNewChildElement("topological_sort_containedby");
            for (const auto& [t, nodes] : idx.containement_order) {
                tinyxml2::XMLElement *node = containers->InsertNewChildElement("time");
                node->SetAttribute("level", t);
                for (const auto idx : nodes) node->InsertNewChildElement("id")->SetText(idx);
            }

            containers = idx_node->InsertNewChildElement("containing");
            containers->SetAttribute("type", "graphml");
            containers->SetAttribute("id", "containing");
            containers->SetAttribute("edgedefault", "directed");
            for (size_t i = 0, N = idx.containerOf.maximumNodeId(); i<N; i++) {
                tinyxml2::XMLElement *node = containers->InsertNewChildElement("node");
                node->SetAttribute("id", i);
                size_t label = idx.containerOf.getUniqueLabel(i);
                node->SetAttribute("label", label);
                uint32_t high = (label & 0xFFFFFFFF00000000ULL) >> 32;
                uint32_t low = label & 0xFFFFFFFF;
                tinyxml2::XMLElement *datum = node->InsertNewChildElement("data");
                datum->SetAttribute("key_low", low);
                datum = node->InsertNewChildElement("data");
                datum->SetAttribute("key_high", high);
            }
            for (size_t i = 0, M = idx.containerOf.maximumEdgeId(); i<M; i++) {
                tinyxml2::XMLElement *node = containers->InsertNewChildElement("edge");
                node->SetAttribute("id", i);
                const std::string &label = idx.containerOf.getEdgeLabel(i);
                node->SetAttribute("label", label.c_str());
                auto cp = idx.containerOf.resolveEdgeById(i);
                node->SetAttribute("source", cp.first);
                node->SetAttribute("target", cp.second);
            }
            containers = idx_node->InsertNewChildElement("topological_sort_containerof");
            for (const auto& [t, nodes] : idx.container_order) {
                tinyxml2::XMLElement *node = containers->InsertNewChildElement("time");
                node->SetAttribute("level", t);
                for (const auto idx : nodes) node->InsertNewChildElement("id")->SetText(idx);
            }

            tinyxml2::XMLElement *siblingood = idx_node->InsertNewChildElement("siblinghood");
            siblingood->SetAttribute("type", "graphml");
            siblingood->SetAttribute("id", "siblinghood");
            siblingood->SetAttribute("edgedefault", "directed");
            for (size_t i = 0, N = idx.siblinghood.maximumNodeId(); i<N; i++) {
                tinyxml2::XMLElement *node = siblingood->InsertNewChildElement("node");
                node->SetAttribute("id", i);
                size_t label = idx.siblinghood.getUniqueLabel(i);
                node->SetAttribute("label", label);
                uint32_t high = (label & 0xFFFFFFFF00000000ULL) >> 32;
                uint32_t low = label & 0xFFFFFFFF;
                tinyxml2::XMLElement *datum = node->InsertNewChildElement("data");
                datum->SetAttribute("key_low", low);
                datum = node->InsertNewChildElement("data");
                datum->SetAttribute("key_high", high);
            }
            for (size_t i = 0, M = idx.siblinghood.maximumEdgeId(); i<M; i++) {
                tinyxml2::XMLElement *node = siblingood->InsertNewChildElement("edge");
                node->SetAttribute("id", i);
                const std::string &label = idx.siblinghood.getEdgeLabel(i);
                node->SetAttribute("label", label.c_str());
                auto cp = idx.siblinghood.resolveEdgeById(i);
                node->SetAttribute("source", cp.first);
                node->SetAttribute("target", cp.second);
            }
            siblingood = idx_node->InsertNewChildElement("topological_sort_siblinghood");
            for (const auto& [t, nodes] : idx.traversal_order) {
                tinyxml2::XMLElement *node = siblingood->InsertNewChildElement("time");
                node->SetAttribute("level", t);
                for (const auto idx : nodes) node->InsertNewChildElement("id")->SetText(idx);
            }
        }
    }

    doc.InsertEndChild(gsm);
    doc.SaveFile(filename.c_str(), false);
}
