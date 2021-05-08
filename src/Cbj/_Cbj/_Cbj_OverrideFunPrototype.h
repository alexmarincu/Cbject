#ifndef _CBJ_OVERRIDEFUNPROTOTYPE_H
#define _CBJ_OVERRIDEFUNPROTOTYPE_H

#define _Cbj_OverrideFunPrototype_0(typeName, returnType, funName, ...) \
    returnType s_##typeName##_##funName(typeName * const me)

#define _Cbj_OverrideFunPrototype__(typeName, returnType, funName, ...) \
    returnType s_##typeName##_##funName(typeName * const me, __VA_ARGS__)

#define _Cbj_OverrideFunPrototype(typeName, returnType, funName, case, ...) \
    _Cbj_OverrideFunPrototype_##case (typeName, returnType, funName, __VA_ARGS__)

#endif // _CBJ_OVERRIDEFUNPROTOTYPE_H
