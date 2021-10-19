#ifndef CBJECT_CONSTS_H
#define CBJECT_CONSTS_H
#include "Cbject_Utils.h"

#define Cbject_Consts_stripParenthesesAndApplyConst(constPrototype) \
    Const constPrototype;

#define Cbject_Consts_0(...)

#define Cbject_Consts_(...) \
    Cbject_Utils_forEach(Cbject_Consts_stripParenthesesAndApplyConst, __VA_ARGS__)

#define Cbject_Consts(case, ...) \
    Cbject_Consts_##case (__VA_ARGS__)

#endif // CBJECT_CONSTS_H
