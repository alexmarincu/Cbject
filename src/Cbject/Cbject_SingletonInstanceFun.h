#ifndef CBJECT_SINGLETONINSTANCEFUN_H
#define CBJECT_SINGLETONINSTANCEFUN_H

/*
Cbject_SingletonInstanceFun_Prototype
*/
#define Cbject_SingletonInstanceFun_Prototype(class) \
    class * class##_instance()

/*
Cbject_SingletonInstanceFun_Impl
*/
#define Cbject_SingletonInstanceFun_Impl(class)                                        \
    Cbject_SingletonInstanceFun_Prototype(class)                                       \
    {                                                                                  \
        static class me;                                                               \
                                                                                       \
        typedef struct ObjectT                                                         \
        {                                                                              \
            Cbject_Settings_maxAlign align;                                            \
            ObjectType * type;                                                         \
        } ObjectT;                                                                     \
                                                                                       \
        if (((ObjectT *)&me)->type == NULL) { class##_init(&me, (class##Params){0}); } \
        return &me;                                                                    \
    }

#endif // CBJECT_SINGLETONINSTANCEFUN_H
