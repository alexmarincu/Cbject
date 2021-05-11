#ifndef _CBJ_OBJECTINSTANCEIMPL_H
#define _CBJ_OBJECTINSTANCEIMPL_H
#include "_Cbj_ObjectInstanceFunPrototype.h"

#define _Cbj_ObjectInstanceImpl(cbjType)                                        \
    _Cbj_ObjectInstanceFunPrototype(cbjType)                                    \
    {                                                                           \
        static cbjType me;                                                      \
        if (Cbject_type((Cbject *) &me) == NULL) { cbjType##_init(&me, NULL); } \
        return &me;                                                             \
    }

#endif // _CBJ_OBJECTINSTANCEIMPL_H
