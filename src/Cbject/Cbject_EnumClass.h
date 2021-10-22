#ifndef CBJECT_ENUMCLASS_H
#define CBJECT_ENUMCLASS_H
#include "Cbject_EnumTypeDef.h"

#define Cbject_EnumClass(cbjType, ...) \
    Cbject_EnumTypeDef(cbjType, __VA_ARGS__)

#endif // CBJECT_ENUMCLASS_H
