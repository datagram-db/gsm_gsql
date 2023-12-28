__author__ = "Giacomo Bergami"
__copyright__ = "Copyright 2023"
__credits__ = ["Giacomo Bergami"]
__license__ = "GPL"
__version__ = "3.0"
__maintainer__ = "Giacomo Bergami"
__email__ = "bergamigiacomo@gmail.com"
__status__ = "Production"
import sys

import yaml

from gsm.object import gsm_object
from gsm.utils import uniqueId

if __name__ == "__main__":
    """
    This script converts a YAML representation of a GSM model into a GSM representation
    for fast parsing
    """
    if len(sys.argv) > 1:
        data_loaded = None
        with open(sys.argv[1], 'r') as stream:
            data_loaded = yaml.safe_load(stream)
            ls = []
            for (dbname, db) in data_loaded.items():
                s = ""
                uid = uniqueId()
                for obj in db:
                    uid.setOrGet(obj["id"])
                for obj in db:
                    x, uid = gsm_object(obj).to_string(uid)
                    s = s + x
                ls.append(s)
            with open(sys.argv[1]+".gsm", "w") as w:
                w.write("~~\n".join(ls))
    else:
        print("This program works by taking as a first argument the name of the YAML file to be converted into GSM format")