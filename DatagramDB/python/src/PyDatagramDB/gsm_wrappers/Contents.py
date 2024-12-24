import pydatagramdb

import PyDatagramDB.gsm.RandomAccessReader


class ContentWrapper:
    def __init__(self, odb_id, content, parent):
        self.odb_id = odb_id
        self._content = content
        self.parent = parent

    @property
    def contentId(self):
        return self._content.id

    @property
    def score(self):
        return self._content.score

    @property
    def content(self):
        from python.src.PyDatagramDB.gsm_wrappers import GSMObject
        return GSMObject.GSMObject(self.odb_id, self._content.id, self.parent)

    def as_tuple(self):
        return (self.score, self.content, self.properties)

    @property
    def properties(self):
        return self._content.property_values

    def obj(self):
        return self._content


class Contents:
    def __init__(self, odb_id, id, parent, obj):
        self._id = id
        self._odb_id = odb_id
        self.parent = parent
        self.obj = obj

    def _resolve_content(self, item):
        return [ContentWrapper(self._odb_id, x, self.parent) for x in self.obj.phi.get(str(item), [])]

    def empty(self):
        return len(self.obj.phi.keys()) == 0

    def keys(self):
        return self.obj.phi.keys()

    def __getitem__(self, item):
        return self._resolve_content(item)

    def items(self):
        for item in self.obj.phi:
            yield (item, self._resolve_content(item))

    def __dict__(self):
        return {self._resolve_content(item) for item in self.obj.phi}

    # def obj(self):
    #     return {item : self.parent.resolveContent(self._odb_id, self._id, str(item)) for item in self.parent.resolveContainmentLabels(self._odb_id, self._id)}