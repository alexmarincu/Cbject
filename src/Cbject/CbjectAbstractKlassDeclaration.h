#ifndef CBJECTABSTRACTKLASSDECLARATION_H
#define CBJECTABSTRACTKLASSDECLARATION_H
#include "CbjectInitFunctionPrototype.h"
#include "CbjectInitParamsTypeDefinition.h"
#include "CbjectKlassInstanceFunctionPrototype.h"
#include "CbjectKlassTypeDefinition.h"
#include "CbjectPropertiesTypeDefinition.h"
#include "CbjectShellTypeDefinition.h"
#include "CbjectTerminateFunctionPrototype.h"
#include "CbjectTypeDeclaration.h"
#include "CbjectVirtualFunctionsTypeDefinition.h"

#define CbjectAbstractKlassDeclaration(klassName, superKlassName, initParams, properties, virtualFunctions) \
    CbjectPropertiesTypeDefinition(klassName, CbjectUtilities_stripParentheses(properties));                   \
    CbjectInitParamsTypeDefinition(klassName, CbjectUtilities_stripParentheses(initParams));             \
    CbjectTypeDeclaration(klassName);                                                                    \
    CbjectShellTypeDefinition(klassName, superKlassName);                                                \
    CbjectInitFunctionPrototype(klassName);                                                              \
    CbjectTerminateFunctionPrototype(klassName);                                                         \
    CbjectVirtualFunctionsTypeDefinition(klassName, CbjectUtilities_stripParentheses(virtualFunctions)); \
    CbjectKlassTypeDefinition(klassName, superKlassName);                                                \
    CbjectKlassInstanceFunctionPrototype(klassName);                                                     \
    SuperFunctions(CbjectUtilities_stripParentheses(virtualFunctions));                                  \
    Functions(CbjectUtilities_stripParentheses(virtualFunctions))

#endif // CBJECTABSTRACTKLASSDECLARATION_H
