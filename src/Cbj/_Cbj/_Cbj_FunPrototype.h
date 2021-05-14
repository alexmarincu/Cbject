#ifndef _CBJ_FUNPROTOTYPE_H
#define _CBJ_FUNPROTOTYPE_H

#define _Cbj_FunPrototype_0(m_cbjType, mReturnType, mFunName, ...) \
    mReturnType m_cbjType##_##mFunName(m_cbjType * const me)

#define _Cbj_FunPrototype__(m_cbjType, mReturnType, mFunName, ...) \
    mReturnType m_cbjType##_##mFunName(m_cbjType * const me, __VA_ARGS__)

#define _Cbj_FunPrototype(m_cbjType, mReturnType, mFunName, mCase, ...) \
    _Cbj_FunPrototype_##mCase (m_cbjType, mReturnType, mFunName, __VA_ARGS__)

#endif // _CBJ_FUNPROTOTYPE_H
