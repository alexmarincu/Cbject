#ifndef CBJECT_CLASSCONTAINERSTRUCT_H
#define CBJECT_CLASSCONTAINERSTRUCT_H
#include "Cbject_Settings.h"

#define Cbject_ClassContainerStruct(className, superClassName) \
    typedef union className##Container                         \
    {                                                          \
        Cbject_Settings_maxAlign align;                        \
        char container[sizeof(struct                           \
            {                                                  \
                superClassName##Container super;               \
                className##Data data;                          \
            })];                                               \
    } className##Container

#endif // CBJECT_CLASSCONTAINERSTRUCT_H
