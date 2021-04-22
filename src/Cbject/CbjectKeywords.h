#ifndef CBJECTKEYWORDS_H
#define CBJECTKEYWORDS_H
#include "CbjectPreprocessor.h"

#define Klass(initParams, members, virtualFunctions) \
    CbjectPreprocessor_expandKlass(klass, superKlass, initParams, members, virtualFunctions)

#define AbstractKlass(initParams, members, virtualFunctions) \
    CbjectPreprocessor_expandAbstractKlass(klass, superKlass, initParams, members, virtualFunctions)

#define Singleton(initParams, members) \
    CbjectPreprocessor_expandSingleton(klass, superKlass, initParams, members)

#define InitParams(...) \
    (__VA_ARGS__)

#define Members(...) \
    (__VA_ARGS__)

#define VirtualFunctions(...) \
    (__VA_ARGS__)

#define PoolSize(poolSize) \
    CbjectPreprocessor_expandPoolSize(klass, poolSize)

#define Constant(type, ...) CbjectPreprocessor_c(klass, type, __VA_ARGS__)
#define Constants(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyConstant, __VA_ARGS__)
#define PublicConstant(type, constName) CbjectPreprocessor_pbc(klass, type, constName)
#define PublicConstants(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPublicConstant, __VA_ARGS__)
#define PrivateConstant(type, ...) CbjectPreprocessor_pc(klass, type, __VA_ARGS__)
#define PrivateConstants(klassName, ...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateConstant, __VA_ARGS__)

#define DataKlassMembers(...) \
    CbjectPreprocessor_expandDataKlassMembers(klass, __VA_ARGS__)

#define EnumKlassMembers(...) \
    CbjectPreprocessor_expandEnumKlassMembers(klass, __VA_ARGS__)

#define Function(returnType, functionName, arguments) \
    CbjectPreprocessor_expandFunction(klass, returnType, functionName, arguments)

#define Functions(...) CbjectPreprocessor_expandFunctions(__VA_ARGS__)

#define PrivateFunction(returnType, functionName, arguments) \
    CbjectPreprocessor_expandPrivateFunction(klass, returnType, functionName, arguments)

#define PrivateFunctions(...) \
    CbjectPreprocessor_expandPrivateFunctions(__VA_ARGS__)

#define VirtualFunction(returnType, functionName, arguments, params) \
    CbjectPreprocessor_expandVirtualFunction(klass, returnType, functionName, arguments, params)

#define SuperFunction(returnType, functionName, arguments) \
    CbjectPreprocessor_expandSuperFunction(klass, returnType, functionName, arguments)

#define SuperFunctions(...) \
    CbjectPreprocessor_expandSuperFunctions(__VA_ARGS__)

#define cbject(klassName, varName, ...)                                \
    klassName * const varName = (klassName *) &((klassName##Shell){}); \
    klassName##_init((klassName *) varName, __VA_ARGS__)

#define Setter(type, memberName) \
    CbjectPreprocessor_expandSetter(klass, type, memberName)

#define Getter(type, memberName) \
    CbjectPreprocessor_expandGetter(klass, type, memberName)

#define Setters(...) \
    CbjectPreprocessor_expandSetters(__VA_ARGS__)

#define Getters(...) \
    CbjectPreprocessor_expandGetters(__VA_ARGS__)

#define DefaultSetter(type, memberName) \
    CbjectPreprocessor_expandDefaultSetter(klass, type, memberName)

#define DefaultGetter(type, memberName) \
    CbjectPreprocessor_expandDefaultGetter(klass, type, memberName)

#define DefaultSetters(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyDefaultSetter, __VA_ARGS__)

#define DefaultGetters(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyDefaultGetter, __VA_ARGS__)

#define OverrideFunction(type, superKlassName, functionName, arguments) \
    CbjectPreprocessor_of(klass, type, superKlassName, functionName, arguments)

#define OverrideFunctionNew(superKlassName, functionPrototype) \
    CbjectPreprocessor_expandOverrideFunctionNew(klass, superKlassName, CbjectUtilities_stripParentheses(functionPrototype))

#define OverrideFunctions(...) \
    CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyOverrideFunction, __VA_ARGS__)

#define Init(...) \
    CbjectPreprocessor_i(klass, superKlass, __VA_ARGS__)
#define Terminate(...) \
    CbjectPreprocessor_t(klass, superKlass, __VA_ARGS__)
#define AbstractKlassSetup(...) \
    CbjectPreprocessor_expandAbstractKlassSetup(klass, superKlass, __VA_ARGS__)
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
