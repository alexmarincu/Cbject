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
#define Cbject_AbstractClass(className, superClassName, params, data, virtFuns, funs) \
    Cbject_ClassTypeInfoStruct_Decl(className);                                       \
    Cbject_ClassStruct_Decl(className);                                               \
    Cbject_ClassParamsStruct(className, params);                                      \
    Cbject_ClassDataStruct(className, data);                                          \
    Cbject_ClassVirtFunsStruct(className, virtFuns);                                  \
    Cbject_ClassTypeInfoContainerStruct(className, superClassName, withVirtFuns);     \
    Cbject_ClassContainerStruct(className, superClassName);                           \
    Cbject_InitFun_Prototype(className);                                              \
    Cbject_TerminateFun_Prototype(className);                                         \
    Cbject_ClassTypeInfoInstanceFun_Prototype(className);                             \
    Cbject_FunDecls(virtFuns);                                                        \
    Cbject_FunDecls(funs);                                                            \
    Cbject_AccessorFunDecls(data);                                                    \
    Cbject_CastFun_Prototype(className);                                              \
    Cbject_ClassVirtFunsGetter_Prototype(className)

/*
Cbject_AbstractClass_Setup
*/
#define Cbject_AbstractClass_Setup(className, superClassName, virtFunSetup, funOverrideSetup) \
    Cbject_ClassTypeInfoStruct_Def(className, superClassName, withVirtFuns);                  \
    Cbject_ClassStruct_Def(className, superClassName);                                        \
    Cbject_SizeImpl(className);                                                               \
    Cbject_ClassTypeInfoInstanceFun_Impl(className, superClassName, funOverrideSetup);        \
    Cbject_CastFun_Impl(className);                                                           \
    Cbject_ClassVirtFunsGetter_Impl(className);                                               \
    Cbject_VirtFunSetup(virtFunSetup);                                                        \
    Cbject_InitFun_Impl(className, superClassName);                                           \
    Cbject_TerminateFun_Impl(className, superClassName)

#endif // CBJECT_ABSTRACTCLASS_H
