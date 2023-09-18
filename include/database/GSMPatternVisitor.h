//
// Created by giacomo on 12/09/23.
//

#ifndef GSM2_GSMPATTERNVISITOR_H
#define GSM2_GSMPATTERNVISITOR_H

#include <simple_graph_grammarBaseVisitor.h>
#include <optional>
#include <yaucl/structures/default_constructors.h>
#include <memory>
#include <variant>

struct rewrite_expr;
using test_side = std::variant<std::shared_ptr<rewrite_expr>,std::string>;
using test_eq = std::pair<test_side,test_side>;

struct rewrite_expr {
    enum cases {
        NONE_CASES_REWRITE = 0,
        NODE_XI,
        NODE_ELL,
        NODE_PROP,
        NODE_CONT,
        EDGE_LABEL,
        EDGE_SRC,
        EDGE_DST,
        VARIABLE,
        IFTE_RW,
        NODE_OR_EDGE
    };

    cases t;
    size_t id;
    std::shared_ptr<rewrite_expr>   pi_key_arg_or_then=nullptr;
    std::shared_ptr<rewrite_expr>   ptr_or_else=nullptr;
    test_eq      ifcond;
    std::string prop;

    rewrite_expr() : t{NONE_CASES_REWRITE}, id{0}, ptr_or_else{nullptr}, pi_key_arg_or_then{nullptr}, prop{} {
        std::shared_ptr<rewrite_expr> o{nullptr};
        ifcond.first = ifcond.second = o;
    };
    DEFAULT_COPY_ASSGN(rewrite_expr);
};



#include <variant>



struct edge_match {
    bool forall{false};
    bool question_mark{false};
    std::optional<std::string> var;
    std::vector<std::string> type;

    DEFAULT_CONSTRUCTORS(edge_match);
    std::vector<size_t> outputQuery;
};

static inline
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

struct rewrite_to {
    enum cases {
        DEL_RW,
        NEU_RW,
        SET_RW,
        NONE_OF_REWRITE
    };
    std::shared_ptr<rewrite_expr> from{nullptr}, to{nullptr};
    std::string  others;
    cases        t;

    rewrite_to() : from{nullptr}, to{nullptr},  others{}, t{NONE_OF_REWRITE} {}
    DEFAULT_COPY_ASSGN(rewrite_to);
};

struct node_match {
    bool star{false};
    bool vec{false};
    std::vector<std::string> var;
    std::optional<std::string> type;
    std::string pattern_name;
    std::vector<std::pair<edge_match, node_match>> out;
    std::vector<std::pair<node_match, edge_match>> in;
    std::vector<edge_match> hook;
    std::vector<node_match> join_edges;

    bool has_rewrite{false};
    std::shared_ptr<node_match> rewrite_match_dst{nullptr};
    std::vector<rewrite_to> rwr_to;


    node_match() : star{false}, vec{false}, has_rewrite{false}, var{}, type{}, pattern_name{}, out{}, in{}, hook{}, join_edges{}, rewrite_match_dst{nullptr} {};
    DEFAULT_COPY_ASSGN(node_match);
};




class GSMPatternVisitor : public simple_graph_grammarBaseVisitor {
public:



    std::any visitNeu_obj(simple_graph_grammarParser::Neu_objContext *ctx) override {
        if (ctx) {
            rewrite_to result;
            result.t = rewrite_to::NEU_RW;
            result.others = ctx->OTHERS()->getText();
            return {result};
        }
        return {};
    }

