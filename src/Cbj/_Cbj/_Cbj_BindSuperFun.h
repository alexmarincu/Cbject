#ifndef _CBJ_BINDSUPERFUN_H
#define _CBJ_BINDSUPERFUN_H
#include "_Cbj_Utils.h"

#define _Cbj_BindSuperFun_0(m_cbjType, mParent, mReturnType, mFunName, ...) \
    mParent##Type_virtFuns((mParent##Type *) &type)->mFunName = (mReturnType(*)(mParent * const me)) s_##m_cbjType##_##mFunName

#define _Cbj_BindSuperFun__(m_cbjType, mParent, mReturnType, mFunName, ...) \
    mParent##Type_virtFuns((mParent##Type *) &type)->mFunName = (mReturnType(*)(mParent * const me, __VA_ARGS__)) s_##m_cbjType##_##mFunName

#define _Cbj_BindSuperFun_case(m_cbjType, mParent, mReturnType, mFunName, mCase, ...) \
    _Cbj_BindSuperFun_##mCase(m_cbjType, mParent, mReturnType, mFunName, __VA_ARGS__)

#define _Cbj_BindSuperFun_(m_cbjType, mParent, mReturnType, mFunName, ...) \
    _Cbj_BindSuperFun_case(m_cbjType, mParent, mReturnType, mFunName, __VA_ARGS__)

#define _Cbj_BindSuperFun(mParent, mReturnType, mFunName, mArgs) \
    _Cbj_BindSuperFun_(Type, mParent, mReturnType, mFunName, _Cbj_Utils_stripParentheses(mArgs))

#endif // _CBJ_BINDSUPERFUN_H
