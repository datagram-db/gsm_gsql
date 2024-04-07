// Generated from /home/giacomo/projects/gsm2/antlr4/graph_grammar/simple_graph_grammar.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link simple_graph_grammarParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface simple_graph_grammarVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link simple_graph_grammarParser#all_matches}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAll_matches(simple_graph_grammarParser.All_matchesContext ctx);
	/**
	 * Visit a parse tree produced by {@link simple_graph_grammarParser#node}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode(simple_graph_grammarParser.NodeContext ctx);
	/**
	 * Visit a parse tree produced by {@link simple_graph_grammarParser#centralmatch}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCentralmatch(simple_graph_grammarParser.CentralmatchContext ctx);
	/**
	 * Visit a parse tree produced by {@link simple_graph_grammarParser#many_edges}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMany_edges(simple_graph_grammarParser.Many_edgesContext ctx);
	/**
	 * Visit a parse tree produced by the {@code del_node_or_edge}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_to}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDel_node_or_edge(simple_graph_grammarParser.Del_node_or_edgeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code neu_obj}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_to}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNeu_obj(simple_graph_grammarParser.Neu_objContext ctx);
	/**
	 * Visit a parse tree produced by the {@code update_expr}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_to}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUpdate_expr(simple_graph_grammarParser.Update_exprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_xi}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_xi(simple_graph_grammarParser.Node_xiContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_ell}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_ell(simple_graph_grammarParser.Node_ellContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_prop}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_prop(simple_graph_grammarParser.Node_propContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_containment}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_containment(simple_graph_grammarParser.Node_containmentContext ctx);
	/**
	 * Visit a parse tree produced by the {@code edge_label}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdge_label(simple_graph_grammarParser.Edge_labelContext ctx);
	/**
	 * Visit a parse tree produced by the {@code edge_src}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdge_src(simple_graph_grammarParser.Edge_srcContext ctx);
	/**
	 * Visit a parse tree produced by the {@code edge_dst}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdge_dst(simple_graph_grammarParser.Edge_dstContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ifte_expr}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIfte_expr(simple_graph_grammarParser.Ifte_exprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_or_edge}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_or_edge(simple_graph_grammarParser.Node_or_edgeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code just_par}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitJust_par(simple_graph_grammarParser.Just_parContext ctx);
	/**
	 * Visit a parse tree produced by the {@code script}
	 * labeled alternative in {@link simple_graph_grammarParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitScript(simple_graph_grammarParser.ScriptContext ctx);
	/**
	 * Visit a parse tree produced by the {@code leq_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLeq_test(simple_graph_grammarParser.Leq_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code script_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitScript_test(simple_graph_grammarParser.Script_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code or_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOr_test(simple_graph_grammarParser.Or_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code par_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPar_test(simple_graph_grammarParser.Par_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code matched}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMatched(simple_graph_grammarParser.MatchedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code eq_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEq_test(simple_graph_grammarParser.Eq_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code neq_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNeq_test(simple_graph_grammarParser.Neq_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code fill}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFill(simple_graph_grammarParser.FillContext ctx);
	/**
	 * Visit a parse tree produced by the {@code lt_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLt_test(simple_graph_grammarParser.Lt_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code unmatched}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnmatched(simple_graph_grammarParser.UnmatchedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code and_test}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnd_test(simple_graph_grammarParser.And_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code test_data}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr_side}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTest_data(simple_graph_grammarParser.Test_dataContext ctx);
	/**
	 * Visit a parse tree produced by the {@code test_value}
	 * labeled alternative in {@link simple_graph_grammarParser#test_expr_side}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTest_value(simple_graph_grammarParser.Test_valueContext ctx);
	/**
	 * Visit a parse tree produced by the {@code outedge}
	 * labeled alternative in {@link simple_graph_grammarParser#edge}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOutedge(simple_graph_grammarParser.OutedgeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code inedge}
	 * labeled alternative in {@link simple_graph_grammarParser#edge}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInedge(simple_graph_grammarParser.InedgeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code hook}
	 * labeled alternative in {@link simple_graph_grammarParser#edge}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitHook(simple_graph_grammarParser.HookContext ctx);
	/**
	 * Visit a parse tree produced by {@link simple_graph_grammarParser#edge_joining}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdge_joining(simple_graph_grammarParser.Edge_joiningContext ctx);
	/**
	 * Visit a parse tree produced by {@link simple_graph_grammarParser#edgelabel}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdgelabel(simple_graph_grammarParser.EdgelabelContext ctx);
	/**
	 * Visit a parse tree produced by {@link simple_graph_grammarParser#multiple_labels}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiple_labels(simple_graph_grammarParser.Multiple_labelsContext ctx);
}