// Generated from /home/giacomo/projects/gsm2/antlr4/scriptv2/script.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class scriptParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, T__33=34, T__34=35, T__35=36, T__36=37, T__37=38, 
		T__38=39, T__39=40, T__40=41, T__41=42, T__42=43, T__43=44, VOID=45, BOT=46, 
		COERCE=47, ObjT=48, TYPEOF=49, SIGMA=50, ASSERT=51, STRINGT=52, LABELT=53, 
		DOUBLET=54, ANYT=55, BOOLT=56, INTT=57, START=58, KIND=59, LISTT=60, SUBTYPE=61, 
		ALPAREN=62, ARPAREN=63, LPAREN=64, RPAREN=65, BOOL=66, AND_TYPE=67, OR_TYPE=68, 
		FUN=69, NOT=70, IF=71, THEN=72, ELSE=73, REMOVE=74, FROM=75, LOG=76, POW=77, 
		SIN=78, COS=79, TAN=80, PHI=81, ELL=82, XI=83, INJ=84, OBJ=85, FLAT=86, 
		SELFX=87, VARPHI=88, CROSS=89, SCRIPT=90, GSQL=91, CREATEDB=92, VARNAME=93, 
		CREATE=94, ELECT=95, MAP=96, DISJOINT=97, FOLD=98, ENFORCE=99, EscapedString=100, 
		NUMBER=101, INTEGER=102, SPACE=103, COMMENT=104, LINE_COMMENT=105;
	public static final int
		RULE_script = 0, RULE_tuple_pair = 1, RULE_expr = 2;
	private static String[] makeRuleNames() {
		return new String[] {
			"script", "tuple_pair", "expr"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'>>'", "'('", "')'", "'+'", "'-'", "'/'", "'%'", "'*'", 
			"'++'", "'@'", "'&&'", "'||'", "'|'", "'=='", "'!='", "'<='", "'>='", 
			"':='", "'var('", "'eval('", "'=>'", "'sub('", "','", "':'", "'['", "']'", 
			"'[['", "']]'", "']:='", "'in'", "'t<'", "'->'", "'map('", "'select('", 
			"'filter('", "'rfold('", "'lfold('", "'|_'", "'_|'", "'|-'", "'-|'", 
			"'where'", "'as'", "'void'", null, "'coerce'", "'ObjT'", "'typeof'", 
			"'sigma'", "'assert'", "'string'", "'label'", "'double'", null, "'bool'", 
			"'int'", "'star'", "'kind'", "'listof'", "'<:'", "'<'", "'>'", "'{'", 
			"'}'", null, "'/\\'", "'\\/'", "'fun'", "'not'", "'if'", "'then'", "'else'", 
			"'remove'", "'from'", "'log'", "'pow'", "'sin'", "'cos'", "'tan'", "'phi'", 
			"'ell'", "'xi'", "'inj'", "'OBJ'", "'flat'", "'selfx'", "'varphi'", "'cross'", 
			"'script'", "'gsql'", "'CREATEDB'", null, "'CREATE'", "'ELECT'", "'MAP'", 
			"'DISJOINT'", "'FOLD'", "'enforce_subtype'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, "VOID", "BOT", 
			"COERCE", "ObjT", "TYPEOF", "SIGMA", "ASSERT", "STRINGT", "LABELT", "DOUBLET", 
			"ANYT", "BOOLT", "INTT", "START", "KIND", "LISTT", "SUBTYPE", "ALPAREN", 
			"ARPAREN", "LPAREN", "RPAREN", "BOOL", "AND_TYPE", "OR_TYPE", "FUN", 
			"NOT", "IF", "THEN", "ELSE", "REMOVE", "FROM", "LOG", "POW", "SIN", "COS", 
			"TAN", "PHI", "ELL", "XI", "INJ", "OBJ", "FLAT", "SELFX", "VARPHI", "CROSS", 
			"SCRIPT", "GSQL", "CREATEDB", "VARNAME", "CREATE", "ELECT", "MAP", "DISJOINT", 
			"FOLD", "ENFORCE", "EscapedString", "NUMBER", "INTEGER", "SPACE", "COMMENT", 
			"LINE_COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "script.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public scriptParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ScriptContext extends ParserRuleContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ScriptContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_script; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterScript(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitScript(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitScript(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ScriptContext script() throws RecognitionException {
		ScriptContext _localctx = new ScriptContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_script);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(11);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(6);
					expr(0);
					setState(7);
					match(T__0);
					}
					} 
				}
				setState(13);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			setState(14);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Tuple_pairContext extends ParserRuleContext {
		public TerminalNode EscapedString() { return getToken(scriptParser.EscapedString, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Tuple_pairContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_tuple_pair; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterTuple_pair(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitTuple_pair(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitTuple_pair(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Tuple_pairContext tuple_pair() throws RecognitionException {
		Tuple_pairContext _localctx = new Tuple_pairContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_tuple_pair);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(16);
			match(EscapedString);
			setState(17);
			match(T__1);
			setState(18);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CoerceContext extends ExprContext {
		public TerminalNode COERCE() { return getToken(scriptParser.COERCE, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public CoerceContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterCoerce(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitCoerce(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitCoerce(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarphiContext extends ExprContext {
		public TerminalNode VARPHI() { return getToken(scriptParser.VARPHI, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public VarphiContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterVarphi(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitVarphi(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitVarphi(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SelectContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public SelectContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterSelect(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitSelect(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitSelect(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ModContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ModContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterMod(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitMod(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitMod(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class MultContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public MultContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterMult(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitMult(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitMult(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class RfoldContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public RfoldContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterRfold(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitRfold(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitRfold(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CosContext extends ExprContext {
		public TerminalNode COS() { return getToken(scriptParser.COS, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public CosContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterCos(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitCos(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitCos(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LtContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode ALPAREN() { return getToken(scriptParser.ALPAREN, 0); }
		public LtContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterLt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitLt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitLt(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ProjectContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ProjectContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterProject(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitProject(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitProject(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PutContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public PutContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterPut(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitPut(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitPut(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class DivContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public DivContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterDiv(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitDiv(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitDiv(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FunctionContext extends ExprContext {
		public TerminalNode FUN() { return getToken(scriptParser.FUN, 0); }
		public TerminalNode VARNAME() { return getToken(scriptParser.VARNAME, 0); }
		public TerminalNode LPAREN() { return getToken(scriptParser.LPAREN, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(scriptParser.RPAREN, 0); }
		public FunctionContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterFunction(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitFunction(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitFunction(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SelfcrossContext extends ExprContext {
		public TerminalNode SELFX() { return getToken(scriptParser.SELFX, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public SelfcrossContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterSelfcross(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitSelfcross(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitSelfcross(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LeqContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public LeqContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterLeq(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitLeq(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitLeq(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_labelContext extends ExprContext {
		public TerminalNode LABELT() { return getToken(scriptParser.LABELT, 0); }
		public TerminalNode EscapedString() { return getToken(scriptParser.EscapedString, 0); }
		public Type_labelContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_label(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_label(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_label(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NeqContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public NeqContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterNeq(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitNeq(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitNeq(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TanContext extends ExprContext {
		public TerminalNode TAN() { return getToken(scriptParser.TAN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TanContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterTan(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitTan(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitTan(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AddContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public AddContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAdd(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAdd(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAdd(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Subtype_ofContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode SUBTYPE() { return getToken(scriptParser.SUBTYPE, 0); }
		public Subtype_ofContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterSubtype_of(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitSubtype_of(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitSubtype_of(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_boolContext extends ExprContext {
		public TerminalNode BOOLT() { return getToken(scriptParser.BOOLT, 0); }
		public Type_boolContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_bool(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_bool(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_bool(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EnsureContext extends ExprContext {
		public TerminalNode ASSERT() { return getToken(scriptParser.ASSERT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public EnsureContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterEnsure(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitEnsure(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitEnsure(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ImplyContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ImplyContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterImply(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitImply(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitImply(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EllContext extends ExprContext {
		public TerminalNode ELL() { return getToken(scriptParser.ELL, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public EllContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterEll(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitEll(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitEll(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VarContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public VarContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterVar(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitVar(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitVar(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class KindContext extends ExprContext {
		public TerminalNode START() { return getToken(scriptParser.START, 0); }
		public KindContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterKind(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitKind(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitKind(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Atom_boolContext extends ExprContext {
		public TerminalNode BOOL() { return getToken(scriptParser.BOOL, 0); }
		public Atom_boolContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAtom_bool(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAtom_bool(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAtom_bool(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CeilContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public CeilContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterCeil(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitCeil(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitCeil(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ConcatContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ConcatContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterConcat(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitConcat(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitConcat(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EqContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public EqContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterEq(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitEq(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitEq(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_tupleContext extends ExprContext {
		public List<Tuple_pairContext> tuple_pair() {
			return getRuleContexts(Tuple_pairContext.class);
		}
		public Tuple_pairContext tuple_pair(int i) {
			return getRuleContext(Tuple_pairContext.class,i);
		}
		public TerminalNode ARPAREN() { return getToken(scriptParser.ARPAREN, 0); }
		public Type_tupleContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_tuple(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_tuple(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_tuple(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_orContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode OR_TYPE() { return getToken(scriptParser.OR_TYPE, 0); }
		public Type_orContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_or(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_or(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_or(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_lexContext extends ExprContext {
		public TerminalNode ObjT() { return getToken(scriptParser.ObjT, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Type_lexContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_lex(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_lex(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_lex(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Sigma_typeContext extends ExprContext {
		public TerminalNode SIGMA() { return getToken(scriptParser.SIGMA, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Sigma_typeContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterSigma_type(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitSigma_type(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitSigma_type(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ContainsContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ContainsContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterContains(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitContains(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitContains(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EvalContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public EvalContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterEval(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitEval(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitEval(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Atom_numberContext extends ExprContext {
		public TerminalNode NUMBER() { return getToken(scriptParser.NUMBER, 0); }
		public Atom_numberContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAtom_number(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAtom_number(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAtom_number(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AtContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public AtContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAt(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NullContext extends ExprContext {
		public TerminalNode BOT() { return getToken(scriptParser.BOT, 0); }
		public NullContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterNull(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitNull(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitNull(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class EnforceContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode ENFORCE() { return getToken(scriptParser.ENFORCE, 0); }
		public EnforceContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterEnforce(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitEnforce(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitEnforce(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SubContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public SubContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterSub(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitSub(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitSub(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Atom_arrayContext extends ExprContext {
		public TerminalNode LPAREN() { return getToken(scriptParser.LPAREN, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(scriptParser.RPAREN, 0); }
		public Atom_arrayContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAtom_array(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAtom_array(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAtom_array(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LogContext extends ExprContext {
		public TerminalNode LOG() { return getToken(scriptParser.LOG, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public LogContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterLog(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitLog(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitLog(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class LfoldContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public LfoldContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterLfold(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitLfold(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitLfold(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SubstringContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public SubstringContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterSubstring(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitSubstring(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitSubstring(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class RemoveContext extends ExprContext {
		public TerminalNode REMOVE() { return getToken(scriptParser.REMOVE, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode FROM() { return getToken(scriptParser.FROM, 0); }
		public RemoveContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterRemove(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitRemove(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitRemove(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ParenContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ParenContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterParen(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitParen(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitParen(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class NotContext extends ExprContext {
		public TerminalNode NOT() { return getToken(scriptParser.NOT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public NotContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterNot(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitNot(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitNot(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_stringContext extends ExprContext {
		public TerminalNode STRINGT() { return getToken(scriptParser.STRINGT, 0); }
		public Type_stringContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_string(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_string(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_string(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_anyContext extends ExprContext {
		public TerminalNode ANYT() { return getToken(scriptParser.ANYT, 0); }
		public Type_anyContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_any(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_any(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_any(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class GeqContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public GeqContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterGeq(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitGeq(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitGeq(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FlatContext extends ExprContext {
		public TerminalNode FLAT() { return getToken(scriptParser.FLAT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public FlatContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterFlat(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitFlat(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitFlat(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AndContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public AndContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAnd(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAnd(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAnd(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PowContext extends ExprContext {
		public TerminalNode POW() { return getToken(scriptParser.POW, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public PowContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterPow(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitPow(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitPow(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class SinContext extends ExprContext {
		public TerminalNode SIN() { return getToken(scriptParser.SIN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public SinContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterSin(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitSin(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitSin(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FloorContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public FloorContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterFloor(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitFloor(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitFloor(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class MapContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public MapContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterMap(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitMap(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitMap(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class TypeofContext extends ExprContext {
		public TerminalNode TYPEOF() { return getToken(scriptParser.TYPEOF, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TypeofContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterTypeof(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitTypeof(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitTypeof(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_intContext extends ExprContext {
		public TerminalNode INTT() { return getToken(scriptParser.INTT, 0); }
		public Type_intContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_int(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_int(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_int(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class OrContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public OrContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterOr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitOr(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitOr(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class InjContext extends ExprContext {
		public TerminalNode INJ() { return getToken(scriptParser.INJ, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public InjContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterInj(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitInj(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitInj(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ApplyContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ApplyContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterApply(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitApply(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitApply(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_andContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode AND_TYPE() { return getToken(scriptParser.AND_TYPE, 0); }
		public Type_andContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_and(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_and(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_and(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class CrossContext extends ExprContext {
		public TerminalNode CROSS() { return getToken(scriptParser.CROSS, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public CrossContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterCross(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitCross(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitCross(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class GtContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode ARPAREN() { return getToken(scriptParser.ARPAREN, 0); }
		public GtContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterGt(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitGt(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitGt(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Atom_tupleContext extends ExprContext {
		public TerminalNode ALPAREN() { return getToken(scriptParser.ALPAREN, 0); }
		public List<Tuple_pairContext> tuple_pair() {
			return getRuleContexts(Tuple_pairContext.class);
		}
		public Tuple_pairContext tuple_pair(int i) {
			return getRuleContext(Tuple_pairContext.class,i);
		}
		public TerminalNode ARPAREN() { return getToken(scriptParser.ARPAREN, 0); }
		public Atom_tupleContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAtom_tuple(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAtom_tuple(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAtom_tuple(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_doubleContext extends ExprContext {
		public TerminalNode DOUBLET() { return getToken(scriptParser.DOUBLET, 0); }
		public Type_doubleContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_double(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_double(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_double(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FilterContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public FilterContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterFilter(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitFilter(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitFilter(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class PhiContext extends ExprContext {
		public TerminalNode PHI() { return getToken(scriptParser.PHI, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public PhiContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterPhi(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitPhi(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitPhi(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class XiContext extends ExprContext {
		public TerminalNode XI() { return getToken(scriptParser.XI, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public XiContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterXi(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitXi(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitXi(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_listContext extends ExprContext {
		public TerminalNode LISTT() { return getToken(scriptParser.LISTT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Type_listContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_list(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_list(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_list(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AbsContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AbsContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAbs(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAbs(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAbs(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ObjContext extends ExprContext {
		public TerminalNode OBJ() { return getToken(scriptParser.OBJ, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ObjContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterObj(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitObj(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitObj(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Type_botContext extends ExprContext {
		public TerminalNode VOID() { return getToken(scriptParser.VOID, 0); }
		public Type_botContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterType_bot(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitType_bot(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitType_bot(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ExprContext {
		public TerminalNode VARNAME() { return getToken(scriptParser.VARNAME, 0); }
		public VariableContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitVariable(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitVariable(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AppendContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public AppendContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAppend(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAppend(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAppend(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class IfteContext extends ExprContext {
		public TerminalNode IF() { return getToken(scriptParser.IF, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode THEN() { return getToken(scriptParser.THEN, 0); }
		public TerminalNode ELSE() { return getToken(scriptParser.ELSE, 0); }
		public IfteContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterIfte(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitIfte(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitIfte(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Atom_stringContext extends ExprContext {
		public TerminalNode EscapedString() { return getToken(scriptParser.EscapedString, 0); }
		public Atom_stringContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAtom_string(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAtom_string(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAtom_string(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class AssignContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public AssignContext(ExprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).enterAssign(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof scriptListener ) ((scriptListener)listener).exitAssign(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof scriptVisitor ) return ((scriptVisitor<? extends T>)visitor).visitAssign(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_expr, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(227);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				{
				_localctx = new ParenContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(21);
				match(T__2);
				setState(22);
				expr(0);
				setState(23);
				match(T__3);
				}
				break;
			case 2:
				{
				_localctx = new AbsContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(25);
				match(T__13);
				setState(26);
				expr(0);
				setState(27);
				match(T__13);
				}
				break;
			case 3:
				{
				_localctx = new ApplyContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(29);
				match(T__2);
				setState(30);
				expr(0);
				setState(31);
				expr(0);
				setState(32);
				match(T__3);
				}
				break;
			case 4:
				{
				_localctx = new VarContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(34);
				match(T__19);
				setState(35);
				expr(0);
				setState(36);
				match(T__3);
				}
				break;
			case 5:
				{
				_localctx = new EvalContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(38);
				match(T__20);
				setState(39);
				expr(0);
				setState(40);
				match(T__3);
				}
				break;
			case 6:
				{
				_localctx = new NotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(42);
				match(NOT);
				setState(43);
				expr(57);
				}
				break;
			case 7:
				{
				_localctx = new IfteContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(44);
				match(IF);
				setState(45);
				expr(0);
				setState(46);
				match(THEN);
				setState(47);
				expr(0);
				setState(48);
				match(ELSE);
				setState(49);
				expr(55);
				}
				break;
			case 8:
				{
				_localctx = new SubstringContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(51);
				match(T__22);
				setState(52);
				expr(0);
				setState(53);
				match(T__23);
				setState(54);
				expr(0);
				setState(55);
				match(T__24);
				setState(56);
				expr(0);
				setState(57);
				match(T__3);
				}
				break;
			case 9:
				{
				_localctx = new RemoveContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(59);
				match(REMOVE);
				setState(60);
				expr(0);
				setState(61);
				match(FROM);
				setState(62);
				expr(49);
				}
				break;
			case 10:
				{
				_localctx = new Atom_numberContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(64);
				match(NUMBER);
				}
				break;
			case 11:
				{
				_localctx = new Atom_boolContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(65);
				match(BOOL);
				}
				break;
			case 12:
				{
				_localctx = new Atom_stringContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(66);
				match(EscapedString);
				}
				break;
			case 13:
				{
				_localctx = new NullContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(67);
				match(BOT);
				}
				break;
			case 14:
				{
				_localctx = new Type_stringContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(68);
				match(STRINGT);
				}
				break;
			case 15:
				{
				_localctx = new Type_boolContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(69);
				match(BOOLT);
				}
				break;
			case 16:
				{
				_localctx = new Type_intContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(70);
				match(INTT);
				}
				break;
			case 17:
				{
				_localctx = new Type_doubleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(71);
				match(DOUBLET);
				}
				break;
			case 18:
				{
				_localctx = new Type_listContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(72);
				match(LISTT);
				setState(73);
				expr(38);
				}
				break;
			case 19:
				{
				_localctx = new Type_tupleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(74);
				match(T__31);
				setState(80);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(75);
						tuple_pair();
						setState(76);
						match(T__0);
						}
						} 
					}
					setState(82);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,1,_ctx);
				}
				setState(83);
				tuple_pair();
				setState(84);
				match(ARPAREN);
				}
				break;
			case 20:
				{
				_localctx = new Type_anyContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(86);
				match(ANYT);
				}
				break;
			case 21:
				{
				_localctx = new Type_botContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(87);
				match(VOID);
				}
				break;
			case 22:
				{
				_localctx = new Type_labelContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(88);
				match(LABELT);
				setState(89);
				match(EscapedString);
				}
				break;
			case 23:
				{
				_localctx = new Type_lexContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(90);
				match(ObjT);
				setState(91);
				expr(0);
				setState(92);
				expr(33);
				}
				break;
			case 24:
				{
				_localctx = new Atom_arrayContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(94);
				match(LPAREN);
				setState(100);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(95);
						expr(0);
						setState(96);
						match(T__0);
						}
						} 
					}
					setState(102);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
				}
				setState(103);
				expr(0);
				setState(104);
				match(RPAREN);
				}
				break;
			case 25:
				{
				_localctx = new KindContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(106);
				match(START);
				}
				break;
			case 26:
				{
				_localctx = new Atom_tupleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(107);
				match(ALPAREN);
				setState(113);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(108);
						tuple_pair();
						setState(109);
						match(T__0);
						}
						} 
					}
					setState(115);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
				}
				setState(116);
				tuple_pair();
				setState(117);
				match(ARPAREN);
				}
				break;
			case 27:
				{
				_localctx = new FunctionContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(119);
				match(FUN);
				setState(120);
				match(VARNAME);
				setState(121);
				match(T__32);
				setState(122);
				match(LPAREN);
				setState(128);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(123);
						expr(0);
						setState(124);
						match(T__0);
						}
						} 
					}
					setState(130);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
				}
				setState(131);
				expr(0);
				setState(132);
				match(RPAREN);
				}
				break;
			case 28:
				{
				_localctx = new VariableContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(134);
				match(VARNAME);
				}
				break;
			case 29:
				{
				_localctx = new MapContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(135);
				match(T__33);
				setState(136);
				expr(0);
				setState(137);
				match(T__24);
				setState(138);
				expr(0);
				setState(139);
				match(T__3);
				}
				break;
			case 30:
				{
				_localctx = new SelectContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(141);
				match(T__34);
				setState(142);
				expr(0);
				setState(143);
				match(T__24);
				setState(144);
				expr(0);
				setState(145);
				match(T__3);
				}
				break;
			case 31:
				{
				_localctx = new FilterContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(147);
				match(T__35);
				setState(148);
				expr(0);
				setState(149);
				match(T__24);
				setState(150);
				expr(0);
				setState(151);
				match(T__3);
				}
				break;
			case 32:
				{
				_localctx = new RfoldContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(153);
				match(T__36);
				setState(154);
				expr(0);
				setState(155);
				match(T__23);
				setState(156);
				expr(0);
				setState(157);
				match(T__24);
				setState(158);
				expr(0);
				setState(159);
				match(T__3);
				}
				break;
			case 33:
				{
				_localctx = new LfoldContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(161);
				match(T__37);
				setState(162);
				expr(0);
				setState(163);
				match(T__23);
				setState(164);
				expr(0);
				setState(165);
				match(T__24);
				setState(166);
				expr(0);
				setState(167);
				match(T__3);
				}
				break;
			case 34:
				{
				_localctx = new LogContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(169);
				match(LOG);
				setState(170);
				expr(0);
				setState(171);
				expr(22);
				}
				break;
			case 35:
				{
				_localctx = new PowContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(173);
				match(POW);
				setState(174);
				expr(0);
				setState(175);
				expr(21);
				}
				break;
			case 36:
				{
				_localctx = new SinContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(177);
				match(SIN);
				setState(178);
				expr(20);
				}
				break;
			case 37:
				{
				_localctx = new CosContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(179);
				match(COS);
				setState(180);
				expr(19);
				}
				break;
			case 38:
				{
				_localctx = new TanContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(181);
				match(TAN);
				setState(182);
				expr(18);
				}
				break;
			case 39:
				{
				_localctx = new FloorContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(183);
				match(T__38);
				setState(184);
				expr(0);
				setState(185);
				match(T__39);
				}
				break;
			case 40:
				{
				_localctx = new CeilContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(187);
				match(T__40);
				setState(188);
				expr(0);
				setState(189);
				match(T__41);
				}
				break;
			case 41:
				{
				_localctx = new PhiContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(191);
				match(PHI);
				setState(192);
				expr(0);
				setState(193);
				expr(15);
				}
				break;
			case 42:
				{
				_localctx = new EllContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(195);
				match(ELL);
				setState(196);
				expr(14);
				}
				break;
			case 43:
				{
				_localctx = new XiContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(197);
				match(XI);
				setState(198);
				expr(13);
				}
				break;
			case 44:
				{
				_localctx = new InjContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(199);
				match(INJ);
				setState(200);
				expr(12);
				}
				break;
			case 45:
				{
				_localctx = new ObjContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(201);
				match(OBJ);
				setState(202);
				expr(11);
				}
				break;
			case 46:
				{
				_localctx = new FlatContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(203);
				match(FLAT);
				setState(204);
				expr(10);
				}
				break;
			case 47:
				{
				_localctx = new CrossContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(205);
				match(CROSS);
				setState(206);
				expr(0);
				setState(207);
				expr(9);
				}
				break;
			case 48:
				{
				_localctx = new SelfcrossContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(209);
				match(SELFX);
				setState(210);
				expr(8);
				}
				break;
			case 49:
				{
				_localctx = new VarphiContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(211);
				match(VARPHI);
				setState(212);
				expr(7);
				}
				break;
			case 50:
				{
				_localctx = new TypeofContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(213);
				match(TYPEOF);
				setState(214);
				expr(6);
				}
				break;
			case 51:
				{
				_localctx = new Sigma_typeContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(215);
				match(SIGMA);
				setState(216);
				expr(0);
				setState(217);
				match(T__42);
				setState(218);
				expr(5);
				}
				break;
			case 52:
				{
				_localctx = new EnsureContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(220);
				match(ASSERT);
				setState(221);
				expr(3);
				}
				break;
			case 53:
				{
				_localctx = new CoerceContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(222);
				match(COERCE);
				setState(223);
				expr(0);
				setState(224);
				match(T__43);
				setState(225);
				expr(1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(313);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(311);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
					case 1:
						{
						_localctx = new AddContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(229);
						if (!(precpred(_ctx, 77))) throw new FailedPredicateException(this, "precpred(_ctx, 77)");
						setState(230);
						match(T__4);
						setState(231);
						expr(78);
						}
						break;
					case 2:
						{
						_localctx = new SubContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(232);
						if (!(precpred(_ctx, 76))) throw new FailedPredicateException(this, "precpred(_ctx, 76)");
						setState(233);
						match(T__5);
						setState(234);
						expr(77);
						}
						break;
					case 3:
						{
						_localctx = new DivContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(235);
						if (!(precpred(_ctx, 75))) throw new FailedPredicateException(this, "precpred(_ctx, 75)");
						setState(236);
						match(T__6);
						setState(237);
						expr(76);
						}
						break;
					case 4:
						{
						_localctx = new ModContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(238);
						if (!(precpred(_ctx, 74))) throw new FailedPredicateException(this, "precpred(_ctx, 74)");
						setState(239);
						match(T__7);
						setState(240);
						expr(75);
						}
						break;
					case 5:
						{
						_localctx = new MultContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(241);
						if (!(precpred(_ctx, 73))) throw new FailedPredicateException(this, "precpred(_ctx, 73)");
						setState(242);
						match(T__8);
						setState(243);
						expr(74);
						}
						break;
					case 6:
						{
						_localctx = new ConcatContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(244);
						if (!(precpred(_ctx, 72))) throw new FailedPredicateException(this, "precpred(_ctx, 72)");
						setState(245);
						match(T__9);
						setState(246);
						expr(73);
						}
						break;
					case 7:
						{
						_localctx = new AppendContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(247);
						if (!(precpred(_ctx, 71))) throw new FailedPredicateException(this, "precpred(_ctx, 71)");
						setState(248);
						match(T__10);
						setState(249);
						expr(72);
						}
						break;
					case 8:
						{
						_localctx = new AndContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(250);
						if (!(precpred(_ctx, 70))) throw new FailedPredicateException(this, "precpred(_ctx, 70)");
						setState(251);
						match(T__11);
						setState(252);
						expr(71);
						}
						break;
					case 9:
						{
						_localctx = new OrContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(253);
						if (!(precpred(_ctx, 69))) throw new FailedPredicateException(this, "precpred(_ctx, 69)");
						setState(254);
						match(T__12);
						setState(255);
						expr(70);
						}
						break;
					case 10:
						{
						_localctx = new EqContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(256);
						if (!(precpred(_ctx, 67))) throw new FailedPredicateException(this, "precpred(_ctx, 67)");
						setState(257);
						match(T__14);
						setState(258);
						expr(68);
						}
						break;
					case 11:
						{
						_localctx = new NeqContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(259);
						if (!(precpred(_ctx, 66))) throw new FailedPredicateException(this, "precpred(_ctx, 66)");
						setState(260);
						match(T__15);
						setState(261);
						expr(67);
						}
						break;
					case 12:
						{
						_localctx = new LeqContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(262);
						if (!(precpred(_ctx, 65))) throw new FailedPredicateException(this, "precpred(_ctx, 65)");
						setState(263);
						match(T__16);
						setState(264);
						expr(66);
						}
						break;
					case 13:
						{
						_localctx = new GeqContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(265);
						if (!(precpred(_ctx, 64))) throw new FailedPredicateException(this, "precpred(_ctx, 64)");
						setState(266);
						match(T__17);
						setState(267);
						expr(65);
						}
						break;
					case 14:
						{
						_localctx = new GtContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(268);
						if (!(precpred(_ctx, 63))) throw new FailedPredicateException(this, "precpred(_ctx, 63)");
						setState(269);
						match(ARPAREN);
						setState(270);
						expr(64);
						}
						break;
					case 15:
						{
						_localctx = new LtContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(271);
						if (!(precpred(_ctx, 62))) throw new FailedPredicateException(this, "precpred(_ctx, 62)");
						setState(272);
						match(ALPAREN);
						setState(273);
						expr(63);
						}
						break;
					case 16:
						{
						_localctx = new AssignContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(274);
						if (!(precpred(_ctx, 61))) throw new FailedPredicateException(this, "precpred(_ctx, 61)");
						setState(275);
						match(T__18);
						setState(276);
						expr(62);
						}
						break;
					case 17:
						{
						_localctx = new ImplyContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(277);
						if (!(precpred(_ctx, 56))) throw new FailedPredicateException(this, "precpred(_ctx, 56)");
						setState(278);
						match(T__21);
						setState(279);
						expr(57);
						}
						break;
					case 18:
						{
						_localctx = new PutContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(280);
						if (!(precpred(_ctx, 51))) throw new FailedPredicateException(this, "precpred(_ctx, 51)");
						setState(281);
						match(T__25);
						setState(282);
						expr(0);
						setState(283);
						match(T__29);
						setState(284);
						expr(52);
						}
						break;
					case 19:
						{
						_localctx = new ContainsContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(286);
						if (!(precpred(_ctx, 50))) throw new FailedPredicateException(this, "precpred(_ctx, 50)");
						setState(287);
						match(T__30);
						setState(288);
						expr(51);
						}
						break;
					case 20:
						{
						_localctx = new Type_andContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(289);
						if (!(precpred(_ctx, 40))) throw new FailedPredicateException(this, "precpred(_ctx, 40)");
						setState(290);
						match(AND_TYPE);
						setState(291);
						expr(41);
						}
						break;
					case 21:
						{
						_localctx = new Type_orContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(292);
						if (!(precpred(_ctx, 39))) throw new FailedPredicateException(this, "precpred(_ctx, 39)");
						setState(293);
						match(OR_TYPE);
						setState(294);
						expr(40);
						}
						break;
					case 22:
						{
						_localctx = new Subtype_ofContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(295);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(296);
						match(SUBTYPE);
						setState(297);
						expr(5);
						}
						break;
					case 23:
						{
						_localctx = new EnforceContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(298);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(299);
						match(ENFORCE);
						setState(300);
						expr(3);
						}
						break;
					case 24:
						{
						_localctx = new AtContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(301);
						if (!(precpred(_ctx, 53))) throw new FailedPredicateException(this, "precpred(_ctx, 53)");
						setState(302);
						match(T__25);
						setState(303);
						expr(0);
						setState(304);
						match(T__26);
						}
						break;
					case 25:
						{
						_localctx = new ProjectContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(306);
						if (!(precpred(_ctx, 52))) throw new FailedPredicateException(this, "precpred(_ctx, 52)");
						setState(307);
						match(T__27);
						setState(308);
						expr(0);
						setState(309);
						match(T__28);
						}
						break;
					}
					} 
				}
				setState(315);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 2:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 77);
		case 1:
			return precpred(_ctx, 76);
		case 2:
			return precpred(_ctx, 75);
		case 3:
			return precpred(_ctx, 74);
		case 4:
			return precpred(_ctx, 73);
		case 5:
			return precpred(_ctx, 72);
		case 6:
			return precpred(_ctx, 71);
		case 7:
			return precpred(_ctx, 70);
		case 8:
			return precpred(_ctx, 69);
		case 9:
			return precpred(_ctx, 67);
		case 10:
			return precpred(_ctx, 66);
		case 11:
			return precpred(_ctx, 65);
		case 12:
			return precpred(_ctx, 64);
		case 13:
			return precpred(_ctx, 63);
		case 14:
			return precpred(_ctx, 62);
		case 15:
			return precpred(_ctx, 61);
		case 16:
			return precpred(_ctx, 56);
		case 17:
			return precpred(_ctx, 51);
		case 18:
			return precpred(_ctx, 50);
		case 19:
			return precpred(_ctx, 40);
		case 20:
			return precpred(_ctx, 39);
		case 21:
			return precpred(_ctx, 4);
		case 22:
			return precpred(_ctx, 2);
		case 23:
			return precpred(_ctx, 53);
		case 24:
			return precpred(_ctx, 52);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001i\u013d\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0001\u0000\u0001\u0000\u0001\u0000\u0005\u0000\n\b"+
		"\u0000\n\u0000\f\u0000\r\t\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0005\u0002O\b\u0002\n\u0002\f\u0002R\t\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0005\u0002c\b\u0002\n\u0002\f\u0002f\t\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0005\u0002p\b\u0002\n\u0002\f\u0002s\t\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002\u007f\b\u0002\n"+
		"\u0002\f\u0002\u0082\t\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0003\u0002\u00e4\b\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0005\u0002\u0138\b\u0002\n\u0002\f\u0002"+
		"\u013b\t\u0002\u0001\u0002\u0000\u0001\u0004\u0003\u0000\u0002\u0004\u0000"+
		"\u0000\u018b\u0000\u000b\u0001\u0000\u0000\u0000\u0002\u0010\u0001\u0000"+
		"\u0000\u0000\u0004\u00e3\u0001\u0000\u0000\u0000\u0006\u0007\u0003\u0004"+
		"\u0002\u0000\u0007\b\u0005\u0001\u0000\u0000\b\n\u0001\u0000\u0000\u0000"+
		"\t\u0006\u0001\u0000\u0000\u0000\n\r\u0001\u0000\u0000\u0000\u000b\t\u0001"+
		"\u0000\u0000\u0000\u000b\f\u0001\u0000\u0000\u0000\f\u000e\u0001\u0000"+
		"\u0000\u0000\r\u000b\u0001\u0000\u0000\u0000\u000e\u000f\u0003\u0004\u0002"+
		"\u0000\u000f\u0001\u0001\u0000\u0000\u0000\u0010\u0011\u0005d\u0000\u0000"+
		"\u0011\u0012\u0005\u0002\u0000\u0000\u0012\u0013\u0003\u0004\u0002\u0000"+
		"\u0013\u0003\u0001\u0000\u0000\u0000\u0014\u0015\u0006\u0002\uffff\uffff"+
		"\u0000\u0015\u0016\u0005\u0003\u0000\u0000\u0016\u0017\u0003\u0004\u0002"+
		"\u0000\u0017\u0018\u0005\u0004\u0000\u0000\u0018\u00e4\u0001\u0000\u0000"+
		"\u0000\u0019\u001a\u0005\u000e\u0000\u0000\u001a\u001b\u0003\u0004\u0002"+
		"\u0000\u001b\u001c\u0005\u000e\u0000\u0000\u001c\u00e4\u0001\u0000\u0000"+
		"\u0000\u001d\u001e\u0005\u0003\u0000\u0000\u001e\u001f\u0003\u0004\u0002"+
		"\u0000\u001f \u0003\u0004\u0002\u0000 !\u0005\u0004\u0000\u0000!\u00e4"+
		"\u0001\u0000\u0000\u0000\"#\u0005\u0014\u0000\u0000#$\u0003\u0004\u0002"+
		"\u0000$%\u0005\u0004\u0000\u0000%\u00e4\u0001\u0000\u0000\u0000&\'\u0005"+
		"\u0015\u0000\u0000\'(\u0003\u0004\u0002\u0000()\u0005\u0004\u0000\u0000"+
		")\u00e4\u0001\u0000\u0000\u0000*+\u0005F\u0000\u0000+\u00e4\u0003\u0004"+
		"\u00029,-\u0005G\u0000\u0000-.\u0003\u0004\u0002\u0000./\u0005H\u0000"+
		"\u0000/0\u0003\u0004\u0002\u000001\u0005I\u0000\u000012\u0003\u0004\u0002"+
		"72\u00e4\u0001\u0000\u0000\u000034\u0005\u0017\u0000\u000045\u0003\u0004"+
		"\u0002\u000056\u0005\u0018\u0000\u000067\u0003\u0004\u0002\u000078\u0005"+
		"\u0019\u0000\u000089\u0003\u0004\u0002\u00009:\u0005\u0004\u0000\u0000"+
		":\u00e4\u0001\u0000\u0000\u0000;<\u0005J\u0000\u0000<=\u0003\u0004\u0002"+
		"\u0000=>\u0005K\u0000\u0000>?\u0003\u0004\u00021?\u00e4\u0001\u0000\u0000"+
		"\u0000@\u00e4\u0005e\u0000\u0000A\u00e4\u0005B\u0000\u0000B\u00e4\u0005"+
		"d\u0000\u0000C\u00e4\u0005.\u0000\u0000D\u00e4\u00054\u0000\u0000E\u00e4"+
		"\u00058\u0000\u0000F\u00e4\u00059\u0000\u0000G\u00e4\u00056\u0000\u0000"+
		"HI\u0005<\u0000\u0000I\u00e4\u0003\u0004\u0002&JP\u0005 \u0000\u0000K"+
		"L\u0003\u0002\u0001\u0000LM\u0005\u0001\u0000\u0000MO\u0001\u0000\u0000"+
		"\u0000NK\u0001\u0000\u0000\u0000OR\u0001\u0000\u0000\u0000PN\u0001\u0000"+
		"\u0000\u0000PQ\u0001\u0000\u0000\u0000QS\u0001\u0000\u0000\u0000RP\u0001"+
		"\u0000\u0000\u0000ST\u0003\u0002\u0001\u0000TU\u0005?\u0000\u0000U\u00e4"+
		"\u0001\u0000\u0000\u0000V\u00e4\u00057\u0000\u0000W\u00e4\u0005-\u0000"+
		"\u0000XY\u00055\u0000\u0000Y\u00e4\u0005d\u0000\u0000Z[\u00050\u0000\u0000"+
		"[\\\u0003\u0004\u0002\u0000\\]\u0003\u0004\u0002!]\u00e4\u0001\u0000\u0000"+
		"\u0000^d\u0005@\u0000\u0000_`\u0003\u0004\u0002\u0000`a\u0005\u0001\u0000"+
		"\u0000ac\u0001\u0000\u0000\u0000b_\u0001\u0000\u0000\u0000cf\u0001\u0000"+
		"\u0000\u0000db\u0001\u0000\u0000\u0000de\u0001\u0000\u0000\u0000eg\u0001"+
		"\u0000\u0000\u0000fd\u0001\u0000\u0000\u0000gh\u0003\u0004\u0002\u0000"+
		"hi\u0005A\u0000\u0000i\u00e4\u0001\u0000\u0000\u0000j\u00e4\u0005:\u0000"+
		"\u0000kq\u0005>\u0000\u0000lm\u0003\u0002\u0001\u0000mn\u0005\u0001\u0000"+
		"\u0000np\u0001\u0000\u0000\u0000ol\u0001\u0000\u0000\u0000ps\u0001\u0000"+
		"\u0000\u0000qo\u0001\u0000\u0000\u0000qr\u0001\u0000\u0000\u0000rt\u0001"+
		"\u0000\u0000\u0000sq\u0001\u0000\u0000\u0000tu\u0003\u0002\u0001\u0000"+
		"uv\u0005?\u0000\u0000v\u00e4\u0001\u0000\u0000\u0000wx\u0005E\u0000\u0000"+
		"xy\u0005]\u0000\u0000yz\u0005!\u0000\u0000z\u0080\u0005@\u0000\u0000{"+
		"|\u0003\u0004\u0002\u0000|}\u0005\u0001\u0000\u0000}\u007f\u0001\u0000"+
		"\u0000\u0000~{\u0001\u0000\u0000\u0000\u007f\u0082\u0001\u0000\u0000\u0000"+
		"\u0080~\u0001\u0000\u0000\u0000\u0080\u0081\u0001\u0000\u0000\u0000\u0081"+
		"\u0083\u0001\u0000\u0000\u0000\u0082\u0080\u0001\u0000\u0000\u0000\u0083"+
		"\u0084\u0003\u0004\u0002\u0000\u0084\u0085\u0005A\u0000\u0000\u0085\u00e4"+
		"\u0001\u0000\u0000\u0000\u0086\u00e4\u0005]\u0000\u0000\u0087\u0088\u0005"+
		"\"\u0000\u0000\u0088\u0089\u0003\u0004\u0002\u0000\u0089\u008a\u0005\u0019"+
		"\u0000\u0000\u008a\u008b\u0003\u0004\u0002\u0000\u008b\u008c\u0005\u0004"+
		"\u0000\u0000\u008c\u00e4\u0001\u0000\u0000\u0000\u008d\u008e\u0005#\u0000"+
		"\u0000\u008e\u008f\u0003\u0004\u0002\u0000\u008f\u0090\u0005\u0019\u0000"+
		"\u0000\u0090\u0091\u0003\u0004\u0002\u0000\u0091\u0092\u0005\u0004\u0000"+
		"\u0000\u0092\u00e4\u0001\u0000\u0000\u0000\u0093\u0094\u0005$\u0000\u0000"+
		"\u0094\u0095\u0003\u0004\u0002\u0000\u0095\u0096\u0005\u0019\u0000\u0000"+
		"\u0096\u0097\u0003\u0004\u0002\u0000\u0097\u0098\u0005\u0004\u0000\u0000"+
		"\u0098\u00e4\u0001\u0000\u0000\u0000\u0099\u009a\u0005%\u0000\u0000\u009a"+
		"\u009b\u0003\u0004\u0002\u0000\u009b\u009c\u0005\u0018\u0000\u0000\u009c"+
		"\u009d\u0003\u0004\u0002\u0000\u009d\u009e\u0005\u0019\u0000\u0000\u009e"+
		"\u009f\u0003\u0004\u0002\u0000\u009f\u00a0\u0005\u0004\u0000\u0000\u00a0"+
		"\u00e4\u0001\u0000\u0000\u0000\u00a1\u00a2\u0005&\u0000\u0000\u00a2\u00a3"+
		"\u0003\u0004\u0002\u0000\u00a3\u00a4\u0005\u0018\u0000\u0000\u00a4\u00a5"+
		"\u0003\u0004\u0002\u0000\u00a5\u00a6\u0005\u0019\u0000\u0000\u00a6\u00a7"+
		"\u0003\u0004\u0002\u0000\u00a7\u00a8\u0005\u0004\u0000\u0000\u00a8\u00e4"+
		"\u0001\u0000\u0000\u0000\u00a9\u00aa\u0005L\u0000\u0000\u00aa\u00ab\u0003"+
		"\u0004\u0002\u0000\u00ab\u00ac\u0003\u0004\u0002\u0016\u00ac\u00e4\u0001"+
		"\u0000\u0000\u0000\u00ad\u00ae\u0005M\u0000\u0000\u00ae\u00af\u0003\u0004"+
		"\u0002\u0000\u00af\u00b0\u0003\u0004\u0002\u0015\u00b0\u00e4\u0001\u0000"+
		"\u0000\u0000\u00b1\u00b2\u0005N\u0000\u0000\u00b2\u00e4\u0003\u0004\u0002"+
		"\u0014\u00b3\u00b4\u0005O\u0000\u0000\u00b4\u00e4\u0003\u0004\u0002\u0013"+
		"\u00b5\u00b6\u0005P\u0000\u0000\u00b6\u00e4\u0003\u0004\u0002\u0012\u00b7"+
		"\u00b8\u0005\'\u0000\u0000\u00b8\u00b9\u0003\u0004\u0002\u0000\u00b9\u00ba"+
		"\u0005(\u0000\u0000\u00ba\u00e4\u0001\u0000\u0000\u0000\u00bb\u00bc\u0005"+
		")\u0000\u0000\u00bc\u00bd\u0003\u0004\u0002\u0000\u00bd\u00be\u0005*\u0000"+
		"\u0000\u00be\u00e4\u0001\u0000\u0000\u0000\u00bf\u00c0\u0005Q\u0000\u0000"+
		"\u00c0\u00c1\u0003\u0004\u0002\u0000\u00c1\u00c2\u0003\u0004\u0002\u000f"+
		"\u00c2\u00e4\u0001\u0000\u0000\u0000\u00c3\u00c4\u0005R\u0000\u0000\u00c4"+
		"\u00e4\u0003\u0004\u0002\u000e\u00c5\u00c6\u0005S\u0000\u0000\u00c6\u00e4"+
		"\u0003\u0004\u0002\r\u00c7\u00c8\u0005T\u0000\u0000\u00c8\u00e4\u0003"+
		"\u0004\u0002\f\u00c9\u00ca\u0005U\u0000\u0000\u00ca\u00e4\u0003\u0004"+
		"\u0002\u000b\u00cb\u00cc\u0005V\u0000\u0000\u00cc\u00e4\u0003\u0004\u0002"+
		"\n\u00cd\u00ce\u0005Y\u0000\u0000\u00ce\u00cf\u0003\u0004\u0002\u0000"+
		"\u00cf\u00d0\u0003\u0004\u0002\t\u00d0\u00e4\u0001\u0000\u0000\u0000\u00d1"+
		"\u00d2\u0005W\u0000\u0000\u00d2\u00e4\u0003\u0004\u0002\b\u00d3\u00d4"+
		"\u0005X\u0000\u0000\u00d4\u00e4\u0003\u0004\u0002\u0007\u00d5\u00d6\u0005"+
		"1\u0000\u0000\u00d6\u00e4\u0003\u0004\u0002\u0006\u00d7\u00d8\u00052\u0000"+
		"\u0000\u00d8\u00d9\u0003\u0004\u0002\u0000\u00d9\u00da\u0005+\u0000\u0000"+
		"\u00da\u00db\u0003\u0004\u0002\u0005\u00db\u00e4\u0001\u0000\u0000\u0000"+
		"\u00dc\u00dd\u00053\u0000\u0000\u00dd\u00e4\u0003\u0004\u0002\u0003\u00de"+
		"\u00df\u0005/\u0000\u0000\u00df\u00e0\u0003\u0004\u0002\u0000\u00e0\u00e1"+
		"\u0005,\u0000\u0000\u00e1\u00e2\u0003\u0004\u0002\u0001\u00e2\u00e4\u0001"+
		"\u0000\u0000\u0000\u00e3\u0014\u0001\u0000\u0000\u0000\u00e3\u0019\u0001"+
		"\u0000\u0000\u0000\u00e3\u001d\u0001\u0000\u0000\u0000\u00e3\"\u0001\u0000"+
		"\u0000\u0000\u00e3&\u0001\u0000\u0000\u0000\u00e3*\u0001\u0000\u0000\u0000"+
		"\u00e3,\u0001\u0000\u0000\u0000\u00e33\u0001\u0000\u0000\u0000\u00e3;"+
		"\u0001\u0000\u0000\u0000\u00e3@\u0001\u0000\u0000\u0000\u00e3A\u0001\u0000"+
		"\u0000\u0000\u00e3B\u0001\u0000\u0000\u0000\u00e3C\u0001\u0000\u0000\u0000"+
		"\u00e3D\u0001\u0000\u0000\u0000\u00e3E\u0001\u0000\u0000\u0000\u00e3F"+
		"\u0001\u0000\u0000\u0000\u00e3G\u0001\u0000\u0000\u0000\u00e3H\u0001\u0000"+
		"\u0000\u0000\u00e3J\u0001\u0000\u0000\u0000\u00e3V\u0001\u0000\u0000\u0000"+
		"\u00e3W\u0001\u0000\u0000\u0000\u00e3X\u0001\u0000\u0000\u0000\u00e3Z"+
		"\u0001\u0000\u0000\u0000\u00e3^\u0001\u0000\u0000\u0000\u00e3j\u0001\u0000"+
		"\u0000\u0000\u00e3k\u0001\u0000\u0000\u0000\u00e3w\u0001\u0000\u0000\u0000"+
		"\u00e3\u0086\u0001\u0000\u0000\u0000\u00e3\u0087\u0001\u0000\u0000\u0000"+
		"\u00e3\u008d\u0001\u0000\u0000\u0000\u00e3\u0093\u0001\u0000\u0000\u0000"+
		"\u00e3\u0099\u0001\u0000\u0000\u0000\u00e3\u00a1\u0001\u0000\u0000\u0000"+
		"\u00e3\u00a9\u0001\u0000\u0000\u0000\u00e3\u00ad\u0001\u0000\u0000\u0000"+
		"\u00e3\u00b1\u0001\u0000\u0000\u0000\u00e3\u00b3\u0001\u0000\u0000\u0000"+
		"\u00e3\u00b5\u0001\u0000\u0000\u0000\u00e3\u00b7\u0001\u0000\u0000\u0000"+
		"\u00e3\u00bb\u0001\u0000\u0000\u0000\u00e3\u00bf\u0001\u0000\u0000\u0000"+
		"\u00e3\u00c3\u0001\u0000\u0000\u0000\u00e3\u00c5\u0001\u0000\u0000\u0000"+
		"\u00e3\u00c7\u0001\u0000\u0000\u0000\u00e3\u00c9\u0001\u0000\u0000\u0000"+
		"\u00e3\u00cb\u0001\u0000\u0000\u0000\u00e3\u00cd\u0001\u0000\u0000\u0000"+
		"\u00e3\u00d1\u0001\u0000\u0000\u0000\u00e3\u00d3\u0001\u0000\u0000\u0000"+
		"\u00e3\u00d5\u0001\u0000\u0000\u0000\u00e3\u00d7\u0001\u0000\u0000\u0000"+
		"\u00e3\u00dc\u0001\u0000\u0000\u0000\u00e3\u00de\u0001\u0000\u0000\u0000"+
		"\u00e4\u0139\u0001\u0000\u0000\u0000\u00e5\u00e6\nM\u0000\u0000\u00e6"+
		"\u00e7\u0005\u0005\u0000\u0000\u00e7\u0138\u0003\u0004\u0002N\u00e8\u00e9"+
		"\nL\u0000\u0000\u00e9\u00ea\u0005\u0006\u0000\u0000\u00ea\u0138\u0003"+
		"\u0004\u0002M\u00eb\u00ec\nK\u0000\u0000\u00ec\u00ed\u0005\u0007\u0000"+
		"\u0000\u00ed\u0138\u0003\u0004\u0002L\u00ee\u00ef\nJ\u0000\u0000\u00ef"+
		"\u00f0\u0005\b\u0000\u0000\u00f0\u0138\u0003\u0004\u0002K\u00f1\u00f2"+
		"\nI\u0000\u0000\u00f2\u00f3\u0005\t\u0000\u0000\u00f3\u0138\u0003\u0004"+
		"\u0002J\u00f4\u00f5\nH\u0000\u0000\u00f5\u00f6\u0005\n\u0000\u0000\u00f6"+
		"\u0138\u0003\u0004\u0002I\u00f7\u00f8\nG\u0000\u0000\u00f8\u00f9\u0005"+
		"\u000b\u0000\u0000\u00f9\u0138\u0003\u0004\u0002H\u00fa\u00fb\nF\u0000"+
		"\u0000\u00fb\u00fc\u0005\f\u0000\u0000\u00fc\u0138\u0003\u0004\u0002G"+
		"\u00fd\u00fe\nE\u0000\u0000\u00fe\u00ff\u0005\r\u0000\u0000\u00ff\u0138"+
		"\u0003\u0004\u0002F\u0100\u0101\nC\u0000\u0000\u0101\u0102\u0005\u000f"+
		"\u0000\u0000\u0102\u0138\u0003\u0004\u0002D\u0103\u0104\nB\u0000\u0000"+
		"\u0104\u0105\u0005\u0010\u0000\u0000\u0105\u0138\u0003\u0004\u0002C\u0106"+
		"\u0107\nA\u0000\u0000\u0107\u0108\u0005\u0011\u0000\u0000\u0108\u0138"+
		"\u0003\u0004\u0002B\u0109\u010a\n@\u0000\u0000\u010a\u010b\u0005\u0012"+
		"\u0000\u0000\u010b\u0138\u0003\u0004\u0002A\u010c\u010d\n?\u0000\u0000"+
		"\u010d\u010e\u0005?\u0000\u0000\u010e\u0138\u0003\u0004\u0002@\u010f\u0110"+
		"\n>\u0000\u0000\u0110\u0111\u0005>\u0000\u0000\u0111\u0138\u0003\u0004"+
		"\u0002?\u0112\u0113\n=\u0000\u0000\u0113\u0114\u0005\u0013\u0000\u0000"+
		"\u0114\u0138\u0003\u0004\u0002>\u0115\u0116\n8\u0000\u0000\u0116\u0117"+
		"\u0005\u0016\u0000\u0000\u0117\u0138\u0003\u0004\u00029\u0118\u0119\n"+
		"3\u0000\u0000\u0119\u011a\u0005\u001a\u0000\u0000\u011a\u011b\u0003\u0004"+
		"\u0002\u0000\u011b\u011c\u0005\u001e\u0000\u0000\u011c\u011d\u0003\u0004"+
		"\u00024\u011d\u0138\u0001\u0000\u0000\u0000\u011e\u011f\n2\u0000\u0000"+
		"\u011f\u0120\u0005\u001f\u0000\u0000\u0120\u0138\u0003\u0004\u00023\u0121"+
		"\u0122\n(\u0000\u0000\u0122\u0123\u0005C\u0000\u0000\u0123\u0138\u0003"+
		"\u0004\u0002)\u0124\u0125\n\'\u0000\u0000\u0125\u0126\u0005D\u0000\u0000"+
		"\u0126\u0138\u0003\u0004\u0002(\u0127\u0128\n\u0004\u0000\u0000\u0128"+
		"\u0129\u0005=\u0000\u0000\u0129\u0138\u0003\u0004\u0002\u0005\u012a\u012b"+
		"\n\u0002\u0000\u0000\u012b\u012c\u0005c\u0000\u0000\u012c\u0138\u0003"+
		"\u0004\u0002\u0003\u012d\u012e\n5\u0000\u0000\u012e\u012f\u0005\u001a"+
		"\u0000\u0000\u012f\u0130\u0003\u0004\u0002\u0000\u0130\u0131\u0005\u001b"+
		"\u0000\u0000\u0131\u0138\u0001\u0000\u0000\u0000\u0132\u0133\n4\u0000"+
		"\u0000\u0133\u0134\u0005\u001c\u0000\u0000\u0134\u0135\u0003\u0004\u0002"+
		"\u0000\u0135\u0136\u0005\u001d\u0000\u0000\u0136\u0138\u0001\u0000\u0000"+
		"\u0000\u0137\u00e5\u0001\u0000\u0000\u0000\u0137\u00e8\u0001\u0000\u0000"+
		"\u0000\u0137\u00eb\u0001\u0000\u0000\u0000\u0137\u00ee\u0001\u0000\u0000"+
		"\u0000\u0137\u00f1\u0001\u0000\u0000\u0000\u0137\u00f4\u0001\u0000\u0000"+
		"\u0000\u0137\u00f7\u0001\u0000\u0000\u0000\u0137\u00fa\u0001\u0000\u0000"+
		"\u0000\u0137\u00fd\u0001\u0000\u0000\u0000\u0137\u0100\u0001\u0000\u0000"+
		"\u0000\u0137\u0103\u0001\u0000\u0000\u0000\u0137\u0106\u0001\u0000\u0000"+
		"\u0000\u0137\u0109\u0001\u0000\u0000\u0000\u0137\u010c\u0001\u0000\u0000"+
		"\u0000\u0137\u010f\u0001\u0000\u0000\u0000\u0137\u0112\u0001\u0000\u0000"+
		"\u0000\u0137\u0115\u0001\u0000\u0000\u0000\u0137\u0118\u0001\u0000\u0000"+
		"\u0000\u0137\u011e\u0001\u0000\u0000\u0000\u0137\u0121\u0001\u0000\u0000"+
		"\u0000\u0137\u0124\u0001\u0000\u0000\u0000\u0137\u0127\u0001\u0000\u0000"+
		"\u0000\u0137\u012a\u0001\u0000\u0000\u0000\u0137\u012d\u0001\u0000\u0000"+
		"\u0000\u0137\u0132\u0001\u0000\u0000\u0000\u0138\u013b\u0001\u0000\u0000"+
		"\u0000\u0139\u0137\u0001\u0000\u0000\u0000\u0139\u013a\u0001\u0000\u0000"+
		"\u0000\u013a\u0005\u0001\u0000\u0000\u0000\u013b\u0139\u0001\u0000\u0000"+
		"\u0000\b\u000bPdq\u0080\u00e3\u0137\u0139";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}