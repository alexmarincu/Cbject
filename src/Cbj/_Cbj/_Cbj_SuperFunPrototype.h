#ifndef _CBJ_SUPERFUNPROTOTYPE_H
#define _CBJ_SUPERFUNPROTOTYPE_H

#define _Cbj_SuperFunPrototype_0(m_cbjType, mReturnType, mFunName, ...) \
    mReturnType s_##m_cbjType##_##mFunName(m_cbjType * const me)

#define _Cbj_SuperFunPrototype__(m_cbjType, mReturnType, mFunName, ...) \
    mReturnType s_##m_cbjType##_##mFunName(m_cbjType * const me, __VA_ARGS__)

#define _Cbj_SuperFunPrototype(m_cbjType, mReturnType, mFunName, mCase, ...) \
    _Cbj_SuperFunPrototype_##mCase (m_cbjType, mReturnType, mFunName, __VA_ARGS__)

#endif // _CBJ_SUPERFUNPROTOTYPE_H
