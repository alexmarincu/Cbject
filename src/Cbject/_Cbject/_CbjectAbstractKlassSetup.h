#ifndef _CBJECTABSTRACTKLASSSETUP_H
#define _CBJECTABSTRACTKLASSSETUP_H
#include "_CbjectKlassInstanceImpl.h"
#include "_CbjectSizeImpl.h"
#include "_CbjectTypeDefinition.h"

#define _CbjectAbstractKlassSetup(klassName, superKlassName, ...) \
    _CbjectTypeDefinition(klassName, superKlassName);             \
    _CbjectSizeImpl(klassName);                                   \
    _CbjectKlassInstanceImpl(klassName, superKlassName, __VA_ARGS__)

#endif // _CBJECTABSTRACTKLASSSETUP_H
