#ifndef _CBJECTCONSTS_H
#define _CBJECTCONSTS_H
#include "_CbjectUtilities.h"

#define _CbjectConsts_stripParenthesesAndApplyConst(constPrototype) \
    Const constPrototype;

#define _CbjectConsts_0(...)

#define _CbjectConsts__(...) \
    _CbjectUtilities_forEach(_CbjectConsts_stripParenthesesAndApplyConst, __VA_ARGS__)

#define _CbjectConsts(case, ...) \
    _CbjectConsts_##case (__VA_ARGS__)

#endif // _CBJECTCONSTS_H
