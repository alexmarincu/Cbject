#ifndef CBJECTKEYWORDS_H
#define CBJECTKEYWORDS_H
#include "CbjectPreprocessor.h"

#define AbstractClassInitParams(...) CbjectPreprocessor_acp(class, superClass, __VA_ARGS__)
#define SingletonInitParams(...) CbjectPreprocessor_op(class, superClass, __VA_ARGS__)
#define ClassInitParams(...) CbjectPreprocessor_cp(class, superClass, __VA_ARGS__)

#if Cbject_useStaticPool == true
    #define classPoolSize(poolSize) CbjectPreprocessor_cps(class, poolSize)
#endif

#define classMembers(...) CbjectPreprocessor_cm(class, superClass, __VA_ARGS__)
#define objectMembers(...) CbjectPreprocessor_cm(class, superClass, __VA_ARGS__)
#define classDeclaration(...) CbjectPreprocessor_cd(class, superClass, __VA_ARGS__)
#define constant(type, ...) CbjectPreprocessor_c(class, type, __VA_ARGS__)
#define constants(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyConstant, __VA_ARGS__)
#define publicConstant(type, constName) CbjectPreprocessor_pbc(class, type, constName)
#define publicConstants(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPublicConstant, __VA_ARGS__)
#define privateConstant(type, ...) CbjectPreprocessor_pc(class, type, __VA_ARGS__)
#define privateConstants(className, ...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateConstant, __VA_ARGS__)
#define abstractClassMembers(...) CbjectPreprocessor_acm(class, superClass, __VA_ARGS__)
#define dataClass(...) CbjectPreprocessor_dc(class, __VA_ARGS__)
#define enumClass(...) CbjectPreprocessor_ec(class, __VA_ARGS__)
#define function(type, functionName, arguments) CbjectPreprocessor_f(class, type, functionName, arguments)
#define functions(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyFunction, __VA_ARGS__)
#define privateFunction(type, functionName, arguments) CbjectPreprocessor_pf(class, type, functionName, arguments)
#define privateFunctions(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyPrivateFunction, __VA_ARGS__)
#define virtualFunction(type, functionName, arguments, params) CbjectPreprocessor_vf(class, type, functionName, arguments, params)
#define virtualFunctions(...) CbjectPreprocessor_vfs(class, superClass, __VA_ARGS__)

#define cbject(className, varName, ...)                  \
    className * const varName = (className *) &((className##Shell){});  \
    className##_init((className *) varName, __VA_ARGS__)
    
#define setterGetter(type, memberName) CbjectPreprocessor_sg(class, type, memberName)
#define settersGetters(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplySetterGetter, __VA_ARGS__)
#define defaultSetter(type, memberName) CbjectPreprocessor_ds(class, type, memberName)
#define defaultGetter(type, memberName) CbjectPreprocessor_dg(class, type, memberName)
#define defaultSetterGetter(type, memberName) CbjectPreprocessor_dsg(class, type, memberName)
#define defaultSettersGetters(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyDefaultSetterGetter, __VA_ARGS__)
#define overrideFunction(type, superClassName, functionName, arguments) CbjectPreprocessor_of(class, type, superClassName, functionName, arguments)
#define overrideFunctions(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyOverrideFunction, __VA_ARGS__)
#define init(...) CbjectPreprocessor_i(class, superClass, __VA_ARGS__)
#define terminate(...) CbjectPreprocessor_t(class, superClass, __VA_ARGS__)
#define abstractClassSetup(...) CbjectPreprocessor_acs(class, superClass, __VA_ARGS__)
#define objectSetup(...) CbjectPreprocessor_os(class, superClass, __VA_ARGS__)
#define classSetup(...) CbjectPreprocessor_cs(class, superClass, __VA_ARGS__)
#define bindVirtualFunction(functionName) CbjectPreprocessor_bvf(class, functionName)
#define bindVirtualFunctions(...) CbjectUtilities_forEach(bindVirtualFunction, __VA_ARGS__)
#define bindFunction(type, superClassName, functionName, arguments) CbjectPreprocessor_bof(class, type, superClassName, functionName, arguments)
#define bindFunctions(...) CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplybindFunction, __VA_ARGS__)

#endif // CBJECTKEYWORDS_H
