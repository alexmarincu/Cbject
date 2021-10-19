#ifndef CBJECT_OBJECTINSTANCEIMPL_H
#define CBJECT_OBJECTINSTANCEIMPL_H
#include "Cbject_ObjectInstanceFunPrototype.h"

#define Cbject_ObjectInstanceImpl(cbjType)                                         \
    Cbject_ObjectInstanceFunPrototype(cbjType)                                     \
    {                                                                              \
        static cbjType me;                                                         \
                                                                                   \
        typedef struct ___Cbject                                                   \
        {                                                                          \
            Cbject_Settings_maxAlign ___align;                                        \
            CbjectType * type;                                                     \
            CbjectProps props;                                                     \
        } ___Cbject;                                                               \
                                                                                   \
        if (((___Cbject *) &me)->type == NULL) { ___##cbjType##_init(&me, NULL); } \
        return &me;                                                                \
    }

#endif // CBJECT_OBJECTINSTANCEIMPL_H
