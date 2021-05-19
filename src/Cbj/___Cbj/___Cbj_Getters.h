#ifndef ___CBJ_GETTERS_H
#define ___CBJ_GETTERS_H
#include "___Cbj_Utils.h"

#define ___Cbj_Getters_stripParenthesesAndApplyGet(propPrototype) \
    Get propPrototype;

#define ___Cbj_Getters_0(...)

#define ___Cbj_Getters__(...) \
    ___Cbj_Utils_forEach(___Cbj_Getters_stripParenthesesAndApplyGet, __VA_ARGS__)

#define ___Cbj_Getters(case, ...) \
    ___Cbj_Getters_##case (__VA_ARGS__)

#endif // ___CBJ_GETTERS_H
