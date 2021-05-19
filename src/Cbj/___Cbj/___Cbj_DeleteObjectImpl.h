#ifndef ___CBJ_DELETEOBJECTIMPL_H
#define ___CBJ_DELETEOBJECTIMPL_H
#include "___Cbj_DeleteObjectFunPrototype.h"

#define ___Cbj_DeleteObjectImpl(cbjType)     \
    ___Cbj_DeleteObjectFunPrototype(cbjType) \
    {                                        \
        cbjType##_terminate(me);             \
        free(me);                            \
    }

#endif // ___CBJ_DELETEOBJECTIMPL_H
