grammar schema;

language: entity_declaration*;

type : String #t_string
     | UInt   #t_uint
     | Int   #t_int
     | Double   #t_double
     ;

entity_declaration: namespace=WORD  TYPE_SEP local_entity_declaration file;
local_entity_declaration: entity=WORD  LPAR (field COMMA)* field RPAR;

field : STAR? (TAG|PROPERTY)? SCORE? name=WORD (MAP map=EscapedString)? OFTYPE type                         #native_field
      | STAR? (TAG|PROPERTY)? name=WORD (MAP map=EscapedString)? EQ name_declar DOT ext_field_name=WORD    #external_reference
      | STAR? name=WORD (MAP map=EscapedString)? EQ LCOLL local_entity_declaration RCOLL   #local_nested_entity_list
      | STAR? name=WORD (MAP map=EscapedString)? EQ local_entity_declaration   #local_nested_entity
      | STAR? name=WORD (MAP map=EscapedString)? EQ MULTI  local_entity_declaration #multi_nested_entity
      ;



name_declar:        namespace=WORD TYPE_SEP entity=WORD;

file: FROM (csv|XML|JSON|LJSON) FILE OFTYPE EscapedString;

csv:  WITH_HEADER? CSV (SEP sep=EscapedString)?;

SCORE:'σ';
TAG:'𝜏';
PROPERTY:'π';
MULTI: '+';
FROM: 'FROM';
FILE: 'FILE';
CSV: 'CSV';
XML: 'XML';
JSON: 'JSON';
LJSON: 'LJSON';
WITH_HEADER: 'HEADER';
SEP: 'SEP';
String: 'String';
UInt: 'UInt';
Int: 'Int';
Double: 'Double';
LPAR : '(';
RPAR : ')';
LCOLL: '[';
RCOLL: ']';
COMMA: ',';
MAP: ':>';
COMMENT
    : '/*' .*? '*/' -> skip
;
DOT: '.';
EQ: '=';
TYPE_SEP: '::';
OFTYPE: ':';
STAR: '*';
LINE_COMMENT
    : '//' ~[\r\n]* -> skip
;
WS : [ \t\r\n]+ -> skip ;
EscapedString : '"' (~[\\"] | '\\' [\\"])* '"';
WORD:  [a-zA-Z$_]+ ;