#ifndef CBJECT_VIRTFUNSETUP_H
#define CBJECT_VIRTFUNSETUP_H
#include "Cbject_Utils.h"
#include "Cbject_VirtFun.h"

/*
Cbject_VirtFunSetup
*/
#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x3(className, funCallParams, funReturnType, funName, funParams) \
    Cbject_VirtFun_Impl(className, funReturnType, funName, funParams, funCallParams);

#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x2(className, funCallParams, ...) \
    Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x3(className, funCallParams, __VA_ARGS__)

#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x1(className, funPrototype, funCallParams) \
    Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x2(className, funCallParams, Cbject_Utils_unpack(funPrototype))

#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x0(className, ...) \
    Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x1(className, __VA_ARGS__)

#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl(funPrototypeWithCallParams) \
    Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x0(Type, Cbject_Utils_unpack(funPrototypeWithCallParams))

#define Cbject_VirtFunSetup_caseNA(...)

#define Cbject_VirtFunSetup_caseVirtFunSetup(...) \
    Cbject_Utils_forEach(Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl, __VA_ARGS__)

#define Cbject_VirtFunSetup_x1(case, ...) \
    Cbject_VirtFunSetup_case##case (__VA_ARGS__)

#define Cbject_VirtFunSetup_x0(...) \
    Cbject_VirtFunSetup_x1(__VA_ARGS__)

#define Cbject_VirtFunSetup(virtFunSetup) \
    Cbject_VirtFunSetup_x0(Cbject_Utils_unpack(virtFunSetup))

#endif // CBJECT_VIRTFUNSETUP_H
