#ifndef ___CBJ_PRIVATEFUNS_H
#define ___CBJ_PRIVATEFUNS_H
#include "___Cbj_Utils.h"

#define ___Cbj_PrivateFuns_stripParenthesesAndApplyPrivateFun(funPrototype) \
    PrivateFun funPrototype;

#define ___Cbj_PrivateFuns_0(...)

#define ___Cbj_PrivateFuns_(...) \
    ___Cbj_Utils_forEach(___Cbj_PrivateFuns_stripParenthesesAndApplyPrivateFun, __VA_ARGS__)

#define ___Cbj_PrivateFuns(case, ...) \
    ___Cbj_PrivateFuns_##case (__VA_ARGS__)

#endif // ___CBJ_PRIVATEFUNS_H
