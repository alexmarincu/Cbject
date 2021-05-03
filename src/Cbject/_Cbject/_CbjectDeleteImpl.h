#ifndef _CBJECTDELETEIMPL_H
#define _CBJECTDELETEIMPL_H
#include "_CbjectDeleteFunctionPrototype.h"

#define _CbjectDeleteImpl(klassName)          \
    _CbjectDeleteFunctionPrototype(klassName) \
    {                                         \
        klassName##_dtor(me);            \
        free(me);                             \
    }

#endif // _CBJECTDELETEIMPL_H
