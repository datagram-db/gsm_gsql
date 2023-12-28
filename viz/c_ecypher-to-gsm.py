__author__ = "Giacomo Bergami"
__copyright__ = "Copyright 2023"
__credits__ = ["Giacomo Bergami"]
__license__ = "GPL"
__version__ = "3.0"
__maintainer__ = "Giacomo Bergami"
__email__ = "bergamigiacomo@gmail.com"
__status__ = "Production"
import json
import sys

import antlr4
from antlr4 import FileStream, InputStream

from fast_graph.fastgraphLexer import fastgraphLexer
from fast_graph.fastgraphParser import fastgraphParser
from gsm.object import gsm_object
from gsm.utils import uniqueId



if __name__== "__main__":
    """
    This script converts a pseudo-extended Cypher notation for DAGs into GSM
    """
    L = None
    if len(sys.argv) > 1:
        L = [FileStream(f) for f in sys.argv[1:]]
    else:
        L = [InputStream(sys.stdin.readline())]
    ls = []
    for input_stream in L:
        s = ""
        lexer = fastgraphLexer(input_stream)
        stream = antlr4.CommonTokenStream(lexer)
        parser = fastgraphParser(stream)
        e = parser.defn()
        d = {}
        edges = {}
        uid = uniqueId()
        edgesRef = {}
        for triplet in e.triplet():
            a = uid.setOrGet(triplet.src.text)
            b = uid.setOrGet(triplet.dst.text)
            c = triplet.edgeId.getText()
            if a not in d:
                d[a] = gsm_object(a)
            if b not in d:
                d[b] = gsm_object(b)
            if c not in edgesRef:
                edgesRef[c] = tuple([list(),dict(),list()])
            test = triplet.NUMBER()
            if test is None:
                test = 1.0
            else:
                test = float(test)
            edgesRef[c][2].append(tuple([a,b,test]))
        for node in e.node():
            id = uid.setOrGet(node.id_.text)
            if id not in d:
                d[id] = gsm_object(id)
            for label in  node.labels.EscapedString():
                d[id].addLabel(json.loads(label.getText()))
            for value in node.xi.EscapedString():
                d[id].addXi(json.loads(value.getText()))
            for (key,value) in zip(node.properties().EscapedString(),node.properties().value()):
                key = json.loads(key.getText())
                if isinstance(value, fastgraphParser.StringContext):
                    d[id].setProperty(key, json.loads(value.getText()))
                elif isinstance(value, fastgraphParser.FloatingContext):
                    d[id].setProperty(key, float(value.getText()))
                elif isinstance(value, fastgraphParser.IntegerContext):
                    d[id].setProperty(key, int(value.getText()))
        for edgeProps in e.edge():
            id = edgeProps.id_.getText()
            if id in edgesRef:
                for label in edgeProps.labels.EscapedString():
                    edgesRef[id][0].append(json.loads(label.getText()))
                for (key, value) in zip(edgeProps.properties().EscapedString(), edgeProps.properties().value()):
                    key = json.loads(key.getText())
                    if isinstance(value, fastgraphParser.StringContext):
                        edgesRef[id][1][key] = ( json.loads(value.getText()))
                    elif isinstance(value, fastgraphParser.FloatingContext):
                        edgesRef[id][1][key] = (float(value.getText()))
                    elif isinstance(value, fastgraphParser.IntegerContext):
                        edgesRef[id][1][key] = (int(value.getText()))
        for c in edgesRef:
                labels,props,src_targ = edgesRef[c]
                if len(labels) == 0:
                    labels = ['?']
                for label in labels:
                    for (parent,child,weight) in src_targ:
                        d[parent].setContainment(label, weight, child)
        for obj in d.values():
            x, uid = obj.to_string(None)
            s = s + x
        ls.append(s)
    print("~~\n".join(ls))


