//
// Created by giacomo on 09/04/23.
//

#ifndef GSM_GSQL_SCRIPTAST_H
#define GSM_GSQL_SCRIPTAST_H

#include <scriptv2/java_types.h>
#include <scriptv2/SerializableFunction.h>
#include <database/gsm_inmemory_db.h>
#include <queries/closure.h>
#include <functional>
#include <optional>

#ifndef ALLOC_TYPE
#define ALLOC_TYPE(NAME,case) do { if (!(NAME).get()) { (NAME) = std::make_shared<ScriptAST>(); (NAME)->type = case; } return (NAME);  } while (0)
#endif

namespace script::structures {
    struct ScriptAST;
    struct Funzione;
    using Gamma = HashMap<std::string, DPtr<ScriptAST>>;


    enum t {
        BotT,
        NullE,
        SigmaT,
        StarT,
        ANDT,
        ORT,
        LABELT,
        ENFORCET,
        ObjTT,
        AnyT,
        BooleanT,
        IntegerT,
        DoubleT,
        StringT,
        TupleT,
        ArrayOfT,
        TypeOf,
        Boolean,
        Integer,
        Double,
        String,
        Assignment,
        Function,
        Array,
        Tuple,
        Variable,
        AndE,
        OrE,
        NotE,
        EqE,
        IfteE,
        ImplyE,
        ApplyE,
        AtE,
        PutE,
        RemoveE,
        AppendE,
        ContainsE,
        FilterE,
        InvokeE,
        MapE,
        SubElementsE,
        AddE,
        DivE,
        ModE,
        AbsE,
        MinusE,
        MulE,
        SinE,
        CosE,
        TanE,
        ExpE,
        LogE,
        FloorE,
        CeilE,
        ConcatE,
        GtE,
        ProjectE,
        LtE,
        GEqE,
        LEqE,
        NeqE,
        PhiX,
        VarPhiX,
        EllX,
        XiX,
        ObjX,
        CrossE,
        SelfCrossE,
        InjE,
        FlatE,
        LFoldE,
        RFoldE,
        EvalE,
        AssertE,
        SubtypeOfE,
        CoerceE
    };

    //// Generic object for expressions
    struct ScriptAST : public std::enable_shared_from_this<ScriptAST>{
        bool bool_; // 0
        long long integer; // 1
        double doubleValue_;
        std::string string; // 2
        ArrayList<DPtr<ScriptAST>> arrayList; // 3
        StringMap<DPtr<ScriptAST>> tuple; // 4
        DPtr<Funzione> function;
        t type;
        DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>> optGamma;
        closure* db{nullptr};
        DPtr<ScriptAST> casted_type;

        ScriptAST() { }
        ScriptAST(const ScriptAST&) = default;
        ScriptAST(ScriptAST&&) = default;
        ScriptAST& operator=(const ScriptAST&) = default;
        ScriptAST& operator=(ScriptAST&&) = default;

        void setOptGammaRecursively(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& gamma);
        void setDBRecursively( closure* datenbanken);
        void setOptGammaRecursively(std::unordered_map<std::string, DPtr<ScriptAST>>&& gamma);

        inline bool isType() const {
            switch (type) {
                case SigmaT:
                case StarT:
                case ANDT:
                case ORT:
                case LABELT:
                case ENFORCET:
                case ObjTT:
                case AnyT:
                case BooleanT:
                case IntegerT:
                case DoubleT:
                case StringT:
                case TupleT:
                case ArrayOfT:
                case TypeOf:
                    return true;
                default:
                    return false;
            }
        }

    void setContext(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& g,
                    closure* db);

        static inline DPtr<ScriptAST> function_(DPtr<Funzione>&& v) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::Function ;
            val->function = std::move(v);
            return val;
        }

    static inline DPtr<ScriptAST> array_(ArrayList<DPtr<ScriptAST>>&& v) {
        auto val = std::make_shared<ScriptAST>();
        val->type = t::Array ;
        val->arrayList = std::move(v);
        return val;
    }

