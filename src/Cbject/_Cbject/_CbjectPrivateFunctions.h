#ifndef _CBJECTPRIVATEFUNCTIONS_H
#define _CBJECTPRIVATEFUNCTIONS_H
#include "_CbjectUtilities.h"

#define _CbjectPrivateFunctions_stripParenthesesAndApplyPrivateFunction(functionPrototype) \
    PrivateFunction functionPrototype;

#define _CbjectPrivateFunctions0(...)

#define _CbjectPrivateFunctions_(...) \
    _CbjectUtilities_forEach(_CbjectPrivateFunctions_stripParenthesesAndApplyPrivateFunction, __VA_ARGS__)

#define _CbjectPrivateFunctions(case, ...) \
    _CbjectPrivateFunctions##case (__VA_ARGS__)

#endif // _CBJECTPRIVATEFUNCTIONS_H
