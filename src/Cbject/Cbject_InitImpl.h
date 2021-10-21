#ifndef CBJECT_INITIMPL_H
#define CBJECT_INITIMPL_H
#include "Cbject_InitFunPrototype.h"
#include "Cbject_OnInitFunPrototype.h"

#define Cbject_InitImpl(cbjType, parent)                                  \
    Cbject_OnInitFunPrototype(cbjType, parent);                           \
    Cbject_InitFunPrototype(cbjType)                                      \
    {                                                                     \
        typedef struct CbjectContainer                                    \
        {                                                                 \
            Cbject_Settings_maxAlign a;                                   \
            CbjectType * type;                                            \
            CbjectProps props;                                            \
        } CbjectContainer;                                                \
                                                                          \
        parent##Params super_params;                                      \
        cbjType##_onInit(me, params, &super_params);                      \
        parent##_init((parent *) me, &super_params);                      \
        ((CbjectContainer *) me)->type = (CbjectType *) cbjType##Type_(); \
    }                                                                     \
    Cbject_OnInitFunPrototype(cbjType, parent)

#endif // CBJECT_INITIMPL_H
