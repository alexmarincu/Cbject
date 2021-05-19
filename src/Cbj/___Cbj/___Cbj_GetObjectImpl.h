#ifndef ___CBJ_GETOBJECTIMPL_H
#define ___CBJ_GETOBJECTIMPL_H
#include "___Cbj_GetObjectFunPrototype.h"

#define ___Cbj_GetObjectImpl(cbjType)            \
    ___Cbj_GetObjectFunPrototype(cbjType)        \
    {                                            \
        static cbjType pool[cbjType##_poolSize]; \
        static uint64 count = 0;                 \
        cbjType * me = NULL;                     \
                                                 \
        if (count < cbjType##_poolSize)          \
        {                                        \
            me = &pool[count];                   \
            cbjType##_init(me, params);          \
            count++;                             \
        }                                        \
                                                 \
        return me;                               \
    }

#endif // ___CBJ_GETOBJECTIMPL_H
