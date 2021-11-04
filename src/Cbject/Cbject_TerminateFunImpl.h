#ifndef CBJECT_TERMINATEFUNIMPL_H
#define CBJECT_TERMINATEFUNIMPL_H
#include "Cbject_OnTerminateFunPrototype.h"
#include "Cbject_TerminateFunPrototype.h"

#define Cbject_TerminateFunImpl(typeName, superTypeName) \
    Cbject_OnTerminateFunPrototype(typeName);            \
    Cbject_TerminateFunPrototype(typeName)               \
    {                                                    \
        typeName##_onTerminate(me);                      \
        superTypeName##_terminate((superTypeName *)me);  \
    }                                                    \
    Cbject_OnTerminateFunPrototype(typeName)

#endif // CBJECT_TERMINATEFUNIMPL_H
