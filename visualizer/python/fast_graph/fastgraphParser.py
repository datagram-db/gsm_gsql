# Generated from viz/fast_graph/fastgraph.g4 by ANTLR 4.11.1
# encoding: utf-8
from antlr4 import *
from io import StringIO
import sys
if sys.version_info[1] > 5:
	from typing import TextIO
else:
	from typing.io import TextIO

def serializedATN():
    return [
        4,1,26,200,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
        6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,
        2,14,7,14,2,15,7,15,2,16,7,16,2,17,7,17,1,0,1,0,1,0,5,0,40,8,0,10,
        0,12,0,43,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,52,8,1,1,1,1,1,1,1,
        1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,
        1,3,1,3,1,4,1,4,1,4,5,4,78,8,4,10,4,12,4,81,9,4,1,4,3,4,84,8,4,1,
        4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,5,5,94,8,5,10,5,12,5,97,9,5,1,5,1,
        5,1,5,3,5,102,8,5,1,5,1,5,1,6,1,6,1,6,3,6,109,8,6,1,7,5,7,112,8,
        7,10,7,12,7,115,9,7,1,7,3,7,118,8,7,1,7,3,7,121,8,7,1,7,3,7,124,
        8,7,1,8,1,8,5,8,128,8,8,10,8,12,8,131,9,8,1,8,1,8,3,8,135,8,8,1,
        8,1,8,5,8,139,8,8,10,8,12,8,142,9,8,3,8,144,8,8,1,9,1,9,5,9,148,
        8,9,10,9,12,9,151,9,9,1,9,1,9,3,9,155,8,9,1,9,1,9,5,9,159,8,9,10,
        9,12,9,162,9,9,3,9,164,8,9,1,10,1,10,5,10,168,8,10,10,10,12,10,171,
        9,10,1,10,1,10,3,10,175,8,10,1,10,1,10,5,10,179,8,10,10,10,12,10,
        182,9,10,3,10,184,8,10,1,11,1,11,1,12,1,12,1,13,1,13,1,14,1,14,1,
        15,1,15,1,16,1,16,1,17,1,17,1,17,0,0,18,0,2,4,6,8,10,12,14,16,18,
        20,22,24,26,28,30,32,34,0,0,210,0,41,1,0,0,0,2,44,1,0,0,0,4,58,1,
        0,0,0,6,67,1,0,0,0,8,74,1,0,0,0,10,87,1,0,0,0,12,108,1,0,0,0,14,
        113,1,0,0,0,16,143,1,0,0,0,18,163,1,0,0,0,20,183,1,0,0,0,22,185,
        1,0,0,0,24,187,1,0,0,0,26,189,1,0,0,0,28,191,1,0,0,0,30,193,1,0,
        0,0,32,195,1,0,0,0,34,197,1,0,0,0,36,40,3,2,1,0,37,40,3,4,2,0,38,
        40,3,6,3,0,39,36,1,0,0,0,39,37,1,0,0,0,39,38,1,0,0,0,40,43,1,0,0,
        0,41,39,1,0,0,0,41,42,1,0,0,0,42,1,1,0,0,0,43,41,1,0,0,0,44,45,5,
        1,0,0,45,46,5,21,0,0,46,47,5,2,0,0,47,48,5,3,0,0,48,51,3,14,7,0,
        49,50,5,4,0,0,50,52,5,22,0,0,51,49,1,0,0,0,51,52,1,0,0,0,52,53,1,
        0,0,0,53,54,5,5,0,0,54,55,5,1,0,0,55,56,5,21,0,0,56,57,5,2,0,0,57,
        3,1,0,0,0,58,59,5,1,0,0,59,60,5,21,0,0,60,61,5,6,0,0,61,62,3,8,4,
        0,62,63,5,7,0,0,63,64,3,8,4,0,64,65,3,10,5,0,65,66,5,2,0,0,66,5,
        1,0,0,0,67,68,5,8,0,0,68,69,3,14,7,0,69,70,5,6,0,0,70,71,3,8,4,0,
        71,72,3,10,5,0,72,73,5,9,0,0,73,7,1,0,0,0,74,79,5,8,0,0,75,76,5,
        20,0,0,76,78,5,4,0,0,77,75,1,0,0,0,78,81,1,0,0,0,79,77,1,0,0,0,79,
        80,1,0,0,0,80,83,1,0,0,0,81,79,1,0,0,0,82,84,5,20,0,0,83,82,1,0,
        0,0,83,84,1,0,0,0,84,85,1,0,0,0,85,86,5,9,0,0,86,9,1,0,0,0,87,95,
        5,10,0,0,88,89,5,20,0,0,89,90,5,6,0,0,90,91,3,12,6,0,91,92,5,11,
        0,0,92,94,1,0,0,0,93,88,1,0,0,0,94,97,1,0,0,0,95,93,1,0,0,0,95,96,
        1,0,0,0,96,101,1,0,0,0,97,95,1,0,0,0,98,99,5,20,0,0,99,100,5,6,0,
        0,100,102,3,12,6,0,101,98,1,0,0,0,101,102,1,0,0,0,102,103,1,0,0,
        0,103,104,5,12,0,0,104,11,1,0,0,0,105,109,5,20,0,0,106,109,5,22,
        0,0,107,109,5,23,0,0,108,105,1,0,0,0,108,106,1,0,0,0,108,107,1,0,
        0,0,109,13,1,0,0,0,110,112,3,34,17,0,111,110,1,0,0,0,112,115,1,0,
        0,0,113,111,1,0,0,0,113,114,1,0,0,0,114,117,1,0,0,0,115,113,1,0,
        0,0,116,118,3,20,10,0,117,116,1,0,0,0,117,118,1,0,0,0,118,120,1,
        0,0,0,119,121,3,18,9,0,120,119,1,0,0,0,120,121,1,0,0,0,121,123,1,
        0,0,0,122,124,3,16,8,0,123,122,1,0,0,0,123,124,1,0,0,0,124,15,1,
        0,0,0,125,134,3,22,11,0,126,128,3,22,11,0,127,126,1,0,0,0,128,131,
        1,0,0,0,129,127,1,0,0,0,129,130,1,0,0,0,130,135,1,0,0,0,131,129,
        1,0,0,0,132,135,3,24,12,0,133,135,3,26,13,0,134,129,1,0,0,0,134,
        132,1,0,0,0,134,133,1,0,0,0,135,144,1,0,0,0,136,140,3,24,12,0,137,
        139,3,22,11,0,138,137,1,0,0,0,139,142,1,0,0,0,140,138,1,0,0,0,140,
        141,1,0,0,0,141,144,1,0,0,0,142,140,1,0,0,0,143,125,1,0,0,0,143,
        136,1,0,0,0,144,17,1,0,0,0,145,154,3,26,13,0,146,148,3,26,13,0,147,
        146,1,0,0,0,148,151,1,0,0,0,149,147,1,0,0,0,149,150,1,0,0,0,150,
        155,1,0,0,0,151,149,1,0,0,0,152,155,3,28,14,0,153,155,3,30,15,0,
        154,149,1,0,0,0,154,152,1,0,0,0,154,153,1,0,0,0,155,164,1,0,0,0,
        156,160,3,28,14,0,157,159,3,26,13,0,158,157,1,0,0,0,159,162,1,0,
        0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,164,1,0,0,0,162,160,1,0,
        0,0,163,145,1,0,0,0,163,156,1,0,0,0,164,19,1,0,0,0,165,174,3,30,
        15,0,166,168,3,30,15,0,167,166,1,0,0,0,168,171,1,0,0,0,169,167,1,
        0,0,0,169,170,1,0,0,0,170,175,1,0,0,0,171,169,1,0,0,0,172,175,3,
        32,16,0,173,175,3,34,17,0,174,169,1,0,0,0,174,172,1,0,0,0,174,173,
        1,0,0,0,175,184,1,0,0,0,176,180,3,32,16,0,177,179,3,30,15,0,178,
        177,1,0,0,0,179,182,1,0,0,0,180,178,1,0,0,0,180,181,1,0,0,0,181,
        184,1,0,0,0,182,180,1,0,0,0,183,165,1,0,0,0,183,176,1,0,0,0,184,
        21,1,0,0,0,185,186,5,13,0,0,186,23,1,0,0,0,187,188,5,14,0,0,188,
        25,1,0,0,0,189,190,5,15,0,0,190,27,1,0,0,0,191,192,5,16,0,0,192,
        29,1,0,0,0,193,194,5,17,0,0,194,31,1,0,0,0,195,196,5,18,0,0,196,
        33,1,0,0,0,197,198,5,19,0,0,198,35,1,0,0,0,24,39,41,51,79,83,95,
        101,108,113,117,120,123,129,134,140,143,149,154,160,163,169,174,
        180,183
    ]

