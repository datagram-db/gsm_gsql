from typing import List

import pydatagramdb


class MainMemoryDBBuilder:
    def __init__(self):
        self.db = pydatagramdb.LinearGSM()
        from python.src.PyDatagramDB.Transformation import GSMSerializer
        self.serializer = GSMSerializer()
        self.dblist = []
        self.init = False

    def toObjectDatabase(self, o : object) -> List[pydatagramdb.gsm_object]:
        if not self.init:
            acc, res = self.serializer.generateObjectDatabase(o)
            assert res == 0
            self.dblist.append(acc)


    def initializeWithLoadedDatabases(self, schema=None):
        if not self.init:
            if schema is None:
                schema = {}
            self.db.load_databases(self.dblist, schema)
            self.init =True
            self.dblist = [len(x) for x in self.dblist]

    def __len__(self):
        return len(self.dblist) if self.init else 0


    def getDBSize(self, dbId):
        return len(self.dblist[dbId]) if len(self.dblist[dbId])>dbId else 0

    def getObjectFromDb(self, dbId, objId):
        if len(self.dblist)<=dbId:
            return None
        if self.dblist[dbId]<=objId:
            return None
        from PyDatagramDB.gsm_wrappers.GSMObject import GSMObject
        return GSMObject(dbId, objId, self.db)

