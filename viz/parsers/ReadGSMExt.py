__author__ = "Giacomo Bergami"
__copyright__ = "Copyright 2023"
__credits__ = ["Giacomo Bergami"]
__license__ = "GPL"
__version__ = "3.0"
__maintainer__ = "Giacomo Bergami"
__email__ = "bergamigiacomo@gmail.com"
__status__ = "Production"

import json
from typing import List

from parsers.GSMExt import GsmSpecification

def serialize_gsm_model(lista:List[GsmSpecification],indent=4):
    return json.dumps(list(map(lambda d1: d1.model_dump(), lista)), indent=indent)

def deserialize_gsm_file(filename:str):
    with open(filename,"r") as f:
        return [GsmSpecification.model_validate(d_) for d_ in json.load(f)]

def deserialize_gsm_model(s:str):
    return [GsmSpecification.model_validate(d_) for d_ in json.loads(s)]
