#ifndef CBJECT_VIRTFUNCALLS_H
#define CBJECT_VIRTFUNCALLS_H
#include "Cbject_Utils.h"
#include "Cbject_VirtFun.h"

#define Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl_x3(className, funCallParams, funReturnType, funName, funParams) \
    Cbject_VirtFun_Impl(className, funReturnType, funName, funParams, funCallParams);

#define Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl_x2(className, funCallParams, ...) \
    Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl_x3(className, funCallParams, __VA_ARGS__)

#define Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl_x1(className, funPrototype, funCallParams) \
    Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl_x2(className, funCallParams, Cbject_Utils_unpack(funPrototype))

#define Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl_x0(className, ...) \
    Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl_x1(className, __VA_ARGS__)

#define Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl(funPrototypeWithCallParams) \
    Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl_x0(Type, Cbject_Utils_unpack(funPrototypeWithCallParams))

#define Cbject_VirtFunCalls_case(...)

#define Cbject_VirtFunCalls_caseVirtFunCalls(...) \
    Cbject_Utils_forEach(Cbject_VirtFunCalls_caseVirtFunCalls_virtFunImpl, __VA_ARGS__)

#define Cbject_VirtFunCalls_x1(case, ...) \
    Cbject_VirtFunCalls_case##case (__VA_ARGS__)

#define Cbject_VirtFunCalls_x0(...) \
    Cbject_VirtFunCalls_x1(__VA_ARGS__)

#define Cbject_VirtFunCalls(virtFunCalls) \
    Cbject_VirtFunCalls_x0(Cbject_Utils_unpack(virtFunCalls))

#endif // CBJECT_VIRTFUNCALLS_H
