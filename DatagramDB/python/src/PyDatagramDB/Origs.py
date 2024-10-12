from dataclasses import dataclass
from typing import Union, Dict, List
import xml.etree.ElementTree as ET

from PyDatagramDB.gsm_wrappers.MainMemoryBuilder import MainMemoryDBBuilder

union_minimal = Union[str, float]
from functools import lru_cache
# @dataclass()
# class gsm_object_xi_content:
#     id: int
#     score: float
#     property_values: Dict[str, union_minimal]
#     orig_edge_id: int=-1
#
# @dataclass
# class gsm_object:
#     id: int
#     ell: List[str]
#     xi: List[str]
#     scores: List[float]
#     phi: Dict[str, List[gsm_object_xi_content]]
#     content: Dict[str, union_minimal]







# class GSMObjectContent():
#     def __init__(self, obj, parent):
#         self.obj = obj
#         self.parent = parent
#         assert isinstance(obj, pydatagramdb.gsm_object_xi_content)
#         assert isinstance(parent, pydatagramdb.LinearGSM)
#
#     @property
#     def contentId(self):
#         return self.obj.id
#
#     @property
#     def score(self):
#         return self.obj.score

# def JSONUtil_escape(input):
#     output = ['"']
#
#     for ch in input:
#         chx = ord(ch)
#
#         # let's not put any nulls in our strings
#         assert chx != 0
#
#         if ch == '\n':
#             output.append("\\n")
#         elif ch == '\t':
#             output.append("\\t")
#         elif ch == '\r':
#             output.append("\\r")
#         elif ch == '\\':
#             output.append("\\\\")
#         elif ch == '"':
#             output.append("\\\"")
#         elif ch == '\b':
#             output.append("\\b")
#         elif ch == '\f':
#             output.append("\\f")
#         elif chx >= 0x10000:
#             assert False, "Python can handle characters larger than 2 bytes, but this should not occur."
#         elif chx > 127:
#             output.append("\\u{:04x}".format(chx))
#         else:
#             output.append(ch)
#
#     output.append('"')
#     return ''.join(output)
#
#
#
# def to_string(self):
#     b = []
#     b.append(f"id:{self.id}\n")
#
#     b.append("ell:\n")
#     for x in self.ell:
#         b.append(x.replace(".", "<dot>") + "\n")
#     b.append(".\n")
#
#     b.append("xi:\n")
#     for x in self.xi:
#         b.append(x.replace(".", "<dot>") + "\n")
#     b.append(".\n")
#
#     b.append("properties:\n")
#     for c, p in self.properties.items():
#         b.append(f"{JSONUtil_escape(c)}\t{JSONUtil_escape(p)}\n")
#     b.append(".\n")
#
#     b.append("phi:\n")
#     for c, p in self.phi.items():
#         b.append(f"{JSONUtil_escape(c)}\n")
#         for k in p:
#             b.append(f"\t{k.weight}\t{map.convert(k.content)}\n")
#         b.append(";")
#     b.append(".\n\n")
#
#     return ''.join(b)


import pydatagramdb




if __name__ == "__main__":
    class Node:
        def __init__(self, data):
            self.left = None
            self.right = None
            self.data = data

        def PrintTree(self):
            print(self.data)


    root = Node(10)
    root.right = Node(120)
    root.left = Node(5)
    root.left.left = Node(1)
    root.left.right = Node(7)
    root.right.right = Node(130)

    ser = MainMemoryDBBuilder()
    ser.toObjectDatabase(root)
    # print(res)

    p = """<?xml version="1.0"?>
<data>
    <country name="Liechtenstein">
        <rank>1</rank>
        <year>2008</year>
        <gdppc>141100</gdppc>
        <neighbor name="Austria" direction="E"/>
        <neighbor name="Switzerland" direction="W"/>
    </country>
    <country name="Singapore">
        <rank>4</rank>
        <year>2011</year>
        <gdppc>59900</gdppc>
        <neighbor name="Malaysia" direction="N"/>
    </country>
    <country name="Panama">
        <rank>68</rank>
        <year>2011</year>
        <gdppc>13600</gdppc>
        <neighbor name="Costa Rica" direction="W"/>
        <neighbor name="Colombia" direction="E"/>
    </country>
</data>"""
    root = ET.fromstring(p)
    ser.toObjectDatabase(root)

#     # ser.gsm_conversion(root, acc=acc)
#
#     # Create a Graph object
    import networkx as nx

    G = nx.MultiDiGraph()

    # Add the nodes to the graph, with properties
    G.add_node("Max", age=20, gender="male")
    G.add_node("Alice", age=22, gender="female")
    G.add_node("Bob", age=21, gender="male")

    # Add the edges to the graph
    G.add_edge("Max", "Alice", label="knows")
    G.add_edge("Alice", "Max", label="knows")
    G.add_edge("Alice", "Bob", label="knows")

    ser.toObjectDatabase(G)
    ser.initializeWithLoadedDatabases()

    obj = ser.getObjectFromDb(0,0)