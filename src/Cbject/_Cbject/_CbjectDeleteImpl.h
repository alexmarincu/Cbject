#ifndef _CBJECTDELETEIMPL_H
#define _CBJECTDELETEIMPL_H
#include "_CbjectDeleteFunPrototype.h"

#define _CbjectDeleteImpl(cbjectTypeName)          \
    _CbjectDeleteFunPrototype(cbjectTypeName) \
    {                                         \
        cbjectTypeName##_terminate(me);            \
        free(me);                             \
    }

#endif // _CBJECTDELETEIMPL_H
