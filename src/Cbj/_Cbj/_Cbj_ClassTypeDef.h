#ifndef _CBJ_CLASSTYPEDEF_H
#define _CBJ_CLASSTYPEDEF_H

#define _Cbj_ClassTypeDef_0(typeName, Cbj_ParentName) \
    typedef struct typeName##Class                             \
    {                                                           \
        Cbj_ParentName##Class s;                                \
    } typeName##Class

#define _Cbj_ClassTypeDef_vf(typeName, Cbj_ParentName) \
    typedef struct typeName##Class                              \
    {                                                            \
        Cbj_ParentName##Class s;                                 \
        typeName##VirtFuns vf;                     \
    } typeName##Class

#define _Cbj_ClassTypeDef(typeName, Cbj_ParentName, case) \
    _Cbj_ClassTypeDef_##case (typeName, Cbj_ParentName)

#endif // _CBJ_CLASSTYPEDEF_H
