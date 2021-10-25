#ifndef CBJECT_CONTAINERTYPEDEF_H
#define CBJECT_CONTAINERTYPEDEF_H
#include "Cbject_Settings.h"

#define Cbject_ContainerTypeDef(typeName, parent) \
    typedef union typeName##Container             \
    {                                             \
        Cbject_Settings_maxAlign a;               \
        char c[sizeof(struct                      \
            {                                     \
                parent##Container s;              \
                typeName##Data d;                 \
            })];                                  \
    } typeName##Container

#endif // CBJECT_CONTAINERTYPEDEF_H
