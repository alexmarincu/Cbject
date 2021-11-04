#ifndef CBJECT_KEYWORDS_H
#define CBJECT_KEYWORDS_H
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

#define Singleton(data) \
    Cbject_KeywordExpander_Singleton(Type, Parent, data)

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

#define VirtFunDeclPure(...) \
    (Pure, (__VA_ARGS__))

#define VirtFunDecl(...) \
    (Implemented, (__VA_ARGS__))

#define Funs(...) \
    (funs, __VA_ARGS__)

#define Final Final
#define Override Override
#define Pure Pure
#define Implemented Implemented

#define FunDecl(...) \
    (Final, (__VA_ARGS__))

#define FunDeclOverride(...) \
    (Override, (__VA_ARGS__))

#define SetProp(fieldType, fieldName) \
    Cbject_KeywordExpander_SetProp(Type, fieldType, fieldName)

#define GetProp(fieldType, fieldName) \
    Cbject_KeywordExpander_GetProp(Type, fieldType, fieldName)

#define DefaultSetProp(fieldType, fieldName) \
    Cbject_KeywordExpander_DefaultSetProp(Type, fieldType, fieldName)

#define DefaultGetProp(fieldType, fieldName) \
    Cbject_KeywordExpander_DefaultGetProp(Type, fieldType, fieldName)

#define Init \
    Cbject_KeywordExpander_Init(Type, Parent)

#define Terminate \
    Cbject_KeywordExpander_Terminate(Type, Parent)

#endif // CBJECT_KEYWORDS_H
