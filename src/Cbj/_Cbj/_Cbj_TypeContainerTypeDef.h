#ifndef _CBJ_TYPECONTAINERTYPEDEF_H
#define _CBJ_TYPECONTAINERTYPEDEF_H
#include "../Cbj_Settings.h"

#define _Cbj_TypeContainerTypeDef_withoutVirtFuns(m_cbjType, mParent) \
    typedef union _##m_cbjType##Type                                 \
    {                                                              \
        Cbj_Settings_maxAlign x_align;                             \
        char x_data[sizeof(struct { _##mParent##Type s; })];             \
    } _##m_cbjType##Type

#define _Cbj_TypeContainerTypeDef_withVirtFuns(m_cbjType, mParent) \
    typedef union _##m_cbjType##Type                              \
    {                                                           \
        Cbj_Settings_maxAlign x_align;                          \
        char x_data[sizeof(struct { _##mParent##Type s; m_cbjType##VirtFuns virtFuns; })];                             \
    } _##m_cbjType##Type

#define _Cbj_TypeContainerTypeDef(m_cbjType, mParent, mCase) \
    _Cbj_TypeContainerTypeDef_##mCase (m_cbjType, mParent)

#endif // _CBJ_TYPECONTAINERTYPEDEF_H
