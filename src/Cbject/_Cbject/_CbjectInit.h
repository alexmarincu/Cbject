#ifndef _CBJECTINIT_H
#define _CBJECTINIT_H
#include "_CbjectInitImpl.h"

#define _CbjectInit(klassName, superKlassName) \
    _CbjectInitImpl(klassName, superKlassName)

#endif // _CBJECTINIT_H
