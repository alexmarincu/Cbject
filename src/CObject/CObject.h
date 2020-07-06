#ifndef COBJECT_H
#define COBJECT_H
#include "CObjectUtilities.h"

typedef struct CObject mCObject;
typedef struct CObject const CObject;

Void CObject_init(mCObject Pt me);
mUInt8 CObject_objectSize(CObject Pt me);

#endif // COBJECT_H
