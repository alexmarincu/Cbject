#ifndef _CBJ_SETPROPFUNPROTOTYPE_H
#define _CBJ_SETPROPFUNPROTOTYPE_H

#define ___Cbj_SetPropFunPrototype(cbjType, propType, propName) \
    void cbjType##_##propName##Set(cbjType * const me, propType const propName)

#endif // _CBJ_SETPROPFUNPROTOTYPE_H
