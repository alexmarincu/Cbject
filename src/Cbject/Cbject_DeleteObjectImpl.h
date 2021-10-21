#ifndef CBJECT_DELETEOBJECTIMPL_H
#define CBJECT_DELETEOBJECTIMPL_H
#include "Cbject_DeleteObjectFunPrototype.h"

#define Cbject_DeleteObjectImpl(cbjType)     \
    Cbject_DeleteObjectFunPrototype(cbjType) \
    {                                        \
        cbjType##_terminate(me);             \
        free(me);                            \
        me = NULL;                           \
    }

#endif // CBJECT_DELETEOBJECTIMPL_H
