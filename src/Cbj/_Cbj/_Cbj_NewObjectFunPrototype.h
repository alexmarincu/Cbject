#ifndef _CBJ_NEWOBJECTFUNPROTOTYPE_H
#define _CBJ_NEWOBJECTFUNPROTOTYPE_H

#define _Cbj_NewObjectFunPrototype(typeName) \
    typeName * New_##typeName(typeName##Params const * const params)
#endif // _CBJ_NEWOBJECTFUNPROTOTYPE_H
