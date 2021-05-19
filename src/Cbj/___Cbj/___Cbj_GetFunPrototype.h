#ifndef ___CBJ_GETFUNPROTOTYPE_H
#define ___CBJ_GETFUNPROTOTYPE_H

#define ___Cbj_GetFunPrototype(cbjType, propType, propName) \
    propType cbjType##_##propName(cbjType const * const me)

#endif // ___CBJ_GETFUNPROTOTYPE_H
