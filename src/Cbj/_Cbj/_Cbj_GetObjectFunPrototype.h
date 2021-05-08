#ifndef _CBJ_GETOBJECTFUNPROTOTYPE_H
#define _CBJ_GETOBJECTFUNPROTOTYPE_H

#define _Cbj_GetObjectFunPrototype(typeName) \
    typeName * Get_##typeName(typeName##Params const * const params)

#endif // _CBJ_GETOBJECTFUNPROTOTYPE_H
