#ifndef _CBJECTENUMTYPEDEFINITION_H
#define _CBJECTENUMTYPEDEFINITION_H

#define _CbjectEnumTypeDefinition_prependClassNameAndAddComma__(cbjectTypeName, valueName) \
    cbjectTypeName##_##valueName,
#define _CbjectEnumTypeDefinition_prependClassNameAndAddComma_(cbjectTypeName, valueName) \
    _CbjectEnumTypeDefinition_prependClassNameAndAddComma__(cbjectTypeName, valueName)

#define _CbjectEnumTypeDefinition_prependClassNameAndAddComma(valueName) \
    _CbjectEnumTypeDefinition_prependClassNameAndAddComma_(CbjectType, valueName)

#define _CbjectEnumTypeDefinition(cbjectTypeName, ...)                                                    \
    typedef enum cbjectTypeName                                                                           \
    {                                                                                                \
        _CbjectUtilities_forEach(_CbjectEnumTypeDefinition_prependClassNameAndAddComma, __VA_ARGS__) \
    } cbjectTypeName

#endif // _CBJECTENUMTYPEDEFINITION_H
