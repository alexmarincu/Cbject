#ifndef _CBJECTSINGLETON_H
#define _CBJECTSINGLETON_H
#include "_CbjectContainerTypeDefinition.h"
#include "_CbjectInitFunPrototype.h"
#include "_CbjectInstanceFunPrototype.h"
#include "_CbjectParamsTypeDefinition.h"
#include "_CbjectPropsTypeDef.h"
#include "_CbjectTerminateFunPrototype.h"
#include "_CbjectTypeDeclaration.h"

#define _CbjectObject(cbjectTypeName, parentName, props)                                \
    _CbjectPropsTypeDef(cbjectTypeName, _CbjectUtilities_stripParentheses(props)); \
    _CbjectParamsTypeDefinition(cbjectTypeName, 0);                                                 \
    _CbjectTypeDeclaration(cbjectTypeName);                                                         \
    _CbjectContainerTypeDefinition(cbjectTypeName, parentName);                                 \
    _CbjectInitFunPrototype(cbjectTypeName);                                                   \
    _CbjectTerminateFunPrototype(cbjectTypeName);                                              \
    _CbjectInstanceFunPrototype(cbjectTypeName)

#endif // _CBJECTSINGLETON_H
