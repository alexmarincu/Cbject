#ifndef _CBJ_DATACLASS_H
#define _CBJ_DATACLASS_H
#include "_Cbj_DataTypeDef.h"

#define _Cbj_DataClass(typeName, ...) \
    _Cbj_DataTypeDef(typeName, __VA_ARGS__)

#endif // _CBJ_DATACLASS_H
