#ifndef CBJECT_CONTAINERTYPEDEF_H
#define CBJECT_CONTAINERTYPEDEF_H
#include "Cbject_Settings.h"

#define Cbject_ContainerTypeDef(cbjType, parent) \
    typedef union ___##cbjType                   \
    {                                            \
        Cbject_Settings_maxAlign ___align;       \
        char ___data[sizeof(struct               \
            {                                    \
                ___##parent super;               \
                cbjType##Props props;            \
            })];                                 \
    } ___##cbjType

#endif // CBJECT_CONTAINERTYPEDEF_H
