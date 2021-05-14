#ifndef _CBJ_CASTTOSUBFUNPROTOTYPE_H
#define _CBJ_CASTTOSUBFUNPROTOTYPE_H

#define _Cbj_CastToSubFunPrototype(m_cbjType, mParent) \
    m_cbjType * const mParent##_to##m_cbjType(mParent const * const me)

#endif // _CBJ_CASTTOSUBFUNPROTOTYPE_H
