#ifndef _CBJ_CASTTOSUBIMPL_H
#define _CBJ_CASTTOSUBIMPL_H
#include "_Cbj_CastToSubFunPrototype.h"

#define _Cbj_CastToSubImpl(cbjType, parent) \
    _Cbj_CastToSubFunPrototype(cbjType, parent) { return (cbjType *) me; }

#endif // _CBJ_CASTTOSUBIMPL_H
