#ifndef CBJECTPRIVATEFUNCTIONS_H
#define CBJECTPRIVATEFUNCTIONS_H
#include "CbjectUtilities.h"

#define CbjectPrivateFunctions_stripParenthesesAndApplyPrivateFunction(functionPrototype) \
    PrivateFunction functionPrototype;

#define CbjectPrivateFunctions0(...)

#define CbjectPrivateFunctions_(...) \
    CbjectUtilities_forEach(CbjectPrivateFunctions_stripParenthesesAndApplyPrivateFunction, __VA_ARGS__)

#define CbjectPrivateFunctions(case, ...) \
    CbjectPrivateFunctions##case (__VA_ARGS__)

#endif // CBJECTPRIVATEFUNCTIONS_H
