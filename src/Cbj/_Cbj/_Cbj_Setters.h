#ifndef _CBJ_SETTERS_H
#define _CBJ_SETTERS_H
#include "_Cbj_Utils.h"

#define _Cbj_Setters_stripParenthesesAndApplySet(propPrototype) \
    Set propPrototype;

#define _Cbj_Setters_0(...)

#define _Cbj_Setters__(...) \
    _Cbj_Utils_forEach(_Cbj_Setters_stripParenthesesAndApplySet, __VA_ARGS__)

#define _Cbj_Setters(mCase, ...) \
    _Cbj_Setters_##mCase (__VA_ARGS__)

#endif // _CBJ_SETTERS_H
