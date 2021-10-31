#ifndef CBJECT_DEFAULTSETPROP_H
#define CBJECT_DEFAULTSETPROP_H
#include "Cbject_DefaultSetPropFunImpl.h"

#define Cbject_DefaultSetProp(typeName, fieldType, fieldName) \
    Cbject_DefaultSetPropFunImpl(typeName, fieldType, fieldName)

#endif // CBJECT_DEFAULTSETPROP_H
