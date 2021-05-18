#ifndef _CBJ_TERMINATEFUNIMPL_H
#define _CBJ_TERMINATEFUNIMPL_H
#include "_Cbj_OnTerminateFunPrototype.h"
#include "_Cbj_TerminateFunPrototype.h"

#define _Cbj_TerminateFunImpl(cbjType, parent) \
    _Cbj_OnTerminateFunPrototype(cbjType);     \
    _Cbj_TerminateFunPrototype(cbjType)        \
    {                                          \
        _##cbjType##_onTerminate(me);          \
        parent##_terminate((parent *) me);     \
    }                                          \
    _Cbj_OnTerminateFunPrototype(cbjType)

#endif // _CBJ_TERMINATEFUNIMPL_H
