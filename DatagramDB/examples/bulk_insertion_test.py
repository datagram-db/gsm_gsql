import shutil

from pydatagramdb import DataFormat

import PyDatagramDB.gsm
from PyDatagramDB.gsm.RandomAccessReader import RandomAccessReader
from PyDatagramDB.gsm.gsm_read import gsm_read
from PyDatagramDB.gsm.gsm_write import gsm_write

if __name__ == "__main__":
    with gsm_write("writing_test_bulk", DataFormat.BulkFolder) as f:
        with f.start_new_db() as db:
            it = PyDatagramDB.gsm.generate_object(0, ["salutation"], ["ciao", "mondo"], properties={"language": "Italian", "code":1})
            en = PyDatagramDB.gsm.generate_object(1, ["salutation"], ["hello", "world"], properties={"language": "English", "code":2})
            main = PyDatagramDB.gsm.generate_object(2, ["salutation"], ["salutation"], containment={"instances": [PyDatagramDB.gsm.generate_object_containment(0), PyDatagramDB.gsm.generate_object_containment(1)]})
            db.write(it)
            db.write(en)
            db.write(main)
        with f.start_new_db() as db:
            en = PyDatagramDB.gsm.generate_object(0, ["closure"], ["goodbye"],
                                                  properties={"language": "English", "code": 2})
            main = PyDatagramDB.gsm.generate_object(1, ["closure"], ["arrivederci"], containment={
                "instances": [PyDatagramDB.gsm.generate_object_containment(0)]})
            db.write(en)
            db.write(main)

    rar = RandomAccessReader.read_from_bulk("writing_test_bulk")

    ## Example of a random access by object and database id
    print(rar[0][0].xi[0])

    ## Example of an iterator-style reading
    for db in rar:
        for object in db:
            print(object.xi)

    ## Removing the bulk insertion folder
    shutil.rmtree("writing_test_bulk")