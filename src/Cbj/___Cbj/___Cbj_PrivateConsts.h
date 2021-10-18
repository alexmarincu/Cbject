#ifndef ___CBJ_PRIVATECONSTS_H
#define ___CBJ_PRIVATECONSTS_H
#include "___Cbj_Utils.h"

#define ___Cbj_PrivateConsts_stripParenthesesAndApplyPrivateConst(constPrototype) \
    PrivateConst constPrototype;

#define ___Cbj_PrivateConsts_0(...)

#define ___Cbj_PrivateConsts_(...) \
    ___Cbj_Utils_forEach(___Cbj_PrivateConsts_stripParenthesesAndApplyPrivateConst, __VA_ARGS__)

#define ___Cbj_PrivateConsts(case, ...) \
    ___Cbj_PrivateConsts_##case (__VA_ARGS__)

#endif // ___CBJ_PRIVATECONSTS_H
