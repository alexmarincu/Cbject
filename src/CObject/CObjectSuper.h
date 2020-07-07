#ifndef COBJECTSUPER_H
#define COBJECTSUPER_H

#include "CObject.h"

typedef struct CObjectVT mCObjectVT;
typedef struct CObjectVT const CObjectVT;

struct CObjectVT
{
    mUInt8(mpt objectSize)(CObject pt me);
};

struct CObject
{
    CObjectVT mpt vT;
};

mUInt8 super_CObject_objectSize(CObject pt me);

#endif // COBJECTSUPER_H
