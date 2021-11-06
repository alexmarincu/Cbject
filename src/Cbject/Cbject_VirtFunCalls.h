#ifndef CBJECT_VIRTFUNCALLS_H
#define CBJECT_VIRTFUNCALLS_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCalls_stripParenthesesAndApplyVirtFunCall(virtFunPrototype) \
    VirtFun virtFunPrototype;

#define Cbject_VirtFunCalls_case_(...)

#define Cbject_VirtFunCalls_case_VirtFunCalls(...) \
    Cbject_Utils_forEach(Cbject_VirtFunCalls_stripParenthesesAndApplyVirtFunCall, __VA_ARGS__)

#define Cbject_VirtFunCalls_switch(case, ...) \
    Cbject_VirtFunCalls_case_##case (__VA_ARGS__)

#define Cbject_VirtFunCalls_x1(...) \
    Cbject_VirtFunCalls_switch(__VA_ARGS__)

#define Cbject_VirtFunCalls(virtFunCalls) \
    Cbject_VirtFunCalls_x1(Cbject_Utils_unpack(virtFunCalls))

#endif // CBJECT_VIRTFUNCALLS_H