class fastgraphParser ( Parser ):

    grammarFileName = "fastgraph.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "'('", "')'", "'--['", "','", "']->'", 
                     "':'", "'='", "'['", "']'", "'{'", "';'", "'}'", "'i'", 
                     "'v'", "'x'", "'l'", "'c'", "'d'", "'m'" ]

    symbolicNames = [ "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "EscapedString", "DIGIT", "NUMBER", "INTEGER", "COMMENT", 
                      "LINE_COMMENT", "WS" ]

    RULE_defn = 0
    RULE_triplet = 1
    RULE_node = 2
    RULE_edge = 3
    RULE_stringlist = 4
    RULE_properties = 5
    RULE_value = 6
    RULE_roman = 7
    RULE_units = 8
    RULE_tens = 9
    RULE_hundreds = 10
    RULE_one = 11
    RULE_five = 12
    RULE_ten = 13
    RULE_fifty = 14
    RULE_oneHundred = 15
    RULE_fiveHundred = 16
    RULE_oneThousand = 17

    ruleNames =  [ "defn", "triplet", "node", "edge", "stringlist", "properties", 
                   "value", "roman", "units", "tens", "hundreds", "one", 
                   "five", "ten", "fifty", "oneHundred", "fiveHundred", 
                   "oneThousand" ]

    EOF = Token.EOF
    T__0=1
    T__1=2
    T__2=3
    T__3=4
    T__4=5
    T__5=6
    T__6=7
    T__7=8
    T__8=9
    T__9=10
    T__10=11
    T__11=12
    T__12=13
    T__13=14
    T__14=15
    T__15=16
    T__16=17
    T__17=18
    T__18=19
    EscapedString=20
    DIGIT=21
    NUMBER=22
    INTEGER=23
    COMMENT=24
    LINE_COMMENT=25
    WS=26

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.11.1")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None




    class DefnContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def triplet(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(fastgraphParser.TripletContext)
            else:
                return self.getTypedRuleContext(fastgraphParser.TripletContext,i)


        def node(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(fastgraphParser.NodeContext)
            else:
                return self.getTypedRuleContext(fastgraphParser.NodeContext,i)


        def edge(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(fastgraphParser.EdgeContext)
            else:
                return self.getTypedRuleContext(fastgraphParser.EdgeContext,i)


        def getRuleIndex(self):
            return fastgraphParser.RULE_defn

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterDefn" ):
                listener.enterDefn(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitDefn" ):
                listener.exitDefn(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitDefn" ):
                return visitor.visitDefn(self)
            else:
                return visitor.visitChildren(self)




    def defn(self):

        localctx = fastgraphParser.DefnContext(self, self._ctx, self.state)
        self.enterRule(localctx, 0, self.RULE_defn)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 41
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while _la==1 or _la==8:
                self.state = 39
                self._errHandler.sync(self)
                la_ = self._interp.adaptivePredict(self._input,0,self._ctx)
                if la_ == 1:
                    self.state = 36
                    self.triplet()
                    pass

                elif la_ == 2:
                    self.state = 37
                    self.node()
                    pass

                elif la_ == 3:
                    self.state = 38
                    self.edge()
                    pass


                self.state = 43
                self._errHandler.sync(self)
                _la = self._input.LA(1)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class TripletContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser
            self.src = None # Token
            self.edgeId = None # RomanContext
            self.dst = None # Token

        def DIGIT(self, i:int=None):
            if i is None:
                return self.getTokens(fastgraphParser.DIGIT)
            else:
                return self.getToken(fastgraphParser.DIGIT, i)

        def roman(self):
            return self.getTypedRuleContext(fastgraphParser.RomanContext,0)


        def NUMBER(self):
            return self.getToken(fastgraphParser.NUMBER, 0)

        def getRuleIndex(self):
            return fastgraphParser.RULE_triplet

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterTriplet" ):
                listener.enterTriplet(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitTriplet" ):
                listener.exitTriplet(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitTriplet" ):
                return visitor.visitTriplet(self)
            else:
                return visitor.visitChildren(self)




    def triplet(self):

        localctx = fastgraphParser.TripletContext(self, self._ctx, self.state)
        self.enterRule(localctx, 2, self.RULE_triplet)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 44
            self.match(fastgraphParser.T__0)
            self.state = 45
            localctx.src = self.match(fastgraphParser.DIGIT)
            self.state = 46
            self.match(fastgraphParser.T__1)
            self.state = 47
            self.match(fastgraphParser.T__2)
            self.state = 48
            localctx.edgeId = self.roman()
            self.state = 51
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            if _la==4:
                self.state = 49
                self.match(fastgraphParser.T__3)
                self.state = 50
                self.match(fastgraphParser.NUMBER)


            self.state = 53
            self.match(fastgraphParser.T__4)
            self.state = 54
            self.match(fastgraphParser.T__0)
            self.state = 55
            localctx.dst = self.match(fastgraphParser.DIGIT)
            self.state = 56
            self.match(fastgraphParser.T__1)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class NodeContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser
            self.id_ = None # Token
            self.labels = None # StringlistContext
            self.xi = None # StringlistContext

        def properties(self):
            return self.getTypedRuleContext(fastgraphParser.PropertiesContext,0)


        def DIGIT(self):
            return self.getToken(fastgraphParser.DIGIT, 0)

        def stringlist(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(fastgraphParser.StringlistContext)
            else:
                return self.getTypedRuleContext(fastgraphParser.StringlistContext,i)


        def getRuleIndex(self):
            return fastgraphParser.RULE_node

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterNode" ):
                listener.enterNode(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitNode" ):
                listener.exitNode(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitNode" ):
                return visitor.visitNode(self)
            else:
                return visitor.visitChildren(self)




    def node(self):

        localctx = fastgraphParser.NodeContext(self, self._ctx, self.state)
        self.enterRule(localctx, 4, self.RULE_node)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 58
            self.match(fastgraphParser.T__0)
            self.state = 59
            localctx.id_ = self.match(fastgraphParser.DIGIT)
            self.state = 60
            self.match(fastgraphParser.T__5)
            self.state = 61
            localctx.labels = self.stringlist()
            self.state = 62
            self.match(fastgraphParser.T__6)
            self.state = 63
            localctx.xi = self.stringlist()
            self.state = 64
            self.properties()
            self.state = 65
            self.match(fastgraphParser.T__1)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class EdgeContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser
            self.id_ = None # RomanContext
            self.labels = None # StringlistContext

        def properties(self):
            return self.getTypedRuleContext(fastgraphParser.PropertiesContext,0)


        def roman(self):
            return self.getTypedRuleContext(fastgraphParser.RomanContext,0)


        def stringlist(self):
            return self.getTypedRuleContext(fastgraphParser.StringlistContext,0)


        def getRuleIndex(self):
            return fastgraphParser.RULE_edge

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterEdge" ):
                listener.enterEdge(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitEdge" ):
                listener.exitEdge(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitEdge" ):
                return visitor.visitEdge(self)
            else:
                return visitor.visitChildren(self)




    def edge(self):

        localctx = fastgraphParser.EdgeContext(self, self._ctx, self.state)
        self.enterRule(localctx, 6, self.RULE_edge)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 67
            self.match(fastgraphParser.T__7)
            self.state = 68
            localctx.id_ = self.roman()
            self.state = 69
            self.match(fastgraphParser.T__5)
            self.state = 70
            localctx.labels = self.stringlist()
            self.state = 71
            self.properties()
            self.state = 72
            self.match(fastgraphParser.T__8)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class StringlistContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def EscapedString(self, i:int=None):
            if i is None:
                return self.getTokens(fastgraphParser.EscapedString)
            else:
                return self.getToken(fastgraphParser.EscapedString, i)

        def getRuleIndex(self):
            return fastgraphParser.RULE_stringlist

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterStringlist" ):
                listener.enterStringlist(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitStringlist" ):
                listener.exitStringlist(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitStringlist" ):
                return visitor.visitStringlist(self)
            else:
                return visitor.visitChildren(self)




    def stringlist(self):

        localctx = fastgraphParser.StringlistContext(self, self._ctx, self.state)
        self.enterRule(localctx, 8, self.RULE_stringlist)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 74
            self.match(fastgraphParser.T__7)
            self.state = 79
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,3,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    self.state = 75
                    self.match(fastgraphParser.EscapedString)
                    self.state = 76
                    self.match(fastgraphParser.T__3) 
                self.state = 81
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,3,self._ctx)

            self.state = 83
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            if _la==20:
                self.state = 82
                self.match(fastgraphParser.EscapedString)


            self.state = 85
            self.match(fastgraphParser.T__8)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class PropertiesContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def EscapedString(self, i:int=None):
            if i is None:
                return self.getTokens(fastgraphParser.EscapedString)
            else:
                return self.getToken(fastgraphParser.EscapedString, i)

        def value(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(fastgraphParser.ValueContext)
            else:
                return self.getTypedRuleContext(fastgraphParser.ValueContext,i)


        def getRuleIndex(self):
            return fastgraphParser.RULE_properties

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterProperties" ):
                listener.enterProperties(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitProperties" ):
                listener.exitProperties(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitProperties" ):
                return visitor.visitProperties(self)
            else:
                return visitor.visitChildren(self)




    def properties(self):

        localctx = fastgraphParser.PropertiesContext(self, self._ctx, self.state)
        self.enterRule(localctx, 10, self.RULE_properties)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 87
            self.match(fastgraphParser.T__9)
            self.state = 95
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,5,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    self.state = 88
                    self.match(fastgraphParser.EscapedString)
                    self.state = 89
                    self.match(fastgraphParser.T__5)
                    self.state = 90
                    self.value()
                    self.state = 91
                    self.match(fastgraphParser.T__10) 
                self.state = 97
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,5,self._ctx)

            self.state = 101
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            if _la==20:
                self.state = 98
                self.match(fastgraphParser.EscapedString)
                self.state = 99
                self.match(fastgraphParser.T__5)
                self.state = 100
                self.value()


            self.state = 103
            self.match(fastgraphParser.T__11)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class ValueContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return fastgraphParser.RULE_value

     
        def copyFrom(self, ctx:ParserRuleContext):
            super().copyFrom(ctx)



    class StringContext(ValueContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a fastgraphParser.ValueContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def EscapedString(self):
            return self.getToken(fastgraphParser.EscapedString, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterString" ):
                listener.enterString(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitString" ):
                listener.exitString(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitString" ):
                return visitor.visitString(self)
            else:
                return visitor.visitChildren(self)


    class FloatingContext(ValueContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a fastgraphParser.ValueContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def NUMBER(self):
            return self.getToken(fastgraphParser.NUMBER, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterFloating" ):
                listener.enterFloating(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitFloating" ):
                listener.exitFloating(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitFloating" ):
                return visitor.visitFloating(self)
            else:
                return visitor.visitChildren(self)


    class IntegerContext(ValueContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a fastgraphParser.ValueContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def INTEGER(self):
            return self.getToken(fastgraphParser.INTEGER, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterInteger" ):
                listener.enterInteger(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitInteger" ):
                listener.exitInteger(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitInteger" ):
                return visitor.visitInteger(self)
            else:
                return visitor.visitChildren(self)



    def value(self):

        localctx = fastgraphParser.ValueContext(self, self._ctx, self.state)
        self.enterRule(localctx, 12, self.RULE_value)
        try:
            self.state = 108
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [20]:
                localctx = fastgraphParser.StringContext(self, localctx)
                self.enterOuterAlt(localctx, 1)
                self.state = 105
                self.match(fastgraphParser.EscapedString)
                pass
            elif token in [22]:
                localctx = fastgraphParser.FloatingContext(self, localctx)
                self.enterOuterAlt(localctx, 2)
                self.state = 106
                self.match(fastgraphParser.NUMBER)
                pass
            elif token in [23]:
                localctx = fastgraphParser.IntegerContext(self, localctx)
                self.enterOuterAlt(localctx, 3)
                self.state = 107
                self.match(fastgraphParser.INTEGER)
                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class RomanContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def oneThousand(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(fastgraphParser.OneThousandContext)
            else:
                return self.getTypedRuleContext(fastgraphParser.OneThousandContext,i)


        def hundreds(self):
            return self.getTypedRuleContext(fastgraphParser.HundredsContext,0)


        def tens(self):
            return self.getTypedRuleContext(fastgraphParser.TensContext,0)


        def units(self):
            return self.getTypedRuleContext(fastgraphParser.UnitsContext,0)


        def getRuleIndex(self):
            return fastgraphParser.RULE_roman

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterRoman" ):
                listener.enterRoman(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitRoman" ):
                listener.exitRoman(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitRoman" ):
                return visitor.visitRoman(self)
            else:
                return visitor.visitChildren(self)




    def roman(self):

        localctx = fastgraphParser.RomanContext(self, self._ctx, self.state)
        self.enterRule(localctx, 14, self.RULE_roman)
        self._la = 0 # Token type
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 113
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            while _la==19:
                self.state = 110
                self.oneThousand()
                self.state = 115
                self._errHandler.sync(self)
                _la = self._input.LA(1)

            self.state = 117
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            if _la==17 or _la==18:
                self.state = 116
                self.hundreds()


            self.state = 120
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            if _la==15 or _la==16:
                self.state = 119
                self.tens()


            self.state = 123
            self._errHandler.sync(self)
            _la = self._input.LA(1)
            if _la==13 or _la==14:
                self.state = 122
                self.units()


        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class UnitsContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def one(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(fastgraphParser.OneContext)
            else:
                return self.getTypedRuleContext(fastgraphParser.OneContext,i)


        def five(self):
            return self.getTypedRuleContext(fastgraphParser.FiveContext,0)


        def ten(self):
            return self.getTypedRuleContext(fastgraphParser.TenContext,0)


        def getRuleIndex(self):
            return fastgraphParser.RULE_units

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterUnits" ):
                listener.enterUnits(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitUnits" ):
                listener.exitUnits(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitUnits" ):
                return visitor.visitUnits(self)
            else:
                return visitor.visitChildren(self)




    def units(self):

        localctx = fastgraphParser.UnitsContext(self, self._ctx, self.state)
        self.enterRule(localctx, 16, self.RULE_units)
        self._la = 0 # Token type
        try:
            self.state = 143
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [13]:
                self.enterOuterAlt(localctx, 1)
                self.state = 125
                self.one()
                self.state = 134
                self._errHandler.sync(self)
                token = self._input.LA(1)
                if token in [4, 5, 6, 13]:
                    self.state = 129
                    self._errHandler.sync(self)
                    _la = self._input.LA(1)
                    while _la==13:
                        self.state = 126
                        self.one()
                        self.state = 131
                        self._errHandler.sync(self)
                        _la = self._input.LA(1)

                    pass
                elif token in [14]:
                    self.state = 132
                    self.five()
                    pass
                elif token in [15]:
                    self.state = 133
                    self.ten()
                    pass
                else:
                    raise NoViableAltException(self)

                pass
            elif token in [14]:
                self.enterOuterAlt(localctx, 2)
                self.state = 136
                self.five()
                self.state = 140
                self._errHandler.sync(self)
                _la = self._input.LA(1)
                while _la==13:
                    self.state = 137
                    self.one()
                    self.state = 142
                    self._errHandler.sync(self)
                    _la = self._input.LA(1)

                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class TensContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def ten(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(fastgraphParser.TenContext)
            else:
                return self.getTypedRuleContext(fastgraphParser.TenContext,i)


        def fifty(self):
            return self.getTypedRuleContext(fastgraphParser.FiftyContext,0)


        def oneHundred(self):
            return self.getTypedRuleContext(fastgraphParser.OneHundredContext,0)


        def getRuleIndex(self):
            return fastgraphParser.RULE_tens

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterTens" ):
                listener.enterTens(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitTens" ):
                listener.exitTens(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitTens" ):
                return visitor.visitTens(self)
            else:
                return visitor.visitChildren(self)




    def tens(self):

        localctx = fastgraphParser.TensContext(self, self._ctx, self.state)
        self.enterRule(localctx, 18, self.RULE_tens)
        self._la = 0 # Token type
        try:
            self.state = 163
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [15]:
                self.enterOuterAlt(localctx, 1)
                self.state = 145
                self.ten()
                self.state = 154
                self._errHandler.sync(self)
                token = self._input.LA(1)
                if token in [4, 5, 6, 13, 14, 15]:
                    self.state = 149
                    self._errHandler.sync(self)
                    _la = self._input.LA(1)
                    while _la==15:
                        self.state = 146
                        self.ten()
                        self.state = 151
                        self._errHandler.sync(self)
                        _la = self._input.LA(1)

                    pass
                elif token in [16]:
                    self.state = 152
                    self.fifty()
                    pass
                elif token in [17]:
                    self.state = 153
                    self.oneHundred()
                    pass
                else:
                    raise NoViableAltException(self)

                pass
            elif token in [16]:
                self.enterOuterAlt(localctx, 2)
                self.state = 156
                self.fifty()
                self.state = 160
                self._errHandler.sync(self)
                _la = self._input.LA(1)
                while _la==15:
                    self.state = 157
                    self.ten()
                    self.state = 162
                    self._errHandler.sync(self)
                    _la = self._input.LA(1)

                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class HundredsContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser

        def oneHundred(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(fastgraphParser.OneHundredContext)
            else:
                return self.getTypedRuleContext(fastgraphParser.OneHundredContext,i)


        def fiveHundred(self):
            return self.getTypedRuleContext(fastgraphParser.FiveHundredContext,0)


        def oneThousand(self):
            return self.getTypedRuleContext(fastgraphParser.OneThousandContext,0)


        def getRuleIndex(self):
            return fastgraphParser.RULE_hundreds

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterHundreds" ):
                listener.enterHundreds(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitHundreds" ):
                listener.exitHundreds(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitHundreds" ):
                return visitor.visitHundreds(self)
            else:
                return visitor.visitChildren(self)




    def hundreds(self):

        localctx = fastgraphParser.HundredsContext(self, self._ctx, self.state)
        self.enterRule(localctx, 20, self.RULE_hundreds)
        self._la = 0 # Token type
        try:
            self.state = 183
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [17]:
                self.enterOuterAlt(localctx, 1)
                self.state = 165
                self.oneHundred()
                self.state = 174
                self._errHandler.sync(self)
                token = self._input.LA(1)
                if token in [4, 5, 6, 13, 14, 15, 16, 17]:
                    self.state = 169
                    self._errHandler.sync(self)
                    _la = self._input.LA(1)
                    while _la==17:
                        self.state = 166
                        self.oneHundred()
                        self.state = 171
                        self._errHandler.sync(self)
                        _la = self._input.LA(1)

                    pass
                elif token in [18]:
                    self.state = 172
                    self.fiveHundred()
                    pass
                elif token in [19]:
                    self.state = 173
                    self.oneThousand()
                    pass
                else:
                    raise NoViableAltException(self)

                pass
            elif token in [18]:
                self.enterOuterAlt(localctx, 2)
                self.state = 176
                self.fiveHundred()
                self.state = 180
                self._errHandler.sync(self)
                _la = self._input.LA(1)
                while _la==17:
                    self.state = 177
                    self.oneHundred()
                    self.state = 182
                    self._errHandler.sync(self)
                    _la = self._input.LA(1)

                pass
            else:
                raise NoViableAltException(self)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class OneContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return fastgraphParser.RULE_one

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterOne" ):
                listener.enterOne(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitOne" ):
                listener.exitOne(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitOne" ):
                return visitor.visitOne(self)
            else:
                return visitor.visitChildren(self)




    def one(self):

        localctx = fastgraphParser.OneContext(self, self._ctx, self.state)
        self.enterRule(localctx, 22, self.RULE_one)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 185
            self.match(fastgraphParser.T__12)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class FiveContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return fastgraphParser.RULE_five

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterFive" ):
                listener.enterFive(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitFive" ):
                listener.exitFive(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitFive" ):
                return visitor.visitFive(self)
            else:
                return visitor.visitChildren(self)




    def five(self):

        localctx = fastgraphParser.FiveContext(self, self._ctx, self.state)
        self.enterRule(localctx, 24, self.RULE_five)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 187
            self.match(fastgraphParser.T__13)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class TenContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return fastgraphParser.RULE_ten

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterTen" ):
                listener.enterTen(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitTen" ):
                listener.exitTen(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitTen" ):
                return visitor.visitTen(self)
            else:
                return visitor.visitChildren(self)




    def ten(self):

        localctx = fastgraphParser.TenContext(self, self._ctx, self.state)
        self.enterRule(localctx, 26, self.RULE_ten)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 189
            self.match(fastgraphParser.T__14)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class FiftyContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return fastgraphParser.RULE_fifty

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterFifty" ):
                listener.enterFifty(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitFifty" ):
                listener.exitFifty(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitFifty" ):
                return visitor.visitFifty(self)
            else:
                return visitor.visitChildren(self)




    def fifty(self):

        localctx = fastgraphParser.FiftyContext(self, self._ctx, self.state)
        self.enterRule(localctx, 28, self.RULE_fifty)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 191
            self.match(fastgraphParser.T__15)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class OneHundredContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return fastgraphParser.RULE_oneHundred

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterOneHundred" ):
                listener.enterOneHundred(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitOneHundred" ):
                listener.exitOneHundred(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitOneHundred" ):
                return visitor.visitOneHundred(self)
            else:
                return visitor.visitChildren(self)




    def oneHundred(self):

        localctx = fastgraphParser.OneHundredContext(self, self._ctx, self.state)
        self.enterRule(localctx, 30, self.RULE_oneHundred)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 193
            self.match(fastgraphParser.T__16)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class FiveHundredContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return fastgraphParser.RULE_fiveHundred

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterFiveHundred" ):
                listener.enterFiveHundred(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitFiveHundred" ):
                listener.exitFiveHundred(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitFiveHundred" ):
                return visitor.visitFiveHundred(self)
            else:
                return visitor.visitChildren(self)




    def fiveHundred(self):

        localctx = fastgraphParser.FiveHundredContext(self, self._ctx, self.state)
        self.enterRule(localctx, 32, self.RULE_fiveHundred)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 195
            self.match(fastgraphParser.T__17)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx


    class OneThousandContext(ParserRuleContext):
        __slots__ = 'parser'

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return fastgraphParser.RULE_oneThousand

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterOneThousand" ):
                listener.enterOneThousand(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitOneThousand" ):
                listener.exitOneThousand(self)

        def accept(self, visitor:ParseTreeVisitor):
            if hasattr( visitor, "visitOneThousand" ):
                return visitor.visitOneThousand(self)
            else:
                return visitor.visitChildren(self)




    def oneThousand(self):

        localctx = fastgraphParser.OneThousandContext(self, self._ctx, self.state)
        self.enterRule(localctx, 34, self.RULE_oneThousand)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 197
            self.match(fastgraphParser.T__18)
        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.exitRule()
        return localctx





