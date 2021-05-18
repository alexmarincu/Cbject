#ifndef _CBJ_DATACLASS_H
#define _CBJ_DATACLASS_H
#include "_Cbj_DataTypeDef.h"

#define _Cbj_DataClass(cbjType, ...) \
    _Cbj_DataTypeDef(cbjType, __VA_ARGS__)

#endif // _CBJ_DATACLASS_H
