import xml
from abc import abstractmethod
from collections import defaultdict
from collections.abc import Iterable
import xml.etree.ElementTree as ET
# import gsm_stream_serialize
import pydatagramdb
import networkx
from pandas import DataFrame


# from utils.DesignPatterns.MyCallable import MyCallable

class MyCallable:

    @abstractmethod
    def call(self, *args, **kwargs) -> object:
        pass


# Notes: gsm_stream_serialize.gsm_object_xi_content refers to the creation of a containment relationship
#        gsm_stream_serialize.gsm_object            refers to the creation of a GSM object

def fullname(o):
    klass = o.__class__
    module = klass.__module__
    if module == 'builtins':
        return klass.__qualname__  # avoid outputs like 'builtins.str'
    return module + '.' + klass.__qualname__


primitives = (bool, str, int, float, type(None))


def is_primitive(obj):
    return type(obj) in primitives


import itertools










class GSMSimpleSerializer:

    def __init__(self):
        self._cont = itertools.count()

    def next_id(self):
        return next(self._cont)

    def skipFor(self, i):
        for x in range(i):
            next(self._cont)

    def gsm_conversion(self, obj, id=None, ff="record", scoring=None, acc=None, label="label"):
        if is_primitive(obj):
            return self.basic_object(obj, id, scoring, acc)
        elif isinstance(obj, ET.Element):
            return self.xml_to_gsm(obj, id, scoring, acc)
        elif isinstance(obj, networkx.classes.multidigraph.MultiDiGraph) or \
                isinstance(obj, networkx.classes.digraph.DiGraph) or \
                isinstance(obj, networkx.classes.graph.Graph) or \
                isinstance(obj, networkx.classes.multidigraph.MultiGraph):
            return self.graph_to_gsm(obj, id, scoring, acc, label)
        elif isinstance(obj, DataFrame):
            return self.list_to_gsm(obj.to_dict('records'), id, ff, scoring, acc)
        elif isinstance(obj, dict):
            return self.dict_to_gsm(obj, id, ff, scoring, acc)
        elif isinstance(obj, list) or isinstance(obj, tuple):
            return self.list_to_gsm(obj, id, ff)
        else:
            if obj is not None and hasattr(obj, '__dict__'):
                return self.dict_to_gsm(vars(obj), id, fullname(obj), scoring, acc)
            else:
                return self.object_to_gsm(obj, id, scoring, acc)

    def graph_to_gsm(self, G, id=None, scoring=None, acc=None, label="label"):
        if isinstance(G, networkx.classes.digraph.DiGraph) or \
                isinstance(G, networkx.classes.graph.Graph) or \
                isinstance(G, networkx.classes.multidigraph.MultiGraph):
            G = networkx.MultiDiGraph(G)
        if acc is None:
            acc = []
        if id is None:
            id = self.next_id()
        if G is not None:
            ell = [fullname(G)]
        else:
            ell = []
        xi = []
        if scoring is not None:
            scores = scoring(G)
        else:
            scores = [1.0]
        content = defaultdict(list)
        pi = defaultdict(list)
        mapp = dict()
        if G is not None:
            for node_id, node_data in G.nodes(data=True):
                xid = self.dict_to_gsm(node_data, None, str(node_id), scoring, acc).id
                mapp[node_id] = xid
                if scoring is not None:
                    xscore = scoring(node_data)
                else:
                    xscore = 1.0
                orig_id = id
                containment = pydatagramdb.gsm_object_xi_content(xid, xscore, orig_id, dict())
                content["nodes"].append(containment)
            for source, target, pi in G.edges(data=True):
                edge_id = self.next_id()
                if label is not None and label in pi:
                    edge_ell = [pi[label]]
                else:
                    edge_ell = ["__label"]
                edge_xi = []
                edge_content = {
                    "src": [pydatagramdb.gsm_object_xi_content(mapp[source], 1.0, edge_id, dict())],
                    "dst": [pydatagramdb.gsm_object_xi_content(mapp[target], 1.0, edge_id, dict())]}
                if scoring is not None:
                    xscore = scoring(pi)
                else:
                    xscore = 1.0
                obj = pydatagramdb.gsm_object(edge_id, edge_ell, edge_xi, [xscore], edge_content, pi)
                acc.append(obj)
                containment = pydatagramdb.gsm_object_xi_content(edge_id, xscore, id, dict())
                content["edge"].append(containment)
        obj = self.finalizeGeneration(acc, content, ell, id, pi, scores, xi)
        return obj

    def xml_to_gsm(self, root, id=None, scoring=None, acc=None):
        assert isinstance(root, ET.Element)
        if acc is None:
            acc = []
        if id is None:
            id = self.next_id()
        if root is None:
            ell = []
        else:
            ell = [root.tag]
        if scoring is not None:
            scores = scoring(root)
        else:
            scores = [1.0]
        if root.text is not None:
            xi = [root.text.strip()]
        else:
            xi = []
        pi = root.attrib
        content = defaultdict(list)
        for child in root:
            self.extractContent(acc, content, child.tag, id, scoring, child)
        obj = pydatagramdb.gsm_object(id, ell, xi, scores, dict(content), pi)
        acc.append(obj)
        return obj

    def dict_to_gsm(self, d, id=None, fullname="record", scoring=None, acc=None):
        if acc is None:
            acc = []
        if id is None:
            id = self.next_id()
        ell = [fullname]
        xi = []
        if scoring is not None:
            scores = scoring(d)
        else:
            scores = [1.0]
        content = defaultdict(list)
        pi = defaultdict(list)
        if d is not None:
            assert isinstance(d, dict)
            for k, v in d.items():
                self.extractField_global(acc, content, k, v, id, pi, scoring)
        obj = self.finalizeGeneration(acc, content, ell, id, pi, scores, xi)
        return obj

    def list_to_gsm(self, ls, id=None, fullname="list", scoring=None, acc=None, fieldname="arg"):
        if acc is None:
            acc = []
        if id is None:
            id = self.next_id()
        ell = [fullname]
        xi = []
        if scoring is not None:
            scores = scoring(ls)
        else:
            scores = [1.0]
        content = defaultdict(list)
        pi = defaultdict(list)
        if ls is not None:
            allInXi = all(map(lambda x: (x is not None) and (isinstance(x, str) or
                                                             isinstance(x, float) or
                                                             isinstance(x, int) or
                                                             isinstance(x, bool)), ls))

            if allInXi:
                for fromField in ls:
                    if fromField is not None:
                        xi.append(fromField)
            else:
                for fromField in ls:
                    if fromField is not None:
                        self.extractContent(acc, content, fieldname, id, scoring, fromField)
        obj = self.finalizeGeneration(acc, content, ell, id, pi, scores, xi)
        return obj

    def finalizeGeneration(self, acc, content, ell, id, pi, scores, xi):
        p2 = dict()
        for k, v in pi.items():
            if isinstance(v, str):
                p2[k] = v
            elif len(v) == 1:
                p2[k] = v[0]
            elif len(v) > 1:
                p2[k] = "[" + ", ".join(map(str, v)) + "]"
        obj = pydatagramdb.gsm_object(id, ell, xi, scores, dict(content), p2)
        acc.append(obj)
        return obj

    def basic_object(self, obj, id=None, scoring=None, acc=None):
        if acc is None:
            acc = []
        if id is None:
            id = self.next_id()
        if obj is None:
            ell = [fullname(obj)]
        else:
            ell = []
        xi = [str(obj)]
        if scoring is not None:
            scores = scoring(obj)
        else:
            scores = [1.0]
        obj = self.finalizeGeneration(acc, defaultdict(list), ell, id, defaultdict(list), scores, xi)
        return obj

    def object_to_gsm(self, obj, id=None, scoring=None, acc=None):
        if obj is not None and hasattr(obj, '__dict__'):
            return self.dict_to_gsm(vars(obj), id, fullname(obj), scoring, acc)
        if acc is None:
            acc = []
        if id is None:
            id = self.next_id()
        if obj is None:
            ell = [fullname(obj)]
        else:
            ell = []
        xi = []
        if scoring is not None:
            scores = scoring(obj)
        else:
            scores = [1.0]
        content = defaultdict(list)
        pi = defaultdict(list)
        if obj is not None:
            fields = [f for f in dir(obj) if not callable(getattr(obj, f)) and not f.startswith('__')]
            for field in fields:
                fieldName = field
                fromField = getattr(obj, fieldName)
                self.extractField_global(acc, content, fieldName, fromField, id, pi, scoring)
        obj = self.finalizeGeneration(acc, content, ell, id, pi, scores, xi)
        return obj

    def extractField_global(self, acc, content, fieldName, fromField, id, pi, scoring):
        if fromField is not None:
            if isinstance(fromField, str) or isinstance(fromField, float) or isinstance(fromField, int) or isinstance(
                    fromField, bool):
                pi[fieldName].append(fromField)
            elif isinstance(fromField, Iterable):
                for x in fromField:
                    self.extractBasicField(acc, content, fieldName, id, pi, scoring, x)
            else:
                self.extractBasicField(acc, content, fieldName, id, pi, scoring, fromField)

    def extractBasicField(self, acc, content, fieldName, id, pi, scoring, x):
        if x is not None:
            if isinstance(x, str) or isinstance(x, float) or isinstance(x, int) or isinstance(x, bool):
                pi[x].append(x)
            else:
                self.extractContent(acc, content, fieldName, id, scoring, x)

    def extractContent(self, acc, content, fieldName, id, scoring, x):
        xid = self.gsm_conversion(x, None, ff="record", scoring=scoring, acc=acc).id
        # xid = self.object_to_gsm(x, None, scoring, acc).id
        if scoring is not None:
            xscore = scoring(x)
        else:
            xscore = 1.0
        orig_id = id
        containment = pydatagramdb.gsm_object_xi_content(xid, xscore, orig_id, dict())
        content[fieldName].append(containment)


class GSMSerializer:

    def __init__(self, ff="record", scoring=None, label="label"):
        super(GSMSerializer, self).__init__()
        self.ff = ff
        self.scoring = scoring
        self.label = label
    #
    # def skipFor(self, i):
    #     self.parent.skipFor(i)

    def generateObjectDatabase(self, obj) -> object:
        acc = []
        res = GSMSimpleSerializer().gsm_conversion(obj, None, self.ff, self.scoring, acc, self.label)
        acc.sort(key=lambda x : x.id)
        if res is not None:
            res = res.id
        return acc, res

def pytype_to_gsms(anytpe):
    if anytpe is float:
        return pydatagramdb.AttributeTableType.DoubleAtt
    elif anytpe is bool:
        return pydatagramdb.AttributeTableType.BoolAtt
    elif anytpe is int:
        return pydatagramdb.AttributeTableType.LongAtt
    else:
        return pydatagramdb.AttributeTableType.StringAtt


