#ifndef ___CBJ_SUPERFUNS_H
#define ___CBJ_SUPERFUNS_H
#include "___Cbj_Utils.h"

#define ___Cbj_SuperFuns_stripParenthesesAndApplySuperFun(funPrototype) \
    SuperFun funPrototype;

#define ___Cbj_SuperFuns_0(...)

#define ___Cbj_SuperFuns__(...) \
    ___Cbj_Utils_forEach(___Cbj_SuperFuns_stripParenthesesAndApplySuperFun, __VA_ARGS__)

#define ___Cbj_SuperFuns(case, ...) \
    ___Cbj_SuperFuns_##case (__VA_ARGS__)

#endif // ___CBJ_SUPERFUNS_H
