#ifndef CBJECT_GETPROP_H
#define CBJECT_GETPROP_H
#include "Cbject_GetPropFun.h"

#define Cbject_GetProp(typeName, fieldType, fieldName) \
    Cbject_GetPropFun_Prototype(typeName, fieldType, fieldName)

#endif // CBJECT_GETPROP_H
