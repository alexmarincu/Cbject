#ifndef _CBJ_GETOBJECTIMPL_H
#define _CBJ_GETOBJECTIMPL_H
#include "_Cbj_GetObjectFunPrototype.h"

#define _Cbj_GetObjectImpl(m_cbjType)              \
    _Cbj_GetObjectFunPrototype(m_cbjType)          \
    {                                            \
        static m_cbjType pool[m_cbjType##_poolSize]; \
        static uint64 count = 0;                 \
        m_cbjType * me = NULL;                     \
                                                 \
        if (count < m_cbjType##_poolSize)          \
        {                                        \
            me = &pool[count];                   \
            m_cbjType##_init(me, params);          \
            count++;                             \
        }                                        \
                                                 \
        return me;                               \
    }

#endif // _CBJ_GETOBJECTIMPL_H
