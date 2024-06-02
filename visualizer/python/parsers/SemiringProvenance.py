__author__ = "Giacomo Bergami"
__copyright__ = "Copyright 2023"
__credits__ = ["Giacomo Bergami"]
__license__ = "GPL"
__version__ = "3.0"
__maintainer__ = "Giacomo Bergami"
__email__ = "bergamigiacomo@gmail.com"
__status__ = "Production"

from typing import Any, Dict, List, Optional, Literal

from pydantic import BaseModel, Extra, Field


class ProvenanceExpression(BaseModel):
    pass


class ProvenanceObject(ProvenanceExpression):
    type: Literal['ProvObject'] = 'ProvObject'
    object: int = Field(description='id associated to the object')



class ProvenanceContainment(ProvenanceExpression):
    type: Literal['ProvPhi'] = 'ProvPhi'
    parent: int = Field(description='id associated to the parent')
    label:str = Field(description='label bridging the two')
    child: int = Field(description='id associated to the child')
    id:int = Field(description='the number of the edge with the same label connecting the two nodes')




class ProvenanceSum(ProvenanceExpression):
    type: Literal['ProvSum'] = 'ProvSum'
    sum_operands: List[ProvenanceExpression] = Field(description='Elements being in an alternative')



class ProvenanceProd(ProvenanceExpression):
    type: Literal['ProvProd'] = 'ProvProd'
    prod_operands: List[ProvenanceExpression] = Field(description='Elements being in a composition')


def to_viz_provenance_string(o:ProvenanceExpression):
    if isinstance(o, ProvenanceObject):
        return str(o.object)
    elif isinstance(o, ProvenanceContainment):
        return "("+str(o.parent)+","+str(o.label)+","+str(o.child)+","+str(o.id)+")"
    elif isinstance(o, ProvenanceSum):
        return "("+(" + ".join(map(lambda x: to_viz_provenance_string(x), o.sum_operands)))+")"
    elif isinstance(o, ProvenanceProd):
        return "("+(" * ".join(map(lambda x: to_viz_provenance_string(x), o.prod_operands)))+")"

def provenance_object(id):
    return ProvenanceObject(object=id)
def provenance_containment(parent:int,label:str,child:int,id:int):
    return ProvenanceContainment(parent=parent,label=label,child=child,id=id)
def sum_p(obj):
    return ProvenanceSum(sum_operand=obj)
def prod_p(obj):
    return ProvenanceProd(prod_operands=obj)
