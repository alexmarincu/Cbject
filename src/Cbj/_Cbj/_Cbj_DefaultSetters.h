#ifndef _CBJ_DEFAULTSETTERS_H
#define _CBJ_DEFAULTSETTERS_H
#include "_Cbj_Utils.h"

#define _Cbj_DefaultSetters_stripParenthesesAndApplyDefaultSet(propPrototype) \
    DefaultSet propPrototype;

#define _Cbj_DefaultSetters_0(...)

#define _Cbj_DefaultSetters__(...) \
    _Cbj_Utils_forEach(_Cbj_DefaultSetters_stripParenthesesAndApplyDefaultSet, __VA_ARGS__)

#define _Cbj_DefaultSetters(case, ...) \
    _Cbj_DefaultSetters_##case (__VA_ARGS__)

#endif // _CBJ_DEFAULTSETTERS_H
