#ifndef CBJECTPREPROCESSOR_H
#define CBJECTPREPROCESSOR_H
#include "CbjectSettings.h"
#include "Primitives.h"
#include "_Cbject/_CbjectContainerTypeDefinition.h"
#include "_Cbject/_CbjectFunction.h"
#include "_Cbject/_CbjectKlassInstanceImpl.h"
#include "_Cbject/_CbjectKlassTypeDefinition.h"
#include "_Cbject/_CbjectParamsTypeDefinition.h"
#include "_Cbject/_CbjectPropertiesTypeDefinition.h"
#include "_Cbject/_CbjectTypeDefinition.h"
#include "_Cbject/_CbjectUtilities.h"
#include "_Cbject/_CbjectVirtualFunctionsTypeDefinition.h"

#define CbjectPreprocessor_c_(klassName, type, ...) type const klassName##_##__VA_ARGS__
#define CbjectPreprocessor_c(klassName, type, ...) CbjectPreprocessor_c_(klassName, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyConstant(constPrototype) Constant constPrototype;

#define CbjectPreprocessor_pbc_(klassName, type, constName) extern type const klassName##_##constName
#define CbjectPreprocessor_pbc(klassName, type, constName) CbjectPreprocessor_pbc_(klassName, type, constName)
#define CbjectPreprocessor_stripParenthesesAndApplyPublicConstant(constPrototype) PublicConstant constPrototype;

#define CbjectPreprocessor_pc_(klassName, type, ...) static type const klassName##_##__VA_ARGS__
#define CbjectPreprocessor_pc(klassName, type, ...) CbjectPreprocessor_pc_(klassName, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyPrivateConstant(constPrototype) PrivateConstant constPrototype;

#define CbjectPreprocessor_bvf_(klassName, functionName) \
    k.vf.functionName = s##klassName##_##functionName;
#define CbjectPreprocessor_bvf(klassName, functionName) CbjectPreprocessor_bvf_(klassName, functionName)

#define CbjectPreprocessor_bof_(klassName, type, superKlassName, functionName, arguments) \
    ((superKlassName##Klass *) &k)->vf.functionName = (type(*)(superKlassName * const me _CbjectUtilities_vaArgs(_CbjectUtilities_stripParentheses(arguments)))) s##klassName##_##functionName
#define CbjectPreprocessor_bof(klassName, type, superKlassName, functionName, arguments) CbjectPreprocessor_bof_(klassName, type, superKlassName, functionName, arguments)

#define CbjectPreprocessor_stripParenthesesAndApplyBindFunction(functionPrototype) BindFunction functionPrototype;

#endif // CBJECTPREPROCESSOR_H
