#ifndef _CBJECTKLASS_H
#define _CBJECTKLASS_H
#include "_CbjectKlassDeclaration.h"

#define _CbjectKlass(klassName, superKlassName, params, properties, virtualFunctions) \
    _CbjectKlassDeclaration(klassName, superKlassName, params, properties, virtualFunctions)

#endif // _CBJECTKLASS_H
