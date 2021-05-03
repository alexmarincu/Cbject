#ifndef _CBJECTSINGLETONSETUP_H
#define _CBJECTSINGLETONSETUP_H
#include "_CbjectInstanceImpl.h"
#include "_CbjectKlassInstanceFunctionPrototype.h"
#include "_CbjectKlassInstanceImpl.h"
#include "_CbjectKlassTypeDefinition.h"
#include "_CbjectSizeImpl.h"
#include "_CbjectTypeDefinition.h"

#define _CbjectSingletonSetup_(klassName, superKlassName, ...) \
    _CbjectTypeDefinition(klassName, superKlassName);          \
    _CbjectKlassTypeDefinition(klassName, superKlassName, 0);  \
    _CbjectKlassInstanceFunctionPrototype(klassName);          \
    _CbjectInstanceImpl(klassName);                            \
    _CbjectSizeImpl(klassName);                                \
    _CbjectKlassInstanceImpl(klassName, superKlassName, __VA_ARGS__)
#define _CbjectSingletonSetup(klassName, superKlassName, ...) _CbjectSingletonSetup_(klassName, superKlassName, __VA_ARGS__)

#endif // _CBJECTSINGLETONSETUP_H
