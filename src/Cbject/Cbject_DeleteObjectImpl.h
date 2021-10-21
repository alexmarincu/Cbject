#ifndef CBJECT_DELETEOBJECTIMPL_H
#define CBJECT_DELETEOBJECTIMPL_H
#include "Cbject_DeleteObjectFunPrototype.h"

#define Cbject_DeleteObjectImpl(cbjType)     \
    Cbject_DeleteObjectFunPrototype(cbjType) \
    {                                        \
        ___##cbjType##_terminate(me);        \
        free(me);                            \
    }

#endif // CBJECT_DELETEOBJECTIMPL_H
