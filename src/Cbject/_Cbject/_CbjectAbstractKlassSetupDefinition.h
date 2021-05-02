#ifndef _CBJECTABSTRACTKLASSSETUPDEFINITION_H
#define _CBJECTABSTRACTKLASSSETUPDEFINITION_H
#include "_CbjectTypeDefinition.h"

#define _CbjectAbstractKlassSetupDefinition(klassName, superKlassName, ...)               \
    _CbjectTypeDefinition(klassName, superKlassName);                                     \
    static uint8 override_Cbject_size(klassName const * const me) { return sizeof(*me); } \
    CbjectPreprocessor_klassInstanceImpl(klassName, superKlassName, __VA_ARGS__)

#endif // _CBJECTABSTRACTKLASSSETUPDEFINITION_H
