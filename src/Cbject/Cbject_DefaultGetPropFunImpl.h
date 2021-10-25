#ifndef CBJECT_DEFAULTGETPROPFUNIMPL_H
#define CBJECT_DEFAULTGETPROPFUNIMPL_H
#include "Cbject_GetPropFunPrototype.h"

#define Cbject_DefaultGetPropFunImpl(typeName, fieldType, fieldName) \
    Cbject_GetPropFunPrototype(typeName, fieldType, fieldName) { return me->d.fieldName; }

#endif // CBJECT_DEFAULTGETPROPFUNIMPL_H
