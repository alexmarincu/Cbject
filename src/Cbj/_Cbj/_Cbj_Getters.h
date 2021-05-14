#ifndef _CBJ_GETTERS_H
#define _CBJ_GETTERS_H
#include "_Cbj_Utils.h"

#define _Cbj_Getters_stripParenthesesAndApplyGet(propPrototype) \
    Get propPrototype;

#define _Cbj_Getters_0(...)

#define _Cbj_Getters__(...) \
    _Cbj_Utils_forEach(_Cbj_Getters_stripParenthesesAndApplyGet, __VA_ARGS__)

#define _Cbj_Getters(mCase, ...) \
    _Cbj_Getters_##mCase (__VA_ARGS__)

#endif // _CBJ_GETTERS_H
