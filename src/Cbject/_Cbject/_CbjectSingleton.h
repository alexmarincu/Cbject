#ifndef _CBJECTSINGLETON_H
#define _CBJECTSINGLETON_H
#include "_CbjectContainerTypeDefinition.h"
#include "_CbjectInitFunctionPrototype.h"
#include "_CbjectInstanceFunctionPrototype.h"
#include "_CbjectParamsTypeDefinition.h"
#include "_CbjectPropertiesTypeDefinition.h"
#include "_CbjectTerminateFunctionPrototype.h"
#include "_CbjectTypeDeclaration.h"

#define _CbjectSingleton(klassName, superKlassName, properties)                                \
    _CbjectPropertiesTypeDefinition(klassName, _CbjectUtilities_stripParentheses(properties)); \
    _CbjectParamsTypeDefinition(klassName, 0);                                                 \
    _CbjectTypeDeclaration(klassName);                                                         \
    _CbjectContainerTypeDefinition(klassName, superKlassName);                                 \
    _CbjectInitFunctionPrototype(klassName);                                                   \
    _CbjectTerminateFunctionPrototype(klassName);                                              \
    _CbjectInstanceFunctionPrototype(klassName)

#endif // _CBJECTSINGLETON_H
