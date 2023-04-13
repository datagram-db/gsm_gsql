//
// Created by giacomo on 09/04/23.
//

#ifndef GSM_GSQL_TRINARYFUNCTION_H
#define GSM_GSQL_TRINARYFUNCTION_H

#include <string>

namespace script::lambdas {
    template <typename X, typename Y, typename Z, typename T>
    struct TrinaryFunction {
        virtual T operator()(X arg0, Y arg1, Z arg2) = 0;
        virtual std::string opRepresentation() { return ""; }
    };
}

#endif //GSM_GSQL_TRINARYFUNCTION_H
