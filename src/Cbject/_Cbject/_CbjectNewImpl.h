#ifndef _CBJECTNEWIMPL_H
#define _CBJECTNEWIMPL_H
#include "_CbjectNewFunctionPrototype.h"

#define _CbjectNewImpl(klassName)                                 \
    _CbjectNewFunctionPrototype(klassName)                        \
    {                                                             \
        klassName * me = (klassName *) malloc(sizeof(klassName)); \
        assert((me != null) && "Heap memory allocation failed");  \
        klassName##_ctor(me, params);                             \
        return me;                                                \
    }

#endif // _CBJECTNEWIMPL_H
