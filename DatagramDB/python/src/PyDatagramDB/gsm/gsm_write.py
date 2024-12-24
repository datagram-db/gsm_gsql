from dataclasses import dataclass
from pydatagramdb import DataFormatHandler, DataFormat

import PyDatagramDB.gsm
from PyDatagramDB.gsm.gsm_read import gsm_read


class gsm_new_db:
    def __init__(self, writer: DataFormatHandler):
        self._writer = writer

    def __enter__(self):
        self._writer.newDB()
        return self

    def write(self, obj):
        """
        Writing a GSM object to the desired writing format
        """
        assert type(obj).__name__ == 'gsm_object'
        self._writer.writeObject(obj)

    def __exit__(self, exc_type, exc_val, exc_tb):
        pass

class gsm_write:
    def __init__(self, outPath: str, format: DataFormat):
        """
        :param outPath: Where to serialize the content
        :param format:  Format of the serialization
        """
        self.format = format
        self.outPath = outPath
        self._writer = DataFormatHandler()

    def __enter__(self):
        self._writer.open_data_writer(self.outPath, self.format)
        return self

    def start_new_db(self):
        """
        As this serialization goes by db, this introduces the usage of a new DB instance
        """
        return gsm_new_db(self._writer)

    def __exit__(self, exc_type, exc_val, exc_tb):
        self._writer.close_writer()


if __name__ == "__main__":
    with gsm_write("/home/giacomo/writing_test.gsm.txt", DataFormat.GSM) as f:
        with f.start_new_db() as db:
            it = PyDatagramDB.gsm.generate_object(0, ["salutation"], ["ciao", "mondo"], properties={"language": "Italian", "code":1})
            en = PyDatagramDB.gsm.generate_object(1, ["salutation"], ["hello", "world"], properties={"language": "English", "code":2})
            main = PyDatagramDB.gsm.generate_object(2, ["salutation"], ["salutation"], containment={"instances": [PyDatagramDB.gsm.generate_object_containment(0), PyDatagramDB.gsm.generate_object_containment(1)]})
            db.write(it)
            db.write(en)
            db.write(main)
    for obj in  gsm_read("/home/giacomo/writing_test.gsm.txt", DataFormat.GSM):
        print(obj.xi[0])