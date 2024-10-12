from typing import Dict, Set

import pydatagramdb


class SimpleGSMDatabase:
    def __init__(self):
        self.map: Dict[int, pydatagramdb.gsm_object] = {}
        self.val: int = 0

    def copy(self) -> 'SimpleGSMDatabase':
        result = SimpleGSMDatabase()
        for val in self.map.values():
            result.put(val)
        return result

    def get(self, id: int) -> pydatagramdb.gsm_object:
        return self.map.get(id)

    def generate_object(self, id, ell, xi, scores, containment, properties) -> pydatagramdb.gsm_object:
        result = pydatagramdb.gsm_object(id, ell, xi, scores, containment, properties)
        self.put(result)
        self.val += 1
        return result

    def get_id_set(self) -> Set[int]:
        return set(self.map.keys())

    def put(self, obj: pydatagramdb.gsm_object) -> pydatagramdb.gsm_object:
        if obj.id in self.map:
            return None
        else:
            if obj.id > self.val:
                self.val = obj.id
            self.map[obj.id] = obj
            return obj

    def delete_object(self, to_integer: int) -> bool:
        return self.map.pop(to_integer, None) is not None

    def get_max_id(self) -> int:
        return self.val

