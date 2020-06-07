#ifndef CObjectBJECT_H
#define CObjectBJECT_H
#include "../Primitives.h"
#include "CObjectUtilities.h"

typedef struct CObject _Ref __CObject;
typedef struct CObject Ref _CObject;
typedef struct CObject const Ref CObject;

_UInt8 CObject_objectSize(CObject me);
_Boolean CObject_isInitialized(CObject me);

#endif // CObjectBJECT_H
