#ifndef CBJECT_KEYWORDS_H
#define CBJECT_KEYWORDS_H
#include "Cbject_AbstractClass.h"
#include "Cbject_AccessorFun.h"
#include "Cbject_Class.h"
#include "Cbject_Const.h"
#include "Cbject_Enum.h"
#include "Cbject_FunDecls.h"
#include "Cbject_FunOverride.h"
#include "Cbject_FunPrototype.h"
#include "Cbject_InitFun.h"
#include "Cbject_PoolSize.h"
#include "Cbject_Singleton.h"
#include "Cbject_Struct.h"
#include "Cbject_TerminateFun.h"
#include "Cbject_Var.h"

#define AbstractClass(params, data, virtFuns, funs) \
    Cbject_AbstractClass(Type, Parent, params, data, virtFuns, funs)

#define AbstractClassSetup(virtFunSetup, funOverrideSetup) \
    Cbject_AbstractClass_Setup(Type, Parent, virtFunSetup, funOverrideSetup)

#define FunOverrideSetup(...) \
    (FunOverrideSetup, __VA_ARGS__)

#define Class(params, data, virtFuns, funs) \
    Cbject_Class(Type, Parent, params, data, virtFuns, funs)

#define ClassSetup(virtFunSetup, funOverrideSetup) \
    Cbject_Class_Setup(Type, Parent, virtFunSetup, funOverrideSetup)

#define Const(constType, constName) \
    Cbject_Const(Type, constType, constName)

#define Var(varType, varName) \
    Cbject_Var(Type, varType, varName)

#define Struct(...) \
    Cbject_Struct(Type, __VA_ARGS__)

#define Enum(...) \
    Cbject_Enum(Type, __VA_ARGS__)

#define Fun(funReturnType, funName, funParams) \
    Cbject_FunPrototype(Type, funReturnType, funName, funParams)

#define Singleton(data, funs) \
    Cbject_Singleton(Type, Parent, data, funs)

#define SingletonSetup(funOverrideSetup) \
    Cbject_Singleton_Setup(Type, Parent, funOverrideSetup)

#define FunOverride(funReturnType, funName, funParams) \
    Cbject_FunOverride_Prototype(Type, funReturnType, funName, funParams)

#define Params(...) \
    (Params, __VA_ARGS__)

#define PoolSize(poolSize) \
    Cbject_PoolSize(Type, poolSize)

#define Data(...) \
    (Data, __VA_ARGS__)

#define VirtFunSetup(...) \
    (VirtFunSetup, __VA_ARGS__)

#define VirtFuns(...) \
    (VirtFuns, __VA_ARGS__)

#define Funs(...) \
    (Funs, __VA_ARGS__)

#define NA \
    (NA)

#define Final Final
#define Override Override
#define Pure Pure
#define Impl Impl
#define Private Private
#define Public Public
#define PublicRead PublicRead
#define PublicWrite PublicWrite

#define Set(fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Prototype(Type, fieldType, fieldName)

#define Get(fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Prototype(Type, fieldType, fieldName)

#define SetImpl(fieldType, fieldName) \
    Cbject_AccessorFun_Setter_Impl(Type, fieldType, fieldName)

#define GetImpl(fieldType, fieldName) \
    Cbject_AccessorFun_Getter_Impl(Type, fieldType, fieldName)

#define Init \
    Cbject_InitFun_Impl(Type, Parent)

#define Terminate \
    Cbject_TerminateFun_Impl(Type, Parent)

#endif // CBJECT_KEYWORDS_H
