#ifndef _CBJECTABSTRACTKLASS_H
#define _CBJECTABSTRACTKLASS_H
#include "_CbjectCastToSubFunPrototype.h"
#include "_CbjectCastToSuperFunPrototype.h"
#include "_CbjectContainerTypeDefinition.h"
#include "_CbjectInitFunPrototype.h"
#include "_CbjectKlassInstanceFunctionPrototype.h"
#include "_CbjectKlassTypeDefinition.h"
#include "_CbjectParamsTypeDefinition.h"
#include "_CbjectPropertiesTypeDefinition.h"
#include "_CbjectTerminateFunPrototype.h"
#include "_CbjectTypeDeclaration.h"
#include "_CbjectVirtualFunctionsTypeDefinition.h"

#define _CbjectAbstractKlass(klassName, superKlassName, params, properties, virtualFunctions)              \
    _CbjectPropertiesTypeDefinition(klassName, _CbjectUtilities_stripParentheses(properties));             \
    _CbjectParamsTypeDefinition(klassName, _CbjectUtilities_stripParentheses(params));                     \
    _CbjectTypeDeclaration(klassName);                                                                     \
    _CbjectContainerTypeDefinition(klassName, superKlassName);                                             \
    _CbjectInitFunPrototype(klassName);                                                                    \
    _CbjectTerminateFunPrototype(klassName);                                                               \
    _CbjectVirtualFunctionsTypeDefinition(klassName, _CbjectUtilities_stripParentheses(virtualFunctions)); \
    _CbjectKlassTypeDefinition(klassName, superKlassName, vf);                                             \
    _CbjectKlassInstanceFunctionPrototype(klassName);                                                      \
    SuperFunctions(_CbjectUtilities_stripParentheses(virtualFunctions));                                   \
    Functions(_CbjectUtilities_stripParentheses(virtualFunctions));                                        \
    _CbjectCastToSuperFunPrototype(klassName, superKlassName);                                             \
    _CbjectCastToSubFunPrototype(klassName, superKlassName)

#endif // _CBJECTABSTRACTKLASS_H
