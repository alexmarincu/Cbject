#ifndef _CBJECTPROPERTIESTYPEDEFINITION_H
#define _CBJECTPROPERTIESTYPEDEFINITION_H

#define _CbjectPropertiesTypeDefinition_0(klassName, ...) \
    typedef char klassName##Properties

#define _CbjectPropertiesTypeDefinition__(klassName, ...)                    \
    typedef struct klassName##Properties                                     \
    {                                                                        \
        _CbjectUtilities_forEach(_CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } klassName##Properties

#define _CbjectPropertiesTypeDefinition_case(klassName, case, ...) \
    _CbjectPropertiesTypeDefinition_##case (klassName, __VA_ARGS__)

#define _CbjectPropertiesTypeDefinition(klassName, ...) \
    _CbjectPropertiesTypeDefinition_case(klassName, __VA_ARGS__)

#endif // _CBJECTPROPERTIESTYPEDEFINITION_H
