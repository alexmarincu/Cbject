#ifndef CBJECT_SETTER_H
#define CBJECT_SETTER_H
#include "Cbject_SetPropFun.h"

#define Cbject_Setter(typeName, fieldType, fieldName) \
    Cbject_SetPropFun_DefaultImpl(typeName, fieldType, fieldName)

#endif // CBJECT_SETTER_H
