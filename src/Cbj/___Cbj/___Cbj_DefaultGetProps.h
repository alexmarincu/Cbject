#ifndef _CBJ_DEFAULTGETTERS_H
#define _CBJ_DEFAULTGETTERS_H
#include "___Cbj_Utils.h"

#define ___Cbj_DefaultGetProps_stripParenthesesAndApplyDefaultGet(propPrototype) \
    DefaultGetProp propPrototype

#define ___Cbj_DefaultGetProps_0(...)

#define ___Cbj_DefaultGetProps_(...) \
    ___Cbj_Utils_forEach(___Cbj_DefaultGetProps_stripParenthesesAndApplyDefaultGet, __VA_ARGS__)

#define ___Cbj_DefaultGetProps(case, ...) \
    ___Cbj_DefaultGetProps_##case (__VA_ARGS__)

#endif // _CBJ_DEFAULTGETTERS_H
