#ifndef _CBJ_NEWONSTACKFUNPROTOTYPE_H
#define _CBJ_NEWONSTACKFUNPROTOTYPE_H

#define ___Cbj_NewOnStackFunPrototype(cbjType) \
    cbjType * ___##cbjType##_newOnStack(cbjType * const me, cbjType##Params const * const params)
#endif // _CBJ_NEWONSTACKFUNPROTOTYPE_H
