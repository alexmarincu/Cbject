#ifndef _CBJECTINSTANCEIMPL_H
#define _CBJECTINSTANCEIMPL_H
#include "_CbjectInstanceFunctionPrototype.h"

#define _CbjectInstanceImpl(klassName)                                             \
    _CbjectInstanceFunctionPrototype(klassName)                                    \
    {                                                                              \
        static klassName me;                                                       \
        if (Cbject_klass((Cbject *) &me) == null) { klassName##_ctor(&me, null); } \
        return &me;                                                                \
    }

#endif // _CBJECTINSTANCEIMPL_H
