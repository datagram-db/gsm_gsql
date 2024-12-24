# import pydatagramdb
#
# import PyDatagramDB.gsm.RandomAccessReader
#
#
# class Properties:
#     def __init__(self, odb_id, id, parent, obj):
#         self._id = id
#         self._odb_id = odb_id
#         assert isinstance(parent, PyDatagramDB.gsm.RandomAccessReader.RandomAccessReader)
#         self.parent = parent
#         self.obj = obj
#
#     @property
#     def keys(self):
#         return self.parent.resolvePropertyLabels(self._odb_id, self._id)
#
#     def __getitem__(self, item):
#         return self.parent.resolveProperties(self._odb_id, self._id, str(item))
#
#     def items(self):
#         for item in self.parent.resolvePropertyLabels(self._odb_id, self._id):
#             yield (item, self.parent.resolveProperties(self._odb_id, self._id, str(item)))
#
#     def __dict__(self):
#         return {str(item): self.parent.resolveProperties(self._odb_id, self._id, str(item)) for item in self.parent.resolvePropertyLabels(self._odb_id, self._id)}
#
#     def obj(self):
#         return self.__dict__()