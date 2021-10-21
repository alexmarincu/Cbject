#ifndef CBJECT_TERMINATEFUNIMPL_H
#define CBJECT_TERMINATEFUNIMPL_H
#include "Cbject_OnTerminateFunPrototype.h"
#include "Cbject_TerminateFunPrototype.h"

#define Cbject_TerminateFunImpl(cbjType, parent) \
    Cbject_OnTerminateFunPrototype(cbjType);     \
    Cbject_TerminateFunPrototype(cbjType)        \
    {                                            \
        cbjType##_onTerminate(me);               \
        parent##_terminate((parent *) me);       \
    }                                            \
    Cbject_OnTerminateFunPrototype(cbjType)

#endif // CBJECT_TERMINATEFUNIMPL_H
