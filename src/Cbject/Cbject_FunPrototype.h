#ifndef CBJECT_FUNPROTOTYPE_H
#define CBJECT_FUNPROTOTYPE_H

#define Cbject_FunPrototype_0(cbjType, returnType, funName, ...) \
    returnType cbjType##_##funName(cbjType * const me)

#define Cbject_FunPrototype_(cbjType, returnType, funName, ...) \
    returnType cbjType##_##funName(cbjType * const me, __VA_ARGS__)

#define Cbject_FunPrototype(cbjType, returnType, funName, case, ...) \
    Cbject_FunPrototype_##case (cbjType, returnType, funName, __VA_ARGS__)

#endif // CBJECT_FUNPROTOTYPE_H
