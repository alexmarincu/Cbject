#ifndef CBJECT_VIRTFUNSETUP_H
#define CBJECT_VIRTFUNSETUP_H
#include "Cbject_Utils.h"
#include "Cbject_VirtFun.h"

/*
Cbject_VirtFunSetup
*/
#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x3(class, funCallParamsPack, funReturnType, funName, funParamsPack) \
    Cbject_VirtFun_Impl(class, funReturnType, funName, funParamsPack, funCallParamsPack);

#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x2(class, funCallParamsPack, ...) \
    Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x3(class, funCallParamsPack, __VA_ARGS__)

#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x1(class, funPrototypePack, funCallParamsPack) \
    Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x2(class, funCallParamsPack, Cbject_Utils_unpack(funPrototypePack))

#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x0(class, ...) \
    Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x1(class, __VA_ARGS__)

#define Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl(funPrototypeWithCallParamsPack) \
    Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl_x0(Type, Cbject_Utils_unpack(funPrototypeWithCallParamsPack))

#define Cbject_VirtFunSetup_caseNA(class, ...)

#define Cbject_VirtFunSetup_caseVirtFunSetup(class, ...) \
    Cbject_ClassVirtFunsGetter_Impl(class);              \
    Cbject_Utils_forEach(Cbject_VirtFunSetup_caseVirtFunSetup_virtFunImpl, __VA_ARGS__)

#define Cbject_VirtFunSetup_x1(class, virtFunSetupCase, ...) \
    Cbject_VirtFunSetup_case##virtFunSetupCase(class, __VA_ARGS__)

#define Cbject_VirtFunSetup_x0(class, ...) \
    Cbject_VirtFunSetup_x1(class, __VA_ARGS__)

#define Cbject_VirtFunSetup(class, virtFunSetupPack) \
    Cbject_VirtFunSetup_x0(class, Cbject_Utils_unpack(virtFunSetupPack))

#endif // CBJECT_VIRTFUNSETUP_H
