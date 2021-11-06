#ifndef CBJECT_TERMINATEFUN_H
#define CBJECT_TERMINATEFUN_H

#define Cbject_TerminateFun_OnTerminateFunPrototype(className) \
    static void className##_onTerminate(className * const me)

#define Cbject_TerminateFun_Prototype(className) \
    void className##_terminate(className * const me)

#define Cbject_TerminateFun_Impl_x(className, superClassName) \
    Cbject_TerminateFun_OnTerminateFunPrototype(className);   \
    Cbject_TerminateFun_Prototype(className)                  \
    {                                                         \
        className##_onTerminate(me);                          \
        superClassName##_terminate((superClassName *)me);     \
    }                                                         \
    Cbject_TerminateFun_OnTerminateFunPrototype(className)

#define Cbject_TerminateFun_Impl(className, superClassName) \
    Cbject_TerminateFun_Impl_x(className, superClassName)

#endif // CBJECT_TERMINATEFUN_H
