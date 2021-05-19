#ifndef ___CBJ_INITIMPL_H
#define ___CBJ_INITIMPL_H
#include "___Cbj_InitFunPrototype.h"
#include "___Cbj_OnInitFunPrototype.h"

#define ___Cbj_InitImpl(cbjType, parent)                            \
    ___Cbj_OnInitFunPrototype(cbjType, parent);                     \
    ___Cbj_InitFunPrototype(cbjType)                                \
    {                                                               \
        typedef struct ___Cbject                                    \
        {                                                           \
            Cbj_Settings_maxAlign ___align;                         \
            CbjectType * type;                                      \
            CbjectProps props;                                      \
        } ___Cbject;                                                \
                                                                    \
        parent##Params s_params;                                    \
        ___##cbjType##_onInit(me, params, &s_params);               \
        parent##_init((parent *) me, &s_params);                    \
        ((___Cbject *) me)->type = (CbjectType *) cbjType##Type_(); \
    }                                                               \
    ___Cbj_OnInitFunPrototype(cbjType, parent)

#endif // ___CBJ_INITIMPL_H
