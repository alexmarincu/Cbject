#ifndef _CBJ_VIRTFUNCALLS_H
#define _CBJ_VIRTFUNCALLS_H
#include "_Cbj_Utils.h"

#define _Cbj_VirtFunCalls_stripParenthesesAndApplyVirtFunCall(mVirtFunPrototype) \
    VirtFun mVirtFunPrototype;

#define _Cbj_VirtFunCalls_0(...)

#define _Cbj_VirtFunCalls__(...) \
    _Cbj_Utils_forEach(_Cbj_VirtFunCalls_stripParenthesesAndApplyVirtFunCall, __VA_ARGS__)

#define _Cbj_VirtFunCalls_(mCase, ...) \
    _Cbj_VirtFunCalls_##mCase (__VA_ARGS__)

#define _Cbj_VirtFunCalls(...) \
    _Cbj_VirtFunCalls_(__VA_ARGS__)

#endif // _CBJ_VIRTFUNCALLS_H
