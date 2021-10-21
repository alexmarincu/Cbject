#ifndef CBJECT_TERMINATEFUNIMPL_H
#define CBJECT_TERMINATEFUNIMPL_H
#include "Cbject_OnTerminateFunPrototype.h"
#include "Cbject_TerminateFunPrototype.h"

#define Cbject_TerminateFunImpl(cbjType, parent) \
    Cbject_OnTerminateFunPrototype(cbjType);     \
    Cbject_TerminateFunPrototype(cbjType)        \
    {                                            \
        ___##cbjType##_onTerminate(me);          \
        ___##parent##_terminate((parent *) me);  \
    }                                            \
    Cbject_OnTerminateFunPrototype(cbjType)

#endif // CBJECT_TERMINATEFUNIMPL_H
