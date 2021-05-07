#ifndef _CBJECTPRIVATECONSTS_H
#define _CBJECTPRIVATECONSTS_H
#include "_CbjectUtilities.h"

#define _CbjectPrivateConsts_stripParenthesesAndApplyPrivateConst(constPrototype) \
    PrivateConst constPrototype;

#define _CbjectPrivateConsts_0(...)

#define _CbjectPrivateConsts__(...) \
    _CbjectUtilities_forEach(_CbjectPrivateConsts_stripParenthesesAndApplyPrivateConst, __VA_ARGS__)

#define _CbjectPrivateConsts(case, ...) \
    _CbjectPrivateConsts_##case (__VA_ARGS__)

#endif // _CBJECTPRIVATECONSTS_H
