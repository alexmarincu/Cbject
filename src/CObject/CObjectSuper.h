#ifndef COBJECTSUPER_H
#define COBJECTSUPER_H

#include "CObject.h"

typedef struct CObjectVT _CObjectVT;
typedef struct CObjectVT const CObjectVT;

struct CObjectVT
{
    _UInt8(_ptr objectSize)(CObject me);
};

struct CObject
{
    CObjectVT _ptr vT;
    _Boolean isInitialized;
};

_UInt8 super_CObject_objectSize(CObject me);

#endif // COBJECTSUPER_H
