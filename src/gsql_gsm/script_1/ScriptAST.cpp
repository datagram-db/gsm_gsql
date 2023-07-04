//
// Created by giacomo on 09/04/23.
//

#include <iostream>
#include <utility>
#include <gsql_gsm/script_1/ScriptAST.h>
DPtr<script::structures::ScriptAST> script::structures::ScriptAST::TRUE;
DPtr<script::structures::ScriptAST> script::structures::ScriptAST::FALSE;
DPtr<script::structures::ScriptAST> script::structures::ScriptAST::DOUBLET;
DPtr<script::structures::ScriptAST> script::structures::ScriptAST::INTEGERT;
DPtr<script::structures::ScriptAST> script::structures::ScriptAST::BOOLEANT;
DPtr<script::structures::ScriptAST> script::structures::ScriptAST::STRINGT;
DPtr<script::structures::ScriptAST> script::structures::ScriptAST::START;
DPtr<script::structures::ScriptAST> script::structures::ScriptAST::ANYT;
#include <gsql_gsm/script_1/Funzione.h>

bool script::structures::ScriptAST::toBoolean()  {
        switch (type) {
            case Boolean:
                return bool_;
            case Integer:
                return integer != 0;
            case Double:
                return doubleValue_ != 0;
            case String:
                return !string.empty();
            case Array:
                return !arrayList.empty();
            case Function:
                return !function->body.empty();
            case TupleT:
            case Tuple:
                return !tuple.empty();
            default:
                return run()->toBoolean();
        }

}

double script::structures::ScriptAST::toDouble()  {
    switch (type) {
        case Boolean:
            return bool_ ? 1.0 : 0.0;
        case Integer:
            return (double)integer;
        case Double:
            return doubleValue_;
        case String:
            return (double)string.length();
        case Array:
            return (double)arrayList.size();
        case TupleT:
        case Tuple:
            return (double)tuple.size();
        case Function:
            return (double)function->body.size();
        default:
            return run()->toDouble();
    }
}

#include <algorithm>
#include <numeric>

long long script::structures::ScriptAST::toInteger()   {
    switch (type) {
        case Boolean:
            return bool_ ? 1LL : 0LL;
        case Integer:
            return integer;
        case Double:
            return (long long)doubleValue_;
        case String:
            return (long long)string.length();
        case Array:
            return (long long)arrayList.size();
        case Tuple:
        case TupleT:
            return (long long)tuple.size();
        case Function:
            return (long long)function->body.size();
        default:
            return run()->toInteger();
    }
}

#include <iomanip>



