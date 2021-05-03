#ifndef _CBJECTTERMINATE_H
#define _CBJECTTERMINATE_H
#include "_CbjectDtorFunImpl.h"

#define _CbjectTerminate(klassName, superKlassName) \
    _CbjectDtorFunImpl(klassName, superKlassName)

#endif // _CBJECTTERMINATE_H
