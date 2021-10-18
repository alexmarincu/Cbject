#ifndef ___CBJ_VIRTFUNCALLS_H
#define ___CBJ_VIRTFUNCALLS_H
#include "___Cbj_Utils.h"

#define ___Cbj_VirtFunCalls_stripParenthesesAndApplyVirtFunCall(virtFunPrototype) \
    VirtFun virtFunPrototype;

#define ___Cbj_VirtFunCalls_0(...)

#define ___Cbj_VirtFunCalls_(...) \
    ___Cbj_Utils_forEach(___Cbj_VirtFunCalls_stripParenthesesAndApplyVirtFunCall, __VA_ARGS__)

#define ___Cbj_VirtFunCalls__(case, ...) \
    ___Cbj_VirtFunCalls_##case (__VA_ARGS__)

#define ___Cbj_VirtFunCalls(...) \
    ___Cbj_VirtFunCalls__(__VA_ARGS__)

#endif // ___CBJ_VIRTFUNCALLS_H
