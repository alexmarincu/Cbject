#ifndef CBJECT_FUNS_H
#define CBJECT_FUNS_H
#include "Cbject_Utils.h"

#define Cbject_Funs_stripParenthesesAndApplyFun(funPrototype) \
    Fun funPrototype;

#define Cbject_Funs_case_(...)

#define Cbject_Funs_case_virtFuns(...) \
    Cbject_Utils_forEach(Cbject_Funs_stripParenthesesAndApplyFun, __VA_ARGS__)

#define Cbject_Funs_switch(case, ...) \
    Cbject_Funs_case_##case (__VA_ARGS__)

#define Cbject_Funs_x(...) \
    Cbject_Funs_switch(__VA_ARGS__)

#define Cbject_Funs(virtFuns) \
    Cbject_Funs_x(Cbject_Utils_stripParentheses(virtFuns))

#endif // CBJECT_FUNS_H
