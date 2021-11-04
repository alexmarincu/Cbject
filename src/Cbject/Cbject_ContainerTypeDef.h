#ifndef CBJECT_CONTAINERTYPEDEF_H
#define CBJECT_CONTAINERTYPEDEF_H
#include "Cbject_Settings.h"

#define Cbject_ContainerTypeDef(typeName, superTypeName) \
    typedef union typeName##Container                    \
    {                                                    \
        Cbject_Settings_maxAlign align;                  \
        char container[sizeof(struct                     \
            {                                            \
                superTypeName##Container super;          \
                typeName##Data data;                     \
            })];                                         \
    } typeName##Container

#endif // CBJECT_CONTAINERTYPEDEF_H
