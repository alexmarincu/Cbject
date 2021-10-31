#ifndef CBJECT_DELETEOBJECTIMPL_H
#define CBJECT_DELETEOBJECTIMPL_H
#include "Cbject_DeleteObjectFunPrototype.h"
#include <stdlib.h>

#define Cbject_DeleteObjectImpl(typeName)     \
    Cbject_DeleteObjectFunPrototype(typeName) \
    {                                         \
        typeName##_terminate(me);             \
        free(me);                             \
    }

#endif // CBJECT_DELETEOBJECTIMPL_H
