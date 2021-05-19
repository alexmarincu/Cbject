#ifndef ___CBJ_TYPETYPEDEF_H
#define ___CBJ_TYPETYPEDEF_H

#define ___Cbj_TypeTypeDef_withoutVirtFuns(cbjType, parent) \
    struct cbjType##Type                                    \
    {                                                       \
        ___##parent##Type s;                                \
    }

#define ___Cbj_TypeTypeDef_withVirtFuns(cbjType, parent) \
    struct cbjType##Type                                 \
    {                                                    \
        ___##parent##Type s;                             \
        cbjType##VirtFuns virtFuns;                      \
    }

#define ___Cbj_TypeTypeDef(cbjType, parent, case) \
    ___Cbj_TypeTypeDef_##case (cbjType, parent)

#endif // ___CBJ_TYPETYPEDEF_H
