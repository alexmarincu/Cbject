#ifndef _CBJ_VIRTFUNIMPL_H
#define _CBJ_VIRTFUNIMPL_H
#include "_Cbj_Utils.h"
#include "_Cbj_VirtFunCall.h"

#define _Cbj_VirtFunImpl(m_cbjType, mReturnType, mFunName, mArgs, mParams) \
    Fun(mReturnType, mFunName, mArgs) { _Cbj_VirtFunCall(m_cbjType, mFunName, _Cbj_Utils_stripParentheses(mParams)); }

#endif // _CBJ_VIRTFUNIMPL_H
