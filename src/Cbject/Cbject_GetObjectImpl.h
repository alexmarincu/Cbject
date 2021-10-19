#ifndef CBJECT_GETOBJECTIMPL_H
#define CBJECT_GETOBJECTIMPL_H
#include "Cbject_GetObjectFunPrototype.h"
#include "string.h"

#define Cbject_GetObjectImpl(cbjType)            \
    Cbject_GetObjectFunPrototype(cbjType)        \
    {                                            \
        static cbjType pool[cbjType##_poolSize]; \
        static uint64 count = 0;                 \
        cbjType * me = NULL;                     \
                                                 \
        if (count < cbjType##_poolSize)          \
        {                                        \
            me = &pool[count];                   \
            memset(me, 0, sizeof(cbjType));      \
            ___##cbjType##_init(me, params);     \
            count++;                             \
        }                                        \
                                                 \
        return me;                               \
    }

#endif // CBJECT_GETOBJECTIMPL_H
