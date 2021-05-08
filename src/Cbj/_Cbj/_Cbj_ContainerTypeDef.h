#ifndef _CBJ_CONTAINERTYPEDEF_H
#define _CBJ_CONTAINERTYPEDEF_H
#include "../Cbj_Settings.h"

#define _Cbj_ContainerTypeDef(cbjType, parent) \
    typedef union _##cbjType                   \
    {                                          \
        char d[sizeof(struct { _##parent s; cbjType##Props p; })];            \
        Cbj_Settings_maxAlign a;               \
    } _##cbjType

#endif // _CBJ_CONTAINERTYPEDEF_H
