#ifndef ___CBJ_PUBLICCONSTS_H
#define ___CBJ_PUBLICCONSTS_H
#include "___Cbj_Utils.h"

#define ___Cbj_PublicConsts_stripParenthesesAndApplyPublicConst(constPrototype) \
    PublicConst constPrototype;

#define ___Cbj_PublicConsts_0(...)

#define ___Cbj_PublicConsts_(...) \
    ___Cbj_Utils_forEach(___Cbj_PublicConsts_stripParenthesesAndApplyPublicConst, __VA_ARGS__)

#define ___Cbj_PublicConsts(case, ...) \
    ___Cbj_PublicConsts_##case (__VA_ARGS__)

#endif // ___CBJ_PUBLICCONSTS_H
