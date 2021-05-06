#ifndef _CBJECTNEWIMPL_H
#define _CBJECTNEWIMPL_H
#include "_CbjectNewFunPrototype.h"

#define _CbjectNewImpl(cbjectTypeName)                                 \
    _CbjectNewFunPrototype(cbjectTypeName)                        \
    {                                                             \
        cbjectTypeName * me = (cbjectTypeName *) malloc(sizeof(cbjectTypeName)); \
        assert((me != NULL) && "Heap memory allocation failed");  \
        cbjectTypeName##_init(me, params);                             \
        return me;                                                \
    }

#endif // _CBJECTNEWIMPL_H
