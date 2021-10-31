#ifndef CBJECT_CASTFUN_H
#define CBJECT_CASTFUN_H

#define Cbject_CastFun_Prototype(typeName) \
    typeName * const Object_to##typeName(Object const * const me)

#define Cbject_CastFun_Impl(typeName)                                                                          \
    Cbject_CastFun_Prototype(typeName)                                                                         \
    {                                                                                                          \
        typedef struct ObjectTypeT                                                                             \
        {                                                                                                      \
            Cbject_Settings_maxAlign a;                                                                        \
            char const * name;                                                                                 \
            ObjectType * st;                                                                                   \
            ObjectVirtFuns vf;                                                                                 \
        } ObjectTypeT;                                                                                         \
                                                                                                               \
        typedef struct ObjectT                                                                                 \
        {                                                                                                      \
            Cbject_Settings_maxAlign a;                                                                        \
            ObjectType * t;                                                                                    \
        } ObjectT;                                                                                             \
                                                                                                               \
        ObjectTypeT const * t = (ObjectTypeT *)((ObjectT *)me)->t;                                             \
                                                                                                               \
        while ((t != (ObjectTypeT *)ObjectType_instance()) && (t != (ObjectTypeT *)typeName##Type_instance())) \
        {                                                                                                      \
            t = (ObjectTypeT *)t->st;                                                                          \
            assert((t != (ObjectTypeT *)ObjectType_instance()) && "Cast not possible");                        \
        }                                                                                                      \
                                                                                                               \
        return (typeName *)me;                                                                                 \
    }

#endif // CBJECT_CASTFUN_H
