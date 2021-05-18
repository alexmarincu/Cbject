#ifndef _CBJ_FUNPROTOTYPE_H
#define _CBJ_FUNPROTOTYPE_H

#define _Cbj_FunPrototype_0(cbjType, returnType, funName, ...) \
    returnType cbjType##_##funName(cbjType * const me)

#define _Cbj_FunPrototype__(cbjType, returnType, funName, ...) \
    returnType cbjType##_##funName(cbjType * const me, __VA_ARGS__)

#define _Cbj_FunPrototype(cbjType, returnType, funName, case, ...) \
    _Cbj_FunPrototype_##case (cbjType, returnType, funName, __VA_ARGS__)

#endif // _CBJ_FUNPROTOTYPE_H
