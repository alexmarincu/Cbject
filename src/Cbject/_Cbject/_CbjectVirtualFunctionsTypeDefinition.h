#ifndef _CBJECTVIRTUALFUNCTIONSTYPEDEFINITION_H
#define _CBJECTVIRTUALFUNCTIONSTYPEDEFINITION_H

#define _CbjectVirtualFunctionsTypeDefinition0(klassName, ...) \
    typedef char klassName##KlassVirtualFunctions

#define _CbjectVirtualFunctionsTypeDefinition_(klassName, ...)                                                   \
    typedef struct klassName##KlassVirtualFunctions                                                              \
    {                                                                                                            \
        _CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyVirtualFunctionPointer, __VA_ARGS__) \
    } klassName##KlassVirtualFunctions

#define _CbjectVirtualFunctionsTypeDefinition_case(klassName, case, ...) \
    _CbjectVirtualFunctionsTypeDefinition##case (klassName, __VA_ARGS__)

#define _CbjectVirtualFunctionsTypeDefinition(klassName, ...) \
    _CbjectVirtualFunctionsTypeDefinition_case(klassName, __VA_ARGS__)

#endif // _CBJECTVIRTUALFUNCTIONSTYPEDEFINITION_H
