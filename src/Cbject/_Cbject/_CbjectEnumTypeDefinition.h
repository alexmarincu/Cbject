#ifndef _CBJECTENUMTYPEDEFINITION_H
#define _CBJECTENUMTYPEDEFINITION_H

#define _CbjectEnumTypeDefinition_prependKlassNameAndAddComma__(klassName, valueName) \
    klassName##_##valueName,
#define _CbjectEnumTypeDefinition_prependKlassNameAndAddComma_(klassName, valueName) \
    _CbjectEnumTypeDefinition_prependKlassNameAndAddComma__(klassName, valueName)

#define _CbjectEnumTypeDefinition_prependKlassNameAndAddComma(valueName) \
    _CbjectEnumTypeDefinition_prependKlassNameAndAddComma_(klass, valueName)

#define _CbjectEnumTypeDefinition(klassName, ...)                                                    \
    typedef enum klassName                                                                           \
    {                                                                                                \
        _CbjectUtilities_forEach(_CbjectEnumTypeDefinition_prependKlassNameAndAddComma, __VA_ARGS__) \
    } klassName

#endif // _CBJECTENUMTYPEDEFINITION_H
