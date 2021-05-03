#ifndef _CBJECTDTORFUNIMPL_H
#define _CBJECTDTORFUNIMPL_H
#include "_CbjectDtorFunPrototype.h"
#include "_CbjectTerminateFunPrototype.h"

#define _CbjectDtorFunImpl(klassName, superKlassName) \
    _CbjectTerminateFunPrototype(klassName);          \
    _CbjectDtorFunPrototype(klassName)                \
    {                                                 \
        _##klassName##_terminate(me);                 \
        superKlassName##_dtor((superKlassName *) me); \
    }                                                 \
                                                      \
    _CbjectTerminateFunPrototype(klassName)

#endif // _CBJECTDTORFUNIMPL_H
