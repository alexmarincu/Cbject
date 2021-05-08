#ifndef _CBJ_GETOBJECTIMPL_H
#define _CBJ_GETOBJECTIMPL_H
#include "_Cbj_GetObjectFunPrototype.h"

#define _Cbj_GetObjectImpl(typeName)               \
    _Cbj_GetObjectFunPrototype(typeName)           \
    {                                              \
        static typeName pool[typeName##_poolSize]; \
        static uint64 count = 0;                   \
        typeName * me = NULL;                      \
                                                   \
        if (count < typeName##_poolSize)           \
        {                                          \
            me = &pool[count];                     \
            typeName##_init(me, params);           \
            count++;                               \
        }                                          \
                                                   \
        return me;                                 \
    }

#endif // _CBJ_GETOBJECTIMPL_H
