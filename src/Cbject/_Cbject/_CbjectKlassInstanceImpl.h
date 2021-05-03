#ifndef _CBJECTKLASSINSTANCEIMPL_H
#define _CBJECTKLASSINSTANCEIMPL_H
#include "_CbjectKlassInstanceFunctionPrototype.h"

#define _CbjectKlassInstanceImpl(klassName, superKlassName, ...)                                     \
    _CbjectKlassInstanceFunctionPrototype(klassName)                                                 \
    {                                                                                                \
        static klassName##Klass k;                                                                   \
                                                                                                     \
        if (((CbjectKlass *) &k)->type == null)                                                      \
        {                                                                                            \
            static char const * const type = #klassName;                                             \
            *((superKlassName##Klass *) &k) = *superKlassName##Klass_instance();                     \
            ((CbjectKlass *) &k)->vf.size = (uint8(*)(Cbject const * const me)) s##klassName##_size; \
                                                                                                     \
            do                                                                                       \
                __VA_ARGS__                                                                          \
            while (0);                                                                               \
                                                                                                     \
            ((CbjectKlass *) &k)->type = type;                                                       \
        }                                                                                            \
                                                                                                     \
        return &k;                                                                                   \
    }

#endif // _CBJECTKLASSINSTANCEIMPL_H
