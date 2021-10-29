#ifndef CBJECT_CASTTOSUPERIMPL_H
#define CBJECT_CASTTOSUPERIMPL_H
#include "Cbject_CastToSuperFunPrototype.h"

#define Cbject_CastToSuperImpl(typeName, parent) \
    Cbject_CastToSuperFunPrototype(typeName, parent) { return (parent *) me; }

#define Cbject_CastImpl(typeName)                                                    \
    Cbject_CastFunPrototype(typeName)                                                \
    {                                                                                \
        typedef struct CbjectTypeT                                                   \
        {                                                                            \
            Cbject_Settings_maxAlign a;                                              \
            char const * name;                                                       \
            CbjectTypeId id;                                                         \
            CbjectType * st;                                                         \
            CbjectVirtFuns vf;                                                       \
        } CbjectTypeT;                                                               \
                                                                                     \
        typedef struct CbjectT                                                       \
        {                                                                            \
            Cbject_Settings_maxAlign a;                                              \
            CbjectType * t;                                                          \
        } CbjectT;                                                                   \
                                                                                     \
        CbjectTypeT const * t = (CbjectTypeT *) ((CbjectT *) me)->t;                 \
                                                                                     \
        while ((t->id != CbjectTypeId_Cbject) && (t->id != CbjectTypeId_##typeName)) \
        {                                                                            \
            t = (CbjectTypeT *) t->st;                                               \
            assert((t->id != CbjectTypeId_Cbject) && "Cast not possible");           \
        }                                                                            \
                                                                                     \
        return (typeName *) me;                                                      \
    }

#endif // CBJECT_CASTTOSUPERIMPL_H
