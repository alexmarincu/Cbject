#ifndef _CBJ_OBJECTINSTANCEIMPL_H
#define _CBJ_OBJECTINSTANCEIMPL_H
#include "_Cbj_ObjectInstanceFunPrototype.h"

#define _Cbj_ObjectInstanceImpl(m_cbjType)                                 \
    _Cbj_ObjectInstanceFunPrototype(m_cbjType)                             \
    {                                                                    \
        static m_cbjType me;                                               \
                                                                         \
        typedef struct _Cbject                                           \
        {                                                                \
            Cbj_Settings_maxAlign x_align;                                     \
            CbjectType * type;                                              \
            CbjectProps props;                                               \
        } _Cbject;                                                       \
                                                                         \
        if (((_Cbject *) &me)->type == NULL) { m_cbjType##_init(&me, NULL); } \
        return &me;                                                      \
    }

#endif // _CBJ_OBJECTINSTANCEIMPL_H
