#ifndef CBJECT_CLASSCONTAINERSTRUCT_H
#define CBJECT_CLASSCONTAINERSTRUCT_H
#include "Cbject_Settings.h"

/*
Cbject_ClassContainerStruct
*/
#define Cbject_ClassContainerStruct(class, superClass) \
    typedef union class##Container                     \
    {                                                  \
        Cbject_Settings_maxAlign align;                \
        char container[sizeof(struct                   \
            {                                          \
                superClass##Container super;           \
                class##Data data;                      \
            })];                                       \
    } class##Container

#endif // CBJECT_CLASSCONTAINERSTRUCT_H
