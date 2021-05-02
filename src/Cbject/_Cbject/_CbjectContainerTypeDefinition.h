#ifndef _CBJECTCONTAINERTYPEDEFINITION_H
#define _CBJECTCONTAINERTYPEDEFINITION_H

#define _CbjectContainerTypeDefinition(klassName, superKlassName) \
    typedef union _##klassName                                    \
    {                                                             \
        char d[sizeof(struct { _##superKlassName s; klassName##Properties p; })];                               \
        CbjectSettings_maxAlign a;                                \
    } _##klassName

#endif // _CBJECTCONTAINERTYPEDEFINITION_H
