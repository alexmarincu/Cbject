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

#define Cbject_Singleton(typeName, superTypeName, data, funs) \
    Cbject_ClassTypeInfoStruct_Decl(typeName);                \
    Cbject_ClassStruct_Decl(typeName);                        \
    Cbject_ClassParamsStruct(typeName, ());                   \
    Cbject_ClassDataStruct(typeName, data);                   \
    Cbject_ClassContainerStruct(typeName, superTypeName);     \
    Cbject_InitFun_Prototype(typeName);                       \
    Cbject_TerminateFun_Prototype(typeName);                  \
    Cbject_SingletonInstanceFun_Prototype(typeName);          \
    Cbject_FunDecls(funs);                                    \
    Cbject_AccessorFunDecls(data)

#define Cbject_Singleton_Setup(typeName, superTypeName, bindFuns)             \
    Cbject_ClassTypeInfoStruct_Def(typeName, superTypeName, withoutVirtFuns); \
    Cbject_ClassStruct_Def(typeName, superTypeName);                          \
    Cbject_ClassTypeInfoInstanceFun_Prototype(typeName);                      \
    Cbject_SingletonInstanceFun_Impl(typeName);                               \
    Cbject_SizeImpl(typeName);                                                \
    Cbject_ClassTypeInfoInstanceFun_Impl(typeName, superTypeName, bindFuns)
#endif // CBJECT_SINGLETON_H
