#ifndef CBJECT_OVERRIDEFUNPROTOTYPE_H
#define CBJECT_OVERRIDEFUNPROTOTYPE_H

#define Cbject_OverrideFunPrototype_case(className, funReturnType, funName, ...) \
    funReturnType super_##className##_##funName(className * const me)

#define Cbject_OverrideFunPrototype_caseParams(className, funReturnType, funName, ...) \
    funReturnType super_##className##_##funName(className * const me, __VA_ARGS__)

#define Cbject_OverrideFunPrototype_switch(className, funReturnType, funName, case, ...) \
    Cbject_OverrideFunPrototype_case##case (className, funReturnType, funName, __VA_ARGS__)

#define Cbject_OverrideFunPrototype_x(className, funReturnType, funName, ...) \
    Cbject_OverrideFunPrototype_switch(className, funReturnType, funName, __VA_ARGS__)

#define Cbject_OverrideFunPrototype(className, funReturnType, funName, funParams) \
    Cbject_OverrideFunPrototype_x(className, funReturnType, funName, Cbject_Utils_unpack(funParams))

#endif // CBJECT_OVERRIDEFUNPROTOTYPE_H
