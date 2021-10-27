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
        parent##Params s_params;                                                \
        typeName##_onInit(me, params, &s_params);                               \
        parent##_init((parent *) me, s_params);                                 \
        ((CbjectContainer *) me)->t = (CbjectType *) typeName##Type_instance(); \
    }                                                                           \
    Cbject_OnInitFunPrototype(typeName, parent)

#endif // CBJECT_INITIMPL_H
