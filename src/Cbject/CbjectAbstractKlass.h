#ifndef CBJECTABSTRACTKLASS_H
#define CBJECTABSTRACTKLASS_H
#include "CbjectAbstractKlassDeclaration.h"

#define CbjectAbstractKlass(klassName, superKlassName, initParams, properties, virtualFunctions) \
    CbjectAbstractKlassDeclaration(klassName, superKlassName, initParams, properties, virtualFunctions)

#endif // CBJECTABSTRACTKLASS_H
