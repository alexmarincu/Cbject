#ifndef COBJECTSUPER_H
#define COBJECTSUPER_H

#include "CObject.h"

typedef struct CObjectVT CObjectVT;

struct CObjectVT
{
    UInt8 (*objectSize)(CObject const * const me);
};

struct CObject
{
    CObjectVT const * vT;
};

UInt8 super_CObject_objectSize(CObject const * const me);

#endif // COBJECTSUPER_H