        static inline DPtr<ScriptAST> array_type(DPtr<ScriptAST>&& v) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::ArrayOfT ;
            val->arrayList.emplace_back(v);
            return val;
        }

        static inline DPtr<ScriptAST> lex_type_(DPtr<ScriptAST>&& l, DPtr<ScriptAST>&& v) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::ObjTT ;
            val->arrayList.emplace_back(l);
            val->arrayList.emplace_back(v);
            return val;
        }

        static inline DPtr<ScriptAST> lex_type_(DPtr<ScriptAST>&& l, StringMap<DPtr<ScriptAST>>&& v) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::ObjTT ;
            val->arrayList.emplace_back(l);
            val->arrayList.emplace_back(tuple_type_(std::move(v)));
            return val;
        }

        static inline DPtr<ScriptAST> tuple_(StringMap<DPtr<ScriptAST>>&& v) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::Tuple ;
            val->tuple = std::move(v);
            return val;
        }

        static inline DPtr<ScriptAST> tuple_type_(StringMap<DPtr<ScriptAST>>&& v) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::TupleT ;
            val->tuple = std::move(v);
            return val;
        }

        DPtr<ScriptAST> variableEval();
        DPtr<ScriptAST> mgu(const std::vector<DPtr<ScriptAST>>& x) const {
            if (x.empty() || (x.size() != 1))
                return any_T();
            else //if (x.size() == 1)
                return x.at(0);
        }

        static inline DPtr<ScriptAST> fromObjectContent(const gsm_object_xi_content& v) {
            StringMap<DPtr<ScriptAST>> result;
            result["id"] = integer_(v.id);
            result["score"] = double_(v.score);
            return tuple_(std::move(result));
        }

        static inline DPtr<ScriptAST> assignment_(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& gamma, DPtr<ScriptAST>&& left, DPtr<ScriptAST>&& right) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::Assignment ;
            val->arrayList.emplace_back(left);
            val->arrayList.emplace_back(right);
            val->optGamma = gamma;
            return val;
        }

        static inline DPtr<ScriptAST> unop_(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& gamma,
                                             t casus,
                                             DPtr<ScriptAST>&& left) {
            auto val = std::make_shared<ScriptAST>();
            val->type = casus;
            val->arrayList.emplace_back(left);
            val->optGamma = gamma;
            return val;
        }

        static inline DPtr<ScriptAST> binop_(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& gamma,
                                             t casus,
                                             DPtr<ScriptAST>&& left,
                                             DPtr<ScriptAST>&& right) {
            auto val = std::make_shared<ScriptAST>();
            val->type = casus;
            val->arrayList.emplace_back(left);
            val->arrayList.emplace_back(right);
            val->optGamma = gamma;
            return val;
        }

        static inline DPtr<ScriptAST> terop_(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& gamma,
                                             t casus,
                                             DPtr<ScriptAST>&& left,
                                             DPtr<ScriptAST>&& mid,
                                             DPtr<ScriptAST>&& right) {
            auto val = std::make_shared<ScriptAST>();
            val->type = casus;
            val->arrayList.emplace_back(left);
            val->arrayList.emplace_back(mid);
            val->arrayList.emplace_back(right);
            val->optGamma = gamma;
            return val;
        }

        static inline DPtr<ScriptAST> integer_(long long i) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::Integer ;
            val->integer = i ;
            return val;
        }

        static inline DPtr<ScriptAST> double_(double i) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::Double ;
            val->doubleValue_ = i ;
            return val;
        }

        bool toBoolean() ;
        long long toInteger();
        double toDouble();
        ArrayList<DPtr<ScriptAST>> toList();
        std::function<DPtr<ScriptAST>(DPtr<ScriptAST>)> toFunction();
        StringMap<DPtr<ScriptAST>> toMap();
        DPtr<ScriptAST> run(bool implode=false);

//        /**
//         * Function to be used if the function needs to be interpreted as the ell/xi for an object
//         * @return
//         */
//        std::vector<std::string> asVectorOfStrings() {
//            auto ls = toList();
//            std::vector<std::string> result(ls.size());
//            for (const DPtr<ScriptAST>& ptr : ls) {
//                result.emplace_back(ptr->toString());
//            }
//            return result;
//        }

//        /**
//         * Function to be used if the function needs to be interpreted as the phi for an object
//         * @return
//         */
//        std::unordered_map<std::string, std::vector<gsm_object_xi_content>> asPhiForObject() {
//            auto ls = toList();
//            std::unordered_map<std::string, std::vector<gsm_object_xi_content>> result;
//            for (const DPtr<ScriptAST>& ptr : ls) {
//                auto cp = ptr->toList();
//                size_t cp_size = cp.size();
//                if (cp_size == 1) {
//                    result[cp[0]->toString()] = {};
//                } else if (cp_size == 2) {
//                    auto vector = result[cp[0]->toString()];
//                    auto content = cp[1]->toList();
//                    size_t content_size = cp.size();
//                    if (content_size == 1) {
//                        vector.emplace_back(content[0]->toInteger());
//                    } else if (content_size == 2) {
//                        vector.emplace_back(content[0]->toInteger(), content[1]->toDouble());
//                    }
//                }
//            }
//            return result;
//        }



        std::ptrdiff_t javaComparator(const DPtr<ScriptAST>& object);

//        DPtr<ScriptAST> eval()  {
//            return type == Variable ? variableEval() : run();
//        }

//        DPtr<ScriptAST> assign() {
//            if (type == Assignment)
//                return assignmentAssign();
//            else
//                return shared_from_this();
//        }
//
//        DPtr<ScriptAST> assignmentAssign() {
//            if (!optGamma.get())
//                assignment.first->optGamma = optGamma;
//            return assignment_(optGamma, shared_from_this());
//        }

