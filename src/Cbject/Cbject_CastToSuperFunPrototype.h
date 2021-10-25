#ifndef CBJECT_CASTTOSUPERFUNPROTOTYPE_H
#define CBJECT_CASTTOSUPERFUNPROTOTYPE_H

#define Cbject_CastToSuperFunPrototype(typeName, parent) \
    parent * const typeName##_to##parent(typeName const * const me)

#endif // CBJECT_CASTTOSUPERFUNPROTOTYPE_H