std::string script::structures::ScriptAST::toString(bool quot) const {
    std::string result;
    switch (type) {
        case BooleanT:
            return "bool";
        case Boolean:
            return bool_ ? "tt" : "ff";
        case Integer:
            return std::to_string(integer);
        case IntegerT:
            return "int";
        case Double:
            return std::to_string(doubleValue_);
        case DoubleT:
            return "double";
        case String:
            if (quot) {
                std::stringstream ss;
                ss << std::quoted(string);
                return ss.str();
            } else return string;
        case StringT:
            return "string";
        case Assignment:
            return arrayList[0]->toString(true) +" := ("+arrayList[1]->toString(true)+") ";
        case Function:
            if (function->body.size() == 1)
                return function->parameter + " -> {" + function->body[0]->toString(true) + "}";
            else
            {
                auto it = function->body.begin();
//                it++;
                return function->parameter + " -> {" + std::accumulate(it,
                                function->body.end(), std::string(""),
                                [](const std::string& m, DPtr<script::structures::ScriptAST> obj) {
                                    return (m.empty() ? m : m+"; ") + obj->toString(true);
                                }) + "}";
            }
        case Array:
            if (arrayList.size() == 1)
                return "{" + arrayList[0]->toString(true) + "}";
            else
            {
                auto it = arrayList.begin();
//                it++;
                return "{" + std::accumulate(it,
                                             arrayList.end(), std::string(""),
                                                                       [](const std::string& m, DPtr<script::structures::ScriptAST> obj) {
                                                                           return (m.empty() ? m : m+"; ") + obj->toString(true);
                                                                       }) + "}";
            }
        case ArrayOfT:
            return "listof (" + arrayList[0]->toString(true) +")";
        case TupleT:
        case Tuple:
            if (tuple.size() == 1) {
                auto it = tuple.begin();
                std::stringstream ss;
                if (type == TupleT)
                    ss << "t< ";
                else
                    ss << "< ";
                ss <<std::quoted(it->first) << " >> " << it->second->toString(true) << " >";
                return ss.str();
            }
            else
            {
                auto it = tuple.begin();
//                it++;
                return ((type == TupleT) ? "t< " : "< ") + std::accumulate(it,
                                             tuple.end(), std::string(""),
                                             [](const std::string& m, const std::pair<std::string,DPtr<script::structures::ScriptAST>>& obj) {
                                                 std::stringstream ss;
                                                 ss << std::quoted(obj.first) << " >> " << obj.second->toString(true);
                                                 return (m.empty() ? m : m+"; ") + ss.str();
                                             }) + " >";
            }
        case Variable:
            return string;

        case AndE:
            return "(" + arrayList[0]->toString(true) +") && ("+ arrayList[1]->toString(true)+")";
        case ANDT:
            return "(" + arrayList[0]->toString(true) +") /\\ ("+ arrayList[1]->toString(true)+")";

        case OrE:
            return "(" + arrayList[0]->toString(true) +") || ("+ arrayList[1]->toString(true)+")";
        case ORT:
            return "(" + arrayList[0]->toString(true) +") \\/ ("+ arrayList[1]->toString(true)+")";

        case NotE:
            return "!(" + arrayList[0]->toString(true) +")";

        case EqE:
            return "(" + arrayList[0]->toString(true) +") == ("+ arrayList[1]->toString(true)+")";

        case IfteE:
            return "if (" + arrayList[0]->toString(true) +") then ("+ arrayList[1]->toString(true)+") else (" + arrayList[2]->toString(true)+")";

        case ImplyE:
            return "(" + arrayList[0]->toString(true) +") => ("+ arrayList[1]->toString(true)+")";

        case ApplyE:
            return "((" + arrayList[0]->toString(true) +")  ("+ arrayList[1]->toString(true)+"))";

        case AtE:
            return "" + arrayList[0]->toString(true) +"  ["+ arrayList[1]->toString(true)+"]";

        case PutE:
            return "" + arrayList[0]->toString(true) +"  ["+ arrayList[1]->toString(true)+"]:= ("+ arrayList[2]->toString(true)+")";

        case RemoveE:
            return "remove (" + arrayList[0]->toString(true) +") from ("+ arrayList[1]->toString(true)+")";

        case AppendE:
            return "(" + arrayList[0]->toString(true) +") @ ("+ arrayList[1]->toString(true)+")";
//
//        case AssignE:
//            return "(" + arrayList[0]->toString(true) +") := ("+ arrayList[1]->toString(true)+")";

        case ContainsE:
            return "(" + arrayList[0]->toString(true) +") in ("+ arrayList[1]->toString(true)+")";

        case FilterE:
            return "filter(" + arrayList[0]->toString(true) +" : "+ arrayList[1]->toString(true)+")";

        case InvokeE:
            return "(" + arrayList[0]->toString(true) +") . ("+ arrayList[1]->toString(true)+")";

        case MapE:
            return "map(" + arrayList[0]->toString(true) +" : "+ arrayList[1]->toString(true)+")";

        case SubElementsE:
            break;
        case AddE:
            return "(" + arrayList[0]->toString(true) +") + ("+ arrayList[1]->toString(true)+")";

        case DivE:
            return "(" + arrayList[0]->toString(true) +") / ("+ arrayList[1]->toString(true)+")";

        case ModE:
            return "(" + arrayList[0]->toString(true) +") % ("+ arrayList[1]->toString(true)+")";

        case AbsE:
            return "| " + arrayList[0]->toString(true) +" |";

        case MinusE:
            return "(" + arrayList[0]->toString(true) +") - ("+ arrayList[1]->toString(true)+")";

        case MulE:
            return "(" + arrayList[0]->toString(true) +") * ("+ arrayList[1]->toString(true)+")";

        case SinE:
            return "sin(" + arrayList[0]->toString(true) +")";

        case CosE:
            return "cos(" + arrayList[0]->toString(true) +")";

        case TanE:
            return "tan(" + arrayList[0]->toString(true) +")";

        case ExpE:
            return "exp (" + arrayList[0]->toString(true) +")  ("+ arrayList[1]->toString(true)+")";

        case LogE:
            return "log (" + arrayList[0]->toString(true) +")  ("+ arrayList[1]->toString(true)+")";

        case FloorE:
            return "|_" + arrayList[0]->toString(true) +"_|";

        case CeilE:
            return "|-" + arrayList[0]->toString(true) +"-|";

        case ConcatE:
            return "(" + arrayList[0]->toString(true) +") @ ("+ arrayList[1]->toString(true)+")";

        case GtE:
            return "(" + arrayList[0]->toString(true) +") > ("+ arrayList[1]->toString(true)+")";

        case LtE:
            return "(" + arrayList[0]->toString(true) +") < ("+ arrayList[1]->toString(true)+")";

        case GEqE:
            return "(" + arrayList[0]->toString(true) +") >= ("+ arrayList[1]->toString(true)+")";

        case LEqE:
            return "(" + arrayList[0]->toString(true) +") <= ("+ arrayList[1]->toString(true)+")";

        case NeqE:
            return "(" + arrayList[0]->toString(true) +") != ("+ arrayList[1]->toString(true)+")";

        case PhiX:
            return "phi (" + arrayList[0]->toString(true) +") * ("+ arrayList[1]->toString(true)+")";

        case VarPhiX:
            return "varphi (" + arrayList[0]->toString(true) +")";

        case EllX:
            return "ell (" + arrayList[0]->toString(true) +")";

        case XiX:
            return "xi (" + arrayList[0]->toString(true) +")";

        case CrossE:
            return "(" + arrayList[0]->toString(true) +") x ("+ arrayList[1]->toString(true)+")";

        case SelfCrossE:
            return "selfx (" + arrayList[0]->toString(true) +")";

        case InjE:
            return "inj (" + arrayList[0]->toString(true) +")";

        case FlatE:
            return "flat (" + arrayList[0]->toString(true) +")";

        case LFoldE:
            return "lfold(" + arrayList[0]->toString(true) +" , "+ arrayList[1]->toString(true)+" : " + arrayList[2]->toString(true)+")";

        case RFoldE:
            return "rfold(" + arrayList[0]->toString(true) +" , "+ arrayList[1]->toString(true)+" : " + arrayList[2]->toString(true)+")";

        case EvalE:
            return "eval (" + arrayList[0]->toString(true) +")";


    }
    return "";
}

