#ifndef CBJECT_OBJECTINSTANCEIMPL_H
#define CBJECT_OBJECTINSTANCEIMPL_H
#include "Cbject_ObjectInstanceFunPrototype.h"

#define Cbject_ObjectInstanceImpl(cbjType)                                          \
    Cbject_ObjectInstanceFunPrototype(cbjType)                                      \
    {                                                                               \
        static cbjType me;                                                          \
                                                                                    \
        typedef struct CbjectContainer                                              \
        {                                                                           \
            Cbject_Settings_maxAlign a;                                             \
            CbjectType * type;                                                      \
            CbjectProps props;                                                      \
        } CbjectContainer;                                                          \
                                                                                    \
        if (((CbjectContainer *) &me)->type == NULL) { cbjType##_init(&me, NULL); } \
        return &me;                                                                 \
    }

#endif // CBJECT_OBJECTINSTANCEIMPL_H
