#ifndef _CBJ_TERMINATEFUNIMPL_H
#define _CBJ_TERMINATEFUNIMPL_H
#include "_Cbj_OnTerminateFunPrototype.h"
#include "_Cbj_TerminateFunPrototype.h"

#define _Cbj_TerminateFunImpl(typeName, Cbj_ParentName) \
    _Cbj_OnTerminateFunPrototype(typeName);         \
    _Cbj_TerminateFunPrototype(typeName)            \
    {                                               \
        _##typeName##_onTerminate(me);              \
        Cbj_ParentName##_terminate((Cbj_ParentName *) me);  \
    }                                               \
    _Cbj_OnTerminateFunPrototype(typeName)

#endif // _CBJ_TERMINATEFUNIMPL_H
