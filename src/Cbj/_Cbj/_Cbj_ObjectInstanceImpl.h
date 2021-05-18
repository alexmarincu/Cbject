#ifndef _CBJ_OBJECTINSTANCEIMPL_H
#define _CBJ_OBJECTINSTANCEIMPL_H
#include "_Cbj_ObjectInstanceFunPrototype.h"

#define _Cbj_ObjectInstanceImpl(cbjType)                                 \
    _Cbj_ObjectInstanceFunPrototype(cbjType)                             \
    {                                                                    \
        static cbjType me;                                               \
                                                                         \
        typedef struct _Cbject                                           \
        {                                                                \
            Cbj_Settings_maxAlign xalign;                                     \
            CbjectType * type;                                              \
            CbjectProps props;                                               \
        } _Cbject;                                                       \
                                                                         \
        if (((_Cbject *) &me)->type == NULL) { cbjType##_init(&me, NULL); } \
        return &me;                                                      \
    }

#endif // _CBJ_OBJECTINSTANCEIMPL_H
