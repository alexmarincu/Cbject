#ifndef _CBJ_NEWOBJECTIMPL_H
#define _CBJ_NEWOBJECTIMPL_H
#include "_Cbj_NewObjectFunPrototype.h"

#define _Cbj_NewObjectImpl(cbjType)                              \
    _Cbj_NewObjectFunPrototype(cbjType)                          \
    {                                                            \
        cbjType * me = (cbjType *) malloc(sizeof(cbjType));      \
        assert((me != NULL) && "Heap memory allocation failed"); \
        cbjType##_init(me, params);                              \
        return me;                                               \
    }

#endif // _CBJ_NEWOBJECTIMPL_H
