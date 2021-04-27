#ifndef CBJECTKEYWORDS_H
#define CBJECTKEYWORDS_H
#include "CbjectPreprocessor.h"
#include "_Cbject/_CbjectAbstractKlass.h"
#include "_Cbject/_CbjectDefaultGetter.h"
#include "_Cbject/_CbjectDefaultGetters.h"
#include "_Cbject/_CbjectDefaultSetter.h"
#include "_Cbject/_CbjectDefaultSetters.h"
#include "_Cbject/_CbjectFunction.h"
#include "_Cbject/_CbjectFunctions.h"
#include "_Cbject/_CbjectGetter.h"
#include "_Cbject/_CbjectGetters.h"
#include "_Cbject/_CbjectInit.h"
#include "_Cbject/_CbjectKlass.h"
#include "_Cbject/_CbjectNewOnStack.h"
#include "_Cbject/_CbjectPoolSize.h"
#include "_Cbject/_CbjectPrivateFunctions.h"
#include "_Cbject/_CbjectSetter.h"
#include "_Cbject/_CbjectSetters.h"
#include "_Cbject/_CbjectSingleton.h"
#include "_Cbject/_CbjectSuperFunction.h"
#include "_Cbject/_CbjectSuperFunctions.h"
#include "_Cbject/_CbjectTerminate.h"
#include "_Cbject/_CbjectVirtualFunction.h"

#define Klass(params, properties, virtualFunctions) \
    _CbjectKlass(klass, superKlass, params, properties, virtualFunctions)

#define AbstractKlass(params, properties, virtualFunctions) \
    _CbjectAbstractKlass(klass, superKlass, params, properties, virtualFunctions)

#define Singleton(params, properties) \
    _CbjectSingleton(klass, superKlass, params, properties)

#define Params(...) \
    (__VA_ARGS__)

#define Properties(...) \
    (__VA_ARGS__)

#define VirtualFunctions(...) \
    (__VA_ARGS__)

#define PoolSize(poolSize) \
    _CbjectPoolSize(klass, poolSize)

#define Constant(type, ...) CbjectPreprocessor_c(klass, type, __VA_ARGS__)
#define Constants(...) _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyConstant, __VA_ARGS__)
#define PublicConstant(type, constName) CbjectPreprocessor_pbc(klass, type, constName)
#define PublicConstants(...) _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPublicConstant, __VA_ARGS__)
#define PrivateConstant(type, ...) CbjectPreprocessor_pc(klass, type, __VA_ARGS__)
#define PrivateConstants(klassName, ...) \
    _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateConstant, __VA_ARGS__)

#define DataKlass(...) \
    CbjectPreprocessor_expandDataKlass(klass, __VA_ARGS__)

#define EnumKlass(...) \
    CbjectPreprocessor_expandEnumKlass(klass, __VA_ARGS__)

#define Function(returnType, functionName, arguments) \
    _CbjectFunction(klass, returnType, functionName, _CbjectUtilities_stripParentheses(arguments))

#define Functions(...) \
    _CbjectFunctions(__VA_ARGS__)

#define PrivateFunction(returnType, functionName, arguments) \
    static Function(returnType, functionName, arguments)

#define PrivateFunctions(...) \
    _CbjectPrivateFunctions(__VA_ARGS__)

#define VirtualFunction(returnType, functionName, arguments, params) \
    _CbjectVirtualFunction(klass, returnType, functionName, arguments, params)

#define SuperFunction(returnType, functionName, arguments) \
    _CbjectSuperFunction(klass, returnType, functionName, _CbjectUtilities_stripParentheses(arguments))

#define SuperFunctions(...) \
    _CbjectSuperFunctions(__VA_ARGS__)

#define NewOnStack(klassName, varName, ...) \
    _CbjectNewOnStack(klassName, varName, __VA_ARGS__)

#define Setter(type, memberName) \
    _CbjectSetter(klass, type, memberName)

#define Getter(type, memberName) \
    _CbjectGetter(klass, type, memberName)

#define Setters(...) \
    _CbjectSetters(__VA_ARGS__)

#define Getters(...) \
    _CbjectGetters(__VA_ARGS__)

#define DefaultSetter(type, memberName) \
    _CbjectDefaultSetter(klass, type, memberName)

#define DefaultGetter(type, memberName) \
    _CbjectDefaultGetter(klass, type, memberName)

#define DefaultSetters(...) \
    _CbjectDefaultSetters(__VA_ARGS__)

#define DefaultGetters(...) \
    _CbjectDefaultGetters(__VA_ARGS__)

#define Init(...) \
    _CbjectInit(klass, superKlass, __VA_ARGS__)

#define Terminate(...) \
    _CbjectTerminate(klass, superKlass, __VA_ARGS__)

#define AbstractKlassSetup(...) \
    CbjectAbstractKlassSetup(klass, superKlass, __VA_ARGS__)
#define SingletonSetup(...) \
    CbjectPreprocessor_expandSingletonSetup(klass, superKlass, __VA_ARGS__)
#define KlassSetup(...) \
    CbjectPreprocessor_expandKlassSetup(klass, superKlass, __VA_ARGS__)
#define BindVirtualFunction(functionName) \
    CbjectPreprocessor_bvf(klass, functionName)
#define BindVirtualFunctions(...) \
    _CbjectUtilities_forEach(BindVirtualFunction, __VA_ARGS__)
#define BindFunction(type, superKlassName, functionName, arguments) \
    CbjectPreprocessor_bof(klass, type, superKlassName, functionName, arguments)
#define BindFunctions(...) \
    _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyBindFunction, __VA_ARGS__)

#endif // CBJECTKEYWORDS_H
