#ifndef CBJECT_SINGLETON_H
#define CBJECT_SINGLETON_H
#include "Cbject_AccessorFunDecls.h"
#include "Cbject_ClassContainerStruct.h"
#include "Cbject_ClassDataStruct.h"
#include "Cbject_ClassParamsStruct.h"
#include "Cbject_ClassStruct.h"
#include "Cbject_ClassTypeInfoInstanceFun.h"
#include "Cbject_ClassTypeInfoStruct.h"
#include "Cbject_FunDecls.h"
#include "Cbject_InitFun.h"
#include "Cbject_SingletonInstanceFun.h"
#include "Cbject_SizeImpl.h"
#include "Cbject_TerminateFun.h"
#include "Cbject_Utils.h"

/*
Cbject_Singleton
*/
#define Cbject_Singleton_caseX(className, superClass, data, funs) \
    Cbject_ClassTypeInfoStruct_Decl(className);                   \
    Cbject_ClassStruct_Decl(className);                           \
    Cbject_ClassParamsStruct(className, NA);                      \
    Cbject_ClassDataStruct(className, data);                      \
    Cbject_ClassContainerStruct(className, superClass);           \
    Cbject_InitFun_Prototype(className);                          \
    Cbject_TerminateFun_Prototype(className);                     \
    Cbject_SingletonInstanceFun_Prototype(className);             \
    Cbject_FunDecls(funs);                                        \
    Cbject_AccessorFunDecls(data)

#define Cbject_Singleton_caseNA(className, superClass, data, funs) \
    Cbject_Singleton_caseX(className, Object, data, funs)

#define Cbject_Singleton_caseExtends(className, superClass, data, funs) \
    Cbject_Singleton_caseX(className, superClass, data, funs)

#define Cbject_Singleton_x1(className, data, funs, extendsCase, ...) \
    Cbject_Singleton_case##extendsCase(className, __VA_ARGS__, data, funs)

#define Cbject_Singleton_x0(className, data, funs, ...) \
    Cbject_Singleton_x1(className, data, funs, __VA_ARGS__)

#define Cbject_Singleton(className, extendsPack, data, funs) \
    Cbject_Singleton_x0(className, data, funs, Cbject_Utils_unpack(extendsPack))

/*
Cbject_Singleton_Setup
*/
#define Cbject_Singleton_Setup_caseX(className, superClass, funOverrideSetup)      \
    Cbject_ClassTypeInfoStruct_Def(className, superClass, withoutVirtFuns);        \
    Cbject_ClassStruct_Def(className, superClass);                                 \
    Cbject_ClassTypeInfoInstanceFun_Prototype(className);                          \
    Cbject_SingletonInstanceFun_Impl(className);                                   \
    Cbject_SizeImpl(className);                                                    \
    Cbject_ClassTypeInfoInstanceFun_Impl(className, superClass, funOverrideSetup); \
    Cbject_InitFun_Impl(className, superClass);                                    \
    Cbject_TerminateFun_Impl(className, superClass)

#define Cbject_Singleton_Setup_caseNA(className, superClass, funOverrideSetup) \
    Cbject_Singleton_Setup_caseX(className, Object, funOverrideSetup)

#define Cbject_Singleton_Setup_caseExtends(className, superClass, funOverrideSetup) \
    Cbject_Singleton_Setup_caseX(className, superClass, funOverrideSetup)

#define Cbject_Singleton_Setup_x1(className, funOverrideSetup, extendsCase, ...) \
    Cbject_Singleton_Setup_case##extendsCase(className, __VA_ARGS__, funOverrideSetup)

#define Cbject_Singleton_Setup_x0(className, funOverrideSetup, ...) \
    Cbject_Singleton_Setup_x1(className, funOverrideSetup, __VA_ARGS__)

#define Cbject_Singleton_Setup(className, extendsPack, funOverrideSetup) \
    Cbject_Singleton_Setup_x0(className, funOverrideSetup, Cbject_Utils_unpack(extendsPack))

#endif // CBJECT_SINGLETON_H
