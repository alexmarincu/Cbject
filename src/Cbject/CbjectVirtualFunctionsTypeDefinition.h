#ifndef CBJECTVIRTUALFUNCTIONSTYPEDEFINITION_H
#define CBJECTVIRTUALFUNCTIONSTYPEDEFINITION_H

#define CbjectVirtualFunctionsTypeDefinition0(klassName, ...) \
    typedef char klassName##KlassVirtualFunctions

#define CbjectVirtualFunctionsTypeDefinition_(klassName, ...)                                                   \
    typedef struct klassName##KlassVirtualFunctions                                                             \
    {                                                                                                           \
        CbjectUtilities_forEach(CbjectPreprocessor_stripParenthesesAndApplyVirtualFunctionPointer, __VA_ARGS__) \
    } klassName##KlassVirtualFunctions

#define CbjectVirtualFunctionsTypeDefinition_case(klassName, case, ...) \
    CbjectVirtualFunctionsTypeDefinition##case (klassName, __VA_ARGS__)

#define CbjectVirtualFunctionsTypeDefinition(klassName, ...) \
    CbjectVirtualFunctionsTypeDefinition_case(klassName, __VA_ARGS__)

#endif // CBJECTVIRTUALFUNCTIONSTYPEDEFINITION_H
