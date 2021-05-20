#ifndef ___CBJ_NEWOBJECTFUNPROTOTYPE_H
#define ___CBJ_NEWOBJECTFUNPROTOTYPE_H

#define ___Cbj_NewObjectFunPrototype(cbjType) \
    cbjType * ___##cbjType##_new(cbjType##Params const * const params)
#endif // ___CBJ_NEWOBJECTFUNPROTOTYPE_H
