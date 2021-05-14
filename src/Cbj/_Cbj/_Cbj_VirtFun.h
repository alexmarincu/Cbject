#ifndef _CBJ_VIRTFUN_H
#define _CBJ_VIRTFUN_H
#include "_Cbj_VirtFunImpl.h"

#define _Cbj_VirtFun(m_cbjType, mReturnType, mFunName, mArgs, mParams) \
    _Cbj_VirtFunImpl(m_cbjType, mReturnType, mFunName, mArgs, mParams)

#endif // _CBJ_VIRTFUN_H
