#ifndef _CBJ_CONTAINERTYPEDEF_H
#define _CBJ_CONTAINERTYPEDEF_H
#include "../Cbj_Settings.h"

#define _Cbj_ContainerTypeDef(typeName, Cbj_ParentName) \
    typedef union _##typeName                       \
    {                                               \
        char d[sizeof(struct { _##Cbj_ParentName s; typeName##Props p; })];                 \
        Cbj_Settings_maxAlign a;                    \
    } _##typeName

#endif // _CBJ_CONTAINERTYPEDEF_H