ArrayList<DPtr<script::structures::ScriptAST>> script::structures::ScriptAST::toList()  {
    ArrayList<DPtr<script::structures::ScriptAST>> result;
    switch (type) {
        case Boolean:
        case Integer:
        case Double:
            result.emplace_back(shared_from_this());
            break;
        case String:
        {
            std::string local;
            for (size_t i = 0; i<string.length(); i++) {
                local = string.at(i);
                result.emplace_back(script::structures::ScriptAST::string_(local));
            }
            break;
        }
        case TupleT:
        case Tuple: {
            for (const auto&[k,v] : tuple) {
                ArrayList<DPtr<script::structures::ScriptAST>> inneres;
                inneres.emplace_back(string_(k));
                inneres.emplace_back(v);
                result.emplace_back(array_(std::move(inneres)));
            }
            break;
        }
        case Array:
            return arrayList;
        case Function:
            return function->body;
        default:
            return run()->toList();
    }
    return result;
}

StringMap<DPtr<script::structures::ScriptAST>> script::structures::ScriptAST::toMap()  {
    StringMap<DPtr<script::structures::ScriptAST>> result;
    switch (type) {
        case Boolean:
        case Integer:
        case Double: {
            result["0"] = shared_from_this();
            break;
        }

        case String: {
            for (size_t i = 0, N = string.size(); i<N; i++) {
                result[std::to_string(i)] = string_(""+string.at(i));
            }
            break;
        }

        case Array: {
            for (size_t i = 0, N = arrayList.size(); i<N; i++) {
                result[std::to_string(i)] = arrayList.at(i);
            }
            break;
        }

        case Function: {
            throw std::runtime_error("ERROR: cannot convert a function with a potential infinite domain into a tuple!");
        }

        case TupleT:
        case Tuple: {
            return tuple;
        }

        default:
            return run()->toMap();
    }
    return result;
}

std::function<DPtr<script::structures::ScriptAST>(DPtr<script::structures::ScriptAST>)> script::structures::ScriptAST::toFunction()  {
    switch (type) {
        case Boolean:
        case BooleanT:
        case Integer:
        case IntegerT:
        case Double:
        case DoubleT:
            return [this](auto x) {return shared_from_this(); };

        case String:
            return [this](DPtr<script::structures::ScriptAST> x) {
                size_t i = (size_t)x->toInteger();
                std::string local;
                if (i<string.length()) {
                    local = string.at(i);
                }
                return script::structures::ScriptAST::string_(local);
            };

        case Array:
            return [this](DPtr<script::structures::ScriptAST> x) {
                size_t i = (size_t)x->toInteger();
                ArrayList<DPtr<script::structures::ScriptAST>> vv;
                if (i<arrayList.size()) {
                    return arrayList[i];
                } else {
                    return script::structures::ScriptAST::array_(std::move(vv));
                }
            };

        case Function: {
            return [this](DPtr<script::structures::ScriptAST> x) {
                return function->apply(std::move(x));
            };
        }

        case TupleT:
        case Tuple: {
            return [this](DPtr<script::structures::ScriptAST> x) {
                std::string i = x->toString();
                auto it = tuple.find(i);
                if (it == tuple.end())
                    return script::structures::ScriptAST::star_T();
                else
                    return it->second;
            };
        }

        default:
            return run()->toFunction();
    }
}

DPtr<script::structures::ScriptAST> script::structures::ScriptAST::variableEval()  {
    if (!optGamma.get()) {
        std::cerr << "Error: variable cannot be solved: Gamma is null" << std::endl;
        return false_();
    } else {
        auto it = optGamma->find(string);
        if (it != optGamma->end()) {
            return it->second;
        } else
            return false_();
    }
}

