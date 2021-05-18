#ifndef _CBJ_FUNS_H
#define _CBJ_FUNS_H
#include "_Cbj_Utils.h"

#define _Cbj_Funs_stripParenthesesAndApplyFun(funPrototype) \
    Fun funPrototype;

#define _Cbj_Funs_0(...)

#define _Cbj_Funs__(...) \
    _Cbj_Utils_forEach(_Cbj_Funs_stripParenthesesAndApplyFun, __VA_ARGS__)

#define _Cbj_Funs(case, ...) \
    _Cbj_Funs_##case (__VA_ARGS__)

#endif // _CBJ_FUNS_H
