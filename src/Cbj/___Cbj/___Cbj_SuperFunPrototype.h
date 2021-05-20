#ifndef ___CBJ_SUPERFUNPROTOTYPE_H
#define ___CBJ_SUPERFUNPROTOTYPE_H

#define ___Cbj_SuperFunPrototype_0(cbjType, returnType, funName, ...) \
    returnType super_##cbjType##_##funName(cbjType * const me)

#define ___Cbj_SuperFunPrototype__(cbjType, returnType, funName, ...) \
    returnType super_##cbjType##_##funName(cbjType * const me, __VA_ARGS__)

#define ___Cbj_SuperFunPrototype(cbjType, returnType, funName, case, ...) \
    ___Cbj_SuperFunPrototype_##case (cbjType, returnType, funName, __VA_ARGS__)

#endif // ___CBJ_SUPERFUNPROTOTYPE_H
