//
// Created by giacomo on 09/04/23.
//

#ifndef GSM_GSQL_JAVIFICATION_H
#define GSM_GSQL_JAVIFICATION_H

#include <gsql_gsm/script_1/ScriptAST.h>

namespace script::structures {
    struct Javification {
        void *reference;
        Gamma gamma;

        Javification(void *reference);
        Javification(const Gamma& g, void* reference) : reference{reference}, gamma{g}  {}

        /**
         * Converts the java object into a "script language" object
         * @return
         */

//        ScriptAST toValue() {
//            if (reference instanceof ScriptAST)
//            return (ScriptAST) reference;
//
//            if (reference instanceof JPair) {
//                JPair cp = (JPair) reference;
//                ScriptAST cpa[] = new ScriptAST[2];
//                cpa[0] = new Javification(gamma, cp.key).toValue();
//                cpa[1] = new Javification(gamma, cp.value).toValue();
//                return new ScriptAST(gamma, cpa);
//            }
//
//            else if (reference.getClass().equals(int.class) || reference
//            instanceof
//            Integer) {
//                Integer i = (Integer) reference;
//                return new ScriptAST(gamma, new JId(i));
//            } else if (reference instanceof JId) {
//                JId i = (JId) reference;
//                return new ScriptAST(gamma, new JId(i));
//
//            } else if (reference.getClass().equals(double.class) || reference
//            instanceof
//            Double) {
//                Double d = (Double) reference;
//                return new ScriptAST(gamma, d);
//
//            } else if (reference instanceof String) {
//                return ScriptAST.string(gamma, reference.toString());
//
//            } else if (reference.getClass().equals(boolean.class) || reference
//            instanceof
//            Boolean) {
//                return new ScriptAST(gamma, (Boolean) reference);
//
//            } else if (reference instanceof Map) {
//                Map map = (Map) reference;
//                Set < Map.Entry > e = map.entrySet();
//                ScriptAST var[] = new ScriptAST[map.size()];
//                int i = 0;
//                for (Map.Entry o : e) {
//                    var[i++] = new Javification(gamma, new Object[]{o.getKey(), o.getValue()}).toValue();
//                }
//                return new ScriptAST(gamma, var);
//
//            } else if (reference instanceof Iterable) {
//                Iterator it = ((Iterable) reference).iterator();
//                ArrayList <ScriptAST> n = new ArrayList<>();
//                while (it.hasNext()) {
//                    Object x = it.next();
//                    if (x != null)
//                        n.add(new Javification(gamma, x).toValue());
//                }
//                return new ScriptAST(gamma, n);
//            } else if (reference instanceof Iterator) {
//                ArrayList <ScriptAST> n = new ArrayList<>();
//                Iterator it = (Iterator) reference;
//                while (it.hasNext()) {
//                    Object x = it.next();
//                    if (x != null)
//                        n.add(new Javification(gamma, x).toValue());
//                }
//                return new ScriptAST(gamma, n);
//            } else if (reference instanceof Stream) {
//                ArrayList <ScriptAST> n = new ArrayList<>();
//                Stream< ?> s = (Stream< ? >)reference;
//                Stream < ScriptAST > sv = s.map(x->
//                new Javification(gamma, x).toValue());
//                sv.collect(Collectors.toList()).forEach(n::add);
//                return new ScriptAST(gamma, n);
//            } else if (reference.getClass().isArray()) {
//                Object[]
//                coll = (Object[]) reference;
//                ArrayList <ScriptAST> n = new ArrayList<>();
//                int i = 0;
//                for (Object o: coll) {
//                    if (o != null)
//                        n.add(new Javification(gamma, o).toValue());
//                }
//                return new ScriptAST(gamma, n);
//            }
//            return new ScriptAST(gamma);
//        }
//
//        /**
//         * Invokes a method on a java object
//         * @param method
//         * @return
//         */
////        @MetaOperation
////        @Statement
////    public
//
//        ScriptAST invoke(Object method) {
//            if (reference instanceof Javification) {
//                return ((Javification) reference).invoke(method);
//            } else {
//                try {
//                    Method metodo = reference.getClass().getMethod(method.toString());
//                    metodo.setAccessible(true);
//                    return new ScriptAST(gamma, metodo.invoke(reference));
//                } catch (NoSuchMethodException | IllegalAccessException | InvocationTargetException
//                e) {
//                    e.printStackTrace();
//                }
//                return new ScriptAST(gamma);
//            }
//        }
    };
}


#endif //GSM_GSQL_JAVIFICATION_H
