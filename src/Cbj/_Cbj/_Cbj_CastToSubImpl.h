#ifndef _CBJ_CASTTOSUBIMPL_H
#define _CBJ_CASTTOSUBIMPL_H
#include "_Cbj_CastToSubFunPrototype.h"

#define _Cbj_CastToSubImpl(typeName, Cbj_ParentName) \
    _Cbj_CastToSubFunPrototype(typeName, Cbj_ParentName) { return (typeName *) me; }

#endif // _CBJ_CASTTOSUBIMPL_H
