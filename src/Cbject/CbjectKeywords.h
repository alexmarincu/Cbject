#ifndef CBJECTKEYWORDS_H
#define CBJECTKEYWORDS_H
#include "CbjectPreprocessor.h"

#define Class(initParams, members, virtualFunctions) \
    CbjectPreprocessor_expandClass(class, superClass, initParams, members, virtualFunctions)

#define AbstractClass(initParams, members, virtualFunctions) CbjectPreprocessor_expandAbstractClass(class, superClass, initParams, members, virtualFunctions)
#define Singleton(initParams, members) CbjectPreprocessor_expandSingleton(class, superClass, initParams, members)
#define InitParams(...) (__VA_ARGS__)
#define Members(...) (__VA_ARGS__)
#define PoolSize(poolSize) CbjectPreprocessor_cps(class, poolSize)
#define ClassMembers() CbjectPreprocessor_cm(class, superClass)
#define AbstractClassMembers() CbjectPreprocessor_expandAbstractClassMembers(class, superClass)
#define Constant(type, ...) CbjectPreprocessor_c(class, type, __VA_ARGS__)
#define Constants(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyConstant, __VA_ARGS__)
#define PublicConstant(type, constName) CbjectPreprocessor_pbc(class, type, constName)
#define PublicConstants(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPublicConstant, __VA_ARGS__)
#define PrivateConstant(type, ...) CbjectPreprocessor_pc(class, type, __VA_ARGS__)
#define PrivateConstants(className, ...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateConstant, __VA_ARGS__)
#define DataClassMembers(...) CbjectPreprocessor_dc(class, __VA_ARGS__)
#define EnumClassMembers(...) CbjectPreprocessor_ec(class, __VA_ARGS__)
#define Function(returnType, functionName, arguments) CbjectPreprocessor_expandFunction(class, returnType, functionName, arguments)
#define Functions(...) CbjectPreprocessor_expandFunctions(__VA_ARGS__)
#define PrivateFunction(returnType, functionName, arguments) CbjectPreprocessor_expandPrivateFunction(class, returnType, functionName, arguments)
#define PrivateFunctions(...) CbjectPreprocessor_expandPrivateFunctions(__VA_ARGS__)
#define VirtualFunction(returnType, functionName, arguments, params) CbjectPreprocessor_expandVirtualFunction(class, returnType, functionName, arguments, params)
#define VirtualFunctionsOld(...) CbjectPreprocessor_expandVirtualFunctions(class, superClass, __VA_ARGS__)
#define VirtualFunctions(...) (__VA_ARGS__)
#define SuperFunction(returnType, functionName, arguments) CbjectPreprocessor_expandSuperFunction(class, returnType, functionName, arguments)
#define SuperFunctions(...) CbjectPreprocessor_expandSuperFunctions(__VA_ARGS__)

#define cbject(className, varName, ...)                                \
    className * const varName = (className *) &((className##Shell){}); \
    className##_init((className *) varName, __VA_ARGS__)

#define Setter(type, memberName) CbjectPreprocessor_expandSetter(class, type, memberName)
#define Getter(type, memberName) CbjectPreprocessor_expandGetter(class, type, memberName)
#define Setters(...) CbjectPreprocessor_expandSetters(__VA_ARGS__)
#define Getters(...) CbjectPreprocessor_expandGetters(__VA_ARGS__)
#define DefaultSetter(type, memberName) CbjectPreprocessor_expandDefaultSetter(class, type, memberName)
#define DefaultGetter(type, memberName) CbjectPreprocessor_expandDefaultGetter(class, type, memberName)
#define DefaultSetters(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyDefaultSetter, __VA_ARGS__)
#define DefaultGetters(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyDefaultGetter, __VA_ARGS__)
#define OverrideFunction(type, superClassName, functionName, arguments) CbjectPreprocessor_of(class, type, superClassName, functionName, arguments)
#define OverrideFunctions(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyOverrideFunction, __VA_ARGS__)
#define Init(...) CbjectPreprocessor_i(class, superClass, __VA_ARGS__)
#define Terminate(...) CbjectPreprocessor_t(class, superClass, __VA_ARGS__)
#define AbstractClassSetup(...) CbjectPreprocessor_acs(class, superClass, __VA_ARGS__)
#define SingletonSetup(...) CbjectPreprocessor_os(class, superClass, __VA_ARGS__)
#define ClassSetup(...) CbjectPreprocessor_cs(class, superClass, __VA_ARGS__)
#define BindVirtualFunction(functionName) CbjectPreprocessor_bvf(class, functionName)
#define BindVirtualFunctions(...) CbjectUtilities_forEach(BindVirtualFunction, __VA_ARGS__)
#define BindFunction(type, superClassName, functionName, arguments) CbjectPreprocessor_bof(class, type, superClassName, functionName, arguments)
#define BindFunctions(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyBindFunction, __VA_ARGS__)

#endif // CBJECTKEYWORDS_H
