#ifndef _CBJ_CASTTOSUPERIMPL_H
#define _CBJ_CASTTOSUPERIMPL_H
#include "_Cbj_CastToSuperFunPrototype.h"

#define _Cbj_CastToSuperImpl(m_cbjType, mParent) \
    _Cbj_CastToSuperFunPrototype(m_cbjType, mParent) { return (mParent *) me; }

#endif // _CBJ_CASTTOSUPERIMPL_H
