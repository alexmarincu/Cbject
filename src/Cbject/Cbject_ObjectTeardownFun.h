#ifndef CBJECT_OBJECTTEARDOWNFUN_H
#define CBJECT_OBJECTTEARDOWNFUN_H

/*
Cbject_ObjectTeardownFun_Prototype
*/
#define Cbject_ObjectTeardownFun_Prototype_x0(class) \
    static void class##_teardown(class * const me)

#define Cbject_ObjectTeardownFun_Prototype(class) \
    Cbject_ObjectTeardownFun_Prototype_x0(class)

/*
Cbject_ObjectTeardownFun_TerminateFunPrototype
*/
#define Cbject_ObjectTeardownFun_TerminateFunPrototype_x0(class) \
    void class##_terminate(class * const me)

#define Cbject_ObjectTeardownFun_TerminateFunPrototype(class) \
    Cbject_ObjectTeardownFun_TerminateFunPrototype_x0(class)

/*
Cbject_ObjectTeardownFun_Impl
*/
#define Cbject_ObjectTeardownFun_Impl_x0(class, superClass) \
    Cbject_ObjectTeardownFun_Prototype(class)               \
    {                                                       \
        class##_terminate(me);                              \
        superClass##_terminate((superClass *)me);           \
    }

#define Cbject_ObjectTeardownFun_Impl(class, superClass) \
    Cbject_ObjectTeardownFun_Impl_x0(class, superClass)

#endif // CBJECT_OBJECTTEARDOWNFUN_H
