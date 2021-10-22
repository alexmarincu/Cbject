#ifndef CBJECT_TYPECONTAINERTYPEDEF_H
#define CBJECT_TYPECONTAINERTYPEDEF_H
#include "Cbject_Settings.h"

#define Cbject_TypeContainerTypeDef_withoutVirtFuns(cbjType, parent) \
    typedef union cbjType##TypeContainer                             \
    {                                                                \
        Cbject_Settings_maxAlign a;                                  \
        char d[sizeof(struct { parent##TypeContainer super; })];     \
    } cbjType##TypeContainer

#define Cbject_TypeContainerTypeDef_withVirtFuns(cbjType, parent) \
    typedef union cbjType##TypeContainer                          \
    {                                                             \
        Cbject_Settings_maxAlign a;                               \
        char d[sizeof(struct                                      \
            {                                                     \
                parent##TypeContainer super;                      \
                cbjType##VirtFuns virtFuns;                       \
            })];                                                  \
    } cbjType##TypeContainer

#define Cbject_TypeContainerTypeDef(cbjType, parent, case) \
    Cbject_TypeContainerTypeDef_##case (cbjType, parent)

#endif // CBJECT_TYPECONTAINERTYPEDEF_H
