#ifndef _CBJ_NEWOBJECTIMPL_H
#define _CBJ_NEWOBJECTIMPL_H
#include "_Cbj_NewObjectFunPrototype.h"

#define _Cbj_NewObjectImpl(typeName)                             \
    _Cbj_NewObjectFunPrototype(typeName)                         \
    {                                                            \
        typeName * me = (typeName *) malloc(sizeof(typeName));   \
        assert((me != NULL) && "Heap memory allocation failed"); \
        typeName##_init(me, params);                             \
        return me;                                               \
    }

#endif // _CBJ_NEWOBJECTIMPL_H
