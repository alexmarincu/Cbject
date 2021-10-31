#ifndef CBJECT_VIRTFUNCALLS_H
#define CBJECT_VIRTFUNCALLS_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCalls_stripParenthesesAndApplyVirtFunCall(virtFunPrototype) \
    VirtFun virtFunPrototype;

#define Cbject_VirtFunCalls_void(...)

#define Cbject_VirtFunCalls_(...) \
    Cbject_Utils_forEach(Cbject_VirtFunCalls_stripParenthesesAndApplyVirtFunCall, __VA_ARGS__)

#define Cbject_VirtFunCalls__(case, ...) \
    Cbject_VirtFunCalls_##case (__VA_ARGS__)

#define Cbject_VirtFunCalls(...) \
    Cbject_VirtFunCalls__(__VA_ARGS__)

#endif // CBJECT_VIRTFUNCALLS_H
