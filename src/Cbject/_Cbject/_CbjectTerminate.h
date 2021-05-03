#ifndef _CBJECTTERMINATE_H
#define _CBJECTTERMINATE_H
#include "_CbjectTerminateFunImpl.h"

#define _CbjectTerminate(klassName, superKlassName) \
    _CbjectTerminateFunImpl(klassName, superKlassName)

#endif // _CBJECTTERMINATE_H
