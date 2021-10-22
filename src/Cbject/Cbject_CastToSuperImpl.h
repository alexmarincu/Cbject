#ifndef CBJECT_CASTTOSUPERIMPL_H
#define CBJECT_CASTTOSUPERIMPL_H
#include "Cbject_CastToSuperFunPrototype.h"

#define Cbject_CastToSuperImpl(cbjType, parent) \
    Cbject_CastToSuperFunPrototype(cbjType, parent) { return (parent *) me; }

#endif // CBJECT_CASTTOSUPERIMPL_H
