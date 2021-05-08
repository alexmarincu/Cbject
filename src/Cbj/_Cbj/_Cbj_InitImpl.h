#ifndef _CBJ_INITIMPL_H
#define _CBJ_INITIMPL_H
#include "_Cbj_InitFunPrototype.h"
#include "_Cbj_OnInitFunPrototype.h"

#define _Cbj_InitImpl(typeName, Cbj_ParentName)                                               \
    _Cbj_OnInitFunPrototype(typeName, Cbj_ParentName);                                        \
    _Cbj_InitFunPrototype(typeName)                                                       \
    {                                                                                     \
        Cbj_ParentName##Params s_params;                                                      \
        _##typeName##_onInit(me, params, &s_params);                                      \
        Cbj_ParentName##_init((Cbj_ParentName *) me, &s_params);                                  \
        Cbj_Base_classSet((Cbj_Base *) me, (Cbj_BaseClass *) typeName##Class_instance()); \
    }                                                                                     \
    _Cbj_OnInitFunPrototype(typeName, Cbj_ParentName)

#endif // _CBJ_INITIMPL_H
