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
#include "___Cbj_DefaultGet.h"
#include "___Cbj_DefaultGetters.h"
#include "___Cbj_DefaultSet.h"
#include "___Cbj_DefaultSetters.h"
#include "___Cbj_EnumClass.h"
#include "___Cbj_Fun.h"
#include "___Cbj_Funs.h"
#include "___Cbj_Get.h"
#include "___Cbj_Getters.h"
#include "___Cbj_Init.h"
#include "___Cbj_NewOnStack.h"
#include "___Cbj_Object.h"
#include "___Cbj_ObjectSetup.h"
#include "___Cbj_PoolSize.h"
#include "___Cbj_PrivateConst.h"
#include "___Cbj_PrivateConsts.h"
#include "___Cbj_PrivateFuns.h"
#include "___Cbj_PublicConst.h"
#include "___Cbj_PublicConsts.h"
#include "___Cbj_Set.h"
#include "___Cbj_Setters.h"
#include "___Cbj_SuperFun.h"
#include "___Cbj_SuperFuns.h"
#include "___Cbj_Terminate.h"
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

#define NewOnStack(cbjType, varName, ...) \
    ___Cbj_NewOnStack(cbjType, varName, __VA_ARGS__)

#define Set(propType, propName) \
    ___Cbj_Set(Type, propType, propName)

#define Get(propType, propName) \
    ___Cbj_Get(Type, propType, propName)

#define Setters(...) \
    ___Cbj_Setters(__VA_ARGS__)

#define Getters(...) \
    ___Cbj_Getters(__VA_ARGS__)

#define DefaultSet(propType, propName) \
    ___Cbj_DefaultSet(Type, propType, propName)

#define DefaultGet(propType, propName) \
    ___Cbj_DefaultGet(Type, propType, propName)

#define DefaultSetters(...) \
    ___Cbj_DefaultSetters(__VA_ARGS__)

#define DefaultGetters(...) \
    ___Cbj_DefaultGetters(__VA_ARGS__)

#define Init \
    ___Cbj_Init(Type, Parent)

#define Terminate \
    ___Cbj_Terminate(Type, Parent)

#endif // _CBJ_KEYWORDS_H
