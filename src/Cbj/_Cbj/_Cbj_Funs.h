#ifndef _CBJ_FUNS_H
#define _CBJ_FUNS_H
#include "_Cbj_Utils.h"

#define _Cbj_Funs_stripParenthesesAndApplyFun(mFunPrototype) \
    Fun mFunPrototype;

#define _Cbj_Funs_0(...)

#define _Cbj_Funs__(...) \
    _Cbj_Utils_forEach(_Cbj_Funs_stripParenthesesAndApplyFun, __VA_ARGS__)

#define _Cbj_Funs(mCase, ...) \
    _Cbj_Funs_##mCase (__VA_ARGS__)

#endif // _CBJ_FUNS_H
