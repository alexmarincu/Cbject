#ifndef CBJECT_TERMINATEFUN_H
#define CBJECT_TERMINATEFUN_H

/*
Cbject_TerminateFun_OnTerminateFunPrototype
*/
#define Cbject_TerminateFun_OnTerminateFunPrototype_x0(class) \
    static void class##_onTerminate(class * const me)

#define Cbject_TerminateFun_OnTerminateFunPrototype(class) \
    Cbject_TerminateFun_OnTerminateFunPrototype_x0(class)

/*
Cbject_TerminateFun_Prototype
*/
#define Cbject_TerminateFun_Prototype(class) \
    void class##_terminate(class * const me)

/*
Cbject_TerminateFun_Impl
*/
#define Cbject_TerminateFun_Impl_x0(class, superClass)  \
    Cbject_TerminateFun_OnTerminateFunPrototype(class); \
    Cbject_TerminateFun_Prototype(class)                \
    {                                                   \
        class##_onTerminate(me);                        \
        superClass##_terminate((superClass *)me);       \
    }

#define Cbject_TerminateFun_Impl(class, superClass) \
    Cbject_TerminateFun_Impl_x0(class, superClass)

#endif // CBJECT_TERMINATEFUN_H
