#ifndef _CBJ_PRIVATEFUNS_H
#define _CBJ_PRIVATEFUNS_H
#include "_Cbj_Utils.h"

#define _Cbj_PrivateFuns_stripParenthesesAndApplyPrivateFun(funPrototype) \
    PrivateFun funPrototype;

#define _Cbj_PrivateFuns_0(...)

#define _Cbj_PrivateFuns__(...) \
    _Cbj_Utils_forEach(_Cbj_PrivateFuns_stripParenthesesAndApplyPrivateFun, __VA_ARGS__)

#define _Cbj_PrivateFuns(case, ...) \
    _Cbj_PrivateFuns_##case (__VA_ARGS__)

#endif // _CBJ_PRIVATEFUNS_H
