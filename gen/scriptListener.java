// Generated from /home/giacomo/projects/gsm2/antlr4/scriptv2/script.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link scriptParser}.
 */
public interface scriptListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link scriptParser#script}.
	 * @param ctx the parse tree
	 */
	void enterScript(scriptParser.ScriptContext ctx);
	/**
	 * Exit a parse tree produced by {@link scriptParser#script}.
	 * @param ctx the parse tree
	 */
	void exitScript(scriptParser.ScriptContext ctx);
	/**
	 * Enter a parse tree produced by {@link scriptParser#tuple_pair}.
	 * @param ctx the parse tree
	 */
	void enterTuple_pair(scriptParser.Tuple_pairContext ctx);
	/**
	 * Exit a parse tree produced by {@link scriptParser#tuple_pair}.
	 * @param ctx the parse tree
	 */
	void exitTuple_pair(scriptParser.Tuple_pairContext ctx);
	/**
	 * Enter a parse tree produced by the {@code coerce}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterCoerce(scriptParser.CoerceContext ctx);
	/**
	 * Exit a parse tree produced by the {@code coerce}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitCoerce(scriptParser.CoerceContext ctx);
	/**
	 * Enter a parse tree produced by the {@code varphi}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterVarphi(scriptParser.VarphiContext ctx);
	/**
	 * Exit a parse tree produced by the {@code varphi}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitVarphi(scriptParser.VarphiContext ctx);
	/**
	 * Enter a parse tree produced by the {@code select}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSelect(scriptParser.SelectContext ctx);
	/**
	 * Exit a parse tree produced by the {@code select}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSelect(scriptParser.SelectContext ctx);
	/**
	 * Enter a parse tree produced by the {@code mod}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterMod(scriptParser.ModContext ctx);
	/**
	 * Exit a parse tree produced by the {@code mod}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitMod(scriptParser.ModContext ctx);
	/**
	 * Enter a parse tree produced by the {@code mult}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterMult(scriptParser.MultContext ctx);
	/**
	 * Exit a parse tree produced by the {@code mult}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitMult(scriptParser.MultContext ctx);
	/**
	 * Enter a parse tree produced by the {@code rfold}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterRfold(scriptParser.RfoldContext ctx);
	/**
	 * Exit a parse tree produced by the {@code rfold}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitRfold(scriptParser.RfoldContext ctx);
	/**
	 * Enter a parse tree produced by the {@code cos}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterCos(scriptParser.CosContext ctx);
	/**
	 * Exit a parse tree produced by the {@code cos}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitCos(scriptParser.CosContext ctx);
	/**
	 * Enter a parse tree produced by the {@code lt}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterLt(scriptParser.LtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code lt}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitLt(scriptParser.LtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code project}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterProject(scriptParser.ProjectContext ctx);
	/**
	 * Exit a parse tree produced by the {@code project}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitProject(scriptParser.ProjectContext ctx);
	/**
	 * Enter a parse tree produced by the {@code put}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterPut(scriptParser.PutContext ctx);
	/**
	 * Exit a parse tree produced by the {@code put}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitPut(scriptParser.PutContext ctx);
	/**
	 * Enter a parse tree produced by the {@code div}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterDiv(scriptParser.DivContext ctx);
	/**
	 * Exit a parse tree produced by the {@code div}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitDiv(scriptParser.DivContext ctx);
	/**
	 * Enter a parse tree produced by the {@code function}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterFunction(scriptParser.FunctionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code function}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitFunction(scriptParser.FunctionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code selfcross}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSelfcross(scriptParser.SelfcrossContext ctx);
	/**
	 * Exit a parse tree produced by the {@code selfcross}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSelfcross(scriptParser.SelfcrossContext ctx);
	/**
	 * Enter a parse tree produced by the {@code leq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterLeq(scriptParser.LeqContext ctx);
	/**
	 * Exit a parse tree produced by the {@code leq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitLeq(scriptParser.LeqContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_label}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_label(scriptParser.Type_labelContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_label}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_label(scriptParser.Type_labelContext ctx);
	/**
	 * Enter a parse tree produced by the {@code neq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterNeq(scriptParser.NeqContext ctx);
	/**
	 * Exit a parse tree produced by the {@code neq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitNeq(scriptParser.NeqContext ctx);
	/**
	 * Enter a parse tree produced by the {@code tan}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterTan(scriptParser.TanContext ctx);
	/**
	 * Exit a parse tree produced by the {@code tan}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitTan(scriptParser.TanContext ctx);
	/**
	 * Enter a parse tree produced by the {@code add}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAdd(scriptParser.AddContext ctx);
	/**
	 * Exit a parse tree produced by the {@code add}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAdd(scriptParser.AddContext ctx);
	/**
	 * Enter a parse tree produced by the {@code subtype_of}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSubtype_of(scriptParser.Subtype_ofContext ctx);
	/**
	 * Exit a parse tree produced by the {@code subtype_of}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSubtype_of(scriptParser.Subtype_ofContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_bool}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_bool(scriptParser.Type_boolContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_bool}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_bool(scriptParser.Type_boolContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ensure}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterEnsure(scriptParser.EnsureContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ensure}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitEnsure(scriptParser.EnsureContext ctx);
	/**
	 * Enter a parse tree produced by the {@code imply}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterImply(scriptParser.ImplyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code imply}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitImply(scriptParser.ImplyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ell}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterEll(scriptParser.EllContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ell}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitEll(scriptParser.EllContext ctx);
	/**
	 * Enter a parse tree produced by the {@code var}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterVar(scriptParser.VarContext ctx);
	/**
	 * Exit a parse tree produced by the {@code var}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitVar(scriptParser.VarContext ctx);
	/**
	 * Enter a parse tree produced by the {@code kind}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterKind(scriptParser.KindContext ctx);
	/**
	 * Exit a parse tree produced by the {@code kind}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitKind(scriptParser.KindContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_bool}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAtom_bool(scriptParser.Atom_boolContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_bool}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAtom_bool(scriptParser.Atom_boolContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ceil}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterCeil(scriptParser.CeilContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ceil}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitCeil(scriptParser.CeilContext ctx);
	/**
	 * Enter a parse tree produced by the {@code concat}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterConcat(scriptParser.ConcatContext ctx);
	/**
	 * Exit a parse tree produced by the {@code concat}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitConcat(scriptParser.ConcatContext ctx);
	/**
	 * Enter a parse tree produced by the {@code eq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterEq(scriptParser.EqContext ctx);
	/**
	 * Exit a parse tree produced by the {@code eq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitEq(scriptParser.EqContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_tuple}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_tuple(scriptParser.Type_tupleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_tuple}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_tuple(scriptParser.Type_tupleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_or}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_or(scriptParser.Type_orContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_or}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_or(scriptParser.Type_orContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_lex}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_lex(scriptParser.Type_lexContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_lex}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_lex(scriptParser.Type_lexContext ctx);
	/**
	 * Enter a parse tree produced by the {@code sigma_type}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSigma_type(scriptParser.Sigma_typeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code sigma_type}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSigma_type(scriptParser.Sigma_typeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code contains}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterContains(scriptParser.ContainsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code contains}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitContains(scriptParser.ContainsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code eval}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterEval(scriptParser.EvalContext ctx);
	/**
	 * Exit a parse tree produced by the {@code eval}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitEval(scriptParser.EvalContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_number}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAtom_number(scriptParser.Atom_numberContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_number}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAtom_number(scriptParser.Atom_numberContext ctx);
	/**
	 * Enter a parse tree produced by the {@code at}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAt(scriptParser.AtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code at}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAt(scriptParser.AtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code null}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterNull(scriptParser.NullContext ctx);
	/**
	 * Exit a parse tree produced by the {@code null}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitNull(scriptParser.NullContext ctx);
	/**
	 * Enter a parse tree produced by the {@code enforce}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterEnforce(scriptParser.EnforceContext ctx);
	/**
	 * Exit a parse tree produced by the {@code enforce}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitEnforce(scriptParser.EnforceContext ctx);
	/**
	 * Enter a parse tree produced by the {@code sub}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSub(scriptParser.SubContext ctx);
	/**
	 * Exit a parse tree produced by the {@code sub}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSub(scriptParser.SubContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_array}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAtom_array(scriptParser.Atom_arrayContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_array}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAtom_array(scriptParser.Atom_arrayContext ctx);
	/**
	 * Enter a parse tree produced by the {@code log}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterLog(scriptParser.LogContext ctx);
	/**
	 * Exit a parse tree produced by the {@code log}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitLog(scriptParser.LogContext ctx);
	/**
	 * Enter a parse tree produced by the {@code lfold}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterLfold(scriptParser.LfoldContext ctx);
	/**
	 * Exit a parse tree produced by the {@code lfold}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitLfold(scriptParser.LfoldContext ctx);
	/**
	 * Enter a parse tree produced by the {@code substring}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSubstring(scriptParser.SubstringContext ctx);
	/**
	 * Exit a parse tree produced by the {@code substring}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSubstring(scriptParser.SubstringContext ctx);
	/**
	 * Enter a parse tree produced by the {@code remove}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterRemove(scriptParser.RemoveContext ctx);
	/**
	 * Exit a parse tree produced by the {@code remove}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitRemove(scriptParser.RemoveContext ctx);
	/**
	 * Enter a parse tree produced by the {@code paren}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterParen(scriptParser.ParenContext ctx);
	/**
	 * Exit a parse tree produced by the {@code paren}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitParen(scriptParser.ParenContext ctx);
	/**
	 * Enter a parse tree produced by the {@code not}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterNot(scriptParser.NotContext ctx);
	/**
	 * Exit a parse tree produced by the {@code not}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitNot(scriptParser.NotContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_string}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_string(scriptParser.Type_stringContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_string}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_string(scriptParser.Type_stringContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_any}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_any(scriptParser.Type_anyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_any}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_any(scriptParser.Type_anyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code geq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterGeq(scriptParser.GeqContext ctx);
	/**
	 * Exit a parse tree produced by the {@code geq}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitGeq(scriptParser.GeqContext ctx);
	/**
	 * Enter a parse tree produced by the {@code flat}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterFlat(scriptParser.FlatContext ctx);
	/**
	 * Exit a parse tree produced by the {@code flat}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitFlat(scriptParser.FlatContext ctx);
	/**
	 * Enter a parse tree produced by the {@code and}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAnd(scriptParser.AndContext ctx);
	/**
	 * Exit a parse tree produced by the {@code and}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAnd(scriptParser.AndContext ctx);
	/**
	 * Enter a parse tree produced by the {@code pow}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterPow(scriptParser.PowContext ctx);
	/**
	 * Exit a parse tree produced by the {@code pow}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitPow(scriptParser.PowContext ctx);
	/**
	 * Enter a parse tree produced by the {@code sin}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterSin(scriptParser.SinContext ctx);
	/**
	 * Exit a parse tree produced by the {@code sin}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitSin(scriptParser.SinContext ctx);
	/**
	 * Enter a parse tree produced by the {@code floor}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterFloor(scriptParser.FloorContext ctx);
	/**
	 * Exit a parse tree produced by the {@code floor}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitFloor(scriptParser.FloorContext ctx);
	/**
	 * Enter a parse tree produced by the {@code map}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterMap(scriptParser.MapContext ctx);
	/**
	 * Exit a parse tree produced by the {@code map}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitMap(scriptParser.MapContext ctx);
	/**
	 * Enter a parse tree produced by the {@code typeof}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterTypeof(scriptParser.TypeofContext ctx);
	/**
	 * Exit a parse tree produced by the {@code typeof}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitTypeof(scriptParser.TypeofContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_int}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_int(scriptParser.Type_intContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_int}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_int(scriptParser.Type_intContext ctx);
	/**
	 * Enter a parse tree produced by the {@code or}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterOr(scriptParser.OrContext ctx);
	/**
	 * Exit a parse tree produced by the {@code or}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitOr(scriptParser.OrContext ctx);
	/**
	 * Enter a parse tree produced by the {@code inj}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterInj(scriptParser.InjContext ctx);
	/**
	 * Exit a parse tree produced by the {@code inj}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitInj(scriptParser.InjContext ctx);
	/**
	 * Enter a parse tree produced by the {@code apply}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterApply(scriptParser.ApplyContext ctx);
	/**
	 * Exit a parse tree produced by the {@code apply}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitApply(scriptParser.ApplyContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_and}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_and(scriptParser.Type_andContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_and}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_and(scriptParser.Type_andContext ctx);
	/**
	 * Enter a parse tree produced by the {@code cross}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterCross(scriptParser.CrossContext ctx);
	/**
	 * Exit a parse tree produced by the {@code cross}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitCross(scriptParser.CrossContext ctx);
	/**
	 * Enter a parse tree produced by the {@code gt}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterGt(scriptParser.GtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code gt}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitGt(scriptParser.GtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_tuple}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAtom_tuple(scriptParser.Atom_tupleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_tuple}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAtom_tuple(scriptParser.Atom_tupleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_double}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_double(scriptParser.Type_doubleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_double}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_double(scriptParser.Type_doubleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code filter}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterFilter(scriptParser.FilterContext ctx);
	/**
	 * Exit a parse tree produced by the {@code filter}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitFilter(scriptParser.FilterContext ctx);
	/**
	 * Enter a parse tree produced by the {@code phi}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterPhi(scriptParser.PhiContext ctx);
	/**
	 * Exit a parse tree produced by the {@code phi}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitPhi(scriptParser.PhiContext ctx);
	/**
	 * Enter a parse tree produced by the {@code xi}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterXi(scriptParser.XiContext ctx);
	/**
	 * Exit a parse tree produced by the {@code xi}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitXi(scriptParser.XiContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_list}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_list(scriptParser.Type_listContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_list}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_list(scriptParser.Type_listContext ctx);
	/**
	 * Enter a parse tree produced by the {@code abs}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAbs(scriptParser.AbsContext ctx);
	/**
	 * Exit a parse tree produced by the {@code abs}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAbs(scriptParser.AbsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code obj}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterObj(scriptParser.ObjContext ctx);
	/**
	 * Exit a parse tree produced by the {@code obj}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitObj(scriptParser.ObjContext ctx);
	/**
	 * Enter a parse tree produced by the {@code type_bot}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterType_bot(scriptParser.Type_botContext ctx);
	/**
	 * Exit a parse tree produced by the {@code type_bot}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitType_bot(scriptParser.Type_botContext ctx);
	/**
	 * Enter a parse tree produced by the {@code variable}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterVariable(scriptParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by the {@code variable}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitVariable(scriptParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by the {@code append}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAppend(scriptParser.AppendContext ctx);
	/**
	 * Exit a parse tree produced by the {@code append}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAppend(scriptParser.AppendContext ctx);
	/**
	 * Enter a parse tree produced by the {@code ifte}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterIfte(scriptParser.IfteContext ctx);
	/**
	 * Exit a parse tree produced by the {@code ifte}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitIfte(scriptParser.IfteContext ctx);
	/**
	 * Enter a parse tree produced by the {@code atom_string}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAtom_string(scriptParser.Atom_stringContext ctx);
	/**
	 * Exit a parse tree produced by the {@code atom_string}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAtom_string(scriptParser.Atom_stringContext ctx);
	/**
	 * Enter a parse tree produced by the {@code assign}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterAssign(scriptParser.AssignContext ctx);
	/**
	 * Exit a parse tree produced by the {@code assign}
	 * labeled alternative in {@link scriptParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitAssign(scriptParser.AssignContext ctx);
}