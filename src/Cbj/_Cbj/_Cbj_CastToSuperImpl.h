#ifndef _CBJ_CASTTOSUPERIMPL_H
#define _CBJ_CASTTOSUPERIMPL_H
#include "_Cbj_CastToSuperFunPrototype.h"

#define _Cbj_CastToSuperImpl(cbjType, parent) \
    _Cbj_CastToSuperFunPrototype(cbjType, parent) { return (parent *) me; }

#endif // _CBJ_CASTTOSUPERIMPL_H