void script::structures::ScriptAST::setContext(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& g, gsm_inmemory_db* db) {
    optGamma = g;
    this->db = db;
    if (type == Function) {
        function->setContext(g, db);
    } else {
        for (auto & i : arrayList) {
            i->setContext(g, db);
        }
    }
}

#include <math.h>
#include "gsql_gsm/script_1/ScriptVisitor.h"
#include "yaucl/strings/string_utils.h"
#include "yaucl/functional/iterators.h"
#include "yaucl/structures/setoids/basics.h"

DPtr<script::structures::ScriptAST> script::structures::ScriptAST::run() {
    switch (type) {
        case Boolean:
        case Integer:
        case Double:
        case String:
        case Array:
        case Function:
        case BooleanT:
        case DoubleT:
        case StringT:
        case StarT:
        case SortT:
        case IntegerT:
        case ArrayOfT:
        case Tuple:
        case TupleT:
        case SigmaT:
            return shared_from_this();

        case Assignment:
            arrayList[1] = arrayList[1]->run();
            if (arrayList[0]->type == Variable) {
                (*arrayList[0]->optGamma)[arrayList[0]->string] = arrayList[1];
            } else if (arrayList[0]->type == Function) {
                return arrayList[0]->function->apply(arrayList[1]);
            }
            return arrayList[1];
            break;

        case Variable:
            return variableEval();

        case AndE:
            return arrayList[0]->toBoolean() && arrayList[1]->toBoolean() ? true_() : false_();

        case OrE:
            return arrayList[0]->toBoolean() || arrayList[1]->toBoolean() ? true_() : false_();

        case NotE:
            return arrayList[0]->toBoolean() ? false_() : true_();

        case EqE:         {
            auto lx = arrayList[0]->run();
            auto rx = arrayList[1]->run();
            return lx->javaComparator(rx) == 0 ? true_() : false_();
        }

        case IfteE:
            return arrayList[0]->toBoolean() ? arrayList[0]->run() : arrayList[1]->run();

        case ImplyE:
            return arrayList[0]->toBoolean() ? arrayList[0]->run() : arrayList[1]->run();

        case InvokeE:
        case ApplyE:
        case AtE:
            return arrayList[0]->toFunction()(arrayList[1]->run());

        case PutE:
        {
            auto run = arrayList[0]->run();
            if (run->type == String) {
                size_t pos = arrayList[1]->toInteger();
                std::string cpy = run->string;
                if (pos < cpy.length()) {
                    auto rpl = arrayList[2]->toString();
                    if (rpl.empty())
                        cpy[pos] = ' ';
                    else
                        cpy[pos] = rpl.at(0);
                } else if (pos == cpy.length()) {
                    auto rpl = arrayList[2]->toString();
                    if (!rpl.empty())
                        cpy += rpl.at(0);
                } else {
                    auto rpl = arrayList[2]->toString();
                    if (!rpl.empty()) {
                        while (cpy.length() < pos)
                            cpy += " ";
                        cpy += rpl.at(0);
                    }
                }
                return string_(cpy);
            } else if ((run->type == Tuple) || (run->type == TupleT)) {
                auto cpy = tuple;
                cpy[arrayList[1]->toString()] = arrayList[2]->run();
                if (run->type == TupleT)
                    return tuple_type_(std::move(cpy));
                else
                    return tuple_(std::move(cpy));
            } else {
                auto list = arrayList[0]->toList();
                size_t pos = arrayList[1]->toInteger();
                if (pos < list.size()) {
                    list[pos] = arrayList[2]->run();
                } else if (pos == list.size()) {
                    list.emplace_back(arrayList[2]->run());
                } else {
                    while (list.size() < pos)
                        list.emplace_back(false_());
                    list.emplace_back(arrayList[2]->run());
                }
                return script::structures::ScriptAST::array_(std::move(list));
            }
        }

        case RemoveE:
        {
            auto run = arrayList[1]->run();
            if (run->type == String) {
                return string_(yaucl::strings::replace_all(run->string, arrayList[0]->toString(), ""));
            } else if ((run->type == Tuple) || (run->type == TupleT)) {
                auto cpy = tuple;
                cpy.erase(arrayList[1]->toString());
                if (run->type == TupleT)
                    return tuple_type_(std::move(cpy));
                else
                    return tuple_(std::move(cpy));
            } else {
                ArrayList<DPtr<script::structures::ScriptAST>> vv;
                auto list = arrayList[0]->toList();
                for (const auto& ref : list) {
                    if (ref->javaComparator(arrayList[0]) != 0)
                        vv.emplace_back(ref);
                }
                return script::structures::ScriptAST::array_(std::move(vv));
            }
        }

        case AppendE:
        {
            auto run = arrayList[0]->run();
            auto run2 = arrayList[1]->run();
            if ((run->type == Tuple) && (run2->type == Tuple)) {
                auto cpy = run->tuple;
                for (const auto& [k,v] : run2->tuple) {
                    cpy[k] = v;
                }
                return tuple_(std::move(cpy));
            } else if ((run->type == TupleT) && (run2->type == TupleT)) {
                auto cpy = run->tuple;
                for (const auto& [k,v] : run2->tuple) {
                    cpy[k] = v;
                }
                return tuple_type_(std::move(cpy));
            } else {
                auto lsx = arrayList[0]->toList();
                auto lrx = arrayList[1]->toList();
                ArrayList<DPtr<script::structures::ScriptAST>> v;
                v.insert(v.end(), std::make_move_iterator(lsx.begin()), std::make_move_iterator(lsx.end()));
                v.insert(v.end(), std::make_move_iterator(lrx.begin()), std::make_move_iterator(lrx.end()));
                return array_(std::move(v));
            }
        }

        case ContainsE:
        {
            auto transf = arrayList[0]->run();
            auto run = arrayList[1]->run();
            if ((run->type == Tuple) || (run->type == TupleT)) {
                return run->tuple.contains(transf->toString()) ? true_() : false_();
            } else {
                auto list = run->toList();
                for (const auto& ref : list) {
                    if (ref->javaComparator(transf) == 0) return true_();
                }
                return false_();
            }
        }

        case FilterE: {
            auto run = arrayList[1]->run();
            auto prop = arrayList[0]->toFunction();
            if ((run->type == Tuple) || (run->type == TupleT)) {
                StringMap<DPtr<script::structures::ScriptAST>> return_;
                for (const auto& [k,v]: run->tuple) {
                    StringMap<DPtr<script::structures::ScriptAST>> map;
                    map["key"] = string_(k);
                    map["value"] = v;
                    if (prop(tuple_(std::move(map)))->toBoolean()) {
                        return_[k] = v;
                    }
                }
                return (run->type == Tuple) ? tuple_(std::move(return_)) : tuple_type_(std::move(return_));
            } else {
                ArrayList<DPtr<script::structures::ScriptAST>> vv;
                auto list = arrayList[1]->toList();
                for (const auto& ref : list) {
                    if (prop(ref)->toBoolean())
                        vv.emplace_back(ref);
                }
                return script::structures::ScriptAST::array_(std::move(vv));
            }
        }

        case MapE:
        {
            auto run = arrayList[1]->run();
            auto transf = arrayList[0]->toFunction();
            if ((run->type == Tuple) || (run->type == TupleT)) {
                StringMap<DPtr<script::structures::ScriptAST>> return_;
                for (const auto& [k,v]: run->tuple) {
                    StringMap<DPtr<script::structures::ScriptAST>> map;
                    map["key"] = string_(k);
                    map["value"] = v;
                    auto mapResult = transf(tuple_(std::move(map)))->toMap();
                    auto it = mapResult.find("key");
                    auto it2 = mapResult.find("value");
                    if ((it != mapResult.end()) && (it2 != mapResult.end())) {
                        return_[it->second->toString()] = it2->second;
                    } else {
                        throw std::runtime_error("ERROR: the transformation should return key and value as elements!");
                    }
                }
                return (run->type == Tuple) ? tuple_(std::move(return_)) : tuple_type_(std::move(return_));
            } else {
                auto list = run->toList();
                ArrayList<DPtr<script::structures::ScriptAST>> vv(list.size());
                for (const auto& ref : list) {
                    vv.emplace_back(transf(ref));
                }
                return script::structures::ScriptAST::array_(std::move(vv));
            }

        }

        case SubElementsE: {
            size_t begin = (size_t)arrayList[0]->toInteger();
            size_t end = (size_t)arrayList[1]->toInteger();
            auto run2 = arrayList[2]->run();
            if (run2->type == String) {
                if (end < begin)
                    return string_("");
                else
                    return string_(arrayList[2]->string.substr(begin, end-begin+1));
            } else if (run2->type == TupleT || run2->type == Tuple) {
                std::vector<std::string> ls;
                StringMap<DPtr<script::structures::ScriptAST>> cp;
                ls.reserve(run2->tuple.size());
                for (const auto& [k,v] : run2->tuple) {
                    ls.emplace_back(k);
                }
                remove_duplicates(ls);
                auto first = ls.begin() + begin;
                auto last = ls.begin() + end;
                while (first != last) {
                    cp[*first] = run2->tuple.at(*first);
                    first++;
                }
                return (run2->type == Tuple) ? tuple_(std::move(cp)) : tuple_type_(std::move(cp));
            } else {
                auto ls = run2->toList();
                auto first = ls.begin() + begin;
                auto last = ls.begin() + end;
                std::vector<DPtr<script::structures::ScriptAST>> newVec(first, last);
                return array_(std::move(newVec));
            }
        }

        case AddE:
            if (arrayList[0]->isDouble() || arrayList[1]->isDouble())
                return double_(arrayList[0]->toDouble()+arrayList[1]->toDouble());
            else
                return integer_(arrayList[0]->toInteger()+arrayList[1]->toInteger());

        case DivE:
            if (arrayList[0]->isDouble() || arrayList[1]->isDouble())
                return double_(arrayList[0]->toDouble()/arrayList[1]->toDouble());
            else
                return integer_(arrayList[0]->toInteger()/arrayList[1]->toInteger());

        case MinusE:
            if (arrayList[0]->isDouble() || arrayList[1]->isDouble())
                return double_(arrayList[0]->toDouble()-arrayList[1]->toDouble());
            else
                return integer_(arrayList[0]->toInteger()-arrayList[1]->toInteger());

        case MulE:
            if (arrayList[0]->isDouble() || arrayList[1]->isDouble())
                return double_(arrayList[0]->toDouble()*arrayList[1]->toDouble());
            else
                return integer_(arrayList[0]->toInteger()*arrayList[1]->toInteger());

        case SinE:
            return double_(std::sin(arrayList[0]->toDouble()));

        case CosE:
            return double_(std::cos(arrayList[0]->toDouble()));

        case TanE:
            return double_(std::tan(arrayList[0]->toDouble()));

        case ExpE: {
            double val = arrayList[1]->toDouble();
            if (val == 2.0) {
                return double_(std::exp2(arrayList[0]->toDouble()));
            } else if (val == M_E) {
                return double_(std::exp(arrayList[0]->toDouble()));
            } else {
                return double_(std::pow(arrayList[0]->toDouble(),val));
            }
        }
        case LogE:{
            double val = arrayList[1]->toDouble();
            if (val == 10.0) {
                return double_(std::log10(arrayList[0]->toDouble()));
            } else if (val == M_E) {
                return double_(std::log(arrayList[0]->toDouble()));
            } else {
                return double_(std::log(arrayList[0]->toDouble())/std::log(val));
            }
        }

        case FloorE:
            return double_(std::floor(arrayList[0]->toDouble()));

        case CeilE:
            return double_(std::ceil(arrayList[0]->toDouble()));

        case ConcatE:
            return string_(arrayList[0]->toString()+arrayList[1]->toString());

        case GtE:
        {
            auto lx = arrayList[0]->run();
            auto rx = arrayList[1]->run();
            return lx->javaComparator(rx) > 0 ? true_() : false_();
        }

        case LtE:
        {
            auto lx = arrayList[0]->run();
            auto rx = arrayList[1]->run();
            return lx->javaComparator(rx) < 0 ? true_() : false_();
        }

        case GEqE:
        {
            auto lx = arrayList[0]->run();
            auto rx = arrayList[1]->run();
            return lx->javaComparator(rx) >= 0 ? true_() : false_();
        }

        case LEqE:
        {
            auto lx = arrayList[0]->run();
            auto rx = arrayList[1]->run();
            return lx->javaComparator(rx) <= 0 ? true_() : false_();
        }

        case NeqE:
        {
            auto lx = arrayList[0]->run();
            auto rx = arrayList[1]->run();
            return lx->javaComparator(rx) != 0 ? true_() : false_();
        }

        case PhiX: {
            auto id = (size_t) arrayList[0]->toInteger();
            auto label = arrayList[1]->toString();
            ArrayList<DPtr<script::structures::ScriptAST>> v;
            if (db) {
                const auto& m = db->phi(id);
                auto it = m.find(label);
                if (it != m.cend()) {
                    for (const auto& content : it->second) {
//                        StringMap<DPtr<script::structures::ScriptAST>> content;
//                        ArrayList<DPtr<script::structures::ScriptAST>> item;
//                        item.emplace_back(v.emplace_back(script::structures::ScriptAST::integer_((long long)content.id)));
//                        item.emplace_back(v.emplace_back(script::structures::ScriptAST::double_(content.score)));
                        v.emplace_back(fromObjectContent(content));
                    }
                }
            } else {
                std::cerr << "WARNING: No DB being associated. Returning an empty array for Phi" << std::endl;
            }
            return script::structures::ScriptAST::array_(std::move(v));
        }

        case VarPhiX:{
            auto id = (size_t) arrayList[0]->toInteger();
            ArrayList<DPtr<script::structures::ScriptAST>> v;
            if (db) {
                for (size_t val : db->varphi(id))
                    v.emplace_back(script::structures::ScriptAST::integer_((long long)val));
            } else {
                std::cerr << "WARNING: No DB being associated. Returning an empty array for VarPhi" << std::endl;
            }
            return script::structures::ScriptAST::array_(std::move(v));
        }

        case EllX: {
            auto id = (size_t) arrayList[0]->toInteger();
            ArrayList<DPtr<script::structures::ScriptAST>> v;
            if (db) {
                for (const std::string& val : db->ell(id))
                    v.emplace_back(script::structures::ScriptAST::string_(val));
            } else {
                std::cerr << "WARNING: No DB being associated. Returning an empty array for Ell" << std::endl;
            }
            return script::structures::ScriptAST::array_(std::move(v));
        }

        case XiX:{
            auto id = (size_t) arrayList[0]->toInteger();
            ArrayList<DPtr<script::structures::ScriptAST>> v;
            if (db) {
                for (const std::string& val : db->xi(id))
                    v.emplace_back(script::structures::ScriptAST::string_(val));
            } else {
                std::cerr << "WARNING: No DB being associated. Returning an empty array for Xi" << std::endl;
            }
            return script::structures::ScriptAST::array_(std::move(v));
        }

        case ObjX: {
            auto id = (size_t) arrayList[0]->toInteger();
            StringMap<DPtr<script::structures::ScriptAST>> vv;
            if (!db) {
                std::cerr << "WARNING: No DB being associated. Returning an empty array for Xi" << std::endl;
            } else {
                ArrayList<DPtr<script::structures::ScriptAST>> ell, xi, errs;
                for (const std::string& val : db->xi(id))
                    xi.emplace_back(script::structures::ScriptAST::string_(val));
                vv["@xi"] = array_(std::move(xi));
                for (const std::string& val : db->ell(id))
                    ell.emplace_back(script::structures::ScriptAST::string_(val));
                vv["@ell"] = array_(std::move(ell));
                for (const double val : db->err(id))
                    errs.emplace_back(script::structures::ScriptAST::double_(val));
                vv["@err"] = array_(std::move(errs));
                for (const auto& [k,v] : db->phi(id)) {
                    ArrayList<DPtr<script::structures::ScriptAST>> local;
                    for (const auto& content : v)
                        local.emplace_back(std::move(fromObjectContent(content)));
                    vv[k] = array_(std::move(local));
                }
            }
            return script::structures::ScriptAST::tuple_(std::move(vv));
        }

        case ModE:
            return integer_(arrayList[0]->toInteger() % arrayList[1]->toInteger());

        case AbsE:
            if (arrayList[0]->isDouble())
                return double_(std::abs(arrayList[0]->toDouble()));
            else
                return integer_(std::abs(arrayList[0]->toInteger()));

        case CrossE: {
            auto lx = arrayList[0]->toList();
            auto rx = arrayList[1]->toList();
            ArrayList<DPtr<script::structures::ScriptAST>> result;
            for (const DPtr<script::structures::ScriptAST>& lptr : lx) {
                for (const DPtr<script::structures::ScriptAST>& rptr : rx) {
                    ArrayList<DPtr<script::structures::ScriptAST>> v;
                    v.emplace_back(lptr);
                    v.emplace_back(rptr);
                    result.emplace_back(script::structures::ScriptAST::array_(std::move(v)));
                }
            }
            return script::structures::ScriptAST::array_(std::move(result));
        }

        case SelfCrossE: {
            ArrayList<DPtr<script::structures::ScriptAST>> result;
            ArrayList<ArrayList<DPtr<script::structures::ScriptAST>>> v;
            for (const DPtr<script::structures::ScriptAST>& lptr : arrayList[0]->toList()) {
                v.emplace_back(lptr->toList());
            }
            for (ArrayList<DPtr<script::structures::ScriptAST>>& res : yaucl::iterators::cartesian(v)) {
                result.emplace_back(array_(std::move(res)));
            }
            return array_(std::move(result));
        }

        case InjE: {
            ArrayList<DPtr<script::structures::ScriptAST>> v;
            v.emplace_back(arrayList[0]);
            return script::structures::ScriptAST::array_(std::move(v));
        }

        case FlatE: {
            ArrayList<DPtr<script::structures::ScriptAST>> v;
            for (const auto& ptr : toList()) {
                auto ls = ptr->toList();
                v.insert(v.end(), std::make_move_iterator(ls.begin()), std::make_move_iterator(ls.end()));
            }
            return script::structures::ScriptAST::array_(std::move(v));
        }

        case LFoldE: {
            auto f = arrayList[0]->toFunction();
            auto obj = arrayList[1];
            auto ls = arrayList[2]->toList();
            if (ls.empty())
                return obj;
            else {
                for (size_t i = 0, N = ls.size(); i<N; i++) {
                    ArrayList<DPtr<script::structures::ScriptAST>> v{obj, ls[i]};
                    obj = f(array_(std::move(v)));
                }
                return obj;
            }
        }

        case RFoldE: {
            auto f = arrayList[0]->toFunction();
            auto obj = arrayList[1];
            auto ls = arrayList[2]->toList();
            if (ls.empty())
                return obj;
            else {
                for (std::ptrdiff_t i = ls.size()-1; i>=0; i--) {
                    ArrayList<DPtr<script::structures::ScriptAST>> v{ls[i], obj};
                    obj = f(array_(std::move(v)));
                }
                return obj;
            }
        }

        case EvalE: {
            std::stringstream ss;
            ss << arrayList[0]->toString(true);
            return script::compiler::ScriptVisitor::eval(ss);
        }

        case TypeOf: {
            return arrayList[0]->typeInference();
        }

        case AssertE:
            if (!arrayList[0]->toBoolean())
                throw std::runtime_error(arrayList[0]->toString()+": condition does not hold!");
            return true_();
    }
    return std::make_shared<ScriptAST>();
}

