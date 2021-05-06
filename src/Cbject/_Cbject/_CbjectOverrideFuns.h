#ifndef _CBJECTSUPERFUNCTIONS_H
#define _CBJECTSUPERFUNCTIONS_H
#include "_CbjectUtilities.h"

#define _CbjectOverrideFuns_stripParenthesesAndApplySuperFun(funPrototype) \
    OverrideFun funPrototype;

#define _CbjectOverrideFuns_0(...)

#define _CbjectOverrideFuns__(...) \
    _CbjectUtilities_forEach(_CbjectOverrideFuns_stripParenthesesAndApplySuperFun, __VA_ARGS__)

#define _CbjectOverrideFuns(case, ...) \
    _CbjectOverrideFuns_##case (__VA_ARGS__)

#endif // _CBJECTSUPERFUNCTIONS_H
