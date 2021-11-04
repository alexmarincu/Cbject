#ifndef CBJECT_KEYWORDEXPANDER_H
#define CBJECT_KEYWORDEXPANDER_H
#include "Cbject_AbstractClass.h"
#include "Cbject_BindFuns.h"
#include "Cbject_Class.h"
#include "Cbject_Const.h"
#include "Cbject_DefaultGetProp.h"
#include "Cbject_DefaultSetProp.h"
#include "Cbject_Enum.h"
#include "Cbject_FunDecls.h"
#include "Cbject_FunPrototype.h"
#include "Cbject_GetProp.h"
#include "Cbject_Init.h"
#include "Cbject_OverrideFunPrototype.h"
#include "Cbject_PoolSize.h"
#include "Cbject_SetProp.h"
#include "Cbject_Singleton.h"
#include "Cbject_Struct.h"
#include "Cbject_Terminate.h"
#include "Cbject_VirtFun.h"

#define Cbject_KeywordExpander_AbstractClass(type, parent, params, data, virtFuns, funs) \
    Cbject_AbstractClass(type, parent, params, data, virtFuns, funs)

#define Cbject_KeywordExpander_AbstractClassSetup(type, parent, virtFunCalls, bindFuns) \
    Cbject_AbstractClass_Setup(type, parent, virtFunCalls, bindFuns)

#define Cbject_KeywordExpander_Class(type, parent, params, data, virtFuns, funs) \
    Cbject_Class(type, parent, params, data, virtFuns, funs)

#define Cbject_KeywordExpander_ClassSetup(type, parent, virtFunCalls, bindFuns) \
    Cbject_Class_Setup(type, parent, virtFunCalls, bindFuns)

#define Cbject_KeywordExpander_Const(type, constType, constNameAndValue) \
    Cbject_Const(type, constType, constNameAndValue)

#define Cbject_KeywordExpander_Struct(type, ...) \
    Cbject_Struct(type, __VA_ARGS__)

#define Cbject_KeywordExpander_Enum(type, ...) \
    Cbject_Enum(type, __VA_ARGS__)

#define Cbject_KeywordExpander_Fun(type, returnType, funName, params) \
    Cbject_FunPrototype(type, returnType, funName, params)

#define Cbject_KeywordExpander_Singleton(type, parent, data) \
    Cbject_Singleton(type, parent, data)

#define Cbject_KeywordExpander_SingletonSetup(type, parent, bindFuns) \
    Cbject_Singleton_Setup(type, parent, bindFuns)

#define Cbject_KeywordExpander_OverrideFun(type, returnType, funName, params) \
    Cbject_OverrideFunPrototype(type, returnType, funName, params)

#define Cbject_KeywordExpander_PoolSize(type, poolSize) \
    Cbject_PoolSize(type, poolSize)

#define Cbject_KeywordExpander_VirtFun(type, returnType, funName, params, callParams) \
    Cbject_VirtFun(type, returnType, funName, params, callParams)

#define Cbject_KeywordExpander_SetProp(type, fieldType, fieldName) \
    Cbject_SetProp(type, fieldType, fieldName)

#define Cbject_KeywordExpander_GetProp(type, fieldType, fieldName) \
    Cbject_GetProp(type, fieldType, fieldName)

#define Cbject_KeywordExpander_DefaultSetProp(type, fieldType, fieldName) \
    Cbject_DefaultSetProp(type, fieldType, fieldName)

#define Cbject_KeywordExpander_DefaultGetProp(type, fieldType, fieldName) \
    Cbject_DefaultGetProp(type, fieldType, fieldName)

#define Cbject_KeywordExpander_Init(type, parent) \
    Cbject_Init(type, parent)

#define Cbject_KeywordExpander_Terminate(type, parent) \
    Cbject_Terminate(type, parent)

#endif // CBJECT_KEYWORDEXPANDER_H
