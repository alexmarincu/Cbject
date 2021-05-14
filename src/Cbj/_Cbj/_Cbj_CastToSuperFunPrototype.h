#ifndef _CBJ_CASTTOSUPERFUNPROTOTYPE_H
#define _CBJ_CASTTOSUPERFUNPROTOTYPE_H

#define _Cbj_CastToSuperFunPrototype(m_cbjType, mParent) \
    mParent * const m_cbjType##_to##mParent(m_cbjType const * const me)

#endif // _CBJ_CASTTOSUPERFUNPROTOTYPE_H
