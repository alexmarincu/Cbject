#ifndef _CBJ_NEWOBJECTFUNPROTOTYPE_H
#define _CBJ_NEWOBJECTFUNPROTOTYPE_H

#define _Cbj_NewObjectFunPrototype(cbjType) \
    cbjType * New_##cbjType(cbjType##Params const * const params)
#endif // _CBJ_NEWOBJECTFUNPROTOTYPE_H
