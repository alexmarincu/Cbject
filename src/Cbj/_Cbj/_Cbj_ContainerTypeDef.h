#ifndef _CBJ_CONTAINERTYPEDEF_H
#define _CBJ_CONTAINERTYPEDEF_H
#include "../Cbj_Settings.h"

#define _Cbj_ContainerTypeDef(cbjType, parent) \
    typedef union _##cbjType                   \
    {                                          \
        Cbj_Settings_maxAlign a;               \
        char d[sizeof(struct { _##parent s; cbjType##Props p; })];            \
    } _##cbjType

#endif // _CBJ_CONTAINERTYPEDEF_H
