#ifndef _CBJECTINITIMPL_H
#define _CBJECTINITIMPL_H
#include "_CbjectInitFunPrototype.h"
#include "_CbjectOnInitFunPrototype.h"

#define _CbjectInitImpl(cbjectTypeName, parentName)                                    \
    _CbjectOnInitFunPrototype(cbjectTypeName, parentName);                               \
    _CbjectInitFunPrototype(cbjectTypeName)                                           \
    {                                                                                 \
        /*if (#parentName == "Cbject") { Cbject_init((Cbject *) me, NULL); }   */ \
        parentName##Params s_params;                                              \
                                                                                      \
        /* do                                                                         \
             __VA_ARGS__                                                              \
         while (0);     */                                                            \
        _##cbjectTypeName##_onInit(me, params, &s_params);                                   \
        /*((Cbject *) me)->k = (CbjectClass *) cbjectTypeName##Class_instance(); */        \
        parentName##_init((parentName *) me, &s_params);                      \
        Cbject_CbjectTypeSet((Cbject *) me, (CbjectClass *) cbjectTypeName##Class_instance());  \
    }                                                                                 \
                                                                                      \
    _CbjectOnInitFunPrototype(cbjectTypeName, parentName)

#endif // _CBJECTINITIMPL_H
