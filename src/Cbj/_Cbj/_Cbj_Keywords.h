#ifndef _CBJ_KEYWORDS_H
#define _CBJ_KEYWORDS_H
#include "_Cbj_AbstractClass.h"
#include "_Cbj_AbstractClassSetup.h"
#include "_Cbj_BindFun.h"
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
#include "_Cbj_OverrideFun.h"
#include "_Cbj_OverrideFuns.h"
#include "_Cbj_PoolSize.h"
#include "_Cbj_PrivateConst.h"
#include "_Cbj_PrivateConsts.h"
#include "_Cbj_PrivateFuns.h"
#include "_Cbj_PublicConst.h"
#include "_Cbj_PublicConsts.h"
#include "_Cbj_Set.h"
#include "_Cbj_Setters.h"
#include "_Cbj_Terminate.h"
#include "_Cbj_VirtFun.h"

#define AbstractClass(params, props, virtFuns) \
    _Cbj_AbstractClass(Cbj_Type, Cbj_Parent, params, props, virtFuns)

#define AbstractClassSetup(virtFunCalls, bindFuns) \
    _Cbj_AbstractClassSetup(Cbj_Type, Cbj_Parent, virtFunCalls, bindFuns)

#define BindFuns(...) \
    (__VA_ARGS__)

#define Class(params, props, virtFuns) \
    _Cbj_Class(Cbj_Type, Cbj_Parent, params, props, virtFuns)

#define ClassSetup(virtFunCalls, bindFuns) \
    _Cbj_ClassSetup(Cbj_Type, Cbj_Parent, virtFunCalls, bindFuns)

#define Const(type, constNameAndValue) \
    _Cbj_Const(Cbj_Type, type, constNameAndValue)

#define Consts(...) \
    _Cbj_Consts(__VA_ARGS__)

#define DataClass(...) \
    _Cbj_DataClass(Cbj_Type, __VA_ARGS__)

#define EnumClass(...) \
    _Cbj_EnumClass(Cbj_Type, __VA_ARGS__)

#define Fun(returnType, funName, args) \
    _Cbj_Fun(Cbj_Type, returnType, funName, _Cbj_Utils_stripParentheses(args))

#define Funs(...) \
    _Cbj_Funs(__VA_ARGS__)

#define Object(props) \
    _Cbj_Object(Cbj_Type, Cbj_Parent, props)

#define ObjectSetup(bindFuns) \
    _Cbj_ObjectSetup(Cbj_Type, Cbj_Parent, bindFuns)

#define OverrideFun(returnType, funName, args) \
    _Cbj_OverrideFun(Cbj_Type, returnType, funName, _Cbj_Utils_stripParentheses(args))

#define OverrideFuns(...) \
    _Cbj_OverrideFuns(__VA_ARGS__)

#define Params(...) \
    (__VA_ARGS__)

#define PoolSize(poolSize) \
    _Cbj_PoolSize(Cbj_Type, poolSize)

#define PrivateConst(type, constNameAndValue) \
    _Cbj_PrivateConst(Cbj_Type, type, constNameAndValue)

#define PrivateConsts(...) \
    _Cbj_PrivateConsts(__VA_ARGS__)

#define PrivateFun(returnType, funName, args) \
    static Fun(returnType, funName, args)

#define PrivateFuns(...) \
    _Cbj_PrivateFuns(__VA_ARGS__)

#define Props(...) \
    (__VA_ARGS__)

#define PublicConst(type, constName) \
    _Cbj_PublicConst(Cbj_Type, type, constName)

#define PublicConsts(...) \
    _Cbj_PublicConsts(__VA_ARGS__)

#define VirtFun(returnType, funName, args, params) \
    _Cbj_VirtFun(Cbj_Type, returnType, funName, args, params)

#define VirtFunCalls(...) \
    (__VA_ARGS__)

#define VirtFuns(...) \
    (__VA_ARGS__)

#define NewOnStack(typeName, varName, ...) \
    _Cbj_NewOnStack(typeName, varName, __VA_ARGS__)

#define Set(type, propName) \
    _Cbj_Set(Cbj_Type, type, propName)

#define Get(type, propName) \
    _Cbj_Get(Cbj_Type, type, propName)

#define Setters(...) \
    _Cbj_Setters(__VA_ARGS__)

#define Getters(...) \
    _Cbj_Getters(__VA_ARGS__)

#define DefaultSet(type, propName) \
    _Cbj_DefaultSet(Cbj_Type, type, propName)

#define DefaultGet(type, propName) \
    _Cbj_DefaultGet(Cbj_Type, type, propName)

#define DefaultSetters(...) \
    _Cbj_DefaultSetters(__VA_ARGS__)

#define DefaultGetters(...) \
    _Cbj_DefaultGetters(__VA_ARGS__)

#define Init \
    _Cbj_Init(Cbj_Type, Cbj_Parent)

#define Terminate \
    _Cbj_Terminate(Cbj_Type, Cbj_Parent)

#define BindVirtFuns(...) \
    _Cbj_Utils_forEach(BindVirtFun, __VA_ARGS__)

#define BindFun(type, Cbj_ParentName, funName, args) \
    _Cbj_BindFun(Cbj_Type, type, Cbj_ParentName, funName, args)

#endif // _CBJ_KEYWORDS_H
