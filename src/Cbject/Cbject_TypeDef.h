#ifndef CBJECT_TYPEDEF_H
#define CBJECT_TYPEDEF_H

#define Cbject_TypeDef(typeName, superTypeName) \
    struct typeName                             \
    {                                           \
        superTypeName##Container super;         \
        typeName##Data data;                    \
    }

#endif // CBJECT_TYPEDEF_H
