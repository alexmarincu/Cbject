#ifndef CBJECT_ENUM_H
#define CBJECT_ENUM_H
#include "Cbject_EnumTypeDef.h"

#define Cbject_Enum(typeName, ...) \
    Cbject_EnumTypeDef(typeName, __VA_ARGS__)

#endif // CBJECT_ENUM_H
