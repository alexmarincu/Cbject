#ifndef CBJECT_NEWONSTACKFUNIMPL_H
#define CBJECT_NEWONSTACKFUNIMPL_H

/*
Cbject_StackCreateObjectFun_Prototype
*/
#define Cbject_StackCreateObjectFun_Prototype(class) \
    class * class##_stackCreate(class * const me, class##Params const params)

/*
Cbject_StackCreateObjectFun_Impl
*/
#define Cbject_StackCreateObjectFun_Impl(class)  \
    Cbject_StackCreateObjectFun_Prototype(class) \
    {                                            \
        *me = (class){0};                        \
        class##_init(me, params);                \
        return me;                               \
    }

#endif // CBJECT_NEWONSTACKFUNIMPL_H
