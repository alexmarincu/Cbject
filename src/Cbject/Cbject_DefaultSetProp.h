#ifndef CBJECT_DEFAULTSETPROP_H
#define CBJECT_DEFAULTSETPROP_H
#include "Cbject_SetPropFun.h"

#define Cbject_DefaultSetProp(typeName, fieldType, fieldName) \
    Cbject_SetPropFun_DefaultImpl(typeName, fieldType, fieldName)

#endif // CBJECT_DEFAULTSETPROP_H
