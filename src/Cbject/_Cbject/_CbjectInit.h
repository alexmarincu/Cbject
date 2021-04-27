#ifndef _CBJECTINIT_H
#define _CBJECTINIT_H
#include "_CbjectInitFunctionImpl.h"

#define _CbjectInit(klassName, superKlassName, ...) \
    _CbjectInitFunctionImpl(klassName, superKlassName, __VA_ARGS__)

#endif // _CBJECTINIT_H
