#ifndef CBJECT_TYPETYPEDEF_H
#define CBJECT_TYPETYPEDEF_H

#define Cbject_TypeTypeDef_withoutVirtFuns(typeName, superTypeName) \
    struct typeName##Type                                           \
    {                                                               \
        superTypeName##TypeContainer super;                         \
    }

#define Cbject_TypeTypeDef_withVirtFuns(typeName, superTypeName) \
    struct typeName##Type                                        \
    {                                                            \
        superTypeName##TypeContainer super;                      \
        typeName##VirtFuns virtFuns;                             \
    }

#define Cbject_TypeTypeDef(typeName, superTypeName, case) \
    Cbject_TypeTypeDef_##case (typeName, superTypeName)

#endif // CBJECT_TYPETYPEDEF_H
