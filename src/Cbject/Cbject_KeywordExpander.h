#ifndef CBJECT_KEYWORDEXPANDER_H
#define CBJECT_KEYWORDEXPANDER_H
#include "Cbject_AbstractClass.h"
#include "Cbject_BindFuns.h"
#include "Cbject_Class.h"
#include "Cbject_Const.h"
#include "Cbject_Enum.h"
#include "Cbject_FunDecls.h"
#include "Cbject_FunPrototype.h"
#include "Cbject_Init.h"
#include "Cbject_OverrideFunPrototype.h"
#include "Cbject_PoolSize.h"
#include "Cbject_Singleton.h"
#include "Cbject_Struct.h"
#include "Cbject_Terminate.h"
#include "Cbject_VirtFun.h"

#define Cbject_KeywordExpander_AbstractClass(type, superTypeName, params, data, virtFuns, funs) \
    Cbject_AbstractClass(type, superTypeName, params, data, virtFuns, funs)

#define Cbject_KeywordExpander_AbstractClassSetup(type, superTypeName, virtFunCalls, bindFuns) \
    Cbject_AbstractClass_Setup(type, superTypeName, virtFunCalls, bindFuns)

#define Cbject_KeywordExpander_Class(type, superTypeName, params, data, virtFuns, funs) \
    Cbject_Class(type, superTypeName, params, data, virtFuns, funs)

#define Cbject_KeywordExpander_ClassSetup(type, superTypeName, virtFunCalls, bindFuns) \
    Cbject_Class_Setup(type, superTypeName, virtFunCalls, bindFuns)

#define Cbject_KeywordExpander_Const(type, constType, constNameAndValue) \
    Cbject_Const(type, constType, constNameAndValue)

#define Cbject_KeywordExpander_Struct(type, ...) \
    Cbject_Struct(type, __VA_ARGS__)

#define Cbject_KeywordExpander_Enum(type, ...) \
    Cbject_Enum(type, __VA_ARGS__)

#define Cbject_KeywordExpander_Fun(type, funReturnType, funName, funParams) \
    Cbject_FunPrototype(type, funReturnType, funName, funParams)

#define Cbject_KeywordExpander_Singleton(type, superTypeName, data, funs) \
    Cbject_Singleton(type, superTypeName, data, funs)

#define Cbject_KeywordExpander_SingletonSetup(type, superTypeName, bindFuns) \
    Cbject_Singleton_Setup(type, superTypeName, bindFuns)

#define Cbject_KeywordExpander_OverrideFun(type, funReturnType, funName, funParams) \
    Cbject_OverrideFunPrototype(type, funReturnType, funName, funParams)

#define Cbject_KeywordExpander_PoolSize(type, poolSize) \
    Cbject_PoolSize(type, poolSize)

#define Cbject_KeywordExpander_VirtFun(type, funReturnType, funName, funParams, funCallParams) \
    Cbject_VirtFun(type, funReturnType, funName, funParams, funCallParams)

#define Cbject_KeywordExpander_Init(type, superTypeName) \
    Cbject_Init(type, superTypeName)

#define Cbject_KeywordExpander_Terminate(type, superTypeName) \
    Cbject_Terminate(type, superTypeName)

#endif // CBJECT_KEYWORDEXPANDER_H
