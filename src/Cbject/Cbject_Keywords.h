#ifndef CBJECT_KEYWORDS_H
#define CBJECT_KEYWORDS_H
#include "Cbject_AbstractClass.h"
#include "Cbject_AbstractClassSetup.h"
#include "Cbject_BindSuperFun.h"
#include "Cbject_Class.h"
#include "Cbject_ClassSetup.h"
#include "Cbject_Const.h"
#include "Cbject_Consts.h"
#include "Cbject_DataClass.h"
#include "Cbject_DefaultGetProp.h"
#include "Cbject_DefaultGetProps.h"
#include "Cbject_DefaultSetProp.h"
#include "Cbject_DefaultSetProps.h"
#include "Cbject_EnumClass.h"
#include "Cbject_Fun.h"
#include "Cbject_Funs.h"
#include "Cbject_GetProp.h"
#include "Cbject_GetProps.h"
#include "Cbject_Init.h"
#include "Cbject_Object.h"
#include "Cbject_ObjectSetup.h"
#include "Cbject_PoolSize.h"
#include "Cbject_PrivateConst.h"
#include "Cbject_PrivateConsts.h"
#include "Cbject_PrivateFuns.h"
#include "Cbject_PublicConst.h"
#include "Cbject_PublicConsts.h"
#include "Cbject_SetProp.h"
#include "Cbject_SetProps.h"
#include "Cbject_SuperFun.h"
#include "Cbject_SuperFuns.h"
#include "Cbject_Terminate.h"
#include "Cbject_VirtFun.h"

#define AbstractClass(params, props, virtFuns) \
    Cbject_AbstractClass(Type, Parent, params, props, virtFuns)

#define AbstractClassSetup(virtFunCalls, bindSuperFuns) \
    Cbject_AbstractClassSetup(Type, Parent, virtFunCalls, bindSuperFuns)

#define BindSuperFuns(...) \
    (__VA_ARGS__)

#define Class(params, props, virtFuns) \
    Cbject_Class(Type, Parent, params, props, virtFuns)

#define ClassSetup(virtFunCalls, bindSuperFuns) \
    Cbject_ClassSetup(Type, Parent, virtFunCalls, bindSuperFuns)

#define Const(constType, constNameAndValue) \
    Cbject_Const(Type, constType, constNameAndValue)

#define Consts(...) \
    Cbject_Consts(__VA_ARGS__)

#define DataClass(...) \
    Cbject_DataClass(Type, __VA_ARGS__)

#define EnumClass(...) \
    Cbject_EnumClass(Type, __VA_ARGS__)

#define Fun(returnType, funName, args) \
    Cbject_Fun(Type, returnType, funName, Cbject_Utils_stripParentheses(args))

#define Funs(...) \
    Cbject_Funs(__VA_ARGS__)

#define Object(props) \
    Cbject_Object(Type, Parent, props)

#define ObjectSetup(bindSuperFuns) \
    Cbject_ObjectSetup(Type, Parent, bindSuperFuns)

#define SuperFun(returnType, funName, args) \
    Cbject_SuperFun(Type, returnType, funName, Cbject_Utils_stripParentheses(args))

#define SuperFuns(...) \
    Cbject_SuperFuns(__VA_ARGS__)

#define Params(...) \
    (__VA_ARGS__)

#define PoolSize(poolSize) \
    Cbject_PoolSize(Type, poolSize)

#define PrivateConst(constType, constNameAndValue) \
    Cbject_PrivateConst(Type, constType, constNameAndValue)

#define PrivateConsts(...) \
    Cbject_PrivateConsts(__VA_ARGS__)

#define PrivateFun(returnType, funName, args) \
    static Fun(returnType, funName, args)

#define PrivateFuns(...) \
    Cbject_PrivateFuns(__VA_ARGS__)

#define Props(...) \
    (__VA_ARGS__)

#define PublicConst(constType, constName) \
    Cbject_PublicConst(Type, constType, constName)

#define PublicConsts(...) \
    Cbject_PublicConsts(__VA_ARGS__)

#define VirtFun(returnType, funName, args, params) \
    Cbject_VirtFun(Type, returnType, funName, args, params)

#define VirtFunCalls(...) \
    (__VA_ARGS__)

#define VirtFuns(...) \
    (__VA_ARGS__)

#define SetProp(propType, propName) \
    Cbject_SetProp(Type, propType, propName)

#define GetProp(propType, propName) \
    Cbject_GetProp(Type, propType, propName)

#define SetProps(...) \
    Cbject_SetProps(__VA_ARGS__)

#define GetProps(...) \
    Cbject_GetProps(__VA_ARGS__)

#define DefaultSetProp(propType, propName) \
    Cbject_DefaultSetProp(Type, propType, propName)

#define DefaultGetProp(propType, propName) \
    Cbject_DefaultGetProp(Type, propType, propName)

#define DefaultSetProps(...) \
    Cbject_DefaultSetProps(__VA_ARGS__)

#define DefaultGetProps(...) \
    Cbject_DefaultGetProps(__VA_ARGS__)

#define Init \
    Cbject_Init(Type, Parent)

#define Terminate \
    Cbject_Terminate(Type, Parent)

#endif // CBJECT_KEYWORDS_H
