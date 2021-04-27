#ifndef _CBJECTFUNCTIONS_H
#define _CBJECTFUNCTIONS_H
#include "_CbjectUtilities.h"

#define _CbjectFunctions_stripParenthesesAndApplyFunction(functionPrototype) \
    Function functionPrototype;

#define _CbjectFunctions0(...)

#define _CbjectFunctions_(...) \
    _CbjectUtilities_forEach(_CbjectFunctions_stripParenthesesAndApplyFunction, __VA_ARGS__)

#define _CbjectFunctions(case, ...) \
    _CbjectFunctions##case (__VA_ARGS__)

#endif // _CBJECTFUNCTIONS_H
