#ifndef _CBJ_SUPERFUN_H
#define _CBJ_SUPERFUN_H
#include "_Cbj_SuperFunPrototype.h"

#define _Cbj_SuperFun(m_cbjType, mReturnType, mFunName, ...) \
    _Cbj_SuperFunPrototype(m_cbjType, mReturnType, mFunName, __VA_ARGS__)

#endif // _CBJ_SUPERFUN_H
