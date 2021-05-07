#ifndef _CBJECTPUBLICCONSTS_H
#define _CBJECTPUBLICCONSTS_H
#include "_CbjectUtilities.h"

#define _CbjectPublicConsts_stripParenthesesAndApplyPublicConst(constPrototype) \
    PublicConst constPrototype;

#define _CbjectPublicConsts_0(...)

#define _CbjectPublicConsts__(...) \
    _CbjectUtilities_forEach(_CbjectPublicConsts_stripParenthesesAndApplyPublicConst, __VA_ARGS__)

#define _CbjectPublicConsts(case, ...) \
    _CbjectPublicConsts_##case (__VA_ARGS__)

#endif // _CBJECTPUBLICCONSTS_H
