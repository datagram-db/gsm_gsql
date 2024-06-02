/*
 * fastgraph.g4
 * This file is part of gsm2_viz
 *
 * Copyright (C) 2023 - Giacomo Bergami
 *
 * gsm2_viz is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gsm2_viz is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gsm2_viz. If not, see <http://www.gnu.org/licenses/>.
 */


grammar fastgraph;

defn: (triplet | node | edge)*;

triplet: '('src=DIGIT')' '--['edgeId=roman (',' NUMBER)? ']->' '('dst=DIGIT')';

node: '('id=DIGIT ':' labels=stringlist
                  '=' xi=stringlist
                  properties ')';

edge: '['id=roman ':' labels=stringlist
                  properties ']';

stringlist: '[' (EscapedString ',')* EscapedString? ']';
properties: '{' (EscapedString ':' value ';')* (EscapedString ':' value)? '}';

value: EscapedString #string
     | NUMBER        #floating
     | INTEGER       #integer
     ;

     roman  : (oneThousand)* hundreds? tens? units?;

     // --- I, II, III, IV, IX or V VI, VII, VIII
     units : one ((one)* | five  | ten) | five (one)*;

     // --- X, XX, XXX, XL, XC or L, LX, LXX, LXXX
     tens  : ten ((ten)* | fifty | oneHundred) | fifty (ten)*;

     // --- C, CC, CCC, CD, CM or D, DC, DCC, DCCC
     hundreds : oneHundred ((oneHundred)* | fiveHundred | oneThousand) | fiveHundred (oneHundred)*;

     // --- atomic definitions
     one         : 'i';
     five        : 'v';
     ten         : 'x';
     fifty       : 'l';
     oneHundred  : 'c';
     fiveHundred : 'd';
     oneThousand : 'm';

EscapedString : '"' (~[\\"] | '\\' [\\"])* '"';
DIGIT : [0-9]+;
NUMBER : [+-]? DecimalFloatingConstant | [+-]? DIGIT;
INTEGER : [+-]? DIGIT;
COMMENT: '/*' .*? '*/' -> skip ;
LINE_COMMENT: '//' ~[\r\n]* -> skip;
WS : [ \t\r\n]+ -> skip ;
fragment
DecimalFloatingConstant
    :   [0-9]* '.' DIGIT
        |   DIGIT '.'

    |   DIGIT ExponentPart
    ;

fragment
FractionalConstant
    :   [0-9]* '.' DIGIT
    |   DIGIT '.'
    ;

fragment
ExponentPart
    :   [eE] [+-]? DIGIT
    ;
