#ifndef CBJECT_TERMINATEFUN_H
#define CBJECT_TERMINATEFUN_H

#define Cbject_TerminateFun_OnTerminateFunPrototype(typeName) \
    static void typeName##_onTerminate(typeName * const me)

#define Cbject_TerminateFun_Prototype(typeName) \
    void typeName##_terminate(typeName * const me)

#define Cbject_TerminateFun_Impl_x(typeName, superTypeName) \
    Cbject_TerminateFun_OnTerminateFunPrototype(typeName);  \
    Cbject_TerminateFun_Prototype(typeName)                 \
    {                                                       \
        typeName##_onTerminate(me);                         \
        superTypeName##_terminate((superTypeName *)me);     \
    }                                                       \
    Cbject_TerminateFun_OnTerminateFunPrototype(typeName)

#define Cbject_TerminateFun_Impl(typeName, superTypeName) \
    Cbject_TerminateFun_Impl_x(typeName, superTypeName)

#endif // CBJECT_TERMINATEFUN_H
