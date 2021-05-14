#ifndef _CBJ_FUN_H
#define _CBJ_FUN_H
#include "_Cbj_FunPrototype.h"

#define _Cbj_Fun(m_cbjType, mReturnType, mFunName, ...) \
    _Cbj_FunPrototype(m_cbjType, mReturnType, mFunName, __VA_ARGS__)

#endif // _CBJ_FUN_H
