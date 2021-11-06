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

#define Cbject_Singleton(className, superClassName, data, funs) \
    Cbject_ClassTypeInfoStruct_Decl(className);                 \
    Cbject_ClassStruct_Decl(className);                         \
    Cbject_ClassParamsStruct(className, ());                    \
    Cbject_ClassDataStruct(className, data);                    \
    Cbject_ClassContainerStruct(className, superClassName);     \
    Cbject_InitFun_Prototype(className);                        \
    Cbject_TerminateFun_Prototype(className);                   \
    Cbject_SingletonInstanceFun_Prototype(className);           \
    Cbject_FunDecls(funs);                                      \
    Cbject_AccessorFunDecls(data)

#define Cbject_Singleton_Setup(className, superClassName, bindFuns)             \
    Cbject_ClassTypeInfoStruct_Def(className, superClassName, withoutVirtFuns); \
    Cbject_ClassStruct_Def(className, superClassName);                          \
    Cbject_ClassTypeInfoInstanceFun_Prototype(className);                       \
    Cbject_SingletonInstanceFun_Impl(className);                                \
    Cbject_SizeImpl(className);                                                 \
    Cbject_ClassTypeInfoInstanceFun_Impl(className, superClassName, bindFuns)
#endif // CBJECT_SINGLETON_H
