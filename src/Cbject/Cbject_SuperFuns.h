#ifndef CBJECT_SUPERFUNS_H
#define CBJECT_SUPERFUNS_H
#include "Cbject_Utils.h"

#define Cbject_SuperFuns_stripParenthesesAndApplySuperFun(funPrototype) \
    SuperFun funPrototype;

#define Cbject_SuperFuns_0(...)

#define Cbject_SuperFuns_(...) \
    Cbject_Utils_forEach(Cbject_SuperFuns_stripParenthesesAndApplySuperFun, __VA_ARGS__)

#define Cbject_SuperFuns(case, ...) \
    Cbject_SuperFuns_##case (__VA_ARGS__)

#endif // CBJECT_SUPERFUNS_H
