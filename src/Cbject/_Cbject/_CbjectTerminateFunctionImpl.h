#ifndef _CBJECTTERMINATEFUNCTIONIMPL_H
#define _CBJECTTERMINATEFUNCTIONIMPL_H
#include "_CbjectTerminateFunctionPrototype.h"

#define _CbjectTerminateFunctionImpl(klassName, superKlassName, ...) \
    _CbjectTerminateFunctionPrototype(klassName)                     \
    {                                                                \
        do                                                           \
            __VA_ARGS__                                              \
        while (0);                                                   \
                                                                     \
        superKlassName##_terminate((superKlassName * const) me);     \
    }

#endif // _CBJECTTERMINATEFUNCTIONIMPL_H
