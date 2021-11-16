#ifndef CBJECT_CASTFUN_H
#define CBJECT_CASTFUN_H

/*
Cbject_CastFun_Prototype
*/
#define Cbject_CastFun_Prototype(class) \
    class * Object_to##class(Object const * const me)

/*
Cbject_CastFun_Impl
*/
#define Cbject_CastFun_Impl(class)                                                \
    Cbject_CastFun_Prototype(class)                                               \
    {                                                                             \
        Assert((IsTypeOf(me, class) == true) && "Cast to" #class "not possible"); \
        return (class *)me;                                                       \
    }

#endif // CBJECT_CASTFUN_H
