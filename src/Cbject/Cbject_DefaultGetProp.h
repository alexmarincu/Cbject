#ifndef CBJECT_DEFAULTGETPROP_H
#define CBJECT_DEFAULTGETPROP_H
#include "Cbject_DefaultGetPropFunImpl.h"

#define Cbject_DefaultGetProp(typeName, fieldType, fieldName) \
    Cbject_DefaultGetPropFunImpl(typeName, fieldType, fieldName)

#endif // CBJECT_DEFAULTGETPROP_H
