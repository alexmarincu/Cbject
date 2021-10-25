#ifndef CBJECT_TYPECONTAINERTYPEDEF_H
#define CBJECT_TYPECONTAINERTYPEDEF_H
#include "Cbject_Settings.h"

#define Cbject_TypeContainerTypeDef_withoutVirtFuns(typeName, parent) \
    typedef union typeName##TypeContainer                             \
    {                                                                 \
        Cbject_Settings_maxAlign a;                                   \
        char c[sizeof(struct { parent##TypeContainer s; })];          \
    } typeName##TypeContainer

#define Cbject_TypeContainerTypeDef_withVirtFuns(typeName, parent) \
    typedef union typeName##TypeContainer                          \
    {                                                              \
        Cbject_Settings_maxAlign a;                                \
        char c[sizeof(struct                                       \
            {                                                      \
                parent##TypeContainer s;                           \
                typeName##VirtFuns vf;                             \
            })];                                                   \
    } typeName##TypeContainer

#define Cbject_TypeContainerTypeDef(typeName, parent, case) \
    Cbject_TypeContainerTypeDef_##case (typeName, parent)

#endif // CBJECT_TYPECONTAINERTYPEDEF_H
