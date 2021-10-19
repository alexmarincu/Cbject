#ifndef CBJECT_CASTTOSUPERFUNPROTOTYPE_H
#define CBJECT_CASTTOSUPERFUNPROTOTYPE_H

#define Cbject_CastToSuperFunPrototype(cbjType, parent) \
    parent * const cbjType##_to##parent(cbjType const * const me)

#endif // CBJECT_CASTTOSUPERFUNPROTOTYPE_H
