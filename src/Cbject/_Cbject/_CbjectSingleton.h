#ifndef _CBJECTSINGLETON_H
#define _CBJECTSINGLETON_H
#include "_CbjectSingletonDeclaration.h"

#define _CbjectSingleton(klassName, superKlassName, params, properties) \
    _CbjectSingletonDeclaration(klassName, superKlassName, params, properties)

#endif // _CBJECTSINGLETON_H
