#ifndef CBJECT_GETOBJECTIMPL_H
#define CBJECT_GETOBJECTIMPL_H
#include "Cbject_GetObjectFunPrototype.h"
#include "string.h"

#define Cbject_GetObjectImpl(typeName)             \
    Cbject_GetObjectFunPrototype(typeName)         \
    {                                              \
        static typeName pool[typeName##_poolSize]; \
        static uint64 count = 0;                   \
        typeName * me = NULL;                      \
                                                   \
        if (count < typeName##_poolSize)           \
        {                                          \
            me = &pool[count];                     \
            memset(me, 0, sizeof(typeName));       \
            typeName##_init(me, params);           \
            count++;                               \
        }                                          \
                                                   \
        return me;                                 \
    }

#endif // CBJECT_GETOBJECTIMPL_H
