#ifndef CBJECT_CASTFUN_H
#define CBJECT_CASTFUN_H

#define Cbject_CastFun_Prototype(typeName) \
    typeName * const Cbject_to##typeName(Cbject const * const me)

#define Cbject_CastFun_Impl(typeName)                                                                          \
    Cbject_CastFun_Prototype(typeName)                                                                         \
    {                                                                                                          \
        typedef struct CbjectTypeT                                                                             \
        {                                                                                                      \
            Cbject_Settings_maxAlign a;                                                                        \
            char const * name;                                                                                 \
            CbjectType * st;                                                                                   \
            CbjectVirtFuns vf;                                                                                 \
        } CbjectTypeT;                                                                                         \
                                                                                                               \
        typedef struct CbjectT                                                                                 \
        {                                                                                                      \
            Cbject_Settings_maxAlign a;                                                                        \
            CbjectType * t;                                                                                    \
        } CbjectT;                                                                                             \
                                                                                                               \
        CbjectTypeT const * t = (CbjectTypeT *)((CbjectT *)me)->t;                                             \
                                                                                                               \
        while ((t != (CbjectTypeT *)CbjectType_instance()) && (t != (CbjectTypeT *)typeName##Type_instance())) \
        {                                                                                                      \
            t = (CbjectTypeT *)t->st;                                                                          \
            assert((t != (CbjectTypeT *)CbjectType_instance()) && "Cast not possible");                        \
        }                                                                                                      \
                                                                                                               \
        return (typeName *)me;                                                                                 \
    }

#endif // CBJECT_CASTFUN_H