    std::any visitNode_containment(simple_graph_grammarParser::Node_containmentContext *ctx) override {
        std::shared_ptr<rewrite_expr> ptr{nullptr};
        if (ctx) {

            ptr = std::make_shared<rewrite_expr>();
            ptr->pi_key_arg_or_then = std::any_cast<std::shared_ptr<rewrite_expr> >(visit(ctx->key));
            ptr->ptr_or_else = std::any_cast<std::shared_ptr<rewrite_expr> >(visit(ctx->nodeVar));
            ptr->prop = ctx->key->getText();
            ptr->t = rewrite_expr::NODE_CONT;


//            ptr = std::make_shared<rewrite_expr>();
//            ptr->ptr_or_else = std::any_cast<std::shared_ptr<rewrite_expr>>(visit(ctx->nodeVar));
//            ptr->prop = ctx->key->getText();
//            ptr->t = rewrite_expr::NODE_CONT;
        }
        return {ptr};
    }

    std::any visitDel_node_or_edge(simple_graph_grammarParser::Del_node_or_edgeContext *ctx) override {
        if (ctx) {
            rewrite_to result;
            result.t = rewrite_to::DEL_RW;
            result.others = ctx->OTHERS()->getText();
            return {result};
        }
        return {};
    }

    std::any visitUpdate_expr(simple_graph_grammarParser::Update_exprContext *ctx) override {
        if (ctx) {
            rewrite_to result;
            result.t = rewrite_to::SET_RW;
            result.from = std::any_cast<std::shared_ptr<rewrite_expr>>(visit(ctx->from));
            result.to = std::any_cast<std::shared_ptr<rewrite_expr>>(visit(ctx->to));
            return {result};
        }
        return {};
    }

    std::any visitIfte_expr(simple_graph_grammarParser::Ifte_exprContext *ctx) override {
        if (ctx) {
            std::shared_ptr<rewrite_expr> result = std::make_shared<rewrite_expr>();
            result->t = rewrite_expr::IFTE_RW;
            result->ifcond = std::any_cast<test_eq>(visit(ctx->ifcond));
            result->pi_key_arg_or_then = std::any_cast< std::shared_ptr<rewrite_expr>>(visit(ctx->then_effect));
            if (ctx->else_effect) {
                result->ptr_or_else = std::any_cast< std::shared_ptr<rewrite_expr>>(visit(ctx->else_effect));
            } else {
                result->ptr_or_else = nullptr;
            }
            return {result};
        }
        return {};
    }

    std::any visitNode_xi(simple_graph_grammarParser::Node_xiContext *ctx) override {
        std::shared_ptr<rewrite_expr> ptr{nullptr};
        if (ctx) {
            auto str = ctx->num->getText();
            if (is_number(str)) {
                ptr = std::make_shared<rewrite_expr>();
                ptr->ptr_or_else = std::any_cast< std::shared_ptr<rewrite_expr>>(visit(ctx->nodeVar));
                ptr->id = std::stoull(str);
                ptr->t = rewrite_expr::NODE_XI;
            }
        }
        return {ptr};
    }

    std::any visitNode_ell(simple_graph_grammarParser::Node_ellContext *ctx) override {
        std::shared_ptr<rewrite_expr> ptr{nullptr};
        if (ctx) {
            auto str = ctx->num->getText();
            if (is_number(str)) {
                ptr = std::make_shared<rewrite_expr>();
                ptr->ptr_or_else = std::any_cast<std::shared_ptr<rewrite_expr> >(visit(ctx->nodeVar));
                ptr->id = std::stoull(str);
                ptr->t = rewrite_expr::NODE_ELL;
            }
        }
        return {ptr};
    }

    std::any visitJust_par(simple_graph_grammarParser::Just_parContext *ctx) override {
        if (ctx) {
            return visit(ctx->rewrite_expr());
        }
        return {};
    }

    std::any visitNode_prop(simple_graph_grammarParser::Node_propContext *ctx) override {
        std::shared_ptr<rewrite_expr> ptr{nullptr};
        if (ctx) {
            ptr = std::make_shared<rewrite_expr>();
            ptr->pi_key_arg_or_then = std::any_cast<std::shared_ptr<rewrite_expr> >(visit(ctx->key));
            ptr->ptr_or_else = std::any_cast<std::shared_ptr<rewrite_expr> >(visit(ctx->nodeVar));
            ptr->prop = ctx->key->getText();
            ptr->t = rewrite_expr::NODE_PROP;
        }
        return {ptr};
    }

