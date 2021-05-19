#ifndef ___CBJ_CASTTOSUPERIMPL_H
#define ___CBJ_CASTTOSUPERIMPL_H
#include "___Cbj_CastToSuperFunPrototype.h"

#define ___Cbj_CastToSuperImpl(cbjType, parent) \
    ___Cbj_CastToSuperFunPrototype(cbjType, parent) { return (parent *) me; }

#endif // ___CBJ_CASTTOSUPERIMPL_H
