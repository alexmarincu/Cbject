#ifndef CBJECT_SUPERFUNPROTOTYPE_H
#define CBJECT_SUPERFUNPROTOTYPE_H

#define Cbject_SuperFunPrototype_0(cbjType, returnType, funName, ...) \
    returnType super_##cbjType##_##funName(cbjType * const me)

#define Cbject_SuperFunPrototype_(cbjType, returnType, funName, ...) \
    returnType super_##cbjType##_##funName(cbjType * const me, __VA_ARGS__)

#define Cbject_SuperFunPrototype(cbjType, returnType, funName, case, ...) \
    Cbject_SuperFunPrototype_##case (cbjType, returnType, funName, __VA_ARGS__)

#endif // CBJECT_SUPERFUNPROTOTYPE_H
