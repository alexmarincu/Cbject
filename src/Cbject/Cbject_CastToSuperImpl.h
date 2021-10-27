#ifndef CBJECT_CASTTOSUPERIMPL_H
#define CBJECT_CASTTOSUPERIMPL_H
#include "Cbject_CastToSuperFunPrototype.h"

#define Cbject_CastToSuperImpl(typeName, parent) \
    Cbject_CastToSuperFunPrototype(typeName, parent) { return (parent *) me; }

#define Cbject_CastImpl(typeName)                                                    \
    Cbject_CastFunPrototype(typeName)                                                \
    {                                                                                \
        typedef struct CbjectType                                                    \
        {                                                                            \
            Cbject_Settings_maxAlign a;                                              \
            char const * name;                                                       \
            CbjectTypeId id;                                                         \
            CbjectType * s;                                                          \
            CbjectVirtFuns vf;                                                       \
        } CbjectType;                                                                \
                                                                                     \
        typedef struct Cbject                                                        \
        {                                                                            \
            Cbject_Settings_maxAlign a;                                              \
            CbjectType * t;                                                          \
        } Cbject;                                                                    \
                                                                                     \
        CbjectType const * t = ((Cbject *) me)->t;                                   \
                                                                                     \
        while ((t->id != CbjectTypeId_Cbject) && (t->id != CbjectTypeId_##typeName)) \
        {                                                                            \
            t = (CbjectType *) t->s;                                                 \
            assert((t->id != CbjectTypeId_Cbject) && "Cast to not possible");        \
        }                                                                            \
                                                                                     \
        return (typeName *) me;                                                      \
    }

#endif // CBJECT_CASTTOSUPERIMPL_H
