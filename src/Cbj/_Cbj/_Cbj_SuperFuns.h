#ifndef _CBJ_SUPERFUNS_H
#define _CBJ_SUPERFUNS_H
#include "_Cbj_Utils.h"

#define _Cbj_SuperFuns_stripParenthesesAndApplySuperFun(mFunPrototype) \
    SuperFun mFunPrototype;

#define _Cbj_SuperFuns_0(...)

#define _Cbj_SuperFuns__(...) \
    _Cbj_Utils_forEach(_Cbj_SuperFuns_stripParenthesesAndApplySuperFun, __VA_ARGS__)

#define _Cbj_SuperFuns(mCase, ...) \
    _Cbj_SuperFuns_##mCase (__VA_ARGS__)

#endif // _CBJ_SUPERFUNS_H
