#ifndef _CBJECTGETIMPL_H
#define _CBJECTGETIMPL_H
#include "_CbjectGetFunctionPrototype.h"

#define _CbjectGetImpl(klassName)                    \
    _CbjectGetFunctionPrototype(klassName)           \
    {                                                \
        static klassName pool[klassName##_poolSize]; \
        static uint64 count = 0;                     \
        klassName * me = null;                       \
                                                     \
        if (count < klassName##_poolSize)            \
        {                                            \
            me = &pool[count];                       \
            klassName##_ctor(me, params);            \
            count++;                                 \
        }                                            \
                                                     \
        return me;                                   \
    }

#endif // _CBJECTGETIMPL_H
