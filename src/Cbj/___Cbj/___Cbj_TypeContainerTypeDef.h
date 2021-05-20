#ifndef ___CBJ_TYPECONTAINERTYPEDEF_H
#define ___CBJ_TYPECONTAINERTYPEDEF_H
#include "../Cbj_Settings.h"

#define ___Cbj_TypeContainerTypeDef_withoutVirtFuns(cbjType, parent) \
    typedef union ___##cbjType##Type                                 \
    {                                                                \
        Cbj_Settings_maxAlign ___align;                              \
        char ___data[sizeof(struct { ___##parent##Type super; })];   \
    } ___##cbjType##Type

#define ___Cbj_TypeContainerTypeDef_withVirtFuns(cbjType, parent) \
    typedef union ___##cbjType##Type                              \
    {                                                             \
        Cbj_Settings_maxAlign ___align;                           \
        char ___data[sizeof(struct { ___##parent##Type super; cbjType##VirtFuns virtFuns; })];                         \
    } ___##cbjType##Type

#define ___Cbj_TypeContainerTypeDef(cbjType, parent, case) \
    ___Cbj_TypeContainerTypeDef_##case (cbjType, parent)

#endif // ___CBJ_TYPECONTAINERTYPEDEF_H
