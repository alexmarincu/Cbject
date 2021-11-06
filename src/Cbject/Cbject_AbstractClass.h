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
#include "Cbject_VirtFunCalls.h"

#define Cbject_AbstractClass(typeName, superTypeName, params, data, virtFuns, funs) \
    Cbject_ClassTypeInfoStruct_Decl(typeName);                                      \
    Cbject_ClassStruct_Decl(typeName);                                              \
    Cbject_ClassParamsStruct(typeName, params);                                     \
    Cbject_ClassDataStruct(typeName, data);                                         \
    Cbject_ClassVirtFunsStruct(typeName, virtFuns);                                 \
    Cbject_ClassTypeInfoContainerStruct(typeName, superTypeName, withVirtFuns);     \
    Cbject_ClassContainerStruct(typeName, superTypeName);                           \
    Cbject_InitFun_Prototype(typeName);                                             \
    Cbject_TerminateFun_Prototype(typeName);                                        \
    Cbject_ClassTypeInfoInstanceFun_Prototype(typeName);                            \
    Cbject_FunDecls(virtFuns);                                                      \
    Cbject_FunDecls(funs);                                                          \
    Cbject_AccessorFunDecls(data);                                                  \
    Cbject_CastFun_Prototype(typeName);                                             \
    Cbject_ClassVirtFunsGetter_Prototype(typeName)

#define Cbject_AbstractClass_Setup(typeName, superTypeName, virtFunCalls, bindFuns) \
    Cbject_ClassTypeInfoStruct_Def(typeName, superTypeName, withVirtFuns);          \
    Cbject_ClassStruct_Def(typeName, superTypeName);                                \
    Cbject_SizeImpl(typeName);                                                      \
    Cbject_ClassTypeInfoInstanceFun_Impl(typeName, superTypeName, bindFuns);        \
    Cbject_CastFun_Impl(typeName);                                                  \
    Cbject_ClassVirtFunsGetter_Impl(typeName);                                      \
    Cbject_VirtFunCalls(virtFunCalls)

#endif // CBJECT_ABSTRACTCLASS_H
