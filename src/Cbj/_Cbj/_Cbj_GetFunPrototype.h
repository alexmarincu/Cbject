#ifndef _CBJ_GETFUNPROTOTYPE_H
#define _CBJ_GETFUNPROTOTYPE_H

#define _Cbj_GetFunPrototype(cbjType, propType, propName) \
    propType cbjType##_##propName(cbjType const * const me)

#endif // _CBJ_GETFUNPROTOTYPE_H
