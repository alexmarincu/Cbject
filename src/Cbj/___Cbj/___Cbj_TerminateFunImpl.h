#ifndef ___CBJ_TERMINATEFUNIMPL_H
#define ___CBJ_TERMINATEFUNIMPL_H
#include "___Cbj_OnTerminateFunPrototype.h"
#include "___Cbj_TerminateFunPrototype.h"

#define ___Cbj_TerminateFunImpl(cbjType, parent) \
    ___Cbj_OnTerminateFunPrototype(cbjType);     \
    ___Cbj_TerminateFunPrototype(cbjType)        \
    {                                            \
        ___##cbjType##_onTerminate(me);          \
        parent##_terminate((parent *) me);       \
    }                                            \
    ___Cbj_OnTerminateFunPrototype(cbjType)

#endif // ___CBJ_TERMINATEFUNIMPL_H
