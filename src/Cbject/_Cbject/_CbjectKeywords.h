#ifndef _CBJECTKEYWORDS_H
#define _CBJECTKEYWORDS_H
#include "../CbjectPreprocessor.h"
#include "_CbjectAbstractKlass.h"
#include "_CbjectAbstractKlassSetup.h"
#include "_CbjectDataKlass.h"
#include "_CbjectDefaultGetter.h"
#include "_CbjectDefaultGetters.h"
#include "_CbjectDefaultSetter.h"
#include "_CbjectDefaultSetters.h"
#include "_CbjectEnumKlass.h"
#include "_CbjectFunction.h"
#include "_CbjectFunctions.h"
#include "_CbjectGetter.h"
#include "_CbjectGetters.h"
#include "_CbjectInit.h"
#include "_CbjectKlass.h"
#include "_CbjectKlassSetup.h"
#include "_CbjectNewOnStack.h"
#include "_CbjectPoolSize.h"
#include "_CbjectPrivateFunctions.h"
#include "_CbjectSetter.h"
#include "_CbjectSetters.h"
#include "_CbjectSingleton.h"
#include "_CbjectSingletonSetup.h"
#include "_CbjectSuperFunction.h"
#include "_CbjectSuperFunctions.h"
#include "_CbjectTerminate.h"
#include "_CbjectVirtualFunction.h"

#define Klass(params, properties, virtualFunctions) \
    _CbjectKlass(klass, superKlass, params, properties, virtualFunctions)

#define AbstractKlass(params, properties, virtualFunctions) \
    _CbjectAbstractKlass(klass, superKlass, params, properties, virtualFunctions)

#define Singleton(properties) \
    _CbjectSingleton(klass, superKlass, properties)

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
    _CbjectDataKlass(klass, __VA_ARGS__)

#define EnumKlass(...) \
    _CbjectEnumKlass(klass, __VA_ARGS__)

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
    _CbjectAbstractKlassSetup(klass, superKlass, __VA_ARGS__)

#define SingletonSetup(...) \
    _CbjectSingletonSetup(klass, superKlass, __VA_ARGS__)

#define KlassSetup(...) \
    _CbjectKlassSetup(klass, superKlass, __VA_ARGS__)

#define BindVirtualFunction(functionName) \
    CbjectPreprocessor_bvf(klass, functionName)
#define BindVirtualFunctions(...) \
    _CbjectUtilities_forEach(BindVirtualFunction, __VA_ARGS__)
#define BindFunction(type, superKlassName, functionName, arguments) \
    CbjectPreprocessor_bof(klass, type, superKlassName, functionName, arguments)
#define BindFunctions(...) \
    _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyBindFunction, __VA_ARGS__)

#endif // _CBJECTKEYWORDS_H
