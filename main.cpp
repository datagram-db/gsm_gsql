#include <iostream>
#include "gsql_gsm/gsm_db_indices.h"

#include <gsql_gsm/gsql_operators.h>

#include <string>

#include <gsql_gsm/dump_to_xml.h>



int main() {
    // Database initialisation, with an empty root
    gsm_inmemory_db db;
    // Adding some nodes in it
    db = create(db, 1, {"nodes"}, {"sometext1"});
    db = create(db, 2, {"nodes"}, {"sometext2"});
    db = create(db, 3, {"nodes"}, {"sometext3"});
    db = create(db, 4, {"nodes2"}, {"sometext4"});
    db = create(db, 5, {"nodes1"}, {"sometext5"});
    // Setting that the root now shall contain the other elements, while updating 0 to a new object
    db = map(db, [](const gsm_object& ref) { return ref.ell; },
                 [](const gsm_object& ref) { return ref.xi;  },
                 [](const gsm_object& ref) {
        if (ref.id == 0) {
            std::unordered_map<std::string, std::vector<gsm_object_xi_content>> result;
            result["src"] = {{1,1.0}, {2,1.0}, {3,1.0}};
            result["dst"] = {{4,1.0}, {5,1.0}, {3,1.0}};
            return result;
        } else return ref.phi;
        });

    // Assuming that all of the operations are done:
    // Therefore, I can also set up the indices

    gsm_db_indices idx;
    idx.init(db);
    idx.valid_data();

    // Dumping the db into a XML format
    dump_to_xml(db, idx, "/home/giacomo/test.xml");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


