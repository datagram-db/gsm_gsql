from pydatagramdb import DataFormat

import PyDatagramDB.gsm
from PyDatagramDB.gsm.RandomAccessReader import RandomAccessReader
from PyDatagramDB.gsm.gsm_read import gsm_read
from PyDatagramDB.gsm.gsm_write import gsm_write
from PyDatagramDB.hierarchy import  DataRepresentationHierarchy, HierarchyDegradation

if __name__ == "__main__":
    ## Serializing a file in the GSM format
    with gsm_write("/home/giacomo/writing_test.gsm.txt", DataFormat.GSM) as f:
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

    ## Loading the GSM as a primary memory database
    rar = RandomAccessReader.load_to_primary_memory("/home/giacomo/writing_test.gsm.txt", DataFormat.GSM)
    ## Example of an iterator-style reading
    for db in rar:
        for object in db:
            print(object.id)

    ## Example of a random access by object and database id
    print(rar[0][0].xi[0])
    # Reading directly from the previously serialized file
    for obj in  gsm_read("/home/giacomo/writing_test.gsm.txt", DataFormat.GSM):
        print(obj.xi[0])