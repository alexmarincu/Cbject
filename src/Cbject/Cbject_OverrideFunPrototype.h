#ifndef CBJECT_OVERRIDEFUNPROTOTYPE_H
#define CBJECT_OVERRIDEFUNPROTOTYPE_H

#define Cbject_OverrideFunPrototype_case_(typeName, funReturnType, funName, ...) \
    funReturnType super_##typeName##_##funName(typeName * const me)

#define Cbject_OverrideFunPrototype_case_Params(typeName, funReturnType, funName, ...) \
    funReturnType super_##typeName##_##funName(typeName * const me, __VA_ARGS__)

#define Cbject_OverrideFunPrototype_switch(typeName, funReturnType, funName, case, ...) \
    Cbject_OverrideFunPrototype_case_##case (typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_OverrideFunPrototype_x1(typeName, funReturnType, funName, ...) \
    Cbject_OverrideFunPrototype_switch(typeName, funReturnType, funName, __VA_ARGS__)

#define Cbject_OverrideFunPrototype(typeName, funReturnType, funName, funParams) \
    Cbject_OverrideFunPrototype_x1(typeName, funReturnType, funName, Cbject_Utils_unpack(funParams))

#endif // CBJECT_OVERRIDEFUNPROTOTYPE_H
