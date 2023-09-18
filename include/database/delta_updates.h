//
// Created by giacomo on 17/09/23.
//

#ifndef GSM2_DELTA_UPDATES_H
#define GSM2_DELTA_UPDATES_H

#include <database/utility.h>
#include <roaring64map.hh>
#include <database/gsm_inmemory_db.h>

/**
 * Represents the partial instantiation of the rewriting patterns, either removing some nodes, or adding/changing something
 */
struct delta_updates {
    // Storing the information pertaining to the newly-inserted or updated objects
    struct gsm_inmemory_db delta_plus_db;
    // Storing the replaced objects
    std::unordered_map<size_t, size_t> replacement_map;
    std::unordered_map<std::string, std::vector<size_t>> newly_inserted_vertices;
    roaring::Roaring64Map newIterationInsertedObjects;
    std::vector<size_t> no_inserted_node;

    void clear_insertions(){
        newly_inserted_vertices.clear();
        newIterationInsertedObjects.clear();
    }


    inline const std::vector<size_t>& getNewlyInsertedVertices(const std::string&x) const {
        auto it = newly_inserted_vertices.find(x);
        if (it == newly_inserted_vertices.end())
            return no_inserted_node;
        else
            return it->second;
    }

    explicit delta_updates(size_t max_id)  {
        delta_plus_db.max_id = max_id;
    }

    inline void set_removed(size_t default_val) {
        size_t toRemove =getOrDefault(replacement_map, default_val, default_val);
                if (!newIterationInsertedObjects.contains(toRemove))
        removed_objects.insert(toRemove);
                else
                    removed_objects.insert(default_val);
    }

    inline void replaceWith(size_t orig, size_t dest) {
        DEBUG_ASSERT(!replacement_map.contains(orig));
        replacement_map[orig] = dest;
    }

    inline void associateNewToVar(const std::string& name, size_t id) {
        newly_inserted_vertices[name].emplace_back(id);
        newIterationInsertedObjects.add(id);
    }

    inline gsm_object& getNewObject() {
        delta_plus_db.max_id++;
        auto& obj = delta_plus_db.O[delta_plus_db.max_id];
        obj.id = delta_plus_db.max_id;
        return obj;
    }

    inline bool hasXBeenRemoved(size_t obj) const {
        return removed_objects.contains(obj);
    }
private:

    // Storing all the nodes that are removed
    std::unordered_set<size_t> removed_objects;
};


#endif //GSM2_DELTA_UPDATES_H
