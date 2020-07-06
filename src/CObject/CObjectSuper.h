#ifndef COBJECTSUPER_H
#define COBJECTSUPER_H

#include "CObject.h"

typedef struct CObjectVT mCObjectVT;
typedef struct CObjectVT const CObjectVT;

struct CObjectVT
{
    mUInt8(mPt objectSize)(CObject Pt me);
};

struct CObject
{
    CObjectVT mPt vT;
};

mUInt8 super_CObject_objectSize(CObject Pt me);

#endif // COBJECTSUPER_H
