#ifndef _CBJECTTERMINATE_H
#define _CBJECTTERMINATE_H
#include "_CbjectTerminateFunctionImpl.h"

#define _CbjectTerminate(klassName, superKlassName, ...) \
    _CbjectTerminateFunctionImpl(klassName, superKlassName, __VA_ARGS__)

#endif // _CBJECTTERMINATE_H
