#ifndef CBJECT_CLASSCONTAINERSTRUCT_H
#define CBJECT_CLASSCONTAINERSTRUCT_H
#include "Cbject_Settings.h"

#define Cbject_ClassContainerStruct(typeName, superTypeName) \
    typedef union typeName##Container                        \
    {                                                        \
        Cbject_Settings_maxAlign align;                      \
        char container[sizeof(struct                         \
            {                                                \
                superTypeName##Container super;              \
                typeName##Data data;                         \
            })];                                             \
    } typeName##Container

#endif // CBJECT_CLASSCONTAINERSTRUCT_H
