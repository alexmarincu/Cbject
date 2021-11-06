#ifndef CBJECT_CASTFUN_H
#define CBJECT_CASTFUN_H

#define Cbject_CastFun_Prototype(className) \
    className * const Object_to##className(Object const * const me)

#define Cbject_CastFun_Impl(className)                                                                                \
    Cbject_CastFun_Prototype(className)                                                                               \
    {                                                                                                                 \
        typedef struct ObjectTypeT                                                                                    \
        {                                                                                                             \
            Cbject_Settings_maxAlign align;                                                                           \
            char const * name;                                                                                        \
            ObjectType * superType;                                                                                   \
            ObjectVirtFuns virtFuns;                                                                                  \
        } ObjectTypeT;                                                                                                \
                                                                                                                      \
        typedef struct ObjectT                                                                                        \
        {                                                                                                             \
            Cbject_Settings_maxAlign align;                                                                           \
            ObjectType * type;                                                                                        \
        } ObjectT;                                                                                                    \
                                                                                                                      \
        ObjectTypeT const * type = (ObjectTypeT *)((ObjectT *)me)->type;                                              \
                                                                                                                      \
        while ((type != (ObjectTypeT *)ObjectType_instance()) && (type != (ObjectTypeT *)className##Type_instance())) \
        {                                                                                                             \
            type = (ObjectTypeT *)type->superType;                                                                    \
            assert((type != (ObjectTypeT *)ObjectType_instance()) && "Cast not possible");                            \
        }                                                                                                             \
                                                                                                                      \
        return (className *)me;                                                                                       \
    }

#endif // CBJECT_CASTFUN_H
