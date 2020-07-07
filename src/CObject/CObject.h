#ifndef COBJECT_H
#define COBJECT_H
#include "CObjectUtilities.h"

typedef struct CObject mCObject;
typedef struct CObject const CObject;

Void CObject_init(mCObject pt me);
mUInt8 CObject_objectSize(CObject pt me);

#endif // COBJECT_H
