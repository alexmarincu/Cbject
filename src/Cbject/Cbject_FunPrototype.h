#ifndef CBJECT_FUNPROTOTYPE_H
#define CBJECT_FUNPROTOTYPE_H

/*
Cbject_FunPrototype
*/
#define Cbject_FunPrototype_caseNA(class, funReturnType, funName, ...) \
    funReturnType class##_##funName(class * const me)

#define Cbject_FunPrototype_caseParams(class, funReturnType, funName, ...) \
    funReturnType class##_##funName(class * const me, __VA_ARGS__)

#define Cbject_FunPrototype_x1(class, funReturnType, funName, paramsCase, ...) \
    Cbject_FunPrototype_case##paramsCase(class, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype_x0(class, funReturnType, funName, ...) \
    Cbject_FunPrototype_x1(class, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype(class, funReturnType, funName, funParamsPack) \
    Cbject_FunPrototype_x0(class, funReturnType, funName, Cbject_Utils_unpack(funParamsPack))

#endif // CBJECT_FUNPROTOTYPE_H
