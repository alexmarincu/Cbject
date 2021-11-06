#ifndef CBJECT_SINGLETONINSTANCEFUN_H
#define CBJECT_SINGLETONINSTANCEFUN_H

#define Cbject_SingletonInstanceFun_Prototype(className) \
    className * className##_instance()

#define Cbject_SingletonInstanceFun_Impl(className)                                            \
    Cbject_SingletonInstanceFun_Prototype(className)                                           \
    {                                                                                          \
        static className me;                                                                   \
                                                                                               \
        typedef struct ObjectT                                                                 \
        {                                                                                      \
            Cbject_Settings_maxAlign align;                                                    \
            ObjectType * type;                                                                 \
        } ObjectT;                                                                             \
                                                                                               \
        if (((ObjectT *)&me)->type == NULL) { className##_init(&me, (className##Params){0}); } \
        return &me;                                                                            \
    }

#endif // CBJECT_SINGLETONINSTANCEFUN_H
