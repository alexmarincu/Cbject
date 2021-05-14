#ifndef _CBJ_TERMINATEFUNIMPL_H
#define _CBJ_TERMINATEFUNIMPL_H
#include "_Cbj_OnTerminateFunPrototype.h"
#include "_Cbj_TerminateFunPrototype.h"

#define _Cbj_TerminateFunImpl(m_cbjType, mParent) \
    _Cbj_OnTerminateFunPrototype(m_cbjType);     \
    _Cbj_TerminateFunPrototype(m_cbjType)        \
    {                                          \
        _##m_cbjType##_onTerminate(me);          \
        mParent##_terminate((mParent *) me);     \
    }                                          \
    _Cbj_OnTerminateFunPrototype(m_cbjType)

#endif // _CBJ_TERMINATEFUNIMPL_H
