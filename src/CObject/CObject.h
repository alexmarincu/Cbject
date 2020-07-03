#ifndef COBJECT_H
#define COBJECT_H
#include "CObjectUtilities.h"

typedef struct CObject mPtr mmCObject;
typedef struct CObject Ptr mCObject;
typedef struct CObject const Ptr CObject;

Void CObject_init(mCObject me);
mUInt8 CObject_objectSize(CObject me);

#endif // COBJECT_H
