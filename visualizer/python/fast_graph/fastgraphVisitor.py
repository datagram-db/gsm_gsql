# Generated from viz/fast_graph/fastgraph.g4 by ANTLR 4.11.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .fastgraphParser import fastgraphParser
else:
    from fastgraphParser import fastgraphParser

# This class defines a complete generic visitor for a parse tree produced by fastgraphParser.

class fastgraphVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by fastgraphParser#defn.
    def visitDefn(self, ctx:fastgraphParser.DefnContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#triplet.
    def visitTriplet(self, ctx:fastgraphParser.TripletContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#node.
    def visitNode(self, ctx:fastgraphParser.NodeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#edge.
    def visitEdge(self, ctx:fastgraphParser.EdgeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#stringlist.
    def visitStringlist(self, ctx:fastgraphParser.StringlistContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#properties.
    def visitProperties(self, ctx:fastgraphParser.PropertiesContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#string.
    def visitString(self, ctx:fastgraphParser.StringContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#floating.
    def visitFloating(self, ctx:fastgraphParser.FloatingContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#integer.
    def visitInteger(self, ctx:fastgraphParser.IntegerContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#roman.
    def visitRoman(self, ctx:fastgraphParser.RomanContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#units.
    def visitUnits(self, ctx:fastgraphParser.UnitsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#tens.
    def visitTens(self, ctx:fastgraphParser.TensContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#hundreds.
    def visitHundreds(self, ctx:fastgraphParser.HundredsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#one.
    def visitOne(self, ctx:fastgraphParser.OneContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#five.
    def visitFive(self, ctx:fastgraphParser.FiveContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#ten.
    def visitTen(self, ctx:fastgraphParser.TenContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#fifty.
    def visitFifty(self, ctx:fastgraphParser.FiftyContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#oneHundred.
    def visitOneHundred(self, ctx:fastgraphParser.OneHundredContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#fiveHundred.
    def visitFiveHundred(self, ctx:fastgraphParser.FiveHundredContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by fastgraphParser#oneThousand.
    def visitOneThousand(self, ctx:fastgraphParser.OneThousandContext):
        return self.visitChildren(ctx)



del fastgraphParser