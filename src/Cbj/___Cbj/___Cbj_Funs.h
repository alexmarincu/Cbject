#ifndef ___CBJ_FUNS_H
#define ___CBJ_FUNS_H
#include "___Cbj_Utils.h"

#define ___Cbj_Funs_stripParenthesesAndApplyFun(funPrototype) \
    Fun funPrototype;

#define ___Cbj_Funs_0(...)

#define ___Cbj_Funs__(...) \
    ___Cbj_Utils_forEach(___Cbj_Funs_stripParenthesesAndApplyFun, __VA_ARGS__)

#define ___Cbj_Funs(case, ...) \
    ___Cbj_Funs_##case (__VA_ARGS__)

#endif // ___CBJ_FUNS_H
