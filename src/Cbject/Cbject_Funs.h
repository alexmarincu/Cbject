#ifndef CBJECT_FUNS_H
#define CBJECT_FUNS_H
#include "Cbject_Utils.h"

#define Cbject_Funs_stripParenthesesAndApplyFun(funPrototype) \
    Fun funPrototype;

#define Cbject_Funs_(...)

#define Cbject_Funs_args(...) \
    Cbject_Utils_forEach(Cbject_Funs_stripParenthesesAndApplyFun, __VA_ARGS__)

#define Cbject_Funs_case(case, ...) \
    Cbject_Funs_##case (__VA_ARGS__)

#define Cbject_Funs(...) \
    Cbject_Funs_case(__VA_ARGS__)

#endif // CBJECT_FUNS_H
