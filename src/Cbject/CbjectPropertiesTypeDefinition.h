#ifndef CBJECTKLASSMEMBERSTYPEDEFINITION_H
#define CBJECTKLASSMEMBERSTYPEDEFINITION_H

#define CbjectPropertiesTypeDefinition0(klassName, ...) \
    typedef char klassName##Properties

#define CbjectPropertiesTypeDefinition_(klassName, ...)                  \
    typedef struct klassName##Properties                                      \
    {                                                                      \
        CbjectUtilities_forEach(CbjectUtilities_addSemicolon, __VA_ARGS__) \
    } klassName##Properties

#define CbjectPropertiesTypeDefinition_case(klassName, case, ...) \
    CbjectPropertiesTypeDefinition##case (klassName, __VA_ARGS__)

#define CbjectPropertiesTypeDefinition(klassName, ...) \
    CbjectPropertiesTypeDefinition_case(klassName, __VA_ARGS__)

#endif // CBJECTKLASSMEMBERSTYPEDEFINITION_H
