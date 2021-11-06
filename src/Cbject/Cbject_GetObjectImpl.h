#ifndef CBJECT_GETOBJECTIMPL_H
#define CBJECT_GETOBJECTIMPL_H
#include "Cbject_GetObjectFunPrototype.h"
#include "string.h"

#define Cbject_GetObjectImpl(className)              \
    Cbject_GetObjectFunPrototype(className)          \
    {                                                \
        static className pool[className##_poolSize]; \
        static uint64 count = 0;                     \
        className * me = NULL;                       \
                                                     \
        if (count < className##_poolSize)            \
        {                                            \
            me = &pool[count];                       \
            memset(me, 0, sizeof(className));        \
            className##_init(me, params);            \
            count++;                                 \
        }                                            \
                                                     \
        return me;                                   \
    }

#endif // CBJECT_GETOBJECTIMPL_H
