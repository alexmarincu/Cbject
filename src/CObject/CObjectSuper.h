#ifndef COBJECTSUPER_H
#define COBJECTSUPER_H

#include "CObject.h"

typedef struct
{
    _UInt8(ptr objectSize)(CObject me);
} CObjectVT;

struct CObject
{
    CObjectVT const _ptr vT;
    _Boolean isInitialized;
};

_UInt8 super_CObject_objectSize(CObject me);

#endif // COBJECTSUPER_H
