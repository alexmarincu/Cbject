#ifndef CBJECT_TYPECONTAINERTYPEDEF_H
#define CBJECT_TYPECONTAINERTYPEDEF_H
#include "Cbject_Settings.h"

#define Cbject_TypeContainerTypeDef_withoutVirtFuns(typeName, superTypeName)    \
    typedef union typeName##TypeContainer                                       \
    {                                                                           \
        Cbject_Settings_maxAlign align;                                         \
        char container[sizeof(struct { superTypeName##TypeContainer super; })]; \
    } typeName##TypeContainer

#define Cbject_TypeContainerTypeDef_withVirtFuns(typeName, superTypeName) \
    typedef union typeName##TypeContainer                                 \
    {                                                                     \
        Cbject_Settings_maxAlign align;                                   \
        char container[sizeof(struct                                      \
            {                                                             \
                superTypeName##TypeContainer super;                       \
                typeName##VirtFuns virtFuns;                              \
            })];                                                          \
    } typeName##TypeContainer

#define Cbject_TypeContainerTypeDef(typeName, superTypeName, case) \
    Cbject_TypeContainerTypeDef_##case (typeName, superTypeName)

#endif // CBJECT_TYPECONTAINERTYPEDEF_H
