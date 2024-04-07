// Generated from /home/giacomo/projects/gsm2/antlr4/graph_grammar/simple_graph_grammar.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class simple_graph_grammarParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, WHERE=31, 
		IF=32, THEN=33, ELSE=34, AS=35, VEC=36, REWRITE_TO=37, FORALL=38, QM=39, 
		EQ=40, STAR=41, LPAR=42, RPAR=43, COL=44, QPAR=45, PPAR=46, EscapedString=47, 
		OTHERS=48, SPACE=49, COMMENT=50, LINE_COMMENT=51;
	public static final int
		RULE_all_matches = 0, RULE_node = 1, RULE_centralmatch = 2, RULE_many_edges = 3, 
		RULE_rewrite_to = 4, RULE_rewrite_expr = 5, RULE_test_expr = 6, RULE_test_expr_side = 7, 
		RULE_edge = 8, RULE_edge_joining = 9, RULE_edgelabel = 10, RULE_multiple_labels = 11;
	private static String[] makeRuleNames() {
		return new String[] {
			"all_matches", "node", "centralmatch", "many_edges", "rewrite_to", "rewrite_expr", 
			"test_expr", "test_expr_side", "edge", "edge_joining", "edgelabel", "multiple_labels"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "';'", "'del'", "'new'", "'set'", "'\\uD835\uDF09'", "'@'", "'\\u2113'", 
			"'\\uD835\uDF0B'", "'\\u03C6'", "','", "'label'", "'src'", "'dst'", "'over'", 
			"'SCRIPT'", "'\\u2260'", "'<'", "'\\u2264'", "'\\u2228'", "'\\u2227'", 
			"'TEST'", "'unmatched'", "'.'", "'matched'", "'FILL'", "'--'", "'->'", 
			"'<-'", "'hook'", "'||'", "'where'", "'if'", "'then'", "'else'", "'as'", 
			"'>>'", "'\\u21AA'", "'\\u2200'", "'?'", "'='", "'*'", "'('", "')'", 
			"':'", "'['", "']'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, "WHERE", "IF", "THEN", "ELSE", 
			"AS", "VEC", "REWRITE_TO", "FORALL", "QM", "EQ", "STAR", "LPAR", "RPAR", 
			"COL", "QPAR", "PPAR", "EscapedString", "OTHERS", "SPACE", "COMMENT", 
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
	public String getGrammarFileName() { return "simple_graph_grammar.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public simple_graph_grammarParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class All_matchesContext extends ParserRuleContext {
		public List<CentralmatchContext> centralmatch() {
			return getRuleContexts(CentralmatchContext.class);
		}
		public CentralmatchContext centralmatch(int i) {
			return getRuleContext(CentralmatchContext.class,i);
		}
		public All_matchesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_all_matches; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterAll_matches(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitAll_matches(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitAll_matches(this);
			else return visitor.visitChildren(this);
		}
	}

	public final All_matchesContext all_matches() throws RecognitionException {
		All_matchesContext _localctx = new All_matchesContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_all_matches);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(29);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(24);
					centralmatch();
					setState(25);
					match(T__0);
					}
					} 
				}
				setState(31);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,0,_ctx);
			}
			setState(32);
			centralmatch();
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
	public static class NodeContext extends ParserRuleContext {
		public Multiple_labelsContext var;
		public TerminalNode LPAR() { return getToken(simple_graph_grammarParser.LPAR, 0); }
		public TerminalNode RPAR() { return getToken(simple_graph_grammarParser.RPAR, 0); }
		public Multiple_labelsContext multiple_labels() {
			return getRuleContext(Multiple_labelsContext.class,0);
		}
		public TerminalNode STAR() { return getToken(simple_graph_grammarParser.STAR, 0); }
		public TerminalNode VEC() { return getToken(simple_graph_grammarParser.VEC, 0); }
		public TerminalNode COL() { return getToken(simple_graph_grammarParser.COL, 0); }
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public NodeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_node; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterNode(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitNode(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitNode(this);
			else return visitor.visitChildren(this);
		}
	}

	public final NodeContext node() throws RecognitionException {
		NodeContext _localctx = new NodeContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_node);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(34);
			match(LPAR);
			setState(36);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==STAR) {
				{
				setState(35);
				match(STAR);
				}
			}

			setState(39);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==VEC) {
				{
				setState(38);
				match(VEC);
				}
			}

			setState(41);
			((NodeContext)_localctx).var = multiple_labels();
			setState(44);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COL) {
				{
				setState(42);
				match(COL);
				setState(43);
				match(OTHERS);
				}
			}

			setState(46);
			match(RPAR);
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
	public static class CentralmatchContext extends ParserRuleContext {
		public Token var;
		public NodeContext src;
		public Many_edgesContext e1;
		public NodeContext dst;
		public TerminalNode EQ() { return getToken(simple_graph_grammarParser.EQ, 0); }
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public List<NodeContext> node() {
			return getRuleContexts(NodeContext.class);
		}
		public NodeContext node(int i) {
			return getRuleContext(NodeContext.class,i);
		}
		public List<Edge_joiningContext> edge_joining() {
			return getRuleContexts(Edge_joiningContext.class);
		}
		public Edge_joiningContext edge_joining(int i) {
			return getRuleContext(Edge_joiningContext.class,i);
		}
		public TerminalNode WHERE() { return getToken(simple_graph_grammarParser.WHERE, 0); }
		public Test_exprContext test_expr() {
			return getRuleContext(Test_exprContext.class,0);
		}
		public TerminalNode REWRITE_TO() { return getToken(simple_graph_grammarParser.REWRITE_TO, 0); }
		public Many_edgesContext many_edges() {
			return getRuleContext(Many_edgesContext.class,0);
		}
		public List<Rewrite_toContext> rewrite_to() {
			return getRuleContexts(Rewrite_toContext.class);
		}
		public Rewrite_toContext rewrite_to(int i) {
			return getRuleContext(Rewrite_toContext.class,i);
		}
		public CentralmatchContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_centralmatch; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterCentralmatch(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitCentralmatch(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitCentralmatch(this);
			else return visitor.visitChildren(this);
		}
	}

	public final CentralmatchContext centralmatch() throws RecognitionException {
		CentralmatchContext _localctx = new CentralmatchContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_centralmatch);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(48);
			((CentralmatchContext)_localctx).var = match(OTHERS);
			setState(49);
			match(EQ);
			setState(50);
			((CentralmatchContext)_localctx).src = node();
			setState(52);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__25 || _la==T__27) {
				{
				setState(51);
				((CentralmatchContext)_localctx).e1 = many_edges();
				}
			}

			setState(57);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==LPAR) {
				{
				{
				setState(54);
				edge_joining();
				}
				}
				setState(59);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(62);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WHERE) {
				{
				setState(60);
				match(WHERE);
				setState(61);
				test_expr(0);
				}
			}

			setState(72);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==REWRITE_TO) {
				{
				setState(64);
				match(REWRITE_TO);
				setState(68);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & 28L) != 0)) {
					{
					{
					setState(65);
					rewrite_to();
					}
					}
					setState(70);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(71);
				((CentralmatchContext)_localctx).dst = node();
				}
			}

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
	public static class Many_edgesContext extends ParserRuleContext {
		public List<EdgeContext> edge() {
			return getRuleContexts(EdgeContext.class);
		}
		public EdgeContext edge(int i) {
			return getRuleContext(EdgeContext.class,i);
		}
		public Many_edgesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_many_edges; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterMany_edges(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitMany_edges(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitMany_edges(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Many_edgesContext many_edges() throws RecognitionException {
		Many_edgesContext _localctx = new Many_edgesContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_many_edges);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(75); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(74);
				edge();
				}
				}
				setState(77); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==T__25 || _la==T__27 );
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
	public static class Rewrite_toContext extends ParserRuleContext {
		public Rewrite_toContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rewrite_to; }
	 
		public Rewrite_toContext() { }
		public void copyFrom(Rewrite_toContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Del_node_or_edgeContext extends Rewrite_toContext {
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public Del_node_or_edgeContext(Rewrite_toContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterDel_node_or_edge(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitDel_node_or_edge(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitDel_node_or_edge(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Update_exprContext extends Rewrite_toContext {
		public Rewrite_exprContext to;
		public Rewrite_exprContext from;
		public TerminalNode AS() { return getToken(simple_graph_grammarParser.AS, 0); }
		public List<Rewrite_exprContext> rewrite_expr() {
			return getRuleContexts(Rewrite_exprContext.class);
		}
		public Rewrite_exprContext rewrite_expr(int i) {
			return getRuleContext(Rewrite_exprContext.class,i);
		}
		public Update_exprContext(Rewrite_toContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterUpdate_expr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitUpdate_expr(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitUpdate_expr(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Neu_objContext extends Rewrite_toContext {
		public Token dst;
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public Neu_objContext(Rewrite_toContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterNeu_obj(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitNeu_obj(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitNeu_obj(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Rewrite_toContext rewrite_to() throws RecognitionException {
		Rewrite_toContext _localctx = new Rewrite_toContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_rewrite_to);
		try {
			setState(88);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
				_localctx = new Del_node_or_edgeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(79);
				match(T__1);
				setState(80);
				match(OTHERS);
				}
				break;
			case T__2:
				_localctx = new Neu_objContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(81);
				match(T__2);
				setState(82);
				((Neu_objContext)_localctx).dst = match(OTHERS);
				}
				break;
			case T__3:
				_localctx = new Update_exprContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(83);
				match(T__3);
				setState(84);
				((Update_exprContext)_localctx).to = rewrite_expr();
				setState(85);
				match(AS);
				setState(86);
				((Update_exprContext)_localctx).from = rewrite_expr();
				}
				break;
			default:
				throw new NoViableAltException(this);
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
	public static class Rewrite_exprContext extends ParserRuleContext {
		public Rewrite_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rewrite_expr; }
	 
		public Rewrite_exprContext() { }
		public void copyFrom(Rewrite_exprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Node_containmentContext extends Rewrite_exprContext {
		public Rewrite_exprContext key;
		public Rewrite_exprContext nodeVar;
		public List<Rewrite_exprContext> rewrite_expr() {
			return getRuleContexts(Rewrite_exprContext.class);
		}
		public Rewrite_exprContext rewrite_expr(int i) {
			return getRuleContext(Rewrite_exprContext.class,i);
		}
		public Node_containmentContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterNode_containment(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitNode_containment(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitNode_containment(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Node_propContext extends Rewrite_exprContext {
		public Rewrite_exprContext key;
		public Rewrite_exprContext nodeVar;
		public List<Rewrite_exprContext> rewrite_expr() {
			return getRuleContexts(Rewrite_exprContext.class);
		}
		public Rewrite_exprContext rewrite_expr(int i) {
			return getRuleContext(Rewrite_exprContext.class,i);
		}
		public Node_propContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterNode_prop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitNode_prop(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitNode_prop(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Ifte_exprContext extends Rewrite_exprContext {
		public Test_exprContext ifcond;
		public Rewrite_exprContext then_effect;
		public Rewrite_exprContext else_effect;
		public TerminalNode IF() { return getToken(simple_graph_grammarParser.IF, 0); }
		public TerminalNode LPAR() { return getToken(simple_graph_grammarParser.LPAR, 0); }
		public TerminalNode RPAR() { return getToken(simple_graph_grammarParser.RPAR, 0); }
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public TerminalNode THEN() { return getToken(simple_graph_grammarParser.THEN, 0); }
		public Test_exprContext test_expr() {
			return getRuleContext(Test_exprContext.class,0);
		}
		public List<Rewrite_exprContext> rewrite_expr() {
			return getRuleContexts(Rewrite_exprContext.class);
		}
		public Rewrite_exprContext rewrite_expr(int i) {
			return getRuleContext(Rewrite_exprContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(simple_graph_grammarParser.ELSE, 0); }
		public Ifte_exprContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterIfte_expr(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitIfte_expr(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitIfte_expr(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Edge_srcContext extends Rewrite_exprContext {
		public Rewrite_exprContext edgeVar;
		public Rewrite_exprContext rewrite_expr() {
			return getRuleContext(Rewrite_exprContext.class,0);
		}
		public Edge_srcContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterEdge_src(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitEdge_src(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitEdge_src(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Edge_dstContext extends Rewrite_exprContext {
		public Rewrite_exprContext edgeVar;
		public Rewrite_exprContext rewrite_expr() {
			return getRuleContext(Rewrite_exprContext.class,0);
		}
		public Edge_dstContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterEdge_dst(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitEdge_dst(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitEdge_dst(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Node_or_edgeContext extends Rewrite_exprContext {
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public Node_or_edgeContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterNode_or_edge(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitNode_or_edge(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitNode_or_edge(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Node_xiContext extends Rewrite_exprContext {
		public Token num;
		public Rewrite_exprContext nodeVar;
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public Rewrite_exprContext rewrite_expr() {
			return getRuleContext(Rewrite_exprContext.class,0);
		}
		public Node_xiContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterNode_xi(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitNode_xi(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitNode_xi(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Just_parContext extends Rewrite_exprContext {
		public TerminalNode LPAR() { return getToken(simple_graph_grammarParser.LPAR, 0); }
		public Rewrite_exprContext rewrite_expr() {
			return getRuleContext(Rewrite_exprContext.class,0);
		}
		public TerminalNode RPAR() { return getToken(simple_graph_grammarParser.RPAR, 0); }
		public Just_parContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterJust_par(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitJust_par(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitJust_par(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Node_ellContext extends Rewrite_exprContext {
		public Token num;
		public Rewrite_exprContext nodeVar;
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public Rewrite_exprContext rewrite_expr() {
			return getRuleContext(Rewrite_exprContext.class,0);
		}
		public Node_ellContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterNode_ell(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitNode_ell(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitNode_ell(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Edge_labelContext extends Rewrite_exprContext {
		public Rewrite_exprContext edgeVar;
		public Rewrite_exprContext rewrite_expr() {
			return getRuleContext(Rewrite_exprContext.class,0);
		}
		public Edge_labelContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterEdge_label(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitEdge_label(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitEdge_label(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class ScriptContext extends Rewrite_exprContext {
		public TerminalNode EscapedString() { return getToken(simple_graph_grammarParser.EscapedString, 0); }
		public ScriptContext(Rewrite_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterScript(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitScript(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitScript(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Rewrite_exprContext rewrite_expr() throws RecognitionException {
		Rewrite_exprContext _localctx = new Rewrite_exprContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_rewrite_expr);
		try {
			setState(133);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__4:
				_localctx = new Node_xiContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(90);
				match(T__4);
				setState(91);
				((Node_xiContext)_localctx).num = match(OTHERS);
				setState(92);
				match(T__5);
				setState(93);
				((Node_xiContext)_localctx).nodeVar = rewrite_expr();
				}
				break;
			case T__6:
				_localctx = new Node_ellContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(94);
				match(T__6);
				setState(95);
				((Node_ellContext)_localctx).num = match(OTHERS);
				setState(96);
				match(T__5);
				setState(97);
				((Node_ellContext)_localctx).nodeVar = rewrite_expr();
				}
				break;
			case T__7:
				_localctx = new Node_propContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(98);
				match(T__7);
				setState(99);
				((Node_propContext)_localctx).key = rewrite_expr();
				setState(100);
				match(T__5);
				setState(101);
				((Node_propContext)_localctx).nodeVar = rewrite_expr();
				}
				break;
			case T__8:
				_localctx = new Node_containmentContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(103);
				match(T__8);
				setState(104);
				((Node_containmentContext)_localctx).key = rewrite_expr();
				setState(105);
				match(T__9);
				setState(106);
				((Node_containmentContext)_localctx).nodeVar = rewrite_expr();
				}
				break;
			case T__10:
				_localctx = new Edge_labelContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(108);
				match(T__10);
				setState(109);
				((Edge_labelContext)_localctx).edgeVar = rewrite_expr();
				}
				break;
			case T__11:
				_localctx = new Edge_srcContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(110);
				match(T__11);
				setState(111);
				((Edge_srcContext)_localctx).edgeVar = rewrite_expr();
				}
				break;
			case T__12:
				_localctx = new Edge_dstContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(112);
				match(T__12);
				setState(113);
				((Edge_dstContext)_localctx).edgeVar = rewrite_expr();
				}
				break;
			case IF:
				_localctx = new Ifte_exprContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(114);
				match(IF);
				setState(115);
				match(LPAR);
				setState(116);
				((Ifte_exprContext)_localctx).ifcond = test_expr(0);
				setState(117);
				match(RPAR);
				setState(118);
				match(T__13);
				setState(119);
				match(OTHERS);
				setState(120);
				match(THEN);
				setState(121);
				((Ifte_exprContext)_localctx).then_effect = rewrite_expr();
				setState(124);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
				case 1:
					{
					setState(122);
					match(ELSE);
					setState(123);
					((Ifte_exprContext)_localctx).else_effect = rewrite_expr();
					}
					break;
				}
				}
				break;
			case OTHERS:
				_localctx = new Node_or_edgeContext(_localctx);
				enterOuterAlt(_localctx, 9);
				{
				setState(126);
				match(OTHERS);
				}
				break;
			case LPAR:
				_localctx = new Just_parContext(_localctx);
				enterOuterAlt(_localctx, 10);
				{
				setState(127);
				match(LPAR);
				setState(128);
				rewrite_expr();
				setState(129);
				match(RPAR);
				}
				break;
			case T__14:
				_localctx = new ScriptContext(_localctx);
				enterOuterAlt(_localctx, 11);
				{
				setState(131);
				match(T__14);
				setState(132);
				match(EscapedString);
				}
				break;
			default:
				throw new NoViableAltException(this);
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
	public static class Test_exprContext extends ParserRuleContext {
		public Test_exprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_test_expr; }
	 
		public Test_exprContext() { }
		public void copyFrom(Test_exprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Leq_testContext extends Test_exprContext {
		public Test_expr_sideContext src;
		public Test_expr_sideContext dst;
		public List<Test_expr_sideContext> test_expr_side() {
			return getRuleContexts(Test_expr_sideContext.class);
		}
		public Test_expr_sideContext test_expr_side(int i) {
			return getRuleContext(Test_expr_sideContext.class,i);
		}
		public Leq_testContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterLeq_test(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitLeq_test(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitLeq_test(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Script_testContext extends Test_exprContext {
		public TerminalNode EscapedString() { return getToken(simple_graph_grammarParser.EscapedString, 0); }
		public Script_testContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterScript_test(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitScript_test(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitScript_test(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Or_testContext extends Test_exprContext {
		public Test_exprContext src;
		public Test_exprContext dst;
		public List<Test_exprContext> test_expr() {
			return getRuleContexts(Test_exprContext.class);
		}
		public Test_exprContext test_expr(int i) {
			return getRuleContext(Test_exprContext.class,i);
		}
		public Or_testContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterOr_test(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitOr_test(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitOr_test(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Par_testContext extends Test_exprContext {
		public TerminalNode LPAR() { return getToken(simple_graph_grammarParser.LPAR, 0); }
		public Test_exprContext test_expr() {
			return getRuleContext(Test_exprContext.class,0);
		}
		public TerminalNode RPAR() { return getToken(simple_graph_grammarParser.RPAR, 0); }
		public Par_testContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterPar_test(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitPar_test(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitPar_test(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class MatchedContext extends Test_exprContext {
		public List<TerminalNode> OTHERS() { return getTokens(simple_graph_grammarParser.OTHERS); }
		public TerminalNode OTHERS(int i) {
			return getToken(simple_graph_grammarParser.OTHERS, i);
		}
		public MatchedContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterMatched(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitMatched(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitMatched(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Eq_testContext extends Test_exprContext {
		public Test_expr_sideContext src;
		public Test_expr_sideContext dst;
		public TerminalNode EQ() { return getToken(simple_graph_grammarParser.EQ, 0); }
		public List<Test_expr_sideContext> test_expr_side() {
			return getRuleContexts(Test_expr_sideContext.class);
		}
		public Test_expr_sideContext test_expr_side(int i) {
			return getRuleContext(Test_expr_sideContext.class,i);
		}
		public Eq_testContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterEq_test(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitEq_test(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitEq_test(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Neq_testContext extends Test_exprContext {
		public Test_expr_sideContext src;
		public Test_expr_sideContext dst;
		public List<Test_expr_sideContext> test_expr_side() {
			return getRuleContexts(Test_expr_sideContext.class);
		}
		public Test_expr_sideContext test_expr_side(int i) {
			return getRuleContext(Test_expr_sideContext.class,i);
		}
		public Neq_testContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterNeq_test(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitNeq_test(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitNeq_test(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class FillContext extends Test_exprContext {
		public Test_exprContext test_expr() {
			return getRuleContext(Test_exprContext.class,0);
		}
		public FillContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterFill(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitFill(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitFill(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Lt_testContext extends Test_exprContext {
		public Test_expr_sideContext src;
		public Test_expr_sideContext dst;
		public List<Test_expr_sideContext> test_expr_side() {
			return getRuleContexts(Test_expr_sideContext.class);
		}
		public Test_expr_sideContext test_expr_side(int i) {
			return getRuleContext(Test_expr_sideContext.class,i);
		}
		public Lt_testContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterLt_test(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitLt_test(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitLt_test(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class UnmatchedContext extends Test_exprContext {
		public List<TerminalNode> OTHERS() { return getTokens(simple_graph_grammarParser.OTHERS); }
		public TerminalNode OTHERS(int i) {
			return getToken(simple_graph_grammarParser.OTHERS, i);
		}
		public UnmatchedContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterUnmatched(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitUnmatched(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitUnmatched(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class And_testContext extends Test_exprContext {
		public Test_exprContext src;
		public Test_exprContext dst;
		public List<Test_exprContext> test_expr() {
			return getRuleContexts(Test_exprContext.class);
		}
		public Test_exprContext test_expr(int i) {
			return getRuleContext(Test_exprContext.class,i);
		}
		public And_testContext(Test_exprContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterAnd_test(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitAnd_test(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitAnd_test(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Test_exprContext test_expr() throws RecognitionException {
		return test_expr(0);
	}

	private Test_exprContext test_expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		Test_exprContext _localctx = new Test_exprContext(_ctx, _parentState);
		Test_exprContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_test_expr, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(170);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				_localctx = new Eq_testContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(136);
				((Eq_testContext)_localctx).src = test_expr_side();
				setState(137);
				match(EQ);
				setState(138);
				((Eq_testContext)_localctx).dst = test_expr_side();
				}
				break;
			case 2:
				{
				_localctx = new Neq_testContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(140);
				((Neq_testContext)_localctx).src = test_expr_side();
				setState(141);
				match(T__15);
				setState(142);
				((Neq_testContext)_localctx).dst = test_expr_side();
				}
				break;
			case 3:
				{
				_localctx = new Lt_testContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(144);
				((Lt_testContext)_localctx).src = test_expr_side();
				setState(145);
				match(T__16);
				setState(146);
				((Lt_testContext)_localctx).dst = test_expr_side();
				}
				break;
			case 4:
				{
				_localctx = new Leq_testContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(148);
				((Leq_testContext)_localctx).src = test_expr_side();
				setState(149);
				match(T__17);
				setState(150);
				((Leq_testContext)_localctx).dst = test_expr_side();
				}
				break;
			case 5:
				{
				_localctx = new Par_testContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(152);
				match(LPAR);
				setState(153);
				test_expr(0);
				setState(154);
				match(RPAR);
				}
				break;
			case 6:
				{
				_localctx = new Script_testContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(156);
				match(T__20);
				setState(157);
				match(EscapedString);
				}
				break;
			case 7:
				{
				_localctx = new UnmatchedContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(158);
				match(OTHERS);
				setState(159);
				match(T__21);
				setState(160);
				match(OTHERS);
				setState(161);
				match(T__22);
				setState(162);
				match(OTHERS);
				}
				break;
			case 8:
				{
				_localctx = new MatchedContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(163);
				match(OTHERS);
				setState(164);
				match(T__23);
				setState(165);
				match(OTHERS);
				setState(166);
				match(T__22);
				setState(167);
				match(OTHERS);
				}
				break;
			case 9:
				{
				_localctx = new FillContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(168);
				match(T__24);
				setState(169);
				test_expr(1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(180);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(178);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
					case 1:
						{
						_localctx = new Or_testContext(new Test_exprContext(_parentctx, _parentState));
						((Or_testContext)_localctx).src = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_test_expr);
						setState(172);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(173);
						match(T__18);
						setState(174);
						((Or_testContext)_localctx).dst = test_expr(8);
						}
						break;
					case 2:
						{
						_localctx = new And_testContext(new Test_exprContext(_parentctx, _parentState));
						((And_testContext)_localctx).src = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_test_expr);
						setState(175);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(176);
						match(T__19);
						setState(177);
						((And_testContext)_localctx).dst = test_expr(7);
						}
						break;
					}
					} 
				}
				setState(182);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
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

	@SuppressWarnings("CheckReturnValue")
	public static class Test_expr_sideContext extends ParserRuleContext {
		public Test_expr_sideContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_test_expr_side; }
	 
		public Test_expr_sideContext() { }
		public void copyFrom(Test_expr_sideContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Test_dataContext extends Test_expr_sideContext {
		public Rewrite_exprContext rewrite_expr() {
			return getRuleContext(Rewrite_exprContext.class,0);
		}
		public Test_dataContext(Test_expr_sideContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterTest_data(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitTest_data(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitTest_data(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class Test_valueContext extends Test_expr_sideContext {
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public Test_valueContext(Test_expr_sideContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterTest_value(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitTest_value(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitTest_value(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Test_expr_sideContext test_expr_side() throws RecognitionException {
		Test_expr_sideContext _localctx = new Test_expr_sideContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_test_expr_side);
		try {
			setState(185);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,16,_ctx) ) {
			case 1:
				_localctx = new Test_dataContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(183);
				rewrite_expr();
				}
				break;
			case 2:
				_localctx = new Test_valueContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(184);
				match(OTHERS);
				}
				break;
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
	public static class EdgeContext extends ParserRuleContext {
		public EdgeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_edge; }
	 
		public EdgeContext() { }
		public void copyFrom(EdgeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class HookContext extends EdgeContext {
		public EdgelabelContext edgelabel() {
			return getRuleContext(EdgelabelContext.class,0);
		}
		public HookContext(EdgeContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterHook(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitHook(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitHook(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class OutedgeContext extends EdgeContext {
		public EdgelabelContext edgelabel() {
			return getRuleContext(EdgelabelContext.class,0);
		}
		public NodeContext node() {
			return getRuleContext(NodeContext.class,0);
		}
		public OutedgeContext(EdgeContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterOutedge(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitOutedge(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitOutedge(this);
			else return visitor.visitChildren(this);
		}
	}
	@SuppressWarnings("CheckReturnValue")
	public static class InedgeContext extends EdgeContext {
		public EdgelabelContext edgelabel() {
			return getRuleContext(EdgelabelContext.class,0);
		}
		public NodeContext node() {
			return getRuleContext(NodeContext.class,0);
		}
		public InedgeContext(EdgeContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterInedge(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitInedge(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitInedge(this);
			else return visitor.visitChildren(this);
		}
	}

	public final EdgeContext edge() throws RecognitionException {
		EdgeContext _localctx = new EdgeContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_edge);
		try {
			setState(201);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
			case 1:
				_localctx = new OutedgeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(187);
				match(T__25);
				setState(188);
				edgelabel();
				setState(189);
				match(T__26);
				setState(190);
				node();
				}
				break;
			case 2:
				_localctx = new InedgeContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(192);
				match(T__27);
				setState(193);
				edgelabel();
				setState(194);
				match(T__25);
				setState(195);
				node();
				}
				break;
			case 3:
				_localctx = new HookContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(197);
				match(T__25);
				setState(198);
				edgelabel();
				setState(199);
				match(T__28);
				}
				break;
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
	public static class Edge_joiningContext extends ParserRuleContext {
		public NodeContext node() {
			return getRuleContext(NodeContext.class,0);
		}
		public EdgeContext edge() {
			return getRuleContext(EdgeContext.class,0);
		}
		public Edge_joiningContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_edge_joining; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterEdge_joining(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitEdge_joining(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitEdge_joining(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Edge_joiningContext edge_joining() throws RecognitionException {
		Edge_joiningContext _localctx = new Edge_joiningContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_edge_joining);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(203);
			node();
			setState(204);
			edge();
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
	public static class EdgelabelContext extends ParserRuleContext {
		public Token var;
		public TerminalNode QPAR() { return getToken(simple_graph_grammarParser.QPAR, 0); }
		public TerminalNode PPAR() { return getToken(simple_graph_grammarParser.PPAR, 0); }
		public TerminalNode COL() { return getToken(simple_graph_grammarParser.COL, 0); }
		public Multiple_labelsContext multiple_labels() {
			return getRuleContext(Multiple_labelsContext.class,0);
		}
		public TerminalNode OTHERS() { return getToken(simple_graph_grammarParser.OTHERS, 0); }
		public TerminalNode FORALL() { return getToken(simple_graph_grammarParser.FORALL, 0); }
		public TerminalNode QM() { return getToken(simple_graph_grammarParser.QM, 0); }
		public EdgelabelContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_edgelabel; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterEdgelabel(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitEdgelabel(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitEdgelabel(this);
			else return visitor.visitChildren(this);
		}
	}

	public final EdgelabelContext edgelabel() throws RecognitionException {
		EdgelabelContext _localctx = new EdgelabelContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_edgelabel);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(206);
			match(QPAR);
			{
			setState(208);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==FORALL) {
				{
				setState(207);
				match(FORALL);
				}
			}

			setState(211);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==QM) {
				{
				setState(210);
				match(QM);
				}
			}

			}
			setState(215);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
			case 1:
				{
				setState(213);
				((EdgelabelContext)_localctx).var = match(OTHERS);
				setState(214);
				match(COL);
				}
				break;
			}
			setState(218);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==OTHERS) {
				{
				setState(217);
				multiple_labels();
				}
			}

			setState(220);
			match(PPAR);
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
	public static class Multiple_labelsContext extends ParserRuleContext {
		public List<TerminalNode> OTHERS() { return getTokens(simple_graph_grammarParser.OTHERS); }
		public TerminalNode OTHERS(int i) {
			return getToken(simple_graph_grammarParser.OTHERS, i);
		}
		public Multiple_labelsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiple_labels; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).enterMultiple_labels(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof simple_graph_grammarListener ) ((simple_graph_grammarListener)listener).exitMultiple_labels(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof simple_graph_grammarVisitor ) return ((simple_graph_grammarVisitor<? extends T>)visitor).visitMultiple_labels(this);
			else return visitor.visitChildren(this);
		}
	}

	public final Multiple_labelsContext multiple_labels() throws RecognitionException {
		Multiple_labelsContext _localctx = new Multiple_labelsContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_multiple_labels);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(226);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(222);
					match(OTHERS);
					setState(223);
					match(T__29);
					}
					} 
				}
				setState(228);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,22,_ctx);
			}
			setState(229);
			match(OTHERS);
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 6:
			return test_expr_sempred((Test_exprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean test_expr_sempred(Test_exprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 7);
		case 1:
			return precpred(_ctx, 6);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u00013\u00e8\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0001"+
		"\u0000\u0001\u0000\u0001\u0000\u0005\u0000\u001c\b\u0000\n\u0000\f\u0000"+
		"\u001f\t\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0003\u0001"+
		"%\b\u0001\u0001\u0001\u0003\u0001(\b\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0003\u0001-\b\u0001\u0001\u0001\u0001\u0001\u0001\u0002\u0001"+
		"\u0002\u0001\u0002\u0001\u0002\u0003\u00025\b\u0002\u0001\u0002\u0005"+
		"\u00028\b\u0002\n\u0002\f\u0002;\t\u0002\u0001\u0002\u0001\u0002\u0003"+
		"\u0002?\b\u0002\u0001\u0002\u0001\u0002\u0005\u0002C\b\u0002\n\u0002\f"+
		"\u0002F\t\u0002\u0001\u0002\u0003\u0002I\b\u0002\u0001\u0003\u0004\u0003"+
		"L\b\u0003\u000b\u0003\f\u0003M\u0001\u0004\u0001\u0004\u0001\u0004\u0001"+
		"\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0003"+
		"\u0004Y\b\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003"+
		"\u0005}\b\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0003\u0005\u0086\b\u0005\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006\u00ab\b\u0006\u0001"+
		"\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0005"+
		"\u0006\u00b3\b\u0006\n\u0006\f\u0006\u00b6\t\u0006\u0001\u0007\u0001\u0007"+
		"\u0003\u0007\u00ba\b\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0003"+
		"\b\u00ca\b\b\u0001\t\u0001\t\u0001\t\u0001\n\u0001\n\u0003\n\u00d1\b\n"+
		"\u0001\n\u0003\n\u00d4\b\n\u0001\n\u0001\n\u0003\n\u00d8\b\n\u0001\n\u0003"+
		"\n\u00db\b\n\u0001\n\u0001\n\u0001\u000b\u0001\u000b\u0005\u000b\u00e1"+
		"\b\u000b\n\u000b\f\u000b\u00e4\t\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0000\u0001\f\f\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014"+
		"\u0016\u0000\u0000\u0104\u0000\u001d\u0001\u0000\u0000\u0000\u0002\"\u0001"+
		"\u0000\u0000\u0000\u00040\u0001\u0000\u0000\u0000\u0006K\u0001\u0000\u0000"+
		"\u0000\bX\u0001\u0000\u0000\u0000\n\u0085\u0001\u0000\u0000\u0000\f\u00aa"+
		"\u0001\u0000\u0000\u0000\u000e\u00b9\u0001\u0000\u0000\u0000\u0010\u00c9"+
		"\u0001\u0000\u0000\u0000\u0012\u00cb\u0001\u0000\u0000\u0000\u0014\u00ce"+
		"\u0001\u0000\u0000\u0000\u0016\u00e2\u0001\u0000\u0000\u0000\u0018\u0019"+
		"\u0003\u0004\u0002\u0000\u0019\u001a\u0005\u0001\u0000\u0000\u001a\u001c"+
		"\u0001\u0000\u0000\u0000\u001b\u0018\u0001\u0000\u0000\u0000\u001c\u001f"+
		"\u0001\u0000\u0000\u0000\u001d\u001b\u0001\u0000\u0000\u0000\u001d\u001e"+
		"\u0001\u0000\u0000\u0000\u001e \u0001\u0000\u0000\u0000\u001f\u001d\u0001"+
		"\u0000\u0000\u0000 !\u0003\u0004\u0002\u0000!\u0001\u0001\u0000\u0000"+
		"\u0000\"$\u0005*\u0000\u0000#%\u0005)\u0000\u0000$#\u0001\u0000\u0000"+
		"\u0000$%\u0001\u0000\u0000\u0000%\'\u0001\u0000\u0000\u0000&(\u0005$\u0000"+
		"\u0000\'&\u0001\u0000\u0000\u0000\'(\u0001\u0000\u0000\u0000()\u0001\u0000"+
		"\u0000\u0000),\u0003\u0016\u000b\u0000*+\u0005,\u0000\u0000+-\u00050\u0000"+
		"\u0000,*\u0001\u0000\u0000\u0000,-\u0001\u0000\u0000\u0000-.\u0001\u0000"+
		"\u0000\u0000./\u0005+\u0000\u0000/\u0003\u0001\u0000\u0000\u000001\u0005"+
		"0\u0000\u000012\u0005(\u0000\u000024\u0003\u0002\u0001\u000035\u0003\u0006"+
		"\u0003\u000043\u0001\u0000\u0000\u000045\u0001\u0000\u0000\u000059\u0001"+
		"\u0000\u0000\u000068\u0003\u0012\t\u000076\u0001\u0000\u0000\u00008;\u0001"+
		"\u0000\u0000\u000097\u0001\u0000\u0000\u00009:\u0001\u0000\u0000\u0000"+
		":>\u0001\u0000\u0000\u0000;9\u0001\u0000\u0000\u0000<=\u0005\u001f\u0000"+
		"\u0000=?\u0003\f\u0006\u0000><\u0001\u0000\u0000\u0000>?\u0001\u0000\u0000"+
		"\u0000?H\u0001\u0000\u0000\u0000@D\u0005%\u0000\u0000AC\u0003\b\u0004"+
		"\u0000BA\u0001\u0000\u0000\u0000CF\u0001\u0000\u0000\u0000DB\u0001\u0000"+
		"\u0000\u0000DE\u0001\u0000\u0000\u0000EG\u0001\u0000\u0000\u0000FD\u0001"+
		"\u0000\u0000\u0000GI\u0003\u0002\u0001\u0000H@\u0001\u0000\u0000\u0000"+
		"HI\u0001\u0000\u0000\u0000I\u0005\u0001\u0000\u0000\u0000JL\u0003\u0010"+
		"\b\u0000KJ\u0001\u0000\u0000\u0000LM\u0001\u0000\u0000\u0000MK\u0001\u0000"+
		"\u0000\u0000MN\u0001\u0000\u0000\u0000N\u0007\u0001\u0000\u0000\u0000"+
		"OP\u0005\u0002\u0000\u0000PY\u00050\u0000\u0000QR\u0005\u0003\u0000\u0000"+
		"RY\u00050\u0000\u0000ST\u0005\u0004\u0000\u0000TU\u0003\n\u0005\u0000"+
		"UV\u0005#\u0000\u0000VW\u0003\n\u0005\u0000WY\u0001\u0000\u0000\u0000"+
		"XO\u0001\u0000\u0000\u0000XQ\u0001\u0000\u0000\u0000XS\u0001\u0000\u0000"+
		"\u0000Y\t\u0001\u0000\u0000\u0000Z[\u0005\u0005\u0000\u0000[\\\u00050"+
		"\u0000\u0000\\]\u0005\u0006\u0000\u0000]\u0086\u0003\n\u0005\u0000^_\u0005"+
		"\u0007\u0000\u0000_`\u00050\u0000\u0000`a\u0005\u0006\u0000\u0000a\u0086"+
		"\u0003\n\u0005\u0000bc\u0005\b\u0000\u0000cd\u0003\n\u0005\u0000de\u0005"+
		"\u0006\u0000\u0000ef\u0003\n\u0005\u0000f\u0086\u0001\u0000\u0000\u0000"+
		"gh\u0005\t\u0000\u0000hi\u0003\n\u0005\u0000ij\u0005\n\u0000\u0000jk\u0003"+
		"\n\u0005\u0000k\u0086\u0001\u0000\u0000\u0000lm\u0005\u000b\u0000\u0000"+
		"m\u0086\u0003\n\u0005\u0000no\u0005\f\u0000\u0000o\u0086\u0003\n\u0005"+
		"\u0000pq\u0005\r\u0000\u0000q\u0086\u0003\n\u0005\u0000rs\u0005 \u0000"+
		"\u0000st\u0005*\u0000\u0000tu\u0003\f\u0006\u0000uv\u0005+\u0000\u0000"+
		"vw\u0005\u000e\u0000\u0000wx\u00050\u0000\u0000xy\u0005!\u0000\u0000y"+
		"|\u0003\n\u0005\u0000z{\u0005\"\u0000\u0000{}\u0003\n\u0005\u0000|z\u0001"+
		"\u0000\u0000\u0000|}\u0001\u0000\u0000\u0000}\u0086\u0001\u0000\u0000"+
		"\u0000~\u0086\u00050\u0000\u0000\u007f\u0080\u0005*\u0000\u0000\u0080"+
		"\u0081\u0003\n\u0005\u0000\u0081\u0082\u0005+\u0000\u0000\u0082\u0086"+
		"\u0001\u0000\u0000\u0000\u0083\u0084\u0005\u000f\u0000\u0000\u0084\u0086"+
		"\u0005/\u0000\u0000\u0085Z\u0001\u0000\u0000\u0000\u0085^\u0001\u0000"+
		"\u0000\u0000\u0085b\u0001\u0000\u0000\u0000\u0085g\u0001\u0000\u0000\u0000"+
		"\u0085l\u0001\u0000\u0000\u0000\u0085n\u0001\u0000\u0000\u0000\u0085p"+
		"\u0001\u0000\u0000\u0000\u0085r\u0001\u0000\u0000\u0000\u0085~\u0001\u0000"+
		"\u0000\u0000\u0085\u007f\u0001\u0000\u0000\u0000\u0085\u0083\u0001\u0000"+
		"\u0000\u0000\u0086\u000b\u0001\u0000\u0000\u0000\u0087\u0088\u0006\u0006"+
		"\uffff\uffff\u0000\u0088\u0089\u0003\u000e\u0007\u0000\u0089\u008a\u0005"+
		"(\u0000\u0000\u008a\u008b\u0003\u000e\u0007\u0000\u008b\u00ab\u0001\u0000"+
		"\u0000\u0000\u008c\u008d\u0003\u000e\u0007\u0000\u008d\u008e\u0005\u0010"+
		"\u0000\u0000\u008e\u008f\u0003\u000e\u0007\u0000\u008f\u00ab\u0001\u0000"+
		"\u0000\u0000\u0090\u0091\u0003\u000e\u0007\u0000\u0091\u0092\u0005\u0011"+
		"\u0000\u0000\u0092\u0093\u0003\u000e\u0007\u0000\u0093\u00ab\u0001\u0000"+
		"\u0000\u0000\u0094\u0095\u0003\u000e\u0007\u0000\u0095\u0096\u0005\u0012"+
		"\u0000\u0000\u0096\u0097\u0003\u000e\u0007\u0000\u0097\u00ab\u0001\u0000"+
		"\u0000\u0000\u0098\u0099\u0005*\u0000\u0000\u0099\u009a\u0003\f\u0006"+
		"\u0000\u009a\u009b\u0005+\u0000\u0000\u009b\u00ab\u0001\u0000\u0000\u0000"+
		"\u009c\u009d\u0005\u0015\u0000\u0000\u009d\u00ab\u0005/\u0000\u0000\u009e"+
		"\u009f\u00050\u0000\u0000\u009f\u00a0\u0005\u0016\u0000\u0000\u00a0\u00a1"+
		"\u00050\u0000\u0000\u00a1\u00a2\u0005\u0017\u0000\u0000\u00a2\u00ab\u0005"+
		"0\u0000\u0000\u00a3\u00a4\u00050\u0000\u0000\u00a4\u00a5\u0005\u0018\u0000"+
		"\u0000\u00a5\u00a6\u00050\u0000\u0000\u00a6\u00a7\u0005\u0017\u0000\u0000"+
		"\u00a7\u00ab\u00050\u0000\u0000\u00a8\u00a9\u0005\u0019\u0000\u0000\u00a9"+
		"\u00ab\u0003\f\u0006\u0001\u00aa\u0087\u0001\u0000\u0000\u0000\u00aa\u008c"+
		"\u0001\u0000\u0000\u0000\u00aa\u0090\u0001\u0000\u0000\u0000\u00aa\u0094"+
		"\u0001\u0000\u0000\u0000\u00aa\u0098\u0001\u0000\u0000\u0000\u00aa\u009c"+
		"\u0001\u0000\u0000\u0000\u00aa\u009e\u0001\u0000\u0000\u0000\u00aa\u00a3"+
		"\u0001\u0000\u0000\u0000\u00aa\u00a8\u0001\u0000\u0000\u0000\u00ab\u00b4"+
		"\u0001\u0000\u0000\u0000\u00ac\u00ad\n\u0007\u0000\u0000\u00ad\u00ae\u0005"+
		"\u0013\u0000\u0000\u00ae\u00b3\u0003\f\u0006\b\u00af\u00b0\n\u0006\u0000"+
		"\u0000\u00b0\u00b1\u0005\u0014\u0000\u0000\u00b1\u00b3\u0003\f\u0006\u0007"+
		"\u00b2\u00ac\u0001\u0000\u0000\u0000\u00b2\u00af\u0001\u0000\u0000\u0000"+
		"\u00b3\u00b6\u0001\u0000\u0000\u0000\u00b4\u00b2\u0001\u0000\u0000\u0000"+
		"\u00b4\u00b5\u0001\u0000\u0000\u0000\u00b5\r\u0001\u0000\u0000\u0000\u00b6"+
		"\u00b4\u0001\u0000\u0000\u0000\u00b7\u00ba\u0003\n\u0005\u0000\u00b8\u00ba"+
		"\u00050\u0000\u0000\u00b9\u00b7\u0001\u0000\u0000\u0000\u00b9\u00b8\u0001"+
		"\u0000\u0000\u0000\u00ba\u000f\u0001\u0000\u0000\u0000\u00bb\u00bc\u0005"+
		"\u001a\u0000\u0000\u00bc\u00bd\u0003\u0014\n\u0000\u00bd\u00be\u0005\u001b"+
		"\u0000\u0000\u00be\u00bf\u0003\u0002\u0001\u0000\u00bf\u00ca\u0001\u0000"+
		"\u0000\u0000\u00c0\u00c1\u0005\u001c\u0000\u0000\u00c1\u00c2\u0003\u0014"+
		"\n\u0000\u00c2\u00c3\u0005\u001a\u0000\u0000\u00c3\u00c4\u0003\u0002\u0001"+
		"\u0000\u00c4\u00ca\u0001\u0000\u0000\u0000\u00c5\u00c6\u0005\u001a\u0000"+
		"\u0000\u00c6\u00c7\u0003\u0014\n\u0000\u00c7\u00c8\u0005\u001d\u0000\u0000"+
		"\u00c8\u00ca\u0001\u0000\u0000\u0000\u00c9\u00bb\u0001\u0000\u0000\u0000"+
		"\u00c9\u00c0\u0001\u0000\u0000\u0000\u00c9\u00c5\u0001\u0000\u0000\u0000"+
		"\u00ca\u0011\u0001\u0000\u0000\u0000\u00cb\u00cc\u0003\u0002\u0001\u0000"+
		"\u00cc\u00cd\u0003\u0010\b\u0000\u00cd\u0013\u0001\u0000\u0000\u0000\u00ce"+
		"\u00d0\u0005-\u0000\u0000\u00cf\u00d1\u0005&\u0000\u0000\u00d0\u00cf\u0001"+
		"\u0000\u0000\u0000\u00d0\u00d1\u0001\u0000\u0000\u0000\u00d1\u00d3\u0001"+
		"\u0000\u0000\u0000\u00d2\u00d4\u0005\'\u0000\u0000\u00d3\u00d2\u0001\u0000"+
		"\u0000\u0000\u00d3\u00d4\u0001\u0000\u0000\u0000\u00d4\u00d7\u0001\u0000"+
		"\u0000\u0000\u00d5\u00d6\u00050\u0000\u0000\u00d6\u00d8\u0005,\u0000\u0000"+
		"\u00d7\u00d5\u0001\u0000\u0000\u0000\u00d7\u00d8\u0001\u0000\u0000\u0000"+
		"\u00d8\u00da\u0001\u0000\u0000\u0000\u00d9\u00db\u0003\u0016\u000b\u0000"+
		"\u00da\u00d9\u0001\u0000\u0000\u0000\u00da\u00db\u0001\u0000\u0000\u0000"+
		"\u00db\u00dc\u0001\u0000\u0000\u0000\u00dc\u00dd\u0005.\u0000\u0000\u00dd"+
		"\u0015\u0001\u0000\u0000\u0000\u00de\u00df\u00050\u0000\u0000\u00df\u00e1"+
		"\u0005\u001e\u0000\u0000\u00e0\u00de\u0001\u0000\u0000\u0000\u00e1\u00e4"+
		"\u0001\u0000\u0000\u0000\u00e2\u00e0\u0001\u0000\u0000\u0000\u00e2\u00e3"+
		"\u0001\u0000\u0000\u0000\u00e3\u00e5\u0001\u0000\u0000\u0000\u00e4\u00e2"+
		"\u0001\u0000\u0000\u0000\u00e5\u00e6\u00050\u0000\u0000\u00e6\u0017\u0001"+
		"\u0000\u0000\u0000\u0017\u001d$\',49>DHMX|\u0085\u00aa\u00b2\u00b4\u00b9"+
		"\u00c9\u00d0\u00d3\u00d7\u00da\u00e2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}