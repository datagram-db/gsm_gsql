// Generated from java-escape by ANTLR 4.11.1
package antlr4;
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link datagramqlParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface datagramqlVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link datagramqlParser#all_matches}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAll_matches(datagramqlParser.All_matchesContext ctx);
	/**
	 * Visit a parse tree produced by {@link datagramqlParser#node}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode(datagramqlParser.NodeContext ctx);
	/**
	 * Visit a parse tree produced by {@link datagramqlParser#centralmatch}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCentralmatch(datagramqlParser.CentralmatchContext ctx);
	/**
	 * Visit a parse tree produced by {@link datagramqlParser#many_edges}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMany_edges(datagramqlParser.Many_edgesContext ctx);
	/**
	 * Visit a parse tree produced by the {@code del_node_or_edge}
	 * labeled alternative in {@link datagramqlParser#rewrite_to}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDel_node_or_edge(datagramqlParser.Del_node_or_edgeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code neu_obj}
	 * labeled alternative in {@link datagramqlParser#rewrite_to}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNeu_obj(datagramqlParser.Neu_objContext ctx);
	/**
	 * Visit a parse tree produced by the {@code update_expr}
	 * labeled alternative in {@link datagramqlParser#rewrite_to}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUpdate_expr(datagramqlParser.Update_exprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_xi}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_xi(datagramqlParser.Node_xiContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_ell}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_ell(datagramqlParser.Node_ellContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_prop}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_prop(datagramqlParser.Node_propContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_containment}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_containment(datagramqlParser.Node_containmentContext ctx);
	/**
	 * Visit a parse tree produced by the {@code edge_label}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdge_label(datagramqlParser.Edge_labelContext ctx);
	/**
	 * Visit a parse tree produced by the {@code edge_src}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdge_src(datagramqlParser.Edge_srcContext ctx);
	/**
	 * Visit a parse tree produced by the {@code edge_dst}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdge_dst(datagramqlParser.Edge_dstContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ifte_expr}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIfte_expr(datagramqlParser.Ifte_exprContext ctx);
	/**
	 * Visit a parse tree produced by the {@code node_or_edge}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNode_or_edge(datagramqlParser.Node_or_edgeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code just_par}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitJust_par(datagramqlParser.Just_parContext ctx);
	/**
	 * Visit a parse tree produced by the {@code script}
	 * labeled alternative in {@link datagramqlParser#rewrite_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitScript(datagramqlParser.ScriptContext ctx);
	/**
	 * Visit a parse tree produced by the {@code leq_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLeq_test(datagramqlParser.Leq_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code script_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitScript_test(datagramqlParser.Script_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code or_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOr_test(datagramqlParser.Or_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code par_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPar_test(datagramqlParser.Par_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code matched}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMatched(datagramqlParser.MatchedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code eq_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEq_test(datagramqlParser.Eq_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code neq_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNeq_test(datagramqlParser.Neq_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code fill}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFill(datagramqlParser.FillContext ctx);
	/**
	 * Visit a parse tree produced by the {@code lt_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLt_test(datagramqlParser.Lt_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code unmatched}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnmatched(datagramqlParser.UnmatchedContext ctx);
	/**
	 * Visit a parse tree produced by the {@code and_test}
	 * labeled alternative in {@link datagramqlParser#test_expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnd_test(datagramqlParser.And_testContext ctx);
	/**
	 * Visit a parse tree produced by the {@code test_data}
	 * labeled alternative in {@link datagramqlParser#test_expr_side}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTest_data(datagramqlParser.Test_dataContext ctx);
	/**
	 * Visit a parse tree produced by the {@code test_value}
	 * labeled alternative in {@link datagramqlParser#test_expr_side}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTest_value(datagramqlParser.Test_valueContext ctx);
	/**
	 * Visit a parse tree produced by the {@code outedge}
	 * labeled alternative in {@link datagramqlParser#edge}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOutedge(datagramqlParser.OutedgeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code inedge}
	 * labeled alternative in {@link datagramqlParser#edge}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInedge(datagramqlParser.InedgeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code hook}
	 * labeled alternative in {@link datagramqlParser#edge}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitHook(datagramqlParser.HookContext ctx);
	/**
	 * Visit a parse tree produced by {@link datagramqlParser#edge_joining}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdge_joining(datagramqlParser.Edge_joiningContext ctx);
	/**
	 * Visit a parse tree produced by {@link datagramqlParser#edgelabel}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEdgelabel(datagramqlParser.EdgelabelContext ctx);
	/**
	 * Visit a parse tree produced by {@link datagramqlParser#multiple_labels}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMultiple_labels(datagramqlParser.Multiple_labelsContext ctx);
}