#ifndef _CBJECTINITFUNCTIONIMPL_H
#define _CBJECTINITFUNCTIONIMPL_H
#include "_CbjectInitFunctionPrototype.h"

#define _CbjectInitFunctionImpl(klassName, superKlassName, ...)                       \
    _CbjectInitFunctionPrototype(klassName)                                           \
    {                                                                                 \
        /*if (#superKlassName == "Cbject") { Cbject_init((Cbject *) me, null); }   */ \
        superKlassName##Params superParams;                                           \
                                                                                      \
        do                                                                            \
            __VA_ARGS__                                                               \
        while (0);                                                                    \
                                                                                      \
        /*((Cbject *) me)->k = (CbjectKlass *) klassName##Klass_instance(); */        \
        superKlassName##_init((superKlassName *) me, &superParams);                   \
        Cbject_klassSet((Cbject *) me, (CbjectKlass *) klassName##Klass_instance());  \
    }

#endif // _CBJECTINITFUNCTIONIMPL_H
