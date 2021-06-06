#ifndef _CBJ_KEYWORDS_H
#define _CBJ_KEYWORDS_H
#include "___Cbj_AbstractClass.h"
#include "___Cbj_AbstractClassSetup.h"
#include "___Cbj_BindSuperFun.h"
#include "___Cbj_Class.h"
#include "___Cbj_ClassSetup.h"
#include "___Cbj_Const.h"
#include "___Cbj_Consts.h"
#include "___Cbj_DataClass.h"
#include "___Cbj_DefaultGetProp.h"
#include "___Cbj_DefaultGetProps.h"
#include "___Cbj_DefaultSetProp.h"
#include "___Cbj_DefaultSetProps.h"
#include "___Cbj_EnumClass.h"
#include "___Cbj_Fun.h"
#include "___Cbj_Funs.h"
#include "___Cbj_Get.h"
#include "___Cbj_GetProp.h"
#include "___Cbj_GetProps.h"
#include "___Cbj_Init.h"
#include "___Cbj_New.h"
#include "___Cbj_NewOnStack.h"
#include "___Cbj_Object.h"
#include "___Cbj_ObjectSetup.h"
#include "___Cbj_PoolSize.h"
#include "___Cbj_PrivateConst.h"
#include "___Cbj_PrivateConsts.h"
#include "___Cbj_PrivateFuns.h"
#include "___Cbj_PublicConst.h"
#include "___Cbj_PublicConsts.h"
#include "___Cbj_SetProp.h"
#include "___Cbj_SetProps.h"
#include "___Cbj_SuperFun.h"
#include "___Cbj_SuperFuns.h"
#include "___Cbj_VirtFun.h"

#define AbstractClass(params, props, virtFuns) \
    ___Cbj_AbstractClass(Type, Parent, params, props, virtFuns)

#define AbstractClassSetup(virtFunCalls, bindSuperFuns) \
    ___Cbj_AbstractClassSetup(Type, Parent, virtFunCalls, bindSuperFuns)

#define BindSuperFuns(...) \
    (__VA_ARGS__)

#define Class(params, props, virtFuns) \
    ___Cbj_Class(Type, Parent, params, props, virtFuns)

#define ClassSetup(virtFunCalls, bindSuperFuns) \
    ___Cbj_ClassSetup(Type, Parent, virtFunCalls, bindSuperFuns)

#define Const(constType, constNameAndValue) \
    ___Cbj_Const(Type, constType, constNameAndValue)

#define Consts(...) \
    ___Cbj_Consts(__VA_ARGS__)

#define DataClass(...) \
    ___Cbj_DataClass(Type, __VA_ARGS__)

#define EnumClass(...) \
    ___Cbj_EnumClass(Type, __VA_ARGS__)

#define Fun(returnType, funName, args) \
    ___Cbj_Fun(Type, returnType, funName, ___Cbj_Utils_stripParentheses(args))

#define Funs(...) \
    ___Cbj_Funs(__VA_ARGS__)

#define Object(props) \
    ___Cbj_Object(Type, Parent, props)

#define ObjectSetup(bindSuperFuns) \
    ___Cbj_ObjectSetup(Type, Parent, bindSuperFuns)

#define SuperFun(returnType, funName, args) \
    ___Cbj_SuperFun(Type, returnType, funName, ___Cbj_Utils_stripParentheses(args))

#define SuperFuns(...) \
    ___Cbj_SuperFuns(__VA_ARGS__)

#define Params(...) \
    (__VA_ARGS__)

#define PoolSize(poolSize) \
    ___Cbj_PoolSize(Type, poolSize)

#define PrivateConst(constType, constNameAndValue) \
    ___Cbj_PrivateConst(Type, constType, constNameAndValue)

#define PrivateConsts(...) \
    ___Cbj_PrivateConsts(__VA_ARGS__)

#define PrivateFun(returnType, funName, args) \
    static Fun(returnType, funName, args)

#define PrivateFuns(...) \
    ___Cbj_PrivateFuns(__VA_ARGS__)

#define Props(...) \
    (__VA_ARGS__)

#define PublicConst(constType, constName) \
    ___Cbj_PublicConst(Type, constType, constName)

#define PublicConsts(...) \
    ___Cbj_PublicConsts(__VA_ARGS__)

#define VirtFun(returnType, funName, args, params) \
    ___Cbj_VirtFun(Type, returnType, funName, args, params)

#define VirtFunCalls(...) \
    (__VA_ARGS__)

#define VirtFuns(...) \
    (__VA_ARGS__)

#define NewOnStack(cbjType, ...) \
    ___Cbj_NewOnStack(cbjType, __VA_ARGS__)

#define New(cbjType, ...) \
    ___Cbj_New(cbjType, __VA_ARGS__)

#define Get(cbjType, ...) \
    ___Cbj_Get(cbjType, __VA_ARGS__)

#define SetProp(propType, propName) \
    ___Cbj_SetProp(Type, propType, propName)

#define GetProp(propType, propName) \
    ___Cbj_GetProp(Type, propType, propName)

#define SetProps(...) \
    ___Cbj_SetProps(__VA_ARGS__)

#define GetProps(...) \
    ___Cbj_GetProps(__VA_ARGS__)

#define DefaultSetProp(propType, propName) \
    ___Cbj_DefaultSetProp(Type, propType, propName)

#define DefaultGetProp(propType, propName) \
    ___Cbj_DefaultGetProp(Type, propType, propName)

#define DefaultSetProps(...) \
    ___Cbj_DefaultSetProps(__VA_ARGS__)

#define DefaultGetProps(...) \
    ___Cbj_DefaultGetProps(__VA_ARGS__)

#define Init \
    ___Cbj_Init(Type, Parent)

#endif // _CBJ_KEYWORDS_H
