#ifndef _CBJ_CASTTOSUPERIMPL_H
#define _CBJ_CASTTOSUPERIMPL_H
#include "_Cbj_CastToSuperFunPrototype.h"

#define _Cbj_CastToSuperImpl(typeName, Cbj_ParentName) \
    _Cbj_CastToSuperFunPrototype(typeName, Cbj_ParentName) { return (Cbj_ParentName *) me; }

#endif // _CBJ_CASTTOSUPERIMPL_H
