#ifndef COBJECTSUPER_H
#define COBJECTSUPER_H

#include "CObject.h"

typedef struct
{
    _UInt8(Ref objectSize)(CObject me);
} CObjectVT;

struct CObject
{
    CObjectVT const _Ref vT;
    _Boolean isInitialized;
};

#endif // COBJECTSUPER_H
