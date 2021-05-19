#ifndef ___CBJ_CASTTOSUPERFUNPROTOTYPE_H
#define ___CBJ_CASTTOSUPERFUNPROTOTYPE_H

#define ___Cbj_CastToSuperFunPrototype(cbjType, parent) \
    parent * const cbjType##_to##parent(cbjType const * const me)

#endif // ___CBJ_CASTTOSUPERFUNPROTOTYPE_H
