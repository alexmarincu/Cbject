#ifndef CBJECTKEYWORDS_H
#define CBJECTKEYWORDS_H
#include "CbjectDefaultGetter.h"
#include "CbjectDefaultGetters.h"
#include "CbjectAbstractKlass.h"
#include "CbjectDefaultSetter.h"
#include "CbjectDefaultSetters.h"
#include "CbjectFunction.h"
#include "CbjectFunctions.h"
#include "CbjectGetter.h"
#include "CbjectGetters.h"
#include "CbjectPoolSize.h"
#include "CbjectPreprocessor.h"
#include "CbjectPrivateFunctions.h"
#include "CbjectSetter.h"
#include "CbjectSetters.h"
#include "CbjectSuperFunction.h"
#include "CbjectSuperFunctions.h"
#include "CbjectVirtualFunction.h"

#define Klass(initParams, properties, virtualFunctions) \
    CbjectPreprocessor_expandKlass(klass, superKlass, initParams, properties, virtualFunctions)

#define AbstractKlass(initParams, properties, virtualFunctions) \
    CbjectAbstractKlass(klass, superKlass, initParams, properties, virtualFunctions)

#define Singleton(initParams, properties) \
    CbjectPreprocessor_expandSingleton(klass, superKlass, initParams, properties)

#define InitParams(...) \
    (__VA_ARGS__)

#define Properties(...) \
    (__VA_ARGS__)

#define VirtualFunctions(...) \
    (__VA_ARGS__)

#define PoolSize(poolSize) \
    CbjectPoolSize(klass, poolSize)

#define Constant(type, ...) CbjectPreprocessor_c(klass, type, __VA_ARGS__)
#define Constants(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyConstant, __VA_ARGS__)
#define PublicConstant(type, constName) CbjectPreprocessor_pbc(klass, type, constName)
#define PublicConstants(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPublicConstant, __VA_ARGS__)
#define PrivateConstant(type, ...) CbjectPreprocessor_pc(klass, type, __VA_ARGS__)
#define PrivateConstants(klassName, ...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateConstant, __VA_ARGS__)

#define DataKlass(...) \
    CbjectPreprocessor_expandDataKlass(klass, __VA_ARGS__)

#define EnumKlass(...) \
    CbjectPreprocessor_expandEnumKlass(klass, __VA_ARGS__)

#define Function(returnType, functionName, arguments) \
    CbjectFunction(klass, returnType, functionName, CbjectUtilities_stripParentheses(arguments))

#define Functions(...) \
    CbjectFunctions(__VA_ARGS__)

#define PrivateFunction(returnType, functionName, arguments) \
    static Function(returnType, functionName, arguments)

#define PrivateFunctions(...) \
    CbjectPrivateFunctions(__VA_ARGS__)

#define VirtualFunction(returnType, functionName, arguments, params) \
    CbjectVirtualFunction(klass, returnType, functionName, arguments, params)

#define SuperFunction(returnType, functionName, arguments) \
    CbjectSuperFunction(klass, returnType, functionName, CbjectUtilities_stripParentheses(arguments))

#define SuperFunctions(...) \
    CbjectSuperFunctions(__VA_ARGS__)

#define cbject(klassName, varName, ...)                                \
    klassName * const varName = (klassName *) &((klassName##Shell){}); \
    klassName##_init((klassName *) varName, __VA_ARGS__)

#define Setter(type, memberName) \
    CbjectSetter(klass, type, memberName)

#define Getter(type, memberName) \
    CbjectGetter(klass, type, memberName)

#define Setters(...) \
    CbjectSetters(__VA_ARGS__)

#define Getters(...) \
    CbjectGetters(__VA_ARGS__)

#define DefaultSetter(type, memberName) \
    CbjectDefaultSetter(klass, type, memberName)

#define DefaultGetter(type, memberName) \
    CbjectDefaultGetter(klass, type, memberName)

#define DefaultSetters(...) \
    CbjectDefaultSetters(__VA_ARGS__)

#define DefaultGetters(...) \
    CbjectDefaultGetters(__VA_ARGS__)

#define Init(...) \
    CbjectPreprocessor_i(klass, superKlass, __VA_ARGS__)
#define Terminate(...) \
    CbjectPreprocessor_t(klass, superKlass, __VA_ARGS__)
#define AbstractKlassSetup(...) \
    CbjectAbstractKlassSetup(klass, superKlass, __VA_ARGS__)
#define SingletonSetup(...) \
    CbjectPreprocessor_expandSingletonSetup(klass, superKlass, __VA_ARGS__)
#define KlassSetup(...) \
    CbjectPreprocessor_expandKlassSetup(klass, superKlass, __VA_ARGS__)
#define BindVirtualFunction(functionName) \
    CbjectPreprocessor_bvf(klass, functionName)
#define BindVirtualFunctions(...) \
    CbjectUtilities_forEach(BindVirtualFunction, __VA_ARGS__)
#define BindFunction(type, superKlassName, functionName, arguments) \
    CbjectPreprocessor_bof(klass, type, superKlassName, functionName, arguments)
#define BindFunctions(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyBindFunction, __VA_ARGS__)

#endif // CBJECTKEYWORDS_H
