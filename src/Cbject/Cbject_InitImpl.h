#ifndef CBJECT_INITIMPL_H
#define CBJECT_INITIMPL_H
#include "Cbject_InitFunPrototype.h"
#include "Cbject_OnInitFunPrototype.h"

#define Cbject_InitImpl(typeName, parent)                             \
    Cbject_OnInitFunPrototype(typeName, parent);                      \
    Cbject_InitFunPrototype(typeName)                                 \
    {                                                                 \
        typedef struct CbjectT                                        \
        {                                                             \
            Cbject_Settings_maxAlign a;                               \
            CbjectType * t;                                           \
        } CbjectT;                                                    \
                                                                      \
        parent##Params sp;                                            \
        typeName##_onInit(me, p, &sp);                                \
        parent##_init((parent *)me, sp);                              \
        ((CbjectT *)me)->t = (CbjectType *)typeName##Type_instance(); \
    }                                                                 \
    Cbject_OnInitFunPrototype(typeName, parent)

#endif // CBJECT_INITIMPL_H
