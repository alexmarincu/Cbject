#ifndef _CBJECTINITIMPL_H
#define _CBJECTINITIMPL_H
#include "_CbjectInitFunPrototype.h"
#include "_CbjectOnInitFunPrototype.h"

#define _CbjectInitImpl(klassName, superKlassName)                                    \
    _CbjectOnInitFunPrototype(klassName, superKlassName);                               \
    _CbjectInitFunPrototype(klassName)                                           \
    {                                                                                 \
        /*if (#superKlassName == "Cbject") { Cbject_init((Cbject *) me, null); }   */ \
        superKlassName##Params s_params;                                              \
                                                                                      \
        /* do                                                                         \
             __VA_ARGS__                                                              \
         while (0);     */                                                            \
        _##klassName##_onInit(me, params, &s_params);                                   \
        /*((Cbject *) me)->k = (CbjectKlass *) klassName##Klass_instance(); */        \
        superKlassName##_init((superKlassName *) me, &s_params);                      \
        Cbject_klassSet((Cbject *) me, (CbjectKlass *) klassName##Klass_instance());  \
    }                                                                                 \
                                                                                      \
    _CbjectOnInitFunPrototype(klassName, superKlassName)

#endif // _CBJECTINITIMPL_H
