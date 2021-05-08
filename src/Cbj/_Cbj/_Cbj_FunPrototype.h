#ifndef _CBJ_FUNPROTOTYPE_H
#define _CBJ_FUNPROTOTYPE_H

#define _Cbj_FunPrototype_0(typeName, returnType, funName, ...) \
    returnType typeName##_##funName(typeName * const me)

#define _Cbj_FunPrototype__(typeName, returnType, funName, ...) \
    returnType typeName##_##funName(typeName * const me, __VA_ARGS__)

#define _Cbj_FunPrototype(typeName, returnType, funName, case, ...) \
    _Cbj_FunPrototype_##case (typeName, returnType, funName, __VA_ARGS__)

#endif // _CBJ_FUNPROTOTYPE_H
