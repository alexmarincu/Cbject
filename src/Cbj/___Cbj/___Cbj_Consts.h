#ifndef ___CBJ_CONSTS_H
#define ___CBJ_CONSTS_H
#include "___Cbj_Utils.h"

#define ___Cbj_Consts_stripParenthesesAndApplyConst(constPrototype) \
    Const constPrototype;

#define ___Cbj_Consts_0(...)

#define ___Cbj_Consts_(...) \
    ___Cbj_Utils_forEach(___Cbj_Consts_stripParenthesesAndApplyConst, __VA_ARGS__)

#define ___Cbj_Consts(case, ...) \
    ___Cbj_Consts_##case (__VA_ARGS__)

#endif // ___CBJ_CONSTS_H