    std::any visitEdge_label(simple_graph_grammarParser::Edge_labelContext *ctx) override {
        std::shared_ptr<rewrite_expr> ptr{nullptr};
        if (ctx) {
            ptr = std::make_shared<rewrite_expr>();
            ptr->ptr_or_else = std::any_cast<std::shared_ptr<rewrite_expr> >(visit(ctx->edgeVar));
            ptr->t = rewrite_expr::EDGE_LABEL;
        }
        return {ptr};
    }

    std::any visitEdge_src(simple_graph_grammarParser::Edge_srcContext *ctx) override {
                std::shared_ptr<rewrite_expr> ptr{nullptr};
        if (ctx) {
            ptr = std::make_shared<rewrite_expr>();
            ptr->ptr_or_else = std::any_cast<std::shared_ptr<rewrite_expr> >(visit(ctx->edgeVar));
            ptr->t = rewrite_expr::EDGE_SRC;
        }
        return {ptr};
    }

    std::any visitEdge_dst(simple_graph_grammarParser::Edge_dstContext *ctx) override {
                std::shared_ptr<rewrite_expr> ptr{nullptr};
        if (ctx) {
            ptr = std::make_shared<rewrite_expr>();
            ptr->ptr_or_else = std::any_cast<std::shared_ptr<rewrite_expr> >(visit(ctx->edgeVar));
            ptr->t = rewrite_expr::EDGE_DST;
        }
        return {ptr};
    }

    std::any visitNode_or_edge(simple_graph_grammarParser::Node_or_edgeContext *ctx) override {
                std::shared_ptr<rewrite_expr> ptr{nullptr};
        if (ctx) {
            ptr = std::make_shared<rewrite_expr>();
            ptr->prop = ctx->OTHERS()->getText();
            ptr->t = rewrite_expr::VARIABLE;
        }
        return {ptr};
    }

    std::any visitTest_expr(simple_graph_grammarParser::Test_exprContext *ctx) override {
        if (ctx) {
            return {std::make_pair(std::any_cast<test_side>(visit(ctx->src)),
                                   std::any_cast<test_side>(visit(ctx->dst)))
            };
        }
        return {};
    }

    std::any visitTest_data(simple_graph_grammarParser::Test_dataContext *ctx) override {
        if (ctx) {
            test_side obj;
            obj = std::any_cast<std::shared_ptr<rewrite_expr> >(visit(ctx->rewrite_expr()));
            return {obj};
        }
        return {};
    }

    std::any visitTest_value(simple_graph_grammarParser::Test_valueContext *ctx) override {
        if (ctx) {
            test_side obj;
            obj = ctx->OTHERS()->getText();
            return {obj};
        }
        return {};
    }

    std::any visitAll_matches(simple_graph_grammarParser::All_matchesContext *ctx) override {
        // visiting all the patterns associated to the query
        std::vector<node_match> l;
        if (ctx) {
            for (const auto& ref : ctx->centralmatch()) {
                l.emplace_back(std::any_cast<node_match>(visitCentralmatch(ref)));
            }
        }
        return {l};
    }

    void extract_ego_edges(node_match &result,
                           simple_graph_grammarParser::EdgeContext *const &ego_edges)  {
        auto tmp = visit(ego_edges);
        edge_match em;
        node_match nm;
        bool casus;
        std::string tmpType = tmp.type().name();
        if (tmpType.contains("tuple")) {
            std::tie(em, nm, casus) = std::any_cast<std::tuple<edge_match,node_match,bool>>(tmp);
            if (casus) {
                result.out.emplace_back(em, nm);
            } else {
                result.in.emplace_back(nm, em);
            }
        } else if (tmpType.contains("edge_match")) {
            result.hook.emplace_back(std::any_cast<edge_match>(tmp));
        }
    }

