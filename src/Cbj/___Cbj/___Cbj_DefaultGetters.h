#ifndef ___CBJ_DEFAULTGETTERS_H
#define ___CBJ_DEFAULTGETTERS_H
#include "___Cbj_Utils.h"

#define ___Cbj_DefaultGetters_stripParenthesesAndApplyDefaultGet(propPrototype) \
    DefaultGet propPrototype

#define ___Cbj_DefaultGetters_0(...)

#define ___Cbj_DefaultGetters__(...) \
    ___Cbj_Utils_forEach(___Cbj_DefaultGetters_stripParenthesesAndApplyDefaultGet, __VA_ARGS__)

#define ___Cbj_DefaultGetters(case, ...) \
    ___Cbj_DefaultGetters_##case (__VA_ARGS__)

#endif // ___CBJ_DEFAULTGETTERS_H
