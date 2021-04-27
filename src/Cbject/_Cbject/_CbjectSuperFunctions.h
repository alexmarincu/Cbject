#ifndef _CBJECTSUPERFUNCTIONS_H
#define _CBJECTSUPERFUNCTIONS_H
#include "_CbjectUtilities.h"

#define _CbjectSuperFunctions_stripParenthesesAndApplySuperFunction(functionPrototype) \
    SuperFunction functionPrototype;

#define _CbjectSuperFunctions0(...)

#define _CbjectSuperFunctions_(...) \
    _CbjectUtilities_forEach(_CbjectSuperFunctions_stripParenthesesAndApplySuperFunction, __VA_ARGS__)

#define _CbjectSuperFunctions(case, ...) \
    _CbjectSuperFunctions##case (__VA_ARGS__)

#endif // _CBJECTSUPERFUNCTIONS_H
