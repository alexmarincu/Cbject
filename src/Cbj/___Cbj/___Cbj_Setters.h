#ifndef ___CBJ_SETTERS_H
#define ___CBJ_SETTERS_H
#include "___Cbj_Utils.h"

#define ___Cbj_Setters_stripParenthesesAndApplySet(propPrototype) \
    Set propPrototype;

#define ___Cbj_Setters_0(...)

#define ___Cbj_Setters__(...) \
    ___Cbj_Utils_forEach(___Cbj_Setters_stripParenthesesAndApplySet, __VA_ARGS__)

#define ___Cbj_Setters(case, ...) \
    ___Cbj_Setters_##case (__VA_ARGS__)

#endif // ___CBJ_SETTERS_H
