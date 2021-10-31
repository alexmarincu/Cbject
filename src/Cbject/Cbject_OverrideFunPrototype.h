#ifndef CBJECT_OVERRIDEFUNPROTOTYPE_H
#define CBJECT_OVERRIDEFUNPROTOTYPE_H

#define Cbject_OverrideFunPrototype_void(typeName, returnType, funName, ...) \
    returnType typeName##_s_##funName(typeName * const me)

#define Cbject_OverrideFunPrototype_(typeName, returnType, funName, ...) \
    returnType typeName##_s_##funName(typeName * const me, __VA_ARGS__)

#define Cbject_OverrideFunPrototype(typeName, returnType, funName, case, ...) \
    Cbject_OverrideFunPrototype_##case (typeName, returnType, funName, __VA_ARGS__)

#endif // CBJECT_OVERRIDEFUNPROTOTYPE_H
