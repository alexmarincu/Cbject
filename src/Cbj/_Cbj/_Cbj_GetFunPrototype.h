#ifndef _CBJ_GETFUNPROTOTYPE_H
#define _CBJ_GETFUNPROTOTYPE_H

#define _Cbj_GetFunPrototype(typeName, type, propName) \
    type typeName##_##propName(typeName const * const me)

#endif // _CBJ_GETFUNPROTOTYPE_H
