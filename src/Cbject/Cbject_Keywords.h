#ifndef CBJECT_KEYWORDS_H
#define CBJECT_KEYWORDS_H
#include "Cbject_AbstractClass.h"
#include "Cbject_AccessorFun.h"
#include "Cbject_BindFuns.h"
#include "Cbject_Class.h"
#include "Cbject_Const.h"
#include "Cbject_Enum.h"
#include "Cbject_FunDecls.h"
#include "Cbject_FunPrototype.h"
#include "Cbject_Init.h"
#include "Cbject_OverrideFunPrototype.h"
#include "Cbject_PoolSize.h"
#include "Cbject_Singleton.h"
#include "Cbject_Struct.h"
#include "Cbject_Terminate.h"
#include "Cbject_VirtFun.h"

#define AbstractClass(params, data, virtFuns, funs) \
    Cbject_AbstractClass(Type, Parent, params, data, virtFuns, funs)

#define AbstractClassSetup(virtFunCalls, bindFuns) \
    Cbject_AbstractClass_Setup(Type, Parent, virtFunCalls, bindFuns)

#define BindFuns(...) \
    (bindFuns, __VA_ARGS__)

#define Class(params, data, virtFuns, funs) \
    Cbject_Class(Type, Parent, params, data, virtFuns, funs)

#define ClassSetup(virtFunCalls, bindFuns) \
    Cbject_Class_Setup(Type, Parent, virtFunCalls, bindFuns)

#define Const(constType, constNameAndValue) \
    Cbject_Const(Type, constType, constNameAndValue)

#define Struct(...) \
    Cbject_Struct(Type, __VA_ARGS__)

#define Enum(...) \
    Cbject_Enum(Type, __VA_ARGS__)

#define Fun(funReturnType, funName, funParams) \
    Cbject_FunPrototype(Type, funReturnType, funName, funParams)

#define Singleton(data, funs) \
    Cbject_Singleton(Type, Parent, data, funs)

#define SingletonSetup(bindFuns) \
    Cbject_Singleton_Setup(Type, Parent, bindFuns)

#define OverrideFun(funReturnType, funName, funParams) \
    Cbject_OverrideFunPrototype(Type, funReturnType, funName, funParams)

#define Params(...) \
    (params, __VA_ARGS__)

#define PoolSize(poolSize) \
    Cbject_PoolSize(Type, poolSize)

#define Data(...) \
    (data, __VA_ARGS__)

#define VirtFun(funReturnType, funName, funParams, funCallParams) \
    Cbject_VirtFun(Type, funReturnType, funName, funParams, funCallParams)

#define VirtFunCalls(...) \
    (virtFunCalls, __VA_ARGS__)

#define VirtFuns(...) \
    (virtFuns, __VA_ARGS__)

#define VirtFunDecl(...) \
    (VirtFunType_Implemented, (__VA_ARGS__))

#define Funs(...) \
    (funs, __VA_ARGS__)

#define FunType_Final FunType_Final
#define FunType_Override FunType_Override
#define VirtFunType_Pure VirtFunType_Pure
#define VirtFunType_Implemented VirtFunType_Implemented
#define Access_None Access_None
#define Access_ReadWrite Access_ReadWrite
#define Access_Read Access_Read
#define Access_Write Access_Write

#define SetterCustom(fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Prototype(Type, fieldType, fieldName)

#define GetterCustom(fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Prototype(Type, fieldType, fieldName)

#define Setter(fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Impl(Type, fieldType, fieldName)

#define Getter(fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Impl(Type, fieldType, fieldName)

#define Init \
    Cbject_Init(Type, Parent)

#define Terminate \
    Cbject_Terminate(Type, Parent)

#endif // CBJECT_KEYWORDS_H
