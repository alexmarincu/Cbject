#ifndef _CBJECTCONTAINERTYPEDEFINITION_H
#define _CBJECTCONTAINERTYPEDEFINITION_H

#define _CbjectContainerTypeDefinition(cbjectTypeName, parentName) \
    typedef union _##cbjectTypeName                                    \
    {                                                             \
        char d[sizeof(struct { _##parentName s; cbjectTypeName##Props p; })];                               \
        CbjectSettings_maxAlign a;                                \
    } _##cbjectTypeName

#endif // _CBJECTCONTAINERTYPEDEFINITION_H
