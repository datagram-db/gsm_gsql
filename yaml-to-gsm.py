__author__ = "Giacomo Bergami"
__copyright__ = "Copyright 2023"
__credits__ = ["Giacomo Bergami"]
__license__ = "GPL"
__version__ = "3.0"
__maintainer__ = "Giacomo Bergami"
__email__ = "bergamigiacomo@gmail.com"
__status__ = "Production"
import json
import sys

import yaml

class uniqueId:
    def __init__(self):
        self.int = dict()
        self.n = 0

    def setOrGet(self, x):
        if x in self.int:
            return self.int[x]
        else:
            self.int[x] = self.n
            self.n = self.n +1
            return self.n -1

class gsm_object():
    def __init__(this, obj):
        assert isinstance(obj, dict)
        assert "id" in obj
        this.id = int(obj["id"])
        this.ell = []
        if "ell" in obj:
            for x in obj["ell"]:
                this.ell.append(str(x))
        this.xi = []
        if "xi" in obj:
            for x in obj["xi"]:
                this.xi.append(str(x))
        this.properties = dict()
        if "properties" in obj:
            assert isinstance(obj["properties"], dict)
            for (k,v) in obj["properties"].items():
                this.properties[str(k)] = str(v)
        this.containment = dict()
        if "containment" in obj:
            assert isinstance(obj["containment"], dict)
            for (k,ls) in obj["containment"].items():
                L = []
                for x in ls:
                    if isinstance(x, tuple) or isinstance(x, list):
                        n = len(x)
                        if n>0:
                            if (n==1):
                                L.append(tuple([1.0,int(x[0])]))
                            elif (n>=2):
                                L.append(tuple([float(x[0]), int(x[1])]))
                this.containment[k] = L

    def addLabel(this,x):
        this.ell.append(x)

    def addXi(this, x):
        this.xi.append(x)

    def setProperty(this, k, v):
        this.properties[k] = v

    def setContainment(this, c, w, cont):
        if c not in this.containment:
            this.containment[c] = list()
        this.containment[c].append(tuple([w,cont]))

    def to_string(object, conv: uniqueId):
        b = ""
        b = b + "id:" + str(conv.setOrGet(object.id)) + "\n"
        b = b + "ell:\n"
        for x in object.ell:
            b = b + x.replace(".","<dot>") + "\n"
        b = b + ".\n"
        b = b + "xi:\n"
        for x in object.xi:
            b = b + x.replace(".","<dot>") + "\n"
        b = b + ".\n"
        b = b + "properties:\n"
        for (k,v) in object.properties.items():
            b = b+json.dumps(k)+"\t"+json.dumps(v)+"\n"
        b = b + ".\n"
        b = b + "phi:\n"
        for (c,p) in object.containment.items():
            b = b + json.dumps(c)+"\n"
            for (w,cont) in object.containment[c]:
                b = b + "\t"+str(w)+"\t"+str(cont)+"\n"
            b = b + ";"
        return b + ".\n\n", conv

if __name__ == "__main__":
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
