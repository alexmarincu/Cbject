#ifndef _CBJECTPRIVATEFUNCTIONS_H
#define _CBJECTPRIVATEFUNCTIONS_H
#include "_CbjectUtilities.h"

#define _CbjectPrivateFuns_stripParenthesesAndApplyPrivateFun(funPrototype) \
    PrivateFun funPrototype;

#define _CbjectPrivateFuns_0(...)

#define _CbjectPrivateFuns__(...) \
    _CbjectUtilities_forEach(_CbjectPrivateFuns_stripParenthesesAndApplyPrivateFun, __VA_ARGS__)

#define _CbjectPrivateFuns(case, ...) \
    _CbjectPrivateFuns_##case (__VA_ARGS__)

#endif // _CBJECTPRIVATEFUNCTIONS_H
