#ifndef _CBJECTKLASSTYPEDEFINITION_H
#define _CBJECTKLASSTYPEDEFINITION_H

#define _CbjectClassTypeDefinition_0(cbjectTypeName, parentName) \
    typedef struct cbjectTypeName##Class                             \
    {                                                           \
        parentName##Class s;                                \
    } cbjectTypeName##Class

#define _CbjectClassTypeDefinition_vf(cbjectTypeName, parentName) \
    typedef struct cbjectTypeName##Class                              \
    {                                                            \
        parentName##Class s;                                 \
        cbjectTypeName##VirtualFuns vf;                     \
    } cbjectTypeName##Class

#define _CbjectClassTypeDefinition(cbjectTypeName, parentName, case) \
    _CbjectClassTypeDefinition_##case (cbjectTypeName, parentName)

#endif // _CBJECTKLASSTYPEDEFINITION_H
