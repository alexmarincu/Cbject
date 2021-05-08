#ifndef _CBJ_OVERRIDEFUNS_H
#define _CBJ_OVERRIDEFUNS_H
#include "_Cbj_Utils.h"

#define _Cbj_OverrideFuns_stripParenthesesAndApplySuperFun(funPrototype) \
    OverrideFun funPrototype;

#define _Cbj_OverrideFuns_0(...)

#define _Cbj_OverrideFuns__(...) \
    _Cbj_Utils_forEach(_Cbj_OverrideFuns_stripParenthesesAndApplySuperFun, __VA_ARGS__)

#define _Cbj_OverrideFuns(case, ...) \
    _Cbj_OverrideFuns_##case (__VA_ARGS__)

#endif // _CBJ_OVERRIDEFUNS_H
