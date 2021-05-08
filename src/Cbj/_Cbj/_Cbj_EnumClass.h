#ifndef _CBJ_ENUMCLASS_H
#define _CBJ_ENUMCLASS_H
#include "_Cbj_EnumTypeDef.h"

#define _Cbj_EnumClass(cbjType, ...) \
    _Cbj_EnumTypeDef(cbjType, __VA_ARGS__)

#endif // _CBJ_ENUMCLASS_H
