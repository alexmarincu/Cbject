#ifndef _CBJECTFUNCTIONS_H
#define _CBJECTFUNCTIONS_H
#include "_CbjectUtilities.h"

#define _CbjectFuns_stripParenthesesAndApplyFun(funPrototype) \
    Fun funPrototype;

#define _CbjectFuns_0(...)

#define _CbjectFuns__(...) \
    _CbjectUtilities_forEach(_CbjectFuns_stripParenthesesAndApplyFun, __VA_ARGS__)

#define _CbjectFuns(case, ...) \
    _CbjectFuns_##case (__VA_ARGS__)

#endif // _CBJECTFUNCTIONS_H
