#ifndef ___CBJ_DATACLASS_H
#define ___CBJ_DATACLASS_H
#include "___Cbj_DataTypeDef.h"

#define ___Cbj_DataClass(cbjType, ...) \
    ___Cbj_DataTypeDef(cbjType, __VA_ARGS__)

#endif // ___CBJ_DATACLASS_H
