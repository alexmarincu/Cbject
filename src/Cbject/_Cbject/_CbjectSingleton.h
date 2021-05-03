#ifndef _CBJECTSINGLETON_H
#define _CBJECTSINGLETON_H
#include "_CbjectContainerTypeDefinition.h"
#include "_CbjectCtorFunPrototype.h"
#include "_CbjectInstanceFunctionPrototype.h"
#include "_CbjectParamsTypeDefinition.h"
#include "_CbjectPropertiesTypeDefinition.h"
#include "_CbjectDtorFunPrototype.h"
#include "_CbjectTypeDeclaration.h"

#define _CbjectSingleton(klassName, superKlassName, properties)                                \
    _CbjectPropertiesTypeDefinition(klassName, _CbjectUtilities_stripParentheses(properties)); \
    _CbjectParamsTypeDefinition(klassName, 0);                                                 \
    _CbjectTypeDeclaration(klassName);                                                         \
    _CbjectContainerTypeDefinition(klassName, superKlassName);                                 \
    _CbjectCtorFunPrototype(klassName);                                                   \
    _CbjectDtorFunPrototype(klassName);                                              \
    _CbjectInstanceFunctionPrototype(klassName)

#endif // _CBJECTSINGLETON_H
