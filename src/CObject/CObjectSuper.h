#ifndef COBJECTSUPER_H
#define COBJECTSUPER_H

#include "CObject.h"

typedef struct CObjectVT mCObjectVT;
typedef struct CObjectVT const CObjectVT;

struct CObjectVT
{
    mUInt8(mPtr objectSize)(CObject me);
};

struct CObject
{
    CObjectVT mPtr vT;
};

mUInt8 super_CObject_objectSize(CObject me);

#endif // COBJECTSUPER_H
