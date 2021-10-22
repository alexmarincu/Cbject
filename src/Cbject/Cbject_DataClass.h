#ifndef CBJECT_DATACLASS_H
#define CBJECT_DATACLASS_H
#include "Cbject_DataTypeDef.h"

#define Cbject_DataClass(cbjType, ...) \
    Cbject_DataTypeDef(cbjType, __VA_ARGS__)

#endif // CBJECT_DATACLASS_H
