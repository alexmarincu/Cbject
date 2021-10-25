#ifndef CBJECT_CASTTOSUPERIMPL_H
#define CBJECT_CASTTOSUPERIMPL_H
#include "Cbject_CastToSuperFunPrototype.h"

#define Cbject_CastToSuperImpl(typeName, parent) \
    Cbject_CastToSuperFunPrototype(typeName, parent) { return (parent *) me; }

#endif // CBJECT_CASTTOSUPERIMPL_H
