#ifndef CBJECT_SUPERFUNPROTOTYPE_H
#define CBJECT_SUPERFUNPROTOTYPE_H

#define Cbject_SuperFunPrototype_0(typeName, returnType, funName, ...) \
    returnType super_##typeName##_##funName(typeName * const me)

#define Cbject_SuperFunPrototype_(typeName, returnType, funName, ...) \
    returnType super_##typeName##_##funName(typeName * const me, __VA_ARGS__)

#define Cbject_SuperFunPrototype(typeName, returnType, funName, case, ...) \
    Cbject_SuperFunPrototype_##case (typeName, returnType, funName, __VA_ARGS__)

#endif // CBJECT_SUPERFUNPROTOTYPE_H
