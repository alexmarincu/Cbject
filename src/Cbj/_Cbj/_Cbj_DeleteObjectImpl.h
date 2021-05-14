#ifndef _CBJ_DELETEOBJECTIMPL_H
#define _CBJ_DELETEOBJECTIMPL_H
#include "_Cbj_DeleteObjectFunPrototype.h"

#define _Cbj_DeleteObjectImpl(m_cbjType)     \
    _Cbj_DeleteObjectFunPrototype(m_cbjType) \
    {                                      \
        m_cbjType##_terminate(me);           \
        free(me);                          \
    }

#endif // _CBJ_DELETEOBJECTIMPL_H
