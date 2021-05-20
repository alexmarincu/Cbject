#ifndef ___CBJ_NEWOBJECTIMPL_H
#define ___CBJ_NEWOBJECTIMPL_H
#include "___Cbj_NewObjectFunPrototype.h"

#define ___Cbj_NewObjectImpl(cbjType)                            \
    ___Cbj_NewObjectFunPrototype(cbjType)                        \
    {                                                            \
        cbjType * me = (cbjType *) malloc(sizeof(cbjType));      \
        assert((me != NULL) && "Heap memory allocation failed"); \
        memset(me, 0, sizeof(cbjType));                          \
        ___##cbjType##_init(me, params);                         \
        return me;                                               \
    }

#endif // ___CBJ_NEWOBJECTIMPL_H
