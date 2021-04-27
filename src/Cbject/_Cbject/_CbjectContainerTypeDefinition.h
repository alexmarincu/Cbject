#ifndef _CBJECTCONTAINERTYPEDEFINITION_H
#define _CBJECTCONTAINERTYPEDEFINITION_H

#define _CbjectContainerTypeDefinition(klassName, superKlassName) \
    typedef union _##klassName                                    \
    {                                                             \
        char d[sizeof(struct { _##superKlassName super; klassName##Properties m; })];                               \
        CbjectSettings_maxAlign a;                                \
    } _##klassName

#endif // _CBJECTCONTAINERTYPEDEFINITION_H
