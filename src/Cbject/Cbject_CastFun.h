#ifndef CBJECT_CASTFUN_H
#define CBJECT_CASTFUN_H

#define Cbject_CastFun_Prototype(typeName) \
    typeName * const Object_to##typeName(Object const * const me)

#define Cbject_CastFun_Impl(typeName)                                                                                \
    Cbject_CastFun_Prototype(typeName)                                                                               \
    {                                                                                                                \
        typedef struct ObjectTypeT                                                                                   \
        {                                                                                                            \
            Cbject_Settings_maxAlign align;                                                                          \
            char const * name;                                                                                       \
            ObjectType * superType;                                                                                  \
            ObjectVirtFuns virtFuns;                                                                                 \
        } ObjectTypeT;                                                                                               \
                                                                                                                     \
        typedef struct ObjectT                                                                                       \
        {                                                                                                            \
            Cbject_Settings_maxAlign align;                                                                          \
            ObjectType * type;                                                                                       \
        } ObjectT;                                                                                                   \
                                                                                                                     \
        ObjectTypeT const * type = (ObjectTypeT *)((ObjectT *)me)->type;                                             \
                                                                                                                     \
        while ((type != (ObjectTypeT *)ObjectType_instance()) && (type != (ObjectTypeT *)typeName##Type_instance())) \
        {                                                                                                            \
            type = (ObjectTypeT *)type->superType;                                                                   \
            assert((type != (ObjectTypeT *)ObjectType_instance()) && "Cast not possible");                           \
        }                                                                                                            \
                                                                                                                     \
        return (typeName *)me;                                                                                       \
    }

#endif // CBJECT_CASTFUN_H
