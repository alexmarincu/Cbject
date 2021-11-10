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
#define Cbject_AbstractClass_caseX(className, superClass, params, data, virtFuns, funs) \
    Cbject_ClassTypeInfoStruct_Decl(className);                                         \
    Cbject_ClassStruct_Decl(className);                                                 \
    Cbject_ClassParamsStruct(className, params);                                        \
    Cbject_ClassDataStruct(className, data);                                            \
    Cbject_ClassVirtFunsStruct(className, virtFuns);                                    \
    Cbject_ClassTypeInfoContainerStruct(className, superClass, withVirtFuns);           \
    Cbject_ClassContainerStruct(className, superClass);                                 \
    Cbject_InitFun_Prototype(className);                                                \
    Cbject_TerminateFun_Prototype(className);                                           \
    Cbject_ClassTypeInfoInstanceFun_Prototype(className);                               \
    Cbject_FunDecls(virtFuns);                                                          \
    Cbject_FunDecls(funs);                                                              \
    Cbject_AccessorFunDecls(data);                                                      \
    Cbject_CastFun_Prototype(className);                                                \
    Cbject_ClassVirtFunsGetter_Prototype(className)

#define Cbject_AbstractClass_caseNA(className, superClass, params, data, virtFuns, funs) \
    Cbject_AbstractClass_caseX(className, Object, params, data, virtFuns, funs)

#define Cbject_AbstractClass_caseExtends(className, superClass, params, data, virtFuns, funs) \
    Cbject_AbstractClass_caseX(className, superClass, params, data, virtFuns, funs)

#define Cbject_AbstractClass_x1(className, params, data, virtFuns, funs, extendsCase, ...) \
    Cbject_AbstractClass_case##extendsCase(className, __VA_ARGS__, params, data, virtFuns, funs)

#define Cbject_AbstractClass_x0(className, params, data, virtFuns, funs, ...) \
    Cbject_AbstractClass_x1(className, params, data, virtFuns, funs, __VA_ARGS__)

#define Cbject_AbstractClass(className, extendsPack, params, data, virtFuns, funs) \
    Cbject_AbstractClass_x0(className, params, data, virtFuns, funs, Cbject_Utils_unpack(extendsPack))

/*
Cbject_AbstractClass_Setup
*/
#define Cbject_AbstractClass_Setup_caseX(className, superClass, virtFunSetup, funOverrideSetup) \
    Cbject_ClassTypeInfoStruct_Def(className, superClass, withVirtFuns);                        \
    Cbject_ClassStruct_Def(className, superClass);                                              \
    Cbject_SizeImpl(className);                                                                 \
    Cbject_ClassTypeInfoInstanceFun_Impl(className, superClass, funOverrideSetup);              \
    Cbject_CastFun_Impl(className);                                                             \
    Cbject_ClassVirtFunsGetter_Impl(className);                                                 \
    Cbject_VirtFunSetup(virtFunSetup);                                                          \
    Cbject_InitFun_Impl(className, superClass);                                                 \
    Cbject_TerminateFun_Impl(className, superClass)

#define Cbject_AbstractClass_Setup_caseNA(className, superClass, virtFunSetup, funOverrideSetup) \
    Cbject_AbstractClass_Setup_caseX(className, Object, virtFunSetup, funOverrideSetup)

#define Cbject_AbstractClass_Setup_caseExtends(className, superClass, virtFunSetup, funOverrideSetup) \
    Cbject_AbstractClass_Setup_caseX(className, superClass, virtFunSetup, funOverrideSetup)

#define Cbject_AbstractClass_Setup_x1(className, virtFunSetup, funOverrideSetup, extendsCase, ...) \
    Cbject_AbstractClass_Setup_case##extendsCase(className, __VA_ARGS__, virtFunSetup, funOverrideSetup)

#define Cbject_AbstractClass_Setup_x0(className, virtFunSetup, funOverrideSetup, ...) \
    Cbject_AbstractClass_Setup_x1(className, virtFunSetup, funOverrideSetup, __VA_ARGS__)

#define Cbject_AbstractClass_Setup(className, extendsPack, virtFunSetup, funOverrideSetup) \
    Cbject_AbstractClass_Setup_x0(className, virtFunSetup, funOverrideSetup, Cbject_Utils_unpack(extendsPack))

#endif // CBJECT_ABSTRACTCLASS_H
