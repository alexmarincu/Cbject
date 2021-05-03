#ifndef _CBJECTVIRTUALFUNCTIONSTYPEDEFINITION_H
#define _CBJECTVIRTUALFUNCTIONSTYPEDEFINITION_H
#include "_CbjectVirtualFunctionPointer.h"

#define _CbjectVirtualFunctionsTypeDefinition_stripParenthesesAndApplyVirtualFunctionPointer(functionPrototype) \
    _CbjectVirtualFunctionPointer functionPrototype;

#define _CbjectVirtualFunctionsTypeDefinition_0(klassName, ...) \
    typedef char klassName##KlassVirtualFunctions

#define _CbjectVirtualFunctionsTypeDefinition__(klassName, ...)                                                                     \
    typedef struct klassName##KlassVirtualFunctions                                                                                 \
    {                                                                                                                               \
        _CbjectUtilities_forEach(_CbjectVirtualFunctionsTypeDefinition_stripParenthesesAndApplyVirtualFunctionPointer, __VA_ARGS__) \
    } klassName##KlassVirtualFunctions

#define _CbjectVirtualFunctionsTypeDefinition_case(klassName, case, ...) \
    _CbjectVirtualFunctionsTypeDefinition_##case (klassName, __VA_ARGS__)

#define _CbjectVirtualFunctionsTypeDefinition(klassName, ...) \
    _CbjectVirtualFunctionsTypeDefinition_case(klassName, __VA_ARGS__)

#endif // _CBJECTVIRTUALFUNCTIONSTYPEDEFINITION_H
