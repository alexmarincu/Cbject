#ifndef _CBJ_VIRTFUNPTR_H
#define _CBJ_VIRTFUNPTR_H
#include "_Cbj_Utils.h"

#define _Cbj_VirtFunPtr_0(m_cbjType, mReturnType, mFunName, ...) \
    mReturnType (*mFunName)(m_cbjType * const me)

#define _Cbj_VirtFunPtr__(m_cbjType, mReturnType, mFunName, ...) \
    mReturnType (*mFunName)(m_cbjType * const me, __VA_ARGS__)

#define _Cbj_VirtFunPtr_case(m_cbjType, mReturnType, mFunName, mCase, ...) \
    _Cbj_VirtFunPtr_##mCase(m_cbjType, mReturnType, mFunName, __VA_ARGS__)

#define _Cbj_VirtFunPtr_(m_cbjType, mReturnType, mFunName, ...) \
    _Cbj_VirtFunPtr_case(m_cbjType, mReturnType, mFunName, __VA_ARGS__)

#define _Cbj_VirtFunPtr(mReturnType, mFunName, mArgs) \
    _Cbj_VirtFunPtr_(Type, mReturnType, mFunName, _Cbj_Utils_stripParentheses(mArgs))

#endif // _CBJ_VIRTFUNPTR_H
