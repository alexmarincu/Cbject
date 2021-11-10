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

#define AbstractClass(superClass, params, data, virtFuns, funs) \
    Cbject_AbstractClass(Type, superClass, params, data, virtFuns, funs)

#define AbstractClassSetup(superClass, virtFunSetup, funOverrideSetup) \
    Cbject_AbstractClass_Setup(Type, superClass, virtFunSetup, funOverrideSetup)

#define FunOverrideSetup(...) \
    (FunOverrideSetup, __VA_ARGS__)

#define Class(superClass, params, data, virtFuns, funs) \
    Cbject_Class(Type, superClass, params, data, virtFuns, funs)

#define ClassSetup(superClass, virtFunSetup, funOverrideSetup) \
    Cbject_Class_Setup(Type, superClass, virtFunSetup, funOverrideSetup)

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

#define Singleton(superClass, data, funs) \
    Cbject_Singleton(Type, superClass, data, funs)

#define SingletonSetup(superClass, funOverrideSetup) \
    Cbject_Singleton_Setup(Type, superClass, funOverrideSetup)

#define FunOverride(funReturnType, funName, funParams) \
    Cbject_FunOverride_Prototype(Type, funReturnType, funName, funParams)

#define Extends(superClass) \
    (Extends, superClass)

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
    Cbject_InitFun_OnInitFunPrototype(Type)

#define Terminate \
    Cbject_TerminateFun_OnTerminateFunPrototype(Type)

#endif // CBJECT_KEYWORDS_H
