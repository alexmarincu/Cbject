#ifndef CBJECT_FUNPROTOTYPE_H
#define CBJECT_FUNPROTOTYPE_H

#define Cbject_FunPrototype_case(className, funReturnType, funName, ...) \
    funReturnType className##_##funName(className * const me)

#define Cbject_FunPrototype_caseParams(className, funReturnType, funName, ...) \
    funReturnType className##_##funName(className * const me, __VA_ARGS__)

#define Cbject_FunPrototype_switch(className, funReturnType, funName, case, ...) \
    Cbject_FunPrototype_case##case (className, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype_x(className, funReturnType, funName, ...) \
    Cbject_FunPrototype_switch(className, funReturnType, funName, __VA_ARGS__)

#define Cbject_FunPrototype(className, funReturnType, funName, funParams) \
    Cbject_FunPrototype_x(className, funReturnType, funName, Cbject_Utils_unpack(funParams))

#endif // CBJECT_FUNPROTOTYPE_H
