#ifndef _CBJECTKEYWORDS_H
#define _CBJECTKEYWORDS_H
#include "../CbjectPreprocessor.h"
#include "_CbjectAbstractClass.h"
#include "_CbjectAbstractClassSetup.h"
#include "_CbjectBindFun.h"
#include "_CbjectClass.h"
#include "_CbjectClassSetup.h"
#include "_CbjectDataClass.h"
#include "_CbjectDefaultGet.h"
#include "_CbjectDefaultGetters.h"
#include "_CbjectDefaultSet.h"
#include "_CbjectDefaultSetters.h"
#include "_CbjectEnumClass.h"
#include "_CbjectFun.h"
#include "_CbjectFuns.h"
#include "_CbjectGet.h"
#include "_CbjectGetters.h"
#include "_CbjectInit.h"
#include "_CbjectNewOnStack.h"
#include "_CbjectObject.h"
#include "_CbjectObjectSetup.h"
#include "_CbjectOverrideFun.h"
#include "_CbjectOverrideFuns.h"
#include "_CbjectPoolSize.h"
#include "_CbjectPrivateFuns.h"
#include "_CbjectSet.h"
#include "_CbjectSetters.h"
#include "_CbjectTerminate.h"
#include "_CbjectVirtualFun.h"

#define Class(params, props, virtualFuns) \
    _CbjectClass(CbjectType, parent, params, props, virtualFuns)

#define ClassSetup(virtualFunCalls, bindFuns) \
    _CbjectClassSetup(CbjectType, parent, virtualFunCalls, bindFuns)

#define AbstractClass(params, props, virtualFuns) \
    _CbjectAbstractClass(CbjectType, parent, params, props, virtualFuns)

#define AbstractClassSetup(virtualFunCalls, bindFuns) \
    _CbjectAbstractClassSetup(CbjectType, parent, virtualFunCalls, bindFuns)

#define Object(props) \
    _CbjectObject(CbjectType, parent, props)

#define ObjectSetup(bindFuns) \
    _CbjectObjectSetup(CbjectType, parent, bindFuns)

#define Params(...) \
    (__VA_ARGS__)

#define Props(...) \
    (__VA_ARGS__)

#define VirtualFuns(...) \
    (__VA_ARGS__)

#define VirtualFunCalls(...) \
    (__VA_ARGS__)

#define BindFuns(...) \
    (__VA_ARGS__)

#define PoolSize(poolSize) \
    _CbjectPoolSize(CbjectType, poolSize)

#define Const(type, ...) CbjectPreprocessor_c(CbjectType, type, __VA_ARGS__)
#define Consts(...) _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyConst, __VA_ARGS__)
#define PublicConst(type, constName) CbjectPreprocessor_pbc(CbjectType, type, constName)
#define PublicConsts(...) _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPublicConst, __VA_ARGS__)
#define PrivateConst(type, ...) CbjectPreprocessor_pc(CbjectType, type, __VA_ARGS__)
#define PrivateConsts(cbjectTypeName, ...) \
    _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateConst, __VA_ARGS__)

#define DataClass(...) \
    _CbjectDataClass(CbjectType, __VA_ARGS__)

#define EnumClass(...) \
    _CbjectEnumClass(CbjectType, __VA_ARGS__)

#define Fun(returnType, funName, args) \
    _CbjectFun(CbjectType, returnType, funName, _CbjectUtilities_stripParentheses(args))

#define Funs(...) \
    _CbjectFuns(__VA_ARGS__)

#define PrivateFun(returnType, funName, args) \
    static Fun(returnType, funName, args)

#define PrivateFuns(...) \
    _CbjectPrivateFuns(__VA_ARGS__)

#define VirtualFun(returnType, funName, args, params) \
    _CbjectVirtualFun(CbjectType, returnType, funName, args, params)

#define OverrideFun(returnType, funName, args) \
    _CbjectOverrideFun(CbjectType, returnType, funName, _CbjectUtilities_stripParentheses(args))

#define OverrideFuns(...) \
    _CbjectOverrideFuns(__VA_ARGS__)

#define NewOnStack(cbjectTypeName, varName, ...) \
    _CbjectNewOnStack(cbjectTypeName, varName, __VA_ARGS__)

#define Set(type, memberName) \
    _CbjectSet(CbjectType, type, memberName)

#define Get(type, memberName) \
    _CbjectGet(CbjectType, type, memberName)

#define Setters(...) \
    _CbjectSetters(__VA_ARGS__)

#define Getters(...) \
    _CbjectGetters(__VA_ARGS__)

#define DefaultSet(type, memberName) \
    _CbjectDefaultSet(CbjectType, type, memberName)

#define DefaultGet(type, memberName) \
    _CbjectDefaultGet(CbjectType, type, memberName)

#define DefaultSetters(...) \
    _CbjectDefaultSetters(__VA_ARGS__)

#define DefaultGetters(...) \
    _CbjectDefaultGetters(__VA_ARGS__)

#define Init \
    _CbjectInit(CbjectType, parent)

#define Terminate \
    _CbjectTerminate(CbjectType, parent)

#define BindVirtualFuns(...) \
    _CbjectUtilities_forEach(BindVirtualFun, __VA_ARGS__)

#define BindFun(type, parentName, funName, args) \
    _CbjectBindFun(CbjectType, type, parentName, funName, args)

#endif // _CBJECTKEYWORDS_H
