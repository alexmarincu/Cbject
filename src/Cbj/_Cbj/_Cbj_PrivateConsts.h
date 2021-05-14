#ifndef _CBJ_PRIVATECONSTS_H
#define _CBJ_PRIVATECONSTS_H
#include "_Cbj_Utils.h"

#define _Cbj_PrivateConsts_stripParenthesesAndApplyPrivateConst(constPrototype) \
    PrivateConst constPrototype;

#define _Cbj_PrivateConsts_0(...)

#define _Cbj_PrivateConsts__(...) \
    _Cbj_Utils_forEach(_Cbj_PrivateConsts_stripParenthesesAndApplyPrivateConst, __VA_ARGS__)

#define _Cbj_PrivateConsts(mCase, ...) \
    _Cbj_PrivateConsts_##mCase (__VA_ARGS__)

#endif // _CBJ_PRIVATECONSTS_H
