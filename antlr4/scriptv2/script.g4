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

script  : inner_block
     ;

expr_block : '{' inner_block '}';
inner_block: expr (';' inner_block)?;

in_tuple_pair :  EscapedString '↦' expr (',' in_tuple_pair)?;

//tuple_pair: EscapedString '>>' expr;

operand:       NUMBER                               #atom_number
              | BOOL                                 #atom_bool
              | EscapedString                        #atom_string
              | BOT                                  #null
              | STRINGT                                              #type_string
              | BOOLT                                                #type_bool
              | INTT                                                 #type_int
              | DOUBLET                                              #type_double
                   | ANYT                                                 #type_any
                   | VOID                                                 #type_bot
                   | '(' expr ')'                          #paren
                        | '|' expr '|'                          #abs
     | '⦃' expr '⦄'                       #var
     | '⦋' expr '⦌'                       #eval
          | '⟪' in_tuple_pair '⟫'           #type_tuple
               | '⌊' expr '⌋'                       #floor
               | '⌈' expr '⌉'                       #ceil
     | 'a' expr_block                     #atom_array
          | LABELT EscapedString               #type_label
     | START                                #kind
     | VARNAME                              #variable
               ;

term :operand               #term_operand
     | NOT operand                            #not
     | LISTT operand                                           #type_list
     |  SIN operand                           #sin
     |  COS operand                           #cos
     |  TAN operand                           #tan
          |  ELL operand                           #ell
          |  XI operand                           #xi
          |  INJ operand                           #inj
          |  OBJ operand                           #obj
          |  FLAT operand                          #flat
         |  SELFX operand                     #selfcross
         |  ZIP operand                     #selfzip
         |  VARPHI operand                        #varphi
         |  TYPEOF operand                        #typeof
     | ASSERT operand                        #ensure
;

cp : 'cp' term  term;

expr : term                                  #exprterm
     | '+' term  expr                         #add
     | '-' term  expr                         #sub
     | '÷' term  expr                         #div
     | '%' term  expr                        #mod
     | '·' term  expr                         #mult
     | '^' term  expr                       #concat
     | '@' term  expr                       #append
     | '∧' term   expr                        #and
     | '∨' term   expr                        #or
     | '=' term     expr                    #eq
     | '≠' term      expr                   #neq
     | '≤' term     expr                    #leq
     | '≥' term     expr                    #geq
     | '>' term      expr                    #gt
     | '<' term      expr                    #lt
     | '≝' term     expr                    #assign
     | '.' term  expr                #apply
     | '⇒' term  expr                        #imply
     | 'e' cp  expr     #ifte
     | 'ς' cp  expr  #substring
     | '[' term  expr ']'                    #at
     | '⟦' term  expr '⟧'                    #project
     | '⥆' cp  expr             #put
     | '∈' term  expr                       #contains
     | 'γ' term  expr            #remove
     | AND_TYPE term  expr                                   #type_and
     | OR_TYPE term  expr                                    #type_or
     |  ObjT term  expr                      #type_lex
     | ALPAREN in_tuple_pair  ARPAREN                     #atom_tuple
     | FUN VARNAME '→' expr_block      #function
     |  '°' term  expr              #map
     |  'σ' term  expr           #select
     | 'mod'  term  expr           #filter
     | 'r' cp  expr           #rfold
     | 'l' cp  expr           #lfold
     |  LOG term  expr                      #log
     |  POW term  expr                      #pow
     |  PHI term  expr                      #phi
     |  CROSS term  expr                   #cross
     | SIGMA  term  expr                       #sigma_type
     |SUBTYPE  term  expr             #subtype_of
     | ENFORCE term  expr                  #enforce
     | COERCE term  expr                #coerce
     ;

VOID: 'void';
BOT : '┴';
COERCE : 'coerce';
ObjT: 'ObjT';
TYPEOF: 'typeof';
SIGMA: '𝛴';
ASSERT: 'assert';
STRINGT: 'string';
LABELT: 'label';
DOUBLET: 'double';
ANYT: '┬';
BOOLT: 'bool';
INTT: 'int';
START: 'star';
KIND: 'kind';
LISTT: 'listof';
SUBTYPE: '⦑';
ALPAREN : '⎨';
ARPAREN : '⎬';
LPAREN : '{';
RPAREN : '}';
BOOL : 'tt'
     | 'ff'
     ;
AND_TYPE : '⋏';
OR_TYPE : '⋎';
FUN : 'fun';
NOT : '¬';
//REMOVE : 'remove';
//FROM : 'from';
LOG : 'log';
POW : 'pow';
SIN : 'sin';
COS : 'cos';
TAN : 'tan';
PHI : '𝜙';
ELL : 'ℓ';
XI : '𝜉';
INJ : 'inj';
OBJ : 'J';
FLAT : 'flat';
SELFX : 'selfx';
ZIP : 'zip';
VARPHI : '𝜑';
CROSS : '⨯';
VARNAME   : [a-z]+ ;
ENFORCE: 'enforce_subtype';
EscapedString : '"' (~[\\"] | '\\' [\\"])* '"';
NUMBER : [-]? DecimalFloatingConstant | [-]? DIGIT;
INTEGER : [-]? DIGIT;
SPACE : [ \t\r\n]+ -> skip;
COMMENT
    : '/*' .*? '*/' -> skip
;

LINE_COMMENT
    : '#' ~[\r\n]* -> skip
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
    :   [eE] [-]? DIGIT
    ;

fragment DIGIT : [0-9]+;