#ifndef _CBJECTCASTTOSUPERIMPL_H
#define _CBJECTCASTTOSUPERIMPL_H
#include "_CbjectCastToSuperFunPrototype.h"

#define _CbjectCastToSuperImpl(klassName, superKlassName) \
    _CbjectCastToSuperFunPrototype(klassName, superKlassName) { return (superKlassName *) me; }

#endif // _CBJECTCASTTOSUPERIMPL_H
