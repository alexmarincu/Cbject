#ifndef CBJECT_CONTAINERTYPEDEF_H
#define CBJECT_CONTAINERTYPEDEF_H
#include "Cbject_Settings.h"

#define Cbject_ContainerTypeDef(cbjType, parent) \
    typedef union cbjType##Container             \
    {                                            \
        Cbject_Settings_maxAlign a;              \
        char d[sizeof(struct                     \
            {                                    \
                parent##Container super;         \
                cbjType##Props props;            \
            })];                                 \
    } cbjType##Container

#endif // CBJECT_CONTAINERTYPEDEF_H
