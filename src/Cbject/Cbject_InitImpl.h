#ifndef CBJECT_INITIMPL_H
#define CBJECT_INITIMPL_H
#include "Cbject_InitFunPrototype.h"
#include "Cbject_OnInitFunPrototype.h"

#define Cbject_InitImpl(typeName, parent)                                       \
    Cbject_OnInitFunPrototype(typeName, parent);                                \
    Cbject_InitFunPrototype(typeName)                                           \
    {                                                                           \
        typedef struct CbjectContainer                                          \
        {                                                                       \
            Cbject_Settings_maxAlign a;                                         \
            CbjectType * t;                                                     \
        } CbjectContainer;                                                      \
                                                                                \
        Cbject_init((Cbject *) me);                                             \
        typeName##_onInit(me, params);                                          \
        /* parent##_init((parent *) me, super_params); */                       \
        ((CbjectContainer *) me)->t = (CbjectType *) typeName##Type_instance(); \
    }                                                                           \
    Cbject_OnInitFunPrototype(typeName, parent)

#endif // CBJECT_INITIMPL_H
