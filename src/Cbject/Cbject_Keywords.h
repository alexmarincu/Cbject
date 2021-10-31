#ifndef CBJECT_KEYWORDS_H
#define CBJECT_KEYWORDS_H
#include "Cbject_AbstractClass.h"
#include "Cbject_AbstractClassSetup.h"
#include "Cbject_BindFuns.h"
#include "Cbject_Class.h"
#include "Cbject_ClassSetup.h"
#include "Cbject_Const.h"
#include "Cbject_DefaultGetProp.h"
#include "Cbject_DefaultSetProp.h"
#include "Cbject_Enum.h"
#include "Cbject_Fun.h"
#include "Cbject_Funs.h"
#include "Cbject_GetProp.h"
#include "Cbject_Init.h"
#include "Cbject_OverrideFun.h"
#include "Cbject_PoolSize.h"
#include "Cbject_SetProp.h"
#include "Cbject_Singleton.h"
#include "Cbject_Struct.h"
#include "Cbject_Terminate.h"
#include "Cbject_VirtFun.h"

#define AbstractClass(params, data, virtFuns) \
    Cbject_AbstractClass(Type, Parent, params, data, virtFuns)

#define AbstractClassSetup(virtFunCalls, bindFuns) \
    Cbject_AbstractClassSetup(Type, Parent, virtFunCalls, bindFuns)

#define BindFuns(...) \
    (, __VA_ARGS__)

#define Class(params, data, virtFuns) \
    Cbject_Class(Type, Parent, params, data, virtFuns)

#define ClassSetup(virtFunCalls, bindFuns) \
    Cbject_ClassSetup(Type, Parent, virtFunCalls, bindFuns)

#define Const(constType, constNameAndValue) \
    Cbject_Const(Type, constType, constNameAndValue)

#define Struct(...) \
    Cbject_Struct(Type, __VA_ARGS__)

#define Enum(...) \
    Cbject_Enum(Type, __VA_ARGS__)

#define Fun(returnType, funName, params) \
    Cbject_Fun(Type, returnType, funName, Cbject_Utils_stripParentheses(params))

#define Singleton(data) \
    Cbject_Singleton(Type, Parent, data)

#define SingletonSetup(bindFuns) \
    Cbject_Singleton_Setup(Type, Parent, bindFuns)

#define OverrideFun(returnType, funName, params) \
    Cbject_OverrideFun(Type, returnType, funName, Cbject_Utils_stripParentheses(params))

#define Params(...) \
    (, __VA_ARGS__)

#define PoolSize(poolSize) \
    Cbject_PoolSize(Type, poolSize)

#define Data(...) \
    (, __VA_ARGS__)

#define VirtFun(returnType, funName, params, callParams) \
    Cbject_VirtFun(Type, returnType, funName, params, callParams)

#define VirtFunCalls(...) \
    (, __VA_ARGS__)

#define VirtFuns(...) \
    (, __VA_ARGS__)

#define SetProp(fieldType, fieldName) \
    Cbject_SetProp(Type, fieldType, fieldName)

#define GetProp(fieldType, fieldName) \
    Cbject_GetProp(Type, fieldType, fieldName)

#define DefaultSetProp(fieldType, fieldName) \
    Cbject_DefaultSetProp(Type, fieldType, fieldName)

#define DefaultGetProp(fieldType, fieldName) \
    Cbject_DefaultGetProp(Type, fieldType, fieldName)

#define Init \
    Cbject_Init(Type, Parent)

#define Terminate \
    Cbject_Terminate(Type, Parent)

#endif // CBJECT_KEYWORDS_H
