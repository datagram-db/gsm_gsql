// Generated from java-escape by ANTLR 4.11.1
package antlr4;
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link datagramqlParser}.
 */
public interface datagramqlListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link datagramqlParser#all_matches}.
	 * @param ctx the parse tree
	 */
	void enterAll_matches(datagramqlParser.All_matchesContext ctx);
	/**
	 * Exit a parse tree produced by {@link datagramqlParser#all_matches}.
	 * @param ctx the parse tree
	 */
	void exitAll_matches(datagramqlParser.All_matchesContext ctx);
	/**
	 * Enter a parse tree produced by {@link datagramqlParser#node}.
	 * @param ctx the parse tree
	 */
	void enterNode(datagramqlParser.NodeContext ctx);
	/**
	 * Exit a parse tree produced by {@link datagramqlParser#node}.
	 * @param ctx the parse tree
	 */
	void exitNode(datagramqlParser.NodeContext ctx);
	/**
	 * Enter a parse tree produced by {@link datagramqlParser#centralmatch}.
	 * @param ctx the parse tree
	 */
	void enterCentralmatch(datagramqlParser.CentralmatchContext ctx);
	/**
	 * Exit a parse tree produced by {@link datagramqlParser#centralmatch}.
	 * @param ctx the parse tree
	 */
	void exitCentralmatch(datagramqlParser.CentralmatchContext ctx);
	/**
	 * Enter a parse tree produced by {@link datagramqlParser#many_edges}.
	 * @param ctx the parse tree
	 */
	void enterMany_edges(datagramqlParser.Many_edgesContext ctx);
	/**
	 * Exit a parse tree produced by {@link datagramqlParser#many_edges}.
	 * @param ctx the parse tree
	 */
	void exitMany_edges(datagramqlParser.Many_edgesContext ctx);
	/**
	 * Enter a parse tree produced by the {@code del_node_or_edge}
	 * labeled alternative in {@link datagramqlParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void enterDel_node_or_edge(datagramqlParser.Del_node_or_edgeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code del_node_or_edge}
	 * labeled alternative in {@link datagramqlParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void exitDel_node_or_edge(datagramqlParser.Del_node_or_edgeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code neu_obj}
	 * labeled alternative in {@link datagramqlParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void enterNeu_obj(datagramqlParser.Neu_objContext ctx);
	/**
	 * Exit a parse tree produced by the {@code neu_obj}
	 * labeled alternative in {@link datagramqlParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void exitNeu_obj(datagramqlParser.Neu_objContext ctx);
	/**
	 * Enter a parse tree produced by the {@code update_expr}
	 * labeled alternative in {@link datagramqlParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void enterUpdate_expr(datagramqlParser.Update_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code update_expr}
	 * labeled alternative in {@link datagramqlParser#rewrite_to}.
	 * @param ctx the parse tree
	 */
	void exitUpdate_expr(datagramqlParser.Update_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_xi}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_xi(datagramqlParser.Node_xiContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_xi}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_xi(datagramqlParser.Node_xiContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_ell}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_ell(datagramqlParser.Node_ellContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_ell}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_ell(datagramqlParser.Node_ellContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_prop}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_prop(datagramqlParser.Node_propContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_prop}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_prop(datagramqlParser.Node_propContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_containment}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_containment(datagramqlParser.Node_containmentContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_containment}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_containment(datagramqlParser.Node_containmentContext ctx);
	/**
	 * Enter a parse tree produced by the {@code edge_label}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterEdge_label(datagramqlParser.Edge_labelContext ctx);
	/**
	 * Exit a parse tree produced by the {@code edge_label}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitEdge_label(datagramqlParser.Edge_labelContext ctx);
	/**
	 * Enter a parse tree produced by the {@code edge_src}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterEdge_src(datagramqlParser.Edge_srcContext ctx);
	/**
	 * Exit a parse tree produced by the {@code edge_src}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitEdge_src(datagramqlParser.Edge_srcContext ctx);
	/**
	 * Enter a parse tree produced by the {@code edge_dst}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterEdge_dst(datagramqlParser.Edge_dstContext ctx);
	/**
	 * Exit a parse tree produced by the {@code edge_dst}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitEdge_dst(datagramqlParser.Edge_dstContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ifte_expr}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterIfte_expr(datagramqlParser.Ifte_exprContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ifte_expr}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitIfte_expr(datagramqlParser.Ifte_exprContext ctx);
	/**
	 * Enter a parse tree produced by the {@code node_or_edge}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterNode_or_edge(datagramqlParser.Node_or_edgeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code node_or_edge}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitNode_or_edge(datagramqlParser.Node_or_edgeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code just_par}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterJust_par(datagramqlParser.Just_parContext ctx);
	/**
	 * Exit a parse tree produced by the {@code just_par}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitJust_par(datagramqlParser.Just_parContext ctx);
	/**
	 * Enter a parse tree produced by the {@code script}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void enterScript(datagramqlParser.ScriptContext ctx);
	/**
	 * Exit a parse tree produced by the {@code script}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 */
	void exitScript(datagramqlParser.ScriptContext ctx);
	/**
	 * Enter a parse tree produced by the {@code leq_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterLeq_test(datagramqlParser.Leq_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code leq_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitLeq_test(datagramqlParser.Leq_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code script_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterScript_test(datagramqlParser.Script_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code script_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitScript_test(datagramqlParser.Script_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code or_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterOr_test(datagramqlParser.Or_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code or_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitOr_test(datagramqlParser.Or_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code par_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterPar_test(datagramqlParser.Par_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code par_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitPar_test(datagramqlParser.Par_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code matched}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterMatched(datagramqlParser.MatchedContext ctx);
	/**
	 * Exit a parse tree produced by the {@code matched}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitMatched(datagramqlParser.MatchedContext ctx);
	/**
	 * Enter a parse tree produced by the {@code eq_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterEq_test(datagramqlParser.Eq_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code eq_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitEq_test(datagramqlParser.Eq_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code neq_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterNeq_test(datagramqlParser.Neq_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code neq_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitNeq_test(datagramqlParser.Neq_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code fill}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterFill(datagramqlParser.FillContext ctx);
	/**
	 * Exit a parse tree produced by the {@code fill}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitFill(datagramqlParser.FillContext ctx);
	/**
	 * Enter a parse tree produced by the {@code lt_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterLt_test(datagramqlParser.Lt_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code lt_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitLt_test(datagramqlParser.Lt_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code unmatched}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterUnmatched(datagramqlParser.UnmatchedContext ctx);
	/**
	 * Exit a parse tree produced by the {@code unmatched}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitUnmatched(datagramqlParser.UnmatchedContext ctx);
	/**
	 * Enter a parse tree produced by the {@code and_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void enterAnd_test(datagramqlParser.And_testContext ctx);
	/**
	 * Exit a parse tree produced by the {@code and_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 */
	void exitAnd_test(datagramqlParser.And_testContext ctx);
	/**
	 * Enter a parse tree produced by the {@code test_data}
	 * labeled alternative in {@link datagramqlParser#test_expr_side}.
	 * @param ctx the parse tree
	 */
	void enterTest_data(datagramqlParser.Test_dataContext ctx);
	/**
	 * Exit a parse tree produced by the {@code test_data}
	 * labeled alternative in {@link datagramqlParser#test_expr_side}.
	 * @param ctx the parse tree
	 */
	void exitTest_data(datagramqlParser.Test_dataContext ctx);
	/**
	 * Enter a parse tree produced by the {@code test_value}
	 * labeled alternative in {@link datagramqlParser#test_expr_side}.
	 * @param ctx the parse tree
	 */
	void enterTest_value(datagramqlParser.Test_valueContext ctx);
	/**
	 * Exit a parse tree produced by the {@code test_value}
	 * labeled alternative in {@link datagramqlParser#test_expr_side}.
	 * @param ctx the parse tree
	 */
	void exitTest_value(datagramqlParser.Test_valueContext ctx);
	/**
	 * Enter a parse tree produced by the {@code outedge}
	 * labeled alternative in {@link datagramqlParser#edge}.
	 * @param ctx the parse tree
	 */
	void enterOutedge(datagramqlParser.OutedgeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code outedge}
	 * labeled alternative in {@link datagramqlParser#edge}.
	 * @param ctx the parse tree
	 */
	void exitOutedge(datagramqlParser.OutedgeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code inedge}
	 * labeled alternative in {@link datagramqlParser#edge}.
	 * @param ctx the parse tree
	 */
	void enterInedge(datagramqlParser.InedgeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code inedge}
	 * labeled alternative in {@link datagramqlParser#edge}.
	 * @param ctx the parse tree
	 */
	void exitInedge(datagramqlParser.InedgeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code hook}
	 * labeled alternative in {@link datagramqlParser#edge}.
	 * @param ctx the parse tree
	 */
	void enterHook(datagramqlParser.HookContext ctx);
	/**
	 * Exit a parse tree produced by the {@code hook}
	 * labeled alternative in {@link datagramqlParser#edge}.
	 * @param ctx the parse tree
	 */
	void exitHook(datagramqlParser.HookContext ctx);
	/**
	 * Enter a parse tree produced by {@link datagramqlParser#edge_joining}.
	 * @param ctx the parse tree
	 */
	void enterEdge_joining(datagramqlParser.Edge_joiningContext ctx);
	/**
	 * Exit a parse tree produced by {@link datagramqlParser#edge_joining}.
	 * @param ctx the parse tree
	 */
	void exitEdge_joining(datagramqlParser.Edge_joiningContext ctx);
	/**
	 * Enter a parse tree produced by {@link datagramqlParser#edgelabel}.
	 * @param ctx the parse tree
	 */
	void enterEdgelabel(datagramqlParser.EdgelabelContext ctx);
	/**
	 * Exit a parse tree produced by {@link datagramqlParser#edgelabel}.
	 * @param ctx the parse tree
	 */
	void exitEdgelabel(datagramqlParser.EdgelabelContext ctx);
	/**
	 * Enter a parse tree produced by {@link datagramqlParser#multiple_labels}.
	 * @param ctx the parse tree
	 */
	void enterMultiple_labels(datagramqlParser.Multiple_labelsContext ctx);
	/**
	 * Exit a parse tree produced by {@link datagramqlParser#multiple_labels}.
	 * @param ctx the parse tree
	 */
	void exitMultiple_labels(datagramqlParser.Multiple_labelsContext ctx);
}