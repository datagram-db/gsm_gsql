import pydatagramdb

import PyDatagramDB.gsm.RandomAccessReader


class GSMObject:
    def __init__(self, odb_id, id, parent):
        self._id = id
        self._odb_id = odb_id
        self.parent = parent
        self.obj = self.parent.retrieve(odb_id, id)

    @property
    def scores(self):
        return self.obj.scores

    @property
    def id(self):
        return self._id

    @property
    def db_id(self):
        return self._odb_id

    @property
    def ell(self):
        return self.obj.ell

    @property
    def xi(self):
        return self.obj.xi

    @property
    def properties(self):
        return self.obj.content

    @property
    def containment(self):
        from PyDatagramDB.gsm_wrappers.Contents import Contents
        return Contents(self._odb_id, self._id, self.parent, self.obj)

    # def obj(self):
    #     return pydatagramdb.gsm_object(self._id, self.ell, self.xi, self.scores, self.containment.obj(), self.properties().obj())