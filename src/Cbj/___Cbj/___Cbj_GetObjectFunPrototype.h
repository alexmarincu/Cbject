#ifndef ___CBJ_GETOBJECTFUNPROTOTYPE_H
#define ___CBJ_GETOBJECTFUNPROTOTYPE_H

#define ___Cbj_GetObjectFunPrototype(cbjType) \
    cbjType * ___##cbjType##_get(cbjType##Params const * const params)

#endif // ___CBJ_GETOBJECTFUNPROTOTYPE_H
