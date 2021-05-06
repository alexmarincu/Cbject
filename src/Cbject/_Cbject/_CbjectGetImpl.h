#ifndef _CBJECTGETIMPL_H
#define _CBJECTGETIMPL_H
#include "_CbjectGetObjectFunPrototype.h"

#define _CbjectGetImpl(cbjectTypeName)                    \
    _CbjectGetObjectFunPrototype(cbjectTypeName)           \
    {                                                \
        static cbjectTypeName pool[cbjectTypeName##_poolSize]; \
        static uint64 count = 0;                     \
        cbjectTypeName * me = NULL;                       \
                                                     \
        if (count < cbjectTypeName##_poolSize)            \
        {                                            \
            me = &pool[count];                       \
            cbjectTypeName##_init(me, params);            \
            count++;                                 \
        }                                            \
                                                     \
        return me;                                   \
    }

#endif // _CBJECTGETIMPL_H
