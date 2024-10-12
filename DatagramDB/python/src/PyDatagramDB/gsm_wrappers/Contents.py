import pydatagramdb

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
        return GSMObject.gsm_object(self.odb_id, self._content.id, self.parent)

    def obj(self):
        return self._content


class Contents:
    def __init__(self, odb_id, id, parent):
        self._id = id
        self._odb_id = odb_id
        assert isinstance(parent, pydatagramdb.LinearGSM)
        self.parent = parent

    def _resolve_content(self, item):
        return [ContentWrapper(self._odb_id, x, self.parent) for x in self.parent.resolveContent(self._odb_id, self._id, str(item))]

    @property
    def keys(self):
        return self.parent.resolveContainmentLabels(self._odb_id, self._id)

    def __getitem__(self, item):
        return self._resolve_content(item)

    def items(self):
        for item in self.parent.resolveContainmentLabels(self._odb_id, self._id):
            yield (item, self._resolve_content(item))

    def __dict__(self):
        return {self._resolve_content(item) for item in self.parent.resolveContainmentLabels(self._odb_id, self._id)}

    def obj(self):
        return {item : self.parent.resolveContent(self._odb_id, self._id, str(item)) for item in self.parent.resolveContainmentLabels(self._odb_id, self._id)}