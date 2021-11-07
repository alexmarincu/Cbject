#ifndef CBJECT_FUNPROTOTYPE_H
#define CBJECT_FUNPROTOTYPE_H

/*
Cbject_FunPrototype
*/
#define Cbject_FunPrototype_caseNA(className, funReturnType, funName, ...) \
    funReturnType className##_##funName(className * const me)

#define Cbject_FunPrototype_caseParams(className, funReturnType, funName, ...) \
    funReturnType className##_##funName(className * const me, __VA_ARGS__)

#define Cbject_FunPrototype_x1(className, funReturnType, funName, case, ...) \
    Cbject_FunPrototype_case##case (className, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype_x0(className, funReturnType, funName, ...) \
    Cbject_FunPrototype_x1(className, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype(className, funReturnType, funName, funParams) \
    Cbject_FunPrototype_x0(className, funReturnType, funName, Cbject_Utils_unpack(funParams))

#endif // CBJECT_FUNPROTOTYPE_H
