#ifndef _CBJECTABSTRACTKLASS_H
#define _CBJECTABSTRACTKLASS_H
#include "_CbjectContainerTypeDefinition.h"
#include "_CbjectCtorFunPrototype.h"
#include "_CbjectKlassInstanceFunctionPrototype.h"
#include "_CbjectKlassTypeDefinition.h"
#include "_CbjectParamsTypeDefinition.h"
#include "_CbjectPropertiesTypeDefinition.h"
#include "_CbjectDtorFunPrototype.h"
#include "_CbjectTypeDeclaration.h"
#include "_CbjectVirtualFunctionsTypeDefinition.h"

#define _CbjectAbstractKlass(klassName, superKlassName, params, properties, virtualFunctions)              \
    _CbjectPropertiesTypeDefinition(klassName, _CbjectUtilities_stripParentheses(properties));             \
    _CbjectParamsTypeDefinition(klassName, _CbjectUtilities_stripParentheses(params));                     \
    _CbjectTypeDeclaration(klassName);                                                                     \
    _CbjectContainerTypeDefinition(klassName, superKlassName);                                             \
    _CbjectCtorFunPrototype(klassName);                                                               \
    _CbjectDtorFunPrototype(klassName);                                                          \
    _CbjectVirtualFunctionsTypeDefinition(klassName, _CbjectUtilities_stripParentheses(virtualFunctions)); \
    _CbjectKlassTypeDefinition(klassName, superKlassName, vf);                                             \
    _CbjectKlassInstanceFunctionPrototype(klassName);                                                      \
    SuperFunctions(_CbjectUtilities_stripParentheses(virtualFunctions));                                   \
    Functions(_CbjectUtilities_stripParentheses(virtualFunctions))

#endif // _CBJECTABSTRACTKLASS_H
