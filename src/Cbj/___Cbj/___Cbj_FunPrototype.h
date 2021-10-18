#ifndef ___CBJ_FUNPROTOTYPE_H
#define ___CBJ_FUNPROTOTYPE_H

#define ___Cbj_FunPrototype_0(cbjType, returnType, funName, ...) \
    returnType cbjType##_##funName(cbjType * const me)

#define ___Cbj_FunPrototype_(cbjType, returnType, funName, ...) \
    returnType cbjType##_##funName(cbjType * const me, __VA_ARGS__)

#define ___Cbj_FunPrototype(cbjType, returnType, funName, case, ...) \
    ___Cbj_FunPrototype_##case (cbjType, returnType, funName, __VA_ARGS__)

#endif // ___CBJ_FUNPROTOTYPE_H
