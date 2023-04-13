/*
 First and earliest version of the language as it appeared in the original
 dissertation: https://bitbucket.org/unibogb/gsql-script/
 
 To be stated with a more specific and sound language.
 */

grammar script;

script  : (expr ';')* expr
     ;

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
     | expr '.'     expr                    #invoke
     | 'eval(' expr ')'                      #eval
     | '(' expr  expr ')'                #apply
     | 'var(' expr ')'                       #var
     | 'not' expr                            #not
     | expr '=>' expr                        #imply
     | 'if' expr 'then' expr 'else' expr     #ifte
     | 'sub(' expr ',' expr ':' expr ')' #substring
     | expr '[' expr ']'                    #at
     | expr '[' expr ']:=' expr             #put
     | expr 'in' expr                       #contains
     | 'remove' expr 'from' expr            #remove
     | EscapedString                        #atom_string
     | BOOL                                 #atom_bool
     | NUMBER                               #atom_number
     | '{' (expr ',')* expr '}'             #atom_array
     | VARNAME '->' '{' (expr ';')* expr '}'    #function
     | VARNAME                              #variable
     | 'map(' expr ':' expr ')'             #map
     | 'select(' expr ':' expr ')'          #select
     | 'filter(' expr ':' expr ')'          #filter
     | 'rfold(' expr ',' expr ':' expr ')'          #rfold
     | 'lfold(' expr ',' expr ':' expr ')'          #lfold
     | 'log' expr expr                      #log
     | 'pow' expr expr                      #pow
     | 'sin' expr                           #sin
     | 'cos' expr                           #cos
     | 'tan' expr                           #tan
     | '|_' expr '_|'                       #floor
     | '|-' expr '-|'                       #ceil
     | 'phi' expr expr                      #phi
     | 'ell' expr                           #ell
     | 'xi'  expr                           #xi
     | 'inj' expr                           #inj
     | 'flat' expr                          #flat
     | expr 'x' expr                    #cross
     | 'selfx' expr                     #selfcross
     | 'varphi' expr                        #varphi
     ;


BOOL : 'tt'
     | 'ff'
     ;
VARNAME   : [a-z]+ ;
FUNVAR    : [A-Z]+ ;
EscapedString : '"' (~[\\"] | '\\' [\\"])* '"';
NUMBER : DecimalFloatingConstant ;
WS     : [ \n\t\r]+ -> skip;


fragment
DecimalFloatingConstant
    :   [0-9]* '.' [0-9]+
        |   [0-9]+ '.'

    |   [0-9]+ ExponentPart
    ;

fragment
FractionalConstant
    :   [0-9]* '.' [0-9]+
    |   [0-9]+ '.'
    ;

fragment
ExponentPart
    :   [eE] [+-]? [0-9]+
    ;

