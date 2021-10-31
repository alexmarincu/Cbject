#ifndef CBJECT_FUNPROTOTYPE_H
#define CBJECT_FUNPROTOTYPE_H

#define Cbject_FunPrototype_void(typeName, returnType, funName, ...) \
    returnType typeName##_##funName(typeName * const me)

#define Cbject_FunPrototype_(typeName, returnType, funName, ...) \
    returnType typeName##_##funName(typeName * const me, __VA_ARGS__)

#define Cbject_FunPrototype(typeName, returnType, funName, case, ...) \
    Cbject_FunPrototype_##case (typeName, returnType, funName, __VA_ARGS__)

#endif // CBJECT_FUNPROTOTYPE_H
