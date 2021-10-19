#ifndef CBJECT_INITIMPL_H
#define CBJECT_INITIMPL_H
#include "Cbject_InitFunPrototype.h"
#include "Cbject_OnInitFunPrototype.h"

#define Cbject_InitImpl(cbjType, parent)                            \
    Cbject_OnInitFunPrototype(cbjType, parent);                     \
    Cbject_InitFunPrototype(cbjType)                                \
    {                                                               \
        typedef struct ___Cbject                                    \
        {                                                           \
            Cbject_Settings_maxAlign ___align;                         \
            CbjectType * type;                                      \
            CbjectProps props;                                      \
        } ___Cbject;                                                \
                                                                    \
        parent##Params super_params;                                \
        ___##cbjType##_onInit(me, params, &super_params);           \
        ___##parent##_init((parent *) me, &super_params);           \
        ((___Cbject *) me)->type = (CbjectType *) cbjType##Type_(); \
    }                                                               \
    Cbject_OnInitFunPrototype(cbjType, parent)

#endif // CBJECT_INITIMPL_H
