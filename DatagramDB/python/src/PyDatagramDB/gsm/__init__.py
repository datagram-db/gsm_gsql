from typing import Callable

import pydatagramdb

def data_converter(input_path: str,
                   input_format: pydatagramdb.DataFormat,
                   output_path: str,
                   output_format: pydatagramdb.DataFormat):
    pydatagramdb.DataFormatHandler().convert(input_path, input_format, output_path, output_format)


def callback_reader(input_path: str,
                   input_format: pydatagramdb.DataFormat,
                    callback):
    pydatagramdb.DataFormatHandler().callback_reader(input_path, input_format, callback)


def generate_object_containment(content, score=1.0, properties=None):
    assert isinstance(content, int)
    if properties is None:
        properties = dict()
    return pydatagramdb.gsm_object_xi_content(content, score, 0, properties)


def generate_object(id, ell=None, xi=None, scores=None, containment=None, properties=None) -> pydatagramdb.gsm_object:
    assert isinstance(id, int)
    if ell is None:
        ell = []
    assert isinstance(ell, list) and all(map(lambda x: isinstance(x, str), ell))
    if xi is None:
        xi = []
    assert isinstance(xi, list) and all(map(lambda x: isinstance(x, str), xi))
    if scores is None:
        scores = [1.0]
    assert isinstance(scores, list) and all(map(lambda x: isinstance(x, float), scores))
    if containment is None:
        containment = dict()
    if properties is None:
        properties = dict()
    return pydatagramdb.gsm_object(id, ell, xi, scores, containment, properties)