    std::any visitCentralmatch(simple_graph_grammarParser::CentralmatchContext *ctx) override {
        if (ctx) {
            auto result = std::any_cast<node_match>(visitNode(ctx->src));
            result.pattern_name = ctx->var->getText();

            if (ctx->e1) {
                for (const auto& ego_edges : ctx->e1->edge()) {
                    extract_ego_edges(result, ego_edges);
                }
            }

            for (const auto& join_edges : ctx->edge_joining()) {
                result.join_edges.emplace_back(std::any_cast<node_match>(visitEdge_joining(join_edges)));
            }

            if (ctx->REWRITE_TO()) {
                result.has_rewrite = true;
                for (const auto& ref : ctx->rewrite_to()) {
                    result.rwr_to.emplace_back(std::any_cast<rewrite_to>(visit(ref)));
                }

                result.rewrite_match_dst = std::make_shared<node_match>();
                *result.rewrite_match_dst = std::any_cast<node_match>(visit(ctx->dst));
//                if (ctx->e2) {
//                    for (const auto& ego_edges : ctx->e2->edge()) {
//                        extract_ego_edges(*result.rewrite_match_dst, ego_edges);
//                    }
//                }
            }
            return {result};
        }
        return {};
    }

    std::any visitNode(simple_graph_grammarParser::NodeContext *ctx) override {
        if (ctx) {
            node_match match;
            match.star = (ctx->STAR());
            match.vec = (ctx->VEC());
            match.var = std::any_cast<std::vector<std::string>>(visitMultiple_labels(ctx->multiple_labels()));
            if (ctx->OTHERS()) {
                match.type = ctx->OTHERS()->getText();
            }
            return {match};
        }
        return {};
    }

    std::any visitOutedge(simple_graph_grammarParser::OutedgeContext *ctx) override {
        if (ctx) {
            return std::make_tuple<edge_match,node_match,bool>(std::any_cast<edge_match>(visitEdgelabel(ctx->edgelabel())),
                                                         std::any_cast<node_match>(visitNode(ctx->node())),
                                                                 true
                                                        );
        }
        return {};
    }

    std::any visitInedge(simple_graph_grammarParser::InedgeContext *ctx) override {
        if (ctx) {
            return std::make_tuple<edge_match,node_match,bool>(std::any_cast<edge_match>(visitEdgelabel(ctx->edgelabel())),
                                                         std::any_cast<node_match>(visitNode(ctx->node())),
                                                                 false
            );
        }
        return {};
    }

    std::any visitHook(simple_graph_grammarParser::HookContext *ctx) override {
        if (ctx) {
            return visitEdgelabel(ctx->edgelabel());
        }
        return {};
    }

    std::any visitEdge_joining(simple_graph_grammarParser::Edge_joiningContext *ctx) override {
        if (ctx) {
            auto n = std::any_cast<node_match>(visitNode(ctx->node()));
            extract_ego_edges(n, ctx->edge());
            return {n};
        }
        return {};
    }

    std::any visitEdgelabel(simple_graph_grammarParser::EdgelabelContext *ctx) override {
        if (ctx) {
            edge_match em;
            em.forall = (ctx->FORALL());
            em.question_mark = (ctx->QM());
            if (ctx->var) {
                em.var = ctx->var->getText();
            }
            em.type = std::any_cast<std::vector<std::string>>(visitMultiple_labels(ctx->multiple_labels()));
            return {em};
        }
        return {};
    }

    std::any visitMultiple_labels(simple_graph_grammarParser::Multiple_labelsContext *ctx) override {
        std::vector<std::string> l;
        if (ctx) {
            for (const auto& lab : ctx->OTHERS()) {
                l.emplace_back(lab->getText());
            }
        }
        return {l};
    }
};


#endif //GSM2_GSMPATTERNVISITOR_H
