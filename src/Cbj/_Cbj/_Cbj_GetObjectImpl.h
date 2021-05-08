#ifndef _CBJ_GETOBJECTIMPL_H
#define _CBJ_GETOBJECTIMPL_H
#include "_Cbj_GetObjectFunPrototype.h"

#define _Cbj_GetObjectImpl(cbjType)              \
    _Cbj_GetObjectFunPrototype(cbjType)          \
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

#endif // _CBJ_GETOBJECTIMPL_H
