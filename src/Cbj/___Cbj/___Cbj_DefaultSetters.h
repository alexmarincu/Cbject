#ifndef ___CBJ_DEFAULTSETTERS_H
#define ___CBJ_DEFAULTSETTERS_H
#include "___Cbj_Utils.h"

#define ___Cbj_DefaultSetters_stripParenthesesAndApplyDefaultSet(propPrototype) \
    DefaultSet propPrototype;

#define ___Cbj_DefaultSetters_0(...)

#define ___Cbj_DefaultSetters__(...) \
    ___Cbj_Utils_forEach(___Cbj_DefaultSetters_stripParenthesesAndApplyDefaultSet, __VA_ARGS__)

#define ___Cbj_DefaultSetters(case, ...) \
    ___Cbj_DefaultSetters_##case (__VA_ARGS__)

#endif // ___CBJ_DEFAULTSETTERS_H
