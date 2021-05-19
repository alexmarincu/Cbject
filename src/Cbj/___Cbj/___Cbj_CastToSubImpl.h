#ifndef ___CBJ_CASTTOSUBIMPL_H
#define ___CBJ_CASTTOSUBIMPL_H
#include "___Cbj_CastToSubFunPrototype.h"

#define ___Cbj_CastToSubImpl(cbjType, parent) \
    ___Cbj_CastToSubFunPrototype(cbjType, parent) { return (cbjType *) me; }

#endif // ___CBJ_CASTTOSUBIMPL_H
