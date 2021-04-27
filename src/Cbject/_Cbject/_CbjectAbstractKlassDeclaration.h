#ifndef _CBJECTABSTRACTKLASSDECLARATION_H
#define _CBJECTABSTRACTKLASSDECLARATION_H
#include "_CbjectInitFunctionPrototype.h"
#include "_CbjectParamsTypeDefinition.h"
#include "_CbjectKlassInstanceFunctionPrototype.h"
#include "_CbjectKlassTypeDefinition.h"
#include "_CbjectPropertiesTypeDefinition.h"
#include "_CbjectContainerTypeDefinition.h"
#include "_CbjectTerminateFunctionPrototype.h"
#include "_CbjectTypeDeclaration.h"
#include "_CbjectVirtualFunctionsTypeDefinition.h"

#define _CbjectAbstractKlassDeclaration(klassName, superKlassName, params, properties, virtualFunctions) \
    _CbjectPropertiesTypeDefinition(klassName, _CbjectUtilities_stripParentheses(properties));               \
    _CbjectParamsTypeDefinition(klassName, _CbjectUtilities_stripParentheses(params));               \
    _CbjectTypeDeclaration(klassName);                                                                       \
    _CbjectContainerTypeDefinition(klassName, superKlassName);                                                   \
    _CbjectInitFunctionPrototype(klassName);                                                                 \
    _CbjectTerminateFunctionPrototype(klassName);                                                            \
    _CbjectVirtualFunctionsTypeDefinition(klassName, _CbjectUtilities_stripParentheses(virtualFunctions));   \
    _CbjectKlassTypeDefinition(klassName, superKlassName);                                                   \
    _CbjectKlassInstanceFunctionPrototype(klassName);                                                        \
    SuperFunctions(_CbjectUtilities_stripParentheses(virtualFunctions));                                     \
    Functions(_CbjectUtilities_stripParentheses(virtualFunctions))

#endif // _CBJECTABSTRACTKLASSDECLARATION_H
