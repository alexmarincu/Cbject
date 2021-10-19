#ifndef CBJECT_TYPECONTAINERTYPEDEF_H
#define CBJECT_TYPECONTAINERTYPEDEF_H
#include "Cbject_Settings.h"

#define Cbject_TypeContainerTypeDef_withoutVirtFuns(cbjType, parent) \
    typedef union ___##cbjType##Type                                 \
    {                                                                \
        Cbject_Settings_maxAlign ___align;                           \
        char ___data[sizeof(struct { ___##parent##Type super; })];   \
    } ___##cbjType##Type

#define Cbject_TypeContainerTypeDef_withVirtFuns(cbjType, parent) \
    typedef union ___##cbjType##Type                              \
    {                                                             \
        Cbject_Settings_maxAlign ___align;                        \
        char ___data[sizeof(struct                                \
            {                                                     \
                ___##parent##Type super;                          \
                cbjType##VirtFuns virtFuns;                       \
            })];                                                  \
    } ___##cbjType##Type

#define Cbject_TypeContainerTypeDef(cbjType, parent, case) \
    Cbject_TypeContainerTypeDef_##case (cbjType, parent)

#endif // CBJECT_TYPECONTAINERTYPEDEF_H
