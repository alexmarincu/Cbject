#ifndef CBJECT_OBJECTINSTANCEIMPL_H
#define CBJECT_OBJECTINSTANCEIMPL_H
#include "Cbject_ObjectInstanceFunPrototype.h"

#define Cbject_ObjectInstanceImpl(typeName)                                                \
    Cbject_ObjectInstanceFunPrototype(typeName)                                            \
    {                                                                                      \
        static typeName me;                                                                \
                                                                                           \
        typedef struct CbjectT                                                             \
        {                                                                                  \
            Cbject_Settings_maxAlign a;                                                    \
            CbjectType * t;                                                                \
        } CbjectT;                                                                         \
                                                                                           \
        if (((CbjectT *) &me)->t == NULL) { typeName##_init(&me, (typeName##Params){0}); } \
        return &me;                                                                        \
    }

#endif // CBJECT_OBJECTINSTANCEIMPL_H
