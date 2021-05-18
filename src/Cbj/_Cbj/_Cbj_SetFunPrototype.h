#ifndef _CBJ_SETFUNPROTOTYPE_H
#define _CBJ_SETFUNPROTOTYPE_H

#define _Cbj_SetFunPrototype(cbjType, propType, propName) \
    void cbjType##_##propName##Set(cbjType * const me, propType const propName)

#endif // _CBJ_SETFUNPROTOTYPE_H
