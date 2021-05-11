#ifndef _CBJ_TYPETYPEDEF_H
#define _CBJ_TYPETYPEDEF_H

#define _Cbj_TypeTypeDef_0(cbjType, parent) \
    typedef struct cbjType##Type            \
    {                                       \
        parent##Type s;                     \
    } cbjType##Type

#define _Cbj_TypeTypeDef_vf(cbjType, parent) \
    typedef struct cbjType##Type             \
    {                                        \
        parent##Type s;                      \
        cbjType##VirtFuns vf;                \
    } cbjType##Type

#define _Cbj_TypeTypeDef(cbjType, parent, case) \
    _Cbj_TypeTypeDef_##case (cbjType, parent)

#endif // _CBJ_TYPETYPEDEF_H
