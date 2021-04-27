#ifndef _CBJECTABSTRACTKLASS_H
#define _CBJECTABSTRACTKLASS_H
#include "_CbjectAbstractKlassDeclaration.h"

#define _CbjectAbstractKlass(klassName, superKlassName, params, properties, virtualFunctions) \
    _CbjectAbstractKlassDeclaration(klassName, superKlassName, params, properties, virtualFunctions)

#endif // _CBJECTABSTRACTKLASS_H
