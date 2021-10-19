#ifndef CBJECT_PRIVATECONSTS_H
#define CBJECT_PRIVATECONSTS_H
#include "Cbject_Utils.h"

#define Cbject_PrivateConsts_stripParenthesesAndApplyPrivateConst(constPrototype) \
    PrivateConst constPrototype;

#define Cbject_PrivateConsts_0(...)

#define Cbject_PrivateConsts_(...) \
    Cbject_Utils_forEach(Cbject_PrivateConsts_stripParenthesesAndApplyPrivateConst, __VA_ARGS__)

#define Cbject_PrivateConsts(case, ...) \
    Cbject_PrivateConsts_##case (__VA_ARGS__)

#endif // CBJECT_PRIVATECONSTS_H
