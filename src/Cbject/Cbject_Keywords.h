#ifndef CBJECT_KEYWORDS_H
#define CBJECT_KEYWORDS_H
#include "Cbject_AccessorFun.h"
#include "Cbject_KeywordExpander.h"

#define AbstractClass(params, data, virtFuns, funs) \
    Cbject_KeywordExpander_AbstractClass(Type, Parent, params, data, virtFuns, funs)

#define AbstractClassSetup(virtFunCalls, bindFuns) \
    Cbject_KeywordExpander_AbstractClassSetup(Type, Parent, virtFunCalls, bindFuns)

#define BindFuns(...) \
    (bindFuns, __VA_ARGS__)

#define Class(params, data, virtFuns, funs) \
    Cbject_KeywordExpander_Class(Type, Parent, params, data, virtFuns, funs)

#define ClassSetup(virtFunCalls, bindFuns) \
    Cbject_KeywordExpander_ClassSetup(Type, Parent, virtFunCalls, bindFuns)

#define Const(constType, constNameAndValue) \
    Cbject_KeywordExpander_Const(Type, constType, constNameAndValue)

#define Struct(...) \
    Cbject_KeywordExpander_Struct(Type, __VA_ARGS__)

#define Enum(...) \
    Cbject_KeywordExpander_Enum(Type, __VA_ARGS__)

#define Fun(funReturnType, funName, funParams) \
    Cbject_KeywordExpander_Fun(Type, funReturnType, funName, funParams)

#define Singleton(data, funs) \
    Cbject_KeywordExpander_Singleton(Type, Parent, data, funs)

#define SingletonSetup(bindFuns) \
    Cbject_KeywordExpander_SingletonSetup(Type, Parent, bindFuns)

#define OverrideFun(funReturnType, funName, funParams) \
    Cbject_KeywordExpander_OverrideFun(Type, funReturnType, funName, funParams)

#define Params(...) \
    (params, __VA_ARGS__)

#define PoolSize(poolSize) \
    Cbject_KeywordExpander_PoolSize(Type, poolSize)

#define Data(...) \
    (data, __VA_ARGS__)

#define VirtFun(funReturnType, funName, funParams, funCallParams) \
    Cbject_KeywordExpander_VirtFun(Type, funReturnType, funName, funParams, funCallParams)

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
    Cbject_KeywordExpander_Init(Type, Parent)

#define Terminate \
    Cbject_KeywordExpander_Terminate(Type, Parent)

#endif // CBJECT_KEYWORDS_H
