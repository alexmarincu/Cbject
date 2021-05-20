#ifndef ___CBJ_CONTAINERTYPEDEF_H
#define ___CBJ_CONTAINERTYPEDEF_H
#include "../Cbj_Settings.h"

#define ___Cbj_ContainerTypeDef(cbjType, parent) \
    typedef union ___##cbjType                   \
    {                                            \
        Cbj_Settings_maxAlign ___align;          \
        char ___data[sizeof(struct { ___##parent super; cbjType##Props props; })];        \
    } ___##cbjType

#endif // ___CBJ_CONTAINERTYPEDEF_H
