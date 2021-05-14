#ifndef _CBJ_CONSTS_H
#define _CBJ_CONSTS_H
#include "_Cbj_Utils.h"

#define _Cbj_Consts_stripParenthesesAndApplyConst(constPrototype) \
    Const constPrototype;

#define _Cbj_Consts_0(...)

#define _Cbj_Consts__(...) \
    _Cbj_Utils_forEach(_Cbj_Consts_stripParenthesesAndApplyConst, __VA_ARGS__)

#define _Cbj_Consts(mCase, ...) \
    _Cbj_Consts_##mCase (__VA_ARGS__)

#endif // _CBJ_CONSTS_H