#include <limits>

template<class InputIt1, class InputIt2, class Compare>
std::ptrdiff_t int_lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2, Compare comp)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
    {
        auto val = (std::ptrdiff_t)comp(*first1, *first2);
        if (val != 0) return val;
    }

    bool hasFirstFinished = first1 == last1;
    if (hasFirstFinished && (first2 == last2))
        return 0;
    else if (hasFirstFinished)
        return -1;
    else return 1;
}

std::ptrdiff_t script::structures::ScriptAST::javaComparator(const DPtr<ScriptAST> &object) {
    if (!object.get()) return 1;
    std::ptrdiff_t cmp = ((std::ptrdiff_t)type) - ((std::ptrdiff_t)object->type);
    if (cmp != 0) return cmp;
    switch (type) {
        case BooleanT:
        case DoubleT:
        case IntegerT:
        case AnyT:
        case StringT:
        case StarT:
            return cmp;

        case Boolean:
            return ((std::ptrdiff_t)bool_) - ((std::ptrdiff_t)object->bool_);
        case Integer:
            return integer - object->integer;
        case Double:
            {
                double cmp = (doubleValue_ - object->doubleValue_);
                if (std::abs(cmp) <= std::numeric_limits<double>::epsilon()) return 0;
                else return (cmp > 0 ? 1 : -1);
            }
        case String:
            return string.compare(object->string);

        case Variable:
            return variableEval()->javaComparator(object->variableEval());

        default:
            return int_lexicographical_compare(function->body.begin(), function->body.end(),
                                               object->function->body.begin(), object->function->body.end(),
                                               [](const auto& x, auto& y) {return x->javaComparator(y);});
    }
}

