#ifndef _CBJ_CLASSTYPEDEF_H
#define _CBJ_CLASSTYPEDEF_H

#define _Cbj_ClassTypeDef_0(cbjType, parent) \
    typedef struct cbjType##Class            \
    {                                        \
        parent##Class s;                     \
    } cbjType##Class

#define _Cbj_ClassTypeDef_vf(cbjType, parent) \
    typedef struct cbjType##Class             \
    {                                         \
        parent##Class s;                      \
        cbjType##VirtFuns vf;                 \
    } cbjType##Class

#define _Cbj_ClassTypeDef(cbjType, parent, case) \
    _Cbj_ClassTypeDef_##case (cbjType, parent)

#endif // _CBJ_CLASSTYPEDEF_H
