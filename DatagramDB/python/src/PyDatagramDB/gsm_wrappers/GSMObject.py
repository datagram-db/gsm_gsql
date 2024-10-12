import pydatagramdb

class gsm_object:
    def __init__(self, odb_id, id, parent):
        self._id = id
        self._odb_id = odb_id
        assert isinstance(parent, pydatagramdb.LinearGSM)
        self.parent = parent

    @property
    def scores(self):
        return self.parent.objectScores[self._odb_id][self._id]

    @property
    def id(self):
        return self._id

    @property
    def db_id(self):
        return self._odb_id

    @property
    def ell(self):
        return self.parent.ell(self._odb_id, self._id)

    @property
    def xi(self):
        return self.parent.xi(self._odb_id, self._id)

    def properties(self):
        from PyDatagramDB.gsm_wrappers.Properties import Properties
        return Properties(self._odb_id, self._id, self.parent)

    @property
    def containment(self):
        from PyDatagramDB.gsm_wrappers.Contents import Contents
        return Contents(self._odb_id, self._id, self.parent)

    def obj(self):
        return pydatagramdb.gsm_object(self._id, self.ell, self.xi, self.scores, self.containment.obj(), self.properties().obj())