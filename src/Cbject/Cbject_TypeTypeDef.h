#ifndef CBJECT_TYPETYPEDEF_H
#define CBJECT_TYPETYPEDEF_H

#define Cbject_TypeTypeDef_withoutVirtFuns(typeName, parent) \
    struct typeName##Type                                    \
    {                                                        \
        parent##TypeContainer s;                             \
    }

#define Cbject_TypeTypeDef_withVirtFuns(typeName, parent) \
    struct typeName##Type                                 \
    {                                                     \
        parent##TypeContainer s;                          \
        typeName##VirtFuns vf;                            \
    }

#define Cbject_TypeTypeDef(typeName, parent, case) \
    Cbject_TypeTypeDef_##case (typeName, parent)

#endif // CBJECT_TYPETYPEDEF_H
