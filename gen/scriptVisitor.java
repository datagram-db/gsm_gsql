// Generated from /home/giacomo/projects/gsm2/antlr4/scriptv2/script.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link scriptParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface scriptVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link scriptParser#script}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitScript(scriptParser.ScriptContext ctx);
	/**
	 * Visit a parse tree produced by {@link scriptParser#tuple_pair}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTuple_pair(scriptParser.Tuple_pairContext ctx);
	/**
	 * Visit a parse tree produced by the {@code coerce}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCoerce(scriptParser.CoerceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code varphi}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVarphi(scriptParser.VarphiContext ctx);
	/**
	 * Visit a parse tree produced by the {@code select}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSelect(scriptParser.SelectContext ctx);
	/**
	 * Visit a parse tree produced by the {@code mod}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMod(scriptParser.ModContext ctx);
	/**
	 * Visit a parse tree produced by the {@code mult}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMult(scriptParser.MultContext ctx);
	/**
	 * Visit a parse tree produced by the {@code rfold}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRfold(scriptParser.RfoldContext ctx);
	/**
	 * Visit a parse tree produced by the {@code cos}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCos(scriptParser.CosContext ctx);
	/**
	 * Visit a parse tree produced by the {@code lt}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLt(scriptParser.LtContext ctx);
	/**
	 * Visit a parse tree produced by the {@code project}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProject(scriptParser.ProjectContext ctx);
	/**
	 * Visit a parse tree produced by the {@code put}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPut(scriptParser.PutContext ctx);
	/**
	 * Visit a parse tree produced by the {@code div}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDiv(scriptParser.DivContext ctx);
	/**
	 * Visit a parse tree produced by the {@code function}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunction(scriptParser.FunctionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code selfcross}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSelfcross(scriptParser.SelfcrossContext ctx);
	/**
	 * Visit a parse tree produced by the {@code leq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLeq(scriptParser.LeqContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_label}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_label(scriptParser.Type_labelContext ctx);
	/**
	 * Visit a parse tree produced by the {@code neq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNeq(scriptParser.NeqContext ctx);
	/**
	 * Visit a parse tree produced by the {@code tan}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTan(scriptParser.TanContext ctx);
	/**
	 * Visit a parse tree produced by the {@code add}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAdd(scriptParser.AddContext ctx);
	/**
	 * Visit a parse tree produced by the {@code subtype_of}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSubtype_of(scriptParser.Subtype_ofContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_bool}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_bool(scriptParser.Type_boolContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ensure}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnsure(scriptParser.EnsureContext ctx);
	/**
	 * Visit a parse tree produced by the {@code imply}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitImply(scriptParser.ImplyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ell}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEll(scriptParser.EllContext ctx);
	/**
	 * Visit a parse tree produced by the {@code var}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVar(scriptParser.VarContext ctx);
	/**
	 * Visit a parse tree produced by the {@code kind}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitKind(scriptParser.KindContext ctx);
	/**
	 * Visit a parse tree produced by the {@code atom_bool}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAtom_bool(scriptParser.Atom_boolContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ceil}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCeil(scriptParser.CeilContext ctx);
	/**
	 * Visit a parse tree produced by the {@code concat}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConcat(scriptParser.ConcatContext ctx);
	/**
	 * Visit a parse tree produced by the {@code eq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEq(scriptParser.EqContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_tuple}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_tuple(scriptParser.Type_tupleContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_or}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_or(scriptParser.Type_orContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_lex}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_lex(scriptParser.Type_lexContext ctx);
	/**
	 * Visit a parse tree produced by the {@code sigma_type}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSigma_type(scriptParser.Sigma_typeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code contains}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitContains(scriptParser.ContainsContext ctx);
	/**
	 * Visit a parse tree produced by the {@code eval}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEval(scriptParser.EvalContext ctx);
	/**
	 * Visit a parse tree produced by the {@code atom_number}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAtom_number(scriptParser.Atom_numberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code at}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAt(scriptParser.AtContext ctx);
	/**
	 * Visit a parse tree produced by the {@code null}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNull(scriptParser.NullContext ctx);
	/**
	 * Visit a parse tree produced by the {@code enforce}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnforce(scriptParser.EnforceContext ctx);
	/**
	 * Visit a parse tree produced by the {@code sub}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSub(scriptParser.SubContext ctx);
	/**
	 * Visit a parse tree produced by the {@code atom_array}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAtom_array(scriptParser.Atom_arrayContext ctx);
	/**
	 * Visit a parse tree produced by the {@code log}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLog(scriptParser.LogContext ctx);
	/**
	 * Visit a parse tree produced by the {@code lfold}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLfold(scriptParser.LfoldContext ctx);
	/**
	 * Visit a parse tree produced by the {@code substring}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSubstring(scriptParser.SubstringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code remove}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRemove(scriptParser.RemoveContext ctx);
	/**
	 * Visit a parse tree produced by the {@code paren}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParen(scriptParser.ParenContext ctx);
	/**
	 * Visit a parse tree produced by the {@code not}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNot(scriptParser.NotContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_string}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_string(scriptParser.Type_stringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_any}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_any(scriptParser.Type_anyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code geq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGeq(scriptParser.GeqContext ctx);
	/**
	 * Visit a parse tree produced by the {@code flat}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFlat(scriptParser.FlatContext ctx);
	/**
	 * Visit a parse tree produced by the {@code and}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAnd(scriptParser.AndContext ctx);
	/**
	 * Visit a parse tree produced by the {@code pow}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPow(scriptParser.PowContext ctx);
	/**
	 * Visit a parse tree produced by the {@code sin}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSin(scriptParser.SinContext ctx);
	/**
	 * Visit a parse tree produced by the {@code floor}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFloor(scriptParser.FloorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code map}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMap(scriptParser.MapContext ctx);
	/**
	 * Visit a parse tree produced by the {@code typeof}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeof(scriptParser.TypeofContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_int}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_int(scriptParser.Type_intContext ctx);
	/**
	 * Visit a parse tree produced by the {@code or}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitOr(scriptParser.OrContext ctx);
	/**
	 * Visit a parse tree produced by the {@code inj}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInj(scriptParser.InjContext ctx);
	/**
	 * Visit a parse tree produced by the {@code apply}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitApply(scriptParser.ApplyContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_and}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_and(scriptParser.Type_andContext ctx);
	/**
	 * Visit a parse tree produced by the {@code cross}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCross(scriptParser.CrossContext ctx);
	/**
	 * Visit a parse tree produced by the {@code gt}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGt(scriptParser.GtContext ctx);
	/**
	 * Visit a parse tree produced by the {@code atom_tuple}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAtom_tuple(scriptParser.Atom_tupleContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_double}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_double(scriptParser.Type_doubleContext ctx);
	/**
	 * Visit a parse tree produced by the {@code filter}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFilter(scriptParser.FilterContext ctx);
	/**
	 * Visit a parse tree produced by the {@code phi}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPhi(scriptParser.PhiContext ctx);
	/**
	 * Visit a parse tree produced by the {@code xi}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitXi(scriptParser.XiContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_list}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_list(scriptParser.Type_listContext ctx);
	/**
	 * Visit a parse tree produced by the {@code abs}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAbs(scriptParser.AbsContext ctx);
	/**
	 * Visit a parse tree produced by the {@code obj}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitObj(scriptParser.ObjContext ctx);
	/**
	 * Visit a parse tree produced by the {@code type_bot}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitType_bot(scriptParser.Type_botContext ctx);
	/**
	 * Visit a parse tree produced by the {@code variable}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariable(scriptParser.VariableContext ctx);
	/**
	 * Visit a parse tree produced by the {@code append}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAppend(scriptParser.AppendContext ctx);
	/**
	 * Visit a parse tree produced by the {@code ifte}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIfte(scriptParser.IfteContext ctx);
	/**
	 * Visit a parse tree produced by the {@code atom_string}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAtom_string(scriptParser.Atom_stringContext ctx);
	/**
	 * Visit a parse tree produced by the {@code assign}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssign(scriptParser.AssignContext ctx);
}