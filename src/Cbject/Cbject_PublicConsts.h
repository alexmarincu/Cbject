#ifndef CBJECT_PUBLICCONSTS_H
#define CBJECT_PUBLICCONSTS_H
#include "Cbject_Utils.h"

#define Cbject_PublicConsts_stripParenthesesAndApplyPublicConst(constPrototype) \
    PublicConst constPrototype;

#define Cbject_PublicConsts_0(...)

#define Cbject_PublicConsts_(...) \
    Cbject_Utils_forEach(Cbject_PublicConsts_stripParenthesesAndApplyPublicConst, __VA_ARGS__)

#define Cbject_PublicConsts(case, ...) \
    Cbject_PublicConsts_##case (__VA_ARGS__)

#endif // CBJECT_PUBLICCONSTS_H
