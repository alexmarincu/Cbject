#ifndef COBJECT_H
#define COBJECT_H

#include "../Primitives.h"
#include "CObjectUtilities.h"

typedef struct CObject _Ref __CObject;
typedef struct CObject Ref _CObject;
typedef struct CObject const Ref CObject;

Void CObject_init(_CObject me);
Void CObject_reset(_CObject me);
_UInt8 CObject_objectSize(CObject me);
_Boolean CObject_isInitialized(CObject me);

#endif // COBJECT_H
