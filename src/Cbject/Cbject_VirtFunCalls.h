#ifndef CBJECT_VIRTFUNCALLS_H
#define CBJECT_VIRTFUNCALLS_H
#include "Cbject_Utils.h"

#define Cbject_VirtFunCalls_caseVirtFunCalls_virtFunCall(virtFunPrototype) \
    VirtFun virtFunPrototype;

#define Cbject_VirtFunCalls_case(...)

#define Cbject_VirtFunCalls_caseVirtFunCalls(...) \
    Cbject_Utils_forEach(Cbject_VirtFunCalls_caseVirtFunCalls_virtFunCall, __VA_ARGS__)

#define Cbject_VirtFunCalls_switch(case, ...) \
    Cbject_VirtFunCalls_case##case (__VA_ARGS__)

#define Cbject_VirtFunCalls_x(...) \
    Cbject_VirtFunCalls_switch(__VA_ARGS__)

#define Cbject_VirtFunCalls(virtFunCalls) \
    Cbject_VirtFunCalls_x(Cbject_Utils_unpack(virtFunCalls))

#endif // CBJECT_VIRTFUNCALLS_H
