#ifndef ___CBJ_SETFUNPROTOTYPE_H
#define ___CBJ_SETFUNPROTOTYPE_H

#define ___Cbj_SetFunPrototype(cbjType, propType, propName) \
    void cbjType##_##propName##Set(cbjType * const me, propType const propName)

#endif // ___CBJ_SETFUNPROTOTYPE_H
