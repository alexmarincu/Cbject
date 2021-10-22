#ifndef CBJECT_TYPETYPEDEF_H
#define CBJECT_TYPETYPEDEF_H

#define Cbject_TypeTypeDef_withoutVirtFuns(cbjType, parent) \
    struct cbjType##Type                                    \
    {                                                       \
        parent##TypeContainer super;                        \
    }

#define Cbject_TypeTypeDef_withVirtFuns(cbjType, parent) \
    struct cbjType##Type                                 \
    {                                                    \
        parent##TypeContainer super;                     \
        cbjType##VirtFuns virtFuns;                      \
    }

#define Cbject_TypeTypeDef(cbjType, parent, case) \
    Cbject_TypeTypeDef_##case (cbjType, parent)

#endif // CBJECT_TYPETYPEDEF_H
