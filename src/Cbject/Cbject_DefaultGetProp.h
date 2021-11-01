#ifndef CBJECT_DEFAULTGETPROP_H
#define CBJECT_DEFAULTGETPROP_H
#include "Cbject_GetPropFun.h"

#define Cbject_DefaultGetProp(typeName, fieldType, fieldName) \
    Cbject_GetPropFun_DefaultImpl(typeName, fieldType, fieldName)

#endif // CBJECT_DEFAULTGETPROP_H
