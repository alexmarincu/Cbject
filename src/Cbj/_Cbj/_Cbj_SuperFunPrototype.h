#ifndef _CBJ_SUPERFUNPROTOTYPE_H
#define _CBJ_SUPERFUNPROTOTYPE_H

#define _Cbj_SuperFunPrototype_0(cbjType, returnType, funName, ...) \
    returnType s_##cbjType##_##funName(cbjType * const me)

#define _Cbj_SuperFunPrototype__(cbjType, returnType, funName, ...) \
    returnType s_##cbjType##_##funName(cbjType * const me, __VA_ARGS__)

#define _Cbj_SuperFunPrototype(cbjType, returnType, funName, case, ...) \
    _Cbj_SuperFunPrototype_##case (cbjType, returnType, funName, __VA_ARGS__)

#endif // _CBJ_SUPERFUNPROTOTYPE_H
