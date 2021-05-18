#ifndef _CBJ_INITIMPL_H
#define _CBJ_INITIMPL_H
#include "_Cbj_InitFunPrototype.h"
#include "_Cbj_OnInitFunPrototype.h"

#define _Cbj_InitImpl(cbjType, parent)                                 \
    _Cbj_OnInitFunPrototype(cbjType, parent);                          \
    _Cbj_InitFunPrototype(cbjType)                                     \
    {                                                                  \
        typedef struct _Cbject                                         \
        {                                                              \
            Cbj_Settings_maxAlign xalign;                                   \
            CbjectType * type;                                            \
            CbjectProps props;                                             \
        } _Cbject;                                                     \
                                                                       \
        parent##Params s_params;                                       \
        _##cbjType##_onInit(me, params, &s_params);                    \
        parent##_init((parent *) me, &s_params);                       \
        ((_Cbject *) me)->type = (CbjectType *) cbjType##Type_instance(); \
    }                                                                  \
    _Cbj_OnInitFunPrototype(cbjType, parent)

#endif // _CBJ_INITIMPL_H
