#ifndef CBJECT_PRIVATEFUNS_H
#define CBJECT_PRIVATEFUNS_H
#include "Cbject_Utils.h"

#define Cbject_PrivateFuns_stripParenthesesAndApplyPrivateFun(funPrototype) \
    PrivateFun funPrototype;

#define Cbject_PrivateFuns_0(...)

#define Cbject_PrivateFuns_(...) \
    Cbject_Utils_forEach(Cbject_PrivateFuns_stripParenthesesAndApplyPrivateFun, __VA_ARGS__)

#define Cbject_PrivateFuns(case, ...) \
    Cbject_PrivateFuns_##case (__VA_ARGS__)

#endif // CBJECT_PRIVATEFUNS_H
