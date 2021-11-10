#ifndef CBJECT_ABSTRACTCLASS_H
#define CBJECT_ABSTRACTCLASS_H
#include "Cbject_AccessorFunDecls.h"
#include "Cbject_CastFun.h"
#include "Cbject_ClassContainerStruct.h"
#include "Cbject_ClassDataStruct.h"
#include "Cbject_ClassParamsStruct.h"
#include "Cbject_ClassStruct.h"
#include "Cbject_ClassTypeInfoContainerStruct.h"
#include "Cbject_ClassTypeInfoInstanceFun.h"
#include "Cbject_ClassTypeInfoStruct.h"
#include "Cbject_ClassVirtFunsGetter.h"
#include "Cbject_ClassVirtFunsStruct.h"
#include "Cbject_FunDecls.h"
#include "Cbject_InitFun.h"
#include "Cbject_SizeImpl.h"
#include "Cbject_TerminateFun.h"
#include "Cbject_Utils.h"
#include "Cbject_VirtFunSetup.h"

/*
Cbject_AbstractClass
*/
#define Cbject_AbstractClass_caseX(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack) \
    Cbject_ClassTypeInfoStruct_Decl(class);                                                         \
    Cbject_ClassStruct_Decl(class);                                                                 \
    Cbject_ClassParamsStruct(class, paramsPack);                                                    \
    Cbject_ClassDataStruct(class, dataPack);                                                        \
    Cbject_ClassVirtFunsStruct(class, virtFunsPack);                                                \
    Cbject_ClassTypeInfoContainerStruct(class, superClass, virtFunsPack);                           \
    Cbject_ClassContainerStruct(class, superClass);                                                 \
    Cbject_InitFun_Prototype(class);                                                                \
    Cbject_TerminateFun_Prototype(class);                                                           \
    Cbject_ClassTypeInfoInstanceFun_Prototype(class);                                               \
    Cbject_FunDecls(virtFunsPack);                                                                  \
    Cbject_FunDecls(funsPack);                                                                      \
    Cbject_AccessorFunDecls(dataPack);                                                              \
    Cbject_CastFun_Prototype(class)

#define Cbject_AbstractClass_caseNA(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack) \
    Cbject_AbstractClass_caseX(class, Object, paramsPack, dataPack, virtFunsPack, funsPack)

#define Cbject_AbstractClass_caseExtends(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack) \
    Cbject_AbstractClass_caseX(class, superClass, paramsPack, dataPack, virtFunsPack, funsPack)

#define Cbject_AbstractClass_x1(class, paramsPack, dataPack, virtFunsPack, funsPack, extendsCase, ...) \
    Cbject_AbstractClass_case##extendsCase(class, __VA_ARGS__, paramsPack, dataPack, virtFunsPack, funsPack)

#define Cbject_AbstractClass_x0(class, paramsPack, dataPack, virtFunsPack, funsPack, ...) \
    Cbject_AbstractClass_x1(class, paramsPack, dataPack, virtFunsPack, funsPack, __VA_ARGS__)

#define Cbject_AbstractClass(class, extendsPack, paramsPack, dataPack, virtFunsPack, funsPack) \
    Cbject_AbstractClass_x0(class, paramsPack, dataPack, virtFunsPack, funsPack, Cbject_Utils_unpack(extendsPack))

/*
Cbject_AbstractClass_Setup
*/
#define Cbject_AbstractClass_Setup_caseX(class, superClass, virtFunSetupPack, funOverrideSetupPack) \
    Cbject_ClassTypeInfoStruct_Def(class, superClass, virtFunSetupPack);                            \
    Cbject_ClassStruct_Def(class, superClass);                                                      \
    Cbject_SizeImpl(class);                                                                         \
    Cbject_ClassTypeInfoInstanceFun_Impl(class, superClass, funOverrideSetupPack);                  \
    Cbject_CastFun_Impl(class);                                                                     \
    Cbject_VirtFunSetup(class, virtFunSetupPack);                                                   \
    Cbject_InitFun_Impl(class, superClass);                                                         \
    Cbject_TerminateFun_Impl(class, superClass)

#define Cbject_AbstractClass_Setup_caseNA(class, superClass, virtFunSetupPack, funOverrideSetupPack) \
    Cbject_AbstractClass_Setup_caseX(class, Object, virtFunSetupPack, funOverrideSetupPack)

#define Cbject_AbstractClass_Setup_caseExtends(class, superClass, virtFunSetupPack, funOverrideSetupPack) \
    Cbject_AbstractClass_Setup_caseX(class, superClass, virtFunSetupPack, funOverrideSetupPack)

#define Cbject_AbstractClass_Setup_x1(class, virtFunSetupPack, funOverrideSetupPack, extendsCase, ...) \
    Cbject_AbstractClass_Setup_case##extendsCase(class, __VA_ARGS__, virtFunSetupPack, funOverrideSetupPack)

#define Cbject_AbstractClass_Setup_x0(class, virtFunSetupPack, funOverrideSetupPack, ...) \
    Cbject_AbstractClass_Setup_x1(class, virtFunSetupPack, funOverrideSetupPack, __VA_ARGS__)

#define Cbject_AbstractClass_Setup(class, extendsPack, virtFunSetupPack, funOverrideSetupPack) \
    Cbject_AbstractClass_Setup_x0(class, virtFunSetupPack, funOverrideSetupPack, Cbject_Utils_unpack(extendsPack))

#endif // CBJECT_ABSTRACTCLASS_H
