from dataclasses import dataclass
from typing import List, Dict, Union, Tuple

import PyDatagramDB.gsm_wrappers.GSMObject


@dataclass
class BL:
    id: int
    types: List[str]
    values: List[str]
    scores: List[float]

    def degradate(self, f):
        if len(self.values)<=1:
            yield self
        else:
            for x in self.values:
                yield BL(self.id, self.types, [x], self.scores)


@dataclass
class AV:
    id: int
    types: List[str]
    properties: Dict[str, Union[str, float]]
    scores: List[float]

    def degradate(self, f):
        for key, value in self.properties.items():
            yield BL(self.id, ["BL"]+[x for x in self.types if x != 'AV'], [f"{key}={value}"], self.scores)

@dataclass
class MI:
    id: int
    types: List[str]
    properties: Dict[str, Union[str, float]]
    containments: Dict[str, List[Tuple[float, object]]]
    scores: List[float]

    def degradate(self, f):
        d = {k:v for k,v in self.properties.items()}
        for c, v in self.containments.items():
            d[c+"_"] = str(v)
        yield AV(self.id, self.types, d, self.scores)



@dataclass
class RL:
    id: int
    types: List[str]
    values: List[str]
    properties: Dict[str, Union[str, float]]
    containments: Dict[str, List[Tuple[float, object, dict]]]
    scores: List[float]

    @staticmethod
    def _record_determination(self, f):
        if len(self[2]) == 0:
            for x in f(self[1]):
                yield (self[0], x)
        else:
            return (1.0, MI(self[0], ["MI", "content"], self[2], {"content": [(self[0], x) for x in f(self[1])]}, [self[0]]))

    def degradate(self, f):
        if len(self.containments) == 0:
            if len(self.values) == 0:
                yield AV(self.id, self.types, self.properties, self.scores)
            else:
                d = {k: v for k, v in self.properties.items()}
                d["(values)"] = "[" + (", ".join(map(str, self.values))) + "]"
                yield MI(self.id, self.types, d, {}, self.scores)
        else:
            yield MI(self.id, self.types, self.properties, {k:[y for x in v for y in RL._record_determination(x, f) ] for k, v in self.containments.items()}, self.scores)

class DataRepresentationHierarchy:
    def __init__(self):
        self.d = dict()

    def to_hierarchy_value(self, object: PyDatagramDB.gsm_wrappers.GSMObject.GSMObject):
        if object.id not in self.d:
            if object.containment.empty():
                if len(object.properties) == 0:
                    self.d[object.id] = BL(object.id, object.ell, object.xi, object.scores)
                elif len(object.xi) == 0:
                    self.d[object.id] = AV(object.id, object.ell, object.properties, object.scores)
                else:
                    self.d[object.id] = RL(object.id, object.ell, object.xi, object.properties, {}, object.scores)
            else:
                from collections import defaultdict
                containments = defaultdict(list)
                for k, v in dict(object.containment).items():
                    for x in v:
                        score, obj, dic = x.as_tuple()
                        obj = self.to_hierarchy_value(obj)
                        containments[k].append((score, obj, dic))
                self.d[object.id] = RL(object.id, object.ell, object.xi, object.properties, dict(containments), object.scores)
        return self.d[object.id]

class HierarchyDegradation:
    def __init__(self, to):
        self.to = to
        self.d = dict()

    def degradate(self, obj):
        if obj.id not in self.d:
            if (type(obj).__name__ == "BL") or (type(obj).__name__ == "AV"):
                yield from obj.degradate(lambda x: self.degradate(x))
            elif (type(obj).__name__ == "MI"):
                if (self.to == "MI") or (self.to == "RL"):
                    yield obj
                elif (self.to == "AV"):
                    yield from obj.degradate(lambda x: self.degradate(x))
                elif (self.to == "BL"):
                    for x in obj.degradate(lambda x: self.degradate(x)):
                        yield from self.degradate(x)
            elif (type(obj).__name__ == "RL"):
                if (self.to == "RL"):
                    yield obj
                elif (self.to == "MI"):
                    yield from obj.degradate(lambda x: self.degradate(x))
                else:
                    for x in obj.degradate(lambda x: self.degradate(x)):
                        yield from self.degradate(x)
            else:
                yield obj



