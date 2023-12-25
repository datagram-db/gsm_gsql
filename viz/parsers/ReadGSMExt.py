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
