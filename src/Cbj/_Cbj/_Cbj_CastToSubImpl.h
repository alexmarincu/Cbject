#ifndef _CBJ_CASTTOSUBIMPL_H
#define _CBJ_CASTTOSUBIMPL_H
#include "_Cbj_CastToSubFunPrototype.h"

#define _Cbj_CastToSubImpl(m_cbjType, mParent) \
    _Cbj_CastToSubFunPrototype(m_cbjType, mParent) { return (m_cbjType *) me; }

#endif // _CBJ_CASTTOSUBIMPL_H
