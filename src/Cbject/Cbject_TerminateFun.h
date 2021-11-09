#ifndef CBJECT_TERMINATEFUN_H
#define CBJECT_TERMINATEFUN_H

/*
Cbject_TerminateFun_OnTerminateFunPrototype
*/
#define Cbject_TerminateFun_OnTerminateFunPrototype_x0(className) \
    static void className##_onTerminate(className * const me)

#define Cbject_TerminateFun_OnTerminateFunPrototype(className) \
    Cbject_TerminateFun_OnTerminateFunPrototype_x0(className)

/*
Cbject_TerminateFun_Prototype
*/
#define Cbject_TerminateFun_Prototype(className) \
    void className##_terminate(className * const me)

/*
Cbject_TerminateFun_Impl
*/
#define Cbject_TerminateFun_Impl_x0(className, superClassName) \
    Cbject_TerminateFun_OnTerminateFunPrototype(className);    \
    Cbject_TerminateFun_Prototype(className)                   \
    {                                                          \
        className##_onTerminate(me);                           \
        superClassName##_terminate((superClassName *)me);      \
    }

#define Cbject_TerminateFun_Impl(className, superClassName) \
    Cbject_TerminateFun_Impl_x0(className, superClassName)

#endif // CBJECT_TERMINATEFUN_H
