#ifndef CBJECT_SETPROP_H
#define CBJECT_SETPROP_H
#include "Cbject_SetPropFun.h"

#define Cbject_SetProp(typeName, fieldType, fieldName) \
    Cbject_SetPropFun_Prototype(typeName, fieldType, fieldName)

#endif // CBJECT_SETPROP_H
