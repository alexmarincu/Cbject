#ifndef _CBJECTCASTTOSUPERIMPL_H
#define _CBJECTCASTTOSUPERIMPL_H
#include "_CbjectCastToSuperFunPrototype.h"

#define _CbjectCastToSuperImpl(cbjectTypeName, parentName) \
    _CbjectCastToSuperFunPrototype(cbjectTypeName, parentName) { return (parentName *) me; }

#endif // _CBJECTCASTTOSUPERIMPL_H
