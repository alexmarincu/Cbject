#ifndef _CBJ_PUBLICCONSTS_H
#define _CBJ_PUBLICCONSTS_H
#include "_Cbj_Utils.h"

#define _Cbj_PublicConsts_stripParenthesesAndApplyPublicConst(constPrototype) \
    PublicConst constPrototype;

#define _Cbj_PublicConsts_0(...)

#define _Cbj_PublicConsts__(...) \
    _Cbj_Utils_forEach(_Cbj_PublicConsts_stripParenthesesAndApplyPublicConst, __VA_ARGS__)

#define _Cbj_PublicConsts(case, ...) \
    _Cbj_PublicConsts_##case (__VA_ARGS__)

#endif // _CBJ_PUBLICCONSTS_H
