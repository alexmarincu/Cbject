#ifndef _CBJ_SETFUNPROTOTYPE_H
#define _CBJ_SETFUNPROTOTYPE_H

#define _Cbj_SetFunPrototype(typeName, type, propName) \
    void typeName##_##propName##Set(typeName * const me, type const propName)

#endif // _CBJ_SETFUNPROTOTYPE_H
