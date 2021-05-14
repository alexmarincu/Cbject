#ifndef _CBJ_DEFAULTGETTERS_H
#define _CBJ_DEFAULTGETTERS_H
#include "_Cbj_Utils.h"

#define _Cbj_DefaultGetters_stripParenthesesAndApplyDefaultGet(propPrototype) \
    DefaultGet propPrototype

#define _Cbj_DefaultGetters_0(...)

#define _Cbj_DefaultGetters__(...) \
    _Cbj_Utils_forEach(_Cbj_DefaultGetters_stripParenthesesAndApplyDefaultGet, __VA_ARGS__)

#define _Cbj_DefaultGetters(mCase, ...) \
    _Cbj_DefaultGetters_##mCase (__VA_ARGS__)

#endif // _CBJ_DEFAULTGETTERS_H
