#ifndef COBJECTSUPER_H
#define COBJECTSUPER_H

#include "CObject.h"

typedef struct CObjectClass
{
    UInt8 (*objectSize)(CObject const * const me);
} CObjectClass;

struct CObject
{
    CObjectClass const * klass;
};

UInt8 super_CObject_objectSize(CObject const * const me);

#endif // COBJECTSUPER_H
