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
#include "Cbject_ObjectSetupFun.h"
#include "Cbject_ObjectTeardownFun.h"
#include "Cbject_PoolSizeDef.h"
#include "Cbject_Singleton.h"
#include "Cbject_Struct.h"
#include "Cbject_Var.h"

#define AbstractClass(superClass, paramsPack, dataPack, virtFunsPack, funsPack) \
    Cbject_AbstractClass(Type, superClass, paramsPack, dataPack, virtFunsPack, funsPack)

#define AbstractClassSetup(superClass, virtFunSetup, funOverrideSetupPack) \
    Cbject_AbstractClass_Setup(Type, superClass, virtFunSetup, funOverrideSetupPack)

#define FunOverrideSetup(...) \
    (FunOverrideSetup, __VA_ARGS__)

#define Class(superClass, paramsPack, dataPack, virtFunsPack, funsPack) \
    Cbject_Class(Type, superClass, paramsPack, dataPack, virtFunsPack, funsPack)

#define ClassSetup(superClass, virtFunSetup, funOverrideSetupPack) \
    Cbject_Class_Setup(Type, superClass, virtFunSetup, funOverrideSetupPack)

#define Const(constType, constName) \
    Cbject_Const(Type, constType, constName)

#define Var(varType, varName) \
    Cbject_Var(Type, varType, varName)

#define Struct(...) \
    Cbject_Struct(Type, __VA_ARGS__)

#define Enum(...) \
    Cbject_Enum(Type, __VA_ARGS__)

#define Fun(funReturnType, funName, funParamsPack) \
    Cbject_FunPrototype(Type, funReturnType, funName, funParamsPack)

#define Singleton(superClass, dataPack, funsPack) \
    Cbject_Singleton(Type, superClass, dataPack, funsPack)

#define SingletonSetup(superClass, funOverrideSetupPack) \
    Cbject_Singleton_Setup(Type, superClass, funOverrideSetupPack)

#define FunOverride(funReturnType, funName, funParamsPack) \
    Cbject_FunOverride_Prototype(Type, funReturnType, funName, funParamsPack)

#define Extends(superClass) \
    (Extends, superClass)

#define Params(...) \
    (Params, __VA_ARGS__)

#define PoolSize(poolSize) \
    Cbject_PoolSizeDef(Type, poolSize)

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

#define Setter(dataMemberType, dataMember) \
    Cbject_AccessorFun_Setter_Prototype(Type, dataMemberType, dataMember)

#define Getter(dataMemberType, dataMember) \
    Cbject_AccessorFun_Getter_Prototype(Type, dataMemberType, dataMember)

#define SetterImpl(dataMemberType, dataMember) \
    Cbject_AccessorFun_Setter_Impl(Type, dataMemberType, dataMember)

#define GetterImpl(dataMemberType, dataMember) \
    Cbject_AccessorFun_Getter_Impl(Type, dataMemberType, dataMember)

#define Init \
    Cbject_ObjectSetupFun_InitFunPrototype(Type)

#define Terminate \
    Cbject_ObjectTeardownFun_TerminateFunPrototype(Type)

#endif // CBJECT_KEYWORDS_H
