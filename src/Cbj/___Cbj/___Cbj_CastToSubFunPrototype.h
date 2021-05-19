#ifndef ___CBJ_CASTTOSUBFUNPROTOTYPE_H
#define ___CBJ_CASTTOSUBFUNPROTOTYPE_H

#define ___Cbj_CastToSubFunPrototype(cbjType, parent) \
    cbjType * const parent##_to##cbjType(parent const * const me)

#endif // ___CBJ_CASTTOSUBFUNPROTOTYPE_H
