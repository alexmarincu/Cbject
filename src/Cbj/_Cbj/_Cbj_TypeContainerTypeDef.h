#ifndef _CBJ_TYPECONTAINERTYPEDEF_H
#define _CBJ_TYPECONTAINERTYPEDEF_H
#include "../Cbj_Settings.h"

#define _Cbj_TypeContainerTypeDef_withoutVirtFuns(cbjType, parent) \
    typedef union _##cbjType##Type                                 \
    {                                                              \
        Cbj_Settings_maxAlign xalign;                             \
        char xdata[sizeof(struct { _##parent##Type s; })];             \
    } _##cbjType##Type

#define _Cbj_TypeContainerTypeDef_withVirtFuns(cbjType, parent) \
    typedef union _##cbjType##Type                              \
    {                                                           \
        Cbj_Settings_maxAlign xalign;                          \
        char xdata[sizeof(struct { _##parent##Type s; cbjType##VirtFuns virtFuns; })];                             \
    } _##cbjType##Type

#define _Cbj_TypeContainerTypeDef(cbjType, parent, case) \
    _Cbj_TypeContainerTypeDef_##case (cbjType, parent)

#endif // _CBJ_TYPECONTAINERTYPEDEF_H
