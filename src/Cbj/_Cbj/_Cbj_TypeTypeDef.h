#ifndef _CBJ_TYPETYPEDEF_H
#define _CBJ_TYPETYPEDEF_H

#define _Cbj_TypeTypeDef_withoutVirtFuns(cbjType, parent) \
    struct cbjType##Type                                   \
    {                                                       \
        _##parent##Type s;                                 \
    }

#define _Cbj_TypeTypeDef_withVirtFuns(cbjType, parent) \
    struct cbjType##Type                                \
    {                                                    \
        _##parent##Type s;                              \
        cbjType##VirtFuns virtFuns;                     \
    }

#define _Cbj_TypeTypeDef(cbjType, parent, case) \
    _Cbj_TypeTypeDef_##case(cbjType, parent)

#endif // _CBJ_TYPETYPEDEF_H
