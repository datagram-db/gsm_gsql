/*
 First and earliest version of the language as it appeared in the original
 dissertation: https://bitbucket.org/unibogb/gsql-script/
 
 To be stated with a more specific and sound language.
 */

grammar script;
//gsm_gsql: directives*;
//
//directives : '#script' EscapedString        #script_from_file
//           |  SCRIPT LPAREN script RPAREN   #script_from_data
//           |  CREATEDB EscapedString        #create_db_with_name
//           |  GSQL LPAREN gsql RPAREN       #actual_gsql
//           ;
//
//gsql : (gexpr '!')* gexpr;
//
//gexpr : '<' gexpr '>'                                                     #gparen
//      | CREATE dbview (ell=expr (xi=expr? (scores=expr (phi=expr)?)?)?)?  #g_create
//      | ELECT dbview expr                                                 #g_direct_elect
//      | ELECT dbview EscapedString INTEGER                                #g_zerocontainment_elect
//      | MAP   dbview expr expr expr                                       #g_map
//      | DISJOINT dbview+                                                  #g_disjoint
//      | VARNAME ':=' gexpr                                                #set_variable
//      | FOLD expr dbview ':' FUN VAR VAR '->>' gexpr                      #g_fold
//      ;
//
//dbview : EscapedString INTEGER                #direct_view
//       | EscapedString EscapedString INTEGER? #contaiment_from_zero_view
//       | gexpr                                #subexpr
//       ;

script  : (expr ';')* expr
     ;

tuple_pair: EscapedString '>>' expr;

expr : '(' expr ')'                          #paren
     | expr '+' expr                         #add
     | expr '-' expr                        #sub
     | expr '/' expr                        #div
     | expr '%' expr                        #mod
     | expr '*' expr                        #mult
     | expr '++' expr                       #concat
     | expr '@' expr                       #append
     | expr '&&' expr                        #and
     | expr '||' expr                        #or
     | '|' expr '|'                          #abs
     | expr '=='    expr                    #eq
     | expr '!='    expr                    #neq
     | expr '<='    expr                    #leq
     | expr '>='    expr                    #geq
     | expr '>'     expr                    #gt
     | expr '<'     expr                    #lt
     | expr ':='    expr                    #assign
     | '(' expr  expr ')'                #apply
     | 'var(' expr ')'                       #var
     | 'eval(' expr ')'                       #eval
     | NOT expr                            #not
     | expr '=>' expr                        #imply
     | IF expr THEN expr ELSE expr     #ifte
     | 'sub(' expr ',' expr ':' expr ')' #substring
     | expr '[' expr ']'                    #at
     | expr '[[' expr ']]'                    #project
     | expr '[' expr ']:=' expr             #put
     | expr 'in' expr                       #contains
     | REMOVE expr FROM expr            #remove
     | NUMBER                               #atom_number
     | BOOL                                 #atom_bool
     | EscapedString                        #atom_string
     | BOT                                  #null
     | STRINGT                                              #type_string
     | BOOLT                                                #type_bool
     | INTT                                                 #type_int
     | DOUBLET                                              #type_double
     | expr AND_TYPE expr                                   #type_and
     | expr OR_TYPE expr                                    #type_or
     | LISTT expr                                           #type_list
     | 't<'  (tuple_pair ';')* tuple_pair ARPAREN           #type_tuple
     | ANYT                                                 #type_any
     | VOID                                                 #type_bot
     | LABELT EscapedString               #type_label
     | ObjT expr expr                     #type_lex
     | LPAREN (expr ';')* expr RPAREN                     #atom_array
     | START                                #kind
     | ALPAREN (tuple_pair ';')* tuple_pair ARPAREN                     #atom_tuple
     | FUN VARNAME '->' LPAREN (expr ';')* expr RPAREN    #function
     | VARNAME                              #variable
     | 'map(' expr ':' expr ')'             #map
     | 'select(' expr ':' expr ')'          #select
     | 'filter(' expr ':' expr ')'          #filter
     | 'rfold(' expr ',' expr ':' expr ')'          #rfold
     | 'lfold(' expr ',' expr ':' expr ')'          #lfold
     | LOG expr expr                      #log
     | POW expr expr                      #pow
     | SIN expr                           #sin
     | COS expr                           #cos
     | TAN expr                           #tan
     | '|_' expr '_|'                       #floor
     | '|-' expr '-|'                       #ceil
     | PHI expr expr                      #phi
     | ELL expr                           #ell
     | XI  expr                           #xi
     | INJ expr                           #inj
     | OBJ expr                           #obj
     | FLAT expr                          #flat
     | CROSS expr expr                    #cross
     | SELFX expr                     #selfcross
     | VARPHI expr                        #varphi
     | TYPEOF expr                        #typeof
     | SIGMA expr 'where' expr                       #sigma_type
     | expr SUBTYPE expr            #subtype_of
     | ASSERT expr                        #ensure
     | expr ENFORCE expr                  #enforce
     | COERCE expr 'as' expr                #coerce
     ;

VOID: 'void';
BOT : 'null'|'┴';
COERCE : 'coerce';
ObjT: 'ObjT';
TYPEOF: 'typeof';
SIGMA: 'sigma';
ASSERT: 'assert';
STRINGT: 'string';
LABELT: 'label';
DOUBLET: 'double';
ANYT: 'any'|'┬';
BOOLT: 'bool';
INTT: 'int';
START: 'star';
KIND: 'kind';
LISTT: 'listof';
SUBTYPE: '<:';
ALPAREN : '<';
ARPAREN : '>';
LPAREN : '{';
RPAREN : '}';
BOOL : 'tt'
     | 'ff'
     ;
AND_TYPE : '/\\';
OR_TYPE : '\\/';
FUN : 'fun';
NOT : 'not';
IF : 'if';
THEN : 'then';
ELSE : 'else';
REMOVE : 'remove';
FROM : 'from';
LOG : 'log';
POW : 'pow';
SIN : 'sin';
COS : 'cos';
TAN : 'tan';
PHI : 'phi';
ELL : 'ell';
XI : 'xi';
INJ : 'inj';
OBJ : 'OBJ';
FLAT : 'flat';
SELFX : 'selfx';
VARPHI : 'varphi';
CROSS : 'cross';
SCRIPT : 'script';
GSQL : 'gsql';
CREATEDB : 'CREATEDB';
VARNAME   : [a-z]+ ;
CREATE : 'CREATE';
ELECT : 'ELECT';
MAP : 'MAP';
DISJOINT : 'DISJOINT';
FOLD : 'FOLD';
ENFORCE: 'enforce_subtype';
EscapedString : '"' (~[\\"] | '\\' [\\"])* '"';
NUMBER : DecimalFloatingConstant | DIGIT;
INTEGER : DIGIT;
SPACE : [ \t\r\n]+ -> skip;
COMMENT
    : '/*' .*? '*/' -> skip
;

LINE_COMMENT
    : '//' ~[\r\n]* -> skip
;

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

fragment DIGIT : [0-9]+;