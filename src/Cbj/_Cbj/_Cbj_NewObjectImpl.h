#ifndef _CBJ_NEWOBJECTIMPL_H
#define _CBJ_NEWOBJECTIMPL_H
#include "_Cbj_NewObjectFunPrototype.h"

#define _Cbj_NewObjectImpl(m_cbjType)                              \
    _Cbj_NewObjectFunPrototype(m_cbjType)                          \
    {                                                            \
        m_cbjType * me = (m_cbjType *) malloc(sizeof(m_cbjType));      \
        assert((me != NULL) && "Heap memory allocation failed"); \
        m_cbjType##_init(me, params);                              \
        return me;                                               \
    }

#endif // _CBJ_NEWOBJECTIMPL_H
