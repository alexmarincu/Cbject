#ifndef _CBJECTINITIMPL_H
#define _CBJECTINITIMPL_H
#include "_CbjectCtorFunPrototype.h"
#include "_CbjectInitFunPrototype.h"

#define _CbjectInitImpl(klassName, superKlassName)                                    \
    _CbjectInitFunPrototype(klassName, superKlassName);                               \
    _CbjectCtorFunPrototype(klassName)                                           \
    {                                                                                 \
        /*if (#superKlassName == "Cbject") { Cbject_ctor((Cbject *) me, null); }   */ \
        superKlassName##Params s_params;                                              \
                                                                                      \
        /* do                                                                         \
             __VA_ARGS__                                                              \
         while (0);     */                                                            \
        _##klassName##_init(me, params, &s_params);                                   \
        /*((Cbject *) me)->k = (CbjectKlass *) klassName##Klass_instance(); */        \
        superKlassName##_ctor((superKlassName *) me, &s_params);                      \
        Cbject_klassSet((Cbject *) me, (CbjectKlass *) klassName##Klass_instance());  \
    }                                                                                 \
                                                                                      \
    _CbjectInitFunPrototype(klassName, superKlassName)

#endif // _CBJECTINITIMPL_H
