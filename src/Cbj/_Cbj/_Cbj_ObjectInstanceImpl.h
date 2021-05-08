#ifndef _CBJ_OBJECTINSTANCEIMPL_H
#define _CBJ_OBJECTINSTANCEIMPL_H
#include "_Cbj_ObjectInstanceFunPrototype.h"

#define _Cbj_ObjectInstanceImpl(typeName)                                             \
    _Cbj_ObjectInstanceFunPrototype(typeName)                                         \
    {                                                                                 \
        static typeName me;                                                           \
        if (Cbj_Base_class((Cbj_Base *) &me) == NULL) { typeName##_init(&me, NULL); } \
        return &me;                                                                   \
    }

#endif // _CBJ_OBJECTINSTANCEIMPL_H
