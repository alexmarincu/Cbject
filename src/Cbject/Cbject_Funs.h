#ifndef CBJECT_FUNS_H
#define CBJECT_FUNS_H
#include "Cbject_Utils.h"

#define Cbject_Funs_stripParenthesesAndApplyFun(funPrototype) \
    Fun funPrototype;

#define Cbject_Funs_0(...)

#define Cbject_Funs_(...) \
    Cbject_Utils_forEach(Cbject_Funs_stripParenthesesAndApplyFun, __VA_ARGS__)

#define Cbject_Funs(case, ...) \
    Cbject_Funs_##case (__VA_ARGS__)

#endif // CBJECT_FUNS_H