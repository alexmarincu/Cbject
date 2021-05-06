#ifndef CBJECTPREPROCESSOR_H
#define CBJECTPREPROCESSOR_H
#include "CbjectSettings.h"
#include "Primitives.h"
#include "_Cbject/_CbjectContainerTypeDefinition.h"
#include "_Cbject/_CbjectFun.h"
#include "_Cbject/_CbjectClassTypeDefinition.h"
#include "_Cbject/_CbjectParamsTypeDefinition.h"
#include "_Cbject/_CbjectPropsTypeDef.h"
#include "_Cbject/_CbjectTypeDefinition.h"
#include "_Cbject/_CbjectUtilities.h"
#include "_Cbject/_CbjectVirtualFunsTypeDef.h"

#define CbjectPreprocessor_c_(cbjectTypeName, type, ...) type const cbjectTypeName##_##__VA_ARGS__
#define CbjectPreprocessor_c(cbjectTypeName, type, ...) CbjectPreprocessor_c_(cbjectTypeName, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyConst(constPrototype) Const constPrototype;

#define CbjectPreprocessor_pbc_(cbjectTypeName, type, constName) extern type const cbjectTypeName##_##constName
#define CbjectPreprocessor_pbc(cbjectTypeName, type, constName) CbjectPreprocessor_pbc_(cbjectTypeName, type, constName)
#define CbjectPreprocessor_stripParenthesesAndApplyPublicConst(constPrototype) PublicConst constPrototype;

#define CbjectPreprocessor_pc_(cbjectTypeName, type, ...) static type const cbjectTypeName##_##__VA_ARGS__
#define CbjectPreprocessor_pc(cbjectTypeName, type, ...) CbjectPreprocessor_pc_(cbjectTypeName, type, __VA_ARGS__)
#define CbjectPreprocessor_stripParenthesesAndApplyPrivateConst(constPrototype) PrivateConst constPrototype;

#define CbjectPreprocessor_bvf_(cbjectTypeName, funName) \
    k.vf.funName = s_##cbjectTypeName##_##funName;
#define CbjectPreprocessor_bvf(cbjectTypeName, funName) CbjectPreprocessor_bvf_(cbjectTypeName, funName)

#define CbjectPreprocessor_stripParenthesesAndApplyBindFun(funPrototype) BindFun funPrototype;

#endif // CBJECTPREPROCESSOR_H