DPtr<script::structures::ScriptAST> script::structures::ScriptAST::typeInference() {
    auto self = run();
    switch (self->type) {
        case Variable:
            return variableEval()->typeInference();

        case AnyT:
        case BooleanT:
        case IntegerT:
        case DoubleT:
        case StringT:
        case TupleT:
        case ArrayOfT:
        case SortT:
        case StarT:
        case SigmaT:
            return star_T();

        case Boolean:
            return boolean_T();

        case Integer:
            return integer_T();

        case Double:
            return double_T();

        case String:
            return string_T();

        case Tuple: {
            StringMap<DPtr<script::structures::ScriptAST>> type_tuple;
            for (const auto&[k,v] : self->tuple) {
                type_tuple[k] = v->typeInference();
            }
            return tuple_type_(std::move(type_tuple));
        }

        case Array: {
            ArrayList<DPtr<script::structures::ScriptAST>> types;
            types.reserve(self->arrayList.size());
            for (const auto& val : self->arrayList) {
                types.emplace_back(val->typeInference());
            }
            remove_duplicates(types, [](const auto& x, const auto& y) {
                return x->javaComparator(y) < 0;
            });
            if (types.empty()) {
                return array_type(any_T());
            } else if (types.size() > 1) {
                throw std::runtime_error("ERROR: at this stage, I cannot unify distinct types together! This requires typing inference with relaxation!");
            } else {
                return array_type(std::move(types[0]));
            }
        }

        default:
            throw std::runtime_error("Cannot determine the type of an unevaluated expression! This would require a more expressive type system!");
//        case Assignment: break;
//        case Function: break;
//        case AndE: break;
//        case OrE: break;
//        case NotE: break;
//        case EqE: break;
//        case IfteE: break;
//        case ImplyE: break;
//        case ApplyE: break;
//        case AtE: break;
//        case PutE: break;
//        case RemoveE: break;
//        case AppendE: break;
//        case ContainsE: break;
//        case FilterE: break;
//        case InvokeE: break;
//        case MapE: break;
//        case SubElementsE: break;
//        case AddE: break;
//        case DivE: break;
//        case ModE: break;
//        case AbsE: break;
//        case MinusE: break;
//        case MulE: break;
//        case SinE: break;
//        case CosE: break;
//        case TanE: break;
//        case ExpE: break;
//        case LogE: break;
//        case FloorE: break;
//        case CeilE: break;
//        case ConcatE: break;
//        case GtE: break;
//        case LtE: break;
//        case GEqE: break;
//        case LEqE: break;
//        case NeqE: break;
//        case PhiX: break;
//        case VarPhiX: break;
//        case EllX: break;
//        case XiX: break;
//        case ObjX: break;
//        case CrossE: break;
//        case SelfCrossE: break;
//        case InjE: break;
//        case FlatE: break;
//        case LFoldE: break;
//        case RFoldE: break;
//        case EvalE: break;
//        case AssertE: break;
    }
}
