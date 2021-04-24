#ifndef CBJECTFUNCTIONS_H
#define CBJECTFUNCTIONS_H
#include "CbjectUtilities.h"

#define CbjectFunctions_stripParenthesesAndApplyFunction(functionPrototype) \
    Function functionPrototype;

#define CbjectFunctions0(...)

#define CbjectFunctions_(...) \
    CbjectUtilities_forEach(CbjectFunctions_stripParenthesesAndApplyFunction, __VA_ARGS__)

#define CbjectFunctions(case, ...) \
    CbjectFunctions##case (__VA_ARGS__)

#endif // CBJECTFUNCTIONS_H
