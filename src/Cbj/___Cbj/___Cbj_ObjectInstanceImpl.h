#ifndef ___CBJ_OBJECTINSTANCEIMPL_H
#define ___CBJ_OBJECTINSTANCEIMPL_H
#include "___Cbj_ObjectInstanceFunPrototype.h"

#define ___Cbj_ObjectInstanceImpl(cbjType)                                         \
    ___Cbj_ObjectInstanceFunPrototype(cbjType)                                     \
    {                                                                              \
        static cbjType me;                                                         \
                                                                                   \
        typedef struct ___Cbject                                                   \
        {                                                                          \
            Cbj_Settings_maxAlign ___align;                                        \
            CbjectType * type;                                                     \
            CbjectProps props;                                                     \
        } ___Cbject;                                                               \
                                                                                   \
        if (((___Cbject *) &me)->type == NULL) { ___##cbjType##_init(&me, NULL); } \
        return &me;                                                                \
    }

#endif // ___CBJ_OBJECTINSTANCEIMPL_H
