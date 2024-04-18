__author__ = "Giacomo Bergami"
__copyright__ = "Copyright 2023"
__credits__ = ["Oliver Robert Fox", "Giacomo Bergami"]
__license__ = "GPL"
__version__ = "3.0"
__maintainer__ = "Giacomo Bergami"
__email__ = "bergamigiacomo@gmail.com"
__status__ = "Production"

import os

def property_value(property : str, value)->str:
    value = str(value).replace('"','\\"')
    return  f"{property}: '{value}'"

def properties(properties : dict):
    return "" if (properties is None or len(properties) == 0) else " {"+(", ".join(map(lambda x: property_value(x, properties[x]), properties)))+"}"

def edge(src, dst, label, prop=None):
    return f"CREATE (p{src})-[:{label}"+properties(prop)+f"]->(p{dst})"

class CreateGraph():
    def __init__(self):
        self.nodes = list()
        self.edges = list()

    def cypher_graph(self, g):
        self.nodes.clear()
        self.edges.clear()
        for node in g:
            self.node(node)
        return "CREATE q="+(", ".join(self.nodes))+os.linesep+(os.linesep.join(self.edges))+os.linesep+"RETURN *"

    def node(self, node_dict: dict):
        prop = node_dict["properties"]
        prop["label"] = node_dict["ell"][0]
        prop["name"] = node_dict["xi"][0]
        id = node_dict["id"]
        node = f"(p{id}"+properties(prop)+")"
        self.nodes.append(node)

        for d in node_dict["phi"]:
            label = str(d["containment"])
            dst = d["score"]["child"]
            src = d["score"]["parent"]
            self.edges.append(edge(src, dst, label.strip()))
