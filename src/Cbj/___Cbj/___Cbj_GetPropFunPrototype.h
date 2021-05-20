#ifndef _CBJ_GETPROPFUNPROTOTYPE_H
#define _CBJ_GETPROPFUNPROTOTYPE_H

#define ___Cbj_GetPropFunPrototype(cbjType, propType, propName) \
    propType cbjType##_##propName(cbjType const * const me)

#endif // _CBJ_GETPROPFUNPROTOTYPE_H
