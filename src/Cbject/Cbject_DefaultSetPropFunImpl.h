#ifndef CBJECT_DEFAULTSETPROPFUNIMPL_H
#define CBJECT_DEFAULTSETPROPFUNIMPL_H
#include "Cbject_SetPropFunPrototype.h"

#define Cbject_DefaultSetPropFunImpl(typeName, fieldType, fieldName) \
    Cbject_SetPropFunPrototype(typeName, fieldType, fieldName) { me->d.fieldName = fieldName; }

#endif // CBJECT_DEFAULTSETPROPFUNIMPL_H
