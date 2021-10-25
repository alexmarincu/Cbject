#ifndef CBJECT_KEYWORDS_H
#define CBJECT_KEYWORDS_H
#include "Cbject_AbstractClass.h"
#include "Cbject_AbstractClassSetup.h"
#include "Cbject_BindSuperFun.h"
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
#include "Cbject_Object.h"
#include "Cbject_ObjectSetup.h"
#include "Cbject_PoolSize.h"
#include "Cbject_SetProp.h"
#include "Cbject_Struct.h"
#include "Cbject_SuperFun.h"
#include "Cbject_Terminate.h"
#include "Cbject_VirtFun.h"

#define AbstractClass(params, data, virtFuns) \
    Cbject_AbstractClass(Type, Parent, params, data, virtFuns)

#define AbstractClassSetup(virtFunCalls, bindSuperFuns) \
    Cbject_AbstractClassSetup(Type, Parent, virtFunCalls, bindSuperFuns)

#define BindSuperFuns(...) \
    (__VA_ARGS__)

#define Class(params, data, virtFuns) \
    Cbject_Class(Type, Parent, params, data, virtFuns)

#define ClassSetup(virtFunCalls, bindSuperFuns) \
    Cbject_ClassSetup(Type, Parent, virtFunCalls, bindSuperFuns)

#define Const(constType, constNameAndValue) \
    Cbject_Const(Type, constType, constNameAndValue)

#define Struct(...) \
    Cbject_Struct(Type, __VA_ARGS__)

#define Enum(...) \
    Cbject_Enum(Type, __VA_ARGS__)

#define Fun(returnType, funName, params) \
    Cbject_Fun(Type, returnType, funName, Cbject_Utils_stripParentheses(params))

#define Object(data) \
    Cbject_Object(Type, Parent, data)

#define ObjectSetup(bindSuperFuns) \
    Cbject_ObjectSetup(Type, Parent, bindSuperFuns)

#define SuperFun(returnType, funName, params) \
    Cbject_SuperFun(Type, returnType, funName, Cbject_Utils_stripParentheses(params))

#define Params(...) \
    (__VA_ARGS__)

#define PoolSize(poolSize) \
    Cbject_PoolSize(Type, poolSize)

#define Data(...) \
    (__VA_ARGS__)

#define VirtFun(returnType, funName, params, callParams) \
    Cbject_VirtFun(Type, returnType, funName, params, callParams)

#define VirtFunCalls(...) \
    (__VA_ARGS__)

#define VirtFuns(...) \
    (__VA_ARGS__)

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
