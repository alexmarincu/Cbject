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
#include "Cbject_ObjectSetupFun.h"
#include "Cbject_ObjectTeardownFun.h"
#include "Cbject_SingletonInstanceFun.h"
#include "Cbject_Utils.h"

/*
Cbject_Singleton
*/
#define Cbject_Singleton_caseX(class, superClass, dataPack, funsPack) \
    Cbject_ClassTypeInfoStruct_Decl(class);                           \
    Cbject_ClassStruct_Decl(class);                                   \
    Cbject_ClassParamsStruct(class, NA);                              \
    Cbject_ClassDataStruct(class, dataPack);                          \
    Cbject_ClassContainerStruct(class, superClass);                   \
    Cbject_ObjectSetupFun_InitFunPrototype(class);                    \
    Cbject_ObjectTeardownFun_TerminateFunPrototype(class);            \
    Cbject_SingletonInstanceFun_Prototype(class);                     \
    Cbject_FunDecls(funsPack);                                        \
    Cbject_AccessorFunDecls(dataPack)

#define Cbject_Singleton_caseNA(class, superClass, dataPack, funsPack) \
    Cbject_Singleton_caseX(class, Object, dataPack, funsPack)

#define Cbject_Singleton_caseExtends(class, superClass, dataPack, funsPack) \
    Cbject_Singleton_caseX(class, superClass, dataPack, funsPack)

#define Cbject_Singleton_x1(class, dataPack, funsPack, extendsCase, ...) \
    Cbject_Singleton_case##extendsCase(class, __VA_ARGS__, dataPack, funsPack)

#define Cbject_Singleton_x0(class, dataPack, funsPack, ...) \
    Cbject_Singleton_x1(class, dataPack, funsPack, __VA_ARGS__)

#define Cbject_Singleton(class, extendsPack, dataPack, funsPack) \
    Cbject_Singleton_x0(class, dataPack, funsPack, Cbject_Utils_unpack(extendsPack))

/*
Cbject_Singleton_Setup
*/
#define Cbject_Singleton_Setup_caseX(class, superClass, funOverrideSetupPack)      \
    Cbject_ClassTypeInfoStruct_Def_caseNA(class, superClass);                      \
    Cbject_ClassStruct_Def(class, superClass);                                     \
    Cbject_ClassTypeInfoInstanceFun_Prototype(class);                              \
    Cbject_ClassTypeInfoInstanceFun_Impl(class, superClass, funOverrideSetupPack); \
    Cbject_ObjectSetupFun_Impl(class, superClass);                                 \
    Cbject_ObjectTeardownFun_Impl(class, superClass);                              \
    Cbject_SingletonInstanceFun_Impl(class)

#define Cbject_Singleton_Setup_caseNA(class, superClass, funOverrideSetupPack) \
    Cbject_Singleton_Setup_caseX(class, Object, funOverrideSetupPack)

#define Cbject_Singleton_Setup_caseExtends(class, superClass, funOverrideSetupPack) \
    Cbject_Singleton_Setup_caseX(class, superClass, funOverrideSetupPack)

#define Cbject_Singleton_Setup_x1(class, funOverrideSetupPack, extendsCase, ...) \
    Cbject_Singleton_Setup_case##extendsCase(class, __VA_ARGS__, funOverrideSetupPack)

#define Cbject_Singleton_Setup_x0(class, funOverrideSetupPack, ...) \
    Cbject_Singleton_Setup_x1(class, funOverrideSetupPack, __VA_ARGS__)

#define Cbject_Singleton_Setup(class, extendsPack, funOverrideSetupPack) \
    Cbject_Singleton_Setup_x0(class, funOverrideSetupPack, Cbject_Utils_unpack(extendsPack))

#endif // CBJECT_SINGLETON_H
