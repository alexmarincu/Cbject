#ifndef _CBJECTABSTRACTKLASSSETUP_H
#define _CBJECTABSTRACTKLASSSETUP_H
#include "_CbjectAbstractKlassSetupDefinition.h"

#define _CbjectAbstractKlassSetup(klassName, superKlassName, ...) \
    _CbjectAbstractKlassSetupDefinition(klassName, superKlassName, __VA_ARGS__)

#endif // _CBJECTABSTRACTKLASSSETUP_H
