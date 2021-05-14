#ifndef _CBJ_KEYWORDS_H
#define _CBJ_KEYWORDS_H
#include "_Cbj_AbstractClass.h"
#include "_Cbj_AbstractClassSetup.h"
#include "_Cbj_BindSuperFun.h"
#include "_Cbj_Class.h"
#include "_Cbj_ClassSetup.h"
#include "_Cbj_Const.h"
#include "_Cbj_Consts.h"
#include "_Cbj_DataClass.h"
#include "_Cbj_DefaultGet.h"
#include "_Cbj_DefaultGetters.h"
#include "_Cbj_DefaultSet.h"
#include "_Cbj_DefaultSetters.h"
#include "_Cbj_EnumClass.h"
#include "_Cbj_Fun.h"
#include "_Cbj_Funs.h"
#include "_Cbj_Get.h"
#include "_Cbj_Getters.h"
#include "_Cbj_Init.h"
#include "_Cbj_NewOnStack.h"
#include "_Cbj_Object.h"
#include "_Cbj_ObjectSetup.h"
#include "_Cbj_PoolSize.h"
#include "_Cbj_PrivateConst.h"
#include "_Cbj_PrivateConsts.h"
#include "_Cbj_PrivateFuns.h"
#include "_Cbj_PublicConst.h"
#include "_Cbj_PublicConsts.h"
#include "_Cbj_Set.h"
#include "_Cbj_Setters.h"
#include "_Cbj_SuperFun.h"
#include "_Cbj_SuperFuns.h"
#include "_Cbj_Terminate.h"
#include "_Cbj_VirtFun.h"

#define AbstractClass(mParams, mProps, mVirtFuns) \
    _Cbj_AbstractClass(Type, Parent, mParams, mProps, mVirtFuns)

#define AbstractClassSetup(mVirtFunCalls, mBindSuperFuns) \
    _Cbj_AbstractClassSetup(Type, Parent, mVirtFunCalls, mBindSuperFuns)

#define BindSuperFuns(...) \
    (__VA_ARGS__)

#define Class(mParams, mProps, mVirtFuns) \
    _Cbj_Class(Type, Parent, mParams, mProps, mVirtFuns)

#define ClassSetup(mVirtFunCalls, mBindSuperFuns) \
    _Cbj_ClassSetup(Type, Parent, mVirtFunCalls, mBindSuperFuns)

#define Const(constType, constNameAndValue) \
    _Cbj_Const(Type, constType, constNameAndValue)

#define Consts(...) \
    _Cbj_Consts(__VA_ARGS__)

#define DataClass(...) \
    _Cbj_DataClass(Type, __VA_ARGS__)

#define EnumClass(...) \
    _Cbj_EnumClass(Type, __VA_ARGS__)

#define Fun(mReturnType, mFunName, mArgs) \
    _Cbj_Fun(Type, mReturnType, mFunName, _Cbj_Utils_stripParentheses(mArgs))

#define Funs(...) \
    _Cbj_Funs(__VA_ARGS__)

#define Object(mProps) \
    _Cbj_Object(Type, Parent, mProps)

#define ObjectSetup(mBindSuperFuns) \
    _Cbj_ObjectSetup(Type, Parent, mBindSuperFuns)

#define SuperFun(mReturnType, mFunName, mArgs) \
    _Cbj_SuperFun(Type, mReturnType, mFunName, _Cbj_Utils_stripParentheses(mArgs))

#define SuperFuns(...) \
    _Cbj_SuperFuns(__VA_ARGS__)

#define Params(...) \
    (__VA_ARGS__)

#define PoolSize(poolSize) \
    _Cbj_PoolSize(Type, poolSize)

#define PrivateConst(constType, constNameAndValue) \
    _Cbj_PrivateConst(Type, constType, constNameAndValue)

#define PrivateConsts(...) \
    _Cbj_PrivateConsts(__VA_ARGS__)

#define PrivateFun(mReturnType, mFunName, mArgs) \
    static Fun(mReturnType, mFunName, mArgs)

#define PrivateFuns(...) \
    _Cbj_PrivateFuns(__VA_ARGS__)

#define Props(...) \
    (__VA_ARGS__)

#define PublicConst(constType, constName) \
    _Cbj_PublicConst(Type, constType, constName)

#define PublicConsts(...) \
    _Cbj_PublicConsts(__VA_ARGS__)

#define VirtFun(mReturnType, mFunName, mArgs, mParams) \
    _Cbj_VirtFun(Type, mReturnType, mFunName, mArgs, mParams)

#define VirtFunCalls(...) \
    (__VA_ARGS__)

#define VirtFuns(...) \
    (__VA_ARGS__)

#define NewOnStack(m_cbjType, varName, ...) \
    _Cbj_NewOnStack(m_cbjType, varName, __VA_ARGS__)

#define Set(propType, propName) \
    _Cbj_Set(Type, propType, propName)

#define Get(propType, propName) \
    _Cbj_Get(Type, propType, propName)

#define Setters(...) \
    _Cbj_Setters(__VA_ARGS__)

#define Getters(...) \
    _Cbj_Getters(__VA_ARGS__)

#define DefaultSet(propType, propName) \
    _Cbj_DefaultSet(Type, propType, propName)

#define DefaultGet(propType, propName) \
    _Cbj_DefaultGet(Type, propType, propName)

#define DefaultSetters(...) \
    _Cbj_DefaultSetters(__VA_ARGS__)

#define DefaultGetters(...) \
    _Cbj_DefaultGetters(__VA_ARGS__)

#define Init \
    _Cbj_Init(Type, Parent)

#define Terminate \
    _Cbj_Terminate(Type, Parent)

#endif // _CBJ_KEYWORDS_H
