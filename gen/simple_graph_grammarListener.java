// Generated from /home/giacomo/projects/gsm2/antlr4/graph_grammar/simple_graph_grammar.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link simple_graph_grammarParser}.
 */
public interface simple_graph_grammarListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link simple_graph_grammarParser#all_matches}.
	 * @param ctx the parse tree
	 */
	void enterAll_matches(simple_graph_grammarParser.All_matchesContext ctx);
	/**
	 * Exit a parse tree produced by {@link simple_graph_grammarParser#all_matches}.
	 * @param ctx the parse tree
	 */
	void exitAll_matches(simple_graph_grammarParser.All_matchesContext ctx);
	/**
	 * Enter a parse tree produced by {@link simple_graph_grammarParser#node}.
	 * @param ctx the parse tree
	 */
	void enterNode(simple_graph_grammarParser.NodeContext ctx);
	/**
	 * Exit a parse tree produced by {@link simple_graph_grammarParser#node}.
	 * @param ctx the parse tree
	 */
	void exitNode(simple_graph_grammarParser.NodeContext ctx);
	/**
	 * Enter a parse tree produced by {@link simple_graph_grammarParser#centralmatch}.
	 * @param ctx the parse tree
	 */
	void enterCentralmatch(simple_graph_grammarParser.CentralmatchContext ctx);
	/**
	 * Exit a parse tree produced by {@link simple_graph_grammarParser#centralmatch}.
	 * @param ctx the parse tree
	 */
	void exitCentralmatch(simple_graph_grammarParser.CentralmatchContext ctx);
	/**
	 * Enter a parse tree produced by {@link simple_graph_grammarParser#many_edges}.
	 * @param ctx the parse tree
	 */
	void enterMany_edges(simple_graph_grammarParser.Many_edgesContext ctx);
	/**
	 * Exit a parse tree produced by {@link simple_graph_grammarParser#many_edges}.
	 * @param ctx the parse tree
	 */
	void exitMany_edges(simple_graph_grammarParser.Many_edgesContext ctx);
	/**
	 * Enter a parse tree produced by the {@code del_node_or_edge}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void enterDel_node_or_edge(simple_graph_grammarParser.Del_node_or_edgeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code del_node_or_edge}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void exitDel_node_or_edge(simple_graph_grammarParser.Del_node_or_edgeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code neu_obj}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void enterNeu_obj(simple_graph_grammarParser.Neu_objContext ctx);
	/**
	 * Exit a parse tree produced by the {@code neu_obj}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void exitNeu_obj(simple_graph_grammarParser.Neu_objContext ctx);
	/**
	 * Enter a parse tree produced by the {@code update_expr}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void enterUpdate_expr(simple_graph_grammarParser.Update_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code update_expr}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void exitUpdate_expr(simple_graph_grammarParser.Update_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_xi}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_xi(simple_graph_grammarParser.Node_xiContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_xi}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_xi(simple_graph_grammarParser.Node_xiContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_ell}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_ell(simple_graph_grammarParser.Node_ellContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_ell}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_ell(simple_graph_grammarParser.Node_ellContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_prop}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_prop(simple_graph_grammarParser.Node_propContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_prop}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_prop(simple_graph_grammarParser.Node_propContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_containment}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_containment(simple_graph_grammarParser.Node_containmentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_containment}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_containment(simple_graph_grammarParser.Node_containmentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code edge_label}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterEdge_label(simple_graph_grammarParser.Edge_labelContext ctx);
	/**
	 * Exit a parse tree produced by the {@code edge_label}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitEdge_label(simple_graph_grammarParser.Edge_labelContext ctx);
	/**
	 * Enter a parse tree produced by the {@code edge_src}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterEdge_src(simple_graph_grammarParser.Edge_srcContext ctx);
	/**
	 * Exit a parse tree produced by the {@code edge_src}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitEdge_src(simple_graph_grammarParser.Edge_srcContext ctx);
	/**
	 * Enter a parse tree produced by the {@code edge_dst}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterEdge_dst(simple_graph_grammarParser.Edge_dstContext ctx);
	/**
	 * Exit a parse tree produced by the {@code edge_dst}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitEdge_dst(simple_graph_grammarParser.Edge_dstContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ifte_expr}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterIfte_expr(simple_graph_grammarParser.Ifte_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ifte_expr}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitIfte_expr(simple_graph_grammarParser.Ifte_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_or_edge}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_or_edge(simple_graph_grammarParser.Node_or_edgeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_or_edge}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_or_edge(simple_graph_grammarParser.Node_or_edgeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code just_par}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterJust_par(simple_graph_grammarParser.Just_parContext ctx);
	/**
	 * Exit a parse tree produced by the {@code just_par}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitJust_par(simple_graph_grammarParser.Just_parContext ctx);
	/**
	 * Enter a parse tree produced by the {@code script}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterScript(simple_graph_grammarParser.ScriptContext ctx);
	/**
	 * Exit a parse tree produced by the {@code script}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitScript(simple_graph_grammarParser.ScriptContext ctx);
	/**
	 * Enter a parse tree produced by the {@code leq_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterLeq_test(simple_graph_grammarParser.Leq_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code leq_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitLeq_test(simple_graph_grammarParser.Leq_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code script_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterScript_test(simple_graph_grammarParser.Script_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code script_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitScript_test(simple_graph_grammarParser.Script_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code or_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterOr_test(simple_graph_grammarParser.Or_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code or_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitOr_test(simple_graph_grammarParser.Or_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code par_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterPar_test(simple_graph_grammarParser.Par_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code par_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitPar_test(simple_graph_grammarParser.Par_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code matched}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterMatched(simple_graph_grammarParser.MatchedContext ctx);
	/**
	 * Exit a parse tree produced by the {@code matched}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitMatched(simple_graph_grammarParser.MatchedContext ctx);
	/**
	 * Enter a parse tree produced by the {@code eq_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterEq_test(simple_graph_grammarParser.Eq_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code eq_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitEq_test(simple_graph_grammarParser.Eq_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code neq_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterNeq_test(simple_graph_grammarParser.Neq_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code neq_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitNeq_test(simple_graph_grammarParser.Neq_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code fill}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterFill(simple_graph_grammarParser.FillContext ctx);
	/**
	 * Exit a parse tree produced by the {@code fill}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitFill(simple_graph_grammarParser.FillContext ctx);
	/**
	 * Enter a parse tree produced by the {@code lt_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterLt_test(simple_graph_grammarParser.Lt_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code lt_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitLt_test(simple_graph_grammarParser.Lt_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code unmatched}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterUnmatched(simple_graph_grammarParser.UnmatchedContext ctx);
	/**
	 * Exit a parse tree produced by the {@code unmatched}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitUnmatched(simple_graph_grammarParser.UnmatchedContext ctx);
	/**
	 * Enter a parse tree produced by the {@code and_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterAnd_test(simple_graph_grammarParser.And_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code and_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitAnd_test(simple_graph_grammarParser.And_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code test_data}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr_side}.
	 * @param ctx the parse tree
	 */
	void enterTest_data(simple_graph_grammarParser.Test_dataContext ctx);
	/**
	 * Exit a parse tree produced by the {@code test_data}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr_side}.
	 * @param ctx the parse tree
	 */
	void exitTest_data(simple_graph_grammarParser.Test_dataContext ctx);
	/**
	 * Enter a parse tree produced by the {@code test_value}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr_side}.
	 * @param ctx the parse tree
	 */
	void enterTest_value(simple_graph_grammarParser.Test_valueContext ctx);
	/**
	 * Exit a parse tree produced by the {@code test_value}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr_side}.
	 * @param ctx the parse tree
	 */
	void exitTest_value(simple_graph_grammarParser.Test_valueContext ctx);
	/**
	 * Enter a parse tree produced by the {@code outedge}
	 * labeled alternative in {@link simple_graph_grammarParser#edge}.
	 * @param ctx the parse tree
	 */
	void enterOutedge(simple_graph_grammarParser.OutedgeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code outedge}
	 * labeled alternative in {@link simple_graph_grammarParser#edge}.
	 * @param ctx the parse tree
	 */
	void exitOutedge(simple_graph_grammarParser.OutedgeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code inedge}
	 * labeled alternative in {@link simple_graph_grammarParser#edge}.
	 * @param ctx the parse tree
	 */
	void enterInedge(simple_graph_grammarParser.InedgeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code inedge}
	 * labeled alternative in {@link simple_graph_grammarParser#edge}.
	 * @param ctx the parse tree
	 */
	void exitInedge(simple_graph_grammarParser.InedgeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code hook}
	 * labeled alternative in {@link simple_graph_grammarParser#edge}.
	 * @param ctx the parse tree
	 */
	void enterHook(simple_graph_grammarParser.HookContext ctx);
	/**
	 * Exit a parse tree produced by the {@code hook}
	 * labeled alternative in {@link simple_graph_grammarParser#edge}.
	 * @param ctx the parse tree
	 */
	void exitHook(simple_graph_grammarParser.HookContext ctx);
	/**
	 * Enter a parse tree produced by {@link simple_graph_grammarParser#edge_joining}.
	 * @param ctx the parse tree
	 */
	void enterEdge_joining(simple_graph_grammarParser.Edge_joiningContext ctx);
	/**
	 * Exit a parse tree produced by {@link simple_graph_grammarParser#edge_joining}.
	 * @param ctx the parse tree
	 */
	void exitEdge_joining(simple_graph_grammarParser.Edge_joiningContext ctx);
	/**
	 * Enter a parse tree produced by {@link simple_graph_grammarParser#edgelabel}.
	 * @param ctx the parse tree
	 */
	void enterEdgelabel(simple_graph_grammarParser.EdgelabelContext ctx);
	/**
	 * Exit a parse tree produced by {@link simple_graph_grammarParser#edgelabel}.
	 * @param ctx the parse tree
	 */
	void exitEdgelabel(simple_graph_grammarParser.EdgelabelContext ctx);
	/**
	 * Enter a parse tree produced by {@link simple_graph_grammarParser#multiple_labels}.
	 * @param ctx the parse tree
	 */
	void enterMultiple_labels(simple_graph_grammarParser.Multiple_labelsContext ctx);
	/**
	 * Exit a parse tree produced by {@link simple_graph_grammarParser#multiple_labels}.
	 * @param ctx the parse tree
	 */
	void exitMultiple_labels(simple_graph_grammarParser.Multiple_labelsContext ctx);
}