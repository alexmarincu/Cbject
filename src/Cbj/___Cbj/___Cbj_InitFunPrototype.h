#ifndef ___CBJ_INITFUNPROTOTYPE_H
#define ___CBJ_INITFUNPROTOTYPE_H

#define ___Cbj_InitFunPrototype(cbjType) \
    void ___##cbjType##_init(cbjType * const me, cbjType##Params const * const params)

#endif // ___CBJ_INITFUNPROTOTYPE_H
