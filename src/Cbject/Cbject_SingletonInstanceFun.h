#ifndef CBJECT_SINGLETONINSTANCEFUN_H
#define CBJECT_SINGLETONINSTANCEFUN_H

#define Cbject_SingletonInstanceFun_Prototype(typeName) \
    typeName * typeName##_instance()

#define Cbject_SingletonInstanceFun_Impl(typeName)                                           \
    Cbject_SingletonInstanceFun_Prototype(typeName)                                          \
    {                                                                                        \
        static typeName me;                                                                  \
                                                                                             \
        typedef struct ObjectT                                                               \
        {                                                                                    \
            Cbject_Settings_maxAlign align;                                                  \
            ObjectType * type;                                                               \
        } ObjectT;                                                                           \
                                                                                             \
        if (((ObjectT *)&me)->type == NULL) { typeName##_init(&me, (typeName##Params){0}); } \
        return &me;                                                                          \
    }

#endif // CBJECT_SINGLETONINSTANCEFUN_H
