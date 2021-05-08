#ifndef _CBJ_CASTTOSUBFUNPROTOTYPE_H
#define _CBJ_CASTTOSUBFUNPROTOTYPE_H

#define _Cbj_CastToSubFunPrototype(cbjType, parent) \
    cbjType * const parent##_to##cbjType(parent const * const me)

#endif // _CBJ_CASTTOSUBFUNPROTOTYPE_H
