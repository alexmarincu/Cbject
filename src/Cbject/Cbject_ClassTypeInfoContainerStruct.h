#ifndef CBJECT_CLASSTYPEINFOCONTAINERSTRUCT_H
#define CBJECT_CLASSTYPEINFOCONTAINERSTRUCT_H
#include "Cbject_Settings.h"

/*
Cbject_ClassTypeInfoContainerStruct
*/
#define Cbject_ClassTypeInfoContainerStruct_withoutVirtFuns(className, superClassName) \
    typedef union className##TypeContainer                                             \
    {                                                                                  \
        Cbject_Settings_maxAlign align;                                                \
        char container[sizeof(struct { superClassName##TypeContainer super; })];       \
    } className##TypeContainer

#define Cbject_ClassTypeInfoContainerStruct_withVirtFuns(className, superClassName) \
    typedef union className##TypeContainer                                          \
    {                                                                               \
        Cbject_Settings_maxAlign align;                                             \
        char container[sizeof(struct                                                \
            {                                                                       \
                superClassName##TypeContainer super;                                \
                className##VirtFuns virtFuns;                                       \
            })];                                                                    \
    } className##TypeContainer

#define Cbject_ClassTypeInfoContainerStruct(className, superClassName, case) \
    Cbject_ClassTypeInfoContainerStruct_##case (className, superClassName)

#endif // CBJECT_CLASSTYPEINFOCONTAINERSTRUCT_H
