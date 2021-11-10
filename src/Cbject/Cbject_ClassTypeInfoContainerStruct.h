#ifndef CBJECT_CLASSTYPEINFOCONTAINERSTRUCT_H
#define CBJECT_CLASSTYPEINFOCONTAINERSTRUCT_H
#include "Cbject_Settings.h"

/*
Cbject_ClassTypeInfoContainerStruct
*/
#define Cbject_ClassTypeInfoContainerStruct_caseNA(class, superClass)        \
    typedef union class##TypeContainer                                       \
    {                                                                        \
        Cbject_Settings_maxAlign align;                                      \
        char container[sizeof(struct { superClass##TypeContainer super; })]; \
    } class##TypeContainer

#define Cbject_ClassTypeInfoContainerStruct_caseVirtFuns(class, superClass) \
    typedef union class##TypeContainer                                      \
    {                                                                       \
        Cbject_Settings_maxAlign align;                                     \
        char container[sizeof(struct                                        \
            {                                                               \
                superClass##TypeContainer super;                            \
                class##VirtFuns virtFuns;                                   \
            })];                                                            \
    } class##TypeContainer

#define Cbject_ClassTypeInfoContainerStruct_x1(class, superClass, virtFunsCase, ...) \
    Cbject_ClassTypeInfoContainerStruct_case##virtFunsCase(class, superClass)

#define Cbject_ClassTypeInfoContainerStruct_x0(class, superClass, ...) \
    Cbject_ClassTypeInfoContainerStruct_x1(class, superClass, __VA_ARGS__)

#define Cbject_ClassTypeInfoContainerStruct(class, superClass, virtFunsPack) \
    Cbject_ClassTypeInfoContainerStruct_x0(class, superClass, Cbject_Utils_unpack(virtFunsPack))

#endif // CBJECT_CLASSTYPEINFOCONTAINERSTRUCT_H
