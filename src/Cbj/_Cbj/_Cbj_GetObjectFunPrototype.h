#ifndef _CBJ_GETOBJECTFUNPROTOTYPE_H
#define _CBJ_GETOBJECTFUNPROTOTYPE_H

#define _Cbj_GetObjectFunPrototype(cbjType) \
    cbjType * Get_##cbjType(cbjType##Params const * const params)

#endif // _CBJ_GETOBJECTFUNPROTOTYPE_H
