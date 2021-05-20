#ifndef ___CBJ_DEFAULTSETTERS_H
#define ___CBJ_DEFAULTSETTERS_H
#include "___Cbj_Utils.h"

#define ___Cbj_DefaultSetProps_stripParenthesesAndApplyDefaultSetProp(propPrototype) \
    DefaultSetProp propPrototype;

#define ___Cbj_DefaultSetProps_0(...)

#define ___Cbj_DefaultSetProps__(...) \
    ___Cbj_Utils_forEach(___Cbj_DefaultSetProps_stripParenthesesAndApplyDefaultSetProp, __VA_ARGS__)

#define ___Cbj_DefaultSetProps(case, ...) \
    ___Cbj_DefaultSetProps_##case (__VA_ARGS__)

#endif // ___CBJ_DEFAULTSETTERS_H
