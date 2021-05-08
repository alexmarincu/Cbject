#ifndef _CBJ_CASTTOSUPERFUNPROTOTYPE_H
#define _CBJ_CASTTOSUPERFUNPROTOTYPE_H

#define _Cbj_CastToSuperFunPrototype(cbjType, parent) \
    parent * const cbjType##_to##parent(cbjType const * const me)

#endif // _CBJ_CASTTOSUPERFUNPROTOTYPE_H
