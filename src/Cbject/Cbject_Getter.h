#ifndef CBJECT_GETTER_H
#define CBJECT_GETTER_H
#include "Cbject_GetPropFun.h"

#define Cbject_Getter(typeName, fieldType, fieldName) \
    Cbject_GetPropFun_DefaultImpl(typeName, fieldType, fieldName)

#endif // CBJECT_GETTER_H
