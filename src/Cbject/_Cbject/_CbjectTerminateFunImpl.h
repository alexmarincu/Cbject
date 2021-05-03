#ifndef _CBJECTTERMINATEFUNIMPL_H
#define _CBJECTTERMINATEFUNIMPL_H
#include "_CbjectTerminateFunPrototype.h"
#include "_CbjectOnTerminateFunPrototype.h"

#define _CbjectTerminateFunImpl(klassName, superKlassName) \
    _CbjectOnTerminateFunPrototype(klassName);          \
    _CbjectTerminateFunPrototype(klassName)                \
    {                                                 \
        _##klassName##_onTerminate(me);                 \
        superKlassName##_terminate((superKlassName *) me); \
    }                                                 \
                                                      \
    _CbjectOnTerminateFunPrototype(klassName)

#endif // _CBJECTTERMINATEFUNIMPL_H
