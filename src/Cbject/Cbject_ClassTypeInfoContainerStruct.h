#ifndef CBJECT_CLASSTYPEINFOCONTAINERSTRUCT_H
#define CBJECT_CLASSTYPEINFOCONTAINERSTRUCT_H
#include "Cbject_Settings.h"

#define Cbject_ClassTypeInfoContainerStruct_withoutVirtFuns(typeName, superTypeName) \
    typedef union typeName##TypeContainer                                            \
    {                                                                                \
        Cbject_Settings_maxAlign align;                                              \
        char container[sizeof(struct { superTypeName##TypeContainer super; })];      \
    } typeName##TypeContainer

#define Cbject_ClassTypeInfoContainerStruct_withVirtFuns(typeName, superTypeName) \
    typedef union typeName##TypeContainer                                         \
    {                                                                             \
        Cbject_Settings_maxAlign align;                                           \
        char container[sizeof(struct                                              \
            {                                                                     \
                superTypeName##TypeContainer super;                               \
                typeName##VirtFuns virtFuns;                                      \
            })];                                                                  \
    } typeName##TypeContainer

#define Cbject_ClassTypeInfoContainerStruct(typeName, superTypeName, case) \
    Cbject_ClassTypeInfoContainerStruct_##case (typeName, superTypeName)

#endif // CBJECT_CLASSTYPEINFOCONTAINERSTRUCT_H
