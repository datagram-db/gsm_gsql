import pydatagramdb

class ObjectIterator:
    def __init__(self, reader, db_id, N):
        self.db_id = db_id
        self._reader = reader
        self.N = N
        self.idx = -1

    def __iter__(self):
        return self

    def __next__(self):  # Python 2: def next(self)
        self.idx += 1
        if self.idx < self.N:
            import PyDatagramDB.gsm_wrappers.GSMObject
            obj = PyDatagramDB.gsm_wrappers.GSMObject.GSMObject(self.db_id, self.idx, self._reader)
            if obj.obj is None:
                return None
            else:
                return obj
        raise StopIteration


class RandomAccessDatabase:

    def __init__(self, reader, db_id):
        self._reader = reader
        self._db_id = db_id

    def __len__(self):
        return self._reader.database_size(self._db_id) if self._reader is not None and self._db_id >= 0 else 0

    def __getitem__(self, item):
        return self._reader.retrieve(self._db_id, item) if self._reader is not None and item >=0 else None

    def __iter__(self):
        return ObjectIterator(self._reader, self._db_id, len(self))


class DatabaseIterator:
    def __init__(self, reader, N):
        self._reader = reader
        self.N = N
        self.idx = -1

    def __next__(self):  # Python 2: def next(self)
        self.idx += 1
        if self.idx < self.N:
            return RandomAccessDatabase(self._reader, self.idx)
        raise StopIteration

    def __iter__(self):
        return self



class RandomAccessReader:

    def __init__(self, reader):
        self._reader = reader

    @staticmethod
    def read_from_bulk(path:str):
        return RandomAccessReader(pydatagramdb.DataFormatHandler().read_from_bulk_data(path))

    @staticmethod
    def load_to_primary_memory(outPath: str, format: pydatagramdb.DataFormat):
        dfh = pydatagramdb.DataFormatHandler()
        dfh.load_to_primary_memory(outPath, format)
        return RandomAccessReader(dfh)

    def __iter__(self):
        return DatabaseIterator(self._reader, len(self))

    def __getitem__(self, key):
        return RandomAccessDatabase(self._reader, key) if key < len(self) else None

    def get_object(self, db, id):
        return self.get_object(db, id)

    def __len__(self):
        return self._reader.count_databases() if self._reader is not None else 0