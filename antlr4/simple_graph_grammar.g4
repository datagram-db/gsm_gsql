grammar simple_graph_grammar;

all_matches: (centralmatch ';')* centralmatch;

node: LPAR STAR? VEC? var=multiple_labels (COL OTHERS)? RPAR;

centralmatch: var=OTHERS EQ src=node            // central match
                            e1=many_edges?           // ego-net patterns
                            edge_joining*   // join conditions
                            (REWRITE_TO rewrite_to* dst=node e2=many_edges?)?
                            ;
many_edges : edge+;

rewrite_to: 'del' OTHERS                                                                                        #del_node_or_edge
          | 'new' dst=OTHERS                                                                                   #neu_obj
          | 'set' to=rewrite_expr 'as' from=rewrite_expr                                                        #update_expr
          ;

rewrite_expr: '𝜉' num=OTHERS '@' nodeVar=rewrite_expr #node_xi
            | 'ℓ' num=OTHERS '@' nodeVar=rewrite_expr #node_ell
            | '𝜋' key=rewrite_expr '@' nodeVar=rewrite_expr #node_prop
            | 'φ' key=OTHERS ',' nodeVar=rewrite_expr #node_containment
            | 'label' edgeVar=rewrite_expr            #edge_label
            | 'src'   edgeVar=rewrite_expr            #edge_src
            | 'dst'   edgeVar=rewrite_expr            #edge_dst
            | IF LPAR ifcond=test_expr RPAR THEN then_effect=rewrite_expr (ELSE else_effect=rewrite_expr)?  #ifte_expr
            | OTHERS                                  #node_or_edge
            | LPAR rewrite_expr RPAR                  #just_par
            ;

test_expr: src=test_expr_side '=' dst=test_expr_side;

test_expr_side : rewrite_expr #test_data
               | OTHERS       #test_value
               ;

edge: '--' edgelabel '->' node #outedge
    | '<-' edgelabel '--' node #inedge
    | '--' edgelabel 'hook' #hook
    ;
edge_joining: node edge;

edgelabel: QPAR (FORALL? | QM?) (var=OTHERS COL)? multiple_labels? PPAR;
multiple_labels: (OTHERS '||')* OTHERS;

IF: 'if';
THEN: 'then';
ELSE: 'else';
AS: 'as';
VEC: '>>';
REWRITE_TO: '↪';
FORALL: '∀';
QM: '?';
EQ: '=';
STAR: '*';
LPAR: '(';
RPAR: ')';
COL: ':';
QPAR: '[';
PPAR: ']';
OTHERS: ~[;*():=\][|∀> \t\r\n-]+;
SPACE : [ \t\r\n]+ -> skip;

COMMENT
    : '/*' .*? '*/' -> skip
;

LINE_COMMENT
    : '//' ~[\r\n]* -> skip
;