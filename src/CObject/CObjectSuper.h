#ifndef CObjectBJECTSUPER_H
#define CObjectBJECTSUPER_H
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

Void CObject_init(_CObject me);
Void CObject_reset(_CObject me);

#endif // CObjectBJECTSUPER_H
