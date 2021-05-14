#ifndef _CBJ_CONTAINERTYPEDEF_H
#define _CBJ_CONTAINERTYPEDEF_H
#include "../Cbj_Settings.h"

#define _Cbj_ContainerTypeDef(m_cbjType, mParent) \
    typedef union _##m_cbjType                   \
    {                                          \
        Cbj_Settings_maxAlign x_align;               \
        char x_data[sizeof(struct { _##mParent s; m_cbjType##Props props; })];            \
    } _##m_cbjType

#endif // _CBJ_CONTAINERTYPEDEF_H
