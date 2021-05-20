#ifndef ___CBJ_GETTERS_H
#define ___CBJ_GETTERS_H
#include "___Cbj_Utils.h"

#define ___Cbj_GetProps_stripParenthesesAndApplyGetProp(propPrototype) \
    GetProp propPrototype;

#define ___Cbj_GetProps_0(...)

#define ___Cbj_GetProps__(...) \
    ___Cbj_Utils_forEach(___Cbj_GetProps_stripParenthesesAndApplyGetProp, __VA_ARGS__)

#define ___Cbj_GetProps(case, ...) \
    ___Cbj_GetProps_##case (__VA_ARGS__)

#endif // ___CBJ_GETTERS_H
