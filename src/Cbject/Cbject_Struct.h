#ifndef CBJECT_STRUCT_H
#define CBJECT_STRUCT_H
#include "Cbject_StructTypeDef.h"

#define Cbject_Struct(typeName, ...) \
    Cbject_StructTypeDef(typeName, __VA_ARGS__)

#endif // CBJECT_STRUCT_H
