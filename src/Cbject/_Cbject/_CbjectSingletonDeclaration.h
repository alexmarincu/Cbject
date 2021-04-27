#ifndef _CBJECTSINGLETONDECLARATION_H
#define _CBJECTSINGLETONDECLARATION_H
#include "_CbjectContainerTypeDefinition.h"
#include "_CbjectInitFunctionPrototype.h"
#include "_CbjectParamsTypeDefinition.h"
#include "_CbjectInstanceFunctionPrototype.h"
#include "_CbjectPropertiesTypeDefinition.h"
#include "_CbjectTerminateFunctionPrototype.h"
#include "_CbjectTypeDeclaration.h"

#define _CbjectSingletonDeclaration(klassName, superKlassName, params, properties)         \
    _CbjectPropertiesTypeDefinition(klassName, _CbjectUtilities_stripParentheses(properties)); \
    _CbjectParamsTypeDefinition(klassName, _CbjectUtilities_stripParentheses(params)); \
    _CbjectTypeDeclaration(klassName);                                                         \
    _CbjectContainerTypeDefinition(klassName, superKlassName);                                 \
    _CbjectInitFunctionPrototype(klassName);                                                   \
    _CbjectTerminateFunctionPrototype(klassName);                                              \
    _CbjectInstanceFunctionPrototype(klassName)

#endif // _CBJECTSINGLETONDECLARATION_H