//        template <typename T>
//        T evalPriorToApplication(const std::function<T(script::structures::ScriptAST)>& fun) {
//            auto extern_ = shared_from_this();
//            switch (type) {
//                case LazyExpression:
//                    extern_ = argsWithFunction.second.apply(argsWithFunction.first);
//                    break;
//                case Variable:
//                    extern_ = variableEval();
//                    break;
//                case Assignment:
//                    extern_ = assignmentAssign();
//                    break;
//            }
//            return fun(extern_);
//        }

        bool isDouble() const {
            if (type == t::String) {
                try {
                    std::stod(string);
                    return true;
                } catch(...) {
                    return false;
                }
            } else return (type == t::Double);
        }

        std::string toString(bool quoted=false, bool implode=false) const;

        /**
         * If the left subtype can be reconciled to the one on the right, then I shall proivde a transformation function for those!
         * @param left: subtype
         * @param right: supertype
         * @return If there is a viable transformation from the first to the latter, then there should be a conversion between the two types
         */
        std::optional<std::function<DPtr<script::structures::ScriptAST>(DPtr<script::structures::ScriptAST>&&)>> subTyping(DPtr<script::structures::ScriptAST>& left, DPtr<script::structures::ScriptAST>& right);

        DPtr<ScriptAST> var() {
            if (type == t::Variable) {
                return shared_from_this();
            } else {
                DPtr<ScriptAST> result = std::make_shared<ScriptAST>();
                result->type= t::Variable;
                result->string = toString();
                return result;
            }
        }

        static inline DPtr<ScriptAST> string_(const std::string& i) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::String ;
            val->string = i;
            return val;
        }

        static inline DPtr<ScriptAST> label_T_(const std::string& i) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::LABELT ;
            val->string = i;
            return val;
        }

        static inline DPtr<ScriptAST> variable_(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& gamma, const std::string& i) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::Variable ;
            val->optGamma = gamma;
            val->string = i;
            return val;
        }

        static inline DPtr<ScriptAST> true_() {
            if (!TRUE.get()) {
                TRUE = std::make_shared<ScriptAST>();
                TRUE->type = t::Boolean ;
                TRUE->bool_ = true;
            }
            return TRUE;
        }


        static inline DPtr<ScriptAST> double_T() {
            ALLOC_TYPE(DOUBLET, t::DoubleT);
        }

        static inline DPtr<ScriptAST> any_T() {
            ALLOC_TYPE(ANYT, t::AnyT);
        }

        static inline DPtr<ScriptAST> integer_T() {
            ALLOC_TYPE(INTEGERT, t::IntegerT);
        }

        static inline DPtr<ScriptAST> string_T() {
            ALLOC_TYPE(STRINGT, t::StringT);
        }



        static inline DPtr<ScriptAST> boolean_T() {
            ALLOC_TYPE(BOOLEANT, t::BooleanT);
        }

        static inline DPtr<ScriptAST> star_T() {
            ALLOC_TYPE(START, t::StarT);
        }

        template <typename T>
        static inline DPtr<ScriptAST> array_(DPtr<std::unordered_map<std::string, DPtr<ScriptAST>>>& gamma, T begin, T end) {
            auto val = std::make_shared<ScriptAST>();
            val->type = t::Array ;
            val->optGamma = gamma;
            for (; begin != end; begin++) {
                val->arrayList.emplace_back(*begin);
            }
            return val;
        }

        static inline DPtr<ScriptAST> false_() {
            if (!FALSE.get()) {
                FALSE = std::make_shared<ScriptAST>();
                FALSE->type = t::Boolean ;
                FALSE->bool_ = false;
            }
            return FALSE;
        }

        static inline DPtr<ScriptAST> bot_t_() {
            if (!BOTCCT.get()) {
                BOTCCT = std::make_shared<ScriptAST>();
                BOTCCT->type = t::BotT ;
            }
            return BOTCCT;
        }

        bool isImmediateInteger() const {
                switch (type) {
                    case ObjX:
                        return arrayList[0]->isImmediateInteger() ;
                    case Boolean:
                    case Integer:
                    case Double:
                    case String:
                    case Array:
                    case Tuple:
                    case TupleT:
                    case Function:
                        return true;
                    default:
                        return false;
                }
        }

        static inline DPtr<ScriptAST> null_() {
            if (!NULLO.get()) {
                NULLO = std::make_shared<ScriptAST>();
                NULLO->type = t::NullE ;
            }
            return NULLO;
        }

        /**
         * Infers the type associated to the given object if this was not calculated yet.
         * @return
         */
        DPtr<script::structures::ScriptAST> typeInference();

    private:
        static DPtr<ScriptAST> TRUE, FALSE, BOOLEANT, DOUBLET, INTEGERT, STRINGT, START, ANYT, BOTCCT, NULLO;


        /**
         * Typing a specific objectId within the database!
         * @param id    Object Id within the database
         * @return      Associated LexT
         */
        DPtr<ScriptAST> upTypeObjX(size_t id);
    };
}

//struct DPointerASTWrapper {
//    const std::string ptr;
//    DPointerASTWrapper(const DPtr<script::structures::ScriptAST>& ptr) : ptr{ptr->toString(false)} {}
//};
//
//namespace std {
//    template <> struct hash<struct DPointerASTWrapper> {
//        std::hash<std::string> H;
//        size_t operator()(const struct DPointerASTWrapper& x) const {
//            return H(x.ptr);
//        }
//    };
//}



#endif //GSM_GSQL_SCRIPTAST_H
