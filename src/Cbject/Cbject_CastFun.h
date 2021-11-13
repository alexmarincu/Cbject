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
#define Cbject_CastFun_Impl(class)                                                                                \
    Cbject_CastFun_Prototype(class)                                                                               \
    {                                                                                                             \
        assert((me != NULL) && "Cast cannot be used with NULL pointer");                                          \
        typedef struct ObjectTypeT                                                                                \
        {                                                                                                         \
            Cbject_Settings_maxAlign align;                                                                       \
            char const * name;                                                                                    \
            ObjectType * superType;                                                                               \
            ObjectVirtFuns virtFuns;                                                                              \
        } ObjectTypeT;                                                                                            \
                                                                                                                  \
        typedef struct ObjectT                                                                                    \
        {                                                                                                         \
            Cbject_Settings_maxAlign align;                                                                       \
            ObjectType * type;                                                                                    \
        } ObjectT;                                                                                                \
                                                                                                                  \
        ObjectTypeT const * type = (ObjectTypeT *)((ObjectT *)me)->type;                                          \
        assert((type != NULL) && "Cast cannot be used if object is not initialized");                             \
                                                                                                                  \
        while ((type != (ObjectTypeT *)ObjectType_instance()) && (type != (ObjectTypeT *)class##Type_instance())) \
        {                                                                                                         \
            type = (ObjectTypeT *)type->superType;                                                                \
            assert((type != (ObjectTypeT *)ObjectType_instance()) && "Cast to" #class "not possible");            \
        }                                                                                                         \
                                                                                                                  \
        return (class *)me;                                                                                       \
    }

#endif // CBJECT_CASTFUN_H
